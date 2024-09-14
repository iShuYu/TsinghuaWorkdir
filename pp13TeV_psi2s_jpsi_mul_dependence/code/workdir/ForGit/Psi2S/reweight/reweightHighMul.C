#define MCPsi2S_cxx
#define CBSplotDecayTree_cxx
#include "../header/MCPsi2S.h"
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

	TChain *McDecayTree = new TChain("DecayTree");
	McDecayTree -> Add(argv[2]);
	MCPsi2S D(McDecayTree);

	//output, saving reweight of pt, y and multiplicity
	TFile *F = new TFile(argv[3],"recreate");

	//Loop
	int NS = Splot -> GetEntries();
	int ND = McDecayTree -> GetEntries();
	double PT, Y, N, wp, wb;
	TH1D *Sp_N = new TH1D("Sp_N","Sp_N",50,0,200);
	TH1D *Sb_N = new TH1D("Sb_N","Sb_N",50,0,200);
	TH1D *D_N = new TH1D("D_N","D_N",50,0,200);
	TH2D *Sp_PTY = new TH2D("Sp_PTY","Sp_PTY",20,300,20000,10,2,4.5);
	TH2D *Sb_PTY = new TH2D("Sb_PTY","Sb_PTY",20,300,20000,10,2,4.5);	
	TH2D *D_PTY = new TH2D("D_Y","D_Y",20,300,20000,10,2,4.5);
	for(int i=0; i<NS; i++)
	{
		Splot -> GetEntry(i);
		wp = S.prompt_sw;
		wb = S.fromb_sw;
		N = S.PVNTRACKS[0];
		Y = 0.5 * log((S.psi_PE + S.psi_PZ)/(S.psi_PE - S.psi_PZ));
		PT = S.psi_PT;
		if(!(S.psi_OWNPV_Z>=-60)) continue;
		Sp_N -> Fill(N,wp);
		Sb_N -> Fill(N,wb);
		if(!(N>60)) continue;
		//Sp_N -> Fill(N,wp);
		Sp_PTY -> Fill(PT,Y,wp);
		//Sb_N -> Fill(N,wb);
                Sb_PTY -> Fill(PT,Y,wb);
	}
	for(int i=0; i<ND; i++)
        {
                McDecayTree -> GetEntry(i);
                N = D.PVNTRACKS[0];
		if(!(D.psi_OWNPV_Z>=-60)) continue;
                //if(!(N>60)) continue;
		Y = 0.5 * log((D.psi_PE + D.psi_PZ)/(D.psi_PE - D.psi_PZ));
                PT = D.psi_PT;
		if(D.psi_L0DiMuonDecision_TOS == 1&&D.psi_Hlt1DiMuonHighMassDecision_TOS == 1&&D.mum_PIDmu>2.&&D.mum_ProbNNmu>0.8&&D.mum_isMuon==1&&D.mup_PIDmu>2.&&D.mup_ProbNNmu>0.8&&D.mup_isMuon==1)
		{
                	D_N -> Fill(N);
                	if(!(N>60)) continue;
			D_PTY -> Fill(PT,Y);
		}
        }
	//normalize them
	Sp_N -> Scale(1.0/Sp_N->Integral());
	Sb_N -> Scale(1.0/Sb_N->Integral());
	D_N -> Scale(1.0/D_N->Integral());
	Sp_PTY -> Scale(1.0/Sp_PTY->Integral());
	Sb_PTY -> Scale(1.0/Sb_PTY->Integral());
	D_PTY -> Scale(1.0/D_PTY->Integral());

	//Save
	TH1D *reweightpN = new TH1D("reweightpN","reweightpN",50,0,200);
	TH2D *reweightpPTY = new TH2D("reweightpPTY","reweightpPTY",20,300,20000,10,2,4.5);
	TH1D *reweightbN = new TH1D("reweightbN","reweightbN",50,0,200);
        TH2D *reweightbPTY = new TH2D("reweightbPTY","reweightbPTY",20,300,20000,10,2,4.5);
	reweightpN -> Divide(Sp_N,D_N,1.,1.,"B");
        reweightpPTY -> Divide(Sp_PTY,D_PTY,1.,1.,"B");
	reweightbN -> Divide(Sb_N,D_N,1.,1.,"B");
        reweightbPTY -> Divide(Sb_PTY,D_PTY,1.,1.,"B");
	reweightpN -> Write();
	reweightpPTY -> Write();
	reweightbN -> Write();
        reweightbPTY -> Write();
	Sp_N -> Write();
	Sb_N -> Write();
	D_N -> Write();
	Sp_PTY -> Write();
        Sb_PTY -> Write();
        D_PTY -> Write();
	F->Close();
	return 0;
}
