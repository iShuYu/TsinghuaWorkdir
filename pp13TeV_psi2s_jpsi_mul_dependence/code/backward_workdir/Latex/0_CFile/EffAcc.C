#include <TString.h>
#include <iostream>
#include <fstream>
#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>
using namespace std;
int main(int argc, char* argv[])
{
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
        int Y[numY+1];
        int flag2;
        for(int i=0; i<=numY; i++)
        {
		yconfig >> flag2;
                Y[i] = flag2;
        }
	//input table
	TFile *input = TFile::Open(argv[1]);
	TH2D *table = (TH2D*)input->Get(argv[2]);
	ofstream out(argv[3]);
	out.setf(ios::fixed, ios::floatfield);
        out.precision(3);
	out << "\\begin{table}[H]" << endl;
	out << "\\centering" << endl;
	//out << "\\begin{center}" << endl;
	out << "\\caption{The efficiency $\\epsilon_\\mathrm{";
	out << argv[4] << "}$ in different bins of \\pt and $y$ for ";
	out << argv[5] << " mesons for PVZ > -30mm.}" << endl;
	out << "\\begin{center}" << endl;
	out << "\\begin{tabular}{c|ccc}" << endl;
	out << "\\hline" << endl;
	out << "\\pt(\\gevc)& $2<y<2.8$& $2.8<y<3.5$& $3.5<y<4.5$ \\\\" << endl;
	out << "\\hline" << endl;
	double con, err;
	for(int pt=1;pt<=numPt; pt++)
	{
		out << Form("%d-%d",Pt[pt-1],Pt[pt]);
		for(int y=1;y<=numY;y++)
		{
			con = table->GetBinContent(pt,y);
			err = table->GetBinError(pt,y);
			out << Form("&$%.3f\\pm%.3f$",con,err);
		}
		out << "\\\\" << endl;
	}
	out << "\\hline" << endl;
	out << "\\end{tabular}" << endl;
	out << "\\end{center}" << endl;
	out << "\\end{table}" << endl;
	return 0;
}
