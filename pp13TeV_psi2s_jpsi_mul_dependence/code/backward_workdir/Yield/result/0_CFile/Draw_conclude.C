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
	TH1::SetDefaultSumw2();
	//input binning scheme
	//int N;
        //sscanf(argv[1],"%d",&N);
        vector<double>  y_s;
	vector<double> pt_s;
	vector<int> n_s;
        double nbin, ybin, ptbin;
        int Nnbin, Nybin, Nptbin;
        ifstream nconfig(argv[1]);
        ifstream yconfig(argv[2]);
        ifstream ptconfig(argv[3]);
        nconfig >> Nnbin;
        yconfig >> Nybin;
        ptconfig >> Nptbin;
        for(int i=0; i<=Nnbin; i++)
        {
                nconfig >> nbin;
                n_s.push_back(nbin);
        }
        for(int i=0; i<=Nybin; i++)
        {
                yconfig >> ybin;
                y_s.push_back(ybin);
        }
        for(int i=0; i<=Nptbin; i++)
        {
                ptconfig >> ptbin;
                pt_s.push_back(ptbin);
        }
        double color[Nybin+Nptbin], marker[Nybin+Nptbin];
        for(int i=0; i<Nybin+Nptbin; i++)
        {
                color[i] = i+1;
                marker[i] = 20+i*2;
        }
        gROOT->SetBatch(true);
        setLHCbStyle();
	//Draw total Modification
	//input
	TFile *allT = TFile::Open("../../result/3_Result/Conclude.root");
	//plot
	TFile *Err;
	for(int i=1;i<=nbin;i++)
	{
		TCanvas *canp = new TCanvas("canp","canp",1200,800);
		TCanvas *canb = new TCanvas("canb","canb",1200,800);
		TLegend *Legp = new TLegend(0.7,0.19,0.9,0.39);
		TLegend *Legb = new TLegend(0.7,0.19,0.9,0.39);
		Legp->SetTextFont(132);
                Legp->SetBorderSize(2);
                Legp->SetTextSize(0.05);
		Legb->SetTextFont(132);
                Legb->SetBorderSize(2);
                Legb->SetTextSize(0.05);
		TH2D *TJp = (TH2D*)allT->Get(Form("Jp%d",i));
		TH2D *TPp = (TH2D*)allT->Get(Form("Pp%d",i));
		TH2D *TJb = (TH2D*)allT->Get(Form("Jb%d",i));
		TH2D *TPb = (TH2D*)allT->Get(Form("Pb%d",i));
		TH2D *TRp = (TH2D*)TJp->Clone(0);
		TH2D *TRb = (TH2D*)TJb->Clone(0);
		TRp -> Divide(TPp,TJp,1.,1.);
		TRb -> Divide(TPb,TJb,1.,1.);
		TH1D *TRps[Nybin];
		TH1D *TRbs[Nybin];
		//input total Error to replace the StatsErr
		Err = TFile::Open(Form("../../../Systematic/AllErr/3_Result/n%d_AllsysErr.root",i));
		TH2D *Errp = (TH2D*)Err->Get("prompt");
		TH2D *Errb = (TH2D*)Err->Get("fromb");
		for(int j=1;j<=Nybin;j++)
		{
			//TCanvas *can = new TCanvas("can","can",1200,800);
			TRps[j] = TRp->ProjectionX(Form("TRp%d",j));
			TRbs[j] = TRb->ProjectionX(Form("TRb%d",j));
			//TH1D *TRps = new TH1D("TRps","TRps",Nptbin,pt_s);
			//TH1D *TRbs = new TH1D("TRbs","TRbs",Nptbin,pt_s);
			for(int k=1;k<=Nptbin;k++)
			{
				TRps[j]->SetBinContent(k,TRp->GetBinContent(k,j));
				TRps[j]->SetBinError(k,TRp->GetBinContent(k,j)*Errp->GetBinContent(k,j));
				TRbs[j]->SetBinContent(k,TRb->GetBinContent(k,j));
				TRbs[j]->SetBinError(k,TRb->GetBinContent(k,j)*Errb->GetBinContent(k,j));
			}
			TRbs[j]->SetStats(0);
			TRbs[j]->GetYaxis()->SetRangeUser(0.5,1.5);
                        TRbs[j]->SetLineColor(color[j]);
			TRbs[j]->SetMarkerStyle(marker[2]);
                        TRbs[j]->GetXaxis()->SetTitle("p_{T}/MeV");
                        TRbs[j]->GetYaxis()->SetTitle("Normalized #sigma_{#psi(2S)}/#sigma_{J/#psi}");
			TRps[j]->SetStats(0);
			TRps[j]->GetYaxis()->SetRangeUser(0.5,1.5);
			TRps[j]->SetLineColor(color[j]);
			TRps[j]->SetMarkerStyle(marker[1]);
			TRps[j]->GetXaxis()->SetTitle("p_{T}/MeV");
			TRps[j]->GetYaxis()->SetTitle("Normalized #sigma_{#psi(2S)}/#sigma_{J/#psi}");
			Legp->AddEntry(TRps[j],Form("%.1f < y < %.1f",y_s[j-1],y_s[j]));
                        Legb->AddEntry(TRbs[j],Form("%.1f < y < %.1f",y_s[j-1],y_s[j]));
			canp->cd();
			TRps[j]->Draw("same");
			canb->cd();
			TRbs[j]->Draw("same");
		}
		canp->cd();
                Legp->Draw("same");
                canp->SaveAs(Form("../4_Plot/n%d_prompt_ratio.pdf",i),"recreate");
		canp->Close();
		canb->cd();
		Legb->Draw("same");
		canb->SaveAs(Form("../4_Plot/n%d_fromb_ratio.pdf",i),"recreate");
		canb->Close();
	}
	return 0;
}
