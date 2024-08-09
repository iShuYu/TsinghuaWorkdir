#define MCPsi2S_cxx
#include "../header/MCPsi2S.h"
#include <TStyle.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
	//input
	TChain *F_in = new TChain("DecayTree");
	F_in -> Add(argv[1]);

	//output
	TFile *F_out = new TFile(argv[2],"recreate");
        TTree *T_out = F_in->CloneTree(0);
        Double_t tz, tzError, psi_Y, psi_ETA, mup_ETA, mum_ETA;
        T_out -> Branch("tz",&tz,"tz/D");
        T_out -> Branch("tzError",&tzError,"tzError/D");
        T_out -> Branch("psi_Y", &psi_Y, "psi_Y/D");
        T_out -> Branch("psi_ETA", &psi_ETA, "psi_ETA/D");
        T_out -> Branch("mup_ETA", &mup_ETA, "mup_ETA/D");
        T_out -> Branch("mum_ETA", &mum_ETA, "mum_ETA/D");

        MCPsi2S t(F_in);
	Long64_t Num_Entries = F_in -> GetEntries();
        for(Long64_t jentry = 0; jentry <= Num_Entries; jentry++)
        {
                F_in -> GetEntry(jentry);
                tz = (t.psi_ENDVERTEX_Z-t.psi_OWNPV_Z)/t.psi_PZ * 10.0 * 3686.09 / 2.9979;
                tzError = sqrt(t.psi_ENDVERTEX_ZERR * t.psi_ENDVERTEX_ZERR + t.psi_OWNPV_ZERR * t.psi_OWNPV_ZERR) / t.psi_PZ * 10.0 * 3686.09 / 2.9979;
		psi_Y = 0.5 * log((t.psi_PE + t.psi_PZ)/(t.psi_PE - t.psi_PZ));
                psi_ETA = 0.5 * log((t.psi_P + t.psi_PZ)/(t.psi_P - t.psi_PZ));
                mup_ETA = 0.5 * log((t.mup_P + t.mup_PZ)/(t.mup_P - t.mup_PZ));
                mum_ETA = 0.5 * log((t.mum_P + t.mum_PZ)/(t.mum_P - t.mum_PZ));
		//cut without pid and trigger
		if(!(t.psi_L0Global_TIS == 1 &&
                        t.psi_Hlt1Global_TIS == 1)) continue;
		if(!(
			//t.L0DUTCK == 5647 &&
                        //t.psi_OWNPV_Z >= -30 &&
			t.nPVs == 1  &&
                        t.BCType == 3 &&
                        t.mum_P > 3000 &&
                        t.mup_P > 3000 &&
                        t.mum_PT > 1200 &&
                        t.mup_PT > 1200 &&
                        //t.mum_PIDmu > 2 &&
                        //t.mup_PIDmu > 2 &&
                        //t.mum_isMuon == 1 &&
                        //t.mup_isMuon == 1 &&
                        //t.mum_ProbNNmu>0.8&&
                        //t.mup_ProbNNmu>0.8&&
			t.mum_TRACK_GhostProb < 0.3 &&
                        t.mup_TRACK_GhostProb < 0.3 &&
                        2. < mup_ETA && mup_ETA < 4.9  &&
                        2. < mum_ETA && mum_ETA < 4.9  &&
                        t.psi_M >= 3566. &&
                        t.psi_M <= 3806. &&
                        -10. < tz && tz < 10. &&
                        tzError < 0.3 &&
			t.psi_ENDVERTEX_CHI2 < 7.8794 &&
                        //t.psi_L0DiMuonDecision_TOS == 1 &&
                        //t.psi_Hlt1DiMuonHighMassDecision_TOS == 1 &&
                        //t.psi_Hlt2DiMuonPsi2STurboDecision_TOS == 1&&
			t.mum_TRACK_CHI2NDOF < 3. &&
                        t.mup_TRACK_CHI2NDOF < 3.
                        ))continue;
                T_out -> Fill();
        }
        T_out -> Write();
        F_out -> Close();
        return 0;
}

