#include <TAxis.h>
#include <fstream>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include "../header/lhcbStyle.h"
using namespace std;
int main(int argc, char* argv[])
{
	//gStyle->SetPaintTextFormat(".2f");
	double ybin, ptbin;
        int Nybin, Nptbin;
        ifstream yconfig(argv[4]);
        ifstream ptconfig(argv[5]);
        yconfig >> Nybin;
        ptconfig >> Nptbin;
        //ifstream yconfig(argv[6]);
        //ifstream ptconfig(argv[7]);
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
	gStyle->SetPaintTextFormat(".3f");
	TFile input(argv[1]);
	TH2D *h_eff = (TH2D*)input.Get("h_eff");
	TH1D *Acc[Nybin];
	for(int i=0; i<Nybin; i++)
	{
		Acc[i] = (TH1D*)input.Get(Form("Acc%d",i));
	}
	TCanvas* c0 = new TCanvas("c0", "c0", 0, 0, 800, 600);
	c0->SetRightMargin(0.16);
	h_eff->GetXaxis()->SetTitle("#font[12]{p}_{T}[GeV/#font[12]{c}]");
        h_eff->GetYaxis()->SetTitle("#font[12]{y}");
        h_eff->SetMarkerSize(1);
        h_eff->Draw("colz text e");
	c0->SaveAs(argv[2]);
        c0->Close();
	TCanvas* c1 = new TCanvas("c1","c1", 800, 600);
	for(int i=0;i<Nybin;i++)
        {
		Acc[i]->SetLineColor(color[i]);
                Acc[i]->SetMarkerColor(color[i]);
                Acc[i]->SetMarkerStyle(marker[i]);
		if(i==0) Acc[i]->Draw();
		else Acc[i]->Draw("same");
	}
        TLegend* leg = new TLegend(0.65, 0.3, 0.85, 0.58);
        leg->SetTextFont(132);
        leg->SetTextSize(0.04);
	for(int i=0;i<Nybin;i++)
	{
        	leg->AddEntry(Form("Acc%d",i), Form("%1.1f < #font[12]{y} < %1.1f", y[i], y[i+1]));
        }
	leg->Draw();
	c1->SaveAs(argv[3]);
        c1->Close();
	gROOT->ProcessLine(".q");
	return 0;
}
