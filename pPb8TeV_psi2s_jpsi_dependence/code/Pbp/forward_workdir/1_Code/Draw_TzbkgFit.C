#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>
#include <TStyle.h>
#include <TSystem.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <RooFit.h>
#include <RooPlot.h>
#include <RooHist.h>
#include <RooHistPdf.h>
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooGaussModel.h>
#include <RooAddModel.h>
#include <RooAddPdf.h>
#include <RooDecay.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "0_header/lhcbStyle.h"

using namespace std;
using namespace RooFit;

int main(int argc, char* argv[])
{

	setLHCbStyle();
	TFile input_file(argv[1]);
	RooDataSet* data_set = (RooDataSet*)input_file.Get("data_set");
	RooAddPdf* tzPDF = (RooAddPdf*)input_file.Get("tzPDF");
	double N = data_set->sumEntries();
	RooRealVar tz("tz", "tz", -10, 10);
	RooRealVar tzError("tzError", "tzError", 0.001, 0.3);
	// Plotting
	RooPlot* plot_frame = tz.frame(Bins(100));
	RooAbsData *BinData = (RooAbsData*)data_set->binnedClone();
	data_set->plotOn(plot_frame, Name("data_set"));
	tzPDF->plotOn(plot_frame, Name("tzDelta"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzDelta"), FillColor(8), FillStyle(3002), VLines(), DrawOption("F"), Normalization(1.0/N), LineWidth(0));
	tzPDF->plotOn(plot_frame, Name("tzP1"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzP1"), LineColor(2), LineStyle(7), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, Name("tzP2"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzP2"), LineColor(12), LineStyle(10), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, Name("tzN"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzN"), LineColor(6), LineStyle(9), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, Name("tzPN"),ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzPN"), FillColor(9), FillStyle(3005), VLines(), DrawOption("F"),  Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, Name("tzPDF"), ProjWData(tzError, *data_set), NumCPU(40, kTRUE), LineColor(4), LineStyle(1), Normalization(1.0/N));	
	RooHist* hpull = plot_frame->pullHist("data_set", "tzPDF", true);
	RooPlot* plot_pull = tz.frame();
	for (int i=0; i<hpull->GetN(); i++)
	{
		hpull->SetPointError(i, 0, 0, 0, 0);
	}
	plot_pull->addPlotable(hpull, "LP");
	plot_pull->GetYaxis()->SetTitleSize(0.20);
	plot_pull->GetYaxis()->SetLabelSize(0.20);
	plot_pull->GetYaxis()->SetNdivisions(5, 0, 0);
	plot_pull->GetYaxis()->SetTitle("#Delta/#sigma");
	plot_pull->GetYaxis()->SetTitleOffset(0.23);
	plot_pull->GetYaxis()->SetRangeUser(-5,5);

	gROOT->SetBatch(true);
	TCanvas* cLog = new TCanvas("cLog","cLog", 800, 600);
	cLog->Divide(1,2,0,0,0);
	cLog->cd(2);
	gPad->SetLogy();
	gPad->SetTopMargin(0);
	gPad->SetLeftMargin(0.12);
	gPad->SetRightMargin(0.015);
	gPad->SetPad(0.03,0.02,0.97,0.77);
	plot_frame->SetMinimum(0.5);
	plot_frame->SetXTitle("#font[12]{t}_{z}[ps]");
	plot_frame->SetYTitle("Candidates per 0.2ps");
	plot_frame->Draw();
	TLegend* leg = new TLegend(0.65, 0.65, 0.9, 0.95);
	leg->SetTextFont(132);
	leg->SetBorderSize(0);
	leg->SetTextSize(0.06);
	leg->AddEntry("data_set", "data", "lep");
	leg->AddEntry("tzPDF", "total fit function", "l");
	leg->AddEntry("tzDelta","delta function","f");
	leg->AddEntry("tzP1","positive decay 1");
	leg->AddEntry("tzP2","positive decay 2");
	leg->AddEntry("tzPN"," double-sided decay","f");
	leg->AddEntry("tzN","negative decay");
	leg->Draw();
	lhcbName->Draw();
	cLog->cd(1);
	gPad->SetBottomMargin(0);
	gPad->SetLeftMargin(0.12);
	gPad->SetRightMargin(0.015);
	gPad->SetPad(0.03,0.77,0.97,0.97);
	plot_pull->Draw();
	cLog->Print(argv[2]);
	return 0;
}
