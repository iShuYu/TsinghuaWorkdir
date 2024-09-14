#include <TString.h>
#include <TFile.h>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int N;
	ofstream out("../2_Table/Xbin/Xbin.tex");
	out << "\\begin{table}[H]" << endl;
	out << "\\begin{center}" << endl;
	out << "\\caption{The horizontal coordinates for different binning schemes.}" << endl;
	out << "\\begin{tabular}{|c|ccccc|}" << endl;
	out << "\\hline" << endl;
	out << "PVNTRACKS &  4-20 & 20-45  & 45-70   & 70-95   & 100-200   \\\\ \\hline" << endl;
	out << "prompt & ";
	ifstream Lp("../../Yield/result/3_Result/promptBin.txt");
	Lp >> N;
	for(int i=1;i<=N;i++)
	{
		double x;
		Lp >> x;
		if(i==N)
		{
			out << Form("%.4f \\\\",x) << endl;
			out << "\\hline" << endl;
		}
		else out << Form("%.4f & ",x);
	}
	Lp.close();
	out << "from $b$ & ";
	ifstream Lb("../../Yield/result/3_Result/frombBin.txt");
	Lb >> N;
	for(int i=1;i<=N;i++)
        {
                double x;
                Lb >> x;
                if(i==N)
		{
			out << Form("%.4f \\\\",x) << endl;
                	out << "\\hline" << endl;
		}
		else out << Form("%.4f & ",x);
        }
	Lb.close();
        out << " nForwardTracks &  0-12 & 12-24  & 24-36   & 36-48   & 48-130  \\\\ \\hline" << endl;
        out << "prompt & ";
	ifstream Fp("/nishome/kangye/disk402_ppAnalysis/ForWorkdir/Yield/result/3_Result/promptBin.txt");
	Fp >> N;
	for(int i=1;i<=N;i++)
        {
                double x;
                Fp >> x;
                if(i==N)
                {
                        out << Form("%.4f \\\\",x) << endl;
                        out << "\\hline" << endl;
                }
                else out << Form("%.4f & ",x);
        }
	Fp.close();
        out << "from $b$ & ";
        ifstream Fb("/nishome/kangye/disk402_ppAnalysis/ForWorkdir/Yield/result/3_Result/frombBin.txt");
	Fb >> N;
	for(int i=1;i<=N;i++)
        {
                double x;
                Fb >> x;
                if(i==N)
                {
                        out << Form("%.4f \\\\",x) << endl;
                        out << "\\hline" << endl;
                }
                else out << Form("%.4f & ",x);
        }
	Fb.close();
        out << "nBackTracks &  0-8 & 8-15  & 15-22   & 22-30   & 30-80  \\\\ \\hline" << endl;
        out << "prompt & ";
        ifstream Bp("/nishome/kangye/disk402_ppAnalysis/BackWorkdir/Yield/result/3_Result/promptBin.txt");
	Bp >> N;
	for(int i=1;i<=N;i++)
        {
                double x;
                Bp >> x;
                if(i==N)
                {
                        out << Form("%.4f \\\\",x) << endl;
                        out << "\\hline" << endl;
                }
                else out << Form("%.4f & ",x);
        }
        Bp.close();
	out << "from $b$ & ";
	ifstream Bb("/nishome/kangye/disk402_ppAnalysis/BackWorkdir/Yield/result/3_Result/frombBin.txt");
	Bb >> N;
        for(int i=1;i<=N;i++)
        {
                double x;
                Bb >> x;
                if(i==N)
                {
                        out << Form("%.4f \\\\",x) << endl;
                        out << "\\hline" << endl;
                }
                else out << Form("%.4f & ",x);
        }
	Bb.close();
	out << "\\end{tabular}" << endl;
        out << "\\end{center}" << endl;
        out << "\\label{XCoordinates}" << endl;
	out << "\\end{table}" << endl;
        out.close();
	return 0;
}

