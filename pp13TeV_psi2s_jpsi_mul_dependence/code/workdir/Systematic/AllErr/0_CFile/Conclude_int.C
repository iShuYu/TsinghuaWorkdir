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
	//TFile *input;

	//All eff Err is Jpsi/Psi2S, opposite to yield
	//PID in bin
	ifstream input1(Form("../../PID/3_Result/InBinVar/n%d_int_frombInBinErr.txt",N));
	double PIDfrombInBinErr;
	input1 >> PIDfrombInBinErr;
	//TH1D *PIDfrombInBinErr = (TH1D*)input->Get("h_eff_py");
	ifstream input2(Form("../../PID/3_Result/InBinVar/n%d_int_promptInBinErr.txt",N));
        double PIDpromptInBinErr;
        input2 >> PIDpromptInBinErr;
	//TH1D *PIDpromptInBinErr = (TH1D*)input->Get("h_eff_py");
	//PID Stats
	ifstream input3(Form("../../PID/3_Result/StatCalibVar/n%d_int_type2.txt",N));
	double PIDfrombStatsErr;
	input3 >> PIDfrombStatsErr;
	//TH1D *PIDfrombStatsErr = (TH1D*)input->Get("h_eff_py");
	ifstream input4(Form("../../PID/3_Result/StatCalibVar/n%d_int_type1.txt",N));
        double PIDpromptStatsErr;
	input4 >> PIDpromptStatsErr;
	//TH1D *PIDpromptStatsErr = (TH1D*)input->Get("h_eff_py");
	//Trigger (for from b and prompt)
	ifstream input5(Form("../../Trigger/3_Result/TriggerErr/n%d_int_fromb.txt",N));
	double TriggerErrb;
	input5 >> TriggerErrb;
	//TH1D *TriggerErrb = (TH1D*)input->Get("ErrTemp");
	ifstream input6(Form("../../Trigger/3_Result/TriggerErr/n%d_int_prompt.txt",N));
        double TriggerErrp;
        input6 >> TriggerErrp;
	//TH1D *TriggerErrp = (TH1D*)input->Get("ErrTemp");
	//tracking
	ifstream input7(Form("../../tracking/3_Result/StatsErr/n%d_int_fromb.txt",N));
	double trackfromb;
	input7 >> trackfromb;
	//TH1D *trackfromb = (TH1D*)input->Get("h_eff_py");
	ifstream input8(Form("../../tracking/3_Result/StatsErr/n%d_int_prompt.txt",N));
	double trackprompt;
	input8 >> trackprompt;
        //TH1D *trackprompt = (TH1D*)input->Get("h_eff_py");
	//tz sigal fit
	ifstream input9(Form("../../tzFit/3_Result/Error/tzsig/n%d_int_J_and_P_b_and_p.txt",N));
	double tzsigfromb, tzsigprompt;
	input9 >> tzsigprompt >> tzsigfromb;
	//TH1D *tzsigfromb = (TH1D*)input->Get("Errb");
	//TH1D *tzsigprompt = (TH1D*)input->Get("Errp");
	//tz bkg and 2D
	ifstream input10(Form("../../tzFit/3_Result/Error/tzbkg_2D/n%d_int_J_and_P_b_and_p.txt",N));
	double tzbkg2Dfromb, tzbkg2Dprompt;
	input10 >> tzbkg2Dprompt >> tzbkg2Dfromb;
        //TH1D *tzbkg2Dfromb = (TH1D*)input->Get("Errb");
        //TH1D *tzbkg2Dprompt = (TH1D*)input->Get("Errp");
	//MC sample size
	ifstream input11(Form("../../MCSampleSize_int/3_Result/n%dMCSizeErrInt.txt",N));
	double MCsampleSizefromb, MCsampleSizeprompt;
	input11 >> MCsampleSizeprompt >> MCsampleSizefromb; 
	//TH1D *MCsampleSizefromb = (TH1D*)input->Get("MCSizeErrFromb");
	//TH1D *MCsampleSizeprompt = (TH1D*)input->Get("MCSizeErrPrompt");
	//massfit
	ifstream input12(Form("../../massFit/3_Result/massFitErr/n%d_int_Err.txt",N));
	double massfit;
	input12 >> massfit;
	cout << "massfit" << massfit << endl;
	//TH1D *massfit = (TH1D*)input->Get("h_eff_py");
	//StatErr
	ifstream input13(Form("../../StatsErr/3_Result/n%dStatsErrInt.txt",N));
	double StatsbErr, StatspErr;
	input13 >> StatspErr >> StatsbErr;
	cout <<  "StatspErr" << StatspErr << endl;
	//TH1D *StatsbErr = (TH1D*)input->Get("StatsErrFromb");
	//TH1D *StatspErr = (TH1D*)input->Get("StatsErrPrompt");

	//output
	ofstream out(Form("../3_Result/n%d_int_AllsysErr.txt",N));
	double prompt, fromb;
	//TH1D *prompt = (TH1D*)PIDpromptInBinErr->Clone(0);
	//TH1D *fromb = (TH1D*)PIDfrombInBinErr->Clone(0);
	//int npt = prompt->GetNbinsX();
	//int ny = prompt->GetNbinsY();
	//for(int y=1;y<=ny;y++)
	//{
		//for(int y=1;y<=ny;y++)
		//{
			double pErr = 0;
			double bErr = 0;
			pErr =  PIDpromptInBinErr*PIDpromptInBinErr+
				PIDpromptStatsErr*PIDpromptStatsErr+
				//TriggerErrp* TriggerErrp+
				tt[N-1]*tt[N-1]+
				trackprompt*trackprompt+
				tzsigprompt*tzsigprompt+
				tzbkg2Dprompt*tzbkg2Dprompt+
				massfit*massfit+
				StatspErr* StatspErr+
				MCsampleSizeprompt*MCsampleSizeprompt;

			bErr =  PIDfrombInBinErr*PIDfrombInBinErr+
                                PIDfrombStatsErr*PIDfrombStatsErr+
                                //TriggerErrb* TriggerErrb+
                                tt[N-1]*tt[N-1]+
				trackfromb*trackfromb+
                                tzsigfromb*tzsigfromb+
                                tzbkg2Dfromb*tzbkg2Dfromb+
				massfit*massfit+
				StatsbErr* StatsbErr+
				MCsampleSizefromb*MCsampleSizefromb;
			prompt = sqrt(pErr+0*ErrBrPsi2S_ee*ErrBrPsi2S_ee+0*ErrBrJpsi_mumu*ErrBrJpsi_mumu);
			fromb = sqrt(bErr+0*ErrBrPsi2S_ee*ErrBrPsi2S_ee+0*ErrBrJpsi_mumu*ErrBrJpsi_mumu);
			//prompt -> SetBinContent(y,pErr);
			//fromb -> SetBinContent(y,bErr);
			//prompt -> SetBinError(y,0.);
			//fromb -> SetBinError(y,0.);
		//}
	//}
	//prompt -> Write("prompt");
	//fromb -> Write("fromb");
	out << prompt << endl;
	out << fromb << endl;
	out.close();
	return 0;
}

	


	

