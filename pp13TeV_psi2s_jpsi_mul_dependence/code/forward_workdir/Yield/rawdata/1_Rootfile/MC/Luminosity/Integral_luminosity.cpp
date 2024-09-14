#define LumiTuple_cxx
#include "LumiTuple.h"
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char* argv[])
{
	TChain *Lumi = new TChain("GetIntegratedLuminosity/LumiTuple");
	for (int i = 0; i <= 10; i++)
		Lumi -> Add(Form("../MagUp/Jpsi/%d/output/Tuple.root",i));
	
	LumiTuple a(Lumi);	
	double tot_lumi = 0;
	double lumi_err = 0;
	long Num_entries = Lumi->GetEntries();
	for(long i_entry; i_entry <= Num_entries; i_entry++)
	{
		Lumi->GetEntry(i_entry);
		tot_lumi = tot_lumi + a.IntegratedLuminosity;
		lumi_err = lumi_err + a.IntegratedLuminosityErr;
	}
	ofstream result("./lumi.txt");
	result << "total Luminosity = " << tot_lumi << endl;
	result << "total Luminosity error = " << lumi_err << endl;
	result.close();
}


