#define DecayTree_cxx
#include "0_header/DecayTree.h"
#include <TStyle.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
	//flag, 1 for jpsi and 2 for psi2S
	int flag;
	sscanf(argv[1],"%d",&flag);
	//input
	TChain *F_in = new TChain("DecayTree");
	F_in -> Add(argv[2]);

	//output
	TFile *F_out = new TFile(argv[3],"recreate");
	TTree *T_out = F_in->CloneTree(0);
	Double_t tz, tzError, psi_Y, psi_ETA, mup_ETA, mum_ETA;
	T_out -> Branch("tz",&tz,"tz/D");
	T_out -> Branch("tzError",&tzError,"tzError/D");
	T_out -> Branch("psi_Y", &psi_Y, "psi_Y/D");
   	T_out -> Branch("psi_ETA", &psi_ETA, "psi_ETA/D");
	T_out -> Branch("mup_ETA", &mup_ETA, "mup_ETA/D");
	T_out -> Branch("mum_ETA", &mum_ETA, "mum_ETA/D");
	DecayTree t(F_in);
	//Loop
	Long64_t Num_Entries = F_in -> GetEntries();
	for(Long64_t jentry = 0; jentry <= Num_Entries; jentry++)
	{
		F_in -> GetEntry(jentry);
		if(flag==1)
		{
			tz = (t.psi_ENDVERTEX_Z-t.psi_OWNPV_Z)/t.psi_PZ * 10.0 * 3096.9 / 2.9979;
			tzError = sqrt(t.psi_ENDVERTEX_ZERR * t.psi_ENDVERTEX_ZERR + t.psi_OWNPV_ZERR * t.psi_OWNPV_ZERR) / t.psi_PZ * 10.0 * 3096.9 / 2.9979;
		}
		if(flag==2)
		{
			tz = (t.psi_ENDVERTEX_Z-t.psi_OWNPV_Z)/t.psi_PZ * 10.0 * 3686.09 / 2.9979;
			tzError = sqrt(t.psi_ENDVERTEX_ZERR * t.psi_ENDVERTEX_ZERR + t.psi_OWNPV_ZERR * t.psi_OWNPV_ZERR) / t.psi_PZ * 10.0 * 3686.09 / 2.9979;
		}

		psi_Y = 0.5 * log((t.psi_PE + t.psi_PZ)/(t.psi_PE - t.psi_PZ))-0.465;
		psi_ETA = 0.5 * log((t.psi_P + t.psi_PZ)/(t.psi_P - t.psi_PZ));
		mup_ETA = 0.5 * log((t.mup_P + t.mup_PZ)/(t.mup_P - t.mup_PZ));
		mum_ETA = 0.5 * log((t.mum_P + t.mum_PZ)/(t.mum_P - t.mum_PZ));
		//cut
		if(!(
			t.psi_OWNPV_Z <= 120 &&
			t.BCType == 3 &&
			t.mum_PT > 900 &&
			t.mup_PT > 900 &&
			t.mum_isMuon == 1 &&
			t.mup_isMuon == 1 &&
			t.mum_ProbNNmu > 0.9 &&
			t.mup_ProbNNmu > 0.9 &&
			t.mum_TRACK_GhostProb < 0.4 &&
			t.mup_TRACK_GhostProb < 0.4 &&
			2 < mup_ETA && mup_ETA < 5  &&
			2 < mum_ETA && mum_ETA < 5  &&
			t.psi_L0Global_TIS == 1 &&
			//t.psi_Hlt1DiMuonHighMassDecision_TOS == 1 &&
			t.psi_ENDVERTEX_CHI2 < 7.8794 &&
			t.mum_TRACK_CHI2NDOF < 3. &&
			t.mup_TRACK_CHI2NDOF < 3.
			))continue;
		if( flag==1 && t.psi_M >= 3096.9 - 120 &&t.psi_M <= 3096.9 + 120)  T_out -> Fill();
		if( flag==2 && t.psi_M >= 3686.09 - 120 &&t.psi_M <= 3686.09 + 120)  T_out -> Fill();
	}
	T_out -> Write();
	F_out -> Close();
	return 0;
}
