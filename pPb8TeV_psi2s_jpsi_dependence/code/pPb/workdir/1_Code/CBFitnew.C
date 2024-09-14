#include <fstream>
#include <RooFormulaVar.h>
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
#include <RooGaussian.h>
#include <string>
#include <RooStats/SPlot.h>
#include <vector>
#include "0_header/lhcbStyle.h"
#include <RooFitResult.h>
using namespace std;
using namespace RooFit;

int main(int argc, char *argv[])
{
	//input
	setLHCbStyle;
	TFile input_fileJ(argv[1]);
	TFile input_fileP(argv[2]);
	TTree *input_treeJ = (TTree*)input_fileJ.Get("DecayTree");
	TTree *input_treeP = (TTree*)input_fileP.Get("DecayTree");
	double a0, b0, c0;
	a0 = -0.00011;
	b0 = 0.0085;
	c0 = 2.066;
	//fit to J/psi
	RooRealVar psi_mass("psi_M", "psi_mass", 3096.9 - 120, 3096.9 + 120);
	RooDataSet data_set("data_set", "data set", input_treeJ, RooArgSet(psi_mass));
	double N = data_set.numEntries();
	RooRealVar mean("mean","mean mass of Jpsi",3096.9,3096.9-10,3096.9+10);
	RooRealVar sigma("sigma","width of CB",12.,0.,40.);
	RooRealVar a("a","a",a0);
	RooRealVar b("b","b",b0);
	RooRealVar c("c","c",c0);
	RooFormulaVar alpha("alpha","alpha","a*sigma*sigma+b*sigma+c",RooArgSet(a,b,c,sigma));
	RooRealVar n("n","n",1.0);
	RooRealVar p0("p0","p0(for background)",0.0,-1.0,1.0);
	RooCBShape signal("signal", "CB_Mass", psi_mass, mean, sigma, alpha, n);
	RooExponential bkg("bkg", "background signal", psi_mass, p0);
	RooRealVar Nsig("Nsig", "number of signal", N*0.8, 0, N);
	RooRealVar Nbkg("Nbkg", "number of background", N*0.2, 0 , N);
	RooAddPdf massPDF("massPDF", "total signal of mass", RooArgList(signal,bkg), RooArgList(Nsig,Nbkg));
	massPDF.fitTo(data_set, Minos(true), Strategy(2), NumCPU(20), Save(true));
	
	//Fit to Psi2S
	double mp = 3686.09;
	double sp = sigma.getVal()*mp/3096.9;
	double l0 = 25.7;
	RooRealVar l("l","l",l0);
	RooRealVar ratioP("ratioP","ratioP",0.96);
	RooRealVar psi_massP("psi_M", "psi_mass_P", 3686.09 - 120, 3686.09 + 120);
	RooDataSet data_setP("data_setP", "psi(2S) data set", input_treeP, RooArgSet(psi_massP));
	double NP = data_setP.numEntries();
	RooRealVar meanP("mean","mean mass of Psi2S from PDG",mp-10, mp+10);
	RooRealVar sigmaP1("sigmaP1","sigma of CB1 for Psi2S",sp,sp-5, sp+5);
	RooFormulaVar sigmaP2("sigmaP2","sigma of CB2 for Psi2S","l+sigmaP1",RooArgSet(l,sigmaP1));
	RooFormulaVar alphaP1("alphaP1","alphaP1","a*sigmaP1*sigmaP1+b*sigmaP1+c",RooArgSet(a,b,c,sigmaP1));
	RooFormulaVar alphaP2("alphaP2","alphaP2","a*sigmaP2*sigmaP2+b*sigmaP2+c",RooArgSet(a,b,c,sigmaP2));
	//RooCBShape signalP("signalP", "CB_Mass psi(2S)", psi_massP, meanP, sigmaP, alphaP, n);
	RooCBShape signalP1("signalP1", "CB_Mass 1 psi(2S)", psi_massP, meanP, sigmaP1, alphaP1, n);
	RooCBShape signalP2("signalP2", "CB_Mass 2 psi(2S)", psi_massP, meanP, sigmaP2, alphaP2, n);
	RooAddPdf signalP("signalP", "signal_mass", RooArgList(signalP1, signalP2), RooArgList(ratioP));
	RooRealVar p0P("p0P","p0(for psi(2S) background)",0.0,-1.0,1.0);
	RooExponential bkgP("bkgP", "background signal for Psi(2S)", psi_massP, p0P);
	RooRealVar NsigP("NsigP", "number of signal", NP*0.8, 0, NP);
	RooRealVar NbkgP("NbkgP", "number of background", NP*0.2, 0 , N);
	RooAddPdf massPDF_P("massPDF_P", "total signal of mass Psi(2S)", RooArgList(signalP,bkgP), RooArgList(NsigP,NbkgP));
	massPDF_P.fitTo(data_setP, Minos(true), Strategy(2), NumCPU(20), Save(false));
	//Fit to Jpsi
	RooRealVar psi_massJ("psi_M", "psi_mass_J", 3096.9 - 120, 3096.9 + 120);
	RooDataSet data_setJ("data_setJ", "J/psi data set", input_treeJ, RooArgSet(psi_massJ));
	double NJ = data_setJ.numEntries();
	RooRealVar meanJ("meanJ","mean mass of Jpsi",3096.9, 3096.9-10, 3096.9+10);
	RooRealVar sigma1("sigma1","sigma of CB1",15.,0.,40.);
	RooRealVar sigma2("sigma2","sigma of CB2",15.,0.,40.);
	RooFormulaVar alpha1("alpha1","alpha1","a*sigma1*sigma1+b*sigma1+c",RooArgSet(a,b,c,sigma1));
	RooFormulaVar alpha2("alpha2","alpha2","a*sigma2*sigma2+b*sigma2+c",RooArgSet(a,b,c,sigma2));
	RooRealVar p0J("p0J","p0J(for background)",0.0,-1.0,1.0);
	RooCBShape CB1("CBMass1", "CB_Function 1", psi_massJ, meanJ, sigma1, alpha1, n);
	RooCBShape CB2("CBMass2", "CB_Function 2", psi_massJ, meanJ, sigma2, alpha2, n);
	RooRealVar ratio("ratio","ratio of CB1 over CB1+CB2",0.5,0.,1.);
	RooAddPdf signalJ("signalJ", "signal_mass Jpsi", RooArgList(CB1, CB2), RooArgList(ratio));
	RooExponential bkgJ("bkgJ", "background signal Jpsi", psi_massJ, p0J);
	RooRealVar NsigJ("NsigJ", "number of signal", NJ*0.8, 0, NJ);
	RooRealVar NbkgJ("NbkgJ", "number of background", NJ*0.2, 0, NJ);
	RooAddPdf massPDF_J("massPDF_J", "total signal of mass", RooArgList(signalJ,bkgJ), RooArgList(NsigJ,NbkgJ));	
	massPDF_J.fitTo(data_setJ, Minos(true), Strategy(2), NumCPU(20), Save(false));


	//plot
	TCanvas *Canvas1 = new TCanvas("Canvas1","Canvas for all", 1600, 1200);
	RooPlot *frame1 = psi_massJ.frame(Bins(60));
	data_set.plotOn(frame1, Name("data_setJ"));
	massPDF_J.plotOn(frame1, Name("signalJ"), Components("signalJ"), FillColor(kRed), FillStyle(3245), VLines(), DrawOption("F"), LineWidth(0));
	massPDF_J.plotOn(frame1, Name("bkgJ"), Components("bkgJ"), LineColor(kViolet), LineStyle(7));
	massPDF_J.plotOn(frame1, Name("total"), LineColor(kBlue), LineStyle(1));
	frame1->SetLabelOffset(0.005, "Y");
	frame1->SetTitleOffset(0.8,"Y");
	frame1->SetXTitle("m_{#mu^{+}#mu^{-}}[MeV/#font[12]{c}^{2}]");
	frame1->SetYTitle("Candidates per 4 MeV/#font[12]{c}^{2}");
	TLegend *leg = new TLegend(0.80, 0.80, 1.0, 1.0);
	leg->SetTextFont(132);
	leg->SetBorderSize(2);
	leg->SetTextSize(0.04);
	leg->AddEntry(frame1->findObject("data_setJ"), "data");
	leg->AddEntry(frame1->findObject("massPDF_J"), "total fit function");
	leg->AddEntry(frame1->findObject("signalJ"), "J/#psi signal");
	leg->AddEntry(frame1->findObject("bkgJ"), "background");
	//pullhist
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
	//plot for Psi(2S)
	TCanvas *Canvas2 = new TCanvas("Canvas2","Canvas for all, Psi2S", 1600, 1200);
	RooPlot *frame2 = psi_massP.frame(Bins(60));
	data_setP.plotOn(frame2, Name("data_setP"));
	massPDF_P.plotOn(frame2, Name("signalP"), Components("signalP"), FillColor(kRed), FillStyle(3245), VLines(), DrawOption("F"), LineWidth(0));
	massPDF_P.plotOn(frame2, Name("bkgP"), Components("bkgP"), LineColor(kViolet), LineStyle(7));
	massPDF_P.plotOn(frame2, Name("totalP"), LineColor(kBlue), LineStyle(1));

	frame2->SetLabelOffset(0.005, "Y");
	frame2->SetTitleOffset(0.8,"Y");
	frame2->SetXTitle("m_{#mu^{+}#mu^{-}}[MeV/#font[12]{c}^{2}]");
	frame2->SetYTitle("Candidates per 4 MeV/#font[12]{c}^{2}");

	TLegend *leg2 = new TLegend(0.80, 0.80, 1.0, 1.0);
	leg2->SetTextFont(132);
	leg2->SetBorderSize(2);
	leg2->SetTextSize(0.04);
	leg2->AddEntry(frame2->findObject("data_setP"), "data");
	leg2->AddEntry(frame2->findObject("massPDF_P"), "total fit function");
	leg2->AddEntry(frame2->findObject("signalP"), "#psi(2S) signal");
	leg2->AddEntry(frame2->findObject("bkgP"), "background");
	RooHist *hist2 = frame2->pullHist();
	RooPlot *plot2 = psi_massP.frame();
	hist2->SetDrawOption("BAR");
	plot2->addPlotable(hist2, "P");
	plot2->GetYaxis()->SetTitleSize(0.20);
	plot2->GetYaxis()->SetLabelSize(0.20);
	plot2->GetYaxis()->SetNdivisions(5,0,0);
	plot2->GetYaxis()->SetTitle("#Delta/#sigma");
	plot2->GetYaxis()->SetRangeUser(-5,5);
	gROOT->SetBatch(true);
	Canvas2->Divide(1,2,0,0,0);
	Canvas2->cd(2);
	gPad->SetTopMargin(0);
	gPad->SetLeftMargin(0.12);
	gPad->SetPad(0.03,0.02,0.97,0.77);
	frame2->Draw();
	leg2->Draw();
	Canvas2->cd(1);
	gPad->SetTopMargin(0);
	gPad->SetLeftMargin(0.12);
	gPad->SetPad(0.03,0.77,0.97,0.97);
	plot2->Draw();
	Canvas2->SaveAs(argv[4],"recreate");	


	//output
	ofstream txtresult(argv[5]);
	txtresult << NsigJ.getVal() <<endl;
	txtresult << NsigP.getVal() <<endl;
	txtresult << meanJ.getVal() << endl;
	txtresult << sigma1.getVal() << endl;
	txtresult << sigma2.getVal() << endl;
	txtresult << alpha1.getVal() << endl;
	txtresult << alpha2.getVal() << endl;
	txtresult << ratio.getVal() << endl;
	txtresult << p0J.getVal() << endl;
	txtresult << meanP.getVal() << endl;
	txtresult << sigmaP1.getVal() << endl;
	txtresult << sigmaP2.getVal() << endl;
	txtresult << alphaP1.getVal() << endl;
	txtresult << alphaP2.getVal() << endl;
	txtresult << ratioP.getVal() << endl;
	txtresult << p0P.getVal() << endl;
	txtresult.close();

	return 0;
}
