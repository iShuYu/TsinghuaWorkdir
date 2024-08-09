#define CBSplotDecayTree_cxx
#include "../../Jpsi/0_CFile/header/CBSplotDecayTree.h"
#include <TTree.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream Xb("../3_Result/XBackInForwardFromb.txt");
	ofstream Xp("../3_Result/XBackInForwardPrompt.txt");
	TH1D *tjp[5];
	TH1D *tpp[5];
	TH1D *tjb[5];
	TH1D *tpb[5];
	for(int i=1;i<=5;i++){
		TChain *CJ = new TChain("DecayTree");
		TChain *CP = new TChain("DecayTree");
		for(int pt=1;pt<=5;pt++){
			for(int y=1;y<=3;y++){
				CJ -> Add(Form("../../Jpsi/3_Result/2DFit/splot_n%dy%dpt%d.root",i,y,pt));
				CP -> Add(Form("../../Psi2S/3_Result/2DFit/splot_n%dy%dpt%d.root",i,y,pt));
			}
		}
		CBSplotDecayTree J(CJ);
		CBSplotDecayTree P(CP);
		int NJ = CJ -> GetEntries();
		int NP = CP -> GetEntries();
		double Jprompt = 0.;
	       	double Jfromb = 0.;
		double Pprompt = 0.;
	       	double Pfromb = 0.;
		tjp[i-1] = new TH1D(Form("tjp%d",i),Form("tjp%d",i),150,0,150);
		tpp[i-1] = new TH1D(Form("tpp%d",i),Form("tpp%d",i),150,0,150); 
		tjb[i-1] = new TH1D(Form("tjb%d",i),Form("tjb%d",i),150,0,150);
		tpb[i-1] = new TH1D(Form("tpb%d",i),Form("tpb%d",i),150,0,150); 
		for(int j=0; j<NJ; j++){
			CJ -> GetEntry(j);
			Jprompt = Jprompt + J.prompt_sw;
			Jfromb = Jfromb + J.fromb_sw;
			tjp[i-1] -> Fill(J.psi_nForWardTracks,J.prompt_sw);
			tjb[i-1] -> Fill(J.psi_nForWardTracks,J.fromb_sw);
		}
		for(int p=0; p<NP; p++){
			CP -> GetEntry(p);
			Pprompt = Pprompt + P.prompt_sw;
			Pfromb = Pfromb + P.fromb_sw;
			tpp[i-1] -> Fill(P.psi_nForWardTracks,P.prompt_sw);
			tpb[i-1] -> Fill(P.psi_nForWardTracks,P.fromb_sw);
		}
		double meanjp = tjp[i-1]->GetMean();
		double meanjb = tjb[i-1]->GetMean();
		double meanpp = tpp[i-1]->GetMean();
		double meanpb = tpb[i-1]->GetMean();
		double stdjp = tjp[i-1]->GetStdDev();
		double stdjb = tjb[i-1]->GetStdDev();
		double stdpp = tpp[i-1]->GetStdDev();
		double stdpb = tpb[i-1]->GetStdDev();
		double wjp = Jprompt/stdjp/stdjp;
		double wjb = Jfromb/stdjb/stdjb;
		double wpp = Pprompt/stdpp/stdpp;
		double wpb = Pfromb/stdpb/stdpb;
		Xb << (meanjb*wjb/(wjb+wpb)+meanpb*wpb/(wjb+wpb))/16.14 << endl;
		Xp << (meanjp*wjp/(wjp+wpp)+meanpp*wpp/(wjp+wpp))/16.14 << endl;
	}
	return 0;
}
