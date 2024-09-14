#include <TAxis.h>
#include <iostream>
#include <fstream>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <math.h>
using namespace std;
int main(int argc, char* argv[])
{
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
	TFile *out = new TFile(argv[3],"recreate");
	TH1D *hpCompare = new TH1D("hpCompare", "Compare", 20, -1,1);
	TFile *input;
	for(int n=1;n<=5;n++)
	{
		input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_tot/n%d_promptHighMul.root",n));
		TH2D *hJH = (TH2D*)input->Get("h_3");
		input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_tot/n%d_promptLowMul.root",n));
		TH2D *hJL = (TH2D*)input->Get("h_3");
		input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_tot/n%d_promptHighMul.root",n));
        	TH2D *hPH = (TH2D*)input->Get("h_3");
		input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_tot/n%d_promptLowMul.root",n));
		TH2D *hPL = (TH2D*)input->Get("h_3");
		input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_tot/n%d_prompt.root",n));
        	TH2D *hJ = (TH2D*)input->Get("h_3");
		input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_tot/n%d_prompt.root",n));
        	TH2D *hP = (TH2D*)input->Get("h_3");
		for(int y=1;y<=3;y++)
		{
			for(int pt=1;pt<=5;pt++)
			{
				double cjh = hJH->GetBinContent(pt,y);
				double cjl = hJL->GetBinContent(pt,y);
				double cj = hJ->GetBinContent(pt,y);
				double cph = hPH->GetBinContent(pt,y);
        	                double cpl = hPL->GetBinContent(pt,y);
        	                double cp = hP->GetBinContent(pt,y);
				double ej = hJ->GetBinError(pt,y);
				double ep = hP->GetBinError(pt,y);
				double rph = cjh/cph;
				double rpl = cjl/cpl;
				double rp = cj/cp;
				double e = sqrt(ej*ej/cj/cj+ep*ep/cp/cp);
				hpCompare->Fill(max(rph-rp,rpl-rp)/e);
			}
		}
	}
	out -> cd();
	hpCompare -> Write();
	TH1D *hbCompare = new TH1D("hbCompare", "Compare", 20, -1, 1);
        for(int n=1;n<=5;n++)
        {   
                input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_tot/n%d_frombHighMul.root",n));
                TH2D *hJH = (TH2D*)input->Get("h_3");
                input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_tot/n%d_frombLowMul.root",n));
                TH2D *hJL = (TH2D*)input->Get("h_3");
                input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_tot/n%d_frombHighMul.root",n));
                TH2D *hPH = (TH2D*)input->Get("h_3");
                input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_tot/n%d_frombLowMul.root",n));
                TH2D *hPL = (TH2D*)input->Get("h_3");
                input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_tot/n%d_fromb.root",n));
                TH2D *hJ = (TH2D*)input->Get("h_3");
                input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_tot/n%d_fromb.root",n));
                TH2D *hP = (TH2D*)input->Get("h_3");
                for(int y=1;y<=3;y++)
                {   
                        for(int pt=1;pt<=5;pt++)
                        {   
                                double cjh = hJH->GetBinContent(pt,y);
                                double cjl = hJL->GetBinContent(pt,y);
                                double cj = hJ->GetBinContent(pt,y);
                                double cph = hPH->GetBinContent(pt,y);
                                double cpl = hPL->GetBinContent(pt,y);
                                double cp = hP->GetBinContent(pt,y);
                                double ej = hJ->GetBinError(pt,y);
                                double ep = hP->GetBinError(pt,y);
                        	double rph = cjh/cph;
				double rpl = cjl/cpl;
				double rp = cj/cp;
				double e = sqrt(ej*ej/cj/cj+ep*ep/cp/cp);
				hbCompare->Fill(max(rph-rp,rpl-rp)/e);
			}
                }
        }
        out -> cd();
        hbCompare -> Write();
	out -> Close();
	return 0;
}
