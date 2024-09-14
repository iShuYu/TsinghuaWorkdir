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
#include "../../../Yield/Psi2S/0_CFile/header/lhcbStyle.h"
using namespace std;
using namespace RooFit;

int main(int argc, char *argv[])
{
	setLHCbStyle();
	
	//input
	//double a1, a2;
	//ifstream config(argv[1]);
	//config >> a1 >> a2;
	TFile input_file(argv[1]);
	TTree *input_tree = (TTree*)input_file.Get("DecayTree");
	//ifstream smear(argv[5]);
	double a0, b0, c0, l0;
	//smear >> a0 >> b0 >> c0;
	a0 = -0.00011;
	b0 = 0.0085;
	c0 = 2.066;
	l0 = 25.7;
	//fit
	RooRealVar psi_mass("psi_M", "psi_mass", 3096.9 - 120, 3096.9 + 120);
	RooDataSet data_set("data_set", "data set", input_tree, RooArgSet(psi_mass));
	double N = data_set.numEntries();
	cout<<"total entries = "<<N<<endl;
	RooRealVar mean("mean","mean mass of Jpsi",3096.9,3096.9-10,3096.9+10);
	RooRealVar sigma1("sigma1","sigma of CB1",15.,0.,40.);
	RooRealVar sigma2("sigma2","sigma of CB2",15.,0.,40.);
	RooRealVar l("l","l",l0);
	//RooFormulaVar sigma2("sigma2","wider sigma","l+sigma1",RooArgSet(l,sigma1));
	RooRealVar a("a","a",a0);
	RooRealVar b("b","b",b0);
	RooRealVar c("c","c",c0);
	RooFormulaVar alpha1("alpha1","alpha1","a*sigma1*sigma1+b*sigma1+c",RooArgSet(a,b,c,sigma1));
	RooFormulaVar alpha2("alpha2","alpha2","a*sigma2*sigma2+b*sigma2+c",RooArgSet(a,b,c,sigma2));
	RooRealVar n("n","n",1.0);
	RooRealVar ratio("ratio","ratio of CB1 over CB1+CB2",0.9,0,1);
	RooRealVar p0("p0","p0(for background)",0.0,-1.0,1.0);
	RooCBShape CB1("CBMass1", "CB_Function 1", psi_mass, mean, sigma1, alpha1, n);
	RooCBShape CB2("CBMass2", "CB_Function 2", psi_mass, mean, sigma2, alpha2, n);
	RooAddPdf signal("signal", "signal_mass", RooArgList(CB1, CB2), RooArgList(ratio));
	RooExponential bkg("bkg", "background signal", psi_mass, p0);
	RooRealVar Nsig("Nsig", "number of signal", N*0.8, 0, N);
	RooRealVar Nbkg("Nbkg", "number of background", N*0.2, 0 , N);
	RooAddPdf massPDF("massPDF", "total signal of mass", RooArgList(signal,bkg), RooArgList(Nsig,Nbkg));
	
	massPDF.fitTo(data_set, Minos(true), Strategy(1), NumCPU(20), Save(false));
	massPDF.getParameters(data_set);
	massPDF.fitTo(data_set, Minos(true), Strategy(2), NumCPU(20), Save(false));


	//plot
	TCanvas *Canvas1 = new TCanvas("Canvas1","Canvas for all", 1600, 1200);
	RooPlot *frame1 = psi_mass.frame(Bins(60));
	data_set.plotOn(frame1, Name("data_set"));
	massPDF.plotOn(frame1, Name("signal"), Components("signal"), FillColor(kRed), FillStyle(3245), VLines(), DrawOption("F"), LineWidth(0));
	massPDF.plotOn(frame1, Name("bkg"), Components("bkg"), LineColor(kViolet), LineStyle(7));
	massPDF.plotOn(frame1, Name("total"), LineColor(kBlue), LineStyle(1));

	frame1->SetLabelOffset(0.005, "Y");
	frame1->SetTitleOffset(0.8,"Y");
	frame1->SetXTitle("m_{#mu^{+}#mu^{-}}[MeV/#font[12]{c}^{2}]");
	frame1->SetYTitle("Candidates per 4 MeV/#font[12]{c}^{2}");

	TLegend *leg = new TLegend(0.80, 0.80, 1.0, 1.0);
	leg->SetTextFont(132);
	leg->SetBorderSize(2);
	leg->SetTextSize(0.04);
	leg->AddEntry(frame1->findObject("data_set"), "data");
	leg->AddEntry(frame1->findObject("massPDF"), "total fit function");
	leg->AddEntry(frame1->findObject("signal"), "J/#psi signal");
	leg->AddEntry(frame1->findObject("bkg"), "background");

	//pullhist
	RooHist *hist1 = frame1->pullHist();
	RooPlot *plot1 = psi_mass.frame();
	hist1->SetDrawOption("BAR");
	//for (int i=0; i<hist1->GetN(); i++) {hist1->SetPointError(i,0,0,0,0);}
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

	Canvas1->SaveAs(argv[2],"recreate");

	//output
	ofstream result(argv[3]);
	result << "Nsig = " << Nsig.getVal() << endl;
	result << "NsigError = " << Nsig.getError() << endl;
	result << "Nbkg = " << Nbkg.getVal() << endl;
	result << "NbkgError = " << Nbkg.getError() << endl;
	result << "mean = " << mean.getVal() << endl;
	result << "meanError = " << mean.getError() << endl;
	result << "sigma1 = " << sigma1.getVal() << endl;
	result << "sigma1Error = " << sigma1.getError() <<endl;
	//result << "sigma2 = " << sigma2.getVal() << endl;
	//result << "sigma2Error = " << sigma2.getError() <<endl;
	//result << "ratio of CB1 over CB2 = " << ratio.getVal() << endl;
	//result << "ratioError = " << ratio.getError() << endl;
	result << "attenuation constant p0 = " << p0.getVal() << endl;
	result << "p0Error = " << p0.getError() << endl;
	result.close();

	ofstream txtresult(argv[4]);
	txtresult << Nsig.getVal() << endl;
	txtresult << mean.getVal() << endl;
	txtresult << sigma1.getVal() << endl;
	txtresult << sigma2.getVal() << endl;
	txtresult << ratio.getVal() << endl;
	txtresult << p0.getVal() << endl;
	txtresult << alpha1.getVal() << endl;
	txtresult << alpha2.getVal() <<endl;
	//txtresult << sigma1.getError() << endl;
	//txtresult << sigma2.getError() << endl;
	//txtresult << ratio.getError() << endl;
	//txtresult << p0.getError() << endl;
	txtresult.close();

	TFile* splot_file = new TFile(argv[5], "recreate");
        RooStats::SPlot* splot = new RooStats::SPlot("splot", "splot", data_set, &massPDF, RooArgList(Nsig, Nbkg));
        TTree* result1 = input_tree->CloneTree(0);
        double sig_sw, bkg_sw , psi_M, psi_M_check;
        result1->Branch("sig_sw", &sig_sw, "sig_sw/D");
        result1->Branch("bkg_sw", &bkg_sw, "bkg_sw/D");
        input_tree->SetBranchAddress("psi_M",&psi_M);
        for (int i = 0; i < N; i++) {
                input_tree->GetEntry(i);
                psi_M_check = ((RooRealVar*)(data_set.get(i)->find("psi_M")))->getVal();
                if(psi_M!=psi_M_check) continue;
                sig_sw = ((RooRealVar*)(data_set.get(i)->find("Nsig_sw")))->getVal();
                bkg_sw = ((RooRealVar*)(data_set.get(i)->find("Nbkg_sw")))->getVal();
                result1->Fill();
	}
        result1->Write();
        splot_file->Close();
	return 0;
}
