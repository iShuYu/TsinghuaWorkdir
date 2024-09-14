#include <TString.h>
#include <iostream>
#include <fstream>
#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>
using namespace std;
int main(int argc, char* argv[])
{
	//input binning scheme
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
	//input all fit results
	double Ptau1[5][3], Ptau2[5][3], Ptau3[5][3], Ptau4[5][3], Pf1[5][3], Pf2[5][3], Pf3[5][3], Pf4[5][3], Pbias[5][3], PSigma1[5][3], PSigma2[5][3], Pbeta[5][3];
	double Ptau1Err[5][3], Ptau2Err[5][3], Ptau3Err[5][3], Ptau4Err[5][3], Pf1Err[5][3], Pf2Err[5][3], Pf3Err[5][3], Pf4Err[5][3], PbiasErr[5][3], PSigma1Err[5][3], PSigma2Err[5][3], PbetaErr[5][3];
	for(int pt=0;pt<5;pt++)
	{
		for(int y=0;y<3;y++)
		{
			double a = 0;
                        double b = 0;
                        double C = 0;
                        double d = 0;
                        double e = 0;
                        double f = 0;
                        double g = 0;
                        double h = 0;
                        double i = 0;
                        double j = 0;
                        double k = 0;
                        double l = 0;
                        double aE = 0;
                        double bE = 0;
                        double cE = 0;
                        double dE = 0;
                        double eE = 0;
                        double fE = 0;
                        double gE = 0;
                        double hE = 0;
                        double iE = 0;
                        double jE = 0;
                        double kE = 0;
                        double lE = 0;
			ifstream F(Form("../../Yield/Psi2S/3_Result/TzbkgFit/Tzbkg_n%dy%dpt%d.txt",N,y+1,pt+1));
			string X;
	        	while(F >> X)
        		{
				if(X=="beta") F >> a >> aE;
		                if(X=="bias") F >> b >> bE;
		                if(X=="f1") F >> C >> cE;
        		        if(X=="f2") F >> d >> dE;
                		if(X=="f3") F >> e >> eE;
              			if(X=="f4") F >> f >> fE;
                		if(X=="sigma1") F >> g >> gE;
                		if(X=="sigma2") F >> h >> hE;
                		if(X=="tau1") F >> i >> iE;
                		if(X=="tau2") F >> j >> jE;
                		if(X=="tau3") F >> k >> kE;
                		if(X=="tau4") F >> l >> lE;
			}
			Pbeta[pt][y] = a;
                       	PbetaErr[pt][y] = aE;
                        Pbias[pt][y] = b*1000;
                       	PbiasErr[pt][y] = bE*1000;
                       	Pf1[pt][y] = C;
                       	Pf1Err[pt][y] = cE;
                       	Pf2[pt][y] = d;
                       	Pf2Err[pt][y] = dE;
                       	Pf3[pt][y] = e;
                       	Pf3Err[pt][y] = eE;
                       	Pf4[pt][y] = f;
                       	Pf4Err[pt][y] = fE;
                       	PSigma1[pt][y] = g;
                       	PSigma1Err[pt][y] = gE;
                       	PSigma2[pt][y] = h;
                       	PSigma2Err[pt][y] = hE;
                       	Ptau1[pt][y] = i;
                       	Ptau1Err[pt][y] = iE;
                       	Ptau2[pt][y] = j;
                       	Ptau2Err[pt][y] = jE;
                       	Ptau3[pt][y] = k;
                       	Ptau3Err[pt][y] = kE;
                       	Ptau4[pt][y] = l;
                       	Ptau4Err[pt][y] = lE;
        	}
	}
	//output latex
	double ybin[4] = {2.0, 2.8, 3.5, 4.5};
        for(int y=0;y<3;y++)
        {
                ofstream Pout(Form("../2_Table/TzFitResult/Pn%dy%d.tex",N,y+1));
		Pout.setf(ios::fixed, ios::floatfield);
                Pout.precision(2);
		Pout << "\\begin{table}[H]" << endl;
                Pout << "\\begin{center}" << endl;
		Pout << Form("\\caption{The parameters of $t_z$ background fit for \\psitwos in the rapidity bin $%.1f<y<%.1f$ and multiplicity bin $%d<PVNTRACKS<%d$.}",ybin[y],ybin[y+1],PVN[N-1],PVN[N]) << endl;
		Pout << "\\resizebox{\\linewidth}{!}{" << endl;
                Pout << "\\begin{tabular}{c|ccccc}" << endl;
                Pout << "\\hline" << endl;
                Pout << "\\multirow{2}{*}{\\psitwos parameters} &  \\multicolumn{5}{|c}{\\pt(\\gevc)}  \\\\ \\cline{2-6}" << endl;
                Pout << "&  0-2 & 2-4  & 4-6   & 6-8   & 8-20   \\\\ \\hline" << endl;
		Pout << "$\\tau_1$";
		for(int c=0;c<5;c++)
		{
			if(Pf1[c][y]!=0) Pout << Form("& $%.2f\\pm%.2f$",Ptau1[c][y], Ptau1Err[c][y]);
			else Pout << "& -";
		}
		Pout << "\\\\" << endl;
		Pout << "$\\tau_2$";
                for(int c=0;c<5;c++)
                {
                        if(Pf2[c][y]!=0) Pout << Form("& $%.2f\\pm%.2f$",Ptau2[c][y], Ptau2Err[c][y]);
                        else Pout << "& -";
                }
		Pout << "\\\\" << endl;
		Pout << "$\\tau_3$";
                for(int c=0;c<5;c++)
                {   
                        if(Pf3[c][y]!=0) Pout << Form("& $%.2f\\pm%.2f$",Ptau3[c][y], Ptau3Err[c][y]);
                        else Pout << "& -";
                }
		Pout << "\\\\" << endl;
		Pout << "$\\tau_4$";
                for(int c=0;c<5;c++)
                {   
                        if(Pf4[c][y]!=0) Pout << Form("& $%.2f\\pm%.2f$",Ptau4[c][y], Ptau4Err[c][y]);
                        else Pout << "& -";
                }
		Pout << "\\\\" << endl;
		Pout << "$f_1$";
                for(int c=0;c<5;c++)
                {
                        if(Pf1[c][y]!=0) Pout << Form("& $%.3f\\pm%.3f$",Pf1[c][y], Pf1Err[c][y]);
                        else Pout << "& 0";
                }
                Pout << "\\\\" << endl;
                Pout << "$f_2$";
                for(int c=0;c<5;c++)
                {
                        if(Pf2[c][y]!=0) Pout << Form("& $%.3f\\pm%.3f$",Pf2[c][y], Pf2Err[c][y]);
                        else Pout << "& 0";
                }
                Pout << "\\\\" << endl;
                Pout << "$f_3$";
                for(int c=0;c<5;c++)
                {
                        if(Pf3[c][y]!=0) Pout << Form("& $%.3f\\pm%.3f$",Pf3[c][y], Pf3Err[c][y]);
                        else Pout << "& 0";
                }
                Pout << "\\\\" << endl;
                Pout << "$f_4$";
                for(int c=0;c<5;c++)
                {
                        if(Pf4[c][y]!=0) Pout << Form("& $%.3f\\pm%.3f$",Pf4[c][y], Pf4Err[c][y]);
                        else Pout << "& 0";
                }
                Pout << "\\\\" << endl;
		Pout << "$1000*\\mu_{tzbkg}$";
		for(int c=0;c<5;c++) Pout << Form("& $%.1f\\pm%.1f$",Pbias[c][y], PbiasErr[c][y]);
		Pout << "\\\\" << endl;
		Pout << "$\\beta_{tzbkg}$";
                for(int c=0;c<5;c++)
                {
                        if(Pbeta[c][y]!=0) Pout << Form("& $%.2f\\pm%.2f$",Pbeta[c][y], PbetaErr[c][y]);
                        else Pout << "& 0";
                }
		Pout << "\\\\" << endl;
		Pout << "$S1_{tzbkg}$";
		for(int c=0;c<5;c++)
                {   
                        if(Pbeta[c][y]!=0) Pout << Form("& $%.2f\\pm%.2f$",PSigma1[c][y], PSigma1Err[c][y]);
                        else Pout << "& -";
                }
		Pout << "\\\\" << endl;
		Pout << "$S2_{tzbkg}$";
		for(int c=0;c<5;c++) Pout << Form("& $%.2f\\pm%.2f$",PSigma2[c][y], PSigma2Err[c][y]);
		Pout << "\\\\" << endl;
		Pout << "\\hline" << endl;
                Pout << "\\end{tabular}" << endl;
                Pout << "}" << endl;
                Pout << "\\end{center}" << endl;
                Pout << "\\end{table}" << endl;
                Pout.close();
	}		
	return 0;
}
