#include <TAxis.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
	//input
	TFile input("../3_Result/HighMul.root");
	//TH1D *t1 = (TH1D*)input.Get("hpCompareJ");
	//TH1D *t2 = (TH1D*)input.Get("hpCompareP");
	TH1D *t4 = (TH1D*)input.Get("hpCompare");
	TH1D *t3 = (TH1D*)input.Get("hbCompare");
	TCanvas *can = new TCanvas("can","can",1200,800);
	//t1->SetStats(0);
	//t2->SetStats(0);
	t3->SetStats(0);
	t4->SetStats(0);
	//t1->SetLineColor(2);
	//t2->SetLineColor(3);
	t3->SetLineColor(kBlue);
	t4->SetLineColor(kRed);
	t3->GetXaxis()->SetTitle("#sigma");
	t3->GetYaxis()->SetTitle("count");
	t3->GetYaxis()->SetRangeUser(0,50);
	t3->SetTitle("Variation of  #epsilon_{tot,J/#psi}/#epsilon_{tot,#psi(2S)} measured in #  #sigma");
	t3->Draw();
	//t1->Draw("same");
	//t2->Draw("same");
	t4->Draw("same");
	TLegend *leg = new TLegend(0.63, 0.63, 0.85, 0.85);
	//leg -> AddEntry(t1, "prompt J/#psi");
	//leg -> AddEntry(t2, "J/#psi from b");
	leg -> AddEntry(t3, "prompt");
	leg -> AddEntry(t4, "from-b");
	leg -> Draw("same");
	can->SaveAs("../4_Plot/HighLow.pdf");
	return 0;
}
