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
	ofstream out(argv[4]);
        //CS = Cross section
	double JCSb[Nnbin][Nybin][Nptbin];
	double JCSb_Err[Nnbin][Nybin][Nptbin];
	double JCSp[Nnbin][Nybin][Nptbin];
	double JCSp_Err[Nnbin][Nybin][Nptbin];
	double PCSb[Nnbin][Nybin][Nptbin];
        double PCSb_Err[Nnbin][Nybin][Nptbin];
        double PCSp[Nnbin][Nybin][Nptbin];
        double PCSp_Err[Nnbin][Nybin][Nptbin];
	//Save the Cross section results:
	double JintPTp=0;
	double JintPTb=0;
	double PintPTp=0;
	double PintPTb=0;
	for(int i=0; i<Nptbin; i++)
	{
		for(int j=0; j<Nybin; j++)
		{
			for(int k=0; k<Nnbin; k++)
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
				JintPTp = JintPTp+JCSp[i][j][k];
				JintPTb = JintPTb+JCSb[i][j][k];
				PintPTp = PintPTp+PCSp[i][j][k];
				PintPTb = PintPTb+PCSb[i][j][k];	
			}
		}
	}
	out << PintPTp*7.93*0.001/JintPTp/0.0593 << endl;
	out.close();
	return 0;
}


