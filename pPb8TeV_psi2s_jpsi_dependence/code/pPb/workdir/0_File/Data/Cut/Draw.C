#include "/nishome/kangye/disk402_ppAnalysis/workdir/Yield/Jpsi/0_CFile/header/lhcbStyle.h"
void Draw()
{
	setLHCbStyle();
	TFile *f1 = TFile::Open("Psi2S_n5y1pt1_ProbNNmuSmall.root");
	TFile *f2 = TFile::Open("Psi2S_n5y1pt1.root");
	TTree *t1 = (TTree*)f1->Get("DecayTree");
	TTree *t2 = (TTree*)f2->Get("DecayTree");
	TH1D *h1 = new TH1D("h1","h1", 80, 3686-120, 3686+120);
	TH1D *h2 = new TH1D("h2","h2", 80, 3686-120, 3686+120);
	t1 -> Draw("psi_M>>h1");
	t2 -> Draw("psi_M>>h2");
	h1 -> SetStats(0);
	h2 -> SetStats(0);
	h1 -> SetLineColor(kBlue);
	h2 -> SetLineColor(kRed);
	h1 -> GetXaxis() -> SetTitle("M_{#mu^+#mu^-}[MeV/#font[12]{c}^{2}]");
	h1 -> GetYaxis() -> SetTitle("counts");
	h2 -> GetXaxis() -> SetTitle("M_{#mu^+#mu^-}[MeV/#font[12]{c}^{2}]");
        h2 -> GetYaxis() -> SetTitle("counts");
	TCanvas *can1 = new TCanvas("can1","can1",1200,800);
	h1 -> GetYaxis() -> SetRangeUser(0,800);
	h1 -> Draw();
	//h2 -> Draw("same");
	TLegend *leg1 = new TLegend(0.6,0.4,0.9,0.6);
	leg1 -> AddEntry(h1, "ProbNN#mu > 0.6");
	//leg1 -> AddEntry(h2, "ProbNN#mu > 0.9");
	leg1 -> Draw("same");
	can1 -> SaveAs("HighMul1.pdf");
	TCanvas *can2 = new TCanvas("can2","can2",1200,800);
        h2 -> Draw();
        TLegend *leg2 = new TLegend(0.6,0.7,0.9,0.9);
        leg2 -> AddEntry(h2, "ProbNN#mu > 0.9");
        leg2 -> Draw("same");
        can2 -> SaveAs("HighMul2.pdf");
}

