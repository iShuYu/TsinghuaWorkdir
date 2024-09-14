#define mct_cxx
#define NoBias_cxx
#define CBSplotDecayTree_cxx
#include "./mct.h"
#include "/nishome/kangye/public/NoBias.h"
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

	//input of splot root and mcDecaytree
	//S for sweight root, and D for MCDecayTree
	TChain *Splot = new TChain("DecayTree");
	Splot -> Add(argv[1]);
	CBSplotDecayTree S(Splot);

	TChain *mctp = new TChain("mct");
	mctp -> Add(argv[2]);
	mct Dp(mctp);

	TChain *mctb = new TChain("mct");
        mctb -> Add(argv[3]);
        mct Db(mctb);

	//input NoBias
	TChain *Nobias = new TChain("ntracks/ntup");
	Nobias -> Add(argv[4]);
	NoBias NB(Nobias);

	//output, saving reweight of pt, y and multiplicity
	TFile *F = new TFile(argv[5],"recreate");

	//Loop
	int NS = Splot -> GetEntries();
	int NDp = mctp -> GetEntries();
	int NDb = mctb -> GetEntries();
	int NN = Nobias -> GetEntries();
	double N, wp, wb;
	TH1D *Sp_N = new TH1D("Sp_N","Sp_N",60,0,180);
	TH1D *Sb_N = new TH1D("Sb_N","Sb_N",60,0,180);
	TH1D *D_Np = new TH1D("D_Np","D_Np",60,0,180);
	TH1D *D_Nb = new TH1D("D_Nb","D_Nb",60,0,180);
	TH1D *D_N = new TH1D("D_N","D_N",60,0,180);
	TH1D *N_N = new TH1D("N_N","N_N",60,0,180);
	for(int i=0; i<NS; i++)
	{
		Splot -> GetEntry(i);
		wp = S.prompt_sw;
		wb = S.fromb_sw;
		N = S.PVNTRACKS[0];
		Sp_N -> Fill(N,wp);
		Sb_N -> Fill(N,wb);
		D_N -> Fill(N, wb+wp);
	}
	for(int i=0; i<NDp; i++)
        {
                mctp -> GetEntry(i);
                N = Dp.PVNTRACKS[0];
		D_Np -> Fill(N);
		D_N -> Fill(N); //都fill就是总的mct
        }
	for(int i=0; i<NDb; i++)
        {
                mctb -> GetEntry(i);
                N = Db.PVNTRACKS[0];
                D_Nb -> Fill(N);
		D_N -> Fill(N); //都fill就是总的mct
        }
	for(int i=0; i<NN; i++)
        {
		Nobias -> GetEntry(i);
		N = NB.PVNTRACKS_npv1;
		N_N -> Fill(N);
	}


	//normalize them
	Sp_N -> Scale(1.0/Sp_N->Integral());
	Sb_N -> Scale(1.0/Sb_N->Integral());
	D_Np -> Scale(1.0/D_Np->Integral());
	D_Nb -> Scale(1.0/D_Nb->Integral());
	D_N -> Scale(1.0/D_N->Integral());
        N_N -> Scale(1.0/N_N->Integral());


	//Save
	TH1D *reweightpN = new TH1D("reweightpN","reweightpN",60,0,180);
	TH1D *reweightbN = new TH1D("reweightbN","reweightbN",60,0,180);
	TH1D *reweightNN = new TH1D("reweightNN","reweightNN",60,0,180);

	reweightpN -> Divide(Sp_N, D_Np,1.,1.,"B");
	reweightbN -> Divide(Sb_N, D_Nb,1.,1.,"B");
	reweightNN -> Divide(N_N, D_N,1.,1.,"B");
	reweightpN -> Write();
	reweightbN -> Write();
	reweightNN -> Write();
	Sp_N -> Write();
	Sb_N -> Write();
	D_Np -> Write();
	D_Nb -> Write();
	D_N -> Write();
	N_N -> Write();
	F->Close();
	return 0;
}
