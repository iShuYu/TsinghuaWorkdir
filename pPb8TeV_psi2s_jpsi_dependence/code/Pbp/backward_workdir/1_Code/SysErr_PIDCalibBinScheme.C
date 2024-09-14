#define MCDecayTree_Cut_cxx
#define mct_cxx
#include <TH1.h>
#include <TH2.h>
#include <TH3F.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <TAxis.h>
#include <TROOT.h>
#include <TRandom3.h>
#include "0_header/MCDecayTree_Cut.h"
#include "0_header/mct.h"
using namespace std;
double Max(double a, double b)
{
	a = abs(a);
	b = abs(b);
	if(a>b) return a;
	if(a<=b) return b;
}
int main(int argc, char *argv[])
{
	//input three different scheme
	int N;
	sscanf(argv[1], "%d", &N);
	TFile *input = TFile::Open(Form("../4_Result/Eff_RecselPIDTrigger/n%d/Eff_RecselPIDTrigger_PIDCalib0.root",N));
	TH2D *t0 = (TH2D*)input->Get("ratio_tot");
	input = TFile::Open(Form("../4_Result/Eff_RecselPIDTrigger/n%d/Eff_RecselPIDTrigger_PIDCalib1.root",N));
	TH2D *t1 = (TH2D*)input->Get("ratio_tot");
	input = TFile::Open(Form("../4_Result/Eff_RecselPIDTrigger/n%d/Eff_RecselPIDTrigger_PIDCalib2.root",N));
	TH2D *t2 = (TH2D*)input->Get("ratio_tot");
	double r0, r1, r2;
	r0 = t0->GetBinContent(1,1);
	r1 = t1->GetBinContent(1,1);
	r2 = t2->GetBinContent(1,1);
	ofstream out(Form("../4_Result/SysErr/PIDCalibBinScheme/n%d.txt",N));
	out << Max((r0-r1)/r0,(r0-r2)/r0) << endl;
	out.close();
        return 0;
}
