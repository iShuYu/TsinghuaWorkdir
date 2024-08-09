#include <iostream>
#include <TStyle.h>
#include <fstream>
#include <TFile.h>
#include <TH2.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TLegend.h>
#include <TROOT.h>
#include "../header/lhcbStyle.h"
using namespace std;
int main(int argc, char *argv[])
{
        gROOT->SetBatch(true);
        setLHCbStyle();
        gStyle->SetPalette(55);
        gStyle->SetPaintTextFormat("4.3f");
        TH1::SetDefaultSumw2();
        double ybin, ptbin;
        int Nybin, Nptbin;
	//input title
	TString Title = argv[7];
	TString TD1 = argv[5];
	TString TD2 = argv[6];
	//input binning scheme
	ifstream yconfig(argv[1]);
        ifstream ptconfig(argv[2]);
        yconfig >> Nybin;
        ptconfig >> Nptbin;
        double y[Nybin+1], pt[Nptbin+1];
        for(int i=0; i<=Nybin; i++)
        {
                yconfig >> ybin;
                y[i]=ybin;
        }
        for(int i=0; i<=Nptbin; i++)
        {
                ptconfig >> ptbin;
                pt[i]=ptbin;
        }
        int color[Nybin];
        int marker[Nptbin];
        for(int i=0; i<Nybin; i++)
        {
                color[i] = i;
                marker[i] = i;
        }
	//output
	TFile F1(argv[3]);
	TFile F2(argv[4]);
	TH2D *t1 = (TH2D*)F1.Get(TD1);
	TH2D *t2 = (TH2D*)F2.Get(TD2);
	TH2D *Compare = new TH2D("Compare", "Compare", Nptbin, pt, Nybin, y);
	Compare -> Divide(t2,t1,1.,1.);
	TCanvas *can = new TCanvas("can","can",1600,1200);
        TH1D* p_bins[Nybin];
	TH1D *Err = new TH1D("Err",Title,10,-3.5,3.5);
	for(int i=0;i<Nybin;i++)
        {
                p_bins[i] = new TH1D(Form("py%d",i),Title,12,2000,14000);
                p_bins[i]->GetYaxis()->SetRangeUser(-5.,5.);
                p_bins[i]->SetLineColor(i+2);
                p_bins[i]->GetYaxis()->SetTitle("Ratio");
                p_bins[i]->GetXaxis()->SetTitle("p_{T} (MeV)");
                p_bins[i]->GetYaxis()->SetRangeUser(0.6,1.4);
		for(int j=0;j<14;j++)
                {
			Err->Fill((Compare->GetBinContent(j+1,i+1)-1)/Compare->GetBinError(j+1,i+1));
                        p_bins[i]->SetBinContent(j+1,Compare->GetBinContent(j+1,i+1));
                        p_bins[i]->SetBinError(j+1,Compare->GetBinError(j+1,i+1));
                }
                p_bins[i]->SetStats(0);
                if(i==1)
		{
			p_bins[i]->GetYaxis()->SetTitle("calculated / punlished");
			p_bins[i]->Draw();
		}
                p_bins[i]->Draw("same");
        }
	TLegend* leg = new TLegend(0.65, 0.65, 0.85, 0.85);
        leg->SetTextFont(132);
        leg->SetTextSize(0.03);
        for(int i=0;i<5;i++)
        {
                leg->AddEntry(Form("py%d",i), Form("%1.1f < #font[12]{y} < %1.1f", 2+i*0.5, 2.5+i*0.5));
        }
        leg->Draw();
        can ->SaveAs(argv[8]);
        can -> Close();
	//Fit for pulls
	TCanvas *canE = new TCanvas("canE","canvas for Error",1600,1200);
	Err->SetStats(0);
	Err->SetLineColor(kRed);
	Err->SetTitle(Title);
	Err->Draw();
	Err->Fit("gaus");
	TF1 *Paras = Err->GetFunction("gaus");
	double mean = Paras->GetParameter(1);
	double sigma = Paras->GetParameter(2);
	double meanErr = Paras->GetParError(1);
	double sigmaErr = Paras->GetParError(2);
	TLegend* legE = new TLegend(0.65, 0.65, 0.85, 0.85);
	legE->AddEntry("",Form("Mean:%4.3f#pm%4.3f",mean,meanErr));
	legE->AddEntry("",Form("Std:%4.3f#pm%4.3f",sigma,sigmaErr));
	legE->SetTextFont(132);
        legE->SetTextSize(0.03);
	legE->Draw("same");
	canE->SaveAs(argv[9]);
	return 0;
}



