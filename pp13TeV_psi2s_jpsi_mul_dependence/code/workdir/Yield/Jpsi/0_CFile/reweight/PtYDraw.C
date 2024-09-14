#include <TStyle.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <TCanvas.h>
#include <TROOT.h>
#include <TLegend.h>
#include "/nishome/kangye/disk402_ppAnalysis/workdir/Yield/Jpsi/0_CFile/header/lhcbStyle.h"
using namespace std;
int main(int argc, char* argv[])
{
	setLHCbStyle();
	//input
	TFile *input = TFile::Open(argv[1]);
	//MC
	TH2D *M = (TH2D*)input->Get("D_Y");
	//Sweight Data
	TH2D *Sp = (TH2D*)input->Get("Sp_PTY");
	TH2D *Sb = (TH2D*)input->Get("Sb_PTY");
	//reweight
	TH2D *Rp = (TH2D*)input->Get("reweightpPTY");
	TH2D *Rb = (TH2D*)input->Get("reweightbPTY");
	//template
	TH2D *SMp = new TH2D("SMp","SMp",20,300,20000,10,2,4.5);
        TH2D *SMb = new TH2D("SMb","SMb",20,300,20000,10,2,4.5);
	SMp -> Multiply(M,Rp,1.,1.,"B");
	SMb -> Multiply(M,Rb,1.,1.,"B");
	//Plot
	TH1D *th = new TH1D("th","th",20,300,20000);
	th -> GetXaxis() -> SetTitle("#font[12]{p}_{T} (Mev/c)");
	th -> GetYaxis() -> SetTitle("Normalized");
	TH1D *thM = new TH1D("thM","thM",20,300,20000);
	TH1D *thS = new TH1D("thS","thS",20,300,20000);
	th -> SetStats(0);
	thM -> SetStats(0);
	thS -> SetStats(0);
	th -> SetLineColor(3);
        thM -> SetLineColor(2);
        thS -> SetLineColor(4);
        th -> GetYaxis() -> SetRangeUser(0,0.030);
	TCanvas *canp[10];
	for(int i=1;i<=10;i++)
	{
		th -> SetTitle(Form("%.2f < y < %.2f",2+(i-1)*0.25,2+i*0.25));
		for(int j=1;j<=20;j++)
		{
			th -> SetBinContent(j,SMp->GetBinContent(j,i));
			thM -> SetBinContent(j,M->GetBinContent(j,i));
			thS -> SetBinContent(j,Sp->GetBinContent(j,i));
		}
		canp[i-1] = new TCanvas(Form("canp%d",i-1),Form("canp%d",i-1),1200,800);
		th -> GetYaxis() -> SetRangeUser(0,0.030);
		th -> SetMarkerStyle(8);
		th -> SetMarkerSize(1.5);
		th -> Draw("P");
		thM ->Draw("HIST same");
		thS ->Draw("HIST same");
		TLegend *legp = new TLegend(0.55,0.55,0.90,0.90);
		legp->SetTextSize(0.035);
	        legp -> AddEntry(thM,"MC w/o reweight");
	        legp -> AddEntry(th,"MC with reweight");
	        legp -> AddEntry(thS,"prompt s-weight");
	        legp -> Draw("same");
		canp[i-1] -> SaveAs(Form("../../4_Plot/reweight/Yp%d.pdf",i));
	}
	TCanvas *canb[10];
	for(int i=1;i<=10;i++)
        {
                th -> SetTitle(Form("%.2f < y < %.2f",2+(i-1)*0.25,2+i*0.25));
                for(int j=1;j<=20;j++)
                {       
                        th -> SetBinContent(j,SMb->GetBinContent(j,i));
                        thM -> SetBinContent(j,M->GetBinContent(j,i));
                        thS -> SetBinContent(j,Sb->GetBinContent(j,i));
                }
                canb[i-1] = new TCanvas(Form("canb%d",i-1),Form("canb%d",i-1),1200,800);
                th -> GetYaxis() -> SetRangeUser(0,0.030);
                th -> SetMarkerStyle(8);
		th -> SetMarkerSize(1.5);
                th -> Draw("P");
                thM ->Draw("HIST same");
                thS ->Draw("HIST same");
                TLegend *legp = new TLegend(0.55,0.55,0.90,0.90);
                legp->SetTextSize(0.035);
		legp -> AddEntry(thM,"MC w/o reweight");
                legp -> AddEntry(th,"MC with reweight");
                legp -> AddEntry(thS,"non-prompt s-weight");
                legp -> Draw("same");
                canb[i-1] -> SaveAs(Form("../../4_Plot/reweight/Yb%d.pdf",i));
        }
	return 0;
}
