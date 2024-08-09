#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TAxis.h>
#include <fstream>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <math.h>
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
        double BCs[6] = {0.15455951,0.77279753,1.7387944,2.7047913,3.6707883,7.7279753};
	vector<double>  y_s;
	vector<int> pt_s;
	vector<double> n_p, n_b;
        double nbin, ybin, ptbin;
        int Npnbin, Nbnbin, Nybin, Nptbin;
        ifstream npconfig(argv[1]);
	ifstream nbconfig(argv[2]);
        ifstream yconfig(argv[3]);
        ifstream ptconfig(argv[4]);
        npconfig >> Npnbin;
	nbconfig >> Nbnbin;
        yconfig >> Nybin;
        ptconfig >> Nptbin;
        for(int i=0; i<Npnbin; i++)
        {
                npconfig >> nbin;
                n_p.push_back(nbin);
        	nbconfig >> nbin;
		n_b.push_back(nbin);
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

	//input  data set

	//Stats err
	int N = Npnbin;
	double xp[N], xb[N], xp_lo[N], xp_hi[N], xb_lo[N], xb_hi[N];
	double yp[N], yb[N], yp_lo[N], yp_hi[N], yb_lo[N], yb_hi[N];
	
	TCanvas *can = new TCanvas("can","can",1600,1200);
	TFile *allT = TFile::Open("../../result/3_Result/SaveSys.root");	
	TH1D *tempSysp = (TH1D*)allT->Get("allp");
	TH1D *tempSysb = (TH1D*)allT->Get("allb");
	allT = TFile::Open("../../result/3_Result/SaveStats.root");
        TH1D *tempStatsp = (TH1D*)allT->Get("allp");
        TH1D *tempStatsb = (TH1D*)allT->Get("allb");

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
		xp_lo[i-1]=xp[i-1]-BCs[i-1];
		xp_hi[i-1]=BCs[i]-xp[i-1];
		xb_lo[i-1]=xb[i-1]-BCs[i-1];
                xb_hi[i-1]=BCs[i]-xb[i-1];	
	}
	
	//Sys Err
	double pWidth[N], bWidth[N], pHeight[N], bHeight[N];
        for(int i=1;i<=N;i++)
        {
                pWidth[i-1]=0.1;
                bWidth[i-1]=0.1;
                pHeight[i-1]=tempSysp->GetBinError(i);
                bHeight[i-1]=tempSysb->GetBinError(i);
        }

		
	//comover
	double CX[38], CH[38], CL[38], CM[38], CS[38];
	double zeros[38];
	ifstream comover("../3_Result/CoMover.txt");
	for(int i=0;i<38;i++)
	{
		comover >> CX[i] >> CL[i] >> CH[i];
		CM[i] = 1./2*(CL[i]+CH[i]);
		CS[i] = 1./2*abs(CH[i]-CL[i]);
		zeros[i] = 0.;
	}

	//PLot
	TGraphErrors *ge = new TGraphErrors(38,CX,CM,zeros,CS);
        ge -> SetFillColor(6);
        ge -> SetFillStyle(3005);
        ge -> GetYaxis() -> SetRangeUser(0.6,1.4);
        ge -> GetXaxis() -> SetLimits(0,7.9279753);
	ge -> GetXaxis()->SetTitle("N_{tracks}^{PV}/<N_{tracks}^{PV}>_{NB}");
        ge -> GetYaxis()->SetTitle("Normalized #sigma_{#psi(2S)}/#sigma_{J/#psi}");
        ge -> Draw("a3");

	TGraphAsymmErrors *TGAEp = new TGraphAsymmErrors(N,xp,yp,xp_lo,xp_hi,yp_lo,yp_hi);
        TGraphAsymmErrors *TGAEb = new TGraphAsymmErrors(N,xb,yb,xb_lo,xb_hi,yb_lo,yb_hi);
        TGAEp -> SetMarkerColor(kRed);
        TGAEb -> SetMarkerColor(kBlue);
        TGAEp -> SetLineColor(kRed);
        TGAEb -> SetLineColor(kBlue);
	TGAEp -> SetMarkerStyle(21);
        TGAEb -> SetMarkerStyle(21);
        TGAEp -> GetXaxis() -> SetLimits(0,7.9279753);
        TGAEb -> GetXaxis() -> SetLimits(0,7.9279753);
        TGAEp -> GetHistogram() -> SetMinimum(0.4);
        TGAEp -> GetHistogram() -> SetMaximum(1.6);
        TGAEp -> Draw("PZsame");
        TGAEb -> Draw("PZsame");

        TGraphErrors *TGEp = new TGraphErrors(N,xp,yp,pWidth,pHeight);
        TGraphErrors *TGEb = new TGraphErrors(N,xb,yb,bWidth,bHeight);
        TGEp -> SetMarkerColor(kRed);
        TGEb -> SetMarkerColor(kBlue);
        TGEp -> SetMarkerStyle(21);
        TGEb -> SetMarkerStyle(21);
        TGEp -> SetFillColorAlpha(kRed,0.3);
        TGEb -> SetFillColorAlpha(kBlue,0.3);
        TGEp -> GetXaxis() -> SetLimits(0,7.9279753);
        TGEp -> GetXaxis() -> SetLimits(0,7.9279753);
        TGEp -> Draw("E2PZsame");
        TGEb -> Draw("E2PZsame");
	//box
	TGraphErrors *TGEFp = new TGraphErrors(N,xp,yp,pWidth,pHeight);
        TGraphErrors *TGEFb = new TGraphErrors(N,xb,yb,bWidth,bHeight);
        TGEFp -> SetMarkerStyle(1);
        TGEFb -> SetMarkerStyle(1);
        TGEFp -> SetLineColor(kRed);
        TGEFb -> SetLineColor(kBlue);
        TGEFp -> GetXaxis() -> SetLimits(0,7.9279753);
        TGEFp -> GetXaxis() -> SetLimits(0,7.9279753);
	TGEFp -> SetFillStyle(0);
        TGEFb -> SetFillStyle(0);
        TGEFp -> Draw("E2PZsame");
        TGEFb -> Draw("E2PZsame");


	TF1 *unit = new TF1("unit","1+x-x",0,7.9279753);
        unit -> SetLineStyle(2);
        unit -> SetLineColor(1);
	unit -> Draw("same");	

	TLegend *legSys = new TLegend(0.18,0.19,0.38,0.39);
        legSys->SetTextFont(132);
        legSys->SetBorderSize(2);
        legSys->SetTextSize(0.05);
        legSys->AddEntry(TGEp,"prompt","LPF");
        legSys->AddEntry(TGEb,"from #font[12]{b}","LPF");
	legSys->AddEntry(ge,"co-mover model","F");
        legSys->Draw("same");
	/*TLegend *Title = new TLegend(0.2,0.85,0.9,0.94);
        Title->SetTextSize(0.04);
        Title->SetHeader("2.0<y<4.5, 0.3GeV<p_{T}<20GeV, -60mm<z_{PV}<180mm");
        Title->Draw("same");*/
	lhcbName->Draw();
        can->SaveAs(Form("../4_Plot/All.pdf"),"recreate");
        can->Close();
	return 0;
}
