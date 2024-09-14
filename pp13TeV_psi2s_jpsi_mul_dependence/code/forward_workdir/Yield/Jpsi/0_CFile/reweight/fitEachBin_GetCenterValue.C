#include <fstream>
#include <TCanvas.h>
#include <TFile.h>
#include <TH1.h>
#include <TF1.h>
#include <TRandom3.h>
#include <math.h>
using namespace std;
double weight(double mu1, double sigma1, double mu2, double sigma2)
{
        double w1 = 1/sigma1/sigma1;
        double w2 = 1/sigma2/sigma2;
        return (w1*mu1+w2*mu2)/(w1+w2);
}
double weightErr(double sigma1, double sigma2)
{
        return sqrt((sigma1*sigma1*sigma2*sigma2)/(sigma1*sigma1+sigma2*sigma2));
}

int main(int argc, char* argv[])
{
	//random seed
	TRandom3 *r = new TRandom3(0);
	
	//For 5 bin
	TFile *input; //pointer input
	const int T = 10000;
	ofstream xb("../../../result/3_Result/Nch_fromb.txt");
	ofstream xp("../../../result/3_Result/Nch_prompt.txt");
	ofstream xberr("../../../result/3_Result/Nch_fromberr.txt");
        ofstream xperr("../../../result/3_Result/Nch_prompterr.txt");
	for(int n=0;n<5;n++)
	{	
		input = TFile::Open("../../3_Result/reweight/TH1D_Nch_in_different_PVN.root");
		TH1D *TbJ = (TH1D*)input->Get(Form("Tb%d",n+1));
		TH1D *TpJ = (TH1D*)input->Get(Form("Tp%d",n+1));
		TH1D *TnJ = (TH1D*)input->Get("Tbp");
		input = TFile::Open("../../../Psi2S/3_Result/reweight/TH1D_Nch_in_different_PVN.root");
		TH1D *TbP = (TH1D*)input->Get(Form("Tb%d",n+1));
                TH1D *TpP = (TH1D*)input->Get(Form("Tp%d",n+1));
		TH1D *TnP = (TH1D*)input->Get("Tbp");
		double mbj[T], mpj[T], mbp[T], mpp[T], mnj[T], mnp[T];
                for(int t=0;t<T;t++)
                {
		TH1D tbj = TH1D("tbj","tbj",400,0,400);
		TH1D tpj = TH1D("tpj","tpj",400,0,400);
		TH1D tbp = TH1D("tbp","tbp",400,0,400);
                TH1D tpp = TH1D("tpp","tpp",400,0,400);
		TH1D tnj = TH1D("tnj","tnj",400,0,400);
		TH1D tnp = TH1D("tnp","tnp",400,0,400);
		for(int j=0;j<400;j++)
		{
			double conTbJ = TbJ->GetBinContent(j+1);
			double conTbJerr = TbJ->GetBinError(j+1);
			double conTpJ = TpJ->GetBinContent(j+1);
                        double conTpJerr = TpJ->GetBinError(j+1);
			double conTbP = TbJ->GetBinContent(j+1);
                        double conTbPerr = TbJ->GetBinError(j+1);
                        double conTpP = TpJ->GetBinContent(j+1);
                        double conTpPerr = TpJ->GetBinError(j+1);
			double conTnJ = TnJ->GetBinContent(j+1);
                        double conTnJerr = TnJ->GetBinError(j+1);
			double conTnP = TnP->GetBinContent(j+1);
                        double conTnPerr = TnP->GetBinError(j+1);
			tbj.SetBinContent(j+1,r->Gaus(conTbJ,conTbJerr));
			tpj.SetBinContent(j+1,r->Gaus(conTpJ,conTpJerr));
			tbp.SetBinContent(j+1,r->Gaus(conTbP,conTbPerr));
                        tpp.SetBinContent(j+1,r->Gaus(conTpP,conTpPerr));
			tnj.SetBinContent(j+1,r->Gaus(conTnJ,conTnJerr));
                        tnp.SetBinContent(j+1,r->Gaus(conTnP,conTnPerr));
		}
		mbj[t] = tbj.GetMean();
		mpj[t] = tpj.GetMean();
		mbp[t] = tbp.GetMean();
                mpp[t] = tpp.GetMean();
		mnj[t] = tnj.GetMean();
                mnp[t] = tnp.GetMean();
		}
		double meanbj, meanpj, meanbp, meanpp, meannj, meannp;
		double sbj, spj, sbp, spp, snj, snp;
		sbj = 0;
		spj = 0;
		sbp = 0;
		spp = 0;
		snj = 0;
		snp = 0;
		for(int t=0; t<T; t++)
		{
			sbj = sbj+mbj[t];
			spj = spj+mpj[t];
			sbp = sbp+mbp[t];
                        spp = spp+mpp[t];
			snj = snj+mnj[t];
                        snp = snp+mnp[t];
		}
		meanbj = sbj/T;
		meanpj = spj/T;
		meanbp = sbp/T;
		meanpp = spp/T;
		meannj = snj/T;
		meannp = snp/T;
		sbj = 0;
                spj = 0;
                sbp = 0;
                spp = 0;
		for(int t=0; t<T; t++)
                {
                        sbj = sbj+(meanbj-mbj[t])*(meanbj-mbj[t]);
                        spj = spj+(meanpj-mpj[t])*(meanpj-mpj[t]);
			sbp = sbp+(meanbp-mbp[t])*(meanbp-mbp[t]);
			spp = spp+(meanpp-mpp[t])*(meanpp-mpp[t]);
                }
		sbj = sqrt(sbj/(T-1));
		spj = sqrt(spj/(T-1));
		sbp = sqrt(sbp/(T-1));
                spp = sqrt(spp/(T-1));
		xb << weight(meanbj, sbj, meanbp, sbp) << endl; ///meannj
		xp << weight(meanpj, spj, meanpp, spp) << endl;
		xberr << weightErr(sbj,spj)/meannj << endl;
		xperr << weightErr(sbp,spp)/meannp << endl;
	}
	xp.close();
	xb.close();
	xperr.close();
	xberr.close();
	return 0;
}

