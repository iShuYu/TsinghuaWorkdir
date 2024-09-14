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
int main(int argc, char *argv[])
{
        gROOT->SetBatch(true);
        setLHCbStyle();
        gStyle->SetPalette(55);
        gStyle->SetPaintTextFormat("4.3f");
        int N;
	//sscanf(argv[1],"%d",&N);
	//input
        TFile *input;
        input = TFile::Open(argv[1]);
        TH2D *TTMCJ_merged = (TH2D*)input->Get("h_eff");
	input = TFile::Open(argv[2]);
	TH2D *TTMCP_merged = (TH2D*)input->Get("h_eff");
	input = TFile::Open(argv[4]);
	TH2D *Temp = (TH2D*)input->Get("h_eff");
	TH2D *TTMCJ = (TH2D*)Temp->Clone("TTMCJ");
        TH2D *TTMCP = (TH2D*)Temp->Clone("TTMCP");
	TH2D *TTDTJ = (TH2D*)Temp->Clone("TTDTJ");
	TH2D *TTDTP = (TH2D*)Temp->Clone("TTDTP");
	TH2D *ErrJ = (TH2D*)Temp->Clone("ErrJ");
	TH2D *ErrP = (TH2D*)Temp->Clone("ErrP");
	int npt = ErrJ->GetNbinsX();
	int ny = ErrJ->GetNbinsY();
	//output
	TFile *out = new TFile(argv[3],"recreate");
	TH2D *Err = (TH2D*)TTMCP_merged->Clone("Err");
	TH2D *ErrTemp = (TH2D*)TTDTP->Clone("ErrTemp");
	//fill value for X and Y
        for(int pt=1;pt<=npt;pt++)
        {
		for(int y=1;y<=ny;y++)
		{
		int p=pt;
		//if(pt==1||pt==2) p=12; 
		ifstream Jtis(Form("../3_Result/Jpsi/pt%dTIS.txt",p));
		ifstream Jtistos(Form("../3_Result/Jpsi/pt%dTISTOS.txt",p));
		ifstream Ptis(Form("../3_Result/Psi2S/pt%dTIS.txt",p));
                ifstream Ptistos(Form("../3_Result/Psi2S/pt%dTISTOS.txt",p));
		double a1,b1,a2,b2;
		Jtistos>>a1;
		Jtis>>b1;
		Ptistos>>a2;
                Ptis>>b2;
		//p = pt-1;
		//if(pt==1||pt==2) p=1;
		double c1=TTMCJ_merged->GetBinContent(p,1);
		double c2=TTMCP_merged->GetBinContent(p,1);
		TTMCJ -> SetBinContent(pt,y,c1);
		TTMCP -> SetBinContent(pt,y,c2);
		TTDTJ -> SetBinContent(pt,y,a1/b1);
		TTDTP -> SetBinContent(pt,y,a2/b2);
		ErrJ->SetBinContent(pt,y,(a1/b1-c1)/c1);
		ErrP->SetBinContent(pt,y,(a2/b2-c2)/c2);
		Err->SetBinContent(p,y,((a1/b1)/(a2/b2)-c1/c2)/(c1/c2));
		ErrTemp->SetBinContent(pt,y,((a1/b1)/(a2/b2)-c1/c2)/(c1/c2));
		}
	}
	ErrJ->Write("ErrJ");
	ErrP->Write("ErrP");
	TTMCJ->Write("TTMCJ");
	TTMCP->Write("TTMCP");
	TTDTJ->Write("TTDTJ");
        TTDTP->Write("TTDTP");
	Err->Write("Err");
	ErrTemp->Write("ErrTemp");
	out->Close();
	return 0;
}



