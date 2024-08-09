#define sPlot_cxx
#include <TGraphMultiErrors.h>
#include <TGraphAsymmErrors.h>
#include <TGraphErrors.h>
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
#include "0_header/lhcbStyle1.h"
#include "0_header/sPlot.h"
using namespace std;
int main(int argc, char* argv[])
{
	const int nt = 5;
	double xt[nt] = {0,60,120,18,240};
	double ext[nt] = {0.};
	double yt[nt] = {0.0107,0.0107,0.0107,0.0107,0.0107};
	double yterr[nt] = {0.0016,0.0016,0.0016,0.0016,0.0016};
	TGraphErrors *ta = new TGraphErrors(nt,xt,yt,ext,yterr);
	ta->SetFillColor(kMagenta);
	ta->SetFillStyle(3004);
	//pp result
	double BRErr = 0.022;
        double r = 0.01894;
	double rBR = 7.93/59.61;
	ifstream ppBin("/nishome/kangye/disk402_ppAnalysis/ForWorkdir/Yield/result/3_Result/promptBin.txt");
        double ppNobias = 16.14;
        int Npp;
        ppBin >> Npp;
	double xpp[Npp];
        for(int i = 0; i<Npp; i++)
        {
                ppBin >> xpp[i];
                xpp[i] = xpp[i]*ppNobias;
        }
        ifstream ppbin("/nishome/kangye/disk402_ppAnalysis/ForWorkdir/Yield/rawdata/3_Bins/nbin");
        ppbin >> Npp;
        double x_lo[Npp], x_hi[Npp], b[Npp+1];
        for(int i=0; i<Npp+1; i++)
        {
                ppbin >> b[i];
        }
        for(int i=0; i<Npp; i++)
        {
                x_lo[i] = xpp[i] - b[i];
                x_hi[i] = b[i+1] - xpp[i];
		x_lo[i] = 1.2;
		x_hi[i] = 1.2;
        }

        TFile *allT = TFile::Open("/nishome/kangye/disk402_ppAnalysis/ForWorkdir/Yield/result/3_Result/SaveSys.root");
        TH1D *tempSysp = (TH1D*)allT->Get("allp");
        allT = TFile::Open("/nishome/kangye/disk402_ppAnalysis/ForWorkdir/Yield/result/3_Result/SaveStats.root");
        TH1D *tempStatsp = (TH1D*)allT->Get("allp");
        double yp[Npp], yp_lo[Npp], yp_hi[Npp];
	for(int i=1;i<=Npp;i++)
        {
                yp[i-1]=tempStatsp->GetBinContent(i)*r;
                yp_lo[i-1]=tempStatsp->GetBinError(i)*r;
                yp_hi[i-1]=yp_lo[i-1];
        }
        //Sys Err
        double pHeight[Npp];
        for(int i=1;i<=Npp;i++)
        {
                pHeight[i-1]=tempSysp->GetBinError(i)*r;
        }

	
	
	
	//input nbin
	int N;
	double Nf_noBias = 33.17;
	double Nb_noBias = 47.07;
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
	ifstream Pbp("/disk411/lhcb/kangye/Leadp/FWorkdir/4_Result/Ratio/ForPlot.txt");
	pPb >> rpf >> rbf;
	Pbp >> rpb >> rbb;	
	for(int i=0;i<N;i++)
        {
		pPb >> xf[i] >> ypf[i] >> ybf[i] >> ypfStatsErr[i] >> ybfStatsErr[i] >> ypfSysErr[i] >> ybfSysErr[i];
		Pbp >> xb[i] >> ypb[i] >> ybb[i] >> ypbStatsErr[i] >> ybbStatsErr[i] >> ypbSysErr[i] >> ybbSysErr[i];

		ypf[i] = ypf[i]*rpf;
		ypfStatsErr[i] = ypfStatsErr[i]*rpf;
		ypfSysErr[i] = sqrt(pow(ypfSysErr[i]/ypf[i],2)+BRErr*BRErr)*ypf[i]*rpf;
		
		ybf[i] = ybf[i]*rbf;
                ybfStatsErr[i] = ybfStatsErr[i]*rbf;
                ybfSysErr[i] = sqrt(pow(ybfSysErr[i]/ybf[i],2)+BRErr*BRErr)*ybf[i]*rbf;
		
		ypb[i] = ypb[i]*rpb;
                ypbStatsErr[i] = ypbStatsErr[i]*rpb;
                ypbSysErr[i] = sqrt(pow(ypbSysErr[i]/ypb[i],2)+BRErr*BRErr)*ypb[i]*rpb;
                
		ybb[i] = ybb[i]*rbb;
                ybbStatsErr[i] = ybbStatsErr[i]*rbb;
                ybbSysErr[i] = sqrt(pow(ybbSysErr[i]/ybb[i],2)+BRErr*BRErr)*ybb[i]*rbb;
	}
	int bin[N+1];
	for(int i=0;i<=N;i++)
	{
		Bin >> bin[i];
	}
	Bin.close();
	pPb.close();
	Pbp.close();
	double xf_lo[N], xf_hi[N];
	for(int i=0; i<N; i++)
        {
		xf_lo[i] = xf[i]*Nf_noBias - bin[i];
		xf_hi[i] = bin[i+1] - xf[i]*Nf_noBias;
		xf_hi[i] = 1.2;
		xf_lo[i] = 1.2;
		xf[i] = xf[i]*Nf_noBias;
	}
	ifstream Binb("/disk411/lhcb/kangye/Leadp/FWorkdir/3_Script/0_Bin/nbin");
	Binb >> N;
	for(int i=0;i<=N;i++)
	{
		Binb >> bin[i];
	}
	Binb.close();
	double xb_lo[N];
       	double xb_hi[N];
	for(int i=0; i<N; i++)
        {
		xb_lo[i] = xb[i]*Nb_noBias - bin[i];
		xb_hi[i] = bin[i+1]-xb[i]*Nb_noBias;
		xb_lo[i] = 1.2;
		xb_hi[i] = 1.2;
		xb[i] = xb[i]*Nb_noBias;
	}
	
	//Draw
	setLHCbStyle();
	TCanvas *can = new TCanvas("can","can",1200,800);
	TGraphMultiErrors *TGE = new TGraphMultiErrors(Npp,xpp,yp,x_lo,x_hi,yp_lo,yp_hi);
	TGraphMultiErrors *TGEf = new TGraphMultiErrors(N,xf,ypf,xf_lo,xf_hi,ypfStatsErr,ypfStatsErr);
	TGraphMultiErrors *TGEb = new TGraphMultiErrors(N,xb,ypb,xb_lo,xb_hi,ypbStatsErr,ypbStatsErr);

	TGE -> AddYError(Npp,pHeight,pHeight);
	TGEf -> AddYError(N,ypfSysErr,ypfSysErr);
	TGEb -> AddYError(N,ypbSysErr,ypbSysErr);
	TGE -> SetMarkerColor(kRed);
	TGEf -> SetMarkerColor(kBlue);
	TGEb -> SetMarkerColor(kGreen);
	TGE -> SetLineColor(kRed);
	TGEf -> SetLineColor(kBlue);
	TGEb -> SetLineColor(kGreen);
	TGE -> SetMarkerStyle(21);
	TGEf -> SetMarkerStyle(21);
	TGEb -> SetMarkerStyle(21);
	TGE -> GetAttLine(0)->SetLineColor(kRed);
        TGE -> GetAttLine(1)->SetLineColor(kRed);
	TGE -> GetAttFill(1)->SetFillStyle(0);
	TGEf -> GetAttLine(0)->SetLineColor(kBlue);
   	TGEf -> GetAttLine(1)->SetLineColor(kBlue);
   	TGEf -> GetAttFill(1)->SetFillStyle(0);
	TGEb -> GetAttLine(0)->SetLineColor(kGreen);
   	TGEb -> GetAttLine(1)->SetLineColor(kGreen);
   	TGEb -> GetAttFill(1)->SetFillStyle(0);
	TGEf -> GetXaxis()->SetLimits(0,150);
	TGEf -> Draw("APS same; Z ; 5 s=1 ; same");
	TGEb -> Draw("PS same; Z ; 5 s=1 ; same");
	TGE -> Draw("PS same; Z ; 5 s=1 ; same");
	ta->Draw("e3same");
	TGEf -> GetXaxis()->SetTitle("#font[12]{N}_{fwd}^{PV}");
        TGEf -> GetYaxis()->SetTitle("BR #sigma_{#psi(2S)}/BR #sigma_{J/#psi}");
	TGEf -> GetYaxis()->SetRangeUser(0,0.030);
	//TGEf -> GetXaxis()->SetLimits(0,240);
	TLegend *legSys = new TLegend(0.2,0.2,0.50,0.40);
	legSys->SetTextFont(132);
	legSys->SetBorderSize(2);
	legSys->SetTextSize(0.04);
	legSys->AddEntry(TGE,"LHC#font[12]{b} #font[12]{pp} #sqrt{s} = 13 TeV","PLEZ");
	legSys->AddEntry(TGEf,"LHC#font[12]{b} #font[12]{p}Pb #sqrt{s_{NN}} = 8.16 TeV","PLEZ");
	legSys->AddEntry(TGEb,"LHC#font[12]{b} Pb#font[12]{p} #sqrt{s_{NN}} = 8.16 TeV","PLEZ");
	legSys->AddEntry(ta,"ALICE PbPb #sqrt{s_{NN}} = 5.02 TeV", "F");
	legSys->Draw("same");	
	lhcbName->Draw();
	can -> SaveAs("../5_Plots/Result/pppPb.pdf");
	can -> Close();
	return 0;
}
