#define GenMC_cxx
#include <iostream>
#include <fstream>
#include <TH2.h>
#include <TH1.h>
#include <TFile.h>
#include <TRandom3.h>
#include <TChain.h>
#include "0_header/GenMC.h"
using namespace std;
int main(int argc, char* argv[])
{
	 //random generator and setting
        TRandom3 *ran = new TRandom3();
        ran -> SetSeed(0);
        TH1::SetDefaultSumw2();


	TH1::SetDefaultSumw2();
	const double minETA = 1.595978718; //10 mrad
	const double maxETA = 5.298309033; //400 mrad
        double ybin, ptbin;
        int Nybin, Nptbin;
	ifstream yconfig(argv[1]);
        ifstream ptconfig(argv[2]);
	yconfig >> Nybin;
        ptconfig >> Nptbin;
	double y[Nybin+1], pt[Nptbin+1];
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
	for(int i=0; i<Nybin; i++)
	{
		color[i] = 2*i+1;
		marker[i] = 20+i*2;
	}
	
	//input reweight
        TFile reweight("../4_Result/Reweight/Reweight.root");
        TH1D *wJ_hiPT = (TH1D*)reweight.Get("wJ_hiPT");
        TH1D *wJ_loPT = (TH1D*)reweight.Get("wJ_loPT");
        TH1D *wP_hiPT = (TH1D*)reweight.Get("wP_hiPT");
        TH1D *wP_loPT = (TH1D*)reweight.Get("wP_loPT");
        TH1D *wJ_hiY = (TH1D*)reweight.Get("wJ_hiY");
        TH1D *wJ_loY = (TH1D*)reweight.Get("wJ_loY");
        TH1D *wP_hiY = (TH1D*)reweight.Get("wP_hiY");
        TH1D *wP_loY = (TH1D*)reweight.Get("wP_loY");

        //generate a random duplicate of PT and T reweight
        int NPT = wJ_hiPT -> GetNbinsX();
        int NY = wJ_hiY -> GetNbinsX();
        TH1D *CwJ_hiPT = (TH1D*)wJ_hiPT->Clone("CwJ_hiPT");
        TH1D *CwJ_loPT = (TH1D*)wJ_loPT->Clone("CwP_loPT");
        TH1D *CwP_hiPT = (TH1D*)wP_hiPT->Clone("CwJ_hiPT");
        TH1D *CwP_loPT = (TH1D*)wP_loPT->Clone("CwP_loPT");
        TH1D *CwJ_hiY = (TH1D*) wJ_hiY->Clone("CwJ_hiY");
        TH1D *CwJ_loY = (TH1D*) wJ_loY->Clone("CwP_loY");
        TH1D *CwP_hiY = (TH1D*) wP_hiY->Clone("CwJ_hiY");
        TH1D *CwP_loY = (TH1D*) wP_loY->Clone("CwP_loY");
        double c, cErr;
	for(int i=1;i<=NPT;i++)
        {
                c = wJ_hiPT->GetBinContent(i);
                cErr = wJ_hiPT->GetBinError(i);
                CwJ_hiPT->SetBinContent(i, ran->Gaus(c,cErr));
                c = wJ_loPT->GetBinContent(i);
                cErr = wJ_loPT->GetBinError(i);
                CwJ_loPT->SetBinContent(i, ran->Gaus(c,cErr));
                c = wP_hiPT->GetBinContent(i);
                cErr = wP_hiPT->GetBinError(i);
                CwP_hiPT->SetBinContent(i, ran->Gaus(c,cErr));
                c = wP_loPT->GetBinContent(i);
                cErr = wP_loPT->GetBinError(i);
                CwP_loPT->SetBinContent(i, ran->Gaus(c,cErr));
        }
        for(int i=1; i<=NY; i++)
        {
                c = wJ_hiY->GetBinContent(i);
                cErr = wJ_hiY->GetBinError(i);
                CwJ_hiY->SetBinContent(i, ran->Gaus(c,cErr));
                c = wJ_loY->GetBinContent(i);
                cErr = wJ_loY->GetBinError(i);
                CwJ_loY->SetBinContent(i, ran->Gaus(c,cErr));
                c = wP_hiY->GetBinContent(i);
                cErr = wP_hiY->GetBinError(i);
                CwP_hiY->SetBinContent(i, ran->Gaus(c,cErr));
                c = wP_loY->GetBinContent(i);
                cErr = wP_loY->GetBinError(i);
                CwP_loY->SetBinContent(i, ran->Gaus(c,cErr));
        }
	//choose hi or lo pT-Y parameterizaiton 1 for hi, 2 for lo, 0 for no reweight
        int flag;
        sscanf(argv[3],"%d",&flag);
	double PTweight, Yweight;
	//input
	TChain* chainJ = new TChain("MCDecayTreeTuple/MCDecayTree");
	chainJ -> Add(argv[4]);
	GenMC myTreeJ(chainJ);
	TChain* chainP = new TChain("MCDecayTreeTuple/MCDecayTree");
        chainP -> Add(argv[5]);
        GenMC myTreeP(chainP);
	//Loop
	TH2D *h_totJ = new TH2D("h_totJ", "h_totJ", Nptbin, pt, Nybin, y);
	TH2D *h_accJ = new TH2D("h_accJ", "h_accJ", Nptbin, pt, Nybin, y);
       	TH2D *h_totP = new TH2D("h_totP", "h_totP", Nptbin, pt, Nybin, y);
        TH2D *h_accP = new TH2D("h_accP", "h_accP", Nptbin, pt, Nybin, y);
	int NJ = chainJ->GetEntries();
	double psi_pt,psi_y,mum_ETA,mup_ETA;
	for(int i=0; i<NJ ; i++)
	{
		chainJ->GetEntry(i);
		if(myTreeJ.MCPVZ[0]>120) continue;
		//calculate y and pt for Psi and mu
		psi_pt = myTreeJ.psi_TRUEPT;
		psi_y = -0.5*log((myTreeJ.psi_TRUEP_E+myTreeJ.psi_TRUEP_Z)/(myTreeJ.psi_TRUEP_E-myTreeJ.psi_TRUEP_Z))-0.465;
		double mumP = sqrt(myTreeJ.mum_TRUEPT*myTreeJ.mum_TRUEPT+myTreeJ.mum_TRUEP_Z*myTreeJ.mum_TRUEP_Z);
		double mupP = sqrt(myTreeJ.mup_TRUEPT*myTreeJ.mup_TRUEPT+myTreeJ.mup_TRUEP_Z*myTreeJ.mup_TRUEP_Z);
		double mumPZ = myTreeJ.mum_TRUEP_Z;
		double mupPZ = myTreeJ.mup_TRUEP_Z;
		mum_ETA = 0.5*log((mumP+mumPZ)/(mumP-mumPZ));
		mup_ETA = 0.5*log((mupP+mupPZ)/(mupP-mupPZ));
		PTweight = CwJ_hiPT->GetBinContent(CwJ_hiPT->FindBin(psi_pt));
                Yweight = CwJ_hiY->GetBinContent(CwJ_hiY->FindBin(psi_y));
                if(flag==2)
                {
                        PTweight = CwJ_loPT->GetBinContent(CwJ_loPT->FindBin(psi_pt));
                        Yweight = CwJ_loY->GetBinContent(CwJ_loY->FindBin(psi_y));
                }
                if(flag==0)
                {
                        PTweight = 1.;
                        Yweight = 1.;
                }
		h_totJ->Fill(psi_pt,psi_y, PTweight*Yweight);
		if(mum_ETA<minETA) continue;
		if(mup_ETA<minETA) continue;
		if(mum_ETA>maxETA) continue;
                if(mup_ETA>maxETA) continue;
		h_accJ->Fill(psi_pt,psi_y, PTweight*Yweight);
	}
	int NP = chainP->GetEntries();
        for(int i=0; i<NP ; i++)
        {
                chainP->GetEntry(i);
		if(myTreeP.MCPVZ[0]>120) continue;
                //calculate y and pt for Psi and mu
                psi_pt = myTreeP.psi_TRUEPT;
                psi_y = -0.5*log((myTreeP.psi_TRUEP_E+myTreeP.psi_TRUEP_Z)/(myTreeP.psi_TRUEP_E-myTreeP.psi_TRUEP_Z))-0.465;
                double mumP = sqrt(myTreeP.mum_TRUEPT*myTreeP.mum_TRUEPT+myTreeP.mum_TRUEP_Z*myTreeP.mum_TRUEP_Z);
                double mupP = sqrt(myTreeP.mup_TRUEPT*myTreeP.mup_TRUEPT+myTreeP.mup_TRUEP_Z*myTreeP.mup_TRUEP_Z);
                double mumPZ = myTreeP.mum_TRUEP_Z;
                double mupPZ = myTreeP.mup_TRUEP_Z;
                mum_ETA = 0.5*log((mumP+mumPZ)/(mumP-mumPZ));
                mup_ETA = 0.5*log((mupP+mupPZ)/(mupP-mupPZ));
		PTweight = CwP_hiPT->GetBinContent(CwP_hiPT->FindBin(psi_pt));
                Yweight = CwP_hiY->GetBinContent(CwP_hiY->FindBin(psi_y));
                if(flag==2)
                {
                        PTweight = CwP_loPT->GetBinContent(CwP_loPT->FindBin(psi_pt));
                        Yweight = CwP_loY->GetBinContent(CwP_loY->FindBin(psi_y));
                }
                if(flag==0)
                {
                        PTweight = 1.;
                        Yweight = 1.;
                }
                h_totP->Fill(psi_pt,psi_y, PTweight*Yweight);
                if(mum_ETA<minETA) continue;
                if(mup_ETA<minETA) continue;
                if(mum_ETA>maxETA) continue;
                if(mup_ETA>maxETA) continue;
                h_accP->Fill(psi_pt,psi_y,PTweight*Yweight);
        }
	TH2D *h_effJ = new TH2D("h_effJ", "h_effJ", Nptbin, pt, Nybin, y);
	TH2D *h_effP = new TH2D("h_effP", "h_effP", Nptbin, pt, Nybin, y);
	h_effJ -> Divide(h_accJ, h_totJ, 1, 1, "B");
	h_effP -> Divide(h_accP, h_totP, 1, 1, "B");
	TH2D *ratio_acc = new TH2D("ratio_acc","ratio_acc", Nptbin, pt, Nybin, y);
	ratio_acc -> Divide(h_effJ, h_effP, 1, 1, "B");	
	TFile* fnew = new TFile(argv[6],"recreate");
        h_effJ->Write();
	h_effP->Write();
	ratio_acc->Write();
	fnew -> Close();
	return 0;
}

