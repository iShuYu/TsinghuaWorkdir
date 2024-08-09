#include <TAxis.h>
#include <fstream>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include "lhcbStyle.h"
int main()
{ 
	setLHCbStyle();
	TFile *input  = TFile::Open("./Ratio_Long_P-ETA_2016_25ns.root");
	TH2D *T = (TH2D*)input->Get("Ratio");
	TCanvas *can = new TCanvas("can","can",800,600);
	//setLHCbStyle();	
	T->SetStats(0);
	gStyle->SetPaintTextFormat(".3f");
	can->SetLogx();
	T->Draw("colz e text");
	can->SaveAs("./TrackCalib.pdf");
	return 0;
}

