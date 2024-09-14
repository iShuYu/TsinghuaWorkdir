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
int main(int argc, char *argv[])
{
	//input total efficiency
	int N;
        sscanf(argv[1],"%d",&N);
	TFile *input;
	input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_tot/n%d_fromb.root",N));
	TH2D *Jeffb = (TH2D*)input->Get("h_3");
	input = TFile::Open(Form("../../../Yield/Jpsi/3_Result/eff_tot/n%d_prompt.root",N));
        TH2D *Jeffp = (TH2D*)input->Get("h_3");
	input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_tot/n%d_fromb.root",N));
        TH2D *Peffb = (TH2D*)input->Get("h_3");
        input = TFile::Open(Form("../../../Yield/Psi2S/3_Result/eff_tot/n%d_prompt.root",N));
        TH2D *Peffp = (TH2D*)input->Get("h_3");
	//input cross section result
	input = TFile::Open(Form("../../../Yield/result/3_Result/Conclude.root"));
	TH2D *CSJb = (TH2D*)input->Get(Form("Jb%d",N));
	TH2D *CSJp = (TH2D*)input->Get(Form("Jp%d",N));
	TH2D *CSPb = (TH2D*)input->Get(Form("Pb%d",N));
        TH2D *CSPp = (TH2D*)input->Get(Form("Pp%d",N));
	int npt = CSJb->GetNbinsX();
	int ny = CSJb->GetNbinsY();
	TFile *out = new TFile(Form("../3_Result/n%dMCSizeErrIntY.root",N),"recreate");
	TH1D *Tp = (TH1D*)CSJb->ProjectionY("a");
	TH1D *Tb = (TH1D*)CSJb->ProjectionY("b");
	for(int y=1;y<=ny;y++)
	//for(int pt=1;pt<=npt;pt++)
	{
		double Sum_SigJb = 0;
                double Sum_SigPb = 0;
                double Sum_SigJp = 0;
                double Sum_SigPp = 0;
		double Sum_ErrJb = 0;
		double Sum_ErrPb = 0;
		double Sum_ErrJp = 0;
                double Sum_ErrPp = 0;
		double cs, rErr;
		for(int pt=1;pt<npt;pt++)
		//for(int y=1;y<=ny;y++)
		{
			cs = CSJp->GetBinContent(pt,y);
			rErr = Jeffp->GetBinError(pt,y)/Jeffp->GetBinContent(pt,y);
			Sum_SigJp = Sum_SigJp + cs;
			Sum_ErrJp = Sum_ErrJp + cs*cs*rErr*rErr;
			cs = CSPp->GetBinContent(pt,y);
			rErr = Peffp->GetBinError(pt,y)/Peffp->GetBinContent(pt,y);
                        Sum_SigPp = Sum_SigPp + cs;
			Sum_ErrPp = Sum_ErrPp + cs*cs*rErr*rErr;
			cs = CSJb->GetBinContent(pt,y);
			rErr = Jeffb->GetBinError(pt,y)/Jeffb->GetBinContent(pt,y);
                        Sum_SigJb = Sum_SigJb + cs;
			Sum_ErrJb = Sum_ErrJb + cs*cs*rErr*rErr;
			cs = CSPb->GetBinContent(pt,y);
			rErr = Peffb->GetBinError(pt,y)/Peffb->GetBinContent(pt,y);
                        Sum_SigPb = Sum_SigPb + cs;
			Sum_ErrPb = Sum_ErrPb + cs*cs*rErr*rErr;
		}
		Sum_ErrJp = sqrt(Sum_ErrJp)/Sum_SigJp;
		Sum_ErrPp = sqrt(Sum_ErrPp)/Sum_SigPp;
		Sum_ErrJb = sqrt(Sum_ErrJb)/Sum_SigJb;
		Sum_ErrPb = sqrt(Sum_ErrPb)/Sum_SigPb;
		Tp->SetBinContent(y,sqrt(Sum_ErrPp*Sum_ErrPp+Sum_ErrJp*Sum_ErrJp));
		Tb->SetBinContent(y,sqrt(Sum_ErrPb*Sum_ErrPb+Sum_ErrJb*Sum_ErrJb));
		Tp->SetBinError(y,0);
		Tb->SetBinError(y,0);
	}
	Tp->Write("MCSizeErrPrompt");
	Tb->Write("MCSizeErrFromb");
	out->Close();
	return 0;
}
