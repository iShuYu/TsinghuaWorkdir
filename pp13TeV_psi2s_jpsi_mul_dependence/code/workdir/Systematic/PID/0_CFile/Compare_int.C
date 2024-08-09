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
	
	//Other efficiency
	input = TFile::Open(argv[8]);
	TH2D *TJacc = (TH2D*)input->Get("h_eff");
	input = TFile::Open(argv[9]);
        TH2D *TJrec = (TH2D*)input->Get("h_eff");
	input = TFile::Open(argv[10]);
        TH2D *TJtri = (TH2D*)input->Get("h_eff");
	input = TFile::Open(argv[11]);
        TH2D *TPacc = (TH2D*)input->Get("h_eff");
        input = TFile::Open(argv[12]);
        TH2D *TPrec = (TH2D*)input->Get("h_eff");
        input = TFile::Open(argv[13]);
        TH2D *TPtri = (TH2D*)input->Get("h_eff");
	int Type, N;
	sscanf(argv[14],"%d",&N);
	sscanf(argv[15],"%d",&Type);
	
	//Scheme
	int npt = T1->GetNbinsX();
	int ny = T1->GetNbinsY();
	//TFile *Out = new TFile(argv[7],"recreate");
	//TH2D *InBinErr2 = (TH2D*)T1->Clone(0);
	//TH1D *InBinErr = (TH1D*)InBinErr2->ProjectionY();
	ofstream Out(argv[7]);
	double Sum_SigJ = 0;
        double Sum_SigP = 0;
        double Sum1_SigJ = 0;
        double Sum1_SigP = 0;
        double Sum2_SigJ = 0;
        double Sum2_SigP = 0;
	double JN, PN, JNp, JNb, PNp,PNb;
	for(int y=0;y<ny;y++)
        //for(int pt=0;pt<npt;pt++)
	{
                for(int pt=0;pt<npt;pt++)
                //for(int y=0;y<ny;y++)
		{
			ifstream YJ(Form("../../../Yield/Jpsi/3_Result/2DFit/txt_n%dy%dpt%d.txt",N,y+1,pt+1));
                        ifstream YP(Form("../../../Yield/Psi2S/3_Result/2DFit/txt_n%dy%dpt%d.txt",N,y+1,pt+1));
                        for(int index=1;index<=11;index++)
                        {
                                YJ>>JNp;
                                YP>>PNp;
                        }
                        for(int index=1;index<=2;index++)
                        {
                                YJ>>JNb;
                                YP>>PNb;
                        }
                        if(Type==1)
                        {
                                JN = JNp;
                                PN = PNp;
                        }
                        if(Type==2)
                        {
                                JN = JNb;
                                PN = PNb;
                        }
                        if(Type==3)
                        {
                                JN = JNp+JNb;
                                PN = PNp+PNb;
                        }
			Sum_SigJ = Sum_SigJ + JN/TJacc->GetBinContent(pt+1,y+1)/TJrec->GetBinContent(pt+1,y+1)/TJtri->GetBinContent(pt+1,y+1)/T1->GetBinContent(pt+1,y+1);
			Sum1_SigJ = Sum1_SigJ + JN/TJacc->GetBinContent(pt+1,y+1)/TJrec->GetBinContent(pt+1,y+1)/TJtri->GetBinContent(pt+1,y+1)/T2->GetBinContent(pt+1,y+1);
			Sum2_SigJ = Sum2_SigJ + JN/TJacc->GetBinContent(pt+1,y+1)/TJrec->GetBinContent(pt+1,y+1)/TJtri->GetBinContent(pt+1,y+1)/T3->GetBinContent(pt+1,y+1);
			Sum_SigP = Sum_SigP + PN/TPacc->GetBinContent(pt+1,y+1)/TPrec->GetBinContent(pt+1,y+1)/TPtri->GetBinContent(pt+1,y+1)/T4->GetBinContent(pt+1,y+1);
                	Sum1_SigP = Sum1_SigP + PN/TPacc->GetBinContent(pt+1,y+1)/TPrec->GetBinContent(pt+1,y+1)/TPtri->GetBinContent(pt+1,y+1)/T5->GetBinContent(pt+1,y+1);
                	Sum2_SigP = Sum2_SigP + PN/TPacc->GetBinContent(pt+1,y+1)/TPrec->GetBinContent(pt+1,y+1)/TPtri->GetBinContent(pt+1,y+1)/T6->GetBinContent(pt+1,y+1);
		}
	}
	double a = Sum_SigP/Sum_SigJ;
	double b = Sum1_SigP/Sum1_SigJ;
	double c = Sum2_SigP/Sum2_SigJ;
	Out << myMax((b-a)/a,(c-a)/a);
	Out.close();
	return 0;
}

	
