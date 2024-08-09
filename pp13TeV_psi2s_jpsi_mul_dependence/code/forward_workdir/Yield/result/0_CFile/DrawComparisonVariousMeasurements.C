#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TAxis.h>
#include <TMultiGraph.h>
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
	ifstream input("../3_Result/VariousMeasurements.txt");
	double otherX[10];
	double other[10];
	double otherErr[10];
	double zeros[10] = {0.};
	double twozero[2] = {0.};
	double zero[1] = {0.};
	double myX[1];
       	double my[1];
	double myErr[1];
	for(int i=0;i<10;i++){
		input >> otherX[i] >> other[i] >> otherErr[i];
	}
	input >> myX[0] >> my[0] >> myErr[0];
	double myXArea[2] = {9,28000};
	double myArea[2] = {my[0],my[0]};
	double myAreah[2] = {myErr[0], myErr[0]};
	double myAreal[2] = {myErr[0], myErr[0]};
	

	TGraphErrors *To = new TGraphErrors(10,otherX,other,zeros,otherErr);
	TGraphErrors *Tm = new TGraphErrors(1,myX,my,zero,myErr);
	//TGraphAsymmErrors *Tm_area = new TGraphAsymmErrors(2, myXArea, myArea,twozero, twozero,myAreal,myAreah);
	TGraphErrors *Tm_area = new TGraphErrors(2, myXArea,myArea,twozero,myAreah);
	TCanvas *can = new TCanvas("can","can",1000,800);
	To -> GetXaxis() -> SetLimits(9, 28000);
	To -> GetXaxis()-> SetTitleOffset(1.2);
	To -> GetXaxis() -> SetTitle("#sqrt{S_{NN}}  [GeV]");
	To -> GetYaxis() -> SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
	To -> SetMaximum(5.);
	To -> SetMinimum(0.);
	
	Tm_area -> GetXaxis() -> SetLimits(9, 28000);
	Tm_area -> GetXaxis() -> SetTitleOffset(1.2);
	Tm_area -> GetXaxis() -> SetTitle("#sqrt{S_{NN}}  [GeV]");
	Tm_area -> GetYaxis() -> SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
	Tm_area -> SetMaximum(5.);
	Tm_area -> SetMinimum(0.);
	
	Tm -> GetXaxis() -> SetLimits(9, 28000);
	Tm -> GetXaxis() -> SetTitleOffset(1.2);
	Tm -> GetXaxis() -> SetTitle("#sqrt{S_{NN}}  [GeV]");
	Tm -> GetYaxis() -> SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
	Tm -> SetMaximum(5.);
	Tm -> SetMinimum(0.);

	To -> SetMarkerColor(kBlack);
	To -> SetMarkerSize(1.3);
	Tm -> SetMarkerColor(kRed);
	Tm -> SetLineColor(kRed);
	Tm -> SetMarkerSize(0.5);
	Tm_area -> SetFillColor(kRed);
	Tm_area -> SetFillStyle(3005);
	
	TMultiGraph *mg = new TMultiGraph();
	mg -> GetXaxis() -> SetLimits(9, 28000);
	mg -> SetMaximum(5.);
	mg -> SetMinimum(0.);
	mg -> GetXaxis() -> SetTitle("#sqrt{S_{NN}}  [GeV]");
	mg -> GetYaxis() -> SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
	mg -> Add(To, "AP");
	mg -> Add(Tm, "AP");
	mg -> Add(Tm_area);
	mg -> Draw("a3");

	//TLatex
	TLatex *latex = new TLatex();
	latex -> SetTextSize(0.035);
	latex -> DrawLatex(otherX[0]*0.6,other[0]+otherErr[0]*1.8,"E705");
	latex -> DrawLatex(otherX[0]*0.6,other[0]+otherErr[0]*1.2,"p+Li");
	latex -> DrawLatex(otherX[1]*0.7,other[1]-otherErr[1]*1.4,"NA50/51");
	latex -> DrawLatex(otherX[1]*0.6,other[1]-otherErr[1]*1.9,"p+H,p+d,p+Be");
	latex -> DrawLatex(otherX[2]*0.65,other[2]+otherErr[2]*1.2,"ISR p+p");
	latex -> DrawLatex(otherX[3]*0.54,other[3]-otherErr[3]*1.4,"PHENIX p+p");
	latex -> DrawLatex(otherX[3]*0.7,other[3]-otherErr[3]*1.9,"|y|<0.35");
	latex -> DrawLatex(otherX[4]*0.53,other[4]+otherErr[4]*1.8,"PHENIX p+p");
	latex -> DrawLatex(otherX[4]*0.58,other[4]+otherErr[4]*1.3,"1.2<|y|<2.2");
	latex -> DrawLatex(otherX[5]*0.9,other[5]-otherErr[5]*1.2,"UA1 p+#bar{p}");
	latex -> DrawLatex(otherX[5]*0.9,other[5]-otherErr[5]*1.4,"p_{T}>5GeV/c");
	latex -> DrawLatex(otherX[6]*0.7,other[6]+otherErr[6]*2.6,"CDF p+#bar{p}");
	latex -> DrawLatex(otherX[6]*0.5,other[6]+otherErr[6]*2,"p_{T}>5GeV/c");
	latex -> DrawLatex(otherX[6]*0.5,other[6]+otherErr[6]*1.4,"B#rightarrow#psi removed");
	latex -> DrawLatex(otherX[7]*0.6,other[7]-otherErr[7]*1.5,"ALICE p+p");
	latex -> DrawLatex(otherX[8]*0.5,other[8]+otherErr[8]*1.42,"LHCb p+p");
	latex -> DrawLatex(otherX[8]*0.55,other[8]+otherErr[8]*1.08,"Exclusive");
	latex -> DrawLatex(otherX[9]*0.66,other[9]+otherErr[9]*1.65,"LHCb p+p");
        latex -> DrawLatex(otherX[9]*0.69,other[9]+otherErr[9]*1.1,"Exclusive");
	latex -> SetTextColor(kRed);
	/*latex -> DrawLatex(myX[0]*0.8,my[0]-myErr[0]*10,"LHCb");
	latex -> DrawLatex(myX[0]*0.9,my[0]-myErr[0]*17,"p+p");
	latex -> DrawLatex(myX[0]*0.76,my[0]-myErr[0]*22,"prompt");
	latex -> DrawLatex(myX[0]*0.76,my[0]-myErr[0]*27,"nPV=1");*/
	can -> SetLogx();

	TLegend *leg = new TLegend(0.2,0.75,0.45,0.9);
	leg->SetTextSize(0.032);
	leg->SetTextFont(132);
	leg->SetFillStyle(0);
	leg -> AddEntry(Tm_area,"LHCb 13 TeV #font[12]{pp} prompt","F");
	leg -> AddEntry(To, "other measurements");
	leg -> Draw("same");
	can -> SaveAs("../4_Plot/VariousMeasurements.pdf");
	can -> SaveAs("../4_Plot/VariousMeasurements.png");
	can -> SaveAs("../4_Plot/VariousMeasurements.eps");
	can -> SaveAs("../4_Plot/VariousMeasurements.C");
	can -> Close();
	return 0;
}

