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
        double Y[numY+1];
        double flag2;
        for(int i=0; i<=numY; i++)
        {
		yconfig >> flag2;
                Y[i] = flag2;
        }
	//input table
	/*TFile *input = TFile::Open(argv[1]);
	TH2D *table = (TH2D*)input->Get(argv[2]);*/
	ofstream out(argv[7]);
	out.setf(ios::fixed, ios::floatfield);
        out.precision(3);
	out << "\\begin{table}[H]" << endl;
	out << "\\centering" << endl;
	out << "\\caption{The efficiency $\\epsilon_\\mathrm{";
	out << argv[5] << "}$ for " << argv[6] <<" signals in different (\\pt,$y$) bins.}" << endl;
	out << "\\begin{center}" << endl;
	out << "\\begin{tabular}{|c|ccccc|}" << endl;
	TFile *input;
	for(int i=1;i<=numN;i++)
	{
		input = TFile::Open(Form("../../Yield/%s/3_Result/%s/n%d_%s.root",argv[1],argv[2],i,argv[3]));
		TH2D *table = (TH2D*)input->Get(argv[4]);	
		out << "\\hline" << endl;
		out << Form("\\multicolumn{6}{|c|}{%d$\\leq$nBackTracks$<$%d}\\\\",N[i-1],N[i]) << endl;
		out << "\\hline" << endl;
		out << Form("\\pt(\\gevc)& %d-%d &  %d-%d & %d-%d & %d-%d & %d-%d  \\\\",Pt[0],Pt[1],Pt[1],Pt[2],Pt[2],Pt[3],Pt[3],Pt[4],Pt[4],Pt[5]) << endl;
		out << "\\hline" << endl;
		double con, err;
		for(int y=1;y<=numY; y++)
		{
			out << Form("$%.1f<y<%.1f$",Y[y-1],Y[y]);
			for(int pt=1;pt<=numPt;pt++)
			{
				con = table->GetBinContent(pt,y);
				err = table->GetBinError(pt,y);
				out << Form("&$%.3f\\pm%.3f$",con,err);
			}
			out << "\\\\" << endl;
		}
		out << "\\hline" << endl;
		//if(i==3) break;
	}
	out << "\\end{tabular}" << endl;
	out << "\\end{center}" << endl;
	out << "\\end{table}" << endl;
	return 0;
}
