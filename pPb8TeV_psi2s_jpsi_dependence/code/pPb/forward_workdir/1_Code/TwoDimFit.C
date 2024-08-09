#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>
#include <TStyle.h>
#include <TSystem.h>
#include <TCanvas.h>
#include <RooFit.h>
#include <RooPlot.h>
#include <RooHist.h>
#include <RooHistPdf.h>
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooGaussModel.h>
#include <RooGaussian.h>
#include <RooAddModel.h>
#include <RooAddPdf.h>
#include <RooDecay.h>
#include <RooCBShape.h>
#include <RooFitResult.h>
#include <RooArgSet.h>
#include <RooExponential.h>
#include <RooProdPdf.h>
#include <RooStats/SPlot.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
using namespace RooFit;
int main(int argc, char* argv[])
{
        int flag;
	sscanf(argv[1],"%d",&flag);
	TFile input_file(argv[2]);
        TTree* data_tree = (TTree*)input_file.Get("DecayTree");
        TFile* root_file = new TFile(argv[3], "recreate");
	RooRealVar psi_mass("psi_M", "psi_M", 3096.9 - 120, 3096.9 + 120);
	RooRealVar psi_massP("psi_M", "psi_M", 3686.09 - 120, 3686.09 + 120);
	RooRealVar tz("tz", "tz", -10, 10);
        RooRealVar tzError("tzError", "tzError", 0.001, 0.3);
        RooRealVar bkgSweight("bkg_sw", "bkg_sw", -100, 100);
        RooDataSet data_set("data_set", "data set", data_tree, RooArgSet(psi_mass, tz, tzError));
        double N = data_set.numEntries();
	RooDataSet data_setP("data_setP", "data set P", data_tree, RooArgSet(psi_massP, tz, tzError));
        if(flag==2) N = data_setP.numEntries();
	double fmass_mean, fmass_sigma1, fmass_sigma2, fmass_ratio, fmass_p0, fmass_alpha1, fmass_alpha2;
	double fmass_meanP, fmass_sigmaP, fmass_alphaP, fmass_p0P;
	double trash;
	ifstream fmass(argv[4]);
	fmass >> trash;
	fmass >> trash;
        fmass >> fmass_mean >> fmass_sigma1 >> fmass_sigma2 >> fmass_alpha1 >> fmass_alpha2 >> fmass_ratio >> fmass_p0 >> fmass_meanP >> fmass_sigmaP >> fmass_alphaP >> fmass_p0P;
	fmass.close();
        RooRealVar mass_mean("mass_mean", "mass mean", fmass_mean);
        RooRealVar mass_meanP("mass_meanP", "mass meanP", fmass_meanP);
	RooRealVar mass_sigmaP("mass_sigmaP","mass_sigma_P",fmass_sigmaP);
	RooRealVar mass_sigma1("mass_sigma1", "mass sigma1", fmass_sigma1);
        RooRealVar mass_sigma2("mass_sigma2", "mass sigma2", fmass_sigma2);
        RooRealVar mass_ratio("mass_ratio", "mass ratio", fmass_ratio);
	RooRealVar mass_p0("mass_p0", "mass p0", fmass_p0);
	RooRealVar mass_p0P("mass_p0", "mass p0", fmass_p0P);
	RooRealVar n("n", "n", 1.0);
	RooRealVar alpha1("alpha1","alpha1",fmass_alpha1);
        RooRealVar alpha2("alpha2","alpha2",fmass_alpha2);
	RooRealVar alphaP("alphaP","alphaP",fmass_alphaP);
	RooCBShape mass_myCB1("mass_myCB1", "CBMass1", psi_mass, mass_mean, mass_sigma1, alpha1, n);
        RooCBShape mass_myCB2("mass_myCB2", "CBMass2", psi_mass, mass_mean, mass_sigma2, alpha2, n);
        RooAddPdf mass_signal("mass_signal", "mass signal", RooArgList(mass_myCB1, mass_myCB2), RooArgList(mass_ratio));
        RooCBShape mass_signalP("mass_signalP", "mass signalP", psi_massP, mass_meanP, mass_sigmaP, alphaP, n);
	RooExponential mass_bkg("mass_bkg", "mass bkg", psi_mass, mass_p0);
	RooExponential mass_bkgP("mass_bkgP", "mass bkgP", psi_mass, mass_p0P);
	//result from background 
        double ftzbkg_bias, ftzbkg_sigma1, ftzbkg_sigma2, ftzbkg_beta, ftzbkg_tau1, ftzbkg_tau2, ftzbkg_tau3, ftzbkg_tau4, ftzbkg_tau5, ftzbkg_f1, ftzbkg_f2, ftzbkg_f3, ftzbkg_f4;
        ifstream ftzbkg(argv[5]);
        ftzbkg >> ftzbkg_bias >> ftzbkg_sigma1 >> ftzbkg_sigma2 >> ftzbkg_beta >> ftzbkg_tau1 >> ftzbkg_tau2 >> ftzbkg_tau3 >> ftzbkg_tau4  >> ftzbkg_f1 >> ftzbkg_f2 >> ftzbkg_f3 >> ftzbkg_f4;
        ftzbkg.close();
        RooRealVar tzbkg_bias("tzbkg_bias", "tzbkg bias", ftzbkg_bias);
        RooRealVar tzbkg_sigma1("tzbkg_sigma1", "tzbkg sigma1", ftzbkg_sigma1);
        RooRealVar tzbkg_sigma2("tzbkg_sigma2", "tzbkg sigma2", ftzbkg_sigma2);
        RooRealVar tzbkg_beta("tzbkg_beta", "tzbkg beta", ftzbkg_beta);
        RooRealVar tzbkg_tau1("tzbkg_tau1", "tzbkg tau1", ftzbkg_tau1);
        RooRealVar tzbkg_tau2("tzbkg_tau2", "tzbkg tau2", ftzbkg_tau2);
        RooRealVar tzbkg_tau3("tzbkg_tau3", "tzbkg tau3", ftzbkg_tau3);
        RooRealVar tzbkg_tau4("tzbkg_tau4", "tzbkg tau4", ftzbkg_tau4);
        RooRealVar tzbkg_f1("tzbkg_f1", "tzbkg f1", ftzbkg_f1);
        RooRealVar tzbkg_f2("tzbkg_f2", "tzbkg f2", ftzbkg_f2);
        RooRealVar tzbkg_f3("tzbkg_f3", "tzbkg f3", ftzbkg_f3);
        RooRealVar tzbkg_f4("tzbkg_f4", "tzbkg f4", ftzbkg_f4);
        RooRealVar zero("zero", "zero", 0);
        RooRealVar one("one", "one", 1);
        RooGaussModel tzbkg_res1("tzbkg_res1", "resolution model 1 for tzbkg", tz, tzbkg_bias, tzbkg_sigma1, one, tzError);
        RooGaussModel tzbkg_res2("tzbkg_res2", "resolution model 2 for tzbkg", tz, tzbkg_bias, tzbkg_sigma2, one, tzError);
        RooAddModel tzbkg_res("tzbkg_res", "resolution model for tzbkg", RooArgList(tzbkg_res1, tzbkg_res2), RooArgList(tzbkg_beta));
        RooDecay tzbkg_tzP1("tzbkg_tzP1", "tz decay function P1 for tzbkg", tz, tzbkg_tau1, tzbkg_res, RooDecay::SingleSided);
        RooDecay tzbkg_tzP2("tzbkg_tzP2", "tz decay function P2 for tzbkg", tz, tzbkg_tau2, tzbkg_res, RooDecay::SingleSided);
        RooDecay tzbkg_tzN("tzbkg_tzN", "tz decay function N for tzbkg", tz, tzbkg_tau3, tzbkg_res, RooDecay::Flipped);
        RooDecay tzbkg_tzPN("tzbkg_tzPN", "tz decay function PN for tzbkg", tz, tzbkg_tau4, tzbkg_res, RooDecay::DoubleSided);
        RooDecay tzbkg_tzDelta("tzbkg_tzDelta", "tz delta function for tzbkg", tz, zero, tzbkg_res, RooDecay::DoubleSided);
        RooAddPdf tzbkg_tzPDF("tzbkg_tzPDF", "tz pdf for tzbkg", RooArgList(tzbkg_tzP1, tzbkg_tzP2, tzbkg_tzN, tzbkg_tzPN, tzbkg_tzDelta), RooArgList(tzbkg_f1, tzbkg_f2, tzbkg_f3, tzbkg_f4));
        RooRealVar bias("bias", "bias", 0., -1., 1.);
        RooRealVar sigma1("sigma1", "sigma1", 1.,0.01,3.);
        //RooRealVar sigma2("sigma2", "sigma2", 0.7,0.1,3. );
        RooFormulaVar sigma2("sigma2","sigma2","2*sigma1", RooArgList(sigma1));
	RooRealVar beta("beta", "beta", 0.6479, 0.0, 1.);
        RooRealVar tau("tau", "tau" ,1.4,0.5,3);
        RooGaussModel res1("res1", "resolution model 1 for tz", tz, bias, sigma1, one, tzError);
        RooGaussModel res2("res2", "resolution model 2 for tz", tz, bias, sigma2, one, tzError);
        RooAddModel res("res", "resolution model for tz", RooArgList(res1, res2), RooArgList(beta));
        RooDecay tzDelta("tzDelta", "tz delta function for tz", tz, zero, res, RooDecay::DoubleSided);
        RooDecay tzP("tzP", "tz decay function P for tz", tz, tau, res, RooDecay::SingleSided);
        RooRealVar Nprompt("Nprompt", "Nprompt", 0.5*N, 0, N);
        RooRealVar Nfromb("Nfromb", "Nfromb", 0.1*N, 0, N);
        RooRealVar Nbkg("Nbkg", "Nbkg", 0.9*N, 0, 1.1*N);
        RooProdPdf prompt("prompt", "pdf prompt", RooArgList(mass_signal, tzDelta));
        RooProdPdf fromb("fromb", "pdf fromb", RooArgList(mass_signal, tzP));
        RooProdPdf bkg("bkg", "pdf bkg", RooArgList(mass_bkg, tzbkg_tzPDF));
        RooAddPdf tzPDF("tzPDF", "pdf tz", RooArgList(prompt, fromb, bkg), RooArgList(Nprompt, Nfromb, Nbkg));
	RooProdPdf promptP("promptP", "pdf promptP", RooArgList(mass_signalP, tzDelta));
        RooProdPdf frombP("frombP", "pdf frombP", RooArgList(mass_signalP, tzP));
        RooProdPdf bkgP("bkgP", "pdf bkgP", RooArgList(mass_bkgP, tzbkg_tzPDF));
        RooAddPdf tzPDFP("tzPDFP", "pdf tz", RooArgList(promptP, frombP, bkgP), RooArgList(Nprompt, Nfromb, Nbkg));
	if(flag==1)
	{
	RooFitResult *R = tzPDF.fitTo(data_set, Minos(true), Strategy(2), NumCPU(9), Save(true), ConditionalObservables(tzError));
        int iter = 0;
	while(R->covQual()!=3||R->edm()>1)
	{
		RooArgList Para = R->randomizePars();
		Nbkg.setVal(((RooAbsReal*)Para.find("Nbkg"))->getVal());
		Nprompt.setVal(((RooAbsReal*)Para.find("Nprompt"))->getVal());
		Nfromb.setVal(((RooAbsReal*)Para.find("Nfromb"))->getVal());
		sigma1.setVal(((RooAbsReal*)Para.find("sigma1"))->getVal());
		//sigma2.setVal(((RooAbsReal*)Para.find("sigma2"))->getVal());
		tau.setVal(((RooAbsReal*)Para.find("tau"))->getVal());
		beta.setVal(((RooAbsReal*)Para.find("beta"))->getVal());
		bias.setVal(((RooAbsReal*)Para.find("bias"))->getVal());
		R = tzPDF.fitTo(data_set, Minos(true), Strategy(2), NumCPU(9), Save(true), ConditionalObservables(tzError));
		iter = iter + 1;
		cout << "iter " << iter << endl;
		if(iter>5) break;
	}
	}
	if(flag==2)
	{
	RooFitResult *R = tzPDFP.fitTo(data_setP, Minos(true), Strategy(2), NumCPU(9), Save(true), ConditionalObservables(tzError));
        int iter = 0;
	while(R->covQual()!=3||R->edm()>1)
	{
		RooArgList Para = R->randomizePars();
		Nbkg.setVal(((RooAbsReal*)Para.find("Nbkg"))->getVal());
		Nprompt.setVal(((RooAbsReal*)Para.find("Nprompt"))->getVal());
		Nfromb.setVal(((RooAbsReal*)Para.find("Nfromb"))->getVal());
		sigma1.setVal(((RooAbsReal*)Para.find("sigma1"))->getVal());
		//sigma2.setVal(((RooAbsReal*)Para.find("sigma2"))->getVal());
		tau.setVal(((RooAbsReal*)Para.find("tau"))->getVal());
		beta.setVal(((RooAbsReal*)Para.find("beta"))->getVal());
		bias.setVal(((RooAbsReal*)Para.find("bias"))->getVal());
		R = tzPDFP.fitTo(data_setP, Minos(true), Strategy(2), NumCPU(9), Save(true), ConditionalObservables(tzError));
		iter = iter + 1;
		cout << "iter " << iter << endl;
		if(iter>5) break;
	}
	}
        if(flag==1) 
	{
		data_set.Write();
		tzPDF.Write();
	}
	if(flag==2)
	{
		data_setP.Write();
		tzPDFP.Write();
	}
        root_file->Close();
	ofstream txtout(argv[6]);
	txtout << Nprompt.getVal() << endl;
        txtout << Nprompt.getError() << endl;
        txtout << Nfromb.getVal() << endl;
        txtout << Nfromb.getError() << endl;
        txtout << Nbkg.getVal() << endl;
        txtout << Nbkg.getError() << endl;
	txtout << bias.getVal() << endl;
        txtout << bias.getError() << endl;
        txtout << sigma1.getVal() << endl;
        txtout << sigma1.getError() << endl;
        //txtout << sigma2.getVal() << endl;
        //txtout << sigma2.getError() << endl;
        txtout << beta.getVal() << endl;
        txtout << beta.getError() << endl;
        txtout << tau.getVal() << endl;
        txtout << tau.getError() << endl;
        txtout.close();
        return 0;
}

