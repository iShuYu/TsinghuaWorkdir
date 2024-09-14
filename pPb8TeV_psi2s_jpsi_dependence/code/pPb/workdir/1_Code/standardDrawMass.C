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

	RooRealVar psi_mass("psi_M", "psi_M", 3096.9 - 120, 3096.9 + 120);
	RooRealVar tzError("tzError", "tzError", 0.001, 0.3);
	RooPlot* plot_frame = psi_mass.frame(Bins(100));
	RooAbsData* BinData = (RooAbsData*) data_set->binnedClone();
	data_set->plotOn(plot_frame, Name("data_set"));
	tzPDF->plotOn(plot_frame, Name("bkg"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("bkg"), LineColor(kViolet), LineStyle(7), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, Name("prompt"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("prompt"), FillColor(kRed), FillStyle(3005), VLines(), DrawOption("F"), LineWidth(0), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, Name("fromb"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), Components("fromb"), FillColor(kBlue), FillStyle(3002), VLines(), DrawOption("F"), LineWidth(0), Normalization(1.0/N));
	tzPDF->plotOn(plot_frame, Name("tzPDF"), ProjWData(tzError, *BinData), NumCPU(40, kTRUE), LineColor(kBlue), LineStyle(1), Normalization(1.0/N));
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
	//cLog->Divide(1,2,0,0,0);
	//cLog->cd(2);
        gPad->SetTopMargin(0);
        gPad->SetLeftMargin(0.12);
        gPad->SetRightMargin(0.015);
        gPad->SetPad(0.03,0.02,0.97,0.97);
	plot_frame->SetXTitle("m_{#mu^{#plus}#mu^{#minus}} [MeV/#it{c}^{2}]");
	plot_frame->SetYTitle("Candidates per 2.4 MeV/#it{c}^{2}");
	plot_frame->GetYaxis()->SetTitleOffset(1.01);
	plot_frame->Draw();
	TLegend* leg = new TLegend(0.16, 0.47, 0.43, 0.92);
	leg->SetTextFont(132);
	leg->SetBorderSize(0);
	leg->SetTextSize(0.05);
	leg->SetFillStyle(0);
	leg->SetHeader("Fit for J/#psi");
	leg->AddEntry("data_set", "data", "lep");
        leg->AddEntry("tzPDF", "total fit", "l");
        leg->AddEntry("prompt", "prompt", "f");
        leg->AddEntry("fromb", "non-prompt", "f");
        leg->AddEntry("bkg", "background", "l");
	leg->Draw("same");
	/*cLog->cd(1);
        gPad->SetBottomMargin(0);
        gPad->SetLeftMargin(0.12);
        gPad->SetRightMargin(0.015);
        gPad->SetPad(0.03,0.77,0.97,0.97);
        plot_pull->Draw();*/
	cLog->Print(argv[2]);
	TFile input_fileP(argv[3]);
        RooDataSet* data_setP = (RooDataSet*)input_fileP.Get("data_setP");
        RooAddPdf* tzPDFP = (RooAddPdf*)input_fileP.Get("tzPDFP");
        double NP = data_setP->numEntries();

        RooRealVar psi_massP("psi_M", "psi_M", 3686.09 - 120, 3686.09 + 120);
        RooPlot* plot_frameP = psi_massP.frame(Bins(100));
        RooAbsData* BinDataP = (RooAbsData*) data_setP->binnedClone();
        data_setP->plotOn(plot_frameP, Name("data_setP"));
        tzPDFP->plotOn(plot_frameP, Name("bkgP"), ProjWData(tzError, *BinDataP), NumCPU(40, kTRUE), Components("bkgP"), LineColor(kViolet), LineStyle(7), Normalization(1.0/NP));
        tzPDFP->plotOn(plot_frameP, Name("promptP"), ProjWData(tzError, *BinDataP), NumCPU(40, kTRUE), Components("promptP"), FillColor(kRed), FillStyle(3005), VLines(), DrawOption("F"), LineWidth(0), Normalization(1.0/NP));
        tzPDFP->plotOn(plot_frameP, Name("frombP"), ProjWData(tzError, *BinDataP), NumCPU(40, kTRUE), Components("frombP"), FillColor(kBlue), FillStyle(3002), VLines(), DrawOption("F"), LineWidth(0), Normalization(1.0/NP));
        tzPDFP->plotOn(plot_frameP, Name("tzPDFP"), ProjWData(tzError, *BinDataP), NumCPU(40, kTRUE), LineColor(kBlue), LineStyle(1), Normalization(1.0/NP));
        data_setP->plotOn(plot_frameP, Name("data_setP"));
        /*RooHist* hpullP = plot_frameP->pullHist("data_setP", "tzPDFP", true);
        RooPlot* plot_pullP = psi_massP.frame();
	for (int i=0; i<hpullP->GetN(); i++) {
                hpullP->SetPointError(i, 0, 0, 0, 0);
        }
        plot_pullP->addPlotable(hpullP, "LP");
        plot_pullP->GetYaxis()->SetTitleSize(0.20);
        plot_pullP->GetYaxis()->SetLabelSize(0.20);
        plot_pullP->GetYaxis()->SetNdivisions(5, 0, 0);
        plot_pullP->GetYaxis()->SetTitle("#Delta/#sigma");
        plot_pullP->GetYaxis()->SetTitleOffset(0.23);
        plot_pullP->GetYaxis()->SetRangeUser(-5,5);*/
        TCanvas* cLog1 = new TCanvas("cLog1","cLog1", 800, 600);
        //cLog1->Divide(1,2,0,0,0);
        //cLog1->cd(2);
        gPad->SetTopMargin(0);
        gPad->SetLeftMargin(0.12);
        gPad->SetRightMargin(0.015);
        gPad->SetPad(0.03,0.02,0.97,0.97);
        plot_frameP->SetXTitle("m_{#mu^{#plus}#mu^{#minus}} [MeV/#it{c}^{2}]");
        plot_frameP->SetYTitle("Candidates per 2.4 MeV/#it{c}^{2}");
        plot_frameP->GetYaxis()->SetTitleOffset(1.01);
        plot_frameP->Draw();
        TLegend* leg1 = new TLegend(0.16, 0.47, 0.43, 0.92);
        leg1->SetTextFont(132);
        leg1->SetBorderSize(0);
        leg1->SetTextSize(0.05);
        leg1->SetFillStyle(0);
        leg1->SetHeader("Fit for #psi(2S)");
        leg1->AddEntry("data_setP", "data", "lep");
        leg1->AddEntry("tzPDFP", "total fit", "l");
        leg1->AddEntry("promptP", "prompt", "f");
        leg1->AddEntry("frombP", "non-prompt", "f");
        leg1->AddEntry("bkgP", "background", "l");
	leg1->Draw("same");
	//cLog1->cd(1);
        //gPad->SetBottomMargin(0);
        //gPad->SetLeftMargin(0.12);
        //gPad->SetRightMargin(0.015);
        //gPad->SetPad(0.03,0.77,0.97,0.97);
        //plot_pullP->Draw();
        cLog1->Print(argv[4]);

	return 0;
}
