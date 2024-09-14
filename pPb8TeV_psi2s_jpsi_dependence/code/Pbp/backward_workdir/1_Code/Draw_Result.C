#define sPlot_cxx
#include <TGraphMultiErrors.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <iostream>
#include <fstream>
#include <TFile.h>
#include <TH1D.h>
#include <math.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TLegend.h>
#include "0_header/lhcbStyle.h"
#include "0_header/sPlot.h"
using namespace std;

double MAX(double x, double y)
{
	if (x>=y) return x;
	if (x<y) return y;
}

int main(int argc, char* argv[])
{
	//input nbin
	int N;
	double N_noBias = 22.47;	//change
	ifstream Bin("0_Bin/nbin");
	Bin >> N;
	int bin[N+1];
	for(int i=0;i<=N;i++)
	{
		Bin >> bin[i];
	}
	Bin.close();
	
	double trash;
	//input trigger error
	ifstream L0Hlt1("../4_Result/SysErr/TISTOS.txt");
	double TriErr1, TriErr2;
	L0Hlt1 >> TriErr1 >> TriErr2;
	double TriErr = MAX(TriErr1, TriErr2);
	//input Acc Error
	double AccErr;
	ifstream ACCERR("../4_Result/Eff_Acc/ErrAcc.txt");
	ACCERR >> trash >> AccErr;
	//input PIDSCheme err
	double PIDErr[N];
	for(int i=1;i<=N;i++)
	{
		ifstream PIDSCHEME(Form("../4_Result/SysErr/PIDCalibBinScheme/n%d.txt",i));
		PIDSCHEME >> PIDErr[i-1];
	}
	//input Branch ratio err
	double BRErr = 0.022;

	//input TTree
	TFile *inputFile = TFile::Open("../4_Result/CBFit/sPlot/Jpsi.root");
	TTree *inputTree = (TTree*)inputFile->Get("DecayTree");
	sPlot t(inputTree);
	int Ntree = inputTree->GetEntries();
	double x[N];
	TH1D *th[N];
	for(int i=0;i<N;i++)
	{
		th[i] = new TH1D(Form("th%d",i),Form("th%d",i),bin[i+1]-bin[i], bin[i], bin[i+1]);
	}
	for(int i=0; i<Ntree; i++)
	{
		inputTree->GetEntry(i);
		for(int j=0;j<N;j++)
		{
			th[j] -> Fill(t.psi_nBackTracks,t.sig_sw);//change
		}
	}
	//calculate for
	double x_lo[N], x_hi[N];
	for(int i=0; i<N; i++)
        {
		x[i] = th[i]->GetMean()/N_noBias;
		/*x_lo[i] = x[i] - bin[i]/N_noBias;
		x_hi[i] = bin[i+1]/N_noBias-x[i];
		cout << bin[i]/N_noBias << endl;*/
		x_lo[i] = 0.024;
		x_hi[i] = 0.024;
	}
	cout << bin[N]/N_noBias << endl;
	//input fit result and Stats Err
	double Jprompt = 0;
       	double Pprompt = 0;
       	double Jfromb = 0;
       	double Pfromb = 0;
	double NJprompt[N], NJfromb[N], NPprompt[N], NPfromb[N];
	double NJpromptErr[N], NJfrombErr[N], NPpromptErr[N], NPfrombErr[N];
	double yp[N], yb[N], ypStatsErr[N], ybStatsErr[N];
	for(int i=0;i<N;i++)
	{
		ifstream inJ(Form("../4_Result/TwoDimFit/Jpsi_n%dy1pt1.txt",i+1));
		inJ >> NJprompt[i] >> NJpromptErr[i] >> NJfromb[i] >> NJfrombErr[i];
		inJ.close();
		ifstream inP(Form("../4_Result/TwoDimFit/Psi2S_n%dy1pt1.txt",i+1));
		inP >> NPprompt[i] >> NPpromptErr[i] >> NPfromb[i] >> NPfrombErr[i];
		yp[i] = NPprompt[i]/NJprompt[i];
		yb[i] = NPfromb[i]/NJfromb[i];
		inP.close();
		ypStatsErr[i] = sqrt(NPpromptErr[i]*NPpromptErr[i]/NPprompt[i]/NPprompt[i]+NJpromptErr[i]*NJpromptErr[i]/NJprompt[i]/NJprompt[i]);
		ybStatsErr[i] = sqrt(NPfrombErr[i]*NPfrombErr[i]/NPfromb[i]/NPfromb[i]+NJfrombErr[i]*NJfrombErr[i]/NJfromb[i]/NJfromb[i]);
	}
	//input EffJ and Effp for sigma_total calculation
	double eJ[N], eP[N];
	for(int i=0;i<N;i++)
        {
		ifstream inJ(Form("../4_Result/Eff_RecselPIDTrigger/h_eff_tot_J_n%d.txt",i+1));
		inJ >> eJ[i];
		Jprompt = Jprompt + NJprompt[i]/eJ[i];
		Jfromb = Jfromb + NJfromb[i]/eJ[i];	
		inJ.close();
		ifstream inP(Form("../4_Result/Eff_RecselPIDTrigger/h_eff_tot_P_n%d.txt",i+1));
                inP >> eP[i];
		Pprompt = Pprompt + NPprompt[i]/eP[i];
                Pfromb = Pfromb + NPfromb[i]/eP[i];
                inP.close();
	}
	double rp = Pprompt/Jprompt;
	double rb = Pfromb/Jfromb;
	//input ratio of Eff and Sys Err
	double ratio[N], ypSysErr[N], ybSysErr[N];
	for(int i=0;i<N;i++)
        {
		ifstream in(Form("../4_Result/SysErr/General/n%d.txt",i+1));
		in >> ratio[i];
		cout << "ratio" << i+1 << "=" << ratio[i] << endl;
		yp[i] = yp[i]*ratio[i]/rp;
		yb[i] = yb[i]*ratio[i]/rb;
		in >> ypSysErr[i];
		in.close();
		ypSysErr[i] = sqrt(ypSysErr[i]*ypSysErr[i]+TriErr*TriErr+AccErr*AccErr+PIDErr[i]*PIDErr[i]);
		ybSysErr[i] = ypSysErr[i];
		//relative to absolute error
		ypStatsErr[i] = yp[i]*ypStatsErr[i];
		ybStatsErr[i] = yb[i]*ybStatsErr[i];
		ypSysErr[i] = yp[i]*ypSysErr[i];
                ybSysErr[i] = yb[i]*ybSysErr[i];
	}
	ofstream OUT("../4_Result/Ratio/ForPlot.txt");
        OUT << rp << endl;
        OUT << rb << endl;
	for(int i=0;i<N;i++)
        {
                OUT << x[i] << endl;
                OUT << yp[i] << endl;
                OUT << yb[i] << endl;
                OUT << ypStatsErr[i] << endl;
                OUT << ybStatsErr[i] << endl;
                OUT << sqrt(ypSysErr[i]*ypSysErr[i]+0*BRErr*BRErr*yp[i]*yp[i]) << endl;
                OUT << sqrt(ybSysErr[i]*ypSysErr[i]+0*BRErr*BRErr*yb[i]*yb[i]) << endl;
        }
	//Draw
	setLHCbStyle();
	TCanvas *can = new TCanvas("can","can",1200,800);
	TF1 *unit = new TF1("unit","1+x-x",0,x[N-1]+x_hi[N-1]+0.3);
	unit -> SetLineStyle(2);
        unit -> SetLineColor(1);
        unit -> GetYaxis() -> SetRangeUser(0.4,1.6);
	unit -> GetXaxis()->SetTitle("#font[12]{N}_{bwd}^{PV}/#LT#font[12]{N}_{bwd}^{PV}#GT_{NB}");
        unit -> GetYaxis()->SetTitle("Normalized #sigma_{#psi(2S)}/#sigma_{J/#psi}");
	unit -> GetXaxis() -> SetLimits(0,3);
        unit -> Draw();
	TGraphMultiErrors *TGEp = new TGraphMultiErrors(N,x,yp,x_lo,x_hi,ypStatsErr,ypStatsErr);
	TGraphMultiErrors *TGEb = new TGraphMultiErrors(N,x,yb,x_lo,x_hi,ybStatsErr,ybStatsErr);
	TGEp -> AddYError(N, ypSysErr, ypSysErr);
	TGEb -> AddYError(N, ybSysErr, ybSysErr);
	TGEp -> SetMarkerColor(kViolet);
	TGEp -> SetLineColor(kViolet);
        TGEb -> SetMarkerColor(kBlue);
	TGEb -> SetLineColor(kBlue);
        TGEp -> SetMarkerStyle(21);
        TGEb -> SetMarkerStyle(21);
	TGEp -> GetAttLine(0)->SetLineColor(kViolet);
   	TGEp -> GetAttLine(1)->SetLineColor(kViolet);
   	TGEp -> GetAttFill(1)->SetFillStyle(0);
	TGEb -> GetAttLine(0)->SetLineColor(kBlue);
   	TGEb -> GetAttLine(1)->SetLineColor(kBlue);
   	TGEb -> GetAttFill(1)->SetFillStyle(0);
	TGEp -> Draw("PS same; Z ; 5 s=1 ; same");
	TGEb -> Draw("PS same; Z ; 5 s=1 ; same");
	TLegend *legSys = new TLegend(0.18,0.25,0.38,0.39);
        legSys->SetTextFont(132);
        legSys->SetBorderSize(2);
        legSys->SetTextSize(0.05);
        legSys->AddEntry(TGEp,"prompt","PLEZ");
        legSys->AddEntry(TGEb,"non-prompt","PLEZ");
        legSys->Draw("same");
	lhcbName->Draw();
	can -> SaveAs("../5_Plots/Result/All.pdf");
	can -> Close();
	return 0;
}
