#define After_rec_sel_cxx
#include <iostream>
#include <fstream>
#include <TFile.h>
#include <TH3.h>
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <math.h>
#include <TAxis.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TChain.h>
#include "../../../Yield/Jpsi/0_CFile/header/lhcbStyle.h"
#include "../../../Yield/Jpsi/0_CFile/header/After_rec_sel.h"
using namespace std;
int main(int argc, char *argv[])
{
        gROOT->SetBatch(true);
        setLHCbStyle();
        gStyle->SetPalette(55);
        gStyle->SetPaintTextFormat("4.3f");
        TH1::SetDefaultSumw2();
	//input binning scheme
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
                y[i] = ybin;
        }
        for(int i=0; i<=Nptbin; i++)
        {
                ptconfig >> ptbin;
                pt[i] = ptbin;
        }
	int color[Nybin];
        int marker[Nptbin];
        for(int i=0; i<Nybin; i++)
        {
                color[i] = i;
                marker[i] = i;
        }
	//input reweight result
	TFile reweight(argv[3]);
        TH1D *reweightN =(TH1D*)reweight.Get(argv[11]);
        //TH1D *reweightY =(TH1D*)reweight.Get("reweightY");
        TH2D *reweightPTY =(TH2D*)reweight.Get(argv[12]);
	//input PIDCalib and TrackCalib
	TFile PIDCalibU(argv[4]);
        TH3F *tableU = (TH3F*)PIDCalibU.Get("Mu_DLLmu > 2.0 && IsMuon == 1.0 && MC15TuneV1_ProbNNmu > 0.8_All");
        TFile PIDCalibD(argv[5]);
        TH3F *tableD = (TH3F*)PIDCalibD.Get("Mu_DLLmu > 2.0 && IsMuon == 1.0 && MC15TuneV1_ProbNNmu > 0.8_All");
        TFile *TrackCalibU = TFile::Open(argv[6]);
        TH2D *TrackingTableU = (TH2D*) TrackCalibU->Get("Ratio");
        TFile *TrackCalibD = TFile::Open(argv[7]);
        TH2D *TrackingTableD = (TH2D*) TrackCalibD->Get("Ratio");
	//input MCDecayTree of full Simulation
	TChain *inputU = new TChain("DecayTree");
	inputU -> Add(argv[8]);
	After_rec_sel tU(inputU);
	int NU = inputU -> GetEntries();
	TChain *inputD = new TChain("DecayTree");
        inputD -> Add(argv[9]);
        After_rec_sel tD(inputD);
        int ND = inputD -> GetEntries();
	double mum_ETA, mup_ETA, mum_P, mup_P;
	int nN, nSPD;
	double PT, Y; //psi
	double mum_Pweight, mup_Pweight;
	double mum_Tweight, mup_Tweight;
	double nweight, ptyweight, yweight;
	//define TH2D to save the PID efficiency
	TH2D *h_pid = new TH2D("h_pid", "h_pid", Nptbin, pt, Nybin, y);
	TH2D *h_tot = new TH2D("h_tot", "h_tot", Nptbin, pt, Nybin, y);
	TH2D *h_eff = new TH2D("h_eff", "h_tot", Nptbin, pt, Nybin, y);
	for(int i=0; i<NU; i++)
	{
		inputU -> GetEntry(i);
		Y = 0.5 * log((tU.psi_PE + tU.psi_PZ)/(tU.psi_PE - tU.psi_PZ));
		PT = tU.psi_PT;
		mup_ETA = 0.5 * log((tU.mup_P + tU.mup_PZ)/(tU.mup_P - tU.mup_PZ));
		mum_ETA = 0.5 * log((tU.mum_P + tU.mum_PZ)/(tU.mum_P - tU.mum_PZ));
		mum_P = tU.mum_P;
		mup_P = tU.mup_P;
		nN = tU.nBackTracks;
		nSPD = tU.nSPDHits;
		mum_Pweight = tableU -> GetBinContent(tableU->FindBin(mum_P,mum_ETA,nSPD));
                mup_Pweight = tableU -> GetBinContent(tableU->FindBin(mup_P,mup_ETA,nSPD));
                int Tbinm = TrackingTableU->FindBin(mum_P,mum_ETA);
                int Tbinp = TrackingTableU->FindBin(mup_P,mup_ETA);
		mum_Tweight = TrackingTableU -> GetBinContent(Tbinm);
                mup_Tweight = TrackingTableU -> GetBinContent(Tbinp);
                if(mum_Tweight==0) mum_Tweight = 1.;
                if(mup_Tweight==0) mup_Tweight = 1.;
		nweight = reweightN->GetBinContent(reweightN->FindBin(nN));
                ptyweight = reweightPTY->GetBinContent(reweightPTY->FindBin(PT,Y));
                //yweight = reweightY->GetBinContent(reweightY->FindBin(Y));
		h_tot -> Fill(PT, Y, mum_Tweight*mup_Tweight*nweight*ptyweight);
        	h_pid -> Fill(PT, Y, mum_Tweight*mup_Tweight*nweight*ptyweight*mum_Pweight*mup_Pweight);
	}
	for(int i=0; i<ND; i++)
        {
                inputD -> GetEntry(i);
                Y = 0.5 * log((tD.psi_PE + tD.psi_PZ)/(tD.psi_PE - tD.psi_PZ));
                PT = tD.psi_PT;
                mup_ETA = 0.5 * log((tD.mup_P + tD.mup_PZ)/(tD.mup_P - tD.mup_PZ));
                mum_ETA = 0.5 * log((tD.mum_P + tD.mum_PZ)/(tD.mum_P - tD.mum_PZ));
                mum_P = tD.mum_P;
                mup_P = tD.mup_P;
                nN = tD.nBackTracks;
		nSPD = tD.nSPDHits;
                mum_Pweight = tableD -> GetBinContent(tableD->FindBin(mum_P,mum_ETA,nSPD));
                mup_Pweight = tableD -> GetBinContent(tableD->FindBin(mup_P,mup_ETA,nSPD));
                int Tbinm = TrackingTableD->FindBin(mum_P,mum_ETA);
                int Tbinp = TrackingTableD->FindBin(mup_P,mup_ETA);
                mum_Tweight = TrackingTableD -> GetBinContent(Tbinm);
                mup_Tweight = TrackingTableD -> GetBinContent(Tbinp);
		if(mum_Tweight==0) mum_Tweight = 1.;
                if(mup_Tweight==0) mup_Tweight = 1.;
		nweight = reweightN->GetBinContent(reweightN->FindBin(nN));
                ptyweight = reweightPTY->GetBinContent(reweightPTY->FindBin(PT,Y));
                //yweight = reweightY->GetBinContent(reweightY->FindBin(Y));
                h_tot -> Fill(PT, Y, mum_Tweight*mup_Tweight*nweight*ptyweight);
                h_pid -> Fill(PT, Y, mum_Tweight*mup_Tweight*nweight*ptyweight*mum_Pweight*mup_Pweight);
        }
	h_eff -> Divide(h_pid, h_tot, 1, 1, "B");
	//save
	TH1D* pid[Nybin];
        for (int i=0; i<Nybin; i++)
        {
                pid[i] = new TH1D(Form("pid%d",i), Form("pid%d",i), Nptbin, pt);
                pid[i]->GetXaxis()->SetTitle("#font[12]{p}_{T}[MeV/#font[12]{c}]");
                pid[i]->GetYaxis()->SetTitle("pid");
                pid[i]->GetYaxis()->SetRangeUser(0.,1.05);
                pid[i]->SetLineColor(color[i]);
                pid[i]->SetMarkerColor(color[i]);
                pid[i]->SetMarkerStyle(marker[i]);
                for (int j=0; j<Nptbin; j++)
                {
                        pid[i]->SetBinContent(j+1, h_eff->GetBinContent(j+1,i+1));
                        pid[i]->SetBinError(j+1, h_eff->GetBinError(j+1,i+1));
                }
        }
        TFile* fnew = new TFile(argv[10],"recreate");
        h_eff -> Write();
	h_tot -> Write();
	h_pid -> Write();
	for(int i=0; i<Nybin; i++) pid[i]->Write();
        fnew -> Close();
        return 0;
}

