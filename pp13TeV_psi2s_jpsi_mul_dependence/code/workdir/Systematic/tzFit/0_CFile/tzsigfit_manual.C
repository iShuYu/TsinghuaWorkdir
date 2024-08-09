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
	//input MC
        TFile input_file(argv[1]);
        TTree* data_tree = (TTree*)input_file.Get("DecayTree");
	//input tail
        TFile tail_file(argv[2]);
        TTree* tail_tree = (TTree*)tail_file.Get("DecayTree");
        TFile* root_file = new TFile(argv[3], "recreate");
	//Variable and dataset
        RooRealVar tz("tz", "tz", -10, 10);
        RooRealVar tzError("tzError", "tzError", 0.001, 0.3);
        RooDataSet data_set("data_set", "data set", data_tree, RooArgSet(tz, tzError));
        RooDataSet tail_set("tail_set", "tail set", tail_tree, RooArgSet(tz));
        RooDataHist* tail_hist = tail_set.binnedClone("");
        double N = data_set.numEntries();
        //signal PDF
        RooRealVar zero("zero", "zero", 0);
        RooRealVar one("one", "one", 1);
        RooRealVar bias("bias", "bias", 0., -1., 1.);
        RooRealVar sigma1("sigma1", "sigma1", 1.4236,0.01,10.);
        RooRealVar sigma2("sigma2", "sigma2",0.6816,0.01,10. );
       	//set beta=0 for those only one gaussian function is set
	RooRealVar beta("beta", "beta", 0.5,0,1);
        RooRealVar tau("tau", "tau" ,1.3431,0.02,5);
        RooGaussModel res1("res1", "resolution model 1 for tz", tz, bias, sigma1, one, tzError);
        RooGaussModel res2("res2", "resolution model 2 for tz", tz, bias, sigma2, one, tzError);
        RooAddModel res("res", "resolution model for tz", RooArgList(res1, res2), RooArgList(beta));
        RooDecay tzDelta("tzDelta", "tz delta function for tz", tz, zero, res, RooDecay::DoubleSided);
        RooDecay tzP("tzP", "tz decay function P for tz", tz, tau, res, RooDecay::SingleSided);
        RooHistPdf tzTail("tzTail", "tz tail for tz", tz, *tail_hist);
        RooRealVar Nprompt("Nprompt", "Nprompt", 0.45*N, 0, N);
        RooRealVar Nfromb("Nfromb", "Nfromb", 0.3*N, 0, N);
	RooRealVar Ntail("Ntail", "Ntail", 0.01*N, 0, 0.3*N);
        RooAddPdf tzPDF("tzPDF", "pdf tz", RooArgList(tzDelta, tzP), RooArgList(Nprompt, Nfromb));

        tzPDF.fitTo(data_set, Minos(true), Strategy(2), NumCPU(20), Save(false), ConditionalObservables(tzError));
        data_set.Write();
        tzPDF.Write();
        root_file->Close();

        ofstream fout(argv[4]);
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
        fout.close();

	ofstream txtout(argv[5]);
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
        txtout.close();
        return 0;
}

