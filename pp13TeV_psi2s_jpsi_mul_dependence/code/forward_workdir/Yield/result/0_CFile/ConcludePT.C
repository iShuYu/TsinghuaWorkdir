#include <math.h>
#include <fstream>
#include <TFile.h>
#include <iostream>
#include <TH1.h>
#include <TH2.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "lhcbStyle.h"
using namespace std;
int main(int argc,char*argv[])
{
	gROOT->SetBatch(true);
        setLHCbStyle();
        gStyle->SetPalette(55);
        gStyle->SetPaintTextFormat("4.3f");
        TH1::SetDefaultSumw2();
        double nbin, ybin, ptbin;
        int Nnbin, Nybin, Nptbin;
	//input binning scheme
	ifstream nconfig(argv[1]);
	ifstream yconfig(argv[2]);
        ifstream ptconfig(argv[3]);
	nconfig >> Nnbin;
        yconfig >> Nybin;
        ptconfig >> Nptbin;
        double n[Nnbin+1], y[Nybin+1], pt[Nptbin+1];
        for(int i=0; i<=Nnbin; i++)
	{
		nconfig >> nbin;
		n[i] = nbin;
	}
	for(int i=0; i<=Nybin; i++)
        {
                yconfig >> ybin;
                y[i]=ybin;
        }
        for(int i=0; i<=Nptbin; i++)
        {
                ptconfig >> ptbin;
                pt[i]=ptbin;
        }
        int color[Nybin];
        int marker[Nptbin];
	//output:
	//TFile *out = new TFile(argv[4],"recreate");
        //CS = Cross section
	double JCSb[Nnbin][Nybin][Nptbin];
	double JCSb_Err[Nnbin][Nybin][Nptbin];
	double JCSp[Nnbin][Nybin][Nptbin];
	double JCSp_Err[Nnbin][Nybin][Nptbin];
	double PCSb[Nnbin][Nybin][Nptbin];
        double PCSb_Err[Nnbin][Nybin][Nptbin];
        double PCSp[Nnbin][Nybin][Nptbin];
        double PCSp_Err[Nnbin][Nybin][Nptbin];
	double Jp[5] = {0.};
       	double Pp[5] = {0.};
	double JpErr[5] = {0.};
	double PpErr[5] = {0.};
	//Save the Cross section results:
	ofstream out(argv[4]);	
	for(int k=0; k<Nptbin; k++)
	{
		for(int j=0; j<Nybin; j++)
		{
			for(int i=0; i<Nnbin; i++)
			{
				ifstream JCS(Form("../Jpsi_result/cross_section_ub/n%dy%dpt%d.txt",i+1,j+1,k+1));
				ifstream PCS(Form("../Psi2S_result/cross_section_ub/n%dy%dpt%d.txt",i+1,j+1,k+1));
				JCS >> JCSp[i][j][k];
				JCS >> JCSb[i][j][k];
				JCS >> JCSp_Err[i][j][k];
				JCS >> JCSb_Err[i][j][k];
				PCS >> PCSp[i][j][k];
                                PCS >> PCSb[i][j][k];
                                PCS >> PCSp_Err[i][j][k];
                                PCS >> PCSb_Err[i][j][k];
				Jp[k] = Jp[k]+JCSp[i][j][k];
				Pp[k] = Pp[k]+PCSp[i][j][k];
				JpErr[k] = JpErr[k]+JCSp_Err[i][j][k]*JCSp_Err[i][j][k];
				PpErr[k] = PpErr[k]+PCSp_Err[i][j][k]*PCSp_Err[i][j][k];
			}
		}
		out << Pp[k]/Jp[k]*7.93*0.001/5.961/0.01 << endl;
	       	//out << Pp[k]/Jp[k]*sqrt(JpErr[k]*JpErr[k]/Jp[k]/Jp[k]+PpErr[k]*PpErr[k]/Pp[k]/Pp[k]) << endl;
	}
	out.close();
	return 0;
}


