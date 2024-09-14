#define sPlot_cxx
#include <TGraphMultiErrors.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <iostream>
#include <fstream>
#include <TFile.h>
#include <TH1D.h>
#include <math.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TLegend.h>
#include "0_header/lhcbStyle.h"
#include "0_header/sPlot.h"
using namespace std;
int main(int argc, char* argv[])
{
	//input nbin
	int N = 5;
	double bin[6] = {4, 45, 70, 90, 120, 270};

	//input fit result and Stats Err
	double NJprompt[N], NJfromb[N], NPprompt[N], NPfromb[N];
	double NJpromptErr[N], NJfrombErr[N], NPpromptErr[N], NPfrombErr[N];
	double yp[N], yb[N], ypStatsErr[N], ybStatsErr[N];
	for(int i=0;i<N;i++)
	{
		ifstream inJ(Form("../4_Result/TwoDimFit/Jpsi_n%dy1pt1.txt",i+1));
		inJ >> NJprompt[i] >> NJpromptErr[i] >> NJfromb[i] >> NJfrombErr[i];
		inJ.close();
		ifstream inP(Form("../4_Result/TwoDimFit/Psi2S_n%dy1pt1.txt",i+1));
		inP >> NPprompt[i] >> NPpromptErr[i] >> NPfromb[i] >> NPfrombErr[i];
		yp[i] = NPprompt[i]/NJprompt[i];
		yb[i] = NPfromb[i]/NJfromb[i];
		inP.close();
	}
	
	//Draw
	setLHCbStyle();
	TCanvas *can = new TCanvas("can","can",1200,800);
	TH1D *tJp = new TH1D("tJp","tJp",N,bin);
	TH1D *tPp = new TH1D("tPp","tPp",N,bin);
	TH1D *tJb = new TH1D("tJb","tJb",N,bin);
	TH1D *tPb = new TH1D("tPb","tPb",N,bin);
	for(int i=0;i<N;i++)
	{
		tJp -> SetBinContent(i+1,NJprompt[i]);
		tJb -> SetBinContent(i+1,NJfromb[i]);
		tJp -> SetBinError(i+1,NJpromptErr[i]);
                tJb -> SetBinError(i+1,NJfrombErr[i]);
		tPp -> SetBinContent(i+1,NPprompt[i]);
                tPb -> SetBinContent(i+1,NPfromb[i]);
                tPp -> SetBinError(i+1,NPpromptErr[i]);
                tPb -> SetBinError(i+1,NPfrombErr[i]);
	}
	tJp -> SetLineColor(1);
	tJp -> SetMarkerColor(1);
	tJp -> GetXaxis() -> SetTitle("#font[12]{N}^{PV}_{tracks}");
	tJp -> GetYaxis() -> SetTitle("Yields");
	tJp -> GetYaxis() -> SetRangeUser(1,10000000);
	tJp -> Draw();
	tJb -> SetLineColor(2);
	tJb -> SetMarkerColor(2);
	tJb -> Draw("same");
	tPp -> SetLineColor(3);
	tPp -> SetMarkerColor(3);
        tPp -> Draw("same");
	tPb -> SetLineColor(4);
	tPb -> SetMarkerColor(4);
        tPb -> Draw("same");
	can -> SetLogy();
	TLegend *leg = new TLegend(0.6,0.75,0.9,0.9);
	leg -> AddEntry(tJp, "prompt J/#psi");
	leg -> AddEntry(tJb, "non-prompt J/#psi");
	TLegend *leg1 = new TLegend(0.57,0.23,0.9,0.4);
	leg1 -> AddEntry(tPp, "prompt #psi(2S)");
        leg1 -> AddEntry(tPb, "non-prompt #psi(2S)");
	leg1 -> Draw("same");
	leg -> Draw("same");
	can -> SaveAs("../5_Plots/Result/Yield.pdf");
	return 0;
}
