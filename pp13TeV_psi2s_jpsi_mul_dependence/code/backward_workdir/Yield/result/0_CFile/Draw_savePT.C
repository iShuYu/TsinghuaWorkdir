#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TGraphMultiErrors.h>
#include <TAxis.h>
#include <fstream>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include "lhcbStyle.h"
#include <TF1.h>
using namespace std;
int main(int argc, char* argv[])
{
	//input binning scheme
	vector<double>  y_s;
	vector<int> pt_s;
	vector<double> n_p, n_b;
        double nbin, ybin, ptbin;
        int Nybin, Nptbin;
	ifstream yconfig(argv[1]);
        ifstream ptconfig(argv[2]);
        yconfig >> Nybin;
        ptconfig >> Nptbin;
        for(int i=0; i<=Nybin; i++)
        {
                yconfig >> ybin;
                y_s.push_back(ybin);
        }
        for(int i=0; i<=Nptbin; i++)
        {
                ptconfig >> ptbin;
                pt_s.push_back(ptbin);
        }
        gROOT->SetBatch(true);
        setLHCbStyle();
	//Draw total Modification
	//input
	int color[5] = {1,2,3,4,7};
	TCanvas *canp = new TCanvas("canp","canp",1200,800);
	TCanvas *canb = new TCanvas("canb","canb",1200,800);
	TGraphMultiErrors* gmep[5];
	TGraphMultiErrors* gmeb[5];
	TLegend *legp1 = new TLegend(0.18,0.19,0.44,0.35);
	TLegend *legb1 = new TLegend(0.18,0.19,0.44,0.35);
	legp1->SetTextSize(0.045);
	legb1->SetTextSize(0.045);
	legp1->SetTextFont(132);
	legb1->SetTextFont(132);
	TLegend *legp2 = new TLegend(0.5,0.19,0.76,0.30);
        TLegend *legb2 = new TLegend(0.5,0.19,0.76,0.30);
        legp2->SetTextSize(0.045);
        legb2->SetTextSize(0.045);
        legp2->SetTextFont(132);
        legb2->SetTextFont(132);

	for(int th=0;th<5;th++)
	{
		int Npnbin, Nbnbin;
                ifstream npconfig(Form("../3_Result/promptBinPT%d.txt",th+1));
                ifstream nbconfig(Form("../3_Result/frombBinPT%d.txt",th+1));
                Npnbin = 5;
		Nbnbin = 5;
		for(int i=0; i<Npnbin; i++)
        	{
                	npconfig >> nbin;
                	n_p.push_back(nbin);
        		nbconfig >> nbin;
			n_b.push_back(nbin);
		}
		int N = Npnbin;
                double xp[N], xb[N], xp_lo[N], xp_hi[N], xb_lo[N], xb_hi[N];
                double yp[N], yb[N], yp_lo[N], yp_hi[N], yb_lo[N], yb_hi[N];
                TFile *allT = TFile::Open("../../result/3_Result/SaveSys.root");	
                TH1D *tempSysp = (TH1D*)allT->Get(Form("pPt%d",th+1));
                TH1D *tempSysb = (TH1D*)allT->Get(Form("bPt%d",th+1));
                allT = TFile::Open("../../result/3_Result/SaveStats.root");
                TH1D *tempStatsp = (TH1D*)allT->Get(Form("pPt%d",th+1));
                TH1D *tempStatsb = (TH1D*)allT->Get(Form("bPt%d",th+1));
                ifstream perr(Form("../3_Result/promptBinPTErr%d.txt",th+1));
		ifstream berr(Form("../3_Result/frombBinPTErr%d.txt",th+1));
		//Stats
                for(int i=1;i<=N;i++)
                {
                	yp[i-1]=tempStatsp->GetBinContent(i);
                	yp_lo[i-1]=tempStatsp->GetBinError(i);
                	yp_hi[i-1]=yp_lo[i-1];
                	yb[i-1]=tempStatsb->GetBinContent(i);
                        yb_lo[i-1]=tempStatsb->GetBinError(i);
                        yb_hi[i-1]=yb_lo[i-1];
                	xp[i-1]=n_p[5*th+i-1];
                	xb[i-1]=n_b[5*th+i-1];
                	perr >> xp_lo[i-1];
			xp_hi[i-1] = xp_lo[i-1];
			berr >> xb_lo[i-1];
                        xb_hi[i-1] = xb_lo[i-1];
		}
		double pWidth[N], bWidth[N], pHeight[N], bHeight[N];
                for(int i=1;i<=N;i++)
                {
                        pWidth[i-1]=0.1;
                        bWidth[i-1]=0.1;
                        pHeight[i-1]=tempSysp->GetBinError(i);
                        bHeight[i-1]=tempSysb->GetBinError(i);
                }	
		if(th==0)
		{	
			TF1 *unit = new TF1("unit","1+x-x",0,4.4);
                	unit -> SetLineStyle(2);
                	unit -> SetLineColor(1);
                	unit -> GetYaxis() -> SetRangeUser(0.4,1.6);
                	unit -> GetXaxis()->SetTitle("#font[12]{N}_{bwd}^{PV}/#LT#font[12]{N}_{bwd}^{PV}#GT_{NB}");
                	unit -> GetYaxis()->SetTitle("Normalised #sigma_{#psi(2S)}/#sigma_{J/#psi}");
                	canp -> cd();
			unit -> Draw();
			canb -> cd();
			unit -> Draw();
                }
		gmep[th] = new TGraphMultiErrors("gmep", "", N, xp, yp, xp_lo, xp_hi, yp_lo, yp_hi);
		gmeb[th] = new TGraphMultiErrors("gmeb", "", N, xb, yb, xb_lo, xb_hi, yb_lo, yb_hi);
		gmep[th] -> AddYError(N, pHeight, pHeight);
		gmeb[th] -> AddYError(N, bHeight, bHeight);
		gmep[th] -> SetMarkerColor(color[th]);
                gmeb[th] -> SetMarkerColor(color[th]);
		gmep[th] -> SetLineColor(color[th]);
                gmeb[th] -> SetLineColor(color[th]);
                gmep[th] -> SetMarkerStyle(21);
                gmeb[th] -> SetMarkerStyle(21);
		gmep[th] -> GetXaxis() -> SetLimits(0,4.4);
                gmeb[th] -> GetXaxis() -> SetLimits(0,4.4);
                gmep[th] -> GetAttLine(0)->SetLineColor(color[th]);
       		gmep[th] -> GetAttLine(1)->SetLineColor(color[th]);
        	gmep[th] -> GetAttFill(1)->SetFillColorAlpha(color[th],0);
        	gmep[th] -> GetYaxis() -> SetRangeUser(0.5,1.5);
		gmeb[th] -> GetAttLine(1)->SetLineColor(color[th]);
                gmeb[th] -> GetAttFill(1)->SetFillColorAlpha(color[th],0);
                gmeb[th] -> GetYaxis() -> SetRangeUser(0.5,1.5);
		//gmep[th] -> GetXaxis()->SetTitle("#font[12]{N}_{bwd}^{PV}/#LT#font[12]{N}_{bwd}^{PV}#GT_{NB}");
                //gmep[th] -> GetYaxis()->SetTitle("Normalised #sigma_{#psi(2S)}/#sigma_{J/#psi}");
                canp -> cd();
		gmep[th] -> Draw("PS same; Z ; 5 s=1 ; same");
		canb ->cd();
                gmeb[th] -> Draw("PS same; Z ; 5 s=1 ; same"); 
                if(th<=2) legp1 -> AddEntry(gmep[th],Form("%.1f < #font[12]{p}_{T} < %.1f GeV/c",pt_s[th]/1000.001,pt_s[th+1]/1000.001), "PLEZ");
		if(th<=2) legb1 -> AddEntry(gmeb[th],Form("%.1f < #font[12]{p}_{T} < %.1f GeV/c",pt_s[th]/1000.001,pt_s[th+1]/1000.001),"PLEZ");
		if(th>2) legp2 -> AddEntry(gmep[th],Form("%.1f < #font[12]{p}_{T} < %.1f GeV/c",pt_s[th]/1000.001,pt_s[th+1]/1000.001), "PLEZ");
                if(th>2) legb2 -> AddEntry(gmeb[th],Form("%.1f < #font[12]{p}_{T} < %.1f GeV/c",pt_s[th]/1000.001,pt_s[th+1]/1000.001),"PLEZ");
	}
	canp -> cd();
	legp1 -> Draw("same");
	legp2 -> Draw("same");
	lhcbName ->Draw();
	canb -> cd();
	lhcbName->Draw();
	legb1 -> Draw("same");
	legb2 -> Draw("same");
	TLegend *Titlep = new TLegend(0.6, 0.7, 0.7, 0.8);
	Titlep->SetTextFont(132);
        Titlep -> SetTextSize(0.06);
        Titlep -> SetHeader("prompt");
	TLegend *Titleb = new TLegend(0.6, 0.74, 0.7, 0.84);
        Titleb->SetTextFont(132);
	Titleb -> SetTextSize(0.06);
        Titleb -> SetHeader("non-prompt");
	Titleb -> SetFillStyle(0);
        canp -> cd();
	Titlep -> Draw("same");
	canb -> cd();
	Titleb -> Draw("same");
	canp -> SaveAs("../4_Plot/promptRatioPTB.pdf");
	canp -> SaveAs("../4_Plot/promptRatioPTB.png");
	canp -> SaveAs("../4_Plot/promptRatioPTB.C");
	canp -> SaveAs("../4_Plot/promptRatioPTB.eps");

	canp -> Close();
	canb -> SaveAs("../4_Plot/frombRatioPTB.pdf");
	canb -> SaveAs("../4_Plot/frombRatioPTB.png");
	canb -> SaveAs("../4_Plot/frombRatioPTB.eps");
	canb -> SaveAs("../4_Plot/frombRatioPTB.C");

	canb -> Close();
	return 0;
}
