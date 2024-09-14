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
	double Jbias[5][3], JbiasErr[5][3], JSigma1[5][3], JSigma1Err[5][3], JSigma2[5][3], JSigma2Err[5][3], Jbeta[5][3], JbetaErr[5][3], Jtau[5][3], JtauErr[5][3], JNp[5][3], JNpErr[5][3], JNb[5][3], JNbErr[5][3], JNt[5][3], JNtErr[5][3], JNbkg[5][3], JNbkgErr[5][3];
	double Pbias[5][3], PbiasErr[5][3], PSigma1[5][3], PSigma1Err[5][3], PSigma2[5][3], PSigma2Err[5][3], Pbeta[5][3], PbetaErr[5][3], Ptau[5][3], PtauErr[5][3], PNp[5][3], PNpErr[5][3], PNb[5][3], PNbErr[5][3], PNt[5][3], PNtErr[5][3], PNbkg[5][3], PNbkgErr[5][3];
	double Jm[5][3], Pm[5][3], Jsig[5][3], Psig[5][3], JNsig[5][3], PNsig[5][3];
	double JmErr[5][3], PmErr[5][3], JsigErr[5][3], PsigErr[5][3], JNsigErr[5][3], PNsigErr[5][3], Jp0[5][3], Jp0Err[5][3], Pp0[5][3], Pp0Err[5][3];
	double fill;
	for(int pt=0;pt<5;pt++)
	{
		for(int y=0;y<5;y++)
		{
			//from 2dtz
			ifstream Jconfig(Form("../../Yield/Jpsi/3_Result/2DFit/txt_n%dy%dpt%d.txt",N,y+1,pt+1));
			ifstream Pconfig(Form("../../Yield/Psi2S/3_Result/2DFit/txt_n%dy%dpt%d.txt",N,y+1,pt+1));
			Jconfig >> Jbias[pt][y] >> JbiasErr[pt][y] >> JSigma1[pt][y] >> JSigma1Err[pt][y]  >> JSigma2[pt][y] >> JSigma2Err[pt][y] >> Jbeta[pt][y] >> JbetaErr[pt][y] >> Jtau[pt][y] >> JtauErr[pt][y] >> JNp[pt][y] >> JNpErr[pt][y] >> JNb[pt][y] >> JNbErr[pt][y] >> JNt[pt][y] >> JNtErr[pt][y] >> JNbkg[pt][y] >> JNbkgErr[pt][y];
			Pconfig >> Pbias[pt][y] >> PbiasErr[pt][y] >> PSigma1[pt][y] >> PSigma1Err[pt][y]  >> PSigma2[pt][y] >> PSigma2Err[pt][y] >> Pbeta[pt][y] >> PbetaErr[pt][y] >> Ptau[pt][y] >> PtauErr[pt][y] >> PNp[pt][y] >> PNpErr[pt][y] >> PNb[pt][y] >> PNbErr[pt][y] >> PNt[pt][y] >> PNtErr[pt][y] >> PNbkg[pt][y] >> PNbkgErr[pt][y];
			//from mass
			ifstream Jmass(Form("../../Yield/Jpsi/3_Result/CBFit/MFit_to_2DFit/n%dy%dpt%d.txt",N,y+1,pt+1));
			ifstream Pmass(Form("../../Yield/Psi2S/3_Result/CBFit/MFit_to_2DFit/n%dy%dpt%d.txt",N,y+1,pt+1));
			Jmass >> Jm[pt][y] >> Jsig[pt][y] >> fill >> fill >> Jp0[pt][y] >> fill >> fill >> JmErr[pt][y] >> JsigErr[pt][y] >> Jp0Err[pt][y] >> JNsig[pt][y] >> JNsigErr[pt][y] >> JNbkg[pt][y] >> JNbkgErr[pt][y];
			Pmass >> Pm[pt][y] >> Psig[pt][y] >> fill >> fill >> Pp0[pt][y] >> fill >> fill >> PmErr[pt][y] >> PsigErr[pt][y] >> Pp0Err[pt][y] >> PNsig[pt][y] >> PNsigErr[pt][y] >> PNbkg[pt][y] >> PNbkgErr[pt][y];
		}
	}
	//output table
	double ybin[4] = {2.0, 2.8, 3.5, 4.5};
	for(int y=0;y<3;y++)
	{
		ofstream Jout(Form("../2_Table/2DFitResult/Jn%dy%d.tex",N,y+1));
		Jout.setf(ios::fixed, ios::floatfield);
        	Jout.precision(2);
		Jout << "\\begin{table}[H]" << endl;
		Jout << "\\begin{center}" << endl;
		Jout << Form("\\caption{The parameters of the invariant mass and $t_z$ fit for \\jpsi, including the fitted yields and the shape parameters for different $\\pt$ bins in the rapidity bin $%.1f<y<%.1f$ and multiplicity bin $%d<PVNTRACKS<%d$.}",ybin[y],ybin[y+1],PVN[N-1],PVN[N]) << endl;
		Jout << "\\resizebox{\\linewidth}{!}{" << endl;
		Jout << "\\begin{tabular}{c|ccccc}" << endl;
		Jout << "\\hline" << endl;
		Jout << "\\multirow{2}{*}{\\jpsi parameters} &  \\multicolumn{5}{|c}{\\pt(\\gevc)}  \\\\ \\cline{2-6}" << endl;
		Jout << "&  0-2 & 2-4  & 4-6   & 6-8   & 8-20   \\\\ \\hline" << endl;
		Jout << Form("$\\mu_{mass}$  & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ \\\\ ", Jm[0][y],JmErr[0][y], Jm[1][y],JmErr[1][y], Jm[2][y],JmErr[2][y], Jm[3][y],JmErr[3][y], Jm[4][y],JmErr[4][y]) << endl;
		Jout << Form("$\\sigma_{mass}$  & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ \\\\ ",  Jsig[0][y],JsigErr[0][y], Jsig[1][y],JsigErr[1][y], Jsig[2][y],JsigErr[2][y], Jsig[3][y],JsigErr[3][y], Jsig[4][y],JsigErr[4][y]) << endl;
		Jout << Form("$n_{sig}$  & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ \\\\", JNsig[0][y],JNsigErr[0][y], JNsig[1][y],JNsigErr[1][y], JNsig[2][y],JNsigErr[2][y], JNsig[3][y],JNsigErr[3][y], JNsig[4][y],JNsigErr[4][y]) << endl;
		Jout << Form("$n_{bkg}$  & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ \\\\", JNbkg[0][y],JNbkgErr[0][y], JNbkg[1][y],JNbkgErr[1][y], JNbkg[2][y],JNbkgErr[2][y], JNbkg[3][y],JNbkgErr[3][y], JNbkg[4][y],JNbkgErr[4][y]) << endl;
		Jout << Form("1000*$p_{0}$   & $%.2f\\pm%.2f$  & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ \\\\", 1000*Jp0[0][y], 1000*Jp0Err[0][y], 1000*Jp0[1][y], 1000*Jp0Err[1][y],Jp0[2][y], 1000*Jp0Err[2][y],1000*Jp0[3][y], 1000*Jp0Err[3][y],1000*Jp0[4][y], 1000*Jp0Err[4][y]) << endl;
		Jout << Form("$1000*\\mu_{tz}$  & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ \\\\", 1000*Jbias[0][y], 1000*JbiasErr[0][y], 1000*Jbias[1][y], 1000*JbiasErr[1][y], 1000*Jbias[2][y], 1000*JbiasErr[2][y], 1000*Jbias[3][y], 1000*JbiasErr[3][y], 1000*Jbias[4][y], 1000*JbiasErr[4][y]) << endl;
		//S1 拆开输出
		Jout << "$S1_{tz}$" ;
		for(int c=0; c<5;c++)
		{
			if(Jbeta[c][y]!=0) Jout << Form("& $%.2f\\pm%.2f$",JSigma1[c][y], JSigma1Err[c][y]);
			else Jout << "& -";
		}
		Jout << "\\\\" << endl;
		//
		Jout << Form("$S2_{tz}$  & $%.2f\\pm%.2f$  & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ \\\\", JSigma2[0][y], JSigma2Err[0][y], JSigma2[1][y], JSigma2Err[1][y], JSigma2[2][y], JSigma2Err[2][y], JSigma2[3][y], JSigma2Err[3][y], JSigma2[4][y], JSigma2Err[4][y]) << endl;
		//beta分情况输出
		Jout << "$\\beta_{tz}$"; 
		for(int c=0; c<5;c++)
                {   
                        if(Jbeta[c][y]!=0) Jout << Form("& $%.2f\\pm%.2f$",Jbeta[c][y], JbetaErr[c][y]);
                        else Jout << "& 0";
                }   
		Jout << "\\\\" << endl;
		Jout << Form("$\\tau_{b}$ & $%.2f\\pm%.2f$  & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ \\\\",  Jtau[0][y], JtauErr[0][y], Jtau[1][y], JtauErr[1][y] , Jtau[2][y], JtauErr[2][y] , Jtau[3][y], JtauErr[3][y] , Jtau[4][y], JtauErr[4][y]) << endl;
		Jout << Form("$n_{prompt}$  & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ \\\\", JNp[0][y],JNpErr[0][y], JNp[1][y],JNpErr[1][y], JNp[2][y],JNpErr[2][y], JNp[3][y],JNpErr[3][y], JNp[4][y],JNpErr[4][y]) << endl;
		Jout << Form("$n_{fromb}$  & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ \\\\", JNb[0][y],JNbErr[0][y], JNb[1][y],JNbErr[1][y], JNb[2][y],JNbErr[2][y], JNb[3][y],JNbErr[3][y], JNb[4][y],JNbErr[4][y]) << endl;
		Jout << Form("$n_{tail}$  & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ \\\\", JNt[0][y],JNtErr[0][y], JNt[1][y],JNtErr[1][y], JNt[2][y],JNtErr[2][y], JNt[3][y],JNtErr[3][y], JNt[4][y],JNtErr[4][y]) << endl;
		Jout << "\\hline" << endl;
		Jout << "\\end{tabular}" << endl;
		Jout << "}" << endl;
		Jout << "\\end{center}" << endl;
		Jout << "\\end{table}" << endl;
		Jout.close();
		ofstream Pout(Form("../2_Table/2DFitResult/Pn%dy%d.tex",N,y+1));
                Pout.setf(ios::fixed, ios::floatfield);
                Pout.precision(2);
                Pout << "\\begin{table}[H]" << endl;
                Pout << "\\begin{center}" << endl;
                Pout << Form("\\caption{The parameters of the invariant mass and $t_z$ fit for \\psitwos, including the fitted yields and the shape parameters for different $\\pt$ bins in the rapidity bin $%.1f<y<%.1f$ and multiplicity bin $%d<PVNTRACKS<%d$.}",ybin[y],ybin[y+1],PVN[N-1],PVN[N]) << endl;
                Pout << "\\resizebox{\\linewidth}{!}{" << endl;
                Pout << "\\begin{tabular}{c|ccccc}" << endl;
                Pout << "\\hline" << endl;
                Pout << "\\multirow{2}{*}{\\psitwos parameters} &  \\multicolumn{5}{|c}{\\pt(\\gevc)}  \\\\ \\cline{2-6}" << endl;
                Pout << "&  0-2 & 2-4  & 4-6   & 6-8   & 8-20   \\\\ \\hline" << endl;
                Pout << Form("$\\mu_{mass}$  & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ \\\\ ", Pm[0][y],PmErr[0][y], Pm[1][y],PmErr[1][y], Pm[2][y],PmErr[2][y], Pm[3][y],PmErr[3][y], Pm[4][y],PmErr[4][y]) << endl;
                Pout << Form("$\\sigma_{mass}$  & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ \\\\ ",  Psig[0][y],PsigErr[0][y], Psig[1][y],PsigErr[1][y], Psig[2][y],PsigErr[2][y], Psig[3][y],PsigErr[3][y], Psig[4][y],PsigErr[4][y]) << endl;
                Pout << Form("$n_{sig}$  & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ \\\\", PNsig[0][y],PNsigErr[0][y], PNsig[1][y],PNsigErr[1][y], PNsig[2][y],PNsigErr[2][y], PNsig[3][y],PNsigErr[3][y], PNsig[4][y],PNsigErr[4][y]) << endl;
                Pout << Form("$n_{bkg}$  & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ \\\\", PNbkg[0][y],PNbkgErr[0][y], PNbkg[1][y],PNbkgErr[1][y], PNbkg[2][y],PNbkgErr[2][y], PNbkg[3][y],PNbkgErr[3][y], PNbkg[4][y],PNbkgErr[4][y]) << endl;
                Pout << Form("1000*$p_{0}$   & $%.2f\\pm%.2f$  & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ \\\\", 1000*Pp0[0][y], 1000*Pp0Err[0][y], 1000*Pp0[1][y], 1000*Pp0Err[1][y],Pp0[2][y], 1000*Pp0Err[2][y],1000*Pp0[3][y], 1000*Pp0Err[3][y],1000*Pp0[4][y], 1000*Pp0Err[4][y]) << endl;
                Pout << Form("$1000*\\mu_{tz}$  & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ & $%.1f\\pm%.1f$ \\\\", 1000*Pbias[0][y], 1000*PbiasErr[0][y], 1000*Pbias[1][y], 1000*PbiasErr[1][y], 1000*Pbias[2][y], 1000*PbiasErr[2][y], 1000*Pbias[3][y], 1000*PbiasErr[3][y], 1000*Pbias[4][y], 1000*PbiasErr[4][y]) << endl;
                Pout << "$S1_{tz}$" ;
                for(int c=0; c<5;c++)
                {
                        if(Pbeta[c][y]!=0) Pout << Form("& $%.2f\\pm%.2f$",PSigma1[c][y], PSigma1Err[c][y]);
                        else Pout << "& -";
                }
                Pout << "\\\\" << endl;
                Pout << Form("$S2_{tz}$  & $%.2f\\pm%.2f$  & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ \\\\", PSigma2[0][y], PSigma2Err[0][y], PSigma2[1][y], PSigma2Err[1][y], PSigma2[2][y], PSigma2Err[2][y], PSigma2[3][y], PSigma2Err[3][y], PSigma2[4][y], PSigma2Err[4][y]) << endl;         
                Pout << "$\\beta_{tz}$";
		for(int c=0; c<5;c++)
                {
                        if(Pbeta[c][y]!=0) Pout << Form("& $%.2f\\pm%.2f$",Pbeta[c][y], PbetaErr[c][y]);
                        else Pout << "& 0";
                }
                Pout << "\\\\" << endl;
                Pout << Form("$\\tau_{b}$ & $%.2f\\pm%.2f$  & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ & $%.2f\\pm%.2f$ \\\\",  Ptau[0][y], PtauErr[0][y], Ptau[1][y], PtauErr[1][y] , Ptau[2][y], PtauErr[2][y] , Ptau[3][y], PtauErr[3][y] , Ptau[4][y], PtauErr[4][y]) << endl;
                Pout << Form("$n_{prompt}$  & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ \\\\", PNp[0][y],PNpErr[0][y], PNp[1][y],PNpErr[1][y], PNp[2][y],PNpErr[2][y], PNp[3][y],PNpErr[3][y], PNp[4][y],PNpErr[4][y]) << endl;
                Pout << Form("$n_{fromb}$  & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ \\\\", PNb[0][y],PNbErr[0][y], PNb[1][y],PNbErr[1][y], PNb[2][y],PNbErr[2][y], PNb[3][y],PNbErr[3][y], PNb[4][y],PNbErr[4][y]) << endl;
                Pout << Form("$n_{tail}$  & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ & $%.0f\\pm%.0f$ \\\\", PNt[0][y],PNtErr[0][y], PNt[1][y],PNtErr[1][y], PNt[2][y],PNtErr[2][y], PNt[3][y],PNtErr[3][y], PNt[4][y],PNtErr[4][y]) << endl;
                Pout << "\\hline" << endl;
                Pout << "\\end{tabular}" << endl;
                Pout << "}" << endl;
                Pout << "\\end{center}" << endl;
                Pout << "\\end{table}" << endl;
		Pout.close();
	}
	return 0;
}
