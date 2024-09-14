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
	input = TFile::Open(Form("../../PID/3_Result/InBinVar/n%d_frombInBinErr.root",N));
	TH2D *PIDfrombInBinErr = (TH2D*)input->Get("h_eff");
	input = TFile::Open(Form("../../PID/3_Result/InBinVar/n%d_promptInBinErr.root",N));
        TH2D *PIDpromptInBinErr = (TH2D*)input->Get("h_eff");
	//PID Stats
	input = TFile::Open(Form("../../PID/3_Result/StatCalibVar/n%d_fromb.root",N));
	TH2D *PIDfrombStatsErr = (TH2D*)input->Get("h_eff");
	input = TFile::Open(Form("../../PID/3_Result/StatCalibVar/n%d_prompt.root",N));
        TH2D *PIDpromptStatsErr = (TH2D*)input->Get("h_eff");
	//Trigger (for from b and prompt)
	input = TFile::Open(Form("../../Trigger/3_Result/TriggerErr/TriggerErr.root"));
	TH2D *TriggerErr = (TH2D*)input->Get("ErrTemp");
	//tracking
	input = TFile::Open(Form("../../tracking/3_Result/StatsErr/n%d_fromb.root",N));
	TH2D *trackfromb = (TH2D*)input->Get("h_eff");
	input = TFile::Open(Form("../../tracking/3_Result/StatsErr/n%d_prompt.root",N));
        TH2D *trackprompt = (TH2D*)input->Get("h_eff");
	//tz sigal fit
	input = TFile::Open(Form("../../tzFit/3_Result/Error/tzsig/n%d_J_and_P_b_and_p.root",N));
	TH2D *tzsigfromb = (TH2D*)input->Get("Errb");
	TH2D *tzsigprompt = (TH2D*)input->Get("Errp");
	//tz bkg and 2D
	input = TFile::Open(Form("../../tzFit/3_Result/Error/tzbkg_2D/n%d_J_and_P_b_and_p.root",N));
        TH2D *tzbkg2Dfromb = (TH2D*)input->Get("Errb");
        TH2D *tzbkg2Dprompt = (TH2D*)input->Get("Errp");
	//MC sample size
	input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_tot/n%d_fromb.root",N));
	TH2D *JMCsampleSizefromb = (TH2D*)input->Get("h_3");
	input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_tot/n%d_prompt.root",N));
	TH2D *JMCsampleSizeprompt = (TH2D*)input->Get("h_3");
	input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_tot/n%d_fromb.root",N));
        TH2D *PMCsampleSizefromb = (TH2D*)input->Get("h_3");
        input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_tot/n%d_prompt.root",N));
        TH2D *PMCsampleSizeprompt = (TH2D*)input->Get("h_3");
	//massfit
	input = TFile::Open(Form("../../massFit/3_Result/massFitErr/n%dErr.root",N));
	TH2D *massfit = (TH2D*)input->Get("h_eff");
	//StatErr
	input = TFile::Open(Form("../../../Yield/result/3_Result/Conclude.root"));
	TH2D *StatsJbErr = (TH2D*)input->Get(Form("Jb%d",N));
	TH2D *StatsJpErr = (TH2D*)input->Get(Form("Jp%d",N));
	TH2D *StatsPbErr = (TH2D*)input->Get(Form("Pb%d",N));
        TH2D *StatsPpErr = (TH2D*)input->Get(Form("Pp%d",N));

	//output
	TFile *out = new TFile(Form("../3_Result/n%d_AllsysErr.root",N),"recreate");
	TH2D *prompt = (TH2D*)PIDpromptInBinErr->Clone(0);
	TH2D *fromb = (TH2D*)PIDfrombInBinErr->Clone(0);
	int npt = prompt->GetNbinsX();
	int ny = prompt->GetNbinsY();
	for(int pt=1;pt<=npt;pt++)
	{
		for(int y=1;y<=ny;y++)
		{
			double pErr = 0;
			double bErr = 0;
			pErr =  PIDpromptInBinErr->GetBinContent(pt,y)*PIDpromptInBinErr->GetBinContent(pt,y)+
				PIDpromptStatsErr->GetBinContent(pt,y)*PIDpromptStatsErr->GetBinContent(pt,y)+
				//TriggerErr->GetBinContent(pt,y)* TriggerErr->GetBinContent(pt,y)+
				tt[N-1]*tt[N-1]+
				trackprompt->GetBinContent(pt,y)*trackprompt->GetBinContent(pt,y)+
				tzsigprompt->GetBinContent(pt,y)*tzsigprompt->GetBinContent(pt,y)+
				tzbkg2Dprompt->GetBinContent(pt,y)*tzbkg2Dprompt->GetBinContent(pt,y)+
				massfit->GetBinContent(pt,y)*massfit->GetBinContent(pt,y)+
				StatsPpErr->GetBinError(pt,y)*StatsPpErr->GetBinError(pt,y)/StatsPpErr->GetBinContent(pt,y)/StatsPpErr->GetBinContent(pt,y)+StatsJpErr->GetBinError(pt,y)*StatsJpErr->GetBinError(pt,y)/StatsJpErr->GetBinContent(pt,y)/StatsJpErr->GetBinContent(pt,y)+
				JMCsampleSizeprompt->GetBinError(pt,y)*JMCsampleSizeprompt->GetBinError(pt,y)/JMCsampleSizeprompt->GetBinContent(pt,y)/JMCsampleSizeprompt->GetBinContent(pt,y)+PMCsampleSizeprompt->GetBinError(pt,y)*PMCsampleSizeprompt->GetBinError(pt,y)/PMCsampleSizeprompt->GetBinContent(pt,y)/PMCsampleSizeprompt->GetBinContent(pt,y);
			bErr =  PIDfrombInBinErr->GetBinContent(pt,y)*PIDfrombInBinErr->GetBinContent(pt,y)+
                                PIDfrombStatsErr->GetBinContent(pt,y)*PIDfrombStatsErr->GetBinContent(pt,y)+
                                //TriggerErr->GetBinContent(pt,y)* TriggerErr->GetBinContent(pt,y)+
                                tt[N-1]*tt[N-1]+
				trackfromb->GetBinContent(pt,y)*trackfromb->GetBinContent(pt,y)+
                                tzsigfromb->GetBinContent(pt,y)*tzsigfromb->GetBinContent(pt,y)+
                                tzbkg2Dfromb->GetBinContent(pt,y)*tzbkg2Dfromb->GetBinContent(pt,y)+
				massfit->GetBinContent(pt,y)*massfit->GetBinContent(pt,y)+
				StatsPbErr->GetBinError(pt,y)*StatsPbErr->GetBinError(pt,y)/StatsPbErr->GetBinContent(pt,y)/StatsPbErr->GetBinContent(pt,y)+StatsJbErr->GetBinError(pt,y)*StatsJbErr->GetBinError(pt,y)/StatsJbErr->GetBinContent(pt,y)/StatsJbErr->GetBinContent(pt,y)+
				JMCsampleSizefromb->GetBinError(pt,y)*JMCsampleSizefromb->GetBinError(pt,y)/JMCsampleSizefromb->GetBinContent(pt,y)/JMCsampleSizefromb->GetBinContent(pt,y)+PMCsampleSizefromb->GetBinError(pt,y)*PMCsampleSizefromb->GetBinError(pt,y)/PMCsampleSizefromb->GetBinContent(pt,y)/PMCsampleSizefromb->GetBinContent(pt,y);;
			pErr = sqrt(pErr+0*ErrBrPsi2S_ee*ErrBrPsi2S_ee+0*ErrBrJpsi_mumu*ErrBrJpsi_mumu);
			bErr = sqrt(bErr+0*ErrBrPsi2S_ee*ErrBrPsi2S_ee+0*ErrBrJpsi_mumu*ErrBrJpsi_mumu);
			prompt -> SetBinContent(pt,y,pErr);
			fromb -> SetBinContent(pt,y,bErr);
			prompt -> SetBinError(pt,y,0.);
			fromb -> SetBinError(pt,y,0.);
		}
	}
	prompt -> Write("prompt");
	fromb -> Write("fromb");
	out -> Close();
	return 0;
}

	


	

