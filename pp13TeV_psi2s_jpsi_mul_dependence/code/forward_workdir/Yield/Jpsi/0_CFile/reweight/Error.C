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
	//return a*x+b*0;
}
double f2(double a, double b, double c, double x)
{
	return a+b*x+c*x*x;
}

int main(int argc, char* argv[])
{
	TH1::SetDefaultSumw2();
	TRandom3 *r = new TRandom3(0);
	//input scheme
	ifstream fn("../../../../../workdir/Yield/rawdata/3_Bins/nbin");
	int N;
	fn >> N;
	double bin[N+1];
	for(int i=0;i<=N;i++) {fn >> bin[i]; cout << bin[i] << endl;}
	
	//input function 
	ifstream funJp("../../3_Result/reweight/fitp.txt");
	double Jp1, Jp2, Jp3, Jp4, Jp5, Jp3Err, Jp4Err, Jp5Err;
	funJp >> Jp1 >> Jp2 >> Jp3 >> Jp4 >> Jp5 >> Jp3Err >> Jp4Err >> Jp5Err;
	ifstream funJb("../../3_Result/reweight/fitb.txt");
        double Jb1, Jb2, Jb3, Jb4, Jb5, Jb3Err, Jb4Err, Jb5Err;
        funJb >> Jb1 >> Jb2 >> Jb3 >> Jb4 >> Jb5 >> Jb3Err >> Jb4Err >> Jb5Err;
	
	ofstream txtperr("../../../result/3_Result/Nch_prompterr.txt");
	ofstream txtberr("../../../result/3_Result/Nch_fromberr.txt");
	ofstream txtp("../../../result/3_Result/Nch_prompt.txt");
        ofstream txtb("../../../result/3_Result/Nch_fromb.txt");
	double b, p;
	for(int j=0;j<N;j++){
	//input DecayTree
	TFile *input = TFile::Open("/nishome/kangye/disk402_ppAnalysis/workdir/Yield/Jpsi/3_Result/RegenVar/newVar.root");
	TTree *tJp = (TTree*)input->Get("DecayTree");
	DecayTree tjp(tJp);
	int Ntjp = tJp->GetEntries();
	TH1D *T1Jp = new TH1D("T1Jp","T1Jp", 400, 0, 400);
	TH1D *T2Jp = new TH1D("T2Jp","T2Jp", 400, 0, 400);
	TH1D *T2JpRan = new TH1D("T2JpRan","T2JpRan", 400, -200, 200);
	for(int i=0;i<Ntjp;i++)
	{
		tJp->GetEntry(i);
		//no weights need here since f is already fitted from weight distribution
		double PVN = tjp.PVNcor;
		if(PVN<bin[j]||PVN>bin[j+1]) continue;
		T1Jp -> Fill(f1(Jp1,Jp2,PVN), tjp.prompt_sw);
		T2Jp -> Fill(f2(Jp3,Jp4,Jp5,PVN), tjp.prompt_sw);
	}
	double meanjp = abs(T2Jp->GetMean()-T1Jp->GetMean());
	double pErr = sqrt(meanjp*meanjp);
	txtp << T2Jp->GetMean()/2.8 << endl;
	double sp = 0;
	double sb = 0;
	double sp2 = 0;
        double sb2 = 0;
	for(int ii=0; ii<13; ii++){
		ifstream txtpp(Form("../../../result/3_Result/MUL/Nch_prompt%d.txt",ii));
        	ifstream txtbb(Form("../../../result/3_Result/MUL/Nch_fromb%d.txt",ii));
		for(int t=0; t<=j; t++){
		       	txtpp >> p;
			txtbb >> b;
		}
		//cout << p << endl;
		sp = sp + p;
		sb = sb + b;
		sp2 = sp2+p*p;
		sb2 = sb2+b*b;
		
	}
	double pErr2 = sqrt(sp2/13-sp*sp/13/13);
	double bErr2 = sqrt(sb2/13-sb*sb/13/13);
	cout << sp2/13 << endl;
	cout << sp*sp/13/13 << endl;
	txtperr << sqrt(pErr*pErr/2.8/2.8+pErr2*pErr2) << endl;
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
                T1Jb -> Fill(f1(Jb1,Jb2,PVN), tjb.fromb_sw);
                T2Jb -> Fill(f2(Jb3,Jb4,Jb5,PVN), tjb.fromb_sw);
        }
	double meanjb = abs(T2Jb->GetMean()-T1Jb->GetMean());
	double bErr = sqrt(meanjb*meanjb);
        txtberr << sqrt(bErr*bErr/2.8/2.8+bErr2*bErr2) << endl;
	txtb << T2Jb->GetMean()/2.8 << endl;
        }
	txtperr.close();
        txtberr.close();
	return 0;
}
