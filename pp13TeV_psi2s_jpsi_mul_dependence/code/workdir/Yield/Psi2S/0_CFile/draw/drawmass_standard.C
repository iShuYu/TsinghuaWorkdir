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
	data_set->plotOn(plot_frame, Name("data_set"));
	RooHist* hpull = plot_frame->pullHist("data_set", "tzPDF", true);
	TCanvas* cLog = new TCanvas("cLog","cLog", 800, 600);
	plot_frame->SetXTitle("#font[12]{m}_{#mu^{#plus}#mu^{#minus}} [MeV/#it{c}^{2}]");
	plot_frame->SetYTitle("Candidates / (2.4 MeV/#it{c}^{2})");
	plot_frame->GetYaxis()->SetTitleOffset(1.0);
	plot_frame->Draw();
	TLegend* leg = new TLegend(0.20, 0.47, 0.43, 0.92);
	leg->SetTextFont(132);
	leg->SetBorderSize(0);
	leg->SetTextSize(0.05);
	leg->SetFillStyle(0);
	leg->SetHeader("Fit for #psi(2S)");
	leg->AddEntry("data_set", "data", "lep");
        leg->AddEntry("tzPDF", "total fit", "l");
        leg->AddEntry("prompt", "prompt", "f");
        leg->AddEntry("fromb", "non-prompt", "f");
        leg->AddEntry("tail", "wrong PV", "l");
        leg->AddEntry("bkg", "background", "l");
	leg->Draw("same");
	lhcbName->Draw();
	cLog->Print(argv[2]);

	return 0;
}
