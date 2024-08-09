#define mct_cxx
#include "./mct.h"
#include <TStyle.h>
#include <TH1.h>
#include <TH2D.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
	TH1::SetDefaultSumw2();

	//input scheme
	ifstream fn("../../../../../workdir/Yield/rawdata/3_Bins/nbin");
	int N;
	fn >> N;
	double bin[N+1];
	for(int i=0;i<=N;i++) {fn >> bin[i]; cout << bin[i] << endl;}

	TFile *out = new TFile("../../3_Result/reweight/TH1D_Nch_in_different_PVN.root","recreate");

	//input
	TChain *mb = new TChain("mct");
	mb -> Add("../../../../../workdir/Yield/rawdata/1_Rootfile/MCtracks/Psi2S/Tupleb.root");
	mct b(mb);
	int Nb = mb->GetEntries();
	TFile *input;
	TH1D *Tb[N];
	for(int j=0;j<N;j++)
	{
		Tb[j] = new TH1D(Form("Tb%d",j+1),Form("Tb%d",j+1),200,0,400);
		input = TFile::Open("../../3_Result/reweight/dNcharge_Reweight.root");
		TH2D *reweightb = (TH2D*)input->Get("reweightbN");
		//input -> Close();
		for(int i=0;i<Nb;i++)
		{
			mb->GetEntry(i);
			double PVN = b.PVNTRACKS[0];
			if(PVN<bin[j]||PVN>=bin[j+1]) continue;
			double Nch = b.Nch;
			double wb = reweightb->GetBinContent(reweightb->FindBin(PVN));
			Tb[j] -> Fill(Nch, wb);
		}
		out -> cd();
		Tb[j] -> Write();
	}
	TChain *mp = new TChain("mct");
        mp -> Add("../../../../../workdir/Yield/rawdata/1_Rootfile/MCtracks/Psi2S/Tuplep.root");
        mct p(mp);
        int Np = mp->GetEntries();
	TH1D *Tp[N];
        for(int j=0;j<N;j++)
        {
                Tp[j] = new TH1D(Form("Tp%d",j+1),Form("Tp%d",j+1),200,0,400);
                input = TFile::Open("../../3_Result/reweight/dNcharge_Reweight.root");
                TH2D *reweightp = (TH2D*)input->Get("reweightpN");
		//input -> Close();
                for(int i=0;i<Np;i++)
                {
                        mp->GetEntry(i);
			double PVN = p.PVNTRACKS[0];
                        if(PVN<bin[j]||PVN>=bin[j+1]) continue;
                        double Nch = p.Nch;
                        double wp = reweightp->GetBinContent(reweightp->FindBin(PVN));
                        Tp[j] -> Fill(Nch, wp);
                }
		out -> cd();
		Tp[j]->Write();
        }
	
	TChain *m = new TChain("mct");
        m -> Add("../../../../../workdir/Yield/rawdata/1_Rootfile/MCtracks/Psi2S/Tuple.root");
        mct bp(m);
	int NN = m->GetEntries();
	TH1D *Tbp = new TH1D("Tbp","Tbp",400,0,400);
	input = TFile::Open("../../3_Result/reweight/dNcharge_Reweight.root");
        TH2D *reweightbp = (TH2D*)input->Get("reweightNN");
	//input -> Close();
	for(int i=0;i<NN;i++)
        {
                m->GetEntry(i);
		double PVN = bp.PVNTRACKS[0];
                double Nch = bp.Nch;
                double wn = reweightbp->GetBinContent(reweightbp->FindBin(PVN));
                Tbp -> Fill(Nch, wn);
        }
	out -> cd();
	Tbp -> Write();
	out -> Close();
	return 0;
}
