#define mct_cxx
#include <TTree.h>
#include <TFile.h>
#include <TProfile.h>
#include <TRandom.h>
#include <TH2D.h>
#include "../../../rawdata/1_Rootfile/MCtracks/Jpsi/mct.h"
void RegenVarMCb()
{
	TFile *input = TFile::Open("../../../rawdata/1_Rootfile/MCtracks/Jpsi/Tupleb.root");
	TH2D *h = new TH2D("h", "h", 60, -180, 180, 70, 0, 140);
	TTree* DecayTree = (TTree*)input->Get("mct");
	DecayTree -> Draw("(PVNTRACKS-nBackTracks):PVZ>>h", "(PVNTRACKS-nBackTracks)>=0");
	TProfile *Pro = h->ProfileX();
	double max = Pro->GetBinContent(Pro->FindBin(35));
	TFile* out = new TFile("../../3_Result/RegenVar/newVarMCb.root","recreate");
	TTree *result = DecayTree->CloneTree(0);
	result->SetBranchStatus("*", 0);
	double nForwardTracks, nForwardcor;
	result->Branch("nForwardTracks", &nForwardTracks, "nForwardTracks/D");
	result->Branch("nForwardcor", &nForwardcor, "nForwardcor/D");
	result->SetBranchStatus("PVZ", 1);
	result->SetBranchStatus("NchL", 1);

	mct t(DecayTree);
	int N = DecayTree->GetEntries();
	cout << N << endl;
	ROOT::Math::GSLRandomEngine Gen;
	Gen.Initialize();
	for(int i=0; i<N; i++)
	{
		DecayTree->GetEntry(i);
		nForwardTracks = t.PVNTRACKS[0]-t.nBackTracks;
		if(nForwardTracks < 0) continue;
		double PVZ = t.PVZ[0];
		double y = max/Pro->GetBinContent(Pro->FindBin(PVZ));
		//double p = 1/(1+y);
		//nForwardcor = Gen.NegativeBinomial(p,nForwardTracks);
		nForwardcor = nForwardTracks * y;
		result->Fill();
	}
	result->Write();
	out->Close();
}

