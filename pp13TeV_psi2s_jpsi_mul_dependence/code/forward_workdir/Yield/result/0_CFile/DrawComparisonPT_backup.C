#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TMultiGraph.h>
#include <TAxis.h>
#include <fstream>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include "lhcbStyle0.h"
#include <TF1.h>
#include <TLatex.h>
#include <TGraph.h>
using namespace std;
int main(int argc, char* argv[])
{
	setLHCbStyle();
	//MyResult
	double x[5] = {1.205,2.977,4.888,6.855,10.375};
	double y[5] = {1.44085,1.91254,2.615,3.29964,3.94047};
	double yerr1[5] = {0.00454901,0.00400526,0.00430775,0.00552683,0.00623027};
       	double yerr2[5] = {0.0334943,0.0379716,0.028923,0.018298,0.0158695};
	double xerr1[5] = {0.};
	double xerr2[5] = {0.1,0.1,0.1,0.1,0.1};
	for(int i=0;i<5;i++)
	{
		yerr1[i] = yerr1[i]*y[i];
		yerr2[i] = yerr2[i]*y[i];
		yerr1[i] = sqrt(yerr1[i]*yerr1[i]+yerr2[i]*yerr2[i]);
		cout << yerr1[i] << endl;
	}
	TGraphErrors *Tmy1 = new TGraphErrors(5,x,y,xerr1,yerr1);
	TGraphErrors *Tmy2 = new TGraphErrors(5,x,y,xerr2,yerr2);

	//CDF result
	double X[1] = {5.4844};
	double Y[1] = {0.5*(2.271+3.893)};
	double Yerr[1] = {0.5*(-2.271+3.893)};
	double Xerr[1] ={0.};
	TGraphErrors *Tcdf = new TGraphErrors(1,X,Y,Xerr,Yerr);
	//CEM result
	ifstream CEM("../3_Result/CEM.csv");
	double cemYL[79], cemYH[79], cemXL[79], cemXH[79], cemY[79],cemX[79], cemErr[79];
	double cemXErr[79] = {0,};
	for(int i=0;i<79;i++)
	{
		CEM >> cemX[i] >> cemYL[i] >> cemYH[i];
		cemY[i] = 50*(cemYL[i]+cemYH[i])*7.93/59.61;	
		cemErr[i] = 50*(cemYH[i]-cemYL[i])*7.93/59.61;
		//cout << cemErr[i] << endl;
	}
	TGraphErrors *Tcem = new TGraphErrors(79,cemX,cemY,cemXErr,cemErr);
	
	//CEM result
        ifstream CEM1("../3_Result/CEM1.csv");
        double cem1YL[31], cem1YH[31], cem1XL[31], cem1XH[31], cem1Y[31],cem1X[31], cem1Err[31];
        double cem1XErr[31] = {0,};
        for(int i=0;i<31;i++)
        {
                CEM1 >> cem1X[i] >> cem1YL[i] >> cem1YH[i];
                cem1Y[i] = 50*(cem1YL[i]+cem1YH[i])*7.93/59.61;
                cem1Err[i] = 50*(cem1YH[i]-cem1YL[i])*7.93/59.61;
		//cout << cem1Err[i] << endl;
        }
        TGraphErrors *Tcem1 = new TGraphErrors(31,cem1X,cem1Y,cem1XErr,cem1Err);

	//E789 result
	ifstream E789("../3_Result/E789.csv");
	double EXL[8], EXH[8], EYL[8], EYH[8], EX[8], EY[8], Eerr[8];
	double EXerr[8] = {0.};
	for(int i=0;i<8;i++)
	{
		E789 >> EXL[i] >> EYL[i] >> EXH[i] >> EYH[i];
		EX[i] = 0.5*(EXH[i]+EXL[i]);
		EY[i] = 0.5*(EYH[i]+EYL[i]);
		Eerr[i] = 0.5*(EYH[i]-EYL[i]);
	}
	TGraphErrors *Te789 = new TGraphErrors(8,EX,EY,EXerr,Eerr);
	//Hera-B result
	ifstream Hera("../3_Result/HeraB.csv");
	double HXL[8], HXH[8], HYL[8], HYH[8], HX[8], HY[8], Herr[8];
	double HXerr[8] = {0.};
	for(int i=0;i<8;i++)
	{
		Hera >> HXL[i] >> HYL[i] >> HXH[i] >> HYH[i];
		HX[i] = 0.5*(HXH[i]+HXL[i]);
		HY[i] = 0.5*(HYH[i]+HYL[i]);
		Herr[i] = 0.5*(HYH[i]-HYL[i]);
	}
	TGraphErrors *Thera = new TGraphErrors(8,HX,HY,HXerr,Herr);
	//LHCb result
	ifstream LHCb("../3_Result/LHCb7TeV.csv");
	double LHXL[6], LHXH[6], LHYL[6], LHYH[6], LHX[6], LHY[6], LHerr[6];
	double LHXerr[6] = {0.};
	for(int i=0;i<6;i++)
	{
		LHCb >> LHXL[i] >> LHYL[i] >> LHXH[i] >> LHYH[i];
		LHX[i] = 0.5*(LHXH[i]+LHXL[i]);
		LHY[i] = 0.5*(LHYH[i]+LHYL[i]);
		LHerr[i] = 0.5*(LHYH[i]-LHYL[i]);
	}
	TGraphErrors *Tlhcb = new TGraphErrors(6,LHX,LHY,LHXerr,LHerr);
	//CMS result
	ifstream CMS("../3_Result/CMS7TeV.txt");
	double cmsXL[5], cmsXH[5], cmsYL[5], cmsYH[5], cmsX[5], cmsY[5], cmserr[5];
	double cmsXerr[5] = {0.};
	for(int i=0;i<5;i++)
	{
		CMS >> cmsXL[i] >> cmsYL[i] >> cmsXH[i] >> cmsYH[i];
		cmsX[i] = 0.5*(cmsXH[i]+cmsXL[i]);
		cmsY[i] = 0.5*(cmsYH[i]+cmsYL[i])*100;
		cmserr[i] = 0.5*(cmsYH[i]-cmsYL[i])*100;
		//cout << cmsY[i] << endl;
	}
	TGraphErrors *Tcms = new TGraphErrors(6,cmsX,cmsY,cmsXerr,cmserr);
	//ALICE result
	ifstream ALICE("../3_Result/ALICE13TeV.txt");
	double aliceXL[12], aliceXH[12], aliceYL[12], aliceYH[12], aliceX[12], aliceY[12], aliceerr[12];
	double aliceXerr[12] = {0.};
	for(int i=0;i<12;i++)
	{
		ALICE >> aliceXL[i] >> aliceYL[i] >> aliceXH[i] >> aliceYH[i];
		aliceX[i] = 0.5*(aliceXH[i]+aliceXL[i]);
		aliceY[i] = 0.5*(aliceYH[i]+aliceYL[i])*7930/596.1;
		aliceerr[i] = 0.5*(aliceYH[i]-aliceYL[i])*7930/596.1;
		cout << aliceY[i] << endl;
	}
	TGraphErrors *Talice = new TGraphErrors(6,aliceX,aliceY,aliceXerr,aliceerr);
	//PHENIX result one
	ifstream ph1("../3_Result/PHENIXy035.csv");
	double p1X[4], p1Y[4], p1Xll[4], p1Xl[4], p1Xh[4], p1Xhh[4], p1Yll[4], p1Yl[4], p1Yh[4], p1Yhh[4];
	double p1Xerr1[4] = {0.};
	double p1Yerr1[4];
	double p1Xerr2[4] = {0.1,0.1,0.1,0.1};
	double p1Yerr2[4];
	for(int i=0;i<4;i++)
	{
		ph1 >> p1Xll[i] >> p1Yll[i] >> p1Xl[i] >> p1Yl[i] >> p1Xh[i] >> p1Yh[i] >> p1Xhh[i] >> p1Yhh[i];
		p1Yerr1[i] = 0.5*(p1Yhh[i]-p1Yll[i]);
		p1Yerr2[i] = 0.5*(p1Yh[i]-p1Yl[i]);
		p1X[i] = 0.25*(p1Xll[i]+p1Xl[i]+p1Xh[i]+p1Xhh[i]);
		p1Y[i] = 0.25*(p1Yll[i]+p1Yl[i]+p1Yh[i]+p1Yhh[i]);
	}
	TGraphErrors *p1Line = new TGraphErrors(4,p1X,p1Y,p1Xerr1,p1Yerr1);
	TGraphErrors *p1Fill = new TGraphErrors(4,p1X,p1Y,p1Xerr2,p1Yerr2);
	//PHENIX result two
	ifstream ph2("../3_Result/PHENIXotherY.csv");
	double p2X[5], p2Y[5], p2Xll[5], p2Xl[5], p2Xh[5], p2Xhh[5], p2Yll[5], p2Yl[5], p2Yh[5], p2Yhh[5];
	double p2Xerr1[5] = {0.};
	double p2Yerr1[5];
	double p2Xerr2[5] = {0.1,0.1,0.1,0.1,0.1};
	double p2Yerr2[5];
	for(int i=0;i<5;i++)
	{
		ph2 >> p2Xll[i] >> p2Yll[i] >> p2Xl[i] >> p2Yl[i] >> p2Xh[i] >> p2Yh[i] >> p2Xhh[i] >> p2Yhh[i];
		p2Yerr1[i] = 0.5*(p2Yhh[i]-p2Yll[i]);
		p2Yerr2[i] = 0.5*(p2Yh[i]-p2Yl[i]);
		p2X[i] = 0.25*(p2Xll[i]+p2Xl[i]+p2Xh[i]+p2Xhh[i]);
		p2Y[i] = 0.25*(p2Yll[i]+p2Yl[i]+p2Yh[i]+p2Yhh[i]);
	}
	TGraphErrors *p2Line = new TGraphErrors(5,p2X,p2Y,p2Xerr1,p2Yerr1);
	TGraphErrors *p2Fill = new TGraphErrors(5,p2X,p2Y,p2Xerr2,p2Yerr2);
	//Plot
	setLHCbStyle();
	TCanvas *can = new TCanvas("can","can",1200,800);
	TMultiGraph *mg = new TMultiGraph();
	mg -> SetTitle(";#font[12]{p}_{T} [GeV/c];B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
	Tcem -> SetFillColor(kGreen-3);
	Tcem -> SetFillStyle(3244);
        Tcem1 -> SetFillColor(kBlue-3);
        Tcem1 -> SetFillStyle(3244);
	Te789 -> SetMarkerColor(5);
	Te789 -> SetLineColor(5);
	Te789 -> SetMarkerStyle(21);
	Te789 -> SetMarkerSize(1.1);
	Thera -> SetMarkerColor(6);
	Thera -> SetLineColor(6);
	Thera -> SetMarkerStyle(22);
	Thera  -> SetMarkerSize(1.1);
	Tlhcb -> SetMarkerColor(7);
	Tlhcb -> SetLineColor(7);
	Tlhcb -> SetMarkerStyle(23);
	Tlhcb -> SetMarkerSize(1.1);
	Tcdf -> SetMarkerColor(kGreen+3);
	Tcdf -> SetLineColor(kGreen+3);
	Tcdf -> SetMarkerStyle(26);
	Tcdf -> SetMarkerSize(1.1);
	//
	Tcms -> SetMarkerColor(kBlue+3);
	Tcms -> SetLineColor(kBlue+3);
	Tcms -> SetMarkerStyle(29);
	Tcms -> SetMarkerSize(1.1);
	Talice -> SetMarkerColor(46);
	Talice -> SetLineColor(46);
	Talice -> SetMarkerStyle(32);
	Talice -> SetMarkerSize(1.1);

	//
	p1Line -> SetMarkerColor(kBlue);
	p1Line -> SetLineColor(kBlue);
	p1Line -> SetMarkerStyle(20);
	p1Line -> SetMarkerSize(1.1);
	p1Fill -> SetFillColorAlpha(kBlue,0.25);
	p2Line -> SetMarkerColor(kOrange);
	p2Line -> SetLineColor(kOrange);
	p2Line -> SetMarkerStyle(20);
	p2Line -> SetMarkerSize(1.1);
	p2Fill -> SetFillColorAlpha(kOrange,0.25);
	Tmy1 -> SetMarkerColor(kRed);
	Tmy1 -> SetLineColor(kRed);
	Tmy1 -> SetMarkerStyle(21);
	Tmy1 -> SetMarkerSize(0.6);
	Tmy2 -> SetFillColorAlpha(kBlack,0.5);
		
	Tcem -> 	GetXaxis() -> SetLimits(0,14);
 	Tcem1 -> 	GetXaxis() -> SetLimits(0,14);
	Thera -> 	GetXaxis() -> SetLimits(0,14);
	Tlhcb -> 	GetXaxis() -> SetLimits(0,14);
	Tcdf -> 	GetXaxis() -> SetLimits(0,14);
	Te789 ->	GetXaxis() -> SetLimits(0,14);
	p1Line -> 	GetXaxis() -> SetLimits(0,14);
	p1Fill -> 	GetXaxis() -> SetLimits(0,14);
	p2Line -> 	GetXaxis() -> SetLimits(0,14);
	p2Fill -> 	GetXaxis() -> SetLimits(0,14);
	Tmy1 -> 	GetXaxis() -> SetLimits(0,14);
	Tmy2 -> 	GetXaxis() -> SetLimits(0,14);
	Talice ->  	GetXaxis() -> SetLimits(0,14);
	Tcms ->  	GetXaxis() -> SetLimits(0,14);
	Tcem ->         SetMinimum(0);
        Tcem1 ->        SetMinimum(0);
        Thera ->        SetMinimum(0);
        Tlhcb ->        SetMinimum(0);
        Tcdf ->         SetMinimum(0);
        Te789 ->        SetMinimum(0);
        p1Line ->       SetMinimum(0);
        p1Fill ->       SetMinimum(0);
        p2Line ->       SetMinimum(0);
        p2Fill ->       SetMinimum(0);
        Tmy1 ->         SetMinimum(0);
        Tmy2 ->         SetMinimum(0);
	Talice  ->      SetMinimum(0);
	Tcms ->         SetMinimum(0);
	Talice  ->      SetMaximum(10);
	Tcms ->         SetMaximum(10);
	Tcem ->         SetMaximum(10);
        Tcem1 ->        SetMaximum(10);
        Thera ->        SetMaximum(10);
        Tlhcb ->        SetMaximum(10);
        Tcdf ->         SetMaximum(10);
        Te789 ->        SetMaximum(10);
        p1Line ->       SetMaximum(10);
        p1Fill ->       SetMaximum(10);
        p2Line ->       SetMaximum(10);
        p2Fill ->       SetMaximum(10);
        Tmy1 ->         SetMaximum(10);
        Tmy2 ->         SetMaximum(10);
	
	Tmy2 -> GetXaxis() -> SetTitle("#font[12]{p}_{T} [GeV/c]");
	Tmy2 -> GetYaxis() -> SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
	Tcem -> GetXaxis() -> SetTitle("#font[12]{p}_{T} [GeV/c]");
        Tcem -> GetYaxis() -> SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
	Tcem1 -> GetXaxis() -> SetTitle("#font[12]{p}_{T} [GeV/c]");
        Tcem1 -> GetYaxis() -> SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
	Thera -> GetXaxis() -> SetTitle("#font[12]{p}_{T} [GeV/c]");
        Thera -> GetYaxis() -> SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
        Tlhcb -> GetXaxis() -> SetTitle("#font[12]{p}_{T} [GeV/c]");
        Tlhcb -> GetYaxis() -> SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
        Tcdf -> GetXaxis() -> SetTitle("#font[12]{p}_{T} [GeV/c]");
        Tcdf -> GetYaxis() -> SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
	Te789 -> GetXaxis() -> SetTitle("#font[12]{p}_{T} [GeV/c]");
        Te789 -> GetYaxis() -> SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
        p1Line -> GetXaxis() -> SetTitle("#font[12]{p}_{T} [GeV/c]");
        p1Fill -> GetYaxis() -> SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
        p2Line -> GetXaxis() -> SetTitle("#font[12]{p}_{T} [GeV/c]");
        p2Fill -> GetYaxis() -> SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");	

	mg -> Add(Tcem);
        mg -> Add(Tcem1);
	//mg -> Add(Te789, "P");
	mg -> Add(Thera, "P");
	mg -> Add(Tlhcb, "P");
	mg -> Add(Tcms, "P");
	mg -> Add(Talice, "P");
	mg -> Add(Tcdf, "P");
	//mg -> Add(p1Line, "P");
	//mg -> Add(p1Fill, "E2");
	//mg -> Add(p2Line, "P");
	//mg -> Add(p2Fill, "E2");
	mg -> Add(Tmy1, "P");
	//mg -> Add(Tmy2, "E2");
	mg -> GetXaxis() -> SetLimits(0,14);
	mg -> SetMaximum(10);
	mg -> SetMinimum(0);
        setLHCbStyle();
	mg -> Draw("a3");


	//legend
	TLegend *leg = new TLegend(0.2,0.65,0.5,0.9);
	leg->SetTextSize(0.032);
	leg->SetTextFont(132);
	leg->SetFillStyle(0);
	//leg -> AddEntry(Te789, "E789, 38.8 GeV p+Au");
	leg -> AddEntry(Tcdf, "CDF 1.8 TeV, p+#bar{p}");
	leg -> AddEntry(Tlhcb, "LHCb 7 TeV p+p (prompt)");
	leg -> AddEntry(Thera, "HERA-B 41.6 GeV p+A");
	leg -> AddEntry(Talice, "ALICE 13 TeV p+p");
	TLegend *rleg = new TLegend(0.51,0.65,0.81,0.9);
	rleg->SetTextSize(0.032);
	rleg->SetTextFont(132);
	rleg->SetFillStyle(0);
	//rleg -> AddEntry(p1Line, "PHENIX 200 GeV p+p, 1.2<|y|<2.2");
	//rleg -> AddEntry(p2Line, "PHENIX 200 GeV p+p, |y|<0.35");
	rleg -> AddEntry(Tcem1, "NLO NRQCD","F");
	rleg -> AddEntry(Tcem, "CGC+NRQCD","F");
	rleg -> AddEntry(Tcms, "CMS 7TeV p+p");
	rleg -> AddEntry(Tmy1, "LHCb 13 TeV p+p, prompt");
	leg -> Draw("same");
	rleg -> Draw("same");
	can -> SaveAs("../4_Plot/Comparisons_PT_VariousMeasurements.pdf");
	can -> SaveAs("../4_Plot/Comparisons_PT_VariousMeasurements.png");
	can -> SaveAs("../4_Plot/Comparisons_PT_VariousMeasurements.eps");
	can -> SaveAs("../4_Plot/Comparisons_PT_VariousMeasurements.C");

	can -> Close();
	return 0;
}
	



