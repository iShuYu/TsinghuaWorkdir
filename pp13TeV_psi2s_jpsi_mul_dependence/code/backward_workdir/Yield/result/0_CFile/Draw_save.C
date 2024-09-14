#include <TGraphErrors.h>
#include <TGraphMultiErrors.h>
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
        Npnbin = 5;
	ifstream npconfig(argv[1]);
	ifstream nbconfig(argv[2]);
        ifstream yconfig(argv[3]);
        ifstream ptconfig(argv[4]);
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
	ifstream errp("../3_Result/promptBinErr.txt");
	ifstream errb("../3_Result/frombBinErr.txt");
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
		errp >> xp_lo[i-1];
		xp_hi[i-1] = xp_lo[i-1];
		errb >> xb_lo[i-1];
                xb_hi[i-1] = xb_lo[i-1];
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
	//comover
	/*TGraphErrors *ge = new TGraphErrors(38,CX,CM,zeros,CS);
        ge -> SetFillColor(6);
        ge -> SetFillStyle(3005);
        ge -> GetYaxis() -> SetRangeUser(0.6,1.4);
        ge -> GetXaxis() -> SetLimits(0,4.4);
        ge -> GetXaxis()->SetTitle("#font[12]{N}_{bwd}^{PV}/#LT#font[12]{N}_{bwd}^{PV}#GT_{NB}");
        ge -> GetYaxis()->SetTitle("Normalised #sigma_{#psi(2S)}/#sigma_{J/#psi}");
        //ge -> Draw("a3");*/
	//prompt
	TGraphMultiErrors* gmep = new TGraphMultiErrors("gmep", "", N, xp, yp, xp_lo, xp_hi, yp_lo, yp_hi);
   	gmep -> AddYError(N, pHeight, pHeight);
   	gmep -> SetMarkerStyle(20);
	gmep -> SetMarkerSize(1.5);
	gmep -> SetMarkerColor(kBlack);
   	gmep -> SetLineColor(kBlack);
   	gmep -> GetAttLine(0)->SetLineColor(kBlack);
   	gmep -> GetAttLine(1)->SetLineColor(kBlack);
   	gmep -> GetAttFill(1)->SetFillColorAlpha(kBlack,0);
	gmep -> GetYaxis() -> SetRangeUser(0.6,1.4);
        gmep -> GetXaxis() -> SetLimits(0,4.4);
        gmep -> GetXaxis()->SetTitle("#font[12]{N}_{bwd}^{PV}/#LT#font[12]{N}_{bwd}^{PV}#GT_{NB}");
        gmep -> GetYaxis()->SetTitle("Normalised #sigma_{#psi(2S)}/#sigma_{J/#psi}");
	//gmep -> Draw("PS same; Z ; 5 s=1 ; same");
 	//fromb
	TGraphMultiErrors* gmeb = new TGraphMultiErrors("gmeb", "", N, xb, yb, xb_lo, xb_hi, yb_lo, yb_hi);
        gmeb -> AddYError(N, bHeight, bHeight);
        gmeb -> SetMarkerStyle(20);
	gmeb -> SetMarkerSize(1.5);
        gmeb -> SetMarkerColor(kBlue);
        gmeb -> SetLineColor(kBlue);
        gmeb -> GetAttLine(0)->SetLineColor(kBlue);
        gmeb -> GetAttLine(1)->SetLineColor(kBlue);
        gmeb -> GetAttFill(1)->SetFillColorAlpha(kBlue,0);
        gmeb -> GetYaxis() -> SetRangeUser(0.6,1.4);
        gmeb -> GetXaxis() -> SetLimits(0,4.4);
        gmeb -> GetXaxis()->SetTitle("#font[12]{N}_{bwd}^{PV}/#LT#font[12]{N}_{bwd}^{PV}#GT_{NB}");
        gmeb -> GetYaxis()->SetTitle("Normalised #sigma_{#psi(2S)}/#sigma_{J/#psi}");
        //gmeb -> Draw("PS same; Z ; 5 s=1 ; same");
	
	TF1 *unit = new TF1("unit","1+x-x",0,4.4);
        unit -> SetLineStyle(2);
        unit -> SetLineColor(1);
	unit -> GetYaxis() -> SetRangeUser(0.6,1.4);
        unit -> GetXaxis() -> SetLimits(0,4.4);
        unit -> GetXaxis()->SetTitle("#font[12]{N}_{bwd}^{PV}/#LT#font[12]{N}_{bwd}^{PV}#GT_{NB}");
        unit -> GetYaxis()->SetTitle("Normalised #sigma_{#psi(2S)}/#sigma_{J/#psi}");
	unit -> Draw();	
	 gmep -> Draw("PS same; Z ; 5 s=1 ; same");
	gmeb -> Draw("PS same; Z ; 5 s=1 ; same");

	TLegend *legSys = new TLegend(0.18,0.19,0.38,0.39);
        legSys->SetTextFont(132);
        legSys->SetBorderSize(2);
        legSys->SetTextSize(0.05);
        legSys->AddEntry(gmep,"prompt","PLEZ");
        legSys->AddEntry(gmeb,"non-prompt","PLEZ");
	//legSys->AddEntry(ge,"co-mover model","F");
        legSys->Draw("same");
	/*TLegend *Title = new TLegend(0.2,0.85,0.9,0.94);
        Title->SetTextSize(0.04);
        Title->SetHeader("2.0<y<4.5, 0.3GeV<p_{T}<20GeV, -60mm<z_{PV}<180mm");
        Title->Draw("same");*/
	lhcbName->Draw();
        can->SaveAs(Form("../4_Plot/AllB.pdf"),"recreate");
	can->SaveAs(Form("../4_Plot/AllB.png"),"recreate");
	can->SaveAs(Form("../4_Plot/AllB.C"),"recreate");
	can->SaveAs(Form("../4_Plot/AllB.eps"),"recreate");
        can->Close();
	return 0;
}
