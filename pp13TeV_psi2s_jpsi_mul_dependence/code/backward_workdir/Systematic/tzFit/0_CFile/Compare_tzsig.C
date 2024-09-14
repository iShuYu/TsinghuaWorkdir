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
        setLHCbStyle();
	TFile *input = TFile::Open(argv[1]);
        TFile *output = new TFile(argv[2], "recreate");
	TH2D *Tb = (TH2D*)input->Get("h_eff");
	TH2D *Tp = (TH2D*)Tb->Clone(0);
        int npt = Tb->GetNbinsX();
        int ny = Tb->GetNbinsY();
        int N;
        sscanf(argv[3],"%d",&N);
	double NJp, NJb, NPp, NPb, rNJp, rNJb, rNPp, rNPb;
        for(int y=1;y<=ny;y++)
        {
                for(int pt=1;pt<=npt;pt++)
                {
			//input original result
			ifstream fitJ(Form("../3_Result/Jpsi/tzsig/n%dy%dpt%d.txt",N,y,pt));
			ifstream fitP(Form("../3_Result/Psi2S/tzsig/n%dy%dpt%d.txt",N,y,pt));
			ifstream realJ(Form("../3_Result/realNum/Jpsi/n%dy%dpt%d.txt",N,y,pt));
			ifstream realP(Form("../3_Result/realNum/Psi2S/n%dy%dpt%d.txt",N,y,pt));
			for(int i=1;i<=11;i++)
			{
				fitJ>>NJp;
				fitP>>NPp;
			}
			for(int i=1;i<=2;i++)
			{
				fitJ>>NJb;
				fitP>>NPb;
			}
			realJ>>rNJp;
			realJ>>rNJb;
			realP>>rNPp;
			realP>>rNPb;
			//cout << NJb << NPb << rNJb << rNPb << endl;
			//cout << NJp << NPp << rNJp << rNPp << endl;
			Tp->SetBinContent(pt,y,((NPp/NJp)-(rNPp/rNJp))/(rNPp/rNJp));
			Tp->SetBinError(pt,y,0);
			Tb->SetBinContent(pt,y,((NPb/NJb)-(rNPb/rNJb))/(rNPb/rNJb));
                        Tb->SetBinError(pt,y,0);
		}
	}
	Tp->Write("Errp");
	Tb->Write("Errb");
	output->Close();
	return 0;
}
