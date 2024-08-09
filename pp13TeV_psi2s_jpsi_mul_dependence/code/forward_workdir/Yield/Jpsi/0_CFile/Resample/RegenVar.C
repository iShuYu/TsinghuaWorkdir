#define CBSplotDecayTree_cxx
#include <TTree.h>
#include <TFile.h>
#include <TProfile.h>
#include <TRandom.h>
#include <TH2D.h>
#include "../../../../../workdir/Yield/Jpsi/3_Result/2DFit/CBSplotDecayTree.h"
void RegenVar()
{
	TFile *input = TFile::Open("../../../../../ForWorkdir/Yield/Jpsi/3_Result/2DFit/2D.root");
	TH2D *h1 = new TH2D("h1", "h1", 60, -60, 180, 100, 0, 200);
	TH2D *h2 = new TH2D("h2", "h2", 60, -180, 180, 70, 0, 140);
	TH2D *h3 = new TH2D("h3", "h3", 60, -30, 180, 80, 0, 80);
	TTree* DecayTree = (TTree*)input->Get("DecayTree");
	DecayTree -> Draw("PVNTRACKS:PVZ>>h1");
	TProfile *Pro1 = h1->ProfileX();
	DecayTree -> Draw("psi_nForWardTracks:PVZ>>h2");
        TProfile *Pro2 = h2->ProfileX();
	DecayTree -> Draw("psi_nBackTracks:PVZ>>h3");
        TProfile *Pro3 = h3->ProfileX();

	double max1 = Pro1->GetMaximum();
	double max2 = Pro2->GetBinContent(Pro2->FindBin(-55));
	double max3 = Pro3->GetBinContent(Pro3->FindBin(43));

	TFile* out = new TFile("../../../../../workdir/Yield/Jpsi/3_Result/RegenVar/newVar.root","recreate");
	TTree *result = DecayTree->CloneTree(0);
	result->SetBranchStatus("*", 0);
	double PVNcor, nFcor, nBcor;
	result->Branch("PVNcor", &PVNcor, "PVNcor/D");
	result->Branch("nFcor", &nFcor, "nFcor/D");
	result->Branch("nBcor", &nBcor, "nBcor/D");
	result->SetBranchStatus("PVNTRACKS", 1);
	result->SetBranchStatus("psi_PT", 1);
	result->SetBranchStatus("psi_Y", 1);
	result->SetBranchStatus("psi_nForWardTracks", 1);
	result->SetBranchStatus("psi_nBackTracks", 1);
	result->SetBranchStatus("PVZ", 1);
	result->SetBranchStatus("prompt_sw", 1);
	result->SetBranchStatus("fromb_sw", 1);
	CBSplotDecayTree t(DecayTree);
	int N = DecayTree->GetEntries();
	ROOT::Math::GSLRandomEngine Gen;
	Gen.Initialize();
	for(int i=0; i<N; i++)
	{
		DecayTree->GetEntry(i);
		int PVN = t.PVNTRACKS[0];
		int nF = t.psi_nForWardTracks;
		int nB = t.psi_nBackTracks;

		double PVZ = t.PVZ[0];
		double y1 = max1/Pro1->GetBinContent(Pro1->FindBin(PVZ));
		double y2 = max2/Pro2->GetBinContent(Pro2->FindBin(PVZ));
		double y3 = max3/Pro3->GetBinContent(Pro3->FindBin(PVZ));
		double p1 = 1/(1+y1);
		double p2 = 1/(1+y2);
		double p3 = 1/(1+y3);

		/*PVNcor = Gen.NegativeBinomial(p1,PVN);
		nFcor = Gen.NegativeBinomial(p2,nF);
		nBcor = Gen.NegativeBinomial(p3,nB);*/
		PVNcor = PVN*y1;
                nFcor = nF*y2;
                nBcor = nB*y3;

		//cout << PVN << endl;
		//cout << PVNcor << endl;
		//cout << y << endl;
                //cout << p << endl;
		//cout << "+++++" << endl;
		result->Fill();
	}
	result->Write();
	out->Close();
}

