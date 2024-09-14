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
int main(int argc, char *argv[])
{ 
	ofstream output("../3_Result/Error/INTErr.txt");
	double Sum_SigJp = 0;
        double Sum_SigPp = 0;
        double Sum_rSigJp = 0;
        double Sum_rSigPp = 0;
        double Sum_SigJb = 0;
        double Sum_SigPb = 0;
        double Sum_rSigJb = 0;
	double Sum_rSigPb = 0;
	double NJp, NJb, NPp, NPb, rNJp, rNJb, rNPp, rNPb;
        TFile *input;
	for(int N=1;N<=5;N++){
       	input = TFile::Open("../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_prompt.root");
        TH2D *Taccjp = (TH2D*)input->Get("h_eff");
        input = TFile::Open("../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_prompt.root");
        TH2D *Taccpp = (TH2D*)input->Get("h_eff");
        input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_rec_sel/n%d_prompt.root",N));
        TH2D *Trecjp = (TH2D*)input->Get("h_eff");
        input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_rec_sel/n%d_prompt.root",N));
        TH2D *Trecpp = (TH2D*)input->Get("h_eff");
        input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_pid/n%d_prompt.root",N));
        TH2D *Tpidjp = (TH2D*)input->Get("h_eff");
        input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_pid/n%d_prompt.root",N));
        TH2D *Tpidpp = (TH2D*)input->Get("h_eff");
        input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_trigger/n%d_prompt.root",N));
        TH2D *Ttrijp = (TH2D*)input->Get("h_eff");
        input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_trigger/n%d_prompt.root",N));
        TH2D *Ttripp = (TH2D*)input->Get("h_eff");
        input = TFile::Open("../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_fromb.root");
        TH2D *Taccjb = (TH2D*)input->Get("h_eff");
        input = TFile::Open("../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_fromb.root");
        TH2D *Taccpb = (TH2D*)input->Get("h_eff");
        input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_rec_sel/n%d_fromb.root",N));
        TH2D *Trecjb = (TH2D*)input->Get("h_eff");
        input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_rec_sel/n%d_fromb.root",N));
        TH2D *Trecpb = (TH2D*)input->Get("h_eff");
        input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_pid/n%d_fromb.root",N));
        TH2D *Tpidjb = (TH2D*)input->Get("h_eff");
        input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_pid/n%d_fromb.root",N));
        TH2D *Tpidpb = (TH2D*)input->Get("h_eff");
        input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_trigger/n%d_fromb.root",N));
        TH2D *Ttrijb = (TH2D*)input->Get("h_eff");
        input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_trigger/n%d_fromb.root",N));
        TH2D *Ttripb = (TH2D*)input->Get("h_eff");
        TH2D *Tb1 = (TH2D*)input->Get("h_eff");
        TH2D *Tp1 = (TH2D*)Tb1->Clone(0);
        int npt = Tb1->GetNbinsX();
        int ny = Tb1->GetNbinsY();
		for(int y=1;y<=ny;y++)
	{
                //for(int y=1;y<=ny;y++)
		for(int pt=1;pt<=npt;pt++)
                {
			//input original result
			ifstream fitJ(Form("../3_Result/Jpsi/2DFit/n%dy%dpt%d.txt",N,y,pt));
			ifstream fitP(Form("../3_Result/Psi2S/2DFit/n%dy%dpt%d.txt",N,y,pt));
			ifstream oldFitJ(Form("../../../Yield/Jpsi/3_Result/2DFit/txt_n%dy%dpt%d.txt",N,y,pt));
			ifstream oldFitP(Form("../../../Yield/Psi2S/3_Result/2DFit/txt_n%dy%dpt%d.txt",N,y,pt));
			for(int i=1;i<=11;i++)
			{
				fitJ>>NJp;
				fitP>>NPp;
				oldFitJ>>rNJp;
				oldFitP>>rNPp;
			}
			for(int i=1;i<=2;i++)
			{
				fitJ>>NJb;
				fitP>>NPb;
				oldFitJ>>rNJb;
				oldFitP>>rNPb;
			}
			Sum_SigJp = Sum_SigJp + NJp/Taccjp->GetBinContent(pt,y)/Trecjp->GetBinContent(pt,y)/Tpidjp->GetBinContent(pt,y)/Ttrijp->GetBinContent(pt,y);
                        Sum_rSigJp = Sum_rSigJp + rNJp/Taccjp->GetBinContent(pt,y)/Trecjp->GetBinContent(pt,y)/Tpidjp->GetBinContent(pt,y)/Ttrijp->GetBinContent(pt,y);
                        Sum_SigJb = Sum_SigJb + NJb/Taccjb->GetBinContent(pt,y)/Trecjb->GetBinContent(pt,y)/Tpidjb->GetBinContent(pt,y)/Ttrijb->GetBinContent(pt,y);
                        Sum_rSigJb = Sum_rSigJb + rNJb/Taccjb->GetBinContent(pt,y)/Trecjb->GetBinContent(pt,y)/Tpidjb->GetBinContent(pt,y)/Ttrijb->GetBinContent(pt,y);
                        Sum_SigPp = Sum_SigPp + NPp/Taccpp->GetBinContent(pt,y)/Trecpp->GetBinContent(pt,y)/Tpidpp->GetBinContent(pt,y)/Ttripp->GetBinContent(pt,y);
                        Sum_rSigPp = Sum_rSigPp + rNPp/Taccpp->GetBinContent(pt,y)/Trecpp->GetBinContent(pt,y)/Tpidpp->GetBinContent(pt,y)/Ttripp->GetBinContent(pt,y);
                        Sum_SigPb = Sum_SigPb + NPb/Taccpb->GetBinContent(pt,y)/Trecpb->GetBinContent(pt,y)/Tpidpb->GetBinContent(pt,y)/Ttripb->GetBinContent(pt,y);
                        Sum_rSigPb = Sum_rSigPb + rNPb/Taccpb->GetBinContent(pt,y)/Trecpb->GetBinContent(pt,y)/Tpidpb->GetBinContent(pt,y)/Ttripb->GetBinContent(pt,y);
		}
	}
	}	
	output << (Sum_SigPp/Sum_SigJp-Sum_rSigPp/Sum_rSigJp)/(Sum_rSigPp/Sum_rSigJp) << endl;
	output << (Sum_SigPb/Sum_SigJb-Sum_rSigPb/Sum_rSigJb)/(Sum_rSigPb/Sum_rSigJb) << endl;
	output.close();
	return 0;
}
