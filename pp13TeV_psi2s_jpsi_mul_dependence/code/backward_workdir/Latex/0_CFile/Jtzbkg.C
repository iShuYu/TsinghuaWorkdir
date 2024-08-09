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
	double Jtau1[5][3], Jtau2[5][3], Jtau3[5][3], Jtau4[5][3], Jf1[5][3], Jf2[5][3], Jf3[5][3], Jf4[5][3], Jbias[5][3], JSigma1[5][3], JSigma2[5][3], Jbeta[5][3];
	double Jtau1Err[5][3], Jtau2Err[5][3], Jtau3Err[5][3], Jtau4Err[5][3], Jf1Err[5][3], Jf2Err[5][3], Jf3Err[5][3], Jf4Err[5][3], JbiasErr[5][3], JSigma1Err[5][3], JSigma2Err[5][3], JbetaErr[5][3];
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
			ifstream F(Form("../../Yield/Jpsi/3_Result/TzbkgFit/Tzbkg_n%dy%dpt%d.txt",N,y+1,pt+1));
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
			Jbeta[pt][y] = a;
                       	JbetaErr[pt][y] = aE;
                        Jbias[pt][y] = b*1000;
                       	JbiasErr[pt][y] = bE*1000;
                       	Jf1[pt][y] = C;
                       	Jf1Err[pt][y] = cE;
                       	Jf2[pt][y] = d;
                       	Jf2Err[pt][y] = dE;
                       	Jf3[pt][y] = e;
                       	Jf3Err[pt][y] = eE;
                       	Jf4[pt][y] = f;
                       	Jf4Err[pt][y] = fE;
                       	JSigma1[pt][y] = g;
                       	JSigma1Err[pt][y] = gE;
                       	JSigma2[pt][y] = h;
                       	JSigma2Err[pt][y] = hE;
                       	Jtau1[pt][y] = i;
                       	Jtau1Err[pt][y] = iE;
                       	Jtau2[pt][y] = j;
                       	Jtau2Err[pt][y] = jE;
                       	Jtau3[pt][y] = k;
                       	Jtau3Err[pt][y] = kE;
                       	Jtau4[pt][y] = l;
                       	Jtau4Err[pt][y] = lE;
        	}
	}
	//output latex
	double ybin[4] = {2.0, 2.8, 3.5, 4.5};
        for(int y=0;y<3;y++)
        {
                ofstream Jout(Form("../2_Table/TzFitResult/Jn%dy%d.tex",N,y+1));
		Jout.setf(ios::fixed, ios::floatfield);
                Jout.precision(2);
		Jout << "\\begin{table}[H]" << endl;
                Jout << "\\begin{center}" << endl;
		Jout << Form("\\caption{The parameters of $t_z$ background fit for \\jpsi in the rapidity bin $%.1f<y<%.1f$ and multiplicity bin $%d<PVNTRACKS<%d$.}",ybin[y],ybin[y+1],PVN[N-1],PVN[N]) << endl;
		Jout << "\\resizebox{\\linewidth}{!}{" << endl;
                Jout << "\\begin{tabular}{c|ccccc}" << endl;
                Jout << "\\hline" << endl;
                Jout << "\\multirow{2}{*}{\\jpsi parameters} &  \\multicolumn{5}{|c}{\\pt(\\gevc)}  \\\\ \\cline{2-6}" << endl;
                Jout << "&  0-2 & 2-4  & 4-6   & 6-8   & 8-20   \\\\ \\hline" << endl;
		Jout << "$\\tau_1$";
		for(int c=0;c<5;c++)
		{
			if(Jf1[c][y]!=0) Jout << Form("& $%.2f\\pm%.2f$",Jtau1[c][y], Jtau1Err[c][y]);
			else Jout << "& -";
		}
		Jout << "\\\\" << endl;
		Jout << "$\\tau_2$";
                for(int c=0;c<5;c++)
                {
                        if(Jf2[c][y]!=0) Jout << Form("& $%.2f\\pm%.2f$",Jtau2[c][y], Jtau2Err[c][y]);
                        else Jout << "& -";
                }
		Jout << "\\\\" << endl;
		Jout << "$\\tau_3$";
                for(int c=0;c<5;c++)
                {   
                        if(Jf3[c][y]!=0) Jout << Form("& $%.2f\\pm%.2f$",Jtau3[c][y], Jtau3Err[c][y]);
                        else Jout << "& -";
                }
		Jout << "\\\\" << endl;
		Jout << "$\\tau_4$";
                for(int c=0;c<5;c++)
                {   
                        if(Jf4[c][y]!=0) Jout << Form("& $%.2f\\pm%.2f$",Jtau4[c][y], Jtau4Err[c][y]);
                        else Jout << "& -";
                }
		Jout << "\\\\" << endl;
		Jout << "$f_1$";
                for(int c=0;c<5;c++)
                {
                        if(Jf1[c][y]!=0) Jout << Form("& $%.3f\\pm%.3f$",Jf1[c][y], Jf1Err[c][y]);
                        else Jout << "& 0";
                }
                Jout << "\\\\" << endl;
                Jout << "$f_2$";
                for(int c=0;c<5;c++)
                {
                        if(Jf2[c][y]!=0) Jout << Form("& $%.3f\\pm%.3f$",Jf2[c][y], Jf2Err[c][y]);
                        else Jout << "& 0";
                }
                Jout << "\\\\" << endl;
                Jout << "$f_3$";
                for(int c=0;c<5;c++)
                {
                        if(Jf3[c][y]!=0) Jout << Form("& $%.3f\\pm%.3f$",Jf3[c][y], Jf3Err[c][y]);
                        else Jout << "& 0";
                }
                Jout << "\\\\" << endl;
                Jout << "$f_4$";
                for(int c=0;c<5;c++)
                {
                        if(Jf4[c][y]!=0) Jout << Form("& $%.3f\\pm%.3f$",Jf4[c][y], Jf4Err[c][y]);
                        else Jout << "& 0";
                }
                Jout << "\\\\" << endl;
		Jout << "$1000*\\mu_{tzbkg}$";
		for(int c=0;c<5;c++) Jout << Form("& $%.1f\\pm%.1f$",Jbias[c][y], JbiasErr[c][y]);
		Jout << "\\\\" << endl;
		Jout << "$\\beta_{tzbkg}$";
                for(int c=0;c<5;c++)
                {
                        if(Jbeta[c][y]!=0) Jout << Form("& $%.2f\\pm%.2f$",Jbeta[c][y], JbetaErr[c][y]);
                        else Jout << "& 0";
                }
		Jout << "\\\\" << endl;
		Jout << "$S1_{tzbkg}$";
                for(int c=0;c<5;c++)
                {
                        if(Jbeta[c][y]!=0) Jout << Form("& $%.2f\\pm%.2f$",JSigma1[c][y], JSigma1Err[c][y]);
                        else Jout << "& -";
                }
		Jout << "\\\\" << endl;
		Jout << "$S2_{tzbkg}$";
		for(int c=0;c<5;c++) Jout << Form("& $%.2f\\pm%.2f$",JSigma2[c][y], JSigma2Err[c][y]);
		Jout << "\\\\" << endl;
		Jout << "\\hline" << endl;
                Jout << "\\end{tabular}" << endl;
                Jout << "}" << endl;
                Jout << "\\end{center}" << endl;
                Jout << "\\end{table}" << endl;
                Jout.close();
	}		
	return 0;
}
