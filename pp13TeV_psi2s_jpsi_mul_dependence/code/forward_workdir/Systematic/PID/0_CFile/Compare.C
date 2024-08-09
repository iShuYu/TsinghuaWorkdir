#include <TH2D.h>
#include <TFile.h>
#include <TROOT.h>
#include <iostream>
#include <fstream>
#include <TH2.h>
#include <TStyle.h>
#include <math.h>
#include <TAxis.h>
#include <TCanvas.h>
#include <TLegend.h>
#include "../../../Yield/Jpsi/0_CFile/header/lhcbStyle.h"
using namespace std;
double myMax(double a, double b)
{
	if(abs(a)>=abs(b)) return a;
	else return b;
}
int main(int argc, char *argv[])
{
	gROOT->SetBatch(true);
        setLHCbStyle();
        gStyle->SetPalette(55);
        gStyle->SetPaintTextFormat("4.3f");
	//input T123 for J, T456 for P, T1, T4 are original eff
	TFile *input;
	input = TFile::Open(argv[1]);
	TH2D *T1 = (TH2D*)input->Get("h_eff");
	input = TFile::Open(argv[2]);
        TH2D *T2 = (TH2D*)input->Get("h_eff");
	input = TFile::Open(argv[3]);
        TH2D *T3 = (TH2D*)input->Get("h_eff");
	input = TFile::Open(argv[4]);
        TH2D *T4 = (TH2D*)input->Get("h_eff");
        input = TFile::Open(argv[5]);
        TH2D *T5 = (TH2D*)input->Get("h_eff");
        input = TFile::Open(argv[6]);
        TH2D *T6 = (TH2D*)input->Get("h_eff");
	//Scheme
	int npt = T1->GetNbinsX();
	int ny = T1->GetNbinsY();
	TFile *Out = new TFile(argv[7],"recreate");
	TH2D *InBinErr = (TH2D*)T1->Clone(0);
	for(int y=0;y<ny;y++)
        {
                for(int pt=0;pt<npt;pt++)
                {
			double a = T2->GetBinContent(pt+1,y+1)/T5->GetBinContent(pt+1,y+1)-T1->GetBinContent(pt+1,y+1)/T4->GetBinContent(pt+1,y+1);
			double b = T3->GetBinContent(pt+1,y+1)/T6->GetBinContent(pt+1,y+1)-T1->GetBinContent(pt+1,y+1)/T4->GetBinContent(pt+1,y+1);
			InBinErr -> SetBinContent(pt+1,y+1,myMax(a,b)/(T1->GetBinContent(pt+1,y+1)/T4->GetBinContent(pt+1,y+1)));
		}
	}
	InBinErr -> Write();
	Out -> Close();
	return 0;
}

	
