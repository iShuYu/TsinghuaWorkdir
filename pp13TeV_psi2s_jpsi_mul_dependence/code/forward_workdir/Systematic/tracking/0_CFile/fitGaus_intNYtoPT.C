#include <fstream>
#include <RooFormulaVar.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>
#include <TF1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <RooFit.h>
#include <RooPlot.h>
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooAddPdf.h>
#include <RooCBShape.h>
#include <RooExponential.h>
#include <RooGaussian.h>
#include <string>
#include <RooStats/SPlot.h>
#include <vector>
#include "../../../Yield/Jpsi/0_CFile/header/lhcbStyle.h"
using namespace std;
using namespace RooFit;
int main(int argc, char *argv[])
{
        setLHCbStyle();
	TH1::SetDefaultSumw2();
	//input REC, PID, TRI tables
	TFile ACCJ("../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_prompt.root");
	TH2D *Taccj = (TH2D*)ACCJ.Get("h_eff");
	TFile ACCP("../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_prompt.root");
	TH2D *Taccp = (TH2D*)ACCP.Get("h_eff");	
	double Content[200];
	int Type=1;
	TFile *input1;
	TFile *input2;
	TFile *input3;
	TFile *input4;
	TFile *input5;
	TFile *input6;
	TH2D *T1;
	TH2D *T2;
	TH2D *T3;
	TH2D *T4;
	TH2D *T5;
	TH2D *T6;
	ofstream Out("../3_Result/StatsErr/IntNYtoPT.txt");

	for(int pt=0;pt<5;pt++)
	{
	for(int i=0;i<200;i++)
        {
		double Sum_SigJ = 0;
                double Sum_SigP = 0;
		for(int y=0;y<3;y++)
		{
			for(int N=1;N<=5;N++)                       	
			{
				input1 = TFile::Open(Form("../3_Result/toyEffRec/Jpsi/n%d_prompt_%d.root",N,i));
				input2 = TFile::Open(Form("../3_Result/toyEffPID/Jpsi/n%d_prompt_%d.root",N,i));
				input3 = TFile::Open(Form("../3_Result/toyEffTrigger/Jpsi/n%d_prompt_%d.root",N,i));
				input4 = TFile::Open(Form("../3_Result/toyEffRec/Psi2S/n%d_prompt_%d.root",N,i));
	 			input5 = TFile::Open(Form("../3_Result/toyEffPID/Psi2S/n%d_prompt_%d.root",N,i));
	                        input6 = TFile::Open(Form("../3_Result/toyEffTrigger/Psi2S/n%d_prompt_%d.root",N,i));
				T1 = (TH2D*)input1->Get("h_eff");
				T2 = (TH2D*)input2->Get("h_eff");
				T3 = (TH2D*)input3->Get("h_eff");
				T4 = (TH2D*)input4->Get("h_eff");
		                T5 = (TH2D*)input5->Get("h_eff");
		                T6 = (TH2D*)input6->Get("h_eff");
				

				ifstream YJ(Form("../../../Yield/Jpsi/3_Result/2DFit/txt_n%dy%dpt%d.txt",N,y+1,pt+1));
                                ifstream YP(Form("../../../Yield/Psi2S/3_Result/2DFit/txt_n%dy%dpt%d.txt",N,y+1,pt+1));
                                double JN, PN, JNp, JNb, PNp,PNb;
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
                                Sum_SigJ = Sum_SigJ + JN/Taccj->GetBinContent(pt+1,y+1)/T1->GetBinContent(pt+1,y+1)/T2->GetBinContent(pt+1,y+1)/T3->GetBinContent(pt+1,y+1);
				Sum_SigP = Sum_SigP + PN/Taccp->GetBinContent(pt+1,y+1)/T4->GetBinContent(pt+1,y+1)/T5->GetBinContent(pt+1,y+1)/T6->GetBinContent(pt+1,y+1);
	                        input1 -> Close();
				input2 -> Close();
				input3 -> Close();
				input4 -> Close();
				input5 -> Close();
				input6 -> Close();

			}
		}
		Content[i] = Sum_SigP/Sum_SigJ;
	}
	int num_bin = 15;
        double mean[1], std[1];
        TH1D *th[1];
        for(int y=0;y<1;y++)
        {
                mean[y]=0;
                for(int i=0;i<200;i++)
                {
                        mean[y]=mean[y]+Content[i];
                }
                mean[y]=mean[y]/200;
                std[y]=0;
                for(int i=0;i<200;i++)
                {
                        std[y]=std[y]+(Content[i]-mean[y])*(Content[i]-mean[y]);
                }
                std[y]=sqrt(std[y]/199);
                th[y] = new TH1D(Form("thy%d",y),Form("thy%d",y),num_bin,mean[y]-3*std[y],mean[y]+3*std[y]);
        }
	
        for(int y=0;y<1;y++)
        {
                for(int i=0;i<200;i++)
                {
                        th[y]->Fill(Content[i]);
                }
                    th[y]->SetLineColor(kRed);
                     th[y]->Fit("gaus");
                TF1 *g = (TF1*)th[y]->GetListOfFunctions()->FindObject("gaus");
                Out<<g->GetParameter(2)/g->GetParameter(1)<<endl;
		
        }
	}
	Out.close();
	return 0;
}



