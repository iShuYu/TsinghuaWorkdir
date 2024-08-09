#define mct_cxx
#include <TTree.h>
#include <TFile.h>
#include <TProfile.h>
#include <TRandom.h>
#include <TH2D.h>
#include "../../../../../workdir/Yield/rawdata/1_Rootfile/MCtracks/Jpsi/mct.h"
void RegenVarMCp()
{
	TFile *re = TFile::Open("../../../../../workdir/Yield/Jpsi/3_Result/RegenVar/weight.root");
	TProfile *reweightNN = (TProfile*)re->Get("Pro2");
	TFile *input = TFile::Open("../../../../../workdir/Yield/rawdata/1_Rootfile/MCtracks/Jpsi/Tuple.root");
	TH2D *h = new TH2D("h", "h", 60, -60, 180, 80, 0, 160);
	TTree* DecayTree = (TTree*)input->Get("mct");
	DecayTree -> Draw("PVNTRACKS:PVZ>>h", "PVZ>-60");
	TProfile *Pro = h->ProfileX();
	double max = Pro->GetBinContent(Pro->FindBin(38));
	TFile* out = new TFile("../../../../../workdir/Yield/Jpsi/3_Result/RegenVar/newVarMC.root","recreate");
	TTree *result = DecayTree->CloneTree(0);
	result->SetBranchStatus("*", 0);
	double PVNrew, PVNcor, wn;
	result->Branch("PVNcor", &PVNcor, "PVNcor/D");
	result->Branch("wn", &wn, "wn/D");
	result->Branch("PVNrew", &PVNrew, "PVNrew/D");
	result->SetBranchStatus("PVNTRACKS", 1);
	result->SetBranchStatus("PVZ", 1);
	result->SetBranchStatus("PVNrew", 1);
	result->SetBranchStatus("Nch", 1);

	mct t(DecayTree);
	int N = DecayTree->GetEntries();
	cout << N << endl;
	ROOT::Math::GSLRandomEngine Gen;
	Gen.Initialize();
	for(int i=0; i<N; i++)
	{
		DecayTree->GetEntry(i);
		int PVN = t.PVNTRACKS[0];
		double PVZ = t.PVZ[0];
		if(PVZ<-60) continue;
		wn = reweightNN -> GetBinContent(reweightNN->FindBin(PVZ));
		double y = max/Pro->GetBinContent(Pro->FindBin(PVZ));
		double p = 1/(1+y);
		//cout << "i" << i << ":" << "p" << p << ":" << "y" << y << endl;
		PVNcor = Gen.NegativeBinomial(p,PVN)*wn;
		PVNrew = PVN*wn;
		result->Fill();
	}
	result->Write();
	out->Close();
}

