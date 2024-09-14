#define MCDecayTree_Cut_cxx
#define mct_cxx
#include <TH1.h>
#include <TH2.h>
#include <TH3F.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <TAxis.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TLegend.h>
#include "0_header/MCDecayTree_Cut.h"
#include "0_header/mct.h"
#include "0_header/lhcbStyle.h"
using namespace std;
int main(int argc, char *argv[])
{
	setLHCbStyle();
	double Pp[5], PpErr[5], Ppnew[5];
	double Jp[5], JpErr[5], Jpnew[5];
	double Pb[5], PbErr[5], Pbnew[5];
        double Jb[5], JbErr[5], Jbnew[5];
	double dustbin;
       	for(int N=1; N<=5; N++)
	{
		ifstream J(Form("../4_Result/TwoDimFit/Jpsi_n%dy1pt1.txt",N));
		ifstream P(Form("../4_Result/TwoDimFit/Psi2S_n%dy1pt1.txt",N));
		ifstream Jnew(Form("../4_Result/TwoDimFit/Jpsi_n%dy1pt1new.txt",N));
                ifstream Pnew(Form("../4_Result/TwoDimFit/Psi2S_n%dy1pt1new.txt",N));
		J >> Jp[N-1] >> JpErr[N-1] >> Jb[N-1] >> JbErr[N-1];
		P >> Pp[N-1] >> PpErr[N-1] >> Pb[N-1] >> PbErr[N-1];
		Jnew >> Jpnew[N-1] >> dustbin >> Jbnew[N-1];
		Pnew >> Ppnew[N-1] >> dustbin >> Pbnew[N-1];
		//cout << PpErr[N-1] << endl;
	}
	const double bin[6] = {4,45,70,90,120,270};
	TH1D *StatsErrp = new TH1D("StatsErrp","StatsErrp",5,bin);
	TH1D *FitErrp = new TH1D("FitErrp","FitErrp",5,bin);
	TH1D *StatsErrb = new TH1D("StatsErrb","StatsErrb",5,bin);
        TH1D *FitErrb = new TH1D("FitErrb","FitErrb",5,bin);
	for(int N=1; N<=5; N++)
        {
		double sp = sqrt(JpErr[N-1]*JpErr[N-1]/Jp[N-1]/Jp[N-1]+PpErr[N-1]*PpErr[N-1]/Pp[N-1]/Pp[N-1]);
		double sb = sqrt(JbErr[N-1]*JbErr[N-1]/Jb[N-1]/Jb[N-1]+PbErr[N-1]*PbErr[N-1]/Pb[N-1]/Pb[N-1]);
		double fp = (Ppnew[N-1]/Jpnew[N-1]-Pp[N-1]/Jp[N-1])/(Pp[N-1]/Jp[N-1]);
		double fb = (Pbnew[N-1]/Jbnew[N-1]-Pb[N-1]/Jb[N-1])/(Pb[N-1]/Jb[N-1]);
		StatsErrp->SetBinContent(N,sp);
		StatsErrb->SetBinContent(N,sb);
		FitErrp->SetBinContent(N,abs(fp));
		FitErrb->SetBinContent(N,abs(fb));
	}
	TCanvas *canp = new TCanvas("canp","canp",1200,800);
	StatsErrp->SetStats(0);
	StatsErrp->SetLineColor(kRed);
	StatsErrp->GetXaxis()->SetTitle("#font[12]{N}_{tracks}^{PV}");
	StatsErrp->GetYaxis()->SetTitle("Relative Error");
	StatsErrp->GetYaxis()->SetRangeUser(0,0.18);
	StatsErrp->Draw("HIST");
	FitErrp->SetStats(0);
	FitErrp->SetLineColor(kRed);
	FitErrp->SetLineStyle(2);
	FitErrp->Draw("same");
	StatsErrb->SetStats(0);
        StatsErrb->SetLineColor(kBlue);
        StatsErrb->Draw("HISTsame");
        FitErrb->SetStats(0);
        FitErrb->SetLineColor(kBlue);
        FitErrb->SetLineStyle(2);
        FitErrb->Draw("same");
	TLegend *legp = new TLegend(0.55,0.72,0.9,0.9);
	legp -> SetTextSize(0.03);
	legp->AddEntry(StatsErrp,"Stats. Err. (prompt)","L");
	legp->AddEntry(FitErrp,"Fit model Err. (prompt)","L");
	legp->AddEntry(StatsErrb,"Stats. Err. (from-b)","L");
        legp->AddEntry(FitErrb,"Fit model Err. (from-b)","L");
	legp->Draw("same");
	canp->SaveAs("../5_Plots/SysErr/FitModel.pdf");
	canp->Close();
	return 0;
}
