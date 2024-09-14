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
	Nbnbin = 5;
        yconfig >> Nybin;
        ptconfig >> Nptbin;
        for(int i=0; i<Npnbin; i++)
        {
                npconfig >> nbin;
                n_p.push_back(nbin);
        	nbconfig >> nbin;
		n_b.push_back(nbin);
		//cout << n_b[i] << endl;
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
	TFile *allT = TFile::Open("../../../../workdir/Yield/result/3_Result/SaveSys.root");	
	TH1D *tempSysp = (TH1D*)allT->Get("allp");
	TH1D *tempSysb = (TH1D*)allT->Get("allb");
	allT = TFile::Open("../../../../workdir/Yield/result/3_Result/SaveStats.root");
        TH1D *tempStatsp = (TH1D*)allT->Get("allp");
        TH1D *tempStatsb = (TH1D*)allT->Get("allb");
	ifstream tberr("../3_Result/Nch_fromberr.txt");
	ifstream tperr("../3_Result/Nch_prompterr.txt");
	//Stats
	for(int i=1;i<=N;i++)
	{
		yp[i-1]=tempStatsp->GetBinContent(i);
		yp_lo[i-1]=tempStatsp->GetBinError(i);
		yp_hi[i-1]=yp_lo[i-1];
		yb[i-1]=tempStatsb->GetBinContent(i);
                yb_lo[i-1]=tempStatsb->GetBinError(i);
                yb_hi[i-1]=yb_lo[i-1];
		xp[i-1]=n_p[i-1]/1;
		xb[i-1]=n_b[i-1]/1;		//done before
		double aa;
		tberr >> aa;
		xb_lo[i-1]=aa;
		xb_hi[i-1]=aa;
		tperr >> aa;
                xp_lo[i-1]=aa;
		xp_hi[i-1]=aa;
		cout << aa << endl;
		/*xp_lo[i-1]=xp[i-1]-BCs[i-1];
		xp_hi[i-1]=BCs[i]-xp[i-1];
		xb_lo[i-1]=xb[i-1]-BCs[i-1];
                xb_hi[i-1]=BCs[i]-xb[i-1];
		cout << yp_lo[i-1] << endl;*/
		/*double ww = 0.7;
                xp_lo[i-1]=ww;
                xp_hi[i-1]=ww;
                xb_lo[i-1]=ww;
                xb_hi[i-1]=ww;*/

	}
	TF1 *unit = new TF1("unit","1+x-x",0,25);
        unit -> SetLineStyle(2);
        unit -> SetLineColor(1);
	unit -> GetYaxis() -> SetRangeUser(0.6,1.4);
	unit -> GetXaxis()->SetTitle("d#font[12]{N}_{ch}/d#eta");
	unit -> GetYaxis()->SetTitle("Normalised #sigma_{#psi(2S)}/#sigma_{J/#psi}");
	unit -> Draw();
	//Sys
	double pWidth[N], bWidth[N], pHeight[N], bHeight[N];
	for(int i=1;i<=N;i++)
        {
		pWidth[i-1]=0.1;
		bWidth[i-1]=0.1;
		pHeight[i-1]=tempSysp->GetBinError(i);
		bHeight[i-1]=tempSysb->GetBinError(i);
	}

        //prompt
        TGraphMultiErrors* gmep = new TGraphMultiErrors("gmep", "", N, xp, yp, xp_lo, xp_hi, yp_lo, yp_hi);
        gmep -> AddYError(N, pHeight, pHeight);
        gmep -> SetMarkerStyle(20);
        gmep -> SetMarkerSize(1.5);
        gmep -> SetMarkerColor(kRed);
        gmep -> SetLineColor(kRed);
        gmep -> GetAttLine(0)->SetLineColor(kRed);
        gmep -> GetAttLine(1)->SetLineColor(kRed);
        gmep -> GetAttFill(1)->SetFillColorAlpha(kRed,0.25);
        gmep -> GetYaxis() -> SetRangeUser(0.6,1.4);
        gmep -> GetXaxis() -> SetLimits(0,5);
        gmep -> GetXaxis()->SetTitle("d#font[12]{N}_{ch}/d#eta");
        gmep -> GetYaxis()->SetTitle("Normalised #sigma_{#psi(2S)}/#sigma_{J/#psi}");
        gmep -> Draw("PS same; Z ; 5 s=1 ; same");
	//fromb
        TGraphMultiErrors* gmeb = new TGraphMultiErrors("gmeb", "", N, xb, yb, xb_lo, xb_hi, yb_lo, yb_hi);
        gmeb -> AddYError(N, bHeight, bHeight);
        gmeb -> SetMarkerStyle(20);
        gmeb -> SetMarkerSize(1.5);
        gmeb -> SetMarkerColor(kBlue);
        gmeb -> SetLineColor(kBlue);
        gmeb -> GetAttLine(0)->SetLineColor(kBlue);
        gmeb -> GetAttLine(1)->SetLineColor(kBlue);
        gmeb -> GetAttFill(1)->SetFillColorAlpha(kBlue,0.25);
        gmeb -> GetYaxis() -> SetRangeUser(0.6,1.4);
        gmeb -> GetXaxis() -> SetLimits(0,5);
        gmeb -> GetXaxis()->SetTitle("d#font[12]{N}_{ch}/d#eta");
        gmeb -> GetYaxis()->SetTitle("Normalised #sigma_{#psi(2S)}/#sigma_{J/#psi}");
        gmeb -> Draw("PS same; Z ; 5 s=1 ; same");

       	TLegend *legSys = new TLegend(0.18,0.19,0.38,0.39);
        legSys->SetTextFont(132);
        legSys->SetBorderSize(2);
        legSys->SetTextSize(0.05);
        legSys->AddEntry(gmep,"prompt","PLEZ");
        legSys->AddEntry(gmeb,"non-prompt","PLEZ");

        legSys->Draw("same");


	lhcbName -> Draw();
        can->SaveAs(Form("../4_Plot/AllNch.pdf"),"recreate");
	can->SaveAs(Form("../4_Plot/AllNch.png"),"recreate");
	can->SaveAs(Form("../4_Plot/AllNch.eps"),"recreate");
	can->SaveAs(Form("../4_Plot/AllNch.C"),"recreate");

        can->Close();
	return 0;
}
