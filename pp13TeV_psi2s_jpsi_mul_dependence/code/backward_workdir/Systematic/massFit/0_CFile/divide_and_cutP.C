#define MCPsi2S_cxx
//#define mctPsi2S_cxx
//#include "mctPsi2S.h"
#include "MCPsi2S.h"
#include <TStyle.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
	int num_n, num_y, num_pt;
        sscanf(argv[1],"%d",&num_n);
        sscanf(argv[2],"%d",&num_y);
        sscanf(argv[3],"%d",&num_pt);
        vector<double> n, y, pt;
        double nbin, ybin, ptbin;
        int Nnbin, Nybin, Nptbin;
        ifstream nconfig(argv[4]);
        ifstream yconfig(argv[5]);
        ifstream ptconfig(argv[6]);
        nconfig >> Nnbin;
        yconfig >> Nybin;
        ptconfig >> Nptbin;
        for(int i=0; i<=Nnbin; i++)
        {
                nconfig >> nbin;
                n.push_back(nbin);
        }
        for(int i=0; i<=Nybin; i++)
        {
                yconfig >> ybin;
                y.push_back(ybin);
        }
        for(int i=0; i<=Nptbin; i++)
        {
                ptconfig >> ptbin;
                pt.push_back(ptbin);
        }
	//input
	TChain *C = new TChain("tuple1/DecayTree");
	C -> Add("~/workdir_local/Yield/rawdata/1_Rootfile/MC/MagUp/Psi2S/MCPsi2S16Up_i.root");
	C -> Add("~/workdir_local/Yield/rawdata/1_Rootfile/MC/MagDown/Psi2S/MCPsi2S16Down_i.root");
	C -> Add("~/workdir_local/Yield/rawdata/1_Rootfile/MC/MagUp/Psi2S/MCPsi2S16Up_l.root");
        C -> Add("~/workdir_local/Yield/rawdata/1_Rootfile/MC/MagDown/Psi2S/MCPsi2S16Down_l.root");
	MCPsi2S t(C);
	//output
	TFile *C_out = new TFile(Form("../2_Rootfile/Psi2S/n%dy%dpt%d.root",num_n,num_y,num_pt),"recreate");
	TTree *DecayTree_out = C -> CloneTree(0);
	Double_t tz, tzError, psi_Y, psi_ETA, mup_ETA, mum_ETA;
        DecayTree_out -> Branch("tz",&tz,"tz/D");
        DecayTree_out -> Branch("tzError",&tzError,"tzError/D");
        DecayTree_out -> Branch("psi_Y", &psi_Y, "psi_Y/D");
        DecayTree_out -> Branch("psi_ETA", &psi_ETA, "psi_ETA/D");
        DecayTree_out -> Branch("mup_ETA", &mup_ETA, "mup_ETA/D");
        DecayTree_out -> Branch("mum_ETA", &mum_ETA, "mum_ETA/D");
	long Num_Entries = C -> GetEntries();
	cout << "total entries = " << Num_Entries << endl;
	for(long jentry = 0; jentry <= Num_Entries; jentry++)
	{
		C -> GetEntry(jentry);
		tz = (t.psi_ENDVERTEX_Z-t.psi_OWNPV_Z)/t.psi_PZ * 10.0 * 3686.09 / 2.9979;
                tzError = sqrt(t.psi_ENDVERTEX_ZERR * t.psi_ENDVERTEX_ZERR + t.psi_OWNPV_ZERR * t.psi_OWNPV_ZERR) / t.psi_PZ * 10.0 * 3686.09 / 2.9979;
                psi_Y = 0.5 * log((t.psi_PE + t.psi_PZ)/(t.psi_PE - t.psi_PZ));
                psi_ETA = 0.5 * log((t.psi_P + t.psi_PZ)/(t.psi_P - t.psi_PZ));
                mup_ETA = 0.5 * log((t.mup_P + t.mup_PZ)/(t.mup_P - t.mup_PZ));
                mum_ETA = 0.5 * log((t.mum_P + t.mum_PZ)/(t.mum_P - t.mum_PZ));
		//divide
		if(!(
			t.nPVs == 1 &&
			t.nBackTracks >=n[num_n-1] &&
			t.nBackTracks< n[num_n]   &&
			psi_Y  >= y[num_y-1]      &&
                        psi_Y < y[num_y]          &&
                        t.psi_PT >= pt[num_pt-1]  &&
                        t.psi_PT < pt[num_pt]
		)) continue;
		//cut
		if(!(
			t.psi_OWNPV_Z >= -30 &&
			t.nPVs == 1  &&
                        t.BCType == 3 &&
                        t.mum_P > 3000 &&
                        t.mup_P > 3000 &&
                        t.mum_PT > 1200 &&
                        t.mup_PT > 1200 &&
			t.mum_TRACK_GhostProb < 0.3 &&
                        t.mup_TRACK_GhostProb < 0.3 &&
			2. < mup_ETA && mup_ETA < 4.9  &&
                        2. < mum_ETA && mum_ETA < 4.9  &&
			t.psi_M >= 3686. - 120 &&
                        t.psi_M <= 3686. + 120 &&
                        -10. < tz && tz < 10. &&
                        tzError < 0.3 &&
                        t.psi_ENDVERTEX_CHI2 < 7.8794 &&
			t.mum_TRACK_CHI2NDOF < 3. &&
                        t.mup_TRACK_CHI2NDOF < 3. &&
                	t.mum_ProbNNmu > 0.8 &&
                        t.mup_ProbNNmu > 0.8 &&
                        t.mum_PIDmu > 2. &&
                        t.mup_PIDmu > 2. &&
                        t.mum_isMuon == 1 &&
                        t.mup_isMuon == 1
		))continue;
		DecayTree_out->Fill();
	}
	DecayTree_out->Write();
	C_out->Close();	
	return 0;
}

