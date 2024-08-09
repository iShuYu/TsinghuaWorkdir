#include <TH1.h>
#include <TH2.h>
#include <fstream>
#include <TFile.h>
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int N;
	sscanf(argv[1],"%d",&N);
	TFile *p =  TFile::Open(argv[2]);
	TH2D *tp = (TH2D*)p->Get("h_3");
	TFile *b = TFile::Open(argv[3]);
	TH2D *tb = (TH2D*)b->Get("h_3");
	int pt = tb->GetNbinsX();
	int y = tb->GetNbinsY();
	TFile *out = new TFile(argv[4],"recreate");
	TH2D *tout = (TH2D*)tb->Clone(0);
	for(int i=1;i<=y;i++)
	{
		for(int j=1;j<=pt;j++)
		{
			ifstream f(Form("../../../Yield/%s/3_Result/2DFit/txt_n%dy%dpt%d.txt",argv[5],N,i,j));
			double bias, biasErr, sigma1, sigma1Err, sigma2, sigma2Err, beta, betaErr, tau, tauErr, Nprompt, NpromptErr, Nfromb, NfrombErr, Ntail, NtailErr, Nbkg, NbkgErr;
			f >> bias >> biasErr >> sigma1 >> sigma1Err >> sigma2 >> sigma2Err >> beta >>  betaErr >> tau >> tauErr >> Nprompt >> NpromptErr >> Nfromb >> NfrombErr >> Ntail >> NtailErr >> Nbkg >> NbkgErr;
			double Np = Nprompt;
			double Nb = Nfromb;
			double ep = tp->GetBinContent(j,i);
			double eb = tb->GetBinContent(j,i);
			cout << Nprompt << endl;
			tout->SetBinContent(j,i,(Np+Nb)/(Np/ep+Nb/eb));
		}
	}
	tout->Write();
	out->Close();
	return 0;
}
