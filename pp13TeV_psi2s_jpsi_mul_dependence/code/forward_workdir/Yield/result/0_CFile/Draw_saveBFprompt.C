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
	//int N;
        double BCs[6] = {0,0.74349442, 1.4869888,2.2304833,2.9739777,8.0545229};
	vector<double>  y_s;
	vector<int> pt_s;
	vector<double> n_p, n_b;
        double nbin, ybin, ptbin;
        int Npnbin, Nbnbin, Nybin, Nptbin;
        ifstream npconfig(argv[1]);
	ifstream nbconfig(argv[2]);
        ifstream yconfig(argv[3]);
        ifstream ptconfig(argv[4]);
        Npnbin = 5;
	//nbconfig >> Nbnbin;
        yconfig >> Nybin;
        ptconfig >> Nptbin;
        for(int i=0; i<Npnbin; i++)
        {
                npconfig >> nbin;
                n_p.push_back(nbin);
        	nbconfig >> nbin;
		n_b.push_back(nbin);
		cout << n_b[i] << endl;
	}
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
        double color[Nybin+Nptbin], marker[Nybin+Nptbin];
        for(int i=0; i<Nybin+Nptbin; i++)
        {
                color[i] = 2*i+1;
                marker[i] = 20+i*2;
        }
        gROOT->SetBatch(true);
        setLHCbStyle();
	//Draw total Modification
	//input
	int N = Npnbin;
	double xp[N], xb[N], xp_lo[N], xp_hi[N], xb_lo[N], xb_hi[N];
	double yp[N], yb[N], yp_lo[N], yp_hi[N], yb_lo[N], yb_hi[N];
	TCanvas *can = new TCanvas("can","can",1600,1200);
	TFile *allT = TFile::Open("../../result/3_Result/SaveSys.root");	
	TH1D *tempSysp = (TH1D*)allT->Get("allp");
	allT = TFile::Open("/disk402/lhcb/kangye/BackWorkdir/Yield/result/3_Result/SaveSys.root");
	TH1D *tempSysb = (TH1D*)allT->Get("allp");
	allT = TFile::Open("../../result/3_Result/SaveStats.root");
        TH1D *tempStatsp = (TH1D*)allT->Get("allp");
        allT = TFile::Open("/disk402/lhcb/kangye/BackWorkdir/Yield/result/3_Result/SaveStats.root");
	TH1D *tempStatsb = (TH1D*)allT->Get("allp");
	ifstream perr("../3_Result/promptBinErr.txt"); 
	ifstream berr("../../../../BackWorkdir/Yield/result/3_Result/XBackInForwardPrompterr.txt");
	//Stats
	for(int i=1;i<=N;i++)
	{
		yp[i-1]=tempStatsp->GetBinContent(i);
		yp_lo[i-1]=tempStatsp->GetBinError(i);
		yp_hi[i-1]=yp_lo[i-1];
		yb[i-1]=tempStatsb->GetBinContent(i);
                yb_lo[i-1]=tempStatsb->GetBinError(i);
                yb_hi[i-1]=yb_lo[i-1];
		xp[i-1]=n_p[i-1];
		xb[i-1]=n_b[i-1];
		perr >> xp_lo[i-1];
		xp_hi[i-1]=xp_lo[i-1];
		berr >> xb_lo[i-1];
                xb_hi[i-1]=xb_lo[i-1];
	}
	//Sys
	double pWidth[N], bWidth[N], pHeight[N], bHeight[N];
	for(int i=1;i<=N;i++)
        {
		pWidth[i-1]=0.04;
		bWidth[i-1]=0.04;
		pHeight[i-1]=tempSysp->GetBinError(i);
		bHeight[i-1]=tempSysb->GetBinError(i);
	}
	TF1 *unit = new TF1("unit","1+x-x",0,4.4);
        unit -> SetLineStyle(2);
        unit -> SetLineColor(1);
	unit -> GetYaxis() -> SetRangeUser(0.6,1.4);
	unit -> GetXaxis()->SetTitle("#font[12]{N}_{fwd}^{PV}/#LT#font[12]{N}_{fwd}^{PV}#GT_{NB}");
	unit -> GetYaxis()->SetTitle("Normalised #sigma_{#psi(2S)}/#sigma_{J/#psi}");
	unit -> Draw();
	TGraphMultiErrors* gmep = new TGraphMultiErrors("gmep", "", N, xp, yp, xp_lo, xp_hi, yp_lo, yp_hi);
        gmep -> AddYError(N, pHeight, pHeight);
        gmep -> SetMarkerStyle(20);
        //gmep -> SetMarkerSize(1);
        gmep -> SetMarkerColor(kGreen);
        gmep -> SetLineColor(kGreen);
        gmep -> GetAttLine(0)->SetLineColor(kGreen);
        gmep -> GetAttLine(1)->SetLineColor(kGreen);
        gmep -> GetAttFill(1)->SetFillColorAlpha(kGreen, 0);
        gmep -> GetYaxis() -> SetRangeUser(0.6,1.4);
        gmep -> GetXaxis() -> SetLimits(0,4.4);
        gmep -> GetXaxis()->SetTitle("#font[12]{N}_{fwd}^{PV}/#LT#font[12]{N}_{fwd}^{PV}#GT_{NB}");
        gmep -> GetYaxis()->SetTitle("Normalised #sigma_{#psi(2S)}/#sigma_{J/#psi}");
        gmep -> Draw("PS same; Z ; 5 s=1 ; same");

	TGraphMultiErrors *gmeb = new TGraphMultiErrors("gmeb", "", N,xb,yb,xb_lo, xb_hi, yb_lo,yb_hi);
	gmeb -> AddYError(N, pHeight, pHeight);
        gmeb -> SetMarkerStyle(20);
	gmeb -> SetMarkerColor(kBlack);
        gmeb -> SetLineColor(kBlack);
        gmeb -> GetAttLine(0)->SetLineColor(kBlack);
        gmeb -> GetAttLine(1)->SetLineColor(kBlack);
        gmeb -> GetAttFill(1)->SetFillColorAlpha(kBlack, 0);
        gmeb -> Draw("PS same; Z ; 5 s=1 ; same");
		
	TLegend *legSys = new TLegend(0.18,0.19,0.38,0.39);
        legSys->SetTextFont(132);
        legSys->SetBorderSize(2);
        legSys->SetTextSize(0.05);
        legSys->AddEntry(gmep,"Result of #font[12]{N}_{fwd}^{PV}","PLEZ");
        legSys->AddEntry(gmeb,"Migrated from #font[12]{N}_{bwd}^{PV}","PLEZ");
        legSys->Draw("same");
	lhcbName->Draw();
	TLegend *Titlep = new TLegend(0.6, 0.7, 0.7, 0.8);
        Titlep->SetTextFont(132);
        Titlep -> SetTextSize(0.06);
        Titlep -> SetHeader("prompt");
	Titlep -> Draw("same");
	can->SaveAs(Form("../4_Plot/AllBtoF.pdf"),"recreate");
	can->SaveAs(Form("../4_Plot/AllBtoF.eps"),"recreate");
	can->SaveAs(Form("../4_Plot/AllBtoF.png"),"recreate");
	can->SaveAs(Form("../4_Plot/AllBtoF.C"),"recreate");

        can->Close();
	return 0;
}
