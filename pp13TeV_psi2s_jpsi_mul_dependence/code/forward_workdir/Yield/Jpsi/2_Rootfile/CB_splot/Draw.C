#define DecayTree_cxx
#include <TH1.h>
#include "DecayTree.h"
#include <TStyle.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	TH1::SetDefaultSumw2();
	TChain *C = new TChain("DecayTree");
	C -> Add("./Data_Splot.root");
	DecayTree t(C);
	int N = C->GetEntries();
	TFile *F = new TFile("Reweight.root","recreate");
	//TTree *SPD = C->CloneTree(0);
	TH1D *SPD = new TH1D("SPD","SPD",60,0,900);
	TH1D *wSPD = new TH1D("wSPD","wSPD",60,0,900);
	double nSPDHits_w,w;
	//SPD->Branch("nSPDHits_w",&nSPDHits_w,"nSPDHits_w/D");
	for(int i=0; i<0.1*N; i++)
	{
		C->GetEntry(i);
		nSPDHits_w = t.nSPDHits;
		w = t.sig_sw;
		wSPD->Fill(nSPDHits_w,w);
		SPD->Fill(nSPDHits_w);
	}
	SPD->Scale(1.0/SPD->Integral());
	wSPD->Scale(1.0/wSPD->Integral());
	SPD->Write();
	wSPD->Write();
	F->Close();
	return 0;
}
