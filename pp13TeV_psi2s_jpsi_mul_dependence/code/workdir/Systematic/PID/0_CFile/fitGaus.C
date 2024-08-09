#include <fstream>
#include <RooFormulaVar.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>
#include <TF1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <RooFit.h>
#include <RooPlot.h>
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooAddPdf.h>
#include <RooCBShape.h>
#include <RooExponential.h>
#include <RooGaussian.h>
#include <string>
#include <RooStats/SPlot.h>
#include <vector>
#include "../../../Yield/Jpsi/0_CFile/header/lhcbStyle.h"
using namespace std;
using namespace RooFit;
int main(int argc, char *argv[])
{
        setLHCbStyle();
	//input binning scheme
	TFile temp(argv[1]);
	TH2D *Ttemp = (TH2D*)temp.Get("h_eff");
	int ny = Ttemp->GetNbinsY();
	int npt = Ttemp->GetNbinsX();
	double Content[npt][ny][200];
	//N: multiplicity, Type: fromb, prompt and total
	int N, Type;
	sscanf(argv[3],"%d",&N);
	sscanf(argv[4],"%d",&Type);
	//Get all the contents
	TFile *inputJ;
	TFile *inputP;
	TH2D *TJ;
	TH2D *TP;
	for(int i=0;i<200;i++)
	{
		if(Type == 1)
		{
			inputJ = TFile::Open(Form("../3_Result/toyPIDeff/Jpsi/n%d_prompt_%d.root",N,i));
			inputP = TFile::Open(Form("../3_Result/toyPIDeff/Psi2S/n%d_prompt_%d.root",N,i));
		}
		if(Type == 2)
                {       
                        inputJ = TFile::Open(Form("../3_Result/toyPIDeff/Jpsi/n%d_fromb_%d.root",N,i));
	                inputP = TFile::Open(Form("../3_Result/toyPIDeff/Psi2S/n%d_fromb_%d.root",N,i));
		}
		if(Type == 3)
                {       
                        inputJ = TFile::Open(Form("../3_Result/toyPIDeff/Jpsi/n%d_total_%d.root",N,i));
                	inputP = TFile::Open(Form("../3_Result/toyPIDeff/Psi2S/n%d_total_%d.root",N,i));
		}
		TJ = (TH2D*)inputJ->Get("h_eff");
		TP = (TH2D*)inputP->Get("h_eff");
		//cout << "draw" << endl;
		//cout << "draw end" << endl;
		for(int y=0;y<ny;y++)
		{
			for(int pt=0;pt<npt;pt++)
			{
				Content[pt][y][i] = TJ->GetBinContent(pt+1,y+1)/TP->GetBinContent(pt+1,y+1);
			}
		}
	}
	//Calculate mean and std for each bin
	//Then we can fill an appropriate TH1 to fit
	int num_bin = 30;
	double mean[npt][ny], std[npt][ny];
	TH1D *th[npt][ny];
	for(int y=0;y<ny;y++)
	{
		for(int pt=0;pt<npt;pt++)
                {
			mean[pt][y]=0;
			for(int i=0;i<200;i++)
			{
				mean[pt][y]=mean[pt][y]+Content[pt][y][i];
				//cout << Content[pt][y][i] << endl;
			}
			mean[pt][y]=mean[pt][y]/200;
			//cout << mean[pt][y];
			std[pt][y]=0;
			for(int i=0;i<200;i++)
                        {
				std[pt][y]=std[pt][y]+(Content[pt][y][i]-mean[pt][y])*(Content[pt][y][i]-mean[pt][y]);
			}
			std[pt][y]=sqrt(std[pt][y]/199);
			th[pt][y] = new TH1D(Form("thpt%dy%d",pt,y),Form("thpt%dy%d",pt,y),num_bin,mean[pt][y]-3*std[pt][y],mean[pt][y]+3*std[pt][y]);
		}
	}
	//output
	TFile *Out = new TFile(argv[2],"recreate");
	TH2D *GausErrTable = (TH2D*)Ttemp->Clone(0);
	//Fit and Fill TH1D
	TCanvas *can[npt][ny];
	for(int y=0;y<ny;y++)
        {
                for(int pt=0;pt<npt;pt++)
                {
                        for(int i=0;i<200;i++)
                        {
				th[pt][y]->Fill(Content[pt][y][i]);
			}
			can[pt][y] = new TCanvas(Form("can%d%d",pt,y),Form("can%d%d",pt,y),800,600);
			th[pt][y]->SetLineColor(kRed);
			th[pt][y]->Draw();
			th[pt][y]->Fit("gaus");
			TF1 *g = (TF1*)th[pt][y]->GetListOfFunctions()->FindObject("gaus");
			GausErrTable->SetBinContent(pt+1,y+1,g->GetParameter(2)/g->GetParameter(1));
			if(Type==1) can[pt][y]->SaveAs(Form("../4_Plot/prompt_pt%dy%d.pdf",pt+1,y+1));
			if(Type==2) can[pt][y]->SaveAs(Form("../4_Plot/fromb_pt%dy%d.pdf",pt+1,y+1));
			if(Type==3) can[pt][y]->SaveAs(Form("../4_Plot/total_pt%dy%d.pdf",pt+1,y+1));
			can[pt][y]->Close();
		}
	}
	GausErrTable->Write();
	Out->Close();
	return 0;
}
	

