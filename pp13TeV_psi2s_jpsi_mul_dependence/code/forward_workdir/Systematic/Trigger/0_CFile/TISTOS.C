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
        ofstream err("../3_Result/TriggerErr/err.txt");
	TFile *input;
	TH2D *TTMCJ;
	TH2D *TTMCP;
	for(int N=1;N<=5;N++)
	{
		int NN = N;
		if(N==1||N==2) NN=12;
		ifstream Jtis(Form("../3_Result/Jpsi/n%dTIS.txt",NN));
		ifstream Jtistos(Form("../3_Result/Jpsi/n%dTISTOS.txt",NN));
		ifstream Ptis(Form("../3_Result/Psi2S/n%dTIS.txt",NN));
                ifstream Ptistos(Form("../3_Result/Psi2S/n%dTISTOS.txt",NN));
		double a1,b1,a2,b2;
		Jtistos>>a1;
		Jtis>>b1;
		Ptistos>>a2;
                Ptis>>b2;
		input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_trigger/n%dtotal_for_triggerErr.root",NN));
		TTMCJ = (TH2D*) input -> Get("h_eff");
		double c1=TTMCJ->GetBinContent(1,1);
		input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_trigger/n%dtotal_for_triggerErr.root",NN));
		TTMCP = (TH2D*) input -> Get("h_eff");
		double c2=TTMCP->GetBinContent(1,1);
		cout << "JTIS: " << b1 << endl;
		cout << "JTOS: " << a1 << endl;
		cout << "Jeff_tistos = " << a1 << "/" << b1 << "=" << a1/b1 << endl;	
		cout << "MC_eff_J = " << c1 << endl;
		cout << "PTIS: " << b2 << endl;
		cout << "PTOS: " << a2 << endl;
		cout << "Jeff_tistos = " << a2 << "/" << b2 << "=" << a2/b2 << endl;
		cout << "MC_eff_P = " << c2 << endl;
		err << (c1/c2-(a1/b1/a2*b2))/(c1/c2) << endl;
	}
	err.close();
	return 0;
}



