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
	ifstream TT("../../Trigger/3_Result/TriggerErr/err.txt ");
	double tt[5];
	for(int i=1;i<=5;i++) TT >> tt[i-1];

	double ErrBrPsi2S_ee = 0.17/7.93;
        double ErrBrJpsi_mumu = 0.006;
	//All eff Err is Jpsi/Psi2S, opposite to yield
	//PID in bin
	ifstream input1("../../PID/3_Result/InBinVar/INTErr.txt");
	double PIDfrombInBinErr;
	double PIDpromptInBinErr;
	input1 >> PIDpromptInBinErr;
        input1 >> PIDfrombInBinErr;
	
	//PID Stats
	ifstream input3("../../PID/3_Result/StatCalibVar/INTErr.txt");
	double PIDfrombStatsErr;
	double PIDpromptStatsErr;
	input3 >> PIDpromptStatsErr;
	input3 >> PIDfrombStatsErr;
	
	//Trigger (for from b and prompt)
	ifstream input5("../../Trigger/3_Result/TriggerErr/INTErr.txt");
	double TriggerErrb;
	double TriggerErrp;
	input5 >> TriggerErrp >> TriggerErrb;
	
	//tracking
	ifstream input7("../../tracking/3_Result/StatsErr/INTErr.txt");
	double trackfromb, trackprompt;
	input7 >> trackprompt;
	input7 >> trackfromb;
	
	//tz sigal fit
	ifstream input9("../../tzFit/3_Result/Error/INTErrsig.txt");
	double tzsigfromb, tzsigprompt;
	input9 >> tzsigprompt >> tzsigfromb;
	
	//tz bkg and 2D
	ifstream input10("../../tzFit/3_Result/Error/INTErr.txt");
	double tzbkg2Dfromb, tzbkg2Dprompt;
	input10 >> tzbkg2Dprompt >> tzbkg2Dfromb;
        
	//MC sample size
	ifstream input11("../../MCSampleSize_int/3_Result/INTErr.txt");
	double MCsampleSizefromb, MCsampleSizeprompt;
	input11 >> MCsampleSizeprompt >> MCsampleSizefromb; 
	
	//massfit
	ifstream input12("../../massFit/3_Result/massFitErr/INTErr.txt");
	double massfit;
	input12 >> massfit;
	
	//StatErr
	ifstream input13("../../StatsErr/3_Result/INTErr.txt");
	double StatsbErr, StatspErr;
	input13 >> StatspErr >> StatsbErr;
	
	//output
	ofstream out(Form("../3_Result/INTErr.txt"));
	double prompt, fromb;
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
                                tt[N-1]+tt[N-1]+
				trackfromb*trackfromb+
                                tzsigfromb*tzsigfromb+
                                tzbkg2Dfromb*tzbkg2Dfromb+
				massfit*massfit+
				StatsbErr* StatsbErr+
				MCsampleSizefromb*MCsampleSizefromb;
			prompt = sqrt(pErr+0*ErrBrPsi2S_ee*ErrBrPsi2S_ee+0*ErrBrJpsi_mumu*ErrBrJpsi_mumu);
			fromb = sqrt(bErr+0*ErrBrPsi2S_ee*ErrBrPsi2S_ee+0*ErrBrJpsi_mumu*ErrBrJpsi_mumu);

	out << prompt << endl;
	out << fromb << endl;
	out.close();
	return 0;
}

	


	

