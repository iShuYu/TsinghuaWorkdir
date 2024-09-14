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
	double N = data_set->numEntries();

	RooRealVar psi_mass("psi_M", "psi_M", 3686.0 - 120, 3686.0 + 120);
	RooRealVar tzError("tzError", "tzError", 0.001, 0.3);

	// Plotting
	RooPlot* plot_frame = psi_mass.frame(Bins(100));
	RooAbsData* BinData = (RooAbsData*) data_set->binnedClone();
	data_set->plotOn(plot_frame, Name("data_set"));
	tzPDF->plotOn(plot_frame, Name("tail"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tail"), LineColor(kGreen), LineStyle(5), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, Name("bkg"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("bkg"), LineColor(kViolet), LineStyle(7), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, Name("prompt"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("prompt"), FillColor(kRed), FillStyle(3005), VLines(), DrawOption("F"), LineWidth(0), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, Name("fromb"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("fromb"), FillColor(kBlue), FillStyle(3002), VLines(), DrawOption("F"), LineWidth(0), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, Name("tzPDF"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), LineColor(kBlue), LineStyle(1), Normalization(1.0/N));
	/*BinData->plotOn(plot_frame, Name("BinData"));
        tzPDF->plotOn(plot_frame, Name("prompt"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzDelta"), FillColor(kRed), FillStyle(3002), VLines(), DrawOption("F"), LineWidth(0), Normalization(1.0/N));
        tzPDF->plotOn(plot_frame, Name("bkg"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzbkg_tzPDF"), LineColor(kViolet), LineStyle(7), Normalization(1.0/N));
        tzPDF->plotOn(plot_frame, Name("tail"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzTail"), LineColor(kGreen), LineStyle(5), Normalization(1.0/N));
        tzPDF->plotOn(plot_frame, Name("fromb"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzP"), FillColor(kBlue), FillStyle(3005), VLines(), DrawOption("F"), LineWidth(0), Normalization(1.0/N));
        tzPDF->plotOn(plot_frame, Name("tzPDF"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), LineColor(kBlue), LineStyle(1), Normalization(1.0/N));*/
	data_set->plotOn(plot_frame, Name("data_set"));
	RooHist* hpull = plot_frame->pullHist("data_set", "tzPDF", true);
        RooPlot* plot_pull = psi_mass.frame();
        for (int i=0; i<hpull->GetN(); i++) {
                hpull->SetPointError(i, 0, 0, 0, 0);
        }
        plot_pull->addPlotable(hpull, "LP");
        plot_pull->GetYaxis()->SetTitleSize(0.20);
        plot_pull->GetYaxis()->SetLabelSize(0.20);
        plot_pull->GetYaxis()->SetNdivisions(5, 0, 0);
        plot_pull->GetYaxis()->SetTitle("#Delta/#sigma");
        plot_pull->GetYaxis()->SetTitleOffset(0.23);
        plot_pull->GetYaxis()->SetRangeUser(-5,5);
	TCanvas* cLog = new TCanvas("cLog","cLog", 800, 600);
	cLog->Divide(1,2,0,0,0);
	cLog->cd(2);
        gPad->SetTopMargin(0);
        gPad->SetLeftMargin(0.12);
        gPad->SetRightMargin(0.015);
        gPad->SetPad(0.03,0.02,0.97,0.77);
	plot_frame->SetXTitle("m_{#mu^{#plus}#mu^{#minus}} [MeV/#it{c}^{2}]");
	plot_frame->SetYTitle("Candidates per 2.4 MeV/#it{c}^{2}");
	plot_frame->GetYaxis()->SetTitleOffset(1.01);
	plot_frame->Draw();
	TLegend* leg = new TLegend(0.16, 0.47, 0.43, 0.92);
	leg->SetTextFont(132);
	leg->SetBorderSize(0);
	leg->SetTextSize(0.05);
	leg->SetFillStyle(0);
	leg->SetHeader("Fit for #psi(2S)");
	leg->AddEntry("data_set", "#psi(2S) data", "lep");
        leg->AddEntry("tzPDF", "#psi(2S) total fit", "l");
        leg->AddEntry("prompt", "prompt #psi(2S)", "f");
        leg->AddEntry("fromb", "#psi(2S) from #font[12]{b}", "f");
        leg->AddEntry("tail", "tail", "l");
        leg->AddEntry("bkg", "background", "l");
	/*
	leg->AddEntry("data_set", "data", "lep");
        leg->AddEntry("tzPDF", "total fit function", "l");
        leg->AddEntry("prompt", "prompt J/#psi", "f");
        leg->AddEntry("fromb", "J/#psi from #font[12]{b}", "f");
        leg->AddEntry("tail", "tail", "l");
        leg->AddEntry("bkg", "background", "l");*/
	leg->Draw();
	/*TPaveText* mylhcbName = new TPaveText(gStyle->GetPadLeftMargin() + 0.50, 0.65 - gStyle->GetPadTopMargin(), gStyle->GetPadLeftMargin() + 0.70, 0.95 - gStyle->GetPadTopMargin(), "BRNDC");//0.12
  	mylhcbName->SetFillColor(0);
  	mylhcbName->SetTextAlign(12);
  	mylhcbName->SetTextFont(132);
  	mylhcbName->SetTextSize(0.05);
  	mylhcbName->SetBorderSize(0);
  	mylhcbName->AddText("LHCb");
  	mylhcbName->AddText("#sqrt{#it{s}} = 5 TeV, 9.1 pb^{#minus1}");
  	mylhcbName->AddText(Form("%d < #it{p}#lower[0.5]{#scale[0.7]{T}} < %d GeV/#it{c}", int(pt_low/1000), int(pt_hi/1000)));
  	mylhcbName->AddText(Form("%1.1f < #it{y} < %1.1f", y_low, y_hi));
	mylhcbName->Draw();
	gPad->RedrawAxis();*/

	//plot_output = plot_file_config + "_mass.pdf";
	cLog->cd(1);
        gPad->SetBottomMargin(0);
        gPad->SetLeftMargin(0.12);
        gPad->SetRightMargin(0.015);
        gPad->SetPad(0.03,0.77,0.97,0.97);
        plot_pull->Draw();
	cLog->Print(argv[2]);
	//plot_output = plot_file_config + "_mass.eps";
	//cLog->Print(plot_output.c_str());
	//plot_output = plot_file_config + "_mass.png";
	//cLog->Print(plot_output.c_str());
	//plot_output = plot_file_config + "_mass.C";
	//cLog->Print(plot_output.c_str());

	return 0;
}
