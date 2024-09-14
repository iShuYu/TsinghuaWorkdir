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
        TFile input_file(argv[1]);
        TTree* data_tree = (TTree*)input_file.Get("DecayTree");

        TFile tail_file(argv[7]);
        TTree* tail_tree = (TTree*)tail_file.Get("DecayTree");
        TFile* root_file = new TFile(argv[2], "recreate");

        RooRealVar psi_mass("psi_M", "psi_M", 3686.0 - 120, 3686.0 + 120);
        RooRealVar tz("tz", "tz", -10, 10);
        RooRealVar tzError("tzError", "tzError", 0.001, 0.3);
        RooRealVar bkgSweight("bkg_sw", "bkg_sw", -100, 100);

        RooDataSet data_set("data_set", "data set", data_tree, RooArgSet(psi_mass, tz, tzError));
        RooDataSet tail_set("tail_set", "tail set", tail_tree, RooArgSet(tz));
        RooDataHist* tail_hist = tail_set.binnedClone("");

        double N = data_set.numEntries();
        //cout << "Total Entries = " << N << endl;
        //cout << "Wrong PV Entries = " << tail_set.numEntries() << endl;
        double fmass_mean, fmass_sigma1, fmass_sigma2, fmass_ratio, fmass_p0, fmass_alpha1, fmass_alpha2;
        ifstream fmass(argv[3]);
        fmass >> fmass_mean >> fmass_sigma1 >> fmass_sigma2 >> fmass_ratio >> fmass_p0 >> fmass_alpha1 >> fmass_alpha2;
        fmass.close();
        RooRealVar mass_mean("mass_mean", "mass mean", fmass_mean);
        RooRealVar mass_sigma1("mass_sigma1", "mass sigma1", fmass_sigma1);
        RooRealVar mass_sigma2("mass_sigma2", "mass sigma2", fmass_sigma2);
        RooRealVar mass_ratio("mass_ratio", "mass ratio", fmass_ratio);
        RooRealVar mass_p0("mass_p0", "mass p0", fmass_p0);
        RooRealVar n("n", "n", 1.0);
        RooRealVar alpha1("alpha1", "alpha1", fmass_alpha1);
        RooRealVar alpha2("alpha2", "alpha2", fmass_alpha2);
        RooCBShape mass_myCB1("mass_myCB1", "CBMass1", psi_mass, mass_mean, mass_sigma1, alpha1, n);
        RooCBShape mass_myCB2("mass_myCB2", "CBMass2", psi_mass, mass_mean, mass_sigma2, alpha2, n);
        RooAddPdf mass_signal("mass_signal", "mass signal", RooArgList(mass_myCB1, mass_myCB2), RooArgList(mass_ratio));
        RooExponential mass_bkg("mass_bkg", "mass bkg", psi_mass, mass_p0);
			//result from background 
        double ftzbkg_bias, ftzbkg_sigma1, ftzbkg_sigma2, ftzbkg_beta, ftzbkg_tau1, ftzbkg_tau2, ftzbkg_tau3, ftzbkg_tau4, ftzbkg_tau5, ftzbkg_f1, ftzbkg_f2, ftzbkg_f3, ftzbkg_f4;
        ifstream ftzbkg(argv[4]);
        ftzbkg >> ftzbkg_bias >> ftzbkg_sigma1 >> ftzbkg_sigma2 >> ftzbkg_beta >> ftzbkg_tau1 >> ftzbkg_tau2 >> ftzbkg_tau3 >> ftzbkg_tau4  >> ftzbkg_f1 >> ftzbkg_f2 >> ftzbkg_f3 >> ftzbkg_f4;
        ftzbkg.close();
        cout << ftzbkg_bias << " " << ftzbkg_sigma1 << " " << ftzbkg_sigma2 << " " << ftzbkg_beta << " " << ftzbkg_tau1 << " " << ftzbkg_tau2 << " " << ftzbkg_tau3 << " " << ftzbkg_tau4 << " " << ftzbkg_f1 << " " << ftzbkg_f2 << " " << ftzbkg_f3 << " " << ftzbkg_f4  << endl;
        RooRealVar tzbkg_bias("tzbkg_bias", "tzbkg bias", ftzbkg_bias);
        RooRealVar tzbkg_sigma1("tzbkg_sigma1", "tzbkg sigma1", ftzbkg_sigma1);
        RooRealVar tzbkg_sigma2("tzbkg_sigma2", "tzbkg sigma2", ftzbkg_sigma2);
        RooRealVar tzbkg_beta("tzbkg_beta", "tzbkg beta", ftzbkg_beta);
        RooRealVar tzbkg_tau1("tzbkg_tau1", "tzbkg tau1", ftzbkg_tau1);
        RooRealVar tzbkg_tau2("tzbkg_tau2", "tzbkg tau2", ftzbkg_tau2);
        RooRealVar tzbkg_tau3("tzbkg_tau3", "tzbkg tau3", ftzbkg_tau3);
        RooRealVar tzbkg_tau4("tzbkg_tau4", "tzbkg tau4", ftzbkg_tau4);
        //RooRealVar tzbkg_tau5("tzbkg_tau5", "tzbkg tau5", ftzbkg_tau5);
        RooRealVar tzbkg_f1("tzbkg_f1", "tzbkg f1", ftzbkg_f1);
        RooRealVar tzbkg_f2("tzbkg_f2", "tzbkg f2", ftzbkg_f2);
        RooRealVar tzbkg_f3("tzbkg_f3", "tzbkg f3", ftzbkg_f3);
        RooRealVar tzbkg_f4("tzbkg_f4", "tzbkg f4", ftzbkg_f4);
        //RooRealVar tzbkg_f5("tzbkg_f5", "tzbkg f5", ftzbkg_f5);
        RooRealVar zero("zero", "zero", 0);
        RooRealVar one("one", "one", 1);
        RooGaussModel tzbkg_res1("tzbkg_res1", "resolution model 1 for tzbkg", tz, tzbkg_bias, tzbkg_sigma1, one, tzError);
        RooGaussModel tzbkg_res2("tzbkg_res2", "resolution model 2 for tzbkg", tz, tzbkg_bias, tzbkg_sigma2, one, tzError);
        RooAddModel tzbkg_res("tzbkg_res", "resolution model for tzbkg", RooArgList(tzbkg_res1, tzbkg_res2), RooArgList(tzbkg_beta));
        RooDecay tzbkg_tzP1("tzbkg_tzP1", "tz decay function P1 for tzbkg", tz, tzbkg_tau1, tzbkg_res, RooDecay::SingleSided);
        RooDecay tzbkg_tzP2("tzbkg_tzP2", "tz decay function P2 for tzbkg", tz, tzbkg_tau2, tzbkg_res, RooDecay::SingleSided);
        //RooDecay tzbkg_tzP3("tzbkg_tzP3", "tz decay function P3 for tzbkg", tz, tzbkg_tau5, tzbkg_res, RooDecay::SingleSided);
        RooDecay tzbkg_tzN("tzbkg_tzN", "tz decay function N for tzbkg", tz, tzbkg_tau3, tzbkg_res, RooDecay::Flipped);
        RooDecay tzbkg_tzPN("tzbkg_tzPN", "tz decay function PN for tzbkg", tz, tzbkg_tau4, tzbkg_res, RooDecay::DoubleSided);
        RooDecay tzbkg_tzDelta("tzbkg_tzDelta", "tz delta function for tzbkg", tz, zero, tzbkg_res, RooDecay::DoubleSided);
        RooAddPdf tzbkg_tzPDF("tzbkg_tzPDF", "tz pdf for tzbkg", RooArgList(tzbkg_tzP1, tzbkg_tzP2, tzbkg_tzN, tzbkg_tzPN, tzbkg_tzDelta), RooArgList(tzbkg_f1, tzbkg_f2, tzbkg_f3, tzbkg_f4));
        RooRealVar bias("bias", "bias", -0.03, -0.5, 0.5);
        RooRealVar sigma1("sigma1", "sigma1", 1,0.01,3.);
        RooRealVar sigma2("sigma2", "sigma2",2,0.01,2.5 );
        RooRealVar beta("beta", "beta", 0.8, 0.0, 1.);
        RooRealVar tau("tau", "tau" ,1.4,0.2,3);
        RooGaussModel res1("res1", "resolution model 1 for tz", tz, bias, sigma1, one, tzError);
        RooGaussModel res2("res2", "resolution model 2 for tz", tz, bias, sigma2, one, tzError);
        RooAddModel res("res", "resolution model for tz", RooArgList(res1, res2), RooArgList(beta));
        RooDecay tzDelta("tzDelta", "tz delta function for tz", tz, zero, res, RooDecay::DoubleSided);
        RooDecay tzP("tzP", "tz decay function P for tz", tz, tau, res, RooDecay::SingleSided);
        RooHistPdf tzTail("tzTail", "tz tail for tz", tz, *tail_hist);
        RooRealVar Nprompt("Nprompt", "Nprompt", 0.21*N, 0, N);
        RooRealVar Nfromb("Nfromb", "Nfromb", 0.05*N, 0, N);
        RooRealVar Ntail("Ntail", "Ntail", 0.001*N, 0., 0.1*N);
        RooRealVar Nbkg("Nbkg", "Nbkg", 0.8*N, 0, 1.1*N);

        RooProdPdf prompt("prompt", "pdf prompt", RooArgList(mass_signal, tzDelta));
        RooProdPdf fromb("fromb", "pdf fromb", RooArgList(mass_signal, tzP));
        RooProdPdf tail("tail", "pdf tail", RooArgList(mass_signal, tzTail));
        RooProdPdf bkg("bkg", "pdf bkg", RooArgList(mass_bkg, tzbkg_tzPDF));
        RooAddPdf tzPDF("tzPDF", "pdf tz", RooArgList(prompt, fromb, bkg, tail), RooArgList(Nprompt, Nfromb, Nbkg, Ntail));
        if (0)
	{
                beta.setVal(0);
                beta.setConstant(true);
                sigma1.setConstant(true);
        }
        if (0) {
                Ntail.setVal(0);
                Ntail.setConstant(true);
        }

        tzPDF.fitTo(data_set, Minos(true), Strategy(2), NumCPU(40), Save(false), ConditionalObservables(tzError));
        data_set.Write();
        tzPDF.Write();
        root_file->Close();

        ofstream fout(argv[5]);
        fout << "bias = " << bias.getVal() << endl;
        fout << "biasError = " << bias.getError() << endl;
        fout << "sigma1 = " << sigma1.getVal() << endl;
        fout << "sigma1Error = " << sigma1.getError() << endl;
        fout << "sigma2 = " << sigma2.getVal() << endl;
        fout << "sigma2Error = " << sigma2.getError() << endl;
        fout << "beta = " << beta.getVal() << endl;
	fout << "betaError = " << beta.getError() << endl;
        fout << "tau = " << tau.getVal() << endl;
        fout << "tauError = " << tau.getError() << endl;
        fout << "Nprompt = " << Nprompt.getVal() << endl;
        fout << "NpromptError = " << Nprompt.getError() << endl;
        fout << "Nfromb = " << Nfromb.getVal() << endl;
        fout << "NfrombError = " << Nfromb.getError() << endl;
        fout << "Ntail = " << Ntail.getVal() << endl;
        fout << "NtailError = " << Ntail.getError() << endl;
        fout << "Nbkg = " << Nbkg.getVal() << endl;
        fout << "NbkgError = " << Nbkg.getError() << endl;
        fout.close();

	ofstream txtout(argv[8]);
	txtout << bias.getVal() << endl;
        txtout << bias.getError() << endl;
        txtout << sigma1.getVal() << endl;
        txtout << sigma1.getError() << endl;
        txtout << sigma2.getVal() << endl;
        txtout << sigma2.getError() << endl;
        txtout << beta.getVal() << endl;
        txtout << beta.getError() << endl;
        txtout << tau.getVal() << endl;
        txtout << tau.getError() << endl;
        txtout << Nprompt.getVal() << endl;
        txtout << Nprompt.getError() << endl;
        txtout << Nfromb.getVal() << endl;
        txtout << Nfromb.getError() << endl;
        txtout << Ntail.getVal() << endl;
        txtout << Ntail.getError() << endl;
        txtout << Nbkg.getVal() << endl;
        txtout << Nbkg.getError() << endl;
        txtout.close();


        TFile* splot_file = new TFile(argv[6], "recreate");
        RooStats::SPlot* splot = new RooStats::SPlot("splot", "splot", data_set, &tzPDF, RooArgList(Nprompt, Nfromb, Nbkg, Ntail));
        TTree* result = data_tree->CloneTree(0);
        double prompt_sw, fromb_sw, tail_sw, bkg_sw;
        result->Branch("prompt_sw", &prompt_sw, "prompt_sw/D");
        result->Branch("fromb_sw", &fromb_sw, "fromb_sw/D");
        result->Branch("bkg_sw", &bkg_sw, "bkg_sw/D");
        for (int i = 0; i < N; i++) {
                data_tree->GetEntry(i);
                prompt_sw = ((RooRealVar*)(data_set.get(i)->find("Nprompt_sw")))->getVal();
                fromb_sw = ((RooRealVar*)(data_set.get(i)->find("Nfromb_sw")))->getVal();
                bkg_sw = ((RooRealVar*)(data_set.get(i)->find("Nbkg_sw")))->getVal();
                result->Fill();
        }
        result->Write();
        splot_file->Close();

        return 0;
}

