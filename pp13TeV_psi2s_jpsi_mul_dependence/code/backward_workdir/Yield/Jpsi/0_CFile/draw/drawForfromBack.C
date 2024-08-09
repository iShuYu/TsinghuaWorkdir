#define CBSplotDecayTree_cxx
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>
#include <TStyle.h>
#include <TSystem.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <RooFit.h>
#include <RooPlot.h>
#include <RooHist.h>
#include <RooHistPdf.h>
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooGaussModel.h>
#include <RooAddModel.h>
#include <RooAddPdf.h>
#include <RooDecay.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../header/lhcbStyle.h"
#include "../header/CBSplotDecayTree.h"
using namespace std;
using namespace RooFit;

int main(int argc, char* argv[])
{
	setLHCbStyle();
	int bin[6] = {0,8,15,22,30,80};
	TChain *t[5];
	TH1D *th[5];
	TCanvas *can =  new TCanvas("can","can",1200,800);
	TLegend *leg = new TLegend(0.6,0.5,0.9,0.9);
	for(int n=0;n<5;n++){
		t[n] = new TChain("DecayTree");
		th[n] = new TH1D(Form("th%d",n+1),Form("th%d",n+1),150,0,150);
		for(int j=1;j<=3;j++){
			for(int k=1;k<=5;k++){
				t[n]->Add(Form("../../3_Result/2DFit/splot_n%dy%dpt%d.root",n+1,j,k));
			}
		}
		CBSplotDecayTree T(t[n]);
		int N = t[n]->GetEntries();
		for(int i=0;i<N;i++){
			t[n] -> GetEntry(i);
			th[n] -> Fill(T.psi_nForWardTracks,T.prompt_sw);
		}
		th[n] -> Scale(1.0/th[n]->Integral());
		th[n] -> SetStats(0);
		th[n] -> SetMarkerColor(n+1);
		th[n] -> GetXaxis() -> SetTitle("nForwardTracks");
		th[n] -> GetYaxis() -> SetTitle("Normalized");
		if(n==0) th[n] -> Draw();
		if(n!=0) th[n] -> Draw("same");
		leg -> AddEntry(th[n], Form("%d<=nBackTracks<%d",bin[n],bin[n+1]));
	}
	leg -> Draw("same");
	can -> SaveAs("../../3_Result/reweight/ForOfBack.pdf");
	can -> Close();
	return 0;
}
