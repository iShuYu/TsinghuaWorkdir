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
	int Type=1;
	ofstream Out("../3_Result/InBinVar/IntNYtoPT.txt");
	for(int pt=0;pt<5;pt++)
	{
	double Sum_SigJ = 0;
        double Sum_SigP = 0;
        double Sum1_SigJ = 0;
        double Sum1_SigP = 0;
        double Sum2_SigJ = 0;
        double Sum2_SigP = 0;
	double JN, PN, JNp, JNb, PNp,PNb;
	for(int y=0;y<3;y++)
	{
		for(int N=1;N<=5;N++)                
		{
			TFile *input;

	input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_pid/n%d_prompt.root",N));
	TH2D *T1 = (TH2D*)input->Get("h_eff");
	input = TFile::Open(Form("../3_Result/InBinVar/Jpsi/n%d_prompt1.root",N));
        TH2D *T2 = (TH2D*)input->Get("h_eff");
	input = TFile::Open(Form("../3_Result/InBinVar/Jpsi/n%d_prompt2.root",N));
        TH2D *T3 = (TH2D*)input->Get("h_eff");
	input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_pid/n%d_prompt.root",N));
        TH2D *T4 = (TH2D*)input->Get("h_eff");
        input = TFile::Open(Form("../3_Result/InBinVar/Psi2S/n%d_prompt1.root",N));
        TH2D *T5 = (TH2D*)input->Get("h_eff");
        input = TFile::Open(Form("../3_Result/InBinVar/Psi2S/n%d_prompt2.root",N));
        TH2D *T6 = (TH2D*)input->Get("h_eff");

	input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_prompt.root"));
	TH2D *TJacc = (TH2D*)input->Get("h_eff");
	input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_rec_sel/n%d_prompt.root",N));
        TH2D *TJrec = (TH2D*)input->Get("h_eff");
	input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_trigger/n%d_prompt.root",N));
        TH2D *TJtri = (TH2D*)input->Get("h_eff");
	input = TFile::Open("../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_prompt.root");
        TH2D *TPacc = (TH2D*)input->Get("h_eff");
        input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_rec_sel/n%d_prompt.root",N));
        TH2D *TPrec = (TH2D*)input->Get("h_eff");
        input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_trigger/n%d_prompt.root",N));
        TH2D *TPtri = (TH2D*)input->Get("h_eff");

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
	Out << myMax((b-a)/a,(c-a)/a)<<endl;
	}
	Out.close();
	return 0;
}

	
