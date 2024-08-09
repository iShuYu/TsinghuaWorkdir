#include <TROOT.h>
#include <TStyle.h>
#include <fstream>
#include <TCanvas.h>
#include <TH1.h>
#include <TLegend.h>
#include <TFile.h>
#include <TH2.h>
#include <iostream>
#include <math.h>
#include "/nishome/kangye/disk402_ppAnalysis/workdir/Yield/Jpsi/0_CFile/header/lhcbStyle.h"
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
        //input binning scheme
        ifstream yconfig("/nishome/kangye/disk402_ppAnalysis/workdir/Yield/rawdata/3_Bins/ybin");
        ifstream ptconfig("/nishome/kangye/disk402_ppAnalysis/workdir/Yield/rawdata/3_Bins/ptbin");
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
	int color1[Nybin];
        int marker1[Nptbin];
        for(int i=0; i<Nybin; i++)
        {
                color[i] = i+1;
                marker[i] = i+1;
        }
	for(int i=0; i<Nybin; i++)
        {
                color1[i] = i+Nybin+4;
                marker1[i] = i+Nybin+4;
        }
	TCanvas* c0 = new TCanvas("c0", "c0", 0, 0, 800, 600);
	//gPad -> SetLogy();
	TLegend* leg1 = new TLegend(0.25, 0.25, 0.45, 0.5);
	leg1 -> SetHeader("J/#psi");
	TLegend* leg2 = new TLegend(0.65, 0.25, 0.85, 0.5);
        leg2 -> SetHeader("#psi(2S)");
	TH1D *rec_selJp;
	TH1D *rec_selPp;
	for (int i=0; i<Nybin; i++)
        {
                rec_selJp = new TH1D(Form("rec_selJp%d",i), Form("rec_selJp%d",i), Nptbin, pt);
		 rec_selPp = new TH1D(Form("rec_selPp%d",i), Form("rec_selPp%d",i), Nptbin, pt);
                rec_selJp->GetXaxis()->SetTitle("#font[12]{p}_{T}[MeV/#font[12]{c}]");
                rec_selJp->GetYaxis()->SetTitle("prompt yields");
                rec_selJp->GetYaxis()->SetRangeUser(1.,1000000);
                rec_selJp->SetLineColor(color[i]);
                rec_selJp->SetMarkerColor(color[i]);
                rec_selJp->SetMarkerStyle(marker[i]);
		rec_selPp->GetXaxis()->SetTitle("#font[12]{p}_{T}[MeV/#font[12]{c}]");
                rec_selPp->GetYaxis()->SetTitle("prompt yields");
                rec_selPp->GetYaxis()->SetRangeUser(1.,1000000);
                rec_selPp->SetLineColor(color1[i]);
                rec_selPp->SetMarkerColor(color1[i]);
                rec_selPp->SetMarkerStyle(marker1[i]);

                for (int j=0; j<Nptbin; j++)
                {
			ifstream production(Form("../../Jpsi/3_Result/2DFit/txt_n1y%dpt%d.txt", i+1, j+1));
        		double bias, biasErr, sigma1, sigma1Err, sigma2, sigma2Err, beta, betaErr, tau, tauErr, Nprompt, NpromptErr, Nfromb, NfrombErr, Ntail, NtailErr, Nbkg, NbkgErr;
        		production >> bias >> biasErr >> sigma1 >> sigma1Err >> sigma2 >> sigma2Err >> beta >>  betaErr >> tau >> tauErr >> Nprompt >> NpromptErr >> Nfromb >> NfrombErr >> Ntail >> NtailErr >> Nbkg >> NbkgErr;
                        cout << Nprompt << endl;
			rec_selJp->SetBinContent(j+1, Nprompt);
                        rec_selJp->SetBinError(j+1, NpromptErr);
			ifstream production1(Form("../../Psi2S/3_Result/2DFit/txt_n1y%dpt%d.txt", i+1, j+1));
                        production1 >> bias >> biasErr >> sigma1 >> sigma1Err >> sigma2 >> sigma2Err >> beta >>  betaErr >> tau >> tauErr >> Nprompt >> NpromptErr >> Nfromb >> NfrombErr >> Ntail >> NtailErr >> Nbkg >> NbkgErr;
			cout << Nprompt << endl;
			rec_selPp->SetBinContent(j+1, Nprompt);
                        rec_selPp->SetBinError(j+1, NpromptErr);
                }
		leg1 -> AddEntry(rec_selJp, Form("%1.1f < #font[12]{y} < %1.1f", y[i], y[i+1]));	
		 leg2 -> AddEntry(rec_selPp, Form("%1.1f < #font[12]{y} < %1.1f", y[i], y[i+1]));
		if(i==0) rec_selJp->Draw();
		else rec_selJp->Draw("same");
		rec_selPp->Draw("same");
        }
	leg1 -> Draw("same");
	leg2 -> Draw("same");
	c0 -> SetLogy();
	c0 -> SaveAs("./Yieldprompt.pdf");

	 TCanvas* c1 = new TCanvas("c1", "c1", 0, 0, 800, 600);
        //gPad -> SetLogy();
        TLegend* leg3 = new TLegend(0.25, 0.25, 0.45, 0.5);
        leg3 -> SetHeader("J/#psi");
        TLegend* leg4 = new TLegend(0.65, 0.25, 0.85, 0.5);
        leg4 -> SetHeader("#psi(2S)");
        TH1D *rec_selJb;
        TH1D *rec_selPb;
        for (int i=0; i<Nybin; i++)
        {
                rec_selJb = new TH1D(Form("rec_selJb%d",i), Form("rec_selJb%d",i), Nptbin, pt);
                 rec_selPb = new TH1D(Form("rec_selPb%d",i), Form("rec_selPb%d",i), Nptbin, pt);
                rec_selJb->GetXaxis()->SetTitle("#font[12]{p}_{T}[MeV/#font[12]{c}]");
                rec_selJb->GetYaxis()->SetTitle("non-prompt yields");
                rec_selJb->GetYaxis()->SetRangeUser(1.,500000);
                rec_selJb->SetLineColor(color[i]);
                rec_selJb->SetMarkerColor(color[i]);
                rec_selJb->SetMarkerStyle(marker[i]);
                rec_selPb->GetXaxis()->SetTitle("#font[12]{p}_{T}[MeV/#font[12]{c}]");
                rec_selPb->GetYaxis()->SetTitle("non-prompt yields");
                rec_selPb->GetYaxis()->SetRangeUser(1.,500000);
                rec_selPb->SetLineColor(color1[i]);
                rec_selPb->SetMarkerColor(color1[i]);
                rec_selPb->SetMarkerStyle(marker1[i]);
		
		 for (int j=0; j<Nptbin; j++)
                {
                        ifstream production(Form("../../Jpsi/3_Result/2DFit/txt_n1y%dpt%d.txt", i+1, j+1));
                        double bias, biasErr, sigma1, sigma1Err, sigma2, sigma2Err, beta, betaErr, tau, tauErr, Nprompt, NpromptErr, Nfromb, NfrombErr, Ntail, NtailErr, Nbkg, NbkgErr;
                        production >> bias >> biasErr >> sigma1 >> sigma1Err >> sigma2 >> sigma2Err >> beta >>  betaErr >> tau >> tauErr >> Nprompt >> NpromptErr >> Nfromb >> NfrombErr >> Ntail >> NtailErr >> Nbkg >> NbkgErr;
                        cout << Nprompt << endl;
                        rec_selJb->SetBinContent(j+1, Nfromb);
                        rec_selJb->SetBinError(j+1, NfrombErr);
                        ifstream production1(Form("../../Psi2S/3_Result/2DFit/txt_n1y%dpt%d.txt", i+1, j+1));
                        production1 >> bias >> biasErr >> sigma1 >> sigma1Err >> sigma2 >> sigma2Err >> beta >>  betaErr >> tau >> tauErr >> Nprompt >> NpromptErr >> Nfromb >> NfrombErr >> Ntail >> NtailErr >> Nbkg >> NbkgErr;
                        cout << Nprompt << endl;
                        rec_selPb->SetBinContent(j+1, Nfromb);
                        rec_selPb->SetBinError(j+1, NfrombErr);
                }
                leg3 -> AddEntry(rec_selJb, Form("%1.1f < #font[12]{y} < %1.1f", y[i], y[i+1]));
                 leg4 -> AddEntry(rec_selPb, Form("%1.1f < #font[12]{y} < %1.1f", y[i], y[i+1]));
                if(i==0) rec_selJb->Draw();
                else rec_selJb->Draw("same");
                rec_selPb->Draw("same");
        }
        leg3 -> Draw("same");
        leg4 -> Draw("same");
        c1 -> SetLogy();
        c1 -> SaveAs("./Yieldfromb.pdf");
		
	return 0;
}

