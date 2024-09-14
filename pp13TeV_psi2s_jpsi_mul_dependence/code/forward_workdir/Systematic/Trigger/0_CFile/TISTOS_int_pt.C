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
        int N, Type;
	sscanf(argv[3],"%d",&N);
	sscanf(argv[4],"%d",&Type);
	//input
        TFile *input;
	input = TFile::Open(argv[1]);
        TH2D *TTMCJ = (TH2D*)input->Get("TTMCJ");
	TH2D *TTMCP = (TH2D*)input->Get("TTMCP");
	TH2D *TTDTJ = (TH2D*)input->Get("TTDTJ");
	TH2D *TTDTP = (TH2D*)input->Get("TTDTP");
	int npt = TTMCJ->GetNbinsX();
	int ny = TTMCJ->GetNbinsY();
	
	//input other efficiencies
	TH2D *Taccj;
	TH2D *Trecj;
	TH2D *Tpidj;
	TH2D *Taccp;
        TH2D *Trecp;
        TH2D *Tpidp;
	if(Type==1)
	{
		input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_prompt.root"));
		Taccj = (TH2D*)input->Get("h_eff");
		input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_prompt.root"));
		Taccp = (TH2D*)input->Get("h_eff");
		input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_rec_sel/n%d_prompt.root",N));
		Trecj = (TH2D*)input->Get("h_eff");
		input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_rec_sel/n%d_prompt.root",N));
		Trecp = (TH2D*)input->Get("h_eff");
		input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_pid/n%d_prompt.root",N));
		Tpidj = (TH2D*)input->Get("h_eff");
		input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_pid/n%d_prompt.root",N));
                Tpidp = (TH2D*)input->Get("h_eff");
	}
	if(Type==2)
        {
                input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_fromb.root"));
                Taccj = (TH2D*)input->Get("h_eff");
                input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_fromb.root"));
                Taccp = (TH2D*)input->Get("h_eff");
                input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_rec_sel/n%d_fromb.root",N));
                Trecj = (TH2D*)input->Get("h_eff");
                input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_rec_sel/n%d_fromb.root",N));
                Trecp = (TH2D*)input->Get("h_eff");
                input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_pid/n%d_fromb.root",N));
                Tpidj = (TH2D*)input->Get("h_eff");
                input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_pid/n%d_fromb.root",N));
                Tpidp = (TH2D*)input->Get("h_eff");
        }
	if(Type==3)
        {
                input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_total.root"));
                Taccj = (TH2D*)input->Get("h_eff");
                input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_total.root"));
                Taccp = (TH2D*)input->Get("h_eff");
                input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_rec_sel/n%d_total.root",N));
                Trecj = (TH2D*)input->Get("h_eff");
                input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_rec_sel/n%d_total.root",N));
                Trecp = (TH2D*)input->Get("h_eff");
                input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_pid/n%d_total.root",N));
                Tpidj = (TH2D*)input->Get("h_eff");
                input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_pid/n%d_total.root",N));
                Tpidp = (TH2D*)input->Get("h_eff");
        }
	//output
	TFile *out = new TFile(argv[2],"recreate");
	TH1D *ErrTemp = (TH1D*)TTDTJ->ProjectionX();
	//fill value for X and Y
        for(int pt=1;pt<=npt;pt++)
        {
		double Sum_SigJ = 0;
                double Sum_SigP = 0;
		double Sum_MSigJ = 0;
                double Sum_MSigP = 0;
		for(int y=1;y<=ny;y++)
		{
			//c for eff TISTOS MC
			//d for eff TISTOS data
			double c1=TTMCJ->GetBinContent(pt,y);
			double c2=TTMCP->GetBinContent(pt,y);
			double d1=TTDTJ->GetBinContent(pt,y);
			double d2=TTDTP->GetBinContent(pt,y);
			//input Yields
			ifstream YJ(Form("../../../Yield/Jpsi/3_Result/2DFit/txt_n%dy%dpt%d.txt",N,y,pt));
                	ifstream YP(Form("../../../Yield/Psi2S/3_Result/2DFit/txt_n%dy%dpt%d.txt",N,y,pt));
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
			Sum_SigJ = Sum_SigJ+JN/Taccj->GetBinContent(pt,y)/Trecj->GetBinContent(pt,y)/Tpidj->GetBinContent(pt,y)/d1;
			Sum_SigP = Sum_SigP+PN/Taccp->GetBinContent(pt,y)/Trecp->GetBinContent(pt,y)/Tpidp->GetBinContent(pt,y)/d2;
			Sum_MSigJ = Sum_MSigJ+JN/Taccj->GetBinContent(pt,y)/Trecj->GetBinContent(pt,y)/Tpidj->GetBinContent(pt,y)/c1;
                	Sum_MSigP = Sum_MSigP+PN/Taccp->GetBinContent(pt,y)/Trecp->GetBinContent(pt,y)/Tpidp->GetBinContent(pt,y)/c2;
		}
		ErrTemp -> SetBinContent(pt,(Sum_SigP/Sum_SigJ-Sum_MSigP/Sum_MSigJ)/(Sum_MSigP/Sum_MSigJ));
	}
	ErrTemp->Write("ErrTemp");
	out->Close();
	return 0;
}



