#include <fstream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <RooFit.h>
#include <RooPlot.h>
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooAddPdf.h>
#include <RooGaussian.h>
#include <RooKeysPdf.h>
#include <RooExponential.h>
#include <RooFFTConvPdf.h>
#include <RooStats/SPlot.h>
#include "../../../Yield/Jpsi/0_CFile/header/lhcbStyle.h"
#include <string>

using namespace std;
using namespace RooFit;

const double inf = 1e10;

int main(int argc, char* argv[])
{
	setLHCbStyle();
	//input MC Tree for fit
	TFile *input;
	input = TFile::Open(argv[1]);
	TTree *MC_tree = (TTree*)input->Get("DecayTree");
	//input data Tree
	input = TFile::Open(argv[2]);
	TTree *Data_tree = (TTree*)input->Get("DecayTree");
	//Variable
	RooRealVar psi_mass("psi_M", "psi mass", 3096.9 - 120, 3096.9 + 120);
	//Data set
	RooDataSet data_set("data_set", "data set", Data_tree, RooArgSet(psi_mass));
        RooDataSet MC_shape("MC_shape", "MC_shape", MC_tree, RooArgSet(psi_mass));
	double N = data_set.numEntries();
	//use a gaus to numerically convolute
	RooRealVar mean("mean", "mean", 0, -10, 10);
        RooRealVar sigma("sigma", "sigma", 5, 0, 25);
        RooGaussian res("res", "res", psi_mass, mean, sigma);
        RooKeysPdf MCpdf("MCpdf", "MCpdf", psi_mass, MC_shape);
        RooFFTConvPdf signal("signal", "signal", psi_mass, MCpdf, res);
	//bkg
	RooRealVar p0("p0", "p0", 0.0, -2.0, 2.0);
	RooExponential bkg("bkg", "background", psi_mass, p0);
	//total
	RooRealVar Nsig("Nsig", "yield of signal", N * 0.8, 0, 1.5*N);
        RooRealVar Nbkg("Nbkg", "yield of background", N * 0.2, 0, N);
        RooAddPdf massPDF("massPDF", "signal and background", RooArgList(signal, bkg), RooArgList(Nsig, Nbkg));
	//fit
	massPDF.fitTo(data_set, Minos(true), Strategy(2), NumCPU(50), Save(false));
	//plot
	RooPlot* plot_frame = psi_mass.frame(Bins(100));
        data_set.plotOn(plot_frame, Name("data_fit"));
        massPDF.plotOn(plot_frame, Components("signal"), LineColor(kRed), LineStyle(1));
        massPDF.plotOn(plot_frame, Components("bkg"), LineColor(kViolet), LineStyle(1));
        massPDF.plotOn(plot_frame, LineColor(kBlue), LineStyle(1));

        RooHist* hpull = plot_frame->pullHist();
        hpull->SetFillStyle(3001);
        RooPlot* plot_pull = psi_mass.frame();
        plot_pull->addPlotable(hpull, "P");
        plot_pull->SetTitle("");
        plot_pull->GetYaxis()->SetLabelSize(0.20);
        plot_pull->GetYaxis()->SetNdivisions(206);

        gROOT->Reset();
        gROOT->SetBatch(true);
        TCanvas* cLog = new TCanvas("cLog","cLog");
        cLog->Divide(1,2,0,0,0);

        cLog->cd(2);
        //gPad->SetLogy();
        gPad->SetTopMargin(0);
        gPad->SetLeftMargin(0.12);
        gPad->SetPad(0.03,0.02,0.97,0.77);
        plot_frame->SetMinimum(0.5);
        plot_frame->Draw();

        cLog->cd(1);
        gPad->SetBottomMargin(0);
        gPad->SetLeftMargin(0.12);
        gPad->SetPad(0.03,0.77,0.97,0.97);
        plot_pull->Draw();	
        cLog->Print(argv[3]);
	
	ofstream fout(argv[4]);
	fout << Nsig.getVal() << endl;
        fout << "NsigError = " << Nsig.getError() << endl;
        fout << "Nbkg = " << Nbkg.getVal() << endl;
        fout << "NbkgError = " << Nbkg.getError() << endl;
        fout << "mean = " << mean.getVal() << endl;
        fout << "meanError = " << mean.getError() << endl;
        fout << "sigma = " << sigma.getVal() << endl;
        fout << "sigmaError = " << sigma.getError() << endl;
        fout << "p0 =" << p0.getVal() << endl;
        fout << "p0Error =" << p0.getError() << endl;
        fout.close();

        return 0;
}

                                   
