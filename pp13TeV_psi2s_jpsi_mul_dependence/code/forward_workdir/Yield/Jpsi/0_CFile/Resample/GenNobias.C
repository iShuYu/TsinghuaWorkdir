#define ntup_cxx
#include <TTree.h>
#include <TFile.h>
#include <TProfile.h>
#include <TRandom.h>
#include <TH2D.h>
#include "/nishome/kangye/public/ntup.h"
void GenNobias()
{
	TFile *input = TFile::Open("/nishome/kangye/public/ntup_rec_nobias.root");
	TH2D *h1 = new TH2D("h1", "h1", 60, -60, 180, 70, 0, 140);
	TH2D *h2 = new TH2D("h2", "h2", 60, -180, 180, 60, 0, 120);
	TH2D *h3 = new TH2D("h3", "h3", 35, -30, 180, 40, 0, 80);
	TTree* DecayTree = (TTree*)input->Get("ntracks/ntup");
	DecayTree -> Draw("PVNTRACKS_npv1:pvz>>h1");
	DecayTree -> Draw("PVNTRACKS_npv1-back_tracks:pvz>>h2","PVNTRACKS_npv1-back_tracks>=0");
	DecayTree -> Draw("back_tracks:pvz>>h3");

	TProfile *Pro1 = h1->ProfileX();
	TProfile *Pro2 = h2->ProfileX();
	TProfile *Pro3 = h3->ProfileX();

	double max1 = Pro1->GetBinContent(Pro1->FindBin(65));
	double max2 = Pro2->GetBinContent(Pro2->FindBin(-55));
	double max3 = Pro3->GetBinContent(Pro2->FindBin(42));

	TFile* out = new TFile("../../../../../workdir/Yield/Jpsi/3_Result/RegenVar/newVarNobias.root","recreate");
	TTree *result = DecayTree->CloneTree(0);
	result->SetBranchStatus("*", 0);
	double PVNcor, nFcor, nBcor, forward_tracks;
	result->Branch("PVNcor", &PVNcor, "PVNcor/D");
	result->Branch("nFcor", &nFcor, "nFcor/D");
	result->Branch("nBcor", &nBcor, "nBcor/D");
	result->Branch("forward_tracks", &forward_tracks, "forward_tracks/D");

	result->SetBranchStatus("PVNTRACKS_npv1", 1);
	result->SetBranchStatus("back_tracks", 1);
//	result->SetBranchStatus("PVNTRACKS_npv1", 1);

	result->SetBranchStatus("pvz", 1);
	//result->SetBranchStatus("prompt_sw", 1);
	//result->SetBranchStatus("fromb_sw", 1);
	ntup t(DecayTree);
	int N = DecayTree->GetEntries();
	ROOT::Math::GSLRandomEngine Gen;
	Gen.Initialize();
	for(int i=0; i<N; i++)
	{
		DecayTree->GetEntry(i);
		int PVN = t.PVNTRACKS_npv1;
		int nB = t.back_tracks;
		double PVZ = t.pvz;
		forward_tracks = PVN - nB;
                if(forward_tracks<0) continue;
		double y1 = max1/Pro1->GetBinContent(Pro1->FindBin(PVZ));
		double p1 = 1/(1+y1);
		//PVNcor = Gen.NegativeBinomial(p1,PVN);
		PVNcor = PVN*y1;
		double y2 = max2/Pro2->GetBinContent(Pro2->FindBin(PVZ));
                double p2 = 1/(1+y2);
                //nFcor = Gen.NegativeBinomial(p2,forward_tracks);
		nFcor = forward_tracks*y2;
		double y3 = max3/Pro3->GetBinContent(Pro3->FindBin(PVZ));
                double p3 = 1/(1+y3);
                //nBcor = Gen.NegativeBinomial(p3,nB);
		nBcor = nB*y3;
		//cout << PVN << endl;
		//cout << PVNcor << endl;
		//cout << y << endl;
                //cout << p << endl;
		//cout << "+++++" << endl;
		result->Fill();
	}
	Pro1->Write();
	Pro2->Write();
	Pro3->Write();

	result->Write();
	out->Close();
}

