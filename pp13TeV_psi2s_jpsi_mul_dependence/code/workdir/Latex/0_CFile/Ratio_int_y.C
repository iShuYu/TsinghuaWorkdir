#include <TString.h>
#include <iostream>
#include <fstream>
#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>
using namespace std;
int main(int argc, char* argv[])
{
	//input Nbin
	//int N;
	//sscanf(argv[1],"%d",&N);
	ifstream nconfig("../../Yield/rawdata/3_Bins/nbin");
	int numN;
	nconfig >> numN;
	int PVN[numN+1];
	int flag;
	for(int i=0; i<=numN; i++)
        {
                nconfig >> flag;
                PVN[i] = flag;
        }
	ifstream yconfig("../../Yield/rawdata/3_Bins/ybin");
        int numY;
        yconfig >> numY;
        double y[numY+1];
        double flag1;
        for(int i=0; i<=numY; i++)
        {
                yconfig >> flag1;
                y[i] = flag1;
        }

	//input CSs of Jpsi and Psi2S
	TFile *input;
	ofstream outb("../2_Table/Ratio/Int_y_fromb.tex");
	//ofstream outp("../2_Table/Ratio/Int_pt_prompt.tex");
	outb << "\\begin{table}[H]" << endl;
        outb << Form("\\caption{Ratio(\\%) of integrated production cross-section in \\nb(\\gevc) for \\psitwos to \\jpsi from $b$-hardron decay as a function of $y$. The first uncertainties are statistical, the second are the systematic uncertainties.}") << endl;
        outb << "\\centering" << endl;
        outb << "\\resizebox{\\linewidth}{!}{" << endl;
        outb << "\\begin{tabular}{c|ccccc}" << endl;
        outb << "\\hline" << endl;
        //outb << "$y$ & $0<PVNTRACKS<20$ & $20<PVNTRACKS<40$ & $40<PVNTRACKS<60$ & $60<PVNTRACKS<80$ & $80<PVNTRACKS<200$ \\\\" << endl;
	//outb << "\\hline" << endl;
	outb << "\\multirow{2}{*}{\\pt(\\gevc)} &  \\multicolumn{5}{|c}{PVNTRACKS}  \\\\ \\cline{2-6}" << endl;
        outb << " &  0-20 & 20-40  & 40-60   & 60-80   & 80-200  \\\\ \\hline" << endl;
	double Rp[5], Rb[5];
	double Sp[5], Sb[5];
	double Tp[5], Tb[5];
	for(int i=1; i<=numY; i++)
	{
		for(int N=1; N<=numN; N++)
		{
			input = TFile::Open("../../Yield/result/3_Result/Save.root");
			TH1D *pY = (TH1D*)input->Get(Form("pY%d",i));
                	TH1D *bY = (TH1D*)input->Get(Form("bY%d",i));
			Rp[N-1]=100*pY->GetBinContent(N);
			Rb[N-1]=100*bY->GetBinContent(N);
			//input Sys Err
			input = TFile::Open(Form("../../Systematic/AllErr/3_Result/n%d_int_y_OnlySysErr.root",N));
			TH1D *SErrp = (TH1D*)input->Get("prompt");
        		TH1D *SErrb = (TH1D*)input->Get("fromb");
        		Sp[N-1]=SErrp->GetBinContent(i);
			Sb[N-1]=SErrb->GetBinContent(i);
			//input Stat Err
			input = TFile::Open(Form("../../Systematic/AllErr/3_Result/n%d_int_y_AllsysErr.root",N));
			TH1D *TErrp = (TH1D*)input->Get("prompt");
        		TH1D *TErrb = (TH1D*)input->Get("fromb");
        	        Tp[N-1]=TErrp->GetBinContent(i);
        	        Tb[N-1]=TErrb->GetBinContent(i);
			Tp[N-1]=sqrt(Tp[N-1]*Tp[N-1]-Sp[N-1]*Sp[N-1]);
        	        Tb[N-1]=sqrt(Tb[N-1]*Tb[N-1]-Sb[N-1]*Sb[N-1]);
        	        Sp[N-1]=Sp[N-1]*Rp[N-1];
        	        Sb[N-1]=Sb[N-1]*Rb[N-1];
        	        Tp[N-1]=Tp[N-1]*Rp[N-1];
        	        Tb[N-1]=Tb[N-1]*Rb[N-1];
        	}
		outb << Form("%.1f-%.1f & $%.2f\\pm%.2f\\pm%.2f$ & $%.2f\\pm%.2f\\pm%.2f$ & $%.2f\\pm%.2f\\pm%.2f$ & $%.2f\\pm%.2f\\pm%.2f$ & $%.2f\\pm%.2f\\pm%.2f$ \\\\",y[i-1],y[i],Rb[0],Tb[0],Sb[0],Rb[1],Tb[1],Sb[1],Rb[2],Tb[2],Sb[2],Rb[3],Tb[3],Sb[3],Rb[4],Tb[4],Sb[4]) << endl;
	}
	outb << "\\hline" << endl;
        outb << "\\end{tabular}" << endl;
        outb << "}" << endl;
        outb << "\\label{Ratio_fromb_int_y}" << endl;
        outb << "\\end{table}" << endl;
        outb.close();
	//prompt
	ofstream outp("../2_Table/Ratio/Int_y_prompt.tex");
	outp << "\\begin{table}[H]" << endl;
        outp << Form("\\caption{Ratio(\\%) of integrated production cross-section in \\nb(\\gevc) for prompt \\psitwos to \\jpsi as a function of $y$. The first uncertainties are statistical, the second are the systematic uncertainties.}") << endl;
        outp << "\\centering" << endl;
        outp << "\\resizebox{\\linewidth}{!}{" << endl;
        outp << "\\begin{tabular}{c|ccccc}" << endl;
        outp << "\\hline" << endl;
	//outp << "$y$& $0<PVNTRACKS<20$ & $20<PVNTRACKS<40$ & $40<PVNTRACKS<60$ & $60<PVNTRACKS<80$ & $80<PVNTRACKS<200$ \\\\" << endl;
	//outp << "\\hline" << endl;
	outp << "\\multirow{2}{*}{\\pt(\\gevc)} &  \\multicolumn{5}{|c}{PVNTRACKS}  \\\\ \\cline{2-6}" << endl;
        outp << " &  0-20 & 20-40  & 40-60   & 60-80   & 80-200  \\\\ \\hline" << endl;
	for(int i=1; i<=numY; i++)
        {       
                for(int N=1; N<=numN; N++)
                {
			input = TFile::Open("../../Yield/result/3_Result/Save.root");
                        TH1D *pY = (TH1D*)input->Get(Form("pY%d",i));
                        TH1D *bY = (TH1D*)input->Get(Form("bY%d",i));
                        Rp[N-1]=100*pY->GetBinContent(N);
                        Rb[N-1]=100*bY->GetBinContent(N);
			input = TFile::Open(Form("../../Systematic/AllErr/3_Result/n%d_int_y_OnlySysErr.root",N));
                        TH1D *SErrp = (TH1D*)input->Get("prompt");
                        TH1D *SErrb = (TH1D*)input->Get("fromb");
                        Sp[N-1]=SErrp->GetBinContent(i);
                        Sb[N-1]=SErrb->GetBinContent(i);
			input = TFile::Open(Form("../../Systematic/AllErr/3_Result/n%d_int_y_AllsysErr.root",N));
                        TH1D *TErrp = (TH1D*)input->Get("prompt");
                        TH1D *TErrb = (TH1D*)input->Get("fromb");
                        Tp[N-1]=TErrp->GetBinContent(i);
                        Tb[N-1]=TErrb->GetBinContent(i);
                        Tp[N-1]=sqrt(Tp[N-1]*Tp[N-1]-Sp[N-1]*Sp[N-1]);
                        Tb[N-1]=sqrt(Tb[N-1]*Tb[N-1]-Sb[N-1]*Sb[N-1]);
                        Sp[N-1]=Sp[N-1]*Rp[N-1];
                        Sb[N-1]=Sb[N-1]*Rb[N-1];
                        Tp[N-1]=Tp[N-1]*Rp[N-1];
                        Tb[N-1]=Tb[N-1]*Rb[N-1];
                }
                outp << Form("%.1f-%.1f & $%.2f\\pm%.2f\\pm%.2f$ & $%.2f\\pm%.2f\\pm%.2f$ & $%.2f\\pm%.2f\\pm%.2f$ & $%.2f\\pm%.2f\\pm%.2f$ & $%.2f\\pm%.2f\\pm%.2f$ \\\\",y[i-1],y[i],Rp[0],Tp[0],Sp[0],Rp[1],Tp[1],Sp[1],Rp[2],Tp[2],Sp[2],Rp[3],Tp[3],Sp[3],Rp[4],Tp[4],Sp[4]) << endl;
	}
	outp << "\\hline" << endl;
        outp << "\\end{tabular}" << endl;
        outp << "}" << endl;
        outp << "\\label{Ratio_prompt_int_y}" << endl;
        outp << "\\end{table}" << endl;
        outp.close();
	return 0;
}
