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
	int N;
	sscanf(argv[1],"%d",&N);
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
	//input CSs of Jpsi and Psi2S
	TFile *input;
	input = TFile::Open("../../Yield/result/3_Result/Conclude.root");
	TH2D *CSJp = (TH2D*)input->Get(Form("Jp%d",N));
	TH2D *CSJb = (TH2D*)input->Get(Form("Jb%d",N));
	TH2D *CSPp = (TH2D*)input->Get(Form("Pp%d",N));
	TH2D *CSPb = (TH2D*)input->Get(Form("Pb%d",N));
	//ratio
	double Rp[5][3], Rb[5][3];
	for(int i=1; i<=5; i++)
	{
		for(int j=1;j<=3;j++)
		{
			Rp[i-1][j-1]=100*CSPp->GetBinContent(i,j)/CSJp->GetBinContent(i,j);
			Rb[i-1][j-1]=100*CSPb->GetBinContent(i,j)/CSJb->GetBinContent(i,j);
		}
	}
	//input Sys Error
	input = TFile::Open(Form("../../Systematic/AllErr/3_Result/n%d_OnlySysErr.root",N));
	TH2D *SErrp = (TH2D*)input->Get("prompt");
	TH2D *SErrb = (TH2D*)input->Get("fromb");
	double Sp[5][3], Sb[5][3];
	for(int i=1; i<=5; i++)
        {
                for(int j=1;j<=3;j++)
                {
			Sp[i-1][j-1]=SErrp->GetBinContent(i,j);
                        Sb[i-1][j-1]=SErrb->GetBinContent(i,j);
                }
        }
	//input Stat Err
	input = TFile::Open(Form("../../Systematic/AllErr/3_Result/n%d_AllsysErr.root",N));
        TH2D *TErrp = (TH2D*)input->Get("prompt");
        TH2D *TErrb = (TH2D*)input->Get("fromb");
        double Tp[5][3], Tb[5][3];
        for(int i=1; i<=5; i++)
        {
                for(int j=1;j<=3;j++)
                {
                        Tp[i-1][j-1]=TErrp->GetBinContent(i,j);
                        Tb[i-1][j-1]=TErrb->GetBinContent(i,j);
			Tp[i-1][j-1]=sqrt(Tp[i-1][j-1]*Tp[i-1][j-1]-Sp[i-1][j-1]*Sp[i-1][j-1]);
			Tb[i-1][j-1]=sqrt(Tb[i-1][j-1]*Tb[i-1][j-1]-Sb[i-1][j-1]*Sb[i-1][j-1]);
			Sp[i-1][j-1]=Sp[i-1][j-1]*Rp[i-1][j-1];
                        Sb[i-1][j-1]=Sb[i-1][j-1]*Rb[i-1][j-1];
			Tp[i-1][j-1]=Tp[i-1][j-1]*Rp[i-1][j-1];
                        Tb[i-1][j-1]=Tb[i-1][j-1]*Rb[i-1][j-1];
                }
        }
	//outut
	ofstream out(Form("../2_Table/Ratio/n%df.tex",N));
	out.setf(ios::fixed, ios::floatfield);
        out.precision(2);
	out << "\\begin{table}[H]" << endl;
	out << Form("\\caption{Ratios (\\%) of double differential production cross-section for \\psitwos to \\jpsi in bins of (\\pt,$y$) for %d $\\leq$ $N_{\\rm fwd}^{\\rm PV}$ $<$ %d. The first uncertainties are statistical, the second are systematic. }",PVN[N-1],PVN[N]) << endl;
	out << "\\centering" << endl;
	out << "\\resizebox{0.7\\linewidth}{!}{" << endl;
	out << "\\begin{tabular}{|c|ccc|}" << endl;
	out << "\\hline" << endl;
	out << "\\multicolumn{4}{|c|}{prompt}\\\\";
	out << "\\hline" << endl;
	out << "\\pt(\\gevc)& $2<y<2.8$& $2.8<y<3.5$& $3.5<y<4.5$ \\\\" << endl;
	out << "\\hline" << endl;
	out << Form("0-2&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$\\\\",Rp[0][0],Tp[0][0],Sp[0][0],Rp[0][1],Tp[0][1],Sp[0][1],Rp[0][2],Tp[0][2],Sp[0][2]) << endl;
	out << Form("2-4&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$\\\\",Rp[1][0],Tp[1][0],Sp[1][0],Rp[1][1],Tp[1][1],Sp[1][1],Rp[1][2],Tp[1][2],Sp[1][2]) << endl;
	out << Form("4-6&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$\\\\",Rp[2][0],Tp[2][0],Sp[2][0],Rp[2][1],Tp[2][1],Sp[2][1],Rp[2][2],Tp[2][2],Sp[2][2]) << endl;
	out << Form("6-8&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$\\\\",Rp[3][0],Tp[3][0],Sp[3][0],Rp[3][1],Tp[3][1],Sp[3][1],Rp[3][2],Tp[3][2],Sp[3][2]) << endl;
	out << Form("8-20&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$\\\\",Rp[4][0],Tp[4][0],Sp[4][0],Rp[4][1],Tp[4][1],Sp[4][1],Rp[4][2],Tp[4][2],Sp[4][2]) << endl;
	out << "\\hline" << endl;
        out << "\\multicolumn{4}{|c|}{non-prompt}\\\\";
	out << "\\hline" << endl;
        out << "\\pt(\\gevc)& $2<y<2.8$& $2.8<y<3.5$& $3.5<y<4.5$ \\\\" << endl;
        out << "\\hline" << endl;
        out << Form("0-2&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$\\\\",Rb[0][0],Tb[0][0],Sb[0][0],Rb[0][1],Tb[0][1],Sb[0][1],Rb[0][2],Tb[0][2],Sb[0][2]) << endl;
        out << Form("2-4&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$\\\\",Rb[1][0],Tb[1][0],Sb[1][0],Rb[1][1],Tb[1][1],Sb[1][1],Rb[1][2],Tb[1][2],Sb[1][2]) << endl;
        out << Form("4-6&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$\\\\",Rb[2][0],Tb[2][0],Sb[2][0],Rb[2][1],Tb[2][1],Sb[2][1],Rb[2][2],Tb[2][2],Sb[2][2]) << endl;
        out << Form("6-8&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$\\\\",Rb[3][0],Tb[3][0],Sb[3][0],Rb[3][1],Tb[3][1],Sb[3][1],Rb[3][2],Tb[3][2],Sb[3][2]) << endl;
        out << Form("8-20&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$&$%.2f\\pm%.2f\\pm%.2f$\\\\",Rb[4][0],Tb[4][0],Sb[4][0],Rb[4][1],Tb[4][1],Sb[4][1],Rb[4][2],Tb[4][2],Sb[4][2]) << endl;
        out << "\\hline" << endl;
        out << "\\end{tabular}" << endl;
        out << "}" << endl;
        out << Form("\\label{RatioFOR%d}",N) << endl;
        out << "\\end{table}" << endl;
        out.close();	
	return 0;
}
