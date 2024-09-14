#define CBSplotDecayTree_cxx
#include "../../Jpsi/0_CFile/header/CBSplotDecayTree.h"
#include <TStyle.h>
#include <TH1.h>
#include <TH2D.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
	TH1::SetDefaultSumw2();

	//input
	TChain *Splot = new TChain("DecayTree");
	Splot -> Add(argv[1]);
	CBSplotDecayTree S(Splot);

	//output
	TFile *F = new TFile(argv[2],"recreate");

	//Loop
	int NS = Splot -> GetEntries();
	double N, wp, wb;
	TH1D *Sp  = new TH1D("Sp ","Sp ",150,0,150);
	TH1D *Sb  = new TH1D("Sb ","Sb ",150,0,150);
	for(int i=0; i<NS; i++)
	{
		Splot -> GetEntry(i);
		wp = S.prompt_sw;
		wb = S.fromb_sw;
		N = S.psi_nForWardTracks;
		Sp  -> Fill(N,wp);
		Sb  -> Fill(N,wb);
	}
	Sp  -> Write();
	Sb  -> Write();
	F->Close();
	return 0;
}
