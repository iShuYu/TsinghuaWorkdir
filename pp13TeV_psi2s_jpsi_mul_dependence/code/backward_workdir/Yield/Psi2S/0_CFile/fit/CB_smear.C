#include <fstream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <RooFit.h>
#include <RooPlot.h>
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooAddPdf.h>
#include <RooCBShape.h>
#include <RooExponential.h>
#include <string>
#include <RooGaussian.h>
#include <RooStats/SPlot.h>
#include <vector>
#include "../header/lhcbStyle.h"
using namespace std;
using namespace RooFit;

int main(int argc, char *argv[])
{
	setLHCbStyle();
 	TFile input_file(argv[1]);
 	TTree *input_tree = (TTree*)input_file.Get("mct");

	//fit
 	RooRealVar psi_mass("psi_MM", "psi_mass", 3686. - 200, 3686. + 120);
 	RooDataSet data_set("data_set", "data set", input_tree, RooArgSet(psi_mass));
 	double N = data_set.numEntries();
 	cout << "total entries = " << N << endl;

 	RooRealVar mean("mean","mean mass of Psi2S",3686.,3686.-10,3686.+10);
 	RooRealVar sigma("sigma","sigma of CB",15.,0.,45.);
 	RooRealVar alpha("alpha","alpha",1,0.,20.);
 	RooRealVar n("n","n",1.0);
 	RooCBShape CB("CBMass", "CB_Function", psi_mass, mean, sigma, alpha, n);
 	CB.fitTo(data_set, Minos(true), Strategy(1), NumCPU(20), Save(false));
 	CB.getParameters(data_set);
 	CB.fitTo(data_set, Minos(true), Strategy(2), NumCPU(20), Save(false));
	//output
 	ofstream result(argv[2]);
 	result << alpha.getVal() << endl;
 	result << sigma.getVal() << endl;
	result << alpha.getError() << endl;
	result << mean.getVal() << endl;
 	result.close();
	//plot
	TCanvas *Canvas1 = new TCanvas("Canvas1","Canvas for all", 1600, 1200);
        RooPlot *frame1 = psi_mass.frame(Bins(60));
        data_set.plotOn(frame1, Name("data_set"));
        CB.plotOn(frame1, Name(""), LineColor(kBlue), LineStyle(1));

        frame1->SetLabelOffset(0.005, "Y");
        frame1->SetTitleOffset(0.8,"Y");
        frame1->SetXTitle("m_{#mu^{+}#mu^{-}}[MeV/#font[12]{c}^{2}]");
        frame1->SetYTitle("Candidates per 4 MeV/#font[12]{c}^{2}");

        TLegend *leg = new TLegend(0.80, 0.80, 1.0, 1.0);
	leg->SetTextFont(132);
        leg->SetBorderSize(2);
        leg->SetTextSize(0.04);
        leg->AddEntry(frame1->findObject("data_set"), "data");
        leg->AddEntry(frame1->findObject("CB"), "CB function");
	RooHist *hist1 = frame1->pullHist();
        RooPlot *plot1 = psi_mass.frame();
        hist1->SetDrawOption("BAR");
	plot1->addPlotable(hist1, "P");
        plot1->GetYaxis()->SetTitleSize(0.20);
        plot1->GetYaxis()->SetLabelSize(0.20);
        plot1->GetYaxis()->SetNdivisions(5,0,0);
        plot1->GetYaxis()->SetTitle("#Delta/#sigma");
        plot1->GetYaxis()->SetRangeUser(-5,5);

        gROOT->SetBatch(true);
        Canvas1->Divide(1,2,0,0,0);
        Canvas1->cd(2);
        gPad->SetTopMargin(0);
        gPad->SetLeftMargin(0.12);
        gPad->SetPad(0.03,0.02,0.97,0.77);
        frame1->Draw();
        leg->Draw();

        Canvas1->cd(1);
        gPad->SetTopMargin(0);
        gPad->SetLeftMargin(0.12);
        gPad->SetPad(0.03,0.77,0.97,0.97);
        plot1->Draw();
	Canvas1->SaveAs(argv[3],"recreate");
	return 0;
}
