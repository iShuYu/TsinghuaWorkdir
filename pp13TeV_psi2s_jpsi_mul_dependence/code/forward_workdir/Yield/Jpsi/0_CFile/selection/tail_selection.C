#define DecayTree_cxx
#include "../header/DecayTree.h"
#include <iostream>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#define SelectionCut 0

//Tree : extra variables add to DecayTree
class Tree : public DecayTree{
public:
	Tree(TTree *tree = 0) : DecayTree(tree) {}

	//pesudo-time
	Double_t tz;
	Double_t tzError;
	//rapidity
	Double_t psi_Y;
	Double_t psi_ETA;
	Double_t mup_ETA;
	Double_t mum_ETA;

	TTree *Select(Int_t CutType);
	Int_t Cut();
	void Loop();
};

int main(){
	time_t rawtime;
	time(&rawtime);
	printf("Mission start at: %s\n", ctime(&rawtime));
	
	//Input raw data
	TChain *input = new TChain("DecayTree", "Data without cut");
	input -> Add("../../../rawdata/1_Rootfile/data/MagDown/Jpsi16MagDown1.root");
	input -> Add("../../../rawdata/1_Rootfile/data/MagUp/Jpsi16MagUp1.root");
	input->Show(0);

	Tree *tree = new Tree((TTree*)input);
	
	//Output file
	TFile *file = new TFile("../../2_Rootfile/tailroot/tail.root", "recreate");
	
	//Do the selection
	TTree *data_tree = tree->Select(0);

	//Save the new tree
	data_tree->Write();

	file->Close();

	time(&rawtime);
	printf("Mission end at: %s\n", ctime(&rawtime));
	return 0;
}

TTree* Tree::Select(Int_t CutType){
	//Create a new tree with all variables definition
	TTree *tree = fChain->CloneTree(0);
	
	//Add new variables definition
	tree->Branch("tz", &tz, "tz/D");
	tree->Branch("tzError", &tzError, "tzError/D");
	tree->Branch("psi_Y", &psi_Y, "psi_Y/D");
	tree->Branch("psi_ETA", &psi_ETA, "psi_ETA/D");
	tree->Branch("mup_ETA", &mup_ETA, "mup_ETA/D");
	tree->Branch("mum_ETA", &mum_ETA, "mum_ETA/D");

	if(fChain == 0) return 0;

	Long64_t nentries = fChain->GetEntries();
	Long64_t nbytes = 0, nb = 0;
	
	double PV[1024][20], PV_error[1024][20];
	int numPV[1024];
	Long64_t next_runNumber[1024], next_eventNumber[1024];
	
	for(Long64_t jentry = 0; jentry < 1024; jentry++){   
		Long64_t ientry = LoadTree(nentries + jentry - 1024);
		if(ientry < 0) break;
		nb = fChain->GetEntry(nentries + jentry - 1024);
		nbytes += nb;
		numPV[jentry] = nPVs;
		if(nPVs==0) continue;
		for(int iPV=0; iPV<nPVs; iPV++){
			PV[jentry][iPV] = PVZ[iPV];
			PV_error[jentry][iPV] = PVZERR[iPV];
		}
		next_eventNumber[jentry] = eventNumber;
		next_runNumber[jentry] = runNumber;
	}    
	
	/*QUESTION*/
	//index = 0;
	int other_numPV;
	double other_PV_Z[20];
	double other_PV_ZERR[20];
	Long64_t other_eventNumber, other_runNumber;
	
	for(Long64_t jentry = 0; jentry < 1000000; jentry++){
		//Long64_t ientry = LoadTree(jentry);
		//if(ientry < 0) break;
		//cout << jentry <<endl;
		//Print some message of the process
		/*
		if(jentry % 10000 == 0){
			processing(Form("Processing Total %lld, Event %lld\n", jentry, ientry));
		}
		*/

		nb = fChain->GetEntry(jentry);
		nbytes += nb;
		/*QUESTION*/
		int i = 0;
		for(i = 0; i < 1024; i++){
			other_numPV = numPV[(jentry + i) & 1023];
			for(int iPV=0; iPV<other_numPV; iPV++){
				other_PV_Z[iPV] = PV[(jentry + i) & 1023][iPV];
				other_PV_ZERR[iPV] = PV_error[(jentry + i) & 1023][iPV];
			}
			other_eventNumber = next_eventNumber[(jentry + i) & 1023];
			other_runNumber = next_runNumber[(jentry + i) & 1023];
			if(other_eventNumber != eventNumber || other_runNumber != runNumber) break;
		}
		numPV[(jentry + i) & 1023] = nPVs;
		for(int iPV=0; iPV<nPVs; iPV++){
			PV[(jentry + i) & 1023][iPV] = PVZ[iPV];
			PV_error[(jentry + i) & 1023][iPV] = PVZERR[iPV];
		}
		next_eventNumber[(jentry + i) & 1023] = eventNumber;
		next_runNumber[(jentry + i) & 1023] = runNumber;

		//Calulate tz and y
		tz = (psi_ENDVERTEX_Z - other_PV_Z[0]) / psi_PZ 
		   * 10.0 * 3096.9 / 2.9979;
		tzError = sqrt(psi_ENDVERTEX_ZERR * psi_ENDVERTEX_ZERR 
				+ other_PV_ZERR[0] * other_PV_ZERR[0]) / psi_PZ
				* 10.0 * 3096.9 / 2.9979;
		for(int iPV=1; iPV<other_numPV; iPV++){
			double newTZ = (psi_ENDVERTEX_Z - other_PV_Z[iPV]) / psi_PZ
						 * 10.0 * 3096.9 / 2.9979;
			if (abs(newTZ) < abs(tz)) {
				tz = newTZ;
				tzError = sqrt(psi_ENDVERTEX_ZERR * psi_ENDVERTEX_ZERR 
						+ other_PV_ZERR[iPV] * other_PV_ZERR[iPV]) / psi_PZ
						* 10.0 * 3096.9 / 2.9979;
			}
		}
		Double_t half_zeta_p = asin(mup_PT/mup_PE)/2;
		Double_t half_zeta_m = asin(mum_PT/mum_PE)/2;
		psi_Y = 0.5 * log((psi_PE + psi_PZ)/(psi_PE - psi_PZ));
		psi_ETA = 0.5 * log((psi_P + psi_PZ)/(psi_P - psi_PZ));
		mup_ETA = -log(tan(half_zeta_p));
		mum_ETA = -log(tan(half_zeta_m));
		if(CutType == SelectionCut && Cut() < 0) continue;
		tree->Fill();
	}

	// Only Save the most useful variables
	tree->SetBranchStatus("*", 0); 
	tree->SetBranchStatus("psi_P*", 1);
	tree->SetBranchStatus("psi_M", 1);
	tree->SetBranchStatus("psi_MM", 1);
	tree->SetBranchStatus("mup_P*", 1);
	tree->SetBranchStatus("mum_P*", 1);
	tree->SetBranchStatus("mup_PIDmu", 1);
	tree->SetBranchStatus("mum_PIDmu", 1);
	tree->SetBranchStatus("nCandidate", 1);
	tree->SetBranchStatus("totCandidates", 1);
	tree->SetBranchStatus("tz", 1);
	tree->SetBranchStatus("tzError", 1);
	tree->SetBranchStatus("psi_Y", 1);
	tree->SetBranchStatus("*_ETA", 1);
	tree->SetBranchStatus("n*", 1);
	tree->SetBranchStatus("*TIS", 1);
	tree->SetBranchStatus("*TOS", 1);

	GetEntry(0);
	return tree;	
}

