#define DecayTree_cxx
#include "/nishome/kangye/disk402_ppAnalysis/workdir/Yield/Jpsi/3_Result/RegenVar/DecayTree.h"
#include <TStyle.h>
#include <TH1.h>
#include <TH2D.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <TRandom3.h>

using namespace std;
double f1(double a, double b, double x)
{
	return a*pow(x,b);
}
double f2(double a, double b, double c, double x)
{
	return a+b*x+c*x*x;
}

int main(int argc, char* argv[])
{
	int ii;
	sscanf(argv[1],"%d",&ii);
	TH1::SetDefaultSumw2();
	TRandom3 *r = new TRandom3(0);
	//input scheme
	ifstream fn(Form("../../../../../workdir/Yield/rawdata/3_Bins/nbin"));
	int N;
	fn >> N;
	double bin[N+1];
	for(int i=0;i<=N;i++) {fn >> bin[i]; cout << bin[i] << endl;}
	
	//input function 
	ifstream funJp(Form("../../3_Result/reweight/MUL/fitp%d.txt",ii));
	double Jp1, Jp2, Jp3, Jp4, Jp5, Jp3Err, Jp4Err, Jp5Err;
	funJp >> Jp1 >> Jp2 >> Jp3 >> Jp4 >> Jp5 >> Jp3Err >> Jp4Err >> Jp5Err;
	ifstream funJb(Form("../../3_Result/reweight/MUL/fitb%d.txt",ii));
        double Jb1, Jb2, Jb3, Jb4, Jb5, Jb3Err, Jb4Err, Jb5Err;
        funJb >> Jb1 >> Jb2 >> Jb3 >> Jb4 >> Jb5 >> Jb3Err >> Jb4Err >> Jb5Err;
	ofstream txtp(Form("../../../result/3_Result/MUL/Nch_prompt%d.txt",ii));
        ofstream txtb(Form("../../../result/3_Result/MUL/Nch_fromb%d.txt",ii));

	for(int j=0;j<N;j++){
	//input DecayTree
	TFile *input = TFile::Open("/nishome/kangye/disk402_ppAnalysis/workdir/Yield/Jpsi/3_Result/RegenVar/newVar.root");
	TTree *tJp = (TTree*)input->Get("DecayTree");
	DecayTree tjp(tJp);
	int Ntjp = tJp->GetEntries();
	TH1D *T1Jp = new TH1D("T1Jp","T1Jp", 400, 0, 400);
	TH1D *T2Jp = new TH1D("T2Jp","T2Jp", 400, 0, 400);
	for(int i=0;i<Ntjp;i++)
	{
		tJp->GetEntry(i);
		//no weights need here since f is already fitted from weight distribution
		double PVN = tjp.PVNcor;
		if(PVN<bin[j]||PVN>bin[j+1]) continue;
		T1Jp -> Fill(f1(Jp1,Jp2,PVN),tjp.prompt_sw);
		T2Jp -> Fill(f2(Jp3,Jp4,Jp5,PVN), tjp.prompt_sw);
	}
	double meanjp = abs(T2Jp->GetMean()-T1Jp->GetMean());
	double pErr = sqrt(meanjp*meanjp);
	txtp << T2Jp->GetMean()/2.8 << endl;

	//input = TFile::Open("../../../../../workdir/Yield/rawdata/1_Rootfile/MCtracks/Jpsi/Tupleb.root");
        TTree *tJb = (TTree*)input->Get("DecayTree");
        DecayTree tjb(tJb);
        int Ntjb = tJb->GetEntries();
        TH1D *T1Jb = new TH1D("T1Jb","T1Jb", 400, 0, 400);
        TH1D *T2Jb = new TH1D("T2Jb","T2Jb", 400, 0, 400);
        for(int i=0;i<Ntjb;i++)
        {
                tJb->GetEntry(i);
                //no weights need here since f is already fitted from weight distribution
                double PVN = tjb.PVNcor;
		if(PVN<bin[j]||PVN>bin[j+1]) continue;
                T1Jb -> Fill(f1(Jb1,Jb2,PVN),tjb.fromb_sw);
                T2Jb -> Fill(f2(Jb3,Jb4,Jb5,PVN), tjb.fromb_sw);
        }
	double meanjb = abs(T2Jb->GetMean()-T1Jb->GetMean());
	double bErr = sqrt(meanjb*meanjb);
	txtb << T2Jb->GetMean()/2.8 << endl;
        }
	txtp.close();
        txtb.close();
	return 0;
}
