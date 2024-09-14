#define CBSplotDecayTree_cxx
#include "../header/CBSplotDecayTree.h"
#include <iostream>
#include <TStyle.h>
#include <fstream>
#include <TFile.h>
#include <TH2.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TF1.h>
#include <TLegend.h>
#include <TROOT.h>
#include "../header/lhcbStyle.h"
using namespace std;
int main(int argc, char *argv[])
{
        gROOT->SetBatch(true);
        setLHCbStyle();
	//input Sweight for Jpsi and Psi2S
	TFile *J = TFile::Open("../../3_Result/2DFit/2D.root");
	TFile *P = TFile::Open("../../../Psi2S/3_Result/2DFit/2D.root");
	TTree *tj = (TTree*)J->Get("DecayTree");
	TTree *tp = (TTree*)P->Get("DecayTree");
	CBSplotDecayTree TJ(tj);
	CBSplotDecayTree TP(tp);
	int nj = tj->GetEntries();
	int np = tp->GetEntries();
	TH1D *jb = new TH1D("jb","jb",50,2,4.5);
	TH1D *jp = new TH1D("jp","jp",50,2,4.5);
	TH1D *pb = new TH1D("pb","pb",50,2,4.5);
	TH1D *pp = new TH1D("pp","pp",50,2,4.5);
	TH1D *b = new TH1D("b","b",50,2,4.5);
	TH1D *p = new TH1D("p","p",50,2,4.5);

	for(int i=0;i<nj;i++)
	{
		tj -> GetEntry(i);
		jb -> Fill(TJ.psi_Y,TJ.fromb_sw);
		jp -> Fill(TJ.psi_Y,TJ.prompt_sw);
	}
	for(int i=0;i<np;i++)
	{
		tp -> GetEntry(i);
		pb -> Fill(TP.psi_Y,TP.fromb_sw);
		pp -> Fill(TP.psi_Y,TP.prompt_sw);
	}
	jb ->  Scale(1.0/jb->Integral());
	jp ->  Scale(1.0/jp->Integral());
	pb ->  Scale(1.0/pb->Integral());
	pp ->  Scale(1.0/pp->Integral());
	b -> Divide(jb,pb,1.,1.,"B");
	p -> Divide(jp,pp,1.,1.,"B");
	TCanvas *can1 = new TCanvas("can1","can1",800,600);
	jb -> SetStats(0);
	jb -> SetLineColor(kRed);
	pb -> SetStats(0);
	pb -> SetLineColor(kBlue);
	jb -> SetTitle("Rapidity dist. for non-prompt signals");
	jb -> GetXaxis() -> SetTitle("y");
	//jb -> GetYaxis() -> SetTitle("Normalized");
	jb -> Draw();
	pb -> Draw("same");
	TLegend *leg1 = new TLegend(0.36,0.26,0.64,0.45);
	leg1 -> AddEntry(jb,"J/#psi from b");
	leg1 -> AddEntry(pb,"#psi(2S) from b");
	leg1 -> Draw("same");
	can1 -> SaveAs("../../3_Result/CompareRapidity/fromb.pdf");
	can1 -> Close();
	TCanvas *can2 = new TCanvas("can2","can2",800,600);
	jp -> SetStats(0);
	jp -> SetLineColor(kRed);
	pp -> SetStats(0);
	pp -> SetLineColor(kBlue);
	jp -> SetTitle("Rapidity dist. for prompt signals");
	jp -> GetXaxis() -> SetTitle("y");
	//jp -> GetYaxis() -> SetTitle("Normalized");
	jp -> Draw();
	pp -> Draw("same");
	TLegend *leg2 = new TLegend(0.36,0.26,0.64,0.45);
	leg2 -> AddEntry(jp,"prompt J/#psi");
	leg2 -> AddEntry(pp,"prompt #psi(2S)");
	leg2 -> Draw("same");
	can2 -> SaveAs("../../3_Result/CompareRapidity/prompt.pdf");
	can2 -> Close();
	return 0;
}


		
