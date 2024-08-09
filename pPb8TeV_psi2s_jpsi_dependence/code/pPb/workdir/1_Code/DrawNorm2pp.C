#define sPlot_cxx
#include <TGraphMultiErrors.h>
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
	double Nf_noBias = 60.54;
	double Nb_noBias = 69.54;
	double BRErr = 0.022;
	double ppFlag = 0.14163860; //0.1416386is ppResult in 13TeV
	ppFlag = 1;
	double rBR = 7.93/59.61*ppFlag; 
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
	ifstream Pbp("/disk411/lhcb/kangye/Leadp/Workdir/4_Result/Ratio/ForPlot.txt");
	pPb >> rpf >> rbf;
	Pbp >> rpb >> rbb;	
	for(int i=0;i<N;i++)
        {
		pPb >> xf[i] >> ypf[i] >> ybf[i] >> ypfStatsErr[i] >> ybfStatsErr[i] >> ypfSysErr[i] >> ybfSysErr[i];
		Pbp >> xb[i] >> ypb[i] >> ybb[i] >> ypbStatsErr[i] >> ybbStatsErr[i] >> ypbSysErr[i] >> ybbSysErr[i];

		ypf[i] = ypf[i]*rpf/rBR;
		ypfStatsErr[i] = ypfStatsErr[i]*rpf/rBR;
		ypfSysErr[i] = sqrt(pow(ypfSysErr[i]/ypf[i],2)+BRErr*BRErr)*ypf[i]*rpf/rBR;
		
		ybf[i] = ybf[i]*rbf/rBR;
                ybfStatsErr[i] = ybfStatsErr[i]*rbf/rBR;
                ybfSysErr[i] = sqrt(pow(ybfSysErr[i]/ybf[i],2)+BRErr*BRErr)*ybf[i]*rbf/rBR;
		
		ypb[i] = ypb[i]*rpb/rBR;
                ypbStatsErr[i] = ypbStatsErr[i]*rpb/rBR;
                ypbSysErr[i] = sqrt(pow(ypbSysErr[i]/ypb[i],2)+BRErr*BRErr)*ypb[i]*rpb/rBR;
                
		ybb[i] = ybb[i]*rbb/rBR;
                ybbStatsErr[i] = ybbStatsErr[i]*rbb/rBR;
                ybbSysErr[i] = sqrt(pow(ybbSysErr[i]/ybb[i],2)+BRErr*BRErr)*ybb[i]*rbb/rBR;
	}
	int bin[N+1];
	for(int i=0;i<=N;i++)
	{
		Bin >> bin[i];
	}
	double xf_lo[N], xf_hi[N];
	for(int i=0; i<N; i++)
        {
		xf_lo[i] = xf[i] - bin[i]/Nf_noBias;
		xf_hi[i] = bin[i+1]/Nf_noBias-xf[i];
		xf_lo[i] = 0.024;
                xf_hi[i] = 0.024;
	}
	ifstream Binb("/disk411/lhcb/kangye/Leadp/Workdir/3_Script/0_Bin/nbin");
	Binb >> N;
	for(int i=0;i<=N;i++)
	{
		Binb >> bin[i];
	}
	double xb_lo[N], xb_hi[N];
	for(int i=0; i<N; i++)
        {
		xb_lo[i] = xb[i] - bin[i]/Nb_noBias;
		xb_hi[i] = bin[i+1]/Nb_noBias-xb[i];
		xb_lo[i] = 0.024;
		xb_hi[i] = 0.024;
	}

	//Draw
	setLHCbStyle();
	TCanvas *can = new TCanvas("can","can",1200,800);
	TGraphMultiErrors *TGEf = new TGraphMultiErrors(N,xf,ypf,xf_lo,xf_hi,ypfStatsErr,ypfStatsErr);
	TGraphMultiErrors *TGEb = new TGraphMultiErrors(N,xb,ypb,xb_lo,xb_hi,ypbStatsErr,ypbStatsErr);
	TGEf -> AddYError(N,ypfSysErr,ypfSysErr);
	TGEb -> AddYError(N,ypbSysErr,ypbSysErr);
	TGEf -> SetMarkerColor(kRed);
	TGEb -> SetMarkerColor(kMagenta);
	TGEf -> SetLineColor(kRed);
	TGEb -> SetLineColor(kMagenta);
	TGEf -> SetMarkerStyle(21);
	TGEb -> SetMarkerStyle(21);
	TGEf -> GetAttLine(0)->SetLineColor(kRed);
   	TGEf -> GetAttLine(1)->SetLineColor(kRed);
   	TGEf -> GetAttFill(1)->SetFillStyle(0);
	TGEb -> GetAttLine(0)->SetLineColor(kMagenta);
   	TGEb -> GetAttLine(1)->SetLineColor(kMagenta);
   	TGEb -> GetAttFill(1)->SetFillStyle(0);
	TGEf -> GetXaxis() -> SetLimits(0,3);
	TGEf -> Draw("APS same; Z ; 5 s=1 ; same");
	TGEb -> Draw("PS same; Z ; 5 s=1 ; same");
	TGEf -> GetXaxis()->SetTitle("#font[12]{N}_{tracks}^{PV}/#LT#font[12]{N}_{tracks}^{PV}#GT_{NB}");
        TGEf -> GetYaxis()->SetTitle("#sigma_{#psi(2S)}/#sigma_{J/#psi}");
	TGEf -> GetYaxis()->SetRangeUser(0,0.22);
	TLegend *legSys = new TLegend(0.25,0.25,0.40,0.40);
	legSys->SetTextFont(132);
	legSys->SetBorderSize(2);
	legSys->SetTextSize(0.06);
	legSys->AddEntry(TGEf,"p-Pb","PLEZ");
	legSys->AddEntry(TGEb,"Pb-p","PLEZ");
	legSys->Draw("same");	
	lhcbName->Draw();
	can -> SaveAs("../5_Plots/Result/Norm.pdf");
	can -> Close();
	return 0;
}
