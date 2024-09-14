#include <fstream>
#include <iostream>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <math.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TROOT.h>
#include <TStyle.h>
#include "0_header/lhcbStyle.h"
#include "TLegend.h"
using namespace std;
int main(int argc, char* argv[])
{
	setLHCbStyle();
	//input
	double ratio_hi[50];
	double ratio_lo[50];
	double Rmean=0;
       	double std=0;
	TFile *input;
	TH2D *tot;
	for(int i=1;i<=50;i++)
	{
		input = TFile::Open(Form("../4_Result/Eff_Acc/Eff_Acc_hi%d.root",i));
		tot = (TH2D*)input->Get("ratio_acc");
		ratio_hi[i-1] = tot->GetBinContent(1,1);
		Rmean = Rmean+ratio_hi[i-1];
		input->Close();
		input = TFile::Open(Form("../4_Result/Eff_Acc/Eff_Acc_lo%d.root",i));
		tot = (TH2D*)input->Get("ratio_acc");
		ratio_lo[i-1] = tot->GetBinContent(1,1);
		Rmean = Rmean+ratio_lo[i-1];
		input->Close();
	}
	Rmean = Rmean/100;
	//calculate std
	for(int i=1;i<=50;i++)
	{
		std = std+(ratio_hi[i-1]-Rmean)*(ratio_hi[i-1]-Rmean)+(ratio_lo[i-1]-Rmean)*(ratio_lo[i-1]-Rmean);
	}
	std = sqrt(std/99);
	int num_bin = 20;
	//fill and fit and Draw
	TCanvas *can = new TCanvas("can","can",1200,800);
	TH1D *T = new TH1D("T","T",num_bin,Rmean-3*std,Rmean+3*std);
	T->SetStats(0);
	T->SetLineColor(kBlue);
	T->GetXaxis()->SetTitle("R_{acc}");
	T->GetYaxis()->SetTitle("Counts");
	for(int i=1;i<=50;i++)
	{
		T->Fill(ratio_hi[i-1]);
		T->Fill(ratio_lo[i-1]);
	}
	gPad->SetLineColor(kRed);
	T->Fit("gaus");
	TF1 *g = (TF1*)T->GetListOfFunctions()->FindObject("gaus");
	TLegend *leg = new TLegend(0.7,0.7,0.9,0.9);
	leg->AddEntry("",Form("mean = %.4f",g->GetParameter(1)));
	leg->AddEntry("",Form("sigma = %.4f",g->GetParameter(2)));
	leg->Draw("same");
	can->SaveAs("../5_Plots/Eff_RecselPIDTrigger/Racc.pdf");
        can->Close();
	ofstream out("../4_Result/Eff_Acc/ErrAcc.txt");
	out << g->GetParameter(1) << endl;
	out << g->GetParameter(2)/g->GetParameter(1) << endl;
	out.close();
	return 0;
}
