#include <TAxis.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include "lhcbStyle.h"
#include <fstream>
#include <TF1.h>
using namespace std;
int main(int argc, char* argv[])
{
	setLHCbStyle();
	double c[5] = {-0.031,-0.029,0.015,-0.012,-0.013};
	double edge[6] = {0,2,4,6,8,20}; 
	TF1 *unit = new TF1("unit","0+x-x",0.,20.);
	unit -> SetLineStyle(2);
        unit -> SetLineColor(1);
	TH1D *t = new TH1D("t","t",5,edge);
	for(int i=1;i<=5;i++)
	{
		t->SetBinContent(i,c[i-1]);
		t->SetBinError(i,0);
	}
	t->SetStats(0);
	t->SetLineColor(kBlue);
	t->GetXaxis()->SetTitle("#font[12]{p}_{T}[GeV/#font[12]{c}]");
	t->GetYaxis()->SetTitle("Sys_{trigger}");
	t->GetYaxis()->SetRangeUser(-0.1,0.1);
	TCanvas *can = new TCanvas("can","can",1200,800);
	t->Draw();
	unit->Draw("same");
	can -> SaveAs("../4_Plot/SysTri_PT.pdf");
	can -> Close();
	return 0;
}


