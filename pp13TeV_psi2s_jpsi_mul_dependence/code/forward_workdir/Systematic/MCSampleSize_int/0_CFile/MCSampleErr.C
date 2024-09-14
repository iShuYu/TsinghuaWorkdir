#include <fstream>
#include <RooFormulaVar.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>
#include <TF1.h>
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
#include "../../../Yield/Jpsi/0_CFile/header/lhcbStyle.h"
using namespace std;
int main(int argc, char *argv[])
{
	//input total efficiency
	int N;
        sscanf(argv[1],"%d",&N);
	TFile *input;
	input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_tot/n%d_fromb.root",N));
	TH2D *Jeffb = (TH2D*)input->Get("h_3");
	input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_tot/n%d_prompt.root",N));
        TH2D *Jeffp = (TH2D*)input->Get("h_3");
	input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_tot/n%d_fromb.root",N));
        TH2D *Peffb = (TH2D*)input->Get("h_3");
        input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_tot/n%d_prompt.root",N));
        TH2D *Peffp = (TH2D*)input->Get("h_3");
	TFile *out = new TFile(Form("../3_Result/n%dMCSizeErr.root",N),"recreate");
	TH2D *Tb = (TH2D*)Peffb->Clone(0);
	int npt = Tb->GetNbinsX();
        int ny = Tb->GetNbinsY();
	TH2D *Tp = (TH2D*)Peffp->Clone(0);
	double Jberr, Pberr, Jb, Pb;
	double Jperr, Pperr, Jp, Pp;
	for(int y=1;y<=ny;y++)
        {
                for(int pt=1;pt<=npt;pt++)
                {
			Jp = Jeffp->GetBinContent(pt,y);
			Jperr = Jeffp->GetBinError(pt,y);
			Jb = Jeffb->GetBinContent(pt,y);
                        Jberr = Jeffb->GetBinError(pt,y);
			Pp = Peffp->GetBinContent(pt,y);
                        Pperr = Peffp->GetBinError(pt,y);
                        Pb = Peffb->GetBinContent(pt,y);
                        Pberr = Peffb->GetBinError(pt,y);
			Tb -> SetBinContent(pt,y,sqrt((Jberr/Jb)*(Jberr/Jb)+(Pberr/Pb)*(Pberr/Pb)));
			Tp -> SetBinContent(pt,y,sqrt((Jperr/Jp)*(Jperr/Jp)+(Pperr/Pp)*(Pperr/Pp)));
		}
	}
	Tb -> Write("Errb");
	Tp -> Write("Errp");
	out -> Close();
	return 0;
}
