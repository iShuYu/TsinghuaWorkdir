#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
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
        double BCs[6] = {0,0.636185007180620,1.272370014361240,1.908555021541861,2.544740028722481,6.361850071806201};
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
	TGraphAsymmErrors *TGAEp[5];
	TGraphAsymmErrors *TGAEb[5];
	TGraphErrors *TGEp[5];
	TGraphErrors *TGEb[5];
	TLegend *legp = new TLegend(0.18,0.19,0.38,0.39);
	TLegend *legb = new TLegend(0.18,0.19,0.38,0.39);
	for(int th=0;th<5;th++)
	{
		int Npnbin, Nbnbin;
                ifstream npconfig(Form("../3_Result/promptBinPT%d.txt",th+1));
                ifstream nbconfig(Form("../3_Result/frombBinPT%d.txt",th+1));
                npconfig >> Npnbin;
		nbconfig >> Nbnbin;
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
                	xp_lo[i-1]=xp[i-1]-BCs[i-1];
                	xp_hi[i-1]=BCs[i]-xp[i-1];
                	xb_lo[i-1]=xb[i-1]-BCs[i-1];
                        xb_hi[i-1]=BCs[i]-xb[i-1];
                	cout << xp[i-1] << endl;
		}	
		if(th==0)
		{	
			TF1 *unit = new TF1("unit","1+x-x",0,4.5);
                	unit -> SetLineStyle(2);
                	unit -> SetLineColor(1);
                	unit -> GetYaxis() -> SetRangeUser(0.4,1.6);
                	unit -> GetXaxis()->SetTitle("#frac{PVNTRACKS}{        <PVNTRACKS>_{NoBias}}");
                	unit -> GetYaxis()->SetTitle("Normalized #sigma_{#psi(2S)}/#sigma_{J/#psi}");
                	canp -> cd();
			unit -> Draw();
			canb -> cd();
			unit -> Draw();
                }
		TGAEp[th] = new TGraphAsymmErrors(N,xp,yp,0,0,yp_lo,yp_hi);
                TGAEb[th] = new TGraphAsymmErrors(N,xb,yb,0,0,yb_lo,yb_hi);
                TGAEp[th] -> SetMarkerColor(color[th]);
                TGAEb[th] -> SetMarkerColor(color[th]);
                TGAEp[th] -> SetMarkerStyle(21);
                TGAEb[th] -> SetMarkerStyle(21);
                TGAEp[th] -> GetXaxis()->SetTitle("#frac{PVNTRACKS}{        <PVNTRACKS>_{NoBias}}");
                TGAEp[th] -> GetYaxis()->SetTitle("Normalized #sigma_{#psi(2S)}/#sigma_{J/#psi}");
                canp -> cd();
		TGAEp[th] -> Draw("PZsame");
		canb ->cd();
                TGAEb[th] -> Draw("PZsame");
                //Sys
                double pWidth[N], bWidth[N], pHeight[N], bHeight[N];
                for(int i=1;i<=N;i++)
                {
                	pWidth[i-1]=0.1;
                	bWidth[i-1]=0.1;
                	pHeight[i-1]=tempSysp->GetBinError(i);
                	bHeight[i-1]=tempSysb->GetBinError(i);
                }
                TGEp[th] = new TGraphErrors(N,xp,yp,pWidth,pHeight);
                TGEb[th] = new TGraphErrors(N,xb,yb,bWidth,bHeight);
                TGEp[th] -> SetMarkerColor(color[th]);
                TGEb[th] -> SetMarkerColor(color[th]);
                TGEp[th] -> SetMarkerStyle(21);
                TGEb[th] -> SetMarkerStyle(21);
                TGEp[th] -> SetFillColorAlpha(color[th],0.25);;
                TGEb[th] -> SetFillColorAlpha(color[th],0.25);;
                canp -> cd();
		TGEp[th] -> Draw("E2PZsame");
                canb -> cd();
		TGEb[th] -> Draw("E2PZsame");
                legp -> AddEntry(TGEp[th],Form("%.1fGeV<p_{T}<%.1fGeV",pt_s[th]/1000.001,pt_s[th+1]/1000.001));
		legb -> AddEntry(TGEb[th],Form("%.1fGeV<p_{T}<%.1fGeV",pt_s[th]/1000.001,pt_s[th+1]/1000.001));
	}
	canp -> cd();
	legp -> Draw("same");
	canb -> cd();
	legb -> Draw("same");
	TLegend *Titlep = new TLegend(0.5,0.85,0.9,0.94);
        Titlep -> SetTextSize(0.05);
        Titlep -> SetHeader("prompt");
	TLegend *Titleb = new TLegend(0.5,0.85,0.9,0.94);
        Titleb -> SetTextSize(0.05);
        Titleb -> SetHeader("from-b");
        canp -> cd();
	Titlep -> Draw("same");
	canb -> cd();
	Titleb -> Draw("same");
	canp -> SaveAs("../4_Plot/promptRatioPT.pdf");
	canp -> Close();
	canb -> SaveAs("../4_Plot/frombRatioPT.pdf");
	canb -> Close();
	return 0;
}
