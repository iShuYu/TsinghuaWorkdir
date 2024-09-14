#include <TString.h>
#include <iostream>
#include <fstream>
#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>
using namespace std;
int main(int argc, char* argv[])
{
	int n, y, pt;
	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%d", &y);
	sscanf(argv[3], "%d", &pt);
	ifstream nconfig("../../Yield/rawdata/3_Bins/nbin");
	int numN;
	nconfig >> numN;
	int N[numN+1];
	int flag;
	for(int i=0; i<=numN; i++)
        {
                nconfig >> flag;
                N[i] = flag;
        }
	ifstream ptconfig("../../Yield/rawdata/3_Bins/ptbin");
        int numPt;
        ptconfig >> numPt;
        int Pt[numPt+1];
        int flag1;
        for(int i=0; i<=numPt; i++)
        {
                ptconfig >> flag1;
                Pt[i] = flag1/1000;
        }
	ifstream yconfig("../../Yield/rawdata/3_Bins/ybin");
        int numY;
        yconfig >> numY;
        double Y[numY+1];
        double flag2;
        for(int i=0; i<=numY; i++)
        {
		yconfig >> flag2;
                Y[i] = flag2;
        }
	ofstream out(Form("../2_Table/FitPlots/n%dy%dpt%dF.tex",n,y,pt));
	out << "\\begin{figure}[H]" << endl;
	out << "\\begin{center}" << endl;
	out << Form("\\includegraphics[width=0.47\\linewidth]{pdf/Jpsi/drawmassF/n%dy%dpt%d.pdf}",n,y,pt) << endl;
	out << Form("\\includegraphics[width=0.47\\linewidth]{pdf/Jpsi/2DFitF/n%dy%dpt%d.pdf}",n,y,pt) << endl;
	out << "\\vspace*{-0.5cm}" << endl;
	out << Form("\\includegraphics[width=0.47\\linewidth]{pdf/Psi2S/drawmassF/n%dy%dpt%d.pdf}",n,y,pt) << endl;
        out << Form("\\includegraphics[width=0.47\\linewidth]{pdf/Psi2S/2DFitF/n%dy%dpt%d.pdf}",n,y,pt) << endl;
        out << "\\vspace*{-0.5cm}" << endl;
	out << "\\end{center}" << endl;
	out << Form("\\caption{Fit results in $%d\\gevc<\\pt<%d\\gevc$, $%.1f<y<%.1f$ and %d$\\leq$nForwardTracks$<$%d.}",Pt[pt-1],Pt[pt],Y[y-1],Y[y],N[n-1],N[n]) << endl;
	out << Form("\\label{Fitn%dy%dpt%d}",n,y,pt) << endl;
	out << "\\end{figure}" << endl;
	return 0;
}
