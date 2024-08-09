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
	double N = data_set->numEntries();
	RooRealVar tz("tz", "tz", -10, 10);
	RooRealVar tzError("tzError", "tzError", 0.001, 0.3);
	RooPlot* plot_frame = tz.frame(Bins(100));
	RooAbsData *BinData = (RooAbsData*)data_set->binnedClone();
	data_set->plotOn(plot_frame, Name("data_set"));
	tzPDF->plotOn(plot_frame, Name("prompt"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzDelta"), FillColor(kRed), FillStyle(3002), VLines(), DrawOption("F"), LineWidth(0), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, Name("bkg"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzbkg_tzPDF"), LineColor(kViolet), LineStyle(7), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, Name("fromb"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("tzP"), FillColor(kBlue), FillStyle(3005), VLines(), DrawOption("F"), LineWidth(0), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, Name("tzPDF"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), LineColor(kBlue), LineStyle(1), Normalization(1.0/N));
	data_set->plotOn(plot_frame, Name("data_set"));
	RooHist* hpull = plot_frame->pullHist("data_set", "tzPDF", true);
	RooPlot* plot_pull = tz.frame();
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
	TLegend* leg = new TLegend(0.16, 0.47, 0.43, 0.92);
	leg->SetTextFont(132);
	leg->SetBorderSize(0);
	leg->SetTextSize(0.05);
	leg->SetHeader("Fit for J/#psi");
	leg->AddEntry("data_set", "J/#psi data", "lep");
	leg->AddEntry("tzPDF", "J/#psi total fit", "l");
	leg->AddEntry("prompt", "prompt", "f");
	leg->AddEntry("fromb", "non-prompt", "f");
	leg->AddEntry("bkg", "background", "l");
	leg->Draw();
	cLog->cd(1);
	gPad->SetBottomMargin(0);
	gPad->SetLeftMargin(0.12);
	gPad->SetRightMargin(0.015);
	gPad->SetPad(0.03,0.77,0.97,0.97);
	plot_pull->Draw();
	cLog->Print(argv[2]);


	TFile input_fileP(argv[3]);
        RooDataSet* data_setP = (RooDataSet*)input_fileP.Get("data_setP");
        RooAddPdf* tzPDFP = (RooAddPdf*)input_fileP.Get("tzPDFP");
        double NP = data_setP->numEntries();	
        RooPlot* plot_frameP = tz.frame(Bins(100));
        RooAbsData *BinDataP = (RooAbsData*)data_setP->binnedClone();
        data_setP->plotOn(plot_frameP, Name("data_setP"));
        tzPDFP->plotOn(plot_frameP, Name("promptP"), ProjWData(tzError, *BinDataP), NumCPU(40, kTRUE), Components("tzDelta"), FillColor(kRed), FillStyle(3002), VLines(), DrawOption("F"), LineWidth(0), Normalization(1.0/NP));
        tzPDFP->plotOn(plot_frameP, Name("bkgP"), ProjWData(tzError, *BinDataP), NumCPU(40, kTRUE), Components("tzbkg_tzPDF"), LineColor(kViolet), LineStyle(7), Normalization(1.0/NP));
        tzPDFP->plotOn(plot_frameP, Name("frombP"), ProjWData(tzError, *BinDataP), NumCPU(40, kTRUE), Components("tzP"), FillColor(kBlue), FillStyle(3005), VLines(), DrawOption("F"), LineWidth(0), Normalization(1.0/NP));
        tzPDFP->plotOn(plot_frameP, Name("tzPDFP"), ProjWData(tzError, *BinDataP), NumCPU(40, kTRUE), LineColor(kBlue), LineStyle(1), Normalization(1.0/NP));
        RooHist* hpullP = plot_frameP->pullHist("data_setP", "tzPDFP", true);
        RooPlot* plot_pullP = tz.frame();
	 for (int i=0; i<hpullP->GetN(); i++) {
                hpullP->SetPointError(i, 0, 0, 0, 0);
        }
        plot_pullP->addPlotable(hpullP, "LP");
        plot_pullP->GetYaxis()->SetTitleSize(0.20);
        plot_pullP->GetYaxis()->SetLabelSize(0.20);
        plot_pullP->GetYaxis()->SetNdivisions(5, 0, 0);
        plot_pullP->GetYaxis()->SetTitle("#Delta/#sigma");
        plot_pullP->GetYaxis()->SetTitleOffset(0.23);
        plot_pullP->GetYaxis()->SetRangeUser(-5,5);

        gROOT->SetBatch(true);
        TCanvas* cLog1 = new TCanvas("cLog1","cLog1", 800, 600);
        cLog1->Divide(1,2,0,0,0);
        cLog1->cd(2);
        gPad->SetLogy();
        gPad->SetTopMargin(0);
        gPad->SetLeftMargin(0.12);
        gPad->SetRightMargin(0.015);
        gPad->SetPad(0.03,0.02,0.97,0.77);
        plot_frameP->SetMinimum(0.5);
        plot_frameP->SetXTitle("#font[12]{t}_{z}[ps]");
        plot_frameP->SetYTitle("Candidates per 0.2ps");
        plot_frameP->Draw();
        TLegend* legP = new TLegend(0.16, 0.47, 0.43, 0.92);
        legP->SetTextFont(132);
        legP->SetBorderSize(0);
        legP->SetTextSize(0.05);
        legP->SetHeader("Fit for #psi(2S)");
        legP->AddEntry("data_setP", "#psi(2S) data", "lep");
        legP->AddEntry("tzPDFP", "#psi(2S) total fit", "l");
        legP->AddEntry("promptP", "prompt", "f");
	legP->AddEntry("frombP", "non-prompt", "f");
        legP->AddEntry("bkgP", "background", "l");
        legP->Draw();
        //lhcbName->Draw();
        cLog1->cd(1);
        gPad->SetBottomMargin(0);
        gPad->SetLeftMargin(0.12);
        gPad->SetRightMargin(0.015);
        gPad->SetPad(0.03,0.77,0.97,0.97);
        plot_pullP->Draw();
        cLog1->Print(argv[4]);

	return 0;
}
