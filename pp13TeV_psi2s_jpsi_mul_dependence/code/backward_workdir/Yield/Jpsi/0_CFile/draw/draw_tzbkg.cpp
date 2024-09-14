// Code to Fit the mass of JPsi
// Author : zhaomr
// Date   : June 4 2015
// Input  : dirData
// Output : dirMass     : fit parameters
//          dirMassPlot : plot
//          dirMassFile : root file

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
#include "../header/lhcbStyle.h"

using namespace std;
using namespace RooFit;

int main(int argc, char* argv[])
{

	//------------------------File-------------------
	setLHCbStyle();
	// Create DecayTree with the data after reconstruction
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
	tzPDF->plotOn(plot_frame, ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzDelta"), FillColor(8), FillStyle(3002), VLines(), DrawOption("F"), Normalization(1.0/N), LineWidth(0));
	tzPDF->plotOn(plot_frame, ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzP1"), LineColor(2), LineStyle(7), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzP2"), LineColor(12), LineStyle(10), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzN"), LineColor(6), LineStyle(9), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzPN"), FillColor(9), FillStyle(3005), VLines(), DrawOption("F"),  Normalization(1.0/N));
	//tzPDF->plotOn(plot_frame, ProjWData(tzError, *data_set), NumCPU(40, kTRUE), Components("tzP3"), LineColor(1), LineStyle(2), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, Name("tzPDF"), ProjWData(tzError, *data_set), NumCPU(40, kTRUE), LineColor(4), LineStyle(1), Normalization(1.0/N));
	data_set->plotOn(plot_frame, Name("data_set"));

	RooHist* hpull = plot_frame->pullHist("data_set", "tzPDF", true);
	RooPlot* plot_pull = tz.frame();
	//hpull -> SetDrawOption("BAR");
	for (int i=0; i<hpull->GetN(); i++)
	{
		hpull->SetPointError(i, 0, 0, 0, 0);
	}
	plot_pull->addPlotable(hpull, "LP");
	//plot_pull->SetTitle("");
	plot_pull->GetYaxis()->SetTitleSize(0.20);
	plot_pull->GetYaxis()->SetLabelSize(0.20);
	plot_pull->GetYaxis()->SetNdivisions(5, 0, 0);
	plot_pull->GetYaxis()->SetTitle("#Delta/#sigma");
	plot_pull->GetYaxis()->SetTitleOffset(0.23);
	plot_pull->GetYaxis()->SetRangeUser(-5,5);
	//plot_pull->GetYaxis()->CenterTitle();

	gROOT->SetBatch(true);
	TCanvas* cLog = new TCanvas("cLog","cLog", 800, 600);
	cLog->Divide(1,2,0,0,0);
	cLog->cd(2);
	gPad->SetLogy();
	gPad->SetTopMargin(0);
	gPad->SetLeftMargin(0.12);
	gPad->SetPad(0.03,0.02,0.97,0.77);
	plot_frame->SetMinimum(0.5);
	plot_frame->SetXTitle("#font[12]{t}_{z}[ps]");
	plot_frame->SetYTitle("Candidates per 0.2ps");
	plot_frame->Draw();
	TLegend* leg = new TLegend(0.65, 0.65, 0.9, 0.85);
	leg->SetTextFont(132);
	leg->SetBorderSize(0);
	leg->SetTextSize(0.06);
	leg->AddEntry("data_set", "data", "lep");
	leg->AddEntry("tzPDF", "total fit function", "l");
	leg->Draw();
  //	lhcbName->AddText(Form("%d < #font[12]{p}_{T} < %dGeV/#font[12]{c}", int(pt_low/1000), int(pt_hi/1000)));
//  	lhcbName->AddText(Form("%1.1f < #font[12]{y} < %1.1f", y_low, y_hi));
	lhcbName->Draw();


	cLog->cd(1);
	gPad->SetBottomMargin(0);
	gPad->SetLeftMargin(0.12);
	gPad->SetPad(0.03,0.77,0.97,0.97);
	plot_pull->Draw();

	cLog->Print(argv[2]);
/*
	gROOT->Reset();
	gROOT->SetBatch(true);
	TCanvas* cPol = new TCanvas("cPol","cPol");
	cPol->Divide(1,2,0,0,0);

	cPol->cd(2);
	gPad->SetTopMargin(0);
	gPad->SetLeftMargin(0.12);
	gPad->SetPad(0.03,0.02,0.97,0.77);
	plot_frame->SetMinimum(0.5);
	plot_frame->Draw();

	cPol->cd(1);
	gPad->SetBottomMargin(0);
	gPad->SetLeftMargin(0.12);
	gPad->SetPad(0.03,0.77,0.97,0.97);
	plot_pull->Draw();

	plot_output = plot_file_config + ".pdf";
	cPol->Print(plot_output.c_str());
	plot_output = plot_file_config + ".eps";
	cPol->Print(plot_output.c_str());
	plot_output = plot_file_config + ".png";
	cPol->Print(plot_output.c_str());
*/
	return 0;
}
