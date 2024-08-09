#define DecayTree_cxx
#include <iostream>
#include <fstream>
#include "../header/DecayTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <vector>
#include <string>
using namespace std;
class Tree : public DecayTree {
        public:
                Tree(TTree *tree=0) : DecayTree(tree) {}
                Double_t tz;
                Double_t tzError;
                Double_t psi_Y;
                Double_t psi_ETA;
                Double_t mup_ETA;
                Double_t mum_ETA;
                TTree * Select();
                int Cut();
                void Loop();
};

int main(int argc, char* argv[])
{

        TChain *input = new TChain("DecayTree", "");
        input -> Add(argv[1]);
        Tree* tree = new Tree( (TTree*)input );
        TFile* file = new TFile(argv[2],"recreate");

        TTree* data_tree = tree->Select();
        data_tree->Write();
        file->Close();

        return 0;
}

TTree* Tree::Select()
{
        TTree *tree = fChain->CloneTree(0);

        tree->Branch("tz", &tz, "tz/D");
        tree->Branch("tzError", &tzError, "tzError/D");
        tree->Branch("psi_Y", &psi_Y, "psi_Y/D");
        tree->Branch("psi_ETA", &psi_ETA, "psi_ETA/D");
        tree->Branch("mup_ETA", &mup_ETA, "mup_ETA/D");
        tree->Branch("mum_ETA", &mum_ETA, "mum_ETA/D");
        if (fChain == 0) return 0;
        long nentries = fChain->GetEntries();

        for (long jentry=0; jentry<nentries; jentry++)
        {
                long ientry = LoadTree(jentry);
                if (ientry < 0) break;
                fChain -> GetEntry(jentry);
                tz = (psi_ENDVERTEX_Z - psi_OWNPV_Z) / psi_PZ * 10.0 * 3686.09 / 2.9979;
                tzError = sqrt(psi_ENDVERTEX_ZERR * psi_ENDVERTEX_ZERR + psi_OWNPV_ZERR * psi_OWNPV_ZERR) / psi_PZ * 10.0 * 3686.09 / 2.9979;
                Double_t half_zeta_p = asin(mup_PT/mup_PE)/2;
                Double_t half_zeta_m = asin(mum_PT/mum_PE)/2;
                psi_Y = 0.5 * log((psi_PE + psi_PZ)/(psi_PE - psi_PZ));
                psi_ETA = 0.5 * log((psi_P + psi_PZ)/(psi_P - psi_PZ));
                mup_ETA = 0.5 * log((mup_P + mup_PZ)/(mup_P - mup_PZ));
                mum_ETA = 0.5 * log((mum_P + mum_PZ)/(mum_P - mum_PZ));
                if (Cut() < 0) continue;
                tree->Fill();
        }

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
		  tree->SetBranchStatus("tzError", 1);
        tree->SetBranchStatus("psi_Y", 1);
        tree->SetBranchStatus("*_ETA", 1);
        tree->SetBranchStatus("n*", 1);
        tree->SetBranchStatus("*TIS", 1);
        tree->SetBranchStatus("*TOS", 1);

        return tree;
}

Int_t Tree::Cut()
{
	if(!(
			//L0DUTCK == 5647 &&
			//psi_OWNPV_Z >= -60 &&
			nPVs == 1  &&
			BCType == 3 &&
			mum_P > 3000 &&
			mup_P > 3000 &&
			mum_PT > 1200 &&
			mup_PT > 1200 &&
			mum_PIDmu > 2 &&
			mup_PIDmu > 2 &&
			mum_isMuon == 1 &&
			mup_isMuon == 1 &&
			mum_ProbNNmu > 0.8 &&
			mup_ProbNNmu>0.8 &&
			mum_TRACK_GhostProb < 0.3 &&
			mup_TRACK_GhostProb < 0.3 &&
			2 < mup_ETA && mup_ETA < 4.9  &&
			2 < mum_ETA && mum_ETA < 4.9  &&
			(psi_M <= 3686. - 50 || psi_M >= 3686. + 50) &&
			-10. < tz && tz < 10. &&
			tzError < 0.3 &&
			psi_L0DiMuonDecision_TOS == 1 &&
			psi_Hlt1DiMuonHighMassDecision_TOS == 1 &&
			//psi_Hlt2DiMuonPsi2STurboDecision_TOS == 1 &&
			psi_ENDVERTEX_CHI2 < 7.8794 &&
			mum_TRACK_CHI2NDOF < 3. &&
			mup_TRACK_CHI2NDOF < 3.
	      )) return -1;
        return 1;
}

