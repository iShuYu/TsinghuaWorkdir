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
	TFile *out = new TFile(argv[4],"recreate");
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
	TH2D *resultJNp[Nnbin];
	TH2D *resultPNp[Nnbin];
	TH2D *resultJNb[Nnbin];
	TH2D *resultPNb[Nnbin];
	for(int i=0; i<Nnbin; i++)
	{
		resultJNp[i] = new TH2D(Form("Jp%d",i+1),Form("Jp%d"),Nptbin, pt, Nybin, y);
		resultPNp[i] = new TH2D(Form("Pp%d",i+1),Form("Pp%d"),Nptbin, pt, Nybin, y);
		resultJNb[i] = new TH2D(Form("Jb%d",i+1),Form("Jb%d"),Nptbin, pt, Nybin, y); 
                resultPNb[i] = new TH2D(Form("Pb%d",i+1),Form("Pb%d"),Nptbin, pt, Nybin, y);
		for(int j=0; j<Nybin; j++)
		{
			for(int k=0; k<Nptbin; k++)
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
				resultJNp[i]->SetBinContent(k+1,j+1,JCSp[i][j][k]);
				resultJNp[i]->SetBinError(k+1,j+1,JCSp_Err[i][j][k]);
				resultPNp[i]->SetBinContent(k+1,j+1,PCSp[i][j][k]);
                                resultPNp[i]->SetBinError(k+1,j+1,PCSp_Err[i][j][k]);
				resultJNb[i]->SetBinContent(k+1,j+1,JCSb[i][j][k]);
                                resultJNb[i]->SetBinError(k+1,j+1,JCSb_Err[i][j][k]);
                                resultPNb[i]->SetBinContent(k+1,j+1,PCSb[i][j][k]);
                                resultPNb[i]->SetBinError(k+1,j+1,PCSb_Err[i][j][k]);
			}
		resultJNp[i] -> Write();
		resultJNb[i] -> Write();
		resultPNp[i] -> Write();
		resultPNb[i] -> Write();
		}
	}
	out -> Close();
	return 0;
}


