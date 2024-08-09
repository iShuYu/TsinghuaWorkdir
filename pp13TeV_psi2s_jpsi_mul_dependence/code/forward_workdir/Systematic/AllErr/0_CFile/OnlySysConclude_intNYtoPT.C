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
   	double ErrBrPsi2S_ee = 0.17/7.93;
        double ErrBrJpsi_mumu = 0.006;
	
	//PID in bin
	ifstream input2("../../PID/3_Result/InBinVar/IntNYtoPT.txt");
        double PIDpromptInBinErr[5];
	for(int i=0;i<5;i++) input2 >> PIDpromptInBinErr[i];
	
	//Trigger (for from b and prompt)
	ifstream input5("../../Trigger/3_Result/TriggerErr/IntNYtoPT.txt");
	double TriggerErrp[5];
	for(int i=0;i<5;i++) input5 >> TriggerErrp[i]; 
	//tracking
	ifstream input7("../../tracking/3_Result/StatsErr/IntNYtoPT.txt");
	double trackprompt[5];
	for(int i=0;i<5;i++) input7 >> trackprompt[i];
       	//tz sigal fit
	ifstream input9("../../tzFit/3_Result/Error/IntNYtoPTtzsig.txt");
	double tzsigprompt[5];
	for(int i=0;i<5;i++) input9 >> tzsigprompt[i];
	//tz bkg and 2D
	ifstream input10("../../tzFit/3_Result/Error/IntNYtoPT2D.txt");
	double tzbkg2Dprompt[5];
	for(int i=0;i<5;i++) input10 >> tzbkg2Dprompt[i];
	//MC sample size
	ifstream input11("../../MCSampleSize_int/3_Result/MCSizeErrIntNYtoPT.txt");
	double MCsampleSizeprompt[5];
	for(int i=0;i<5;i++) input11 >> MCsampleSizeprompt[i];
	//massfit
	ifstream input12("../../massFit/3_Result/massFitErr/Int_to_PT.txt");
	double massfit[5];
	for(int i=0;i<5;i++) input12 >> massfit[i];
	//StatErr
	ifstream input13("../../StatsErr/3_Result/StatsErrIntNYtoPT.txt");
	double StatspErr[5];
	for(int i=0;i<5;i++) input13 >> StatspErr[i];
	
	//output
	ofstream out("../3_Result/IntNYtoPT_OnlySysErr.txt");
	double pErr[5];
	for(int i=1;i<=5;i++){
	pErr[i-1] =  PIDpromptInBinErr[i-1]*PIDpromptInBinErr[i-1] +
		TriggerErrp[i-1]*TriggerErrp[i-1] +
		trackprompt[i-1]*trackprompt[i-1] +
		tzsigprompt[i-1]*tzsigprompt[i-1] +
		tzbkg2Dprompt[i-1]*tzbkg2Dprompt[i-1] +
		massfit[i-1]*massfit[i-1] +
		//StatspErr* StatspErr+
		MCsampleSizeprompt[i-1]*MCsampleSizeprompt[i-1] ;
	out << sqrt(pErr[i-1]) << endl;
	}
	out.close();
	return 0;
}

	


	

