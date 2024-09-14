#include <TH1.h>
#include <TFile.h>
#include <TH2.h>
#include <TStyle.h>
#include <TAxis.h>
#include <TLegend.h>
#include <TCanvas.h>
#include <TROOT.h>
//#include "lhcbStyle.h"
#include "/nishome/kangye/disk402_ppAnalysis/workdir/Yield/Jpsi/0_CFile/header/lhcbStyle.h"

using namespace std;
int main()
{
	setLHCbStyle();
	TFile a("reweightHighMul.root");
	TFile b("reweightLowMul.root");
	TH2D* Hp = (TH2D*)a.Get("Sp_PTY");
	TH2D* Hb = (TH2D*)a.Get("Sb_PTY");
	TH2D* Lp = (TH2D*)b.Get("Sp_PTY");
	TH2D* Lb = (TH2D*)b.Get("Sb_PTY");
	TCanvas *canp = new TCanvas("canp","canp",1200,800);
	//Hp->SetTitle("prompt-J/#psi #font[12]{p}_{T}-#font[12]{y} distribution");
	Hp->GetXaxis()->SetTitle("p_{T} (MeV/c)");
	Hp->GetYaxis()->SetTitle("y");
	Hp->GetZaxis()->SetTitle("Normalized");
	Hp->GetXaxis()->SetTitleOffset(1.5);
	Hp->GetYaxis()->SetTitleOffset(1.5);
	Hp->GetZaxis()->SetTitleOffset(1.2);
	gStyle->SetTitleFontSize(5);
	Hp->SetStats(0);
	Lp->SetStats(0);
	Hp->SetLineColor(kRed);
	Lp->SetLineColor(kBlue);
	Hp->Draw("surf");
	Lp->Draw("surf same");
	TLegend *leg = new TLegend(0.65,0.65,0.99,0.9);
	leg->SetTextSize(0.035);
	leg->SetHeader("prompt-J/#psi #font[12]{p}_{T}-#font[12]{y} distribution");
	leg->AddEntry(Lp, "Low Multiplicity");
	leg->AddEntry(Hp, "High Multiplicity");
	leg->Draw("same");
	canp->SaveAs("./promptHighLowPTY.pdf");
	canp->Close();
	TCanvas *canb = new TCanvas("canb","canb",1200,800);
	//Hb->SetTitle("non-prompt J/#psi #font[12]{p}_{T}-#font[12]{y} distribution");
	Hb->GetXaxis()->SetTitle("p_{T} (MeV/c)");
	Hb->GetYaxis()->SetTitle("y");
	Hb->GetZaxis()->SetTitle("Normalized");
	Hb->GetXaxis()->SetTitleOffset(2);
	Hb->GetYaxis()->SetTitleOffset(2);
	Hb->GetZaxis()->SetTitleOffset(1.5);
	Hb->SetStats(0);
	Lb->SetStats(0);
	Hb->SetLineColor(kRed);
	Lb->SetLineColor(kBlue);
	Hb->Draw("surf");
	Lb->Draw("surf same");
	TLegend *leg1 = new TLegend(0.65,0.65,0.95,0.9);
	leg1->SetTextSize(0.035);
	leg1->SetHeader("non-prompt J/#psi #font[12]{p}_{T}-#font[12]{y} distribution");
	leg1->AddEntry(Lb, "Low Multiplicity");
	leg1->AddEntry(Hb, "High Multiplicity");
	leg1->Draw("same");
	canb->SaveAs("./frombHighLowPTY.pdf");
	canb->Close();
	return 0;
}
