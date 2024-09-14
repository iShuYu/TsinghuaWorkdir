#include <TH1D.h>
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
        ifstream TT("../../Trigger/3_Result/TriggerErr/err.txt");
	double tt[5];
	for(int i=1;i<=5;i++) TT >> tt[i-1];

	gROOT->SetBatch(true);
        setLHCbStyle();
        gStyle->SetPalette(55);
        gStyle->SetPaintTextFormat("4.3f");
        int N;
        sscanf(argv[1],"%d",&N);
	double ErrBrPsi2S_ee = 0.17/7.93;
        double ErrBrJpsi_mumu = 0.006;
	//input
	TFile *input;

	//All eff Err is Jpsi/Psi2S, opposite to yield
	//PID in bin
	input = TFile::Open(Form("../../PID/3_Result/InBinVar/n%d_int_y_frombInBinErr.root",N));
	TH1D *PIDfrombInBinErr = (TH1D*)input->Get("h_eff_py");
	input = TFile::Open(Form("../../PID/3_Result/InBinVar/n%d_int_y_promptInBinErr.root",N));
        TH1D *PIDpromptInBinErr = (TH1D*)input->Get("h_eff_py");
	//PID Stats
	input = TFile::Open(Form("../../PID/3_Result/StatCalibVar/n%d_int_y_fromb.root",N));
	TH1D *PIDfrombStatsErr = (TH1D*)input->Get("h_eff_py");
	input = TFile::Open(Form("../../PID/3_Result/StatCalibVar/n%d_int_y_prompt.root",N));
        TH1D *PIDpromptStatsErr = (TH1D*)input->Get("h_eff_py");
	//Trigger (for from b and prompt)
	input = TFile::Open(Form("../../Trigger/3_Result/TriggerErr/n%d_int_y_fromb.root",N));
	TH1D *TriggerErrb = (TH1D*)input->Get("ErrTemp");
	input = TFile::Open(Form("../../Trigger/3_Result/TriggerErr/n%d_int_y_prompt.root",N));
        TH1D *TriggerErrp = (TH1D*)input->Get("ErrTemp");
	//tracking
	input = TFile::Open(Form("../../tracking/3_Result/StatsErr/n%d_int_y_fromb.root",N));
	TH1D *trackfromb = (TH1D*)input->Get("h_eff_py");
	input = TFile::Open(Form("../../tracking/3_Result/StatsErr/n%d_int_y_prompt.root",N));
        TH1D *trackprompt = (TH1D*)input->Get("h_eff_py");
	//tz sigal fit
	input = TFile::Open(Form("../../tzFit/3_Result/Error/tzsig/n%d_int_y_J_and_P_b_and_p.root",N));
	TH1D *tzsigfromb = (TH1D*)input->Get("Errb");
	TH1D *tzsigprompt = (TH1D*)input->Get("Errp");
	//tz bkg and 2D
	input = TFile::Open(Form("../../tzFit/3_Result/Error/tzbkg_2D/n%d_int_y_J_and_P_b_and_p.root",N));
        TH1D *tzbkg2Dfromb = (TH1D*)input->Get("Errb");
        TH1D *tzbkg2Dprompt = (TH1D*)input->Get("Errp");
	//MC sample size
	input = TFile::Open(Form("../../MCSampleSize_int/3_Result/n%dMCSizeErrIntY.root",N));
	TH1D *MCsampleSizefromb = (TH1D*)input->Get("MCSizeErrFromb");
	TH1D *MCsampleSizeprompt = (TH1D*)input->Get("MCSizeErrPrompt");
	//massfit
	input = TFile::Open(Form("../../massFit/3_Result/massFitErr/n%d_sumy_Err.root",N));
	TH1D *massfit = (TH1D*)input->Get("h_eff_py");
	//StatErr
	input = TFile::Open(Form(" ../../StatsErr/3_Result/n%dStatsErrIntY.root",N));
	TH1D *StatsbErr = (TH1D*)input->Get("StatsErrFromb");
	TH1D *StatspErr = (TH1D*)input->Get("StatsErrPrompt");

	//output
	TFile *out = new TFile(Form("../3_Result/n%d_int_y_OnlySysErr.root",N),"recreate");
	TH1D *prompt = (TH1D*)PIDpromptInBinErr->Clone(0);
	TH1D *fromb = (TH1D*)PIDfrombInBinErr->Clone(0);
	//int npt = prompt->GetNbinsX();
	int ny = prompt->GetNbinsX();
	cout << ny << endl;
	for(int y=1;y<=ny;y++)
	{
		//for(int y=1;y<=ny;y++)
		//{
			double pErr = 0;
			double bErr = 0;
			pErr =  PIDpromptInBinErr->GetBinContent(y)*PIDpromptInBinErr->GetBinContent(y)+
				PIDpromptStatsErr->GetBinContent(y)*PIDpromptStatsErr->GetBinContent(y)+
				//TriggerErrp->GetBinContent(y)* TriggerErrp->GetBinContent(y)+
				tt[N-1]*tt[N-1]+
				trackprompt->GetBinContent(y)*trackprompt->GetBinContent(y)+
				tzsigprompt->GetBinContent(y)*tzsigprompt->GetBinContent(y)+
				tzbkg2Dprompt->GetBinContent(y)*tzbkg2Dprompt->GetBinContent(y)+
				massfit->GetBinContent(y)*massfit->GetBinContent(y)+
				//StatspErr->GetBinContent(y)* StatspErr->GetBinContent(y)+
				MCsampleSizeprompt->GetBinContent(y)*MCsampleSizeprompt->GetBinContent(y);

			bErr =  PIDfrombInBinErr->GetBinContent(y)*PIDfrombInBinErr->GetBinContent(y)+
                                PIDfrombStatsErr->GetBinContent(y)*PIDfrombStatsErr->GetBinContent(y)+
                                //TriggerErrb->GetBinContent(y)* TriggerErrb->GetBinContent(y)+
                                tt[N-1]*tt[N-1]+
				trackfromb->GetBinContent(y)*trackfromb->GetBinContent(y)+
                                tzsigfromb->GetBinContent(y)*tzsigfromb->GetBinContent(y)+
                                tzbkg2Dfromb->GetBinContent(y)*tzbkg2Dfromb->GetBinContent(y)+
				massfit->GetBinContent(y)*massfit->GetBinContent(y)+
				//StatsbErr->GetBinContent(y)* StatsbErr->GetBinContent(y)+
				MCsampleSizefromb->GetBinContent(y)*MCsampleSizefromb->GetBinContent(y);
			pErr = sqrt(pErr+0*ErrBrPsi2S_ee*ErrBrPsi2S_ee+0*ErrBrJpsi_mumu*ErrBrJpsi_mumu);
			bErr = sqrt(bErr+0*ErrBrPsi2S_ee*ErrBrPsi2S_ee+0*ErrBrJpsi_mumu*ErrBrJpsi_mumu);
			prompt -> SetBinContent(y,pErr);
			fromb -> SetBinContent(y,bErr);
			prompt -> SetBinError(y,0.);
			fromb -> SetBinError(y,0.);
		//}
	}
	prompt -> Write("prompt");
	fromb -> Write("fromb");
	out -> Close();
	return 0;
}

	


	

