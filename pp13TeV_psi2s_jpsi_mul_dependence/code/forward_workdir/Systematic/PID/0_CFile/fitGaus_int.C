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
	double Content[200];

	//N: multiplicity, Type: 1 prompt 2 fromb and 3 total
	int N, Type;
	sscanf(argv[3],"%d",&N);
	sscanf(argv[4],"%d",&Type);

	//input each nominal efficiency except for PID
	TFile *JAcc;
	TFile *JRec;
	TFile *JTri;
	TFile *JPID;
	TH2D *TJacc;
	TH2D *TJrec;
	TH2D *TJtri;
	TH2D *TJpid;
	TFile *PAcc;
        TFile *PRec;
        TFile *PTri;
	TFile *PPID;
        TH2D *TPacc;
        TH2D *TPrec;
        TH2D *TPtri;
	TH2D *TPpid;

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
			JAcc = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_prompt.root"));
			JRec = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_rec_sel/n%d_prompt.root",N));
			JTri =  TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_trigger/n%d_prompt.root",N));
			PAcc = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_prompt.root"));
                        PRec = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_rec_sel/n%d_prompt.root",N));
                        PTri =  TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_trigger/n%d_prompt.root",N));
			JPID = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_pid/n%d_prompt.root",N));
			PPID = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_pid/n%d_prompt.root",N));
		}
		if(Type == 2)
                {       
                        inputJ = TFile::Open(Form("../3_Result/toyPIDeff/Jpsi/n%d_fromb_%d.root",N,i));
	                inputP = TFile::Open(Form("../3_Result/toyPIDeff/Psi2S/n%d_fromb_%d.root",N,i));
			JAcc = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_fromb.root"));
                        JRec = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_rec_sel/n%d_fromb.root",N));
                        JTri =  TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_trigger/n%d_fromb.root",N));
                        PAcc = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_fromb.root"));
                        PRec = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_rec_sel/n%d_fromb.root",N));
                        PTri =  TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_trigger/n%d_fromb.root",N));
			JPID = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_pid/n%d_fromb.root",N));
                        PPID = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_pid/n%d_fromb.root",N));
		}
		if(Type == 3)
                {       
                        inputJ = TFile::Open(Form("../3_Result/toyPIDeff/Jpsi/n%d_total_%d.root",N,i));
                	inputP = TFile::Open(Form("../3_Result/toyPIDeff/Psi2S/n%d_total_%d.root",N,i));
			JAcc = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_total.root"));
                        JRec = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_rec_sel/n%d_total.root",N));
                        JTri =  TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_trigger/n%d_total.root",N));
                        PAcc = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_total.root"));
                        PRec = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_rec_sel/n%d_total.root",N));
                        PTri =  TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_trigger/n%d_total.root",N));
			JPID = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_pid/n%d_total.root",N));
                        PPID = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_pid/n%d_total.root",N));
		}
		TJacc = (TH2D*)JAcc->Get("h_eff");
		TJrec = (TH2D*)JRec->Get("h_eff");
		TJtri = (TH2D*)JTri->Get("h_eff");
		TPacc = (TH2D*)PAcc->Get("h_eff");
                TPrec = (TH2D*)PRec->Get("h_eff");
                TPtri = (TH2D*)PTri->Get("h_eff");
		TJpid = (TH2D*)JPID->Get("h_eff");
		TPpid = (TH2D*)PPID->Get("h_eff");
		TJ = (TH2D*)inputJ->Get("h_eff");
		TP = (TH2D*)inputP->Get("h_eff");
		//cout << "draw" << endl;
		//cout << "draw end" << endl;
		double Sum_SigJ = 0;
                double Sum_SigP = 0;
		for(int y=0;y<ny;y++)
		//for(int pt=0;pt<npt;pt++)
		{
			//for(int y=0;y<ny;y++)
			for(int pt=0;pt<npt;pt++)
			{
				ifstream YJ(Form("../../../Yield/Jpsi/3_Result/2DFit/txt_n%dy%dpt%d.txt",N,y+1,pt+1));
				ifstream YP(Form("../../../Yield/Psi2S/3_Result/2DFit/txt_n%dy%dpt%d.txt",N,y+1,pt+1));
				double JN, PN, JNp, JNb, PNp,PNb;
				for(int index=1;index<=11;index++)
				{
					YJ>>JNp;
					YP>>PNp;
				}
				for(int index=1;index<=2;index++)
                                {
                                        YJ>>JNb;
                                        YP>>PNb;
                                }
				if(Type==1) 
				{
					JN = JNp;
					PN = PNp;
				}
				if(Type==2) 
                                {
                                        JN = JNb;
                                        PN = PNb;
                                }
				if(Type==3) 
                                {
                                        JN = JNp+JNb;
                                        PN = PNp+PNb;
                                }
				Sum_SigJ = Sum_SigJ+JN/TJacc->GetBinContent(pt+1,y+1)/TJrec->GetBinContent(pt+1,y+1)/TJtri->GetBinContent(pt+1,y+1)/TJ->GetBinContent(pt+1,y+1);
				Sum_SigP = Sum_SigP+PN/TPacc->GetBinContent(pt+1,y+1)/TPrec->GetBinContent(pt+1,y+1)/TPtri->GetBinContent(pt+1,y+1)/TP->GetBinContent(pt+1,y+1);
			}
		}
		Content[i]=Sum_SigP/Sum_SigJ;
		inputJ -> Close();
		inputP -> Close();
		JAcc -> Close();
		JRec -> Close();
		JTri -> Close(); 
		PAcc -> Close();
		PRec -> Close();
		PTri -> Close();
		JPID -> Close();
		PPID -> Close();
	}
	//Calculate mean and std for each bin
	//Then we can fill an appropriate TH1 to fit
	int num_bin = 15;
	double mean[1], std[1];
	TH1D *th[1];
	for(int y=0;y<1;y++)
        {
		mean[y]=0;
		for(int i=0;i<200;i++)
		{
			mean[y]=mean[y]+Content[i];
		}
		mean[y]=mean[y]/200;
		std[y]=0;
		for(int i=0;i<200;i++)
                {
			std[y]=std[y]+(Content[i]-mean[y])*(Content[i]-mean[y]);
		}
		std[y]=sqrt(std[y]/199);
		th[y] = new TH1D(Form("thy%d",y),Form("thy%d",y),num_bin,mean[y]-3*std[y],mean[y]+3*std[y]);
	}
	//output
	TFile *Out = new TFile(argv[2],"recreate");
	//TH2D *GausErrTable2D = (TH2D*)Ttemp->Clone(0);
	//TH1D *GausErrTable = (TH1D*)GausErrTable2D->ProjectionX();
	ofstream GausErrTable(Form("../3_Result/StatCalibVar/n%d_type%d.txt",N,Type));
	//Fit and Fill TH1D
	TCanvas *can[1];
        for(int y=0;y<1;y++)
        {
                for(int i=0;i<200;i++)
                {
			th[y]->Fill(Content[i]);
		}
		can[y] = new TCanvas(Form("can%d",y),Form("can%d",y),800,600);
		th[y]->SetLineColor(kRed);
		th[y]->Draw();
		th[y]->Fit("gaus");
		TF1 *g = (TF1*)th[y]->GetListOfFunctions()->FindObject("gaus");
		GausErrTable<<(y+1,g->GetParameter(2)/g->GetParameter(1))<<endl;
		if(Type==1) can[y]->SaveAs(Form("../4_Plot/prompt_int_y%d.pdf",y+1));
		if(Type==2) can[y]->SaveAs(Form("../4_Plot/fromb_int_y%d.pdf",y+1));
		if(Type==3) can[y]->SaveAs(Form("../4_Plot/total_int_y%d.pdf",y+1));
		can[y]->Close();
	}
	Out->Close();
	return 0;
}
	

