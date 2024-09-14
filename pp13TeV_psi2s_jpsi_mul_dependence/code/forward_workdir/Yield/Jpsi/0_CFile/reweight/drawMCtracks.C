#define mctNew_cxx
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
#include "./mctNew.h"
using namespace std;
int main(int argc, char* argv[])
{	
	//input
	TChain *mp = new TChain("mct");
	mp -> Add("../../../../../workdir/Yield/Jpsi/3_Result/RegenVar/newVarMCp.root");
	mctNew M(mp);
	int N = mp->GetEntries();
	TH2D *Tp = new TH2D("Tp","Tp",60,0,240,60,0,120);
	for(int i=0;i<N;i++)
	{
		mp->GetEntry(i);
		double PVN = M.PVNcor;
		double Nch = M.Nch;
		Tp -> Fill(PVN, Nch);
	}
	TChain *mb = new TChain("mct");
        mb -> Add("../../../../../workdir/Yield/Jpsi/3_Result/RegenVar/newVarMCb.root");
        mctNew Mb(mb);
        N = mb->GetEntries();
        TH2D *Tb = new TH2D("Tb","Tb",60,0,240,60,0,120);
        for(int i=0;i<N;i++)
        {
                mb->GetEntry(i);
                double PVN = Mb.PVNcor;
                double Nch = Mb.Nch;
                Tb -> Fill(PVN, Nch);
        }
	TFile *out = new TFile("../../3_Result/reweight/PVN_Nch.root","recreate");
	Tp -> Write();
	Tb -> Write();
	out -> Close();
	return 0;
}
