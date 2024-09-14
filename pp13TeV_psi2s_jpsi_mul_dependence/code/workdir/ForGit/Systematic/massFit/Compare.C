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
using namespace RooFit;
int main(int argc, char *argv[])
{
        setLHCbStyle();
	//template
	TFile *input = TFile::Open(argv[1]);
	TH2D *T = (TH2D*)input->Get("h_eff");
	int npt = T->GetNbinsX();
	int ny = T->GetNbinsY();
	int N;
        sscanf(argv[2],"%d",&N);
	for(int y=1;y<=ny;y++)
        {
                for(int pt=1;pt<=npt;pt++)
                {
			ifstream J(Form("../../../Yield/Jpsi/3_Result/CBFit/n%dy%dpt%d.txt",N,y,pt));
			ifstream P(Form("../../../Yield/Psi2S/3_Result/CBFit/n%dy%dpt%d.txt",N,y,pt));
			ifstream MJ(Form("../3_Result/Jpsi/n%dy%dpt%d.txt",N,y,pt));
			ifstream MP(Form("../3_Result/Psi2S/n%dy%dpt%d.txt",N,y,pt));
			double sigJ, sigP, MsigJ, MsigP;
			J >> sigJ;
			P >> sigP;
			MJ >> MsigJ;
			MP >> MsigP;
			T->SetBinContent(pt,y,(MsigP/MsigJ-sigP/sigJ)/(sigP/sigJ));
			T->SetBinError(pt,y,0);
		}
	}
	TFile *out = new TFile(Form("../3_Result/massFitErr/n%dErr.root",N),"recreate");
	T->Write();
	out->Close();
	return 0;
}
