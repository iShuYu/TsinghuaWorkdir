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
	ifstream input("../3_Result/TriggerErr/err.txt");
	double edge[6] = {4,20,45,70,95,200}; 
	TF1 *unit = new TF1("unit","0+x-x",4.,200.);
	unit -> SetLineStyle(2);
        unit -> SetLineColor(1);
	TH1D *t = new TH1D("t","t",5,edge);
	double err;
	for(int i=1;i<=5;i++)
	{
		input >> err;
		t->SetBinContent(i,err);
		t->SetBinError(i,0);
	}
	t->SetStats(0);
	t->SetLineColor(kRed);
	t->GetXaxis()->SetTitle("PVNTRACKS");
	t->GetYaxis()->SetTitle("Sys_{trigger}");
	t->GetYaxis()->SetRangeUser(-0.1,0.1);
	TCanvas *can = new TCanvas("can","can",1200,800);
	t->Draw();
	unit->Draw("same");
	can -> SaveAs("../4_Plot/SysTri_PVN.pdf");
	can -> Close();
	return 0;
}