Int_t Tree::Cut(){
//	if (!(L0DUTCK == 5647)) return -1;
	if (!( nPVs != 0 )) return -1;
	if (!( BCType == 3 )) return -1;
	if (!( mup_PT > 1200 )) return -1;
	if (!( mup_P > 3000 )) return -1;
	if (!( mum_PT > 1200 )) return -1;
	if (!( mum_P > 3000 )) return -1;
	if (!( mup_PIDmu > 2 )) return -1;
	if (!( mum_PIDmu > 2 )) return -1;

	if(!(psi_ENDVERTEX_CHI2 < 7.8794)) return -1;

	if (!( mup_isMuon == 1 )) return -1;
	if (!( mum_isMuon == 1 )) return -1;
	if (!( 2 < mup_ETA && mup_ETA < 5 )) return -1;
	if (!( 2 < mum_ETA && mum_ETA < 5 )) return -1;

	if (!( mup_TRACK_GhostProb < 0.3 )) return -1;
	if (!( mum_TRACK_GhostProb < 0.3 )) return -1;
	if (!( 3096.9 - 120 <= psi_M && psi_M <= 3096.9 + 120 )) return -1;
	//if (!( 3096.9 +75 <= psi_M || psi_M <= 3096.9 - 75 )) return -1;
	//if (!( psi_ENDVERTEX_CHI2 < 8 )) return -1;
	if (!( -10 < tz && tz < 10 )) return -1;
	//if (!( -40 < tz && tz < 40 )) return -1;
	if (!( tzError < 0.3 )) return -1;
	if (!( psi_L0DiMuonDecision_TOS == 1)) return -1;
	if (!( psi_Hlt1DiMuonHighMassDecision_TOS == 1)) return -1;
	//if (!(psi_Hlt2DiMuonJPsiTurboDecision_TOS == 1)) return -1;
	//if (!(psi_ENDVERTEX_CHI2 / psi_ENDVERTEX_NDOF < 4)) return -1;
	if (!(mum_TRACK_CHI2NDOF < 3.)) return -1;
	if (!(mup_TRACK_CHI2NDOF < 3.)) return -1;

	return 1;
}
