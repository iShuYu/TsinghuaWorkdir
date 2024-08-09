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
	for(int ii=0; ii<13; ii++){
		TFile *out = new TFile(Form("../../3_Result/reweight/MUL/PVN_Nch%d.root", ii),"recreate");
		double lo = -60+10*ii;
		double hi = 60+10*ii;
	TH2D *Tp = new TH2D("Tp","Tp",60,0,240,60,0,120);
	for(int i=0;i<N;i++)
	{
		mp->GetEntry(i);
		double PVZ = M.PVZ[0];
		if(PVZ>hi||PVZ<lo) continue;
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
		double PVZ = Mb.PVZ[0];
		if(PVZ>hi||PVZ<lo) continue;
                Tb -> Fill(PVN, Nch);
        }
	Tp -> Write();
	Tb -> Write();
	out -> Close();
	}
	return 0;
}
