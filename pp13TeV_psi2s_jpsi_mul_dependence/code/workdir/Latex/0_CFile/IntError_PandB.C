#include <iomanip>
#include <TString.h>
#include <iostream>
#include <fstream>
#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>
using namespace std;
int main(int argc, char* argv[])
{
	int PVN[6] = {0,20,40,60,80,200};
	int Z;
	sscanf(argv[12],"%d",&Z);
	TFile *input;
	input = TFile::Open(argv[1]);
	TH1D *Py = (TH1D*)input->Get(argv[2]);
	input = TFile::Open(argv[3]);
	TH1D *Ppt = (TH1D*)input->Get(argv[4]);
	input = TFile::Open(argv[5]);
        TH1D *By = (TH1D*)input->Get(argv[6]);
        input = TFile::Open(argv[7]);
        TH1D *Bpt = (TH1D*)input->Get(argv[8]);
	TString A(argv[9]);
	TString B(argv[10]);
	ifstream Ptot(argv[9]);
	ifstream Btot(argv[10]);
	double y[2][3], pt[2][5], tot[2];
	for(int i=1;i<=3;i++)
	{
		y[0][i-1]=Py->GetBinContent(i)*100;
		y[1][i-1]=By->GetBinContent(i)*100; 
	}
	for(int i=1;i<=5;i++)
        {
                pt[0][i-1]=Ppt->GetBinContent(i)*100;
                pt[1][i-1]=Bpt->GetBinContent(i)*100;
        }
	if(A==B)
	{
		Ptot >> tot[0];
		Ptot >> tot[1];
	}
	else
	{
		Ptot >> tot[0];
		Btot >> tot[1];
	}
	//output latex table
	ofstream out(argv[11]);
	out.setf(ios::fixed, ios::floatfield);
	out.precision(2);
	out << "\\begin{table}[H]" << endl;
	out << "    \\centering" << endl;
	//out << "    \\captionsetup{labelformat=empty}" << endl;
	out << "    \\caption{Summary of systematic relative uncertainties of ratio of integrated production due to the uncertainty of ";
	out << argv[13] << Form(" for PVNTRACKS from %d to %d.}", PVN[Z-1],PVN[Z] )<< endl;
	out << "\\begin{center}" << endl;
	out << "    \\begin{tabular}{ c | c | c }" << endl;
	out << "        \\hline" << endl;
        out << "        Region & prompt (\\%) & from $b$ (\\%)\\\\" << endl;
        out << "        \\hline" << endl;
	out << "        2.0$<$y$<$2.8" << "&" << y[0][0] << "&" << y[1][0] << "\\\\" << endl;
	out << "        2.8$<$y$<$3.5" << "&" << y[0][1] << "&" << y[1][1] << "\\\\" << endl;
	out << "        3.5$<$y$<$4.5" << "&" << y[0][2] << "&" << y[1][2] << "\\\\" << endl;
        out << "        \\hline" << endl;
	out << "        0\\gevc $<$\\pt$<$2\\gevc" << "&" << pt[0][0] << "&" << pt[1][0] << "\\\\" << endl;
	out << "        2\\gevc $<$\\pt$<$4\\gevc" << "&" << pt[0][1] << "&" << pt[1][1] << "\\\\" << endl;
	out << "        4\\gevc $<$\\pt$<$6\\gevc" << "&" << pt[0][2] << "&" << pt[1][2] << "\\\\" << endl;
	out << "        6\\gevc $<$\\pt$<$8\\gevc" << "&" << pt[0][3] << "&" << pt[1][3] << "\\\\" << endl;
	out << "        8\\gevc $<$\\pt$<$20\\gevc" << "&" << pt[0][4] << "&" << pt[1][4] << "\\\\" << endl;
        out << "        \\hline" << endl;
        out << "        all \\pt-y region&" << 100*tot[0] << "&" << 100*tot[1] << "\\\\" << endl;
        out << "        \\hline" << endl;
        out << "    \\end{tabular}" << endl;
        out << "\\end{center}" << endl;
        out << "\\label{input label here}" << endl;
        out << "\\end{table}" << endl;
	out.close();
	return 0;
}
