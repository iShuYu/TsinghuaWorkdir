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
#include "./0_header/lhcbStyle.h"
#include <TF1.h>
#include <TLatex.h>
#include <TGraph.h>
using namespace std;
int main(int argc, char* argv[])
{
	setLHCbStyle();
	ifstream input("../4_Result/Ratio/VariousMeasurements.txt");
	double otherX[12];
	double other[12];
	double otherErr[12];
	double zeros[12] = {0.};
	double zero[1] = {0.};
	double myX[1];
       	double my[1];
	double myErr[1];
	double MyX[1];
        double My[1];
        double MyErr[1];
	for(int i=0;i<12;i++){
		input >> otherX[i] >> other[i] >> otherErr[i];
	}
	input >> myX[0] >> my[0] >> myErr[0] >> MyX[0] >> My[0] >> MyErr[0];
	TGraphErrors *To = new TGraphErrors(12,otherX,other,zeros,otherErr);
	TGraphErrors *Tm = new TGraphErrors(1,myX,my,zero,myErr);
	TGraphErrors *TM = new TGraphErrors(1,MyX,My,zero,MyErr);
	TCanvas *can = new TCanvas("can","can",1200,800);
	To -> GetXaxis() -> SetLimits(9,20000);
	To -> GetXaxis() -> SetTitle("#sqrt{S_{NN}}(GeV)");
	To -> GetYaxis() -> SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
	To ->GetHistogram()->SetMaximum(5.);
	To ->GetHistogram()->SetMinimum(0.);
	To -> SetMarkerColor(kBlack);
	To -> SetMarkerSize(1.3);
	Tm -> SetMarkerSize(1);
	Tm -> SetMarkerColor(kRed);
	Tm -> SetLineColor(kRed);
	TM -> SetMarkerSize(1);
        TM -> SetMarkerColor(kMagenta);
        TM -> SetLineColor(kMagenta);
	To -> Draw("AP");
	Tm -> Draw("Psame");
	TM -> Draw("Psame");
	TLegend *leg = new TLegend(0.2,0.8,0.5,0.9);
	leg -> SetTextSize(0.033);
	leg -> AddEntry(Tm, "LHCb p+Pb 8.16TeV, nPVs=1");
        leg -> AddEntry(TM, "LHCb Pb+p 8.16TeV, nPVs=1");
	leg -> Draw("same");
	//TLatex
	TLatex *latex = new TLatex();
	latex -> SetTextSize(0.035);
	latex -> DrawLatex(otherX[0]*0.8,other[0]+otherErr[0]*1.8,"E705");
	latex -> DrawLatex(otherX[0]*0.8,other[0]+otherErr[0]*1.2,"p+Li");
	latex -> DrawLatex(otherX[1]*0.65,other[1]-otherErr[1]*1.4,"NA50/51");
	latex -> DrawLatex(otherX[1]*0.54,other[1]-otherErr[1]*1.9,"p+H,p+d,p+Be");
	latex -> DrawLatex(otherX[4]*0.65,other[4]+otherErr[4]*1.2,"ISR p+p");
	latex -> DrawLatex(otherX[5]*0.54,other[5]-otherErr[5]*1.4,"PHENIX p+p");
	latex -> DrawLatex(otherX[5]*0.7,other[5]-otherErr[5]*1.9,"|y|<0.35");
	latex -> DrawLatex(otherX[6]*0.53,other[6]+otherErr[6]*1.8,"PHENIX p+p");
	latex -> DrawLatex(otherX[6]*0.58,other[6]+otherErr[6]*1.3,"1.2<|y|<2.2");
	latex -> DrawLatex(otherX[7]*0.7,other[7]-otherErr[7]*1.2,"UA1 p+#bar{p}");
	latex -> DrawLatex(otherX[7]*0.65,other[7]-otherErr[7]*1.4,"p_{T}>5GeV/c");
	latex -> DrawLatex(otherX[8]*0.7,other[8]+otherErr[8]*2.3,"CDF p+#bar{p}");
	latex -> DrawLatex(otherX[8]*0.5,other[8]+otherErr[8]*1.7,"p_T>5GeV/c");
	latex -> DrawLatex(otherX[8]*0.5,other[8]+otherErr[8]*1.2,"B#rightarrow#psi removed");
	latex -> DrawLatex(otherX[9]*0.3,other[9]-otherErr[9]*0.5,"ALICE p+p");
	latex -> DrawLatex(otherX[10]*0.5,other[10]+otherErr[10]*1.4,"LHCb p+p");
	latex -> DrawLatex(otherX[10]*0.55,other[10]+otherErr[10]*1.08,"Exclusive");
	//latex -> SetTextColor(kRed);
	latex -> DrawLatex(otherX[11]*0.8, other[11]-otherErr[11]*8,"LHCb");
        latex -> DrawLatex(otherX[11]*0.9, other[11]-otherErr[11]*13,"p+p");
        latex -> DrawLatex(otherX[11]*0.76,other[11]-otherErr[11]*18,"prompt");
        latex -> DrawLatex(otherX[11]*0.76,other[11]-otherErr[11]*23,"nPV=1");	
	can -> SetLogx();
	can -> SaveAs("../5_Plots/Result/VariousMeasurements.pdf");
	can -> Close();
	return 0;
}

