#define MCDecayTree_Cut_cxx
#define sPlot_cxx
#include "0_header/MCDecayTree_Cut.h"
#include "0_header/sPlot.h"
#include <TStyle.h>
#include <TH1.h>
#include <TH1D.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
	//input
	int hi_lo = 33; //mean of PVNTRACKS, divide hi lo sample
	TH1::SetDefaultSumw2();
	TChain *SplotJ = new TChain("DecayTree");
	TChain *SplotP = new TChain("DecayTree");
	SplotJ -> Add("../4_Result/CBFit/sPlot/Jpsi.root");
	SplotP -> Add("../4_Result/CBFit/sPlot/Psi2S.root");
	sPlot SJ(SplotJ);
	sPlot SP(SplotP);
	TChain *McDecayTreeJ = new TChain("DecayTree");
	TChain *McDecayTreeP = new TChain("DecayTree");
	McDecayTreeJ -> Add("../0_File/MC/Cut/Jpsi.root");
	McDecayTreeP -> Add("../0_File/MC/Cut/Psi2S.root");
	MCDecayTree_Cut DJ(McDecayTreeJ);
	MCDecayTree_Cut DP(McDecayTreeP);

	//output, saving reweight of pt, y and multiplicity
	TFile *F = new TFile("../4_Result/Reweight/Reweight.root","recreate");

	//Loop
	int NSJ = SplotJ -> GetEntries();
	int NSP = SplotP -> GetEntries();
	int NDJ = McDecayTreeJ -> GetEntries();
	int NDP = McDecayTreeP -> GetEntries();
	double PT, Y, N, w;
	TH1D *SJ_N = new TH1D("SJ_N","SJ_N",30,0,180);
	TH1D *SP_N = new TH1D("SP_N","SP_N",30,0,180);
	TH1D *DJ_N = new TH1D("DJ_N","DJ_N",30,0,180);
	TH1D *DP_N = new TH1D("DP_N","DP_N",30,0,180);
	TH1D *SJ_PT = new TH1D("SJ_PT","SJ_PT",20,0,14000);
	TH1D *SP_PT = new TH1D("SP_PT","SP_PT",20,0,14000);
	TH1D *SJ_Y = new TH1D("SJ_Y","SJ_Y",6,1.5,4.5);
	TH1D *SP_Y = new TH1D("SP_Y","SP_Y",6,1.5,4.5);
	TH1D *SJ_hiPT = new TH1D("SJ_hiPT","SJ_hiPT",20,0,14000);
	TH1D *SP_hiPT = new TH1D("SP_hiPT","SP_hiPT",20,0,14000);
	TH1D *SJ_loPT = new TH1D("SJ_loPT","SJ_loPT",20,0,14000);
	TH1D *SP_loPT = new TH1D("SP_loPT","SP_loPT",20,0,14000);
	TH1D *SJ_hiY = new TH1D("SJ_hiY","SJ_hiY",6,1.5,4.5);
	TH1D *SP_hiY = new TH1D("SP_hiY","SP_hiY",6,1.5,4.5);
	TH1D *SJ_loY = new TH1D("SJ_loY","SJ_loY",6,1.5,4.5);
	TH1D *SP_loY = new TH1D("SP_loY","SP_loY",6,1.5,4.5);
	TH1D *DJ_hiPT = new TH1D("DJ_hiPT","DJ_hiPT",20,0,14000);
	TH1D *DP_hiPT = new TH1D("DP_hiPT","DP_hiPT",20,0,14000);
	TH1D *DJ_loPT = new TH1D("DJ_loPT","DJ_loPT",20,0,14000);
	TH1D *DP_loPT = new TH1D("DP_loPT","DP_loPT",20,0,14000);
	TH1D *DJ_hiY = new TH1D("DJ_hiY","DJ_hiY",6,1.5,4.5);
	TH1D *DP_hiY = new TH1D("DP_hiY","DP_hiY",6,1.5,4.5);
	TH1D *DJ_loY = new TH1D("DJ_loY","DJ_loY",6,1.5,4.5);
	TH1D *DP_loY = new TH1D("DP_loY","DP_loY",6,1.5,4.5);
	//Fill Jpsi Splot
	for(int i=0; i<NSJ; i++)
	{
		SplotJ -> GetEntry(i);
		if(!(SJ.psi_OWNPV_Z>=-30)) continue;
		w = SJ.sig_sw;
		N = SJ.psi_nBackTracks;
		Y = SJ.psi_Y;
		PT = SJ.psi_PT;
		SJ_N -> Fill(N,w);
		SJ_PT -> Fill(PT,w);
		SJ_Y -> Fill(Y,w);
		if(N>=hi_lo)
		{
			SJ_hiPT -> Fill(PT,w);
			SJ_hiY -> Fill(Y,w);
		}
		if(N<hi_lo)
		{
			SJ_loPT -> Fill(PT,w);
			SJ_loY -> Fill(Y,w);
		}

	}
	//Fill Psi2S Splot
	for(int i=0; i<NSP; i++)
	{
		SplotP -> GetEntry(i);
		if(!(SP.psi_OWNPV_Z>=-30)) continue;
		w = SP.sig_sw;
		N = SP.psi_nBackTracks;
		Y = SP.psi_Y;
		PT = SP.psi_PT;
		SP_N -> Fill(N,w);
		SP_PT -> Fill(PT,w);
		SP_Y -> Fill(Y,w);
		if(N>=hi_lo)
		{
			SP_hiPT -> Fill(PT,w);
			SP_hiY -> Fill(Y,w);
		}
		if(N<hi_lo)
		{
			SP_loPT -> Fill(PT,w);
			SP_loY -> Fill(Y,w);
		}
	}
	//Fill MC Jpsi
	for(int i=0; i<NDJ; i++)
        {
                McDecayTreeJ -> GetEntry(i);
		if(!(DJ.psi_OWNPV_Z>=-30)) continue;
		if(!(DJ.psi_L0MuonDecision_TOS==1)) continue;
		if(!(DJ.psi_Hlt1DiMuonHighMassDecision_TOS==1)) continue;
		if(!(DJ.mum_ProbNNmu>0.9)) continue;
		if(!(DJ.mup_ProbNNmu>0.9)) continue;
		if(!(DJ.mum_isMuon==1)) continue;
		if(!(DJ.mup_isMuon==1)) continue;
		N = DJ.nBackTracks;
                Y = DJ.psi_Y;
                PT = DJ.psi_PT;
		DJ_N -> Fill(N);
		if(N>=hi_lo)
		{
                	DJ_hiPT -> Fill(PT);
                	DJ_hiY -> Fill(Y);
		}
		if(N<hi_lo)
		{
                	DJ_loPT -> Fill(PT);
                	DJ_loY -> Fill(Y);
		}
        }
	//Fill MC Psi2S
	for(int i=0; i<NDP; i++)
        {
                McDecayTreeP -> GetEntry(i);
                if(!(DP.psi_OWNPV_Z>=-30)) continue;
                if(!(DP.psi_L0MuonDecision_TOS==1)) continue;
                if(!(DP.psi_Hlt1DiMuonHighMassDecision_TOS==1)) continue;
                if(!(DP.mum_ProbNNmu>0.9)) continue;
                if(!(DP.mup_ProbNNmu>0.9)) continue;
                if(!(DP.mum_isMuon==1)) continue;
                if(!(DP.mup_isMuon==1)) continue;
                N = DP.nBackTracks;
                Y = DP.psi_Y;
                PT = DP.psi_PT;
		DP_N -> Fill(N);
                if(N>=hi_lo)
                {
                        DP_hiPT -> Fill(PT);
                        DP_hiY -> Fill(Y);
                }
                if(N<hi_lo)
                {
                        DP_loPT -> Fill(PT);
                        DP_loY -> Fill(Y);
                }
        }

	//normalize
	SJ_PT->Scale(1.0/SJ_PT->Integral());
	SP_PT->Scale(1.0/SP_PT->Integral());
	SJ_Y->Scale(1.0/SJ_Y->Integral());
	SP_Y->Scale(1.0/SP_Y->Integral());
	SJ_N->Scale(1.0/SJ_N->Integral());
	SP_N->Scale(1.0/SP_N->Integral());
	DJ_N->Scale(1.0/DJ_N->Integral());
	DP_N->Scale(1.0/DP_N->Integral());
	SJ_hiPT->Scale(1.0/SJ_hiPT->Integral());
	SJ_loPT->Scale(1.0/SJ_loPT->Integral());
	SJ_hiY ->Scale(1.0/SJ_hiY->Integral());
	SJ_loY ->Scale(1.0/SJ_loY->Integral());
	SP_hiPT->Scale(1.0/SP_hiPT->Integral());
	SP_loPT->Scale(1.0/SP_loPT->Integral());
	SP_hiY ->Scale(1.0/SP_hiY->Integral());
	SP_loY ->Scale(1.0/SP_loY->Integral());
	DJ_hiPT->Scale(1.0/DJ_hiPT->Integral());
	DJ_loPT->Scale(1.0/DJ_loPT->Integral());
	DJ_hiY ->Scale(1.0/DJ_hiY->Integral());
	DJ_loY ->Scale(1.0/DJ_loY->Integral());
	DP_hiPT->Scale(1.0/DP_hiPT->Integral());
	DP_loPT->Scale(1.0/DP_loPT->Integral());
	DP_hiY ->Scale(1.0/DP_hiY->Integral());
	DP_loY ->Scale(1.0/DP_loY->Integral());

	//Save
	TH1D *wJ_N = new TH1D("wJ_N","wJ_N",30,0,180);
	TH1D *wP_N = new TH1D("wP_N","wP_N",30,0,180);
	TH1D *wJ_hiPT = new TH1D("wJ_hiPT","wJ_hiPT",20,0,14000);
	TH1D *wP_hiPT = new TH1D("wP_hiPT","wP_hiPT",20,0,14000);
	TH1D *wJ_hiY = new TH1D("wJ_hiY","wJ_hiY",6,1.5,4.5);
        TH1D *wP_hiY = new TH1D("wP_hiY","wP_hiY",6,1.5,4.5);
	TH1D *wJ_loPT = new TH1D("wJ_loPT","wJ_loPT",20,0,14000);
        TH1D *wP_loPT = new TH1D("wP_loPT","wP_loPT",20,0,14000);
        TH1D *wJ_loY = new TH1D("wJ_loY","wJ_loY",6,1.5,4.5);
        TH1D *wP_loY = new TH1D("wP_loY","wP_loY",6,1.5,4.5);
	wJ_N -> Divide(SJ_N, DJ_N, 1., 1., "B");
	wP_N -> Divide(SP_N, DP_N, 1., 1., "B");
	wJ_hiPT -> Divide(SJ_hiPT, DJ_hiPT, 1., 1., "B");
	wJ_loPT -> Divide(SJ_loPT, DJ_loPT, 1., 1., "B");
	wJ_hiY -> Divide(SJ_hiY, DJ_hiY, 1., 1., "B");
	wJ_loY -> Divide(SJ_loY, DJ_loY, 1., 1., "B");
	wP_hiPT -> Divide(SP_hiPT, DP_hiPT, 1., 1., "B");
        wP_loPT -> Divide(SP_loPT, DP_loPT, 1., 1., "B");
        wP_hiY -> Divide(SP_hiY, DP_hiY, 1., 1., "B");
        wP_loY -> Divide(SP_loY, DP_loY, 1., 1., "B");
	wJ_N -> Write();
	wP_N -> Write();
	wJ_hiPT -> Write();	 
	wJ_loPT -> Write();
	wJ_hiY  -> Write();
	wJ_loY  -> Write();
	wP_hiPT -> Write(); 
	wP_loPT -> Write(); 
	wP_hiY  -> Write();
	wP_loY  -> Write();
	SJ_N -> Write();
	SP_N -> Write();
	DJ_N -> Write();
	DP_N -> Write();
	SJ_hiPT -> Write(); 
        SP_hiPT -> Write(); 
        SJ_loPT -> Write(); 
        SP_loPT -> Write(); 
        SJ_hiY  -> Write();
        SP_hiY  -> Write();
        SJ_loY  -> Write();
        SP_loY  -> Write();
        DJ_hiPT -> Write();
        DP_hiPT -> Write();
        DJ_loPT -> Write();
        DP_loPT -> Write();
        DJ_hiY  -> Write();
        DP_hiY  -> Write();
        DJ_loY  -> Write();
        DP_loY  -> Write();
	SJ_PT-> Write();
	SP_PT-> Write();
	SJ_Y->  Write();
	SP_Y->  Write();
	F -> Close();
	return 0;
}
