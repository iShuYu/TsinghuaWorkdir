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
	TH1::SetDefaultSumw2();
	//input REC, PID, TRI tables
	TFile RECJ(argv[1]);
	TFile PIDJ(argv[2]);
	TFile TRIJ(argv[3]);
	TH2D *Trecj = (TH2D*)RECJ.Get("h_eff");
	TH2D *Tpidj = (TH2D*)PIDJ.Get("h_eff");
	TH2D *Ttrij = (TH2D*)TRIJ.Get("h_eff");
	TFile RECP(argv[4]);
        TFile PIDP(argv[5]);
        TFile TRIP(argv[6]);
        TH2D *Trecp = (TH2D*)RECP.Get("h_eff");
        TH2D *Tpidp = (TH2D*)PIDP.Get("h_eff");
        TH2D *Ttrip = (TH2D*)TRIP.Get("h_eff");
	TH2D *Teff = (TH2D*)Trecj->Clone(0);
	Teff->Multiply(Teff,Tpidj,1.,1.);
	Teff->Multiply(Teff,Ttrij,1.,1.);
	Teff->Divide(Teff,Trecp,1.,1.);
	Teff->Divide(Teff,Tpidp,1.,1.);
	Teff->Divide(Teff,Ttrip,1.,1.);
	//scheme
	int ny = Trecj->GetNbinsY();
	int npt = Trecj->GetNbinsX();
	double Content[npt][ny][200];
	int N, Type;
        sscanf(argv[8],"%d",&N);
        sscanf(argv[9],"%d",&Type);
	for(int i=0;i<200;i++)
        {
		TFile *input1;
        	TFile *input2;
        	TFile *input3;
        	TFile *input4;
        	TFile *input5;
        	TFile *input6;
        	TH2D *T1;
        	TH2D *T2;
        	TH2D *T3;
        	TH2D *T4;
        	TH2D *T5;
        	TH2D *T6;
                if(Type == 1)
                {
                        input1 = TFile::Open(Form("../3_Result/toyEffRec/Jpsi/n%d_prompt_%d.root",N,i));
			input2 = TFile::Open(Form("../3_Result/toyEffPID/Jpsi/n%d_prompt_%d.root",N,i));
			input3 = TFile::Open(Form("../3_Result/toyEffTrigger/Jpsi/n%d_prompt_%d.root",N,i));
			input4 = TFile::Open(Form("../3_Result/toyEffRec/Psi2S/n%d_prompt_%d.root",N,i));
                        input5 = TFile::Open(Form("../3_Result/toyEffPID/Psi2S/n%d_prompt_%d.root",N,i));
                        input6 = TFile::Open(Form("../3_Result/toyEffTrigger/Psi2S/n%d_prompt_%d.root",N,i));
		}
		if(Type == 2)
                {   
                        input1 = TFile::Open(Form("../3_Result/toyEffRec/Jpsi/n%d_fromb_%d.root",N,i));
                        input2 = TFile::Open(Form("../3_Result/toyEffPID/Jpsi/n%d_fromb_%d.root",N,i));
                        input3 = TFile::Open(Form("../3_Result/toyEffTrigger/Jpsi/n%d_fromb_%d.root",N,i));
                	input4 = TFile::Open(Form("../3_Result/toyEffRec/Psi2S/n%d_fromb_%d.root",N,i));
                        input5 = TFile::Open(Form("../3_Result/toyEffPID/Psi2S/n%d_fromb_%d.root",N,i));
                        input6 = TFile::Open(Form("../3_Result/toyEffTrigger/Psi2S/n%d_fromb_%d.root",N,i));
		}
		if(Type == 3)
                {
                        input1 = TFile::Open(Form("../3_Result/toyEffRec/Jpsi/n%d_total_%d.root",N,i));
                        input2 = TFile::Open(Form("../3_Result/toyEffPID/Jpsi/n%d_total_%d.root",N,i));
                        input3 = TFile::Open(Form("../3_Result/toyEffTrigger/Jpsi/n%d_total_%d.root",N,i));
                	input4 = TFile::Open(Form("../3_Result/toyEffRec/Psi2S/n%d_total_%d.root",N,i));
                        input5 = TFile::Open(Form("../3_Result/toyEffPID/Psi2S/n%d_total_%d.root",N,i));
                        input6 = TFile::Open(Form("../3_Result/toyEffTrigger/Psi2S/n%d_total_%d.root",N,i));
		}
		T1 = (TH2D*)input1->Get("h_eff");
		T2 = (TH2D*)input2->Get("h_eff");
		T3 = (TH2D*)input3->Get("h_eff");
		T4 = (TH2D*)input4->Get("h_eff");
                T5 = (TH2D*)input5->Get("h_eff");
                T6 = (TH2D*)input6->Get("h_eff");
		for(int y=0;y<ny;y++)
                {       
                        for(int pt=0;pt<npt;pt++)
                        {
                                Content[pt][y][i] = T1->GetBinContent(pt+1,y+1)*T2->GetBinContent(pt+1,y+1)*T3->GetBinContent(pt+1,y+1)/T4->GetBinContent(pt+1,y+1)/T5->GetBinContent(pt+1,y+1)/T6->GetBinContent(pt+1,y+1);
				//Content[pt][y][i] = T1->GetBinContent(pt+1,y+1);
                        }
                }
		delete input1;
                delete input2;
                delete input3;
                delete input4;
                delete input5;
                delete input6;
	}
	int num_bin = 15;
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
                        }
                        mean[pt][y]=mean[pt][y]/200;
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
	TFile *Out = new TFile(argv[7],"recreate");
        TH2D *GausErrTable = (TH2D*)Trecj->Clone(0);
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
                        GausErrTable->SetBinContent(pt+1,y+1,g->GetParameter(2)/Teff->GetBinContent(pt+1,y+1));
                        //GausErrTable->SetBinContent(pt+1,y+1,g->GetParameter(2)/Trec->GetBinContent(pt+1,y+1));
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



