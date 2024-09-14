#include <TAxis.h>
#include <fstream>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TH1.h>
#include <TH1D.h>
#include <TH2.h>
#include "lhcbStyle.h"
using namespace std;
int main(int argc, char* argv[])
{
	double ybin, ptbin;
        int Nybin, Nptbin;
        ifstream yconfig(argv[1]);
        ifstream ptconfig(argv[2]);
        yconfig >> Nybin;
        ptconfig >> Nptbin;
	double color[Nybin], marker[Nybin];
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
	for(int i=0; i<Nybin; i++)
        {
                color[i] = i+1;
                marker[i] = 20+i*2;
        }
	gROOT->SetBatch(true);
	setLHCbStyle();
	TFile input(argv[3]);
	TH2D *h_eff = (TH2D*)input.Get(argv[4]);
	TH1D *THPT[Nybin];
	for(int i=0; i<Nybin; i++)
	{
		THPT[i] = new TH1D(Form("THPT%d",i),Form("THPT%d",i), Nptbin,pt);
		for(int j=0; j<Nptbin; j++)
		{
			THPT[i]->SetBinContent(j+1,h_eff->GetBinContent(j+1,i+1));
		}
	}
	gStyle->SetPaintTextFormat(".3f");
	TCanvas* c0 = new TCanvas("c0", "c0", 0, 0, 800, 600);
	c0->SetRightMargin(0.16);
	h_eff->SetStats(0);
	h_eff->GetXaxis()->SetTitle("#font[12]{p}_{T}[GeV/#font[12]{c}]");
        h_eff->GetYaxis()->SetTitle("#font[12]{y}");
        h_eff->SetMarkerSize(1);
        h_eff->Draw("colz text");
	c0->SaveAs(argv[5]);
        c0->Close();
	TCanvas* c1 = new TCanvas("c1","c1", 800, 600);
	for(int i=0;i<Nybin;i++)
        {
		THPT[i]->SetLineColor(color[i]);
                THPT[i]->SetMarkerColor(color[i]);
                THPT[i]->SetMarkerStyle(marker[i]);
		if(i==0) 
		{
			THPT[i]->Draw();
			THPT[i]->GetXaxis()->SetTitle("#font[12]{p}_{T}[GeV/#font[12]{c}]");
			THPT[i]->GetYaxis()->SetRangeUser(-0.2,0.2);
			THPT[i]->GetYaxis()->SetTitle(argv[6]);
		}
		else THPT[i]->Draw("same");
	}
        TLegend* leg = new TLegend(0.25, 0.3, 0.45, 0.45);
        leg->SetTextFont(132);
        leg->SetTextSize(0.04);
	for(int i=0;i<Nybin;i++)
	{
        	leg->AddEntry(Form("THPT%d",i), Form("%1.1f < #font[12]{y} < %1.1f", y[i], y[i+1]));
        }
	leg->Draw();
	c1->SaveAs(argv[7]);
        c1->Close();
	gROOT->ProcessLine(".q");
	return 0;
}
