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
#include "../header/lhcbStyle.h"
#include "../header/After_rec_sel.h"
using namespace std;
int main(int argc, char* argv[])
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
	TFile reweight(argv[3]);
        TH1D *reweightN =(TH1D*)reweight.Get("reweightN");
        //TH1D *reweightY =(TH1D*)reweight.Get("reweightY");
        TH2D *reweightPTY =(TH2D*)reweight.Get("reweightPTY");
	//input trackcalib
	TFile *TrackCalibU = TFile::Open(argv[4]);
        TH2D *TrackingTableU = (TH2D*) TrackCalibU->Get("Ratio");
	TChain *recU = new TChain("DecayTree");
	recU -> Add(argv[6]);
	After_rec_sel AU(recU);
	int NU = recU->GetEntries();
	TFile *TrackCalibD = TFile::Open(argv[5]);
        TH2D *TrackingTableD = (TH2D*) TrackCalibD->Get("Ratio");
        TChain *recD = new TChain("DecayTree");
        recD -> Add(argv[7]);
        After_rec_sel AD(recD);
        int ND = recD->GetEntries();
	double PT, Y,  mum_ETA, mup_ETA, mum_P, mup_P;
	double mum_Tweight, mup_Tweight;
	TH2D *h_tistos = new TH2D("h_tistos", "h_tistos", Nptbin, pt, Nybin, y);
        TH2D *h_tis = new TH2D("h_tis", "h_tis", Nptbin, pt, Nybin, y);
        TH2D *h_eff = new TH2D("h_eff", "h_eff", Nptbin, pt, Nybin, y);
	for(int i=0; i<NU; i++)
	{
		recU -> GetEntry(i);
		Y = 0.5 * log((AU.psi_PE + AU.psi_PZ)/(AU.psi_PE - AU.psi_PZ));
                PT = AU.psi_PT;
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
		if (!( AU.mup_isMuon == 1 ))  continue;
                if (!( AU.mum_isMuon == 1 ))  continue;
		if (!( AU.mup_PIDmu > 2. ))  continue;
                if (!( AU.mum_PIDmu > 2. ))  continue;
		if (!( AU.mup_ProbNNmu > 0.8 ))  continue;
                if (!( AU.mum_ProbNNmu > 0.8 ))  continue;
		double nweight, ptyweight, yweight;
                nweight = reweightN->GetBinContent(reweightN->FindBin(AU.nVeloClusters));
                ptyweight = reweightPTY->GetBinContent(reweightPTY->FindBin(PT,Y));
                //yweight = reweightY->GetBinContent(reweightY->FindBin(Y));
		if(AU.psi_L0Global_TIS!=1) continue;
		if(AU.psi_Hlt1Global_TIS!=1) continue;
		nweight = 1;
		ptyweight = 1;
		h_tis -> Fill(PT,Y, mum_Tweight*mup_Tweight*nweight*ptyweight);
		if(!(AU.psi_L0DiMuonDecision_TOS==1)) continue;
		if(!(AU.psi_Hlt1DiMuonHighMassDecision_TOS==1)) continue;
		//if(!(AU.psi_Hlt2DiMuonPsi2STurboDecision_TOS==1)) continue;
		h_tistos -> Fill(PT,Y, mum_Tweight*mup_Tweight*nweight*ptyweight);
	}
	for(int i=0; i<ND; i++)
        {
                recD -> GetEntry(i);
                Y = 0.5 * log((AD.psi_PE + AD.psi_PZ)/(AD.psi_PE - AD.psi_PZ));
                PT = AD.psi_PT;
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
		if (!( AD.mup_isMuon == 1 ))  continue;
                if (!( AD.mum_isMuon == 1 ))  continue;
		if (!( AD.mup_PIDmu > 2.))  continue;
                if (!( AD.mum_PIDmu > 2.))  continue;
                if (!( AD.mup_ProbNNmu > 0.8 ))  continue;
                if (!( AD.mum_ProbNNmu > 0.8 ))  continue;
		double nweight, ptyweight, yweight;
                nweight = reweightN->GetBinContent(reweightN->FindBin(AD.nVeloClusters));
                ptyweight = reweightPTY->GetBinContent(reweightPTY->FindBin(PT,Y));
                //yweight = reweightY->GetBinContent(reweightY->FindBin(Y));
                if(AD.psi_L0Global_TIS!=1) continue;
                if(AD.psi_Hlt1Global_TIS!=1) continue;
		nweight = 1;
		ptyweight = 1;
		h_tis -> Fill(PT,Y, mum_Tweight*mup_Tweight*nweight*ptyweight);
		if(!(AD.psi_L0DiMuonDecision_TOS==1)) continue;
                if(!(AD.psi_Hlt1DiMuonHighMassDecision_TOS==1)) continue;
                //if(!(AD.psi_Hlt2DiMuonPsi2STurboDecision_TOS==1)) continue;
        	h_tistos -> Fill(PT,Y, mum_Tweight*mup_Tweight*nweight*ptyweight);
	}
	h_eff -> Divide(h_tistos, h_tis, 1, 1, "B");
	//save
	TH1D* trigger[Nybin];
        for (int i=0; i<Nybin; i++)
        {
                trigger[i] = new TH1D(Form("trigger%d",i), Form("trigger%d",i), Nptbin, pt);
                trigger[i]->GetXaxis()->SetTitle("#font[12]{p}_{T}[MeV/#font[12]{c}]");
                trigger[i]->GetYaxis()->SetTitle("trigger");
                trigger[i]->GetYaxis()->SetRangeUser(0.,1.05);
                trigger[i]->SetLineColor(color[i]);
                trigger[i]->SetMarkerColor(color[i]);
                trigger[i]->SetMarkerStyle(marker[i]);
                for (int j=0; j<Nptbin; j++)
                {
                        trigger[i]->SetBinContent(j+1, h_eff->GetBinContent(j+1,i+1));
                        trigger[i]->SetBinError(j+1, h_eff->GetBinError(j+1,i+1));
                }
        }
        TFile* fnew = new TFile(argv[8],"recreate");
        h_eff -> Write();
        h_tis -> Write();
        h_tistos -> Write();
        for(int i=0; i<Nybin; i++) trigger[i]->Write();
        fnew -> Close();
        return 0;
}


