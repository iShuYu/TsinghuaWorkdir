#define sPlot_cxx
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
	int N;
	double rBR = 7.93/59.61;
	ifstream Bin("0_Bin/nbin");
	Bin >> N;
	double xf[N];
	double ypf[N], ybf[N], ypfStatsErr[N], ybfStatsErr[N], ypfSysErr[N], ybfSysErr[N];
	double rpf;
	double rbf;
	double xb[N];
        double ypb[N], ybb[N], ypbStatsErr[N], ybbStatsErr[N], ypbSysErr[N], ybbSysErr[N];
        double rpb;
        double rbb;
	ifstream pPb("../4_Result/Ratio/ForPlot.txt");
	ifstream Pbp("/disk411/lhcb/kangye/Leadp/BWorkdir/4_Result/Ratio/ForPlot.txt");
	pPb >> rpf >> rbf;
	Pbp >> rpb >> rbb;	
	for(int i=0;i<N;i++)
        {
		pPb >> xf[i] >> ypf[i] >> ybf[i] >> ypfStatsErr[i] >> ybfStatsErr[i] >> ypfSysErr[i] >> ybfSysErr[i];
		Pbp >> xb[i] >> ypb[i] >> ybb[i] >> ypbStatsErr[i] >> ybbStatsErr[i] >> ypbSysErr[i] >> ybbSysErr[i];
		ypf[i] = ypf[i]*rpf/rBR;
		ypfStatsErr[i] = ypfStatsErr[i]*rpf/rBR;
		ypfSysErr[i] = ypfSysErr[i]*rpf/rBR;
		ybf[i] = ybf[i]*rbf/rBR;
                ybfStatsErr[i] = ybfStatsErr[i]*rbf/rBR;
                ybfSysErr[i] = ybfSysErr[i]*rbf/rBR;
		ypb[i] = ypb[i]*rpb/rBR;
                ypbStatsErr[i] = ypbStatsErr[i]*rpb/rBR;
                ypbSysErr[i] = ypbSysErr[i]*rpb/rBR;
                ybb[i] = ybb[i]*rbb/rBR;
                ybbStatsErr[i] = ybbStatsErr[i]*rbb/rBR;
                ybbSysErr[i] = ybbSysErr[i]*rbb/rBR;
		cout << xf[i]<<" " << ypf[i]  << " ";
		cout << 0.1 <<" " << ypfSysErr[i] <<endl;
	}
	//Draw
	setLHCbStyle();
	TCanvas *can = new TCanvas("can","can",1200,800);
	double width[N];
       	for(int i=0;i<N;i++)
	{
		width[i] = 0.1;
	}
	TF1 *unit = new TF1("unit","1+x-x",0,3);
        unit -> SetLineStyle(2);
        unit -> SetLineColor(1);
        unit -> GetYaxis() -> SetRangeUser(0,0.03/rBR);
        unit -> GetXaxis()->SetTitle("#frac{nBackTracks}{        <nBackTracks>_{NoBias}}");
        unit -> GetYaxis()->SetTitle("#sigma_{#psi(2S)}/#sigma_{J/#psi}");
        unit -> Draw();
	TGraphErrors *TGEf = new TGraphErrors(N,xf,ypf,width,ypfSysErr);
	TGraphErrors *TGEb = new TGraphErrors(N,xb,ypb,width,ypbSysErr);
	TGEf -> SetMarkerColor(12);
	TGEb -> SetMarkerColor(kViolet);
	TGEf -> SetMarkerStyle(21);
	TGEb -> SetMarkerStyle(21);
	TGEf -> SetFillColorAlpha(12,0.25);
	TGEb -> SetFillColorAlpha(kViolet,0.75);
	TGEf -> Draw("E2PZsame");
	TGEb -> Draw("E2PZsame");
	TLegend *legSys = new TLegend(0.18,0.25,0.38,0.39);
	legSys->SetTextFont(132);
	legSys->SetBorderSize(2);
	legSys->SetTextSize(0.05);
	legSys->AddEntry(TGEf,"p-Pb","F");
	legSys->AddEntry(TGEb,"Pb-p","F");
	legSys->Draw("same");	
	TGraphAsymmErrors *TGAEf = new TGraphAsymmErrors(N,xf,ypf,0,0,ypfStatsErr,ypfStatsErr);
	TGraphAsymmErrors *TGAEb = new TGraphAsymmErrors(N,xb,ypb,0,0,ypbStatsErr,ypbStatsErr);
	TGAEf -> SetMarkerColor(12);
	TGAEb -> SetMarkerColor(kViolet);
	TGAEf -> SetMarkerStyle(21);
	TGAEb -> SetMarkerStyle(21);
	TGAEf -> Draw("PZsame");
	TGAEb -> Draw("PZsame");		
	can -> SaveAs("../5_Plots/Result/Compare.pdf");
	can -> Close();
	return 0;
}
