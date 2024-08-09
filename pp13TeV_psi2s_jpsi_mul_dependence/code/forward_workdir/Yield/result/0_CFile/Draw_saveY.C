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
        TGraphMultiErrors* gmep[3];
        TGraphMultiErrors* gmeb[3];
	TLegend *legp = new TLegend(0.18,0.19,0.38,0.39);
	TLegend *legb = new TLegend(0.18,0.19,0.38,0.39);
	legp->SetTextSize(0.045);
	legb->SetTextSize(0.045);
	legp->SetTextFont(132);
	legb->SetTextFont(132);
	for(int th=0;th<3;th++)
	{
		int Npnbin, Nbnbin;
                ifstream npconfig(Form("../3_Result/promptBinY%d.txt",th+1));
                ifstream nbconfig(Form("../3_Result/frombBinY%d.txt",th+1));
                Npnbin=5;
		Nbnbin=5;
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
                TH1D *tempSysp = (TH1D*)allT->Get(Form("pY%d",th+1));
                TH1D *tempSysb = (TH1D*)allT->Get(Form("bY%d",th+1));
                allT = TFile::Open("../../result/3_Result/SaveStats.root");
                TH1D *tempStatsp = (TH1D*)allT->Get(Form("pY%d",th+1));
                TH1D *tempStatsb = (TH1D*)allT->Get(Form("bY%d",th+1));
                ifstream perr(Form("../3_Result/promptBinYErr%d.txt",th+1));
                ifstream berr(Form("../3_Result/frombBinYErr%d.txt",th+1));

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
		//Sys
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
                	unit -> GetXaxis()->SetTitle("#font[12]{N}_{fwd}^{PV}/#LT#font[12]{N}_{fwd}^{PV}#GT_{NB}");
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
		canp -> cd();
                gmep[th] -> Draw("PS same; Z ; 5 s=1 ; same");
                canb ->cd();
                gmeb[th] -> Draw("PS same; Z ; 5 s=1 ; same");
		legp -> AddEntry(gmep[th],Form("%.1f < #font[12]{y} < %.1f",y_s[th],y_s[th+1]),"PLEZ");
		legb -> AddEntry(gmeb[th],Form("%.1f < #font[12]{y} < %.1f",y_s[th],y_s[th+1]),"PLEZ");
	}
	canp -> cd();
	legp -> Draw("same");
	canb -> cd();
	legb -> Draw("same");
	TLegend *Titlep = new TLegend(0.6, 0.7, 0.7, 0.8);
        Titlep -> SetTextSize(0.06);
        Titlep->SetTextFont(132);
	Titlep -> SetHeader("prompt");
	TLegend *Titleb = new TLegend(0.6, 0.7, 0.7, 0.8);
        Titleb -> SetTextSize(0.06);
        Titleb->SetTextFont(132);
	Titleb -> SetHeader("non-prompt");
        canp -> cd();
	lhcbName->Draw();
	Titlep -> Draw("same");
	canb -> cd();
	lhcbName->Draw();
	Titleb -> Draw("same");
	canp -> SaveAs("../4_Plot/promptRatioYF.pdf");
	canp -> SaveAs("../4_Plot/promptRatioYF.png");
	canp -> SaveAs("../4_Plot/promptRatioYF.eps");
	canp -> SaveAs("../4_Plot/promptRatioYF.C");

	canp -> Close();
	canb -> SaveAs("../4_Plot/frombRatioYF.pdf");
	canb -> SaveAs("../4_Plot/frombRatioYF.png");
        canb -> SaveAs("../4_Plot/frombRatioYF.eps");
        canb -> SaveAs("../4_Plot/frombRatioYF.C");

	canb -> Close();
	return 0;
}
