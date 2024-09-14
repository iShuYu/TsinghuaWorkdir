#define CBSplotDecayTree_cxx
#define mct_cxx
#include <TStyle.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2D.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <TCanvas.h>
#include <TROOT.h>
#include <TLegend.h>
#include "../../0_CFile/header/CBSplotDecayTree.h"
#include "./mct.h"
using namespace std;
int main(int argc, char* argv[])
{
	//input
	TFile *input = TFile::Open("../../3_Result/reweight/dNcharge_Reweight.root");
	TH1D *reweightNB = (TH1D*)input->Get("reweightNN");
	TH1D *reweightp = (TH1D*)input->Get("reweightpN");
	TH1D *reweightb = (TH1D*)input->Get("reweightbN");
	
	//Fill sweight data
	TChain *m = new TChain("mct");
	m -> Add("../../../../../workdir/Yield/rawdata/1_Rootfile/MCtracks/Psi2S/Tuple.root");
	mct M(m);
	int N = m->GetEntries();
	TH2D *Tp = new TH2D("Tp","Tp",60,0,180,80,0,160);
	TH2D *Tb = new TH2D("Tb","Tb",60,0,180,80,0,160);
	TH2D *Tn = new TH2D("Tn","Tn",60,0,180,80,0,160);
	for(int i=0;i<N;i++)
	{
		m->GetEntry(i);
		double PVN = M.PVNTRACKS[0];
		//double wb = reweightb -> GetBinContent(reweightb->FindBin(PVN));
		//double wp = reweightp -> GetBinContent(reweightp->FindBin(PVN));
		double wn = reweightNB -> GetBinContent(reweightNB->FindBin(PVN));
		double Nch = M.Nch;
		//Tp -> Fill(PVN, Nch, wp);
		//Tb -> Fill(PVN, Nch, wb);
		Tn -> Fill(PVN, Nch, wn);
	}
	TChain *mp = new TChain("mct");
        mp -> Add("../../../../../workdir/Yield/rawdata/1_Rootfile/MCtracks/Psi2S/Tuplep.root");
        mct MP(mp);
	N = mp->GetEntries();
	for(int i=0;i<N;i++)
        {
                mp->GetEntry(i);
                double PVN = MP.PVNTRACKS[0];
                //double wb = reweightb -> GetBinContent(reweightb->FindBin(PVN));
                double wp = reweightp -> GetBinContent(reweightp->FindBin(PVN));
                //double wn = reweightNB -> GetBinContent(reweightNB->FindBin(PVN));
                double Nch = MP.Nch;
                Tp -> Fill(PVN, Nch, wp);
                //Tb -> Fill(PVN, Nch, wb);
                //Tn -> Fill(PVN, Nch, wn);
        }
	TChain *mb = new TChain("mct");
        mb -> Add("../../../../../workdir/Yield/rawdata/1_Rootfile/MCtracks/Psi2S/Tupleb.root");
        mct MB(mb);
        N = mb->GetEntries();
        for(int i=0;i<N;i++)
        {
                mb->GetEntry(i);
                double PVN = MB.PVNTRACKS[0];
                //double wb = reweightb -> GetBinContent(reweightb->FindBin(PVN));
                double wb = reweightb -> GetBinContent(reweightb->FindBin(PVN));
                //double wn = reweightNB -> GetBinContent(reweightNB->FindBin(PVN));
                double Nch = MB.Nch;
                Tb -> Fill(PVN, Nch, wb);
                //Tb -> Fill(PVN, Nch, wb);
                //Tn -> Fill(PVN, Nch, wn);
        }

	TFile *out = new TFile("../../3_Result/reweight/PVN_Nch.root","recreate");
	Tp -> Write();
	Tb -> Write();
	Tn -> Write();
	out -> Close();
	return 0;
}
