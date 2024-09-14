#include <fstream>
#include <TFile.h>
#include <TH2.h>
#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char *argv[])
{
	//纯纯统计误差，这里计算的是
	int flag;
	sscanf(argv[1],"%d",&flag); //1 for J and 2 for P
	int num_y, num_pt;
        sscanf(argv[2],"%d",&num_y);
        sscanf(argv[3],"%d",&num_pt);
	ifstream production(argv[4]);
	double bias, biasErr, sigma1, sigma1Err, sigma2, sigma2Err, beta, betaErr, tau, tauErr, Nprompt, NpromptErr, Nfromb, NfrombErr, Ntail, NtailErr, Nbkg, NbkgErr;
	production >> bias >> biasErr >> sigma1 >> sigma1Err >> sigma2 >> sigma2Err >> beta >>  betaErr >> tau >> tauErr >> Nprompt >> NpromptErr >> Nfromb >> NfrombErr >> Ntail >> NtailErr >> Nbkg >> NbkgErr;
	TFile eff_fromb(argv[5]);
	TFile eff_prompt(argv[6]);
	TH2D *eff_b = (TH2D*)eff_fromb.Get("h_3");
	TH2D *eff_p = (TH2D*)eff_prompt.Get("h_3");
	double lumi = 657.6611390205;
	double lumiErr = 657.6611390205*0.02;
	double k = 1;
	double BrPsi2S_2_ee = 7.93*0.001;
	double BrPErr = 0.17*0.001;
	double BrJPsi_2_mumu = 5.961*0.01;
	double BrJErr = 0.033*0.01;
	double efromb, eprompt, efrombErr, epromptErr;
	efromb = eff_b->GetBinContent(num_pt, num_y);
	efrombErr = eff_b->GetBinError(num_pt, num_y);
	eprompt = eff_p->GetBinContent(num_pt, num_y);
        epromptErr = eff_p->GetBinError(num_pt, num_y);
	if(flag==1)
	{
		ofstream bin_result(argv[7]);
		bin_result << Nprompt / eprompt / BrJPsi_2_mumu / lumi / 1000 << endl;
		bin_result << Nfromb / efromb / BrJPsi_2_mumu / lumi / 1000 << endl;
		//No, not this way
		//bin_result << sqrt((NpromptErr/Nprompt)*(NpromptErr/Nprompt)+(epromptErr/eprompt)*(epromptErr/eprompt)+(BrJErr/BrJPsi_2_mumu)*(BrJErr/BrJPsi_2_mumu)+(lumiErr/lumi)*(lumiErr/lumi))*Nprompt/eprompt/BrJPsi_2_mumu/lumi/1000 << endl;
		//bin_result << sqrt((NfrombErr/Nfromb)*(NfrombErr/Nfromb)+(efrombErr/efromb)*(efrombErr/efromb)+(BrJErr/BrJPsi_2_mumu)*(BrJErr/BrJPsi_2_mumu)+(lumiErr/lumi)*(lumiErr/lumi))*Nfromb/efromb/BrJPsi_2_mumu/lumi /1000 << endl;
		bin_result << NpromptErr / eprompt / BrJPsi_2_mumu / lumi / 1000 << endl;
		bin_result <<  NfrombErr / efromb / BrJPsi_2_mumu / lumi / 1000 << endl;
	}
	if(flag==2)
        {
		ofstream bin_result(argv[7]);
		bin_result << Nprompt / eprompt / k  / BrPsi2S_2_ee / lumi /1000 << endl;
		bin_result << Nfromb / efromb / k  / BrPsi2S_2_ee / lumi/1000 << endl;
		//bin_result << sqrt((NpromptErr/Nprompt)*(NpromptErr/Nprompt)+(epromptErr/eprompt)*(epromptErr/eprompt)+(BrPErr/BrPsi2S_2_ee)*(BrPErr/BrPsi2S_2_ee)+(lumiErr/lumi)*(lumiErr/lumi))*Nprompt/eprompt/BrPsi2S_2_ee/lumi/k/1000 << endl;
		//bin_result << sqrt((NfrombErr/Nfromb)*(NfrombErr/Nfromb)+(efrombErr/efromb)*(efrombErr/efromb)+(BrPErr/BrPsi2S_2_ee)*(BrPErr/BrPsi2S_2_ee)+(lumiErr/lumi)*(lumiErr/lumi))*Nfromb/efromb/BrPsi2S_2_ee/lumi/k/1000 << endl;
		bin_result << NpromptErr / eprompt / k  / BrPsi2S_2_ee / lumi /1000 << endl;
                bin_result << NfrombErr / efromb / k  / BrPsi2S_2_ee / lumi/1000 << endl;
	}
	return 0;
}

