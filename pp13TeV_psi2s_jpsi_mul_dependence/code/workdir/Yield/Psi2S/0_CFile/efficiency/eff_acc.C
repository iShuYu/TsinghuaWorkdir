#define MCDecayTree_cxx
#include <iostream>
#include <fstream>
#include <TH2.h>
#include <TH1.h>
#include <TFile.h>
#include <TChain.h>
#include "../header/MCDecayTree.h"
#include <TROOT.h>
#include <TStyle.h>
#include "/nishome/kangye/disk402_ppAnalysis/workdir/Yield/Jpsi/0_CFile/header/lhcbStyle.h"
using namespace std;
int main(int argc, char* argv[])
{
	setLHCbStyle();
	TH1::SetDefaultSumw2();
	const double minETA = 1.595978718; //10 mrad
	const double maxETA = 5.298309033; //400 mrad
        double ybin, ptbin;
        int Nybin, Nptbin;
	ifstream yconfig(argv[3]);
        ifstream ptconfig(argv[4]);
	yconfig >> Nybin;
        ptconfig >> Nptbin;
	double y[Nybin+1], pt[Nptbin+1];
	for(int i=0; i<=Nybin; i++)
        {
                yconfig >> ybin;
                y[i]=ybin;
        }
        for(int i=0; i<=Nptbin; i++)
        {
                ptconfig >> ptbin;
		pt[i]=ptbin;
        }
        int color[Nybin];
        int marker[Nptbin];
	for(int i=0; i<Nybin; i++)
	{
		color[i] = 2*i+1;
		marker[i] = 20+i*2;
	}
	//input
	TChain* chain = new TChain("MCDecayTreeTuple/MCDecayTree");
	chain -> Add(argv[1]);
	MCDecayTree myTree(chain);
	//Loop
	TH2D *h_tot = new TH2D("h_tot", "h_tot", Nptbin, pt, Nybin, y);
	TH2D *h_acc = new TH2D("h_acc", "h_acc", Nptbin, pt, Nybin, y);
	int N = chain->GetEntries();
	double psi_pt,psi_y,mum_ETA,mup_ETA;
	for(int i=0; i<N ; i++)
	{
		chain->GetEntry(i);
		//calculate y and pt for Psi and mu
		if(myTree.MCPVs!=1) continue;
		if(myTree.MCPVZ[0]<-60) continue;
		psi_pt = myTree.psi_TRUEPT;
		psi_y = 0.5*log((myTree.psi_TRUEP_E+myTree.psi_TRUEP_Z)/(myTree.psi_TRUEP_E-myTree.psi_TRUEP_Z));
		double mumP = sqrt(myTree.mum_TRUEPT*myTree.mum_TRUEPT+myTree.mum_TRUEP_Z*myTree.mum_TRUEP_Z);
		double mupP = sqrt(myTree.mup_TRUEPT*myTree.mup_TRUEPT+myTree.mup_TRUEP_Z*myTree.mup_TRUEP_Z);
		double mumPZ = myTree.mum_TRUEP_Z;
		double mupPZ = myTree.mup_TRUEP_Z;
		mum_ETA = 0.5*log((mumP+mumPZ)/(mumP-mumPZ));
		mup_ETA = 0.5*log((mupP+mupPZ)/(mupP-mupPZ));
		h_tot->Fill(psi_pt,psi_y);
		//cout << mum_ETA << endl;
		//cout << mup_ETA << endl;
		if(mum_ETA<minETA) continue;
		if(mup_ETA<minETA) continue;
		if(mum_ETA>maxETA) continue;
                if(mup_ETA>maxETA) continue;
		h_acc->Fill(psi_pt,psi_y);
		//cout << "fill" << endl;
	}
	//output
	TH2D *h_eff = new TH2D("h_eff", "h_eff", Nptbin, pt, Nybin, y);
	h_eff -> Divide(h_acc, h_tot, 1, 1, "B");
	TH1D* Acc[Nybin];
	for (int i=0; i<Nybin; i++)
	{
                Acc[i] = new TH1D(Form("Acc%d",i), Form("Acc%d",i), Nptbin, pt);
                Acc[i]->GetXaxis()->SetTitle("#font[12]{p}_{T}[MeV/#font[12]{c}]");
                Acc[i]->GetYaxis()->SetTitle(argv[5]);
                Acc[i]->GetYaxis()->SetRangeUser(0.2,1.05);
                Acc[i]->SetLineColor(color[i]);
                Acc[i]->SetMarkerColor(color[i]);
                Acc[i]->SetMarkerStyle(marker[i]);
                for (int j=0; j<Nptbin; j++)
		{
                        Acc[i]->SetBinContent(j+1, h_eff->GetBinContent(j+1,i+1));
                        Acc[i]->SetBinError(j+1, h_eff->GetBinError(j+1,i+1));
                }
	}
	TFile* fnew = new TFile(argv[2],"recreate");
        h_eff->Write();
        for(int i=0; i<Nybin; i++) Acc[i]->Write();
	fnew->Close();
	return 0;
}

