#include <fstream>
#include <iostream>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <math.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include "0_header/lhcbStyle.h"
using namespace std;
int main(int argc, char* argv[])
{
	setLHCbStyle();
	//input
	double nbin;
	int Nnbin;
	ifstream nconfig("0_Bin/nbin");
	nconfig >> Nnbin;
        int n[Nnbin+1];
        for(int i=0; i<=Nnbin; i++)
        {
                nconfig >> nbin;
                n[i]=nbin;
		cout << n[i] << endl;
        }
	int N;
	sscanf(argv[1],"%d",&N);
	double ratio_hi[500];
	double ratio_lo[500];
	double Rmean=0;
       	double std=0;
	TFile *input;
	TH2D *tot;
	for(int i=1;i<=500;i++)
	{
		input = TFile::Open(Form("../4_Result/Eff_RecselPIDTrigger/n%d/Eff_RecselPIDTrigger_hi%d.root",N,i));
		tot = (TH2D*)input->Get("ratio_tot");
		ratio_hi[i-1] = tot->GetBinContent(1,1);
		Rmean = Rmean+ratio_hi[i-1];
		input->Close();
		input = TFile::Open(Form("../4_Result/Eff_RecselPIDTrigger/n%d/Eff_RecselPIDTrigger_lo%d.root",N,i));
		tot = (TH2D*)input->Get("ratio_tot");
		ratio_lo[i-1] = tot->GetBinContent(1,1);
		Rmean = Rmean+ratio_lo[i-1];
		input->Close();
	}
	Rmean = Rmean/1000;
	//calculate std
	for(int i=1;i<=500;i++)
	{
		std = std+(ratio_hi[i-1]-Rmean)*(ratio_hi[i-1]-Rmean)+(ratio_lo[i-1]-Rmean)*(ratio_lo[i-1]-Rmean);
	}
	std = sqrt(std/999);
	int num_bin = 30;
	//fill and fit and Draw
	TCanvas *can = new TCanvas("can","can",1200,800);
	TH1D *T = new TH1D("T","T",num_bin,Rmean-3*std,Rmean+3*std);
	T->SetStats(0);
	T->SetLineColor(kBlue);
	T->GetXaxis()->SetTitle("R_{eff}");
	T->GetYaxis()->SetTitle("Counts");
	for(int i=1;i<=500;i++)
	{
		T->Fill(ratio_hi[i-1]);
		T->Fill(ratio_lo[i-1]);
	}
	gPad->SetLineColor(kRed);
	T->Fit("gaus");
	TF1 *g = (TF1*)T->GetListOfFunctions()->FindObject("gaus");
	TLegend *Title = new TLegend(0.6,0.8,0.9,0.9);
        Title->SetTextSize(0.045);
        Title->SetHeader(Form("%d #leq #font[12]{N}_{tracks}^{PV} < %d",n[N-1],n[N]));
	Title->Draw("same");
	can->SaveAs(Form("../5_Plots/Eff_RecselPIDTrigger/n%d.pdf",N));
        can->Close();
	ofstream out(Form("../4_Result/SysErr/General/n%d.txt",N));
	out << g->GetParameter(1) << endl;
	out << g->GetParameter(2)/g->GetParameter(1) << endl;
	out.close();
	return 0;
}
