#include <TAxis.h>
#include <fstream>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include "lhcbStyle.h"
using namespace std;
int main(int argc, char* argv[])
{
	setLHCbStyle();
	TFile input(argv[1]);
	ifstream nbin(argv[2]);
	ifstream ybin(argv[3]);
	ifstream ptbin(argv[4]);
	int Nn, Npt, Ny;
	nbin >> Nn;
	ybin >> Ny;
	ptbin >> Npt;
	double n[Nn];
	for(int i=0; i<=Nn; i++)
	{
		nbin >> n[i];
	}

	TFile *out = new TFile(argv[5], "recreate");
	TH1D *allp = new TH1D("allp","allp",Nn,n);
	TH1D *allb = new TH1D("allb","allb",Nn,n);
	double BJpsi = 0;
	double BPsi2S = 0;
	double PJpsi = 0;
        double PPsi2S = 0;
	double BJpt[5] = {0};
	double PJpt[5] = {0};
	double BPpt[5] = {0};
	double PPpt[5] = {0};
	double BJy[3] = {0};
        double PJy[3] = {0};
        double BPy[3] = {0};
        double PPy[3] = {0};
	for(int i=1; i<=Nn; i++)
	{
		ifstream E(Form("../../../Systematic/AllErr/3_Result/n%d_int_OnlySysErr.txt",i));
		TH2D *Jp = (TH2D*)input.Get(Form("Jp%d",i));
		TH2D *Jb = (TH2D*)input.Get(Form("Jb%d",i));
		TH2D *Pp = (TH2D*)input.Get(Form("Pp%d",i));
		TH2D *Pb = (TH2D*)input.Get(Form("Pb%d",i));
		double SumEJp = 0;
		double SumEJb = 0;
		double SumEPp = 0;
		double SumEPb = 0;
		double SumCJp = 0;
		double SumCJb = 0;
		double SumCPp = 0;
		double SumCPb = 0;
		for(int j=1; j<=Ny; j++)
		{
			for(int k=1; k<=Npt; k++)
			{
				double CJp = Jp->GetBinContent(k,j);
				double CJb = Jb->GetBinContent(k,j);
				double CPp = Pp->GetBinContent(k,j);
				double CPb = Pb->GetBinContent(k,j);
				double EJp = Jp->GetBinError(k,j);
				double EJb = Jb->GetBinError(k,j);
				double EPp = Pp->GetBinError(k,j);
				double EPb = Pb->GetBinError(k,j);
				SumCJp = SumCJp+CJp;
				SumCJb = SumCJb+CJb;
				SumEJp = SumEJp+EJp*EJp;
				SumEJb = SumEJb+EJb*EJb;
				SumCPp = SumCPp+CPp;
				SumCPb = SumCPb+CPb;
				SumEPp = SumEPp+EPp*EPp;
				SumEPb = SumEPb+EPb*EPb;
				BJpt[k-1] = BJpt[k-1]+CJb;
				PJpt[k-1] = PJpt[k-1]+CJp;
				BPpt[k-1] = BPpt[k-1]+CPb;
                                PPpt[k-1] = PPpt[k-1]+CPp;
				BJy[j-1] = BJy[j-1]+CJb;
                                PJy[j-1] = PJy[j-1]+CJp;
                                BPy[j-1] = BPy[j-1]+CPb;
                                PPy[j-1] = PPy[j-1]+CPp;
				 
			}
		}
		PJpsi = PJpsi + SumCJp;
		BJpsi = BJpsi + SumCJb;
		PPsi2S = PPsi2S + SumCPp;
                BPsi2S = BPsi2S + SumCPb;
	}
	for(int i=1; i<=Nn; i++)
        {	
		ifstream E(Form("../../../Systematic/AllErr/3_Result/n%d_int_OnlySysErr.txt",i));
                TH2D *Jp = (TH2D*)input.Get(Form("Jp%d",i));
                TH2D *Jb = (TH2D*)input.Get(Form("Jb%d",i));
                TH2D *Pp = (TH2D*)input.Get(Form("Pp%d",i));
                TH2D *Pb = (TH2D*)input.Get(Form("Pb%d",i));
                double SumEJp = 0;
                double SumEJb = 0;
                double SumEPp = 0;
                double SumEPb = 0;
                double SumCJp = 0;
                double SumCJb = 0;
                double SumCPp = 0;
                double SumCPb = 0;
                for(int j=1; j<=Ny; j++)
                {
                        for(int k=1; k<=Npt; k++)
                        {
                                double CJp = Jp->GetBinContent(k,j);
                                double CJb = Jb->GetBinContent(k,j);
                                double CPp = Pp->GetBinContent(k,j);
                                double CPb = Pb->GetBinContent(k,j);
                                double EJp = Jp->GetBinError(k,j);
                                double EJb = Jb->GetBinError(k,j);
                                double EPp = Pp->GetBinError(k,j);
                                double EPb = Pb->GetBinError(k,j);
                                SumCJp = SumCJp+CJp;
                                SumCJb = SumCJb+CJb;
                                SumEJp = SumEJp+EJp*EJp;
                                SumEJb = SumEJb+EJb*EJb;
                                SumCPp = SumCPp+CPp;
                                SumCPb = SumCPb+CPb;
                                SumEPp = SumEPp+EPp*EPp;
                                SumEPb = SumEPb+EPb*EPb;
                        }
               	}
		double Errp, Errb;
		E >> Errp >> Errb;
		allp -> SetBinContent(i,SumCPp/SumCJp*PJpsi/PPsi2S);
		allp -> SetBinError(i,SumCPp/SumCJp*Errp*PJpsi/PPsi2S);
		allb -> SetBinContent(i,SumCPb/SumCJb*BJpsi/BPsi2S);
		allb -> SetBinError(i,SumCPb/SumCJb*Errb*BJpsi/BPsi2S);
		E.close();
	}
	out->cd();
	allp -> Write();
	allb -> Write();
	TH1D *pPt[Npt];
	TH1D *bPt[Npt];
	for(int k=1; k<=Npt; k++)
	{
		pPt[k] = new TH1D(Form("pPt%d",k),Form("pPt%d",k),Nn,n);
		bPt[k] = new TH1D(Form("bPt%d",k),Form("bPt%d",k),Nn,n);
		for(int i=1; i<=Nn; i++)
		{
			double SumEJp = 0;
			double SumEJb = 0;
			double SumEPp = 0;
			double SumEPb = 0;
			double SumCJp = 0;
			double SumCJb = 0;
			double SumCPp = 0;
			double SumCPb = 0;
			TFile *E = TFile::Open(Form("../../../Systematic/AllErr/3_Result/n%d_int_pt_OnlySysErr.root",i));
			double Errp, Errb;
			TH1D *Ep = (TH1D*)E->Get("prompt");
			TH1D *Eb = (TH1D*)E->Get("fromb");
			Errp = Ep->GetBinContent(k);
			Errb = Eb->GetBinContent(k);
			TH2D *Jp = (TH2D*)input.Get(Form("Jp%d",i));
			TH2D *Jb = (TH2D*)input.Get(Form("Jb%d",i));
			TH2D *Pp = (TH2D*)input.Get(Form("Pp%d",i));
			TH2D *Pb = (TH2D*)input.Get(Form("Pb%d",i));
			for(int j=1; j<=Ny; j++)
			{
				double CJp = Jp->GetBinContent(k,j);
				double CJb = Jb->GetBinContent(k,j);
				double CPp = Pp->GetBinContent(k,j);
				double CPb = Pb->GetBinContent(k,j);
				double EJp = Jp->GetBinError(k,j);
				double EJb = Jb->GetBinError(k,j);
				double EPp = Pp->GetBinError(k,j);
				double EPb = Pb->GetBinError(k,j);
				SumCJp = SumCJp+CJp;
				SumCJb = SumCJb+CJb;
				SumEJp = SumEJp+EJp*EJp;
				SumEJb = SumEJb+EJb*EJb;
				SumCPp = SumCPp+CPp;
				SumCPb = SumCPb+CPb;
				SumEPp = SumEPp+EPp*EPp;
				SumEPb = SumEPb+EPb*EPb;
			}
			pPt[k] -> SetBinContent(i,SumCPp/SumCJp*PJpt[k-1]/PPpt[k-1]);
			pPt[k] -> SetBinError(i,Errp*SumCPp/SumCJp*PJpt[k-1]/PPpt[k-1]);
			bPt[k] -> SetBinContent(i,SumCPb/SumCJb*BJpt[k-1]/BPpt[k-1]);
			bPt[k] -> SetBinError(i,Errb*SumCPb/SumCJb*BJpt[k-1]/BPpt[k-1]);
			E->Close();
		}
	}
	out->cd();
	for(int k=1; k<=Npt; k++)
	{
		pPt[k]->Write();
		bPt[k]->Write();
	}

	TH1D *pY[Ny];
	TH1D *bY[Ny];
	for(int j=1; j<=Ny; j++)
	{   
		pY[j] = new TH1D(Form("pY%d",j),Form("pY%d",j),Nn,n);
		bY[j] = new TH1D(Form("bY%d",j),Form("bY%d",j),Nn,n);
		for(int i=1; i<=Nn; i++)
		{   
			double SumEJp = 0;
			double SumEJb = 0;
			double SumEPp = 0;
			double SumEPb = 0;
			double SumCJp = 0;
			double SumCJb = 0;
			double SumCPp = 0;
			double SumCPb = 0;
			TH2D *Jp = (TH2D*)input.Get(Form("Jp%d",i));
			TH2D *Jb = (TH2D*)input.Get(Form("Jb%d",i));
			TH2D *Pp = (TH2D*)input.Get(Form("Pp%d",i));
			TH2D *Pb = (TH2D*)input.Get(Form("Pb%d",i));
			TFile *E = TFile::Open(Form("../../../Systematic/AllErr/3_Result/n%d_int_y_OnlySysErr.root",i));
			double Errp, Errb;
			TH1D *Ep = (TH1D*)E->Get("prompt");
			TH1D *Eb = (TH1D*)E->Get("fromb");
			Errp = Ep->GetBinContent(j);
			Errb = Eb->GetBinContent(j);
			for(int k=1; k<=Npt; k++)
			{   
				double CJp = Jp->GetBinContent(k,j);
				double CJb = Jb->GetBinContent(k,j);
				double CPp = Pp->GetBinContent(k,j);
				double CPb = Pb->GetBinContent(k,j);
				double EJp = Jp->GetBinError(k,j);
				double EJb = Jb->GetBinError(k,j);
				double EPp = Pp->GetBinError(k,j);
				double EPb = Pb->GetBinError(k,j);
				SumCJp = SumCJp+CJp;
				SumCJb = SumCJb+CJb;
				SumEJp = SumEJp+EJp*EJp;
				SumEJb = SumEJb+EJb*EJb;
				SumCPp = SumCPp+CPp;
				SumCPb = SumCPb+CPb;
				SumEPp = SumEPp+EPp*EPp;
				SumEPb = SumEPb+EPb*EPb;
			}
			pY[j] -> SetBinContent(i,SumCPp/SumCJp*PJy[j-1]/PPy[j-1]);
			pY[j] -> SetBinError(i,Errp*SumCPp/SumCJp*PJy[j-1]/PPy[j-1]);
			bY[j] -> SetBinContent(i,SumCPb/SumCJb*BJy[j-1]/BPy[j-1]);
			bY[j] -> SetBinError(i,Errb*SumCPb/SumCJb*BJy[j-1]/BPy[j-1]);
			E->Close();
		}   
	}
	out->cd();
	for(int j=1; j<=Ny; j++)
	{   
		pY[j]->Write();
		bY[j]->Write();
	}
	out -> Close();
	return 0;
}
