#include "../../0_CFile/header/lhcbStyle.h"
void DrawData()
{
	setLHCbStyle();
	TFile *out = TFile::Open("newVar.root");
	TTree *DecayTree = (TTree*)out->Get("DecayTree");
	TH2D *h1 = new TH2D("h1", "h1", 60,-60,180,100,0,200);
	DecayTree->Draw("PVNTRACKS:PVZ>>h1","fromb_sw+prompt_sw");
	TH2D *h2 = new TH2D("h2", "h2", 60,-60,180,100,0,200);
        DecayTree->Draw("PVNcor:PVZ>>h2","fromb_sw+prompt_sw");
	TProfile *Pro = h1->ProfileX();
	TProfile *Pro1 = h2->ProfileX();
	Pro->SetStats(0);
	Pro->SetLineColor(kBlue);
	Pro->SetMarkerColor(kBlue);
	Pro->SetTitle("2016 pp 13TeV Data (sw)");
	Pro->GetXaxis()->SetTitle("#font[12]{z}_{PV}");
	Pro->GetYaxis()->SetTitle("#LT#font[12]{N}^{PV}_{tracks}#GT");
	TCanvas *can = new TCanvas("can", "can", 1200, 800);
	Pro->Draw();
	Pro->GetYaxis()->SetRangeUser(0,70);
	Pro->Draw();
	Pro1->SetLineColor(kRed);
	Pro1->SetMarkerColor(kRed);
	Pro1->Draw("same");
	TLegend *leg = new TLegend(0.3,0.3,0.42,0.47);
	leg->AddEntry(Pro, "#font[12]{N}^{PV}_{tracks}");
	leg->AddEntry(Pro1, "#font[12]{N}^{PV,cor}_{tracks}");
	leg->Draw("same");
	can -> SaveAs("Data.pdf");
	can -> Close();
}
