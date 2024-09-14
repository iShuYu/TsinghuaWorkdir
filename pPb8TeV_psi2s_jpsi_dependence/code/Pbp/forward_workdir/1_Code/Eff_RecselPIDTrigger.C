#define MCDecayTree_Cut_cxx
#define mct_cxx
#include <TH1.h>
#include <TH2.h>
#include <TH3F.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <TAxis.h>
#include <TROOT.h>
#include <TRandom3.h>
#include "0_header/MCDecayTree_Cut.h"
#include "0_header/mct.h"
using namespace std;
int main(int argc, char *argv[])
{
	//random generator and setting
	TRandom3 *ran = new TRandom3();
	ran -> SetSeed(0);
        TH1::SetDefaultSumw2();
	
	//input binning scheme
	double ybin, ptbin;
        int Nybin, Nptbin;
        ifstream yconfig(argv[2]);
        ifstream ptconfig(argv[3]);
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
	
	//input TrackCalib
	TFile TrackTable("../0_File/TrackCalib/TrackTable.root");
	TH2D *Track = (TH2D*)TrackTable.Get("Pbp");
	TH2D *CTrack = (TH2D*)Track->Clone("CTracks");
	
	//Generate random duplicate of TrackCalib
	int NTT = Track->GetNcells();
	for(int i=1;i<=NTT;i++)
	{
		c = Track->GetBinContent(i);
		cErr = Track->GetBinError(i);
		CTrack -> SetBinContent(i, ran->Gaus(c,cErr));
	}
	
	//choose hi or lo pT-Y parameterizaiton 1 for hi, 2 for lo, 0 for no reweight
	int flag;
	sscanf(argv[1],"%d",&flag);
	double mum_Tweight, mup_Tweight;
	double PTweight, Yweight;
	double mum_P, mup_P, mum_ETA, mup_ETA;
	
	//Jpsi RecSel
	TChain *before_rec_sel = new TChain("mct");
	TChain *after_rec_sel = new TChain("DecayTree");
	before_rec_sel -> Add(argv[4]);
	after_rec_sel -> Add(argv[5]);
	mct B(before_rec_sel);
	MCDecayTree_Cut A(after_rec_sel);
	int NA = after_rec_sel->GetEntries();
	int NB = before_rec_sel->GetEntries();
	double mctPT, mctY, DTPT, DTY;
	TH2D *h_before_rec_sel_J = new TH2D("h_before_rec_sel_J","h_before_rec_sel_J", Nptbin, pt, Nybin, y);
	TH2D *h_after_rec_sel_without_PIDtrigger_J = new TH2D("h_after_rec_sel_without_PIDtrigger_J","h_after_rec_sel_without_PIDtrigger_J", Nptbin, pt, Nybin, y);
	TH2D *h_eff_rec_sel_J = new TH2D("h_eff_rec_sel_J", "h_eff_rec_sel_J", Nptbin, pt, Nybin, y);
	for(int i=0; i<NB; i++)
	{
		before_rec_sel -> GetEntry(i);
		if(B.PVZ[0]>120) continue;
		mctPT = B.psi_TRUEPT;
		//careful definition of y*
		mctY = -0.5*log((B.psi_TRUEP_E+B.psi_TRUEP_Z)/(B.psi_TRUEP_E-B.psi_TRUEP_Z))-0.465;
		PTweight = CwJ_hiPT->GetBinContent(CwJ_hiPT->FindBin(mctPT));
		Yweight = CwJ_hiY->GetBinContent(CwJ_hiY->FindBin(mctY));
		if(flag==2)
		{
			PTweight = CwJ_loPT->GetBinContent(CwJ_loPT->FindBin(mctPT));
			Yweight = CwJ_loY->GetBinContent(CwJ_loY->FindBin(mctY));
		}
		if(flag==0)
		{
			PTweight = 1.;
			Yweight = 1.;
		}
		h_before_rec_sel_J -> Fill(mctPT, mctY, PTweight*Yweight);
	}
	for(int i=0; i<NA; i++)
	{
		after_rec_sel -> GetEntry(i);
		DTPT = A.psi_PT;
		//already -0.465 when Cut
		DTY = A.psi_Y;
		mup_ETA = 0.5 * log((A.mup_P + A.mup_PZ)/(A.mup_P - A.mup_PZ));
		mum_ETA = 0.5 * log((A.mum_P + A.mum_PZ)/(A.mum_P - A.mum_PZ));
		mum_P = A.mum_P;
                mup_P = A.mup_P;
		int Tbinm = CTrack->FindBin(mum_P,mum_ETA);
		int Tbinp = CTrack->FindBin(mup_P,mup_ETA);
		mum_Tweight = CTrack -> GetBinContent(Tbinm);
		mup_Tweight = CTrack -> GetBinContent(Tbinp);
		//if out of range
		if(mum_Tweight==0) mum_Tweight = 1.;
		if(mup_Tweight==0) mup_Tweight = 1.;
		PTweight = CwJ_hiPT->GetBinContent(CwJ_hiPT->FindBin(DTPT));
                Yweight = CwJ_hiY->GetBinContent(CwJ_hiY->FindBin(DTY));
		if(flag==2)
		{
			PTweight = CwJ_loPT->GetBinContent(CwJ_loPT->FindBin(DTPT));
                	Yweight = CwJ_loY->GetBinContent(CwJ_loY->FindBin(DTY));
		}
		if(flag==0)
		{
			PTweight = 1.;
			Yweight = 1.;
			mum_Tweight = 1.;
			mup_Tweight = 1.;
		}
		h_after_rec_sel_without_PIDtrigger_J -> Fill(DTPT, DTY, mum_Tweight*mup_Tweight*PTweight*Yweight);
	}
	h_eff_rec_sel_J->Divide(h_after_rec_sel_without_PIDtrigger_J, h_before_rec_sel_J, 1, 1, "B");
	
	//Psi2S RecSel
	TChain *before_rec_selP = new TChain("mct");
	TChain *after_rec_selP = new TChain("DecayTree");
	before_rec_selP -> Add(argv[6]);
	after_rec_selP -> Add(argv[7]);
	mct BP(before_rec_selP);
	MCDecayTree_Cut AP(after_rec_selP);
	int NAP = after_rec_selP->GetEntries();
	int NBP = before_rec_selP->GetEntries();
	TH2D *h_before_rec_sel_P = new TH2D("h_before_rec_sel_P","h_before_rec_sel_P", Nptbin, pt, Nybin, y);
	TH2D *h_after_rec_sel_without_PIDtrigger_P = new TH2D("h_after_rec_sel_without_PIDtrigger_P","h_after_rec_sel_without_PIDtrigger_P", Nptbin, pt, Nybin, y);
	TH2D *h_eff_rec_sel_P = new TH2D("h_eff_rec_sel_P", "h_eff_rec_sel_P", Nptbin, pt, Nybin, y);
	for(int i=0; i<NBP; i++)
	{
		before_rec_selP -> GetEntry(i);
		if(BP.PVZ[0]>120) continue;
		mctPT = BP.psi_TRUEPT;
		//careful definition of y*
		mctY = -0.5*log((BP.psi_TRUEP_E+BP.psi_TRUEP_Z)/(BP.psi_TRUEP_E-BP.psi_TRUEP_Z))-0.465;
		PTweight = CwP_hiPT->GetBinContent(CwP_hiPT->FindBin(mctPT));
		Yweight = CwP_hiY->GetBinContent(CwP_hiY->FindBin(mctY));
		if(flag==2)
		{
			PTweight = CwP_loPT->GetBinContent(CwP_loPT->FindBin(mctPT));
			Yweight = CwP_loY->GetBinContent(CwP_loY->FindBin(mctY));
		}
		if(flag==0)
		{
			PTweight = 1.;
			Yweight = 1.;
		}
		h_before_rec_sel_P -> Fill(mctPT, mctY, PTweight*Yweight);
	}
	for(int i=0; i<NAP; i++)
	{
		after_rec_selP -> GetEntry(i);
		DTPT = AP.psi_PT;
		//already -0.465 when Cut
		DTY = AP.psi_Y;
		mup_ETA = 0.5 * log((AP.mup_P + AP.mup_PZ)/(AP.mup_P - AP.mup_PZ));
		mum_ETA = 0.5 * log((AP.mum_P + AP.mum_PZ)/(AP.mum_P - AP.mum_PZ));
		mum_P = AP.mum_P;
                mup_P = AP.mup_P;
		int Tbinm = CTrack->FindBin(mum_P,mum_ETA);
		int Tbinp = CTrack->FindBin(mup_P,mup_ETA);
		mum_Tweight = CTrack -> GetBinContent(Tbinm);
		mup_Tweight = CTrack -> GetBinContent(Tbinp);
		//if out of range
		if(mum_Tweight==0) mum_Tweight = 1.;
		if(mup_Tweight==0) mup_Tweight = 1.;
		PTweight = CwP_hiPT->GetBinContent(CwP_hiPT->FindBin(DTPT));
                Yweight = CwP_hiY->GetBinContent(CwP_hiY->FindBin(DTY));
		if(flag==2)
		{
			PTweight = CwP_loPT->GetBinContent(CwP_loPT->FindBin(DTPT));
                	Yweight = CwP_loY->GetBinContent(CwP_loY->FindBin(DTY));
		}
		if(flag==0)
		{
			PTweight = 1.;
			Yweight = 1.;
			mum_Tweight = 1.;
			mup_Tweight = 1.;
		}
		h_after_rec_sel_without_PIDtrigger_P -> Fill(DTPT, DTY, mum_Tweight*mup_Tweight*PTweight*Yweight);
	}
	h_eff_rec_sel_P->Divide(h_after_rec_sel_without_PIDtrigger_P, h_before_rec_sel_P, 1, 1, "B");

	//input PID table
	TFile PIDTable(argv[8]);
	TH3F *PID = (TH3F*)PIDTable.Get("Mu_IsMuon == 1.0 && MC15TuneV1_ProbNNmu > 0.9_All");
	//Generate random duplicate of PIDTable
	TH3F *CPID = (TH3F*)PID->Clone("CPID");
	int NcellPID = PID->GetNcells();
	for(int i=1; i<=NcellPID; i++)
	{
		c = PID->GetBinContent(i);
		cErr = PID->GetBinError(i);
		CPID->SetBinContent(i, ran->Gaus(c,cErr));
		if(abs(cErr)>10) CPID->SetBinContent(i, 0);
	}

	//Jpsi PID
	double mum_PIDw, mup_PIDw;
	TH2D *h_after_recsel_withPID_without_trigger_J = new TH2D("h_after_recsel_withPID_without_trigger_J","h_after_recsel_withPID_without_trigger_J", Nptbin, pt, Nybin, y);
	for(int i=0; i<NA; i++)
	{
		after_rec_sel -> GetEntry(i);
		DTPT = A.psi_PT;
		//already -0.465 when Cut
		DTY = A.psi_Y;
		mup_ETA = 0.5 * log((A.mup_P + A.mup_PZ)/(A.mup_P - A.mup_PZ));
		mum_ETA = 0.5 * log((A.mum_P + A.mum_PZ)/(A.mum_P - A.mum_PZ));
		mum_P = A.mum_P;
                mup_P = A.mup_P;
		int Tbinm = CTrack->FindBin(mum_P,mum_ETA);
		int Tbinp = CTrack->FindBin(mup_P,mup_ETA);
		mum_Tweight = CTrack -> GetBinContent(Tbinm);
		mup_Tweight = CTrack -> GetBinContent(Tbinp);
		//if out of range
		if(mum_Tweight==0) mum_Tweight = 1.;
		if(mup_Tweight==0) mup_Tweight = 1.;
		PTweight = CwJ_hiPT->GetBinContent(CwJ_hiPT->FindBin(DTPT));
                Yweight = CwJ_hiY->GetBinContent(CwJ_hiY->FindBin(DTY));
		if(flag==2)
		{
			PTweight = CwJ_loPT->GetBinContent(CwJ_loPT->FindBin(DTPT));
                	Yweight = CwJ_loY->GetBinContent(CwJ_loY->FindBin(DTY));
		}
		if(flag==0)
		{
			PTweight = 1.;
			Yweight = 1.;
			mum_Tweight = 1.;
			mup_Tweight = 1.;
		}
		int SPD = A.nSPDHits;
		mum_PIDw = CPID->GetBinContent(CPID->FindBin(mum_P,mum_ETA,SPD));
		mup_PIDw = CPID->GetBinContent(CPID->FindBin(mup_P,mup_ETA,SPD));
		if(mum_PIDw==0) mum_PIDw=1.;
		if(mup_PIDw==0) mup_PIDw=1.;
		h_after_recsel_withPID_without_trigger_J -> Fill(DTPT, DTY, mum_Tweight*mup_Tweight*PTweight*Yweight*mum_PIDw*mup_PIDw);
	}
	TH2D *h_eff_PID_J = new TH2D("h_eff_PID_J","h_eff_PID_J", Nptbin, pt, Nybin, y);
	h_eff_PID_J -> Divide(h_after_recsel_withPID_without_trigger_J, h_after_rec_sel_without_PIDtrigger_J, 1., 1., "B");
	//Psi2S PID
	TH2D *h_after_recsel_withPID_without_trigger_P = new TH2D("h_after_recsel_withPID_without_trigger_P","h_after_recsel_withPID_without_trigger_P", Nptbin, pt, Nybin, y);
	for(int i=0; i<NAP; i++)
	{
		after_rec_selP -> GetEntry(i);
		DTPT = AP.psi_PT;
		//already -0.465 when Cut
		DTY = AP.psi_Y;
		mup_ETA = 0.5 * log((AP.mup_P + AP.mup_PZ)/(AP.mup_P - AP.mup_PZ));
		mum_ETA = 0.5 * log((AP.mum_P + AP.mum_PZ)/(AP.mum_P - AP.mum_PZ));
		mum_P = AP.mum_P;
                mup_P = AP.mup_P;
		int Tbinm = CTrack->FindBin(mum_P,mum_ETA);
		int Tbinp = CTrack->FindBin(mup_P,mup_ETA);
		mum_Tweight = CTrack -> GetBinContent(Tbinm);
		mup_Tweight = CTrack -> GetBinContent(Tbinp);
		//if out of range
		if(mum_Tweight==0) mum_Tweight = 1.;
		if(mup_Tweight==0) mup_Tweight = 1.;
		PTweight = CwP_hiPT->GetBinContent(CwP_hiPT->FindBin(DTPT));
                Yweight = CwP_hiY->GetBinContent(CwP_hiY->FindBin(DTY));
		if(flag==2)
		{
			PTweight = CwP_loPT->GetBinContent(CwP_loPT->FindBin(DTPT));
                	Yweight = CwP_loY->GetBinContent(CwP_loY->FindBin(DTY));
		}
		if(flag==0)
		{
			PTweight = 1.;
			Yweight = 1.;
			mum_Tweight = 1.;
			mup_Tweight = 1.;
		}
		int SPD = AP.nSPDHits;
		mum_PIDw = CPID->GetBinContent(CPID->FindBin(mum_P,mum_ETA,SPD));
		mup_PIDw = CPID->GetBinContent(CPID->FindBin(mup_P,mup_ETA,SPD));
		if(mum_PIDw==0) mum_PIDw=1.;
		if(mup_PIDw==0) mup_PIDw=1.;
		h_after_recsel_withPID_without_trigger_P -> Fill(DTPT, DTY, mum_Tweight*mup_Tweight*PTweight*Yweight*mum_PIDw*mup_PIDw);
	}
	TH2D *h_eff_PID_P = new TH2D("h_eff_PID_P","h_eff_PID_P", Nptbin, pt, Nybin, y);
	h_eff_PID_P -> Divide(h_after_recsel_withPID_without_trigger_P, h_after_rec_sel_without_PIDtrigger_P, 1., 1., "B");

	//Jpsi trigger
	TH2D *h_withPIDcutNOTtable_without_trigger_J = new TH2D("h_withPIDcutNOTtable_without_trigger_J","h_withPIDcutNOTtable_without_trigger_J", Nptbin, pt, Nybin, y);
	TH2D *h_withPIDcutNOTtable_with_trigger_J = new TH2D("h_withPIDcutNOTtable_with_trigger_J","h_withPIDcutNOTtable_with_trigger_J", Nptbin, pt, Nybin, y);
	for(int i=0; i<NA; i++)
	{
		after_rec_sel -> GetEntry(i);
		if (!( A.mup_isMuon == 1 ))  continue;
                if (!( A.mum_isMuon == 1 ))  continue;
		if (!( A.mum_ProbNNmu > 0.9 ))  continue;
                if (!( A.mup_ProbNNmu > 0.9 ))  continue;
		DTPT = A.psi_PT;
		//already -0.465 when Cut
		DTY = A.psi_Y;
		mup_ETA = 0.5 * log((A.mup_P + A.mup_PZ)/(A.mup_P - A.mup_PZ));
		mum_ETA = 0.5 * log((A.mum_P + A.mum_PZ)/(A.mum_P - A.mum_PZ));
		mum_P = A.mum_P;
                mup_P = A.mup_P;
		int Tbinm = CTrack->FindBin(mum_P,mum_ETA);
		int Tbinp = CTrack->FindBin(mup_P,mup_ETA);
		mum_Tweight = CTrack -> GetBinContent(Tbinm);
		mup_Tweight = CTrack -> GetBinContent(Tbinp);
		//if out of range
		if(mum_Tweight==0) mum_Tweight = 1.;
		if(mup_Tweight==0) mup_Tweight = 1.;
		PTweight = CwJ_hiPT->GetBinContent(CwJ_hiPT->FindBin(DTPT));
                Yweight = CwJ_hiY->GetBinContent(CwJ_hiY->FindBin(DTY));
		if(flag==2)
		{
			PTweight = CwJ_loPT->GetBinContent(CwJ_loPT->FindBin(DTPT));
                	Yweight = CwJ_loY->GetBinContent(CwJ_loY->FindBin(DTY));
		}
		if(flag==0)
		{
			PTweight = 1.;
			Yweight = 1.;
			mum_Tweight = 1.;
			mup_Tweight = 1.;
		}
		h_withPIDcutNOTtable_without_trigger_J -> Fill(DTPT, DTY, mum_Tweight*mup_Tweight*PTweight*Yweight);
		if(!(A.psi_L0MuonDecision_TOS==1)) continue;
		if(!(A.psi_Hlt1DiMuonHighMassDecision_TOS==1)) continue;
		h_withPIDcutNOTtable_with_trigger_J -> Fill(DTPT, DTY, mum_Tweight*mup_Tweight*PTweight*Yweight);
	}
	TH2D *h_eff_trigger_J = new TH2D("h_eff_trigger_J","h_eff_trigger_J", Nptbin, pt, Nybin, y);
	h_eff_trigger_J -> Divide(h_withPIDcutNOTtable_with_trigger_J,h_withPIDcutNOTtable_without_trigger_J,1.,1.,"B");
	
	//Psi2S trigger
	TH2D *h_withPIDcutNOTtable_without_trigger_P = new TH2D("h_withPIDcutNOTtable_without_trigger_P","h_withPIDcutNOTtable_without_trigger_P", Nptbin, pt, Nybin, y);
	TH2D *h_withPIDcutNOTtable_with_trigger_P = new TH2D("h_withPIDcutNOTtable_with_trigger_P","h_withPIDcutNOTtable_with_trigger_P", Nptbin, pt, Nybin, y);
	for(int i=0; i<NAP; i++)
	{
		after_rec_selP -> GetEntry(i);
		if (!( AP.mup_isMuon == 1 ))  continue;
                if (!( AP.mum_isMuon == 1 ))  continue;
		if (!( AP.mum_ProbNNmu > 0.9 ))  continue;
                if (!( AP.mup_ProbNNmu > 0.9 ))  continue;
		DTPT = AP.psi_PT;
		//already -0.465 when Cut
		DTY = AP.psi_Y;
		mup_ETA = 0.5 * log((AP.mup_P + AP.mup_PZ)/(AP.mup_P - AP.mup_PZ));
		mum_ETA = 0.5 * log((AP.mum_P + AP.mum_PZ)/(AP.mum_P - AP.mum_PZ));
		mum_P = AP.mum_P;
                mup_P = AP.mup_P;
		int Tbinm = CTrack->FindBin(mum_P,mum_ETA);
		int Tbinp = CTrack->FindBin(mup_P,mup_ETA);
		mum_Tweight = CTrack -> GetBinContent(Tbinm);
		mup_Tweight = CTrack -> GetBinContent(Tbinp);
		//if out of range
		if(mum_Tweight==0) mum_Tweight = 1.;
		if(mup_Tweight==0) mup_Tweight = 1.;
		PTweight = CwP_hiPT->GetBinContent(CwP_hiPT->FindBin(DTPT));
                Yweight = CwP_hiY->GetBinContent(CwP_hiY->FindBin(DTY));
		if(flag==2)
		{
			PTweight = CwP_loPT->GetBinContent(CwP_loPT->FindBin(DTPT));
                	Yweight = CwP_loY->GetBinContent(CwP_loY->FindBin(DTY));
		}
		if(flag==0)
		{
			PTweight = 1.;
			Yweight = 1.;
			mum_Tweight = 1.;
			mup_Tweight = 1.;
		}
		h_withPIDcutNOTtable_without_trigger_P -> Fill(DTPT, DTY, mum_Tweight*mup_Tweight*PTweight*Yweight);
		if(!(AP.psi_L0MuonDecision_TOS==1)) continue;
		if(!(AP.psi_Hlt1DiMuonHighMassDecision_TOS==1)) continue;
		h_withPIDcutNOTtable_with_trigger_P -> Fill(DTPT, DTY, mum_Tweight*mup_Tweight*PTweight*Yweight);
	}
	TH2D *h_eff_trigger_P = new TH2D("h_eff_trigger_P","h_eff_trigger_P", Nptbin, pt, Nybin, y);
	h_eff_trigger_P -> Divide(h_withPIDcutNOTtable_with_trigger_P,h_withPIDcutNOTtable_without_trigger_P,1.,1.,"B");

	//Jpsi and Psi2S total efficiency except for acceptance
	TH2D *h_eff_tot_J = new TH2D("h_eff_tot_J","h_eff_tot_J", Nptbin, pt, Nybin, y);
	TH2D *h_eff_tot_P = new TH2D("h_eff_tot_P","h_eff_tot_P", Nptbin, pt, Nybin, y);
	h_eff_tot_J -> Multiply(h_eff_rec_sel_J, h_eff_PID_J, 1., 1., "B");
	h_eff_tot_J -> Multiply(h_eff_tot_J, h_eff_trigger_J, 1., 1., "B");
	h_eff_tot_P -> Multiply(h_eff_rec_sel_P, h_eff_PID_P, 1., 1., "B");
	h_eff_tot_P -> Multiply(h_eff_tot_P, h_eff_trigger_P, 1., 1., "B");
	TH2D *ratio_tot = new TH2D("ratio_tot","ratio_tot", Nptbin, pt, Nybin, y);
	ratio_tot->Divide(h_eff_tot_J, h_eff_tot_P,1.,1.,"B");
	TFile *out = new TFile(argv[9], "recreate");
	h_eff_rec_sel_J -> Write();
	h_eff_rec_sel_P -> Write();
	h_eff_PID_J -> Write();
	h_eff_PID_P -> Write();
	h_eff_trigger_J -> Write();
	h_eff_trigger_P -> Write();
	h_eff_tot_J -> Write();
	h_eff_tot_P -> Write();
	ratio_tot -> Write();
	out->Close();
        return 0;
}


