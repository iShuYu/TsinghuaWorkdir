#include <TCanvas.h>
#include <TAxis.h>
#include <fstream>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TString.h>
#include "lhcbStyle.h"
using namespace std;
int main(int argc, char* argv[])
{
	gStyle->SetPaintTextFormat(".2f");
	//TFile *out = new TFile(argv[4],"recreate");
	TFile SampleErr(argv[1]);
	TH2D *SE = (TH2D*)SampleErr.Get(argv[2]);
	TFile AllErr(argv[3]);
	TH2D *AE;
	AE = (TH2D*)AllErr.Get(argv[4]);
	int Nx = SE->GetNbinsX();
	int Ny = SE->GetNbinsY();
	//TFile *out = new TFile(argv[4],"recreate");
	TH2D *Tout = (TH2D*)SE->Clone("StatsErr2AllErr");
	for(int i=1;i<=Nx;i++)
	{
		for(int j=1;j<=Ny;j++)
		{
			Tout->SetBinError(i,j,0);
			Tout->SetBinContent(i,j,SE->GetBinError(i,j)/SE->GetBinContent(i,j)/AE->GetBinContent(i,j));
		}
	}
	TCanvas *can = new TCanvas("can","can",800,600);
	Tout->SetStats(0);
	Tout->SetTitle("");
	Tout->Draw("text colz");
	can->SaveAs(argv[5]);
	return 0;
}
			
