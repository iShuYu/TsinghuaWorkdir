#define MCJpsi_cxx
#define CBSplotDecayTree_cxx
#include "../header/MCJpsi.h"
#include "../header/CBSplotDecayTree.h"
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

	//S for sweight root, and D for MCDecayTree
	TChain *Splot = new TChain("DecayTree");
	Splot -> Add(argv[1]);
	CBSplotDecayTree S(Splot);
	//output, saving reweight of pt, y and multiplicity
	TFile *F = new TFile(argv[2],"recreate");

	//Loop
	int N = Splot -> GetEntries();
	TH2D *FBb = new TH2D("FBb","FBb",120,0,120,80,0,80);
	TH2D *FBp = new TH2D("FBp","FBp",120,0,120,80,0,80);
	double wp,wb;
	int Nf, Nb;
	for(int i=0; i<N; i++)
	{
		Splot -> GetEntry(i);
		wp = S.prompt_sw;
		wb = S.fromb_sw;
		Nf = S.psi_nForWardTracks;
		Nb = S.psi_nBackTracks;
		FBp -> Fill(Nf,Nb,wp);
		FBb -> Fill(Nf,Nb,wb);
	}
	FBp -> Write();
	FBb -> Write();
	F -> Close();
	return 0;
}
