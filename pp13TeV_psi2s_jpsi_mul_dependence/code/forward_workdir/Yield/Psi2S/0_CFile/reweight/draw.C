#include <TStyle.h>
#include <TFile.h>
#include <TH1.h>
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
	TH1D *Sp_N = (TH1D*)input->Get("Sp_N");
	TH1D *Sb_N = (TH1D*)input->Get("Sb_N");
	TH1D *D_N = (TH1D*)input->Get("D_N");
	TH1D *reweightpN = (TH1D*)input->Get("reweightpN");
	TH1D *reweightbN = (TH1D*)input->Get("reweightbN");
	TH1D *Dp_N = new TH1D("Dp_N","Dp_N",50,0,150);
	TH1D *Db_N = new TH1D("Db_N","Db_N",50,0,150);;
	Dp_N -> Multiply(D_N,reweightpN,1.,1.,"B");
	Db_N -> Multiply(D_N,reweightbN,1.,1.,"B");
	//Draw
	TCanvas *canp = new TCanvas("canp","canp",800,600);
	Sp_N -> SetStats(0);
	Sb_N -> SetStats(0);
	D_N -> SetStats(0);
	Sp_N -> SetLineColor(4);
	Sp_N -> SetTitle("prompt #psi(2S)");
	Sp_N -> GetYaxis() -> SetRangeUser(0,0.09);
	Sp_N -> GetXaxis() -> SetTitle("#font[12]{N}^{PV}_{fwd}");
	 Sp_N -> GetYaxis() -> SetTitle("Normalized");
	Sp_N -> Draw("HIST");
	D_N -> SetLineColor(2);
	D_N -> Draw("HIST same");
	Dp_N -> SetStats(0);
	Dp_N -> SetLineColor(3);
        Dp_N -> SetMarkerStyle(8);
        Dp_N -> Draw("same");
	TLegend *legp = new TLegend(0.55,0.55,0.90,0.90);
	legp->SetTextSize(0.035);
	legp -> AddEntry(D_N,"MC w/o reweight");
        legp -> AddEntry(Dp_N,"MC with reweight");
        legp -> AddEntry(Sp_N,"prompt s-weight");
        legp -> Draw("same");
        canp -> SaveAs(argv[2]);
	canp -> Close();
	TCanvas *canb = new TCanvas("canb","canb",800,600);
        Sb_N -> SetStats(0);
        Sb_N -> SetStats(0);
        D_N -> SetStats(0);
        Sb_N -> SetLineColor(4);
        Sb_N -> SetTitle("non-prompt #psi(2S)");
        Sb_N -> GetYaxis() -> SetRangeUser(0,0.09);
        Sb_N -> GetXaxis() -> SetTitle("#font[12]{N}^{PV}_{fwd}");
        Sb_N -> GetYaxis() -> SetTitle("Normalized");
	Sb_N -> Draw("HIST");
        D_N -> SetLineColor(2);
	D_N -> Draw("HIST same");
        Db_N -> SetStats(0);
        Db_N -> SetLineColor(3);
        Db_N -> SetMarkerStyle(8);
        Db_N -> Draw("same");
        TLegend *legb = new TLegend(0.55,0.55,0.90,0.90);
        legb->SetTextSize(0.035);
	legb -> AddEntry(D_N,"MC w/o reweight");
        legb -> AddEntry(Db_N,"MC with reweight");
        legb -> AddEntry(Sb_N,"non-prompt s-weight");
        legb -> Draw("same");
        canb -> SaveAs(argv[3]);
	canb -> Close();
	return 0;
}
