#include <TFile.h>
#include <TRandom.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TString.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char** argv)
{
	TFile F(argv[1]);
	TH3F *Table = (TH3F*)F.Get(argv[2]);
	TFile *outF = new TFile(argv[4], "recreate");
	int N;
	sscanf(argv[3],"%d",&N);
	double c, cErr;
	TH3F *copyTable[N];
	for(int i=0;i<N;i++)
	{
		copyTable[i] = (TH3F*)Table->Clone(TString::Format("t%d", i));
		int Ncell = copyTable[i]->GetNcells();
		//cout << "total cells: " << Ncell << endl;
		for(int j=0;j<Ncell;j++)
		{
			c = Table->GetBinContent(j);
			cErr = Table->GetBinError(j);
			copyTable[i]->SetBinContent(j, gRandom->Gaus(c,cErr));
		}
		copyTable[i]->Write();
	}
	outF->Close();
	return 0;
}
