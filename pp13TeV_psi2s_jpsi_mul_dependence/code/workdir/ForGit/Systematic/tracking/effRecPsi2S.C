#define After_rec_sel_cxx
#define mct_cxx
#include <TH1.h>
#include <TH2.h>
#include <TStyle.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <TAxis.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TChain.h>
#include "../../../Yield/Psi2S/0_CFile/header/lhcbStyle.h"
#include "../../../Yield/Psi2S/0_CFile/header/After_rec_sel.h"
#include "../../../Yield/Psi2S/0_CFile/header/mct.h"
using namespace std;
int main(int argc, char *argv[])
{
	gROOT->SetBatch(true);
        setLHCbStyle();
        gStyle->SetPalette(55);
        gStyle->SetPaintTextFormat("4.3f");
        TH1::SetDefaultSumw2();
	double ybin, ptbin;
        int Nybin, Nptbin;
	int index;
        sscanf(argv[11],"%d",&index);
	//input binning scheme
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
                color[i] = i;
                marker[i] = i;
        }
	//input reweight result:
	TFile reweight(argv[3]);
        TH1D *reweightN =(TH1D*)reweight.Get(argv[12]);
        //TH1D *reweightY =(TH1D*)reweight.Get("reweightY");
        TH2D *reweightPTY =(TH2D*)reweight.Get(argv[13]);
	//input Tracking Efficiency result from trackcalib
	TFile *TrackCalibU = TFile::Open(argv[4]);
	TH2D *TrackingTableU = (TH2D*) TrackCalibU->Get(Form("t%d",index));
	TFile *TrackCalibD = TFile::Open(argv[5]);
        TH2D *TrackingTableD = (TH2D*) TrackCalibD->Get(Form("t%d",index));
	//Loop
	double mum_Tweight, mup_Tweight;
	double nweight, ptyweight;
	double mum_P, mup_P, mum_ETA, mup_ETA;
	TChain *before_rec_selU = new TChain("mct");
	TChain *after_rec_selU = new TChain("DecayTree");
	before_rec_selU -> Add(argv[6]);
	after_rec_selU -> Add(argv[7]);
	TChain *before_rec_selD = new TChain("mct");
        TChain *after_rec_selD = new TChain("DecayTree");
        before_rec_selD -> Add(argv[8]);
        after_rec_selD -> Add(argv[9]);
	mct BU(before_rec_selU);
	After_rec_sel AU(after_rec_selU);
	mct BD(before_rec_selD);
        After_rec_sel AD(after_rec_selD);
	int NBU = before_rec_selU->GetEntries();
	int NAU = after_rec_selU->GetEntries();
	int NBD = before_rec_selD->GetEntries();
        int NAD = after_rec_selD->GetEntries();
	double mctPT, mctY, DTPT, DTY;
	TH2D *h_B = new TH2D("h_B","h_B", Nptbin, pt, Nybin, y);
	TH2D *h_A = new TH2D("h_A","h_A", Nptbin, pt, Nybin, y);
	TH2D *h_eff = new TH2D("h_eff", "h_eff", Nptbin, pt, Nybin, y);
	for(int i=0; i<NBU; i++)
	{
		before_rec_selU -> GetEntry(i);
		if(BU.PVZ[0]<-60) continue;
		mctPT = BU.psi_TRUEPT;
		mctY = 0.5*log((BU.psi_TRUEP_E+BU.psi_TRUEP_Z)/(BU.psi_TRUEP_E-BU.psi_TRUEP_Z));
		nweight = reweightN->GetBinContent(reweightN->FindBin(BU.PVNTRACKS[0]));
                ptyweight = reweightPTY->GetBinContent(reweightPTY->FindBin(mctPT,mctY));
                //yweight = reweightY->GetBinContent(reweightY->FindBin(mctY));
		h_B -> Fill(mctPT, mctY, nweight*ptyweight);
	}
	for(int i=0; i<NAU; i++)
	{
		after_rec_selU -> GetEntry(i);
		DTPT = AU.psi_PT;
		DTY = AU.psi_Y;
		mup_ETA = 0.5 * log((AU.mup_P + AU.mup_PZ)/(AU.mup_P - AU.mup_PZ));
		mum_ETA = 0.5 * log((AU.mum_P + AU.mum_PZ)/(AU.mum_P - AU.mum_PZ));
		mum_P = AU.mum_P;
                mup_P = AU.mup_P;
		int Tbinm = TrackingTableU->FindBin(mum_P,mum_ETA);
                int Tbinp = TrackingTableU->FindBin(mup_P,mup_ETA);
		mum_Tweight = TrackingTableU -> GetBinContent(Tbinm);
		mup_Tweight = TrackingTableU -> GetBinContent(Tbinp);
		if(mum_Tweight==0) mum_Tweight = 1.;
                if(mup_Tweight==0) mup_Tweight = 1.;
		nweight = reweightN->GetBinContent(reweightN->FindBin(AU.PVNTRACKS[0]));
                ptyweight = reweightPTY->GetBinContent(reweightPTY->FindBin(DTPT,DTY));
                //yweight = reweightY->GetBinContent(reweightY->FindBin(DTY));
		h_A -> Fill(DTPT, DTY, mum_Tweight*mup_Tweight*nweight*ptyweight);
	}
	for(int i=0; i<NBD; i++)
        {
                before_rec_selD -> GetEntry(i);
		if(BD.PVZ[0]<-60) continue;
                mctPT = BD.psi_TRUEPT;
                mctY = 0.5*log((BD.psi_TRUEP_E+BD.psi_TRUEP_Z)/(BD.psi_TRUEP_E-BD.psi_TRUEP_Z));
                nweight = reweightN->GetBinContent(reweightN->FindBin(BD.PVNTRACKS[0]));
                ptyweight = reweightPTY->GetBinContent(reweightPTY->FindBin(mctPT,mctY));
                //yweight = reweightY->GetBinContent(reweightY->FindBin(mctY));
                h_B -> Fill(mctPT, mctY, nweight*ptyweight);
        }
        for(int i=0; i<NAD; i++)
        {
                after_rec_selD -> GetEntry(i);
                DTPT = AD.psi_PT;
                DTY = AD.psi_Y;
                mup_ETA = 0.5 * log((AD.mup_P + AD.mup_PZ)/(AD.mup_P - AD.mup_PZ));
                mum_ETA = 0.5 * log((AD.mum_P + AD.mum_PZ)/(AD.mum_P - AD.mum_PZ));
                mum_P = AD.mum_P;
                mup_P = AD.mup_P;
                int Tbinm = TrackingTableD->FindBin(mum_P,mum_ETA);
                int Tbinp = TrackingTableD->FindBin(mup_P,mup_ETA);
                mum_Tweight = TrackingTableD -> GetBinContent(Tbinm);
                mup_Tweight = TrackingTableD -> GetBinContent(Tbinp);
		if(mum_Tweight==0) mum_Tweight = 1.;
                if(mup_Tweight==0) mup_Tweight = 1.;
		nweight = reweightN->GetBinContent(reweightN->FindBin(AD.PVNTRACKS[0]));
                ptyweight = reweightPTY->GetBinContent(reweightPTY->FindBin(DTPT,DTY));
                //yweight = reweightY->GetBinContent(reweightY->FindBin(DTY));
                h_A -> Fill(DTPT, DTY, mum_Tweight*mup_Tweight*nweight*ptyweight);
        }
	//calculate
	h_eff->Divide(h_A, h_B, 1., 1., "B");
	TH1D* rec_sel[Nybin];
        for (int i=0; i<Nybin; i++)
        {
                rec_sel[i] = new TH1D(Form("rec_sel%d",i), Form("rec_sel%d",i), Nptbin, pt);
                rec_sel[i]->GetXaxis()->SetTitle("#font[12]{p}_{T}[MeV/#font[12]{c}]");
                rec_sel[i]->GetYaxis()->SetTitle("rec_sel");
                rec_sel[i]->GetYaxis()->SetRangeUser(0.,1.05);
                rec_sel[i]->SetLineColor(color[i]);
                rec_sel[i]->SetMarkerColor(color[i]);
                rec_sel[i]->SetMarkerStyle(marker[i]);
                for (int j=0; j<Nptbin; j++)
                {
                        rec_sel[i]->SetBinContent(j+1, h_eff->GetBinContent(j+1,i+1));
                        rec_sel[i]->SetBinError(j+1, h_eff->GetBinError(j+1,i+1));
                }
        }
	TFile* fnew = new TFile(argv[10],"recreate");
	h_eff -> Write();
	h_A -> Write();
	h_B -> Write();
        for(int i=0; i<Nybin; i++) rec_sel[i]->Write();
        fnew -> Close();
        return 0;
}

