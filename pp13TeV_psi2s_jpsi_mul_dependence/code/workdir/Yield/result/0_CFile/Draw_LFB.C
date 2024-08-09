#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TAxis.h>
#include <fstream>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include "lhcbStyle.h"
#include <TF1.h>
using namespace std;
int main(int argc, char* argv[])
{
	vector<double>  y_s;
	vector<int> pt_s;
	vector<double> nL, nF, nB;
        double nbin, ybin, ptbin;
        int NL, NF, NB, Nybin, Nptbin;
        ifstream nCL(argv[1]);
	ifstream nCF(argv[2]);
	ifstream nCB(argv[3]);
        ifstream yconfig(argv[4]);
        ifstream ptconfig(argv[5]);
        nCL >> NL;
	nCF >> NF;
	nCB >> NB;
        yconfig >> Nybin;
        ptconfig >> Nptbin;
        for(int i=0; i<NL; i++)
        {
                nCL >> nbin;
                nL.push_back(nbin);
		nCF >> nbin;
                nF.push_back(nbin);
		nCB >> nbin;
                nB.push_back(nbin);
	}
        for(int i=0; i<=Nybin; i++)
        {
                yconfig >> ybin;
                y_s.push_back(ybin);
        }
        for(int i=0; i<=Nptbin; i++)
        {
                ptconfig >> ptbin;
                pt_s.push_back(ptbin);
        }
        double color[Nybin+Nptbin], marker[Nybin+Nptbin];
        gROOT->SetBatch(true);
        setLHCbStyle();
	//Draw total Modification
	//input
	int N = NL;
	double xL[N], xF[N], xB[N];
	double yL[N], yF[N], yB[N];
	double yL_lo[N], yL_hi[N];
        double yF_lo[N], yF_hi[N];
	double yB_lo[N], yB_hi[N];
	TCanvas *can = new TCanvas("can","can",1600,1200);
	TFile *allT = TFile::Open("../../result/3_Result/SaveSys.root");
	TH1D *sysL = (TH1D*)allT->Get("allp");
	allT = TFile::Open("../../result/3_Result/SaveStats.root");
        TH1D *statsL = (TH1D*)allT->Get("allp");
	allT = TFile::Open("~/forward_Workdir/Yield/result/3_Result/SaveSys.root");
        TH1D *sysF = (TH1D*)allT->Get("allp");
        allT = TFile::Open("~/forward_Workdir/Yield/result/3_Result/SaveStats.root");
        TH1D *statsF = (TH1D*)allT->Get("allp");
	allT = TFile::Open("~/back_workdir/Yield/result/3_Result/SaveSys.root");
        TH1D *sysB = (TH1D*)allT->Get("allp");
        allT = TFile::Open("~/back_workdir/Yield/result/3_Result/SaveStats.root");
        TH1D *statsB = (TH1D*)allT->Get("allp");
	//Stats
	for(int i=1;i<=N;i++)
	{
		xL[i-1]=nL[i-1];
		xF[i-1]=nF[i-1];
		xB[i-1]=nB[i-1];
		yL[i-1]=statsL->GetBinContent(i);
		yL_lo[i-1]=statsL->GetBinError(i);
		yL_hi[i-1]=yL_lo[i-1];
		yF[i-1]=statsF->GetBinContent(i);
                yF_lo[i-1]=statsF->GetBinError(i);
                yF_hi[i-1]=yF_lo[i-1];
		yB[i-1]=statsB->GetBinContent(i);
                yB_lo[i-1]=statsB->GetBinError(i);
                yB_hi[i-1]=yB_lo[i-1];
	}
	TF1 *unit = new TF1("unit","1+x-x",0,4.5);
        unit -> SetLineStyle(2);
        unit -> SetLineColor(1);
	unit -> SetTitle("Ratio for prompt signals");
	unit -> GetYaxis() -> SetRangeUser(0.4,1.6);
	unit -> GetXaxis()->SetTitle("#frac{n}{        <n>_{NoBias}}");
        unit -> GetYaxis()->SetTitle("Normalized #sigma_{#psi(2S)}/#sigma_{J/#psi}");
	unit -> Draw();
	TGraphAsymmErrors *TGAEL = new TGraphAsymmErrors(N,xL,yL,0,0,yL_lo,yL_hi);
	TGraphAsymmErrors *TGAEF = new TGraphAsymmErrors(N,xF,yF,0,0,yF_lo,yF_hi);
	TGraphAsymmErrors *TGAEB = new TGraphAsymmErrors(N,xB,yB,0,0,yB_lo,yB_hi);
	TGAEL -> SetMarkerColor(kRed);
	TGAEF -> SetMarkerColor(kGreen);
	TGAEB -> SetMarkerColor(kYellow);
	TGAEL -> SetMarkerStyle(21);
	TGAEF -> SetMarkerStyle(21);
	TGAEB -> SetMarkerStyle(21);
	TGAEL -> Draw("PZsame");
	TGAEF -> Draw("PZsame");
	TGAEB -> Draw("PZsame");
	//Sys
	double LWidth[N], FWidth[N], BWidth[N], LHeight[N], FHeight[N], BHeight[N];
	for(int i=1;i<=N;i++)
        {
		LWidth[i-1]=0.1;
		FWidth[i-1]=0.1;
		BWidth[i-1]=0.1;
		LHeight[i-1]=sysL->GetBinError(i);
		FHeight[i-1]=sysF->GetBinError(i);
		BHeight[i-1]=sysB->GetBinError(i);
	}
	TGraphErrors *TGEL = new TGraphErrors(N,xL,yL,LWidth,LHeight);
	TGraphErrors *TGEF = new TGraphErrors(N,xF,yF,FWidth,FHeight);
	TGraphErrors *TGEB = new TGraphErrors(N,xB,yB,BWidth,BHeight);
	TGEL -> SetMarkerColor(kRed);
        TGEF -> SetMarkerColor(kGreen);
	TGEB -> SetMarkerColor(kYellow);
        TGEL -> SetMarkerStyle(21);
        TGEF -> SetMarkerStyle(21);
	TGEB -> SetMarkerStyle(21);
	TGEL -> SetFillColorAlpha(kRed,0.25);
	TGEF -> SetFillColorAlpha(kGreen,0.25);
	TGEB -> SetFillColorAlpha(kYellow,0.25);
	TGEL -> Draw("E2PZsame");
	TGEF -> Draw("E2PZsame");
	TGEB -> Draw("E2PZsame");
	TLegend *legSys = new TLegend(0.18,0.19,0.38,0.39);
        legSys->SetTextFont(132);
        legSys->SetBorderSize(2);
        legSys->SetTextSize(0.05);
        legSys->AddEntry(TGEL,"'n' is PVNTRACKS");
        legSys->AddEntry(TGEF,"'n' is nForwardTracks");
	legSys->AddEntry(TGEB,"'n' is nBackTracks");
        legSys->Draw("same");
        TLegend *Title = new TLegend(0.5,0.85,0.9,0.94);
        Title->SetTextSize(0.05);
        Title->SetHeader("0<y<4.5, 0GeV<p_{T}<20GeV");
        Title->Draw("same");
        can->SaveAs(Form("../4_Plot/AllLFB.pdf"),"recreate");
        can->Close();
	return 0;
}
