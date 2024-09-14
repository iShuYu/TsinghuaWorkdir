#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
	double lumi = 657.6611390205;
	double lumiErr = lumi*0.02;
	//input binning scheme
	int Nnbin, Nybin, Nptbin;
	ifstream nconfig(argv[1]);
	ifstream yconfig(argv[2]);
        ifstream ptconfig(argv[3]);
	nconfig >> Nnbin;
        yconfig >> Nybin;
        ptconfig >> Nptbin;
        double ybin, ptbin;
	double y[Nybin+1], pt[Nptbin+1];
        for(int i=0; i<=Nybin; i++)
        {
                yconfig >> ybin;
                y[i]=ybin;
        }
        for(int i=0; i<=Nptbin; i++)
        {
                ptconfig >> ptbin;
                pt[i]=ptbin;
        }
	TH2D *thp[Nnbin];
	TH2D *thb[Nnbin];
	for(int i=0;i<Nnbin;i++)
	{
		thp[i] = new TH2D(Form("thp%d",i),"",Nptbin,pt,Nybin,y);
		thb[i] = new TH2D(Form("thb%d",i),"",Nptbin,pt,Nybin,y);
		for(int j=0;j<Nybin;j++)
		{
			for(int k=0;k<Nptbin;k++)
			{
				ifstream R(Form("../../3_Result/2DFit/txt_n%dy%dpt%d.txt",i+1,j+1,k+1));
				double element;
				for(int l=0;l<10;l++)
				{
					R>>element;
					//cout << element;
				}
				R>>element;
				thp[i]->SetBinContent(k+1,j+1,element/lumi);
				R>>element;
				thp[i]->SetBinError(k+1,j+1,element/lumi);
				R>>element;
                                thb[i]->SetBinContent(k+1,j+1,element/lumi);
                                R>>element;
                                thb[i]->SetBinError(k+1,j+1,element/lumi);

			}
		}
		//output
		TFile *F = new TFile(Form("../../3_Result/Conclude/2DFit_Yields_n%d.root",i+1),"recreate");
		thp[i]->Write();
		thb[i]->Write();
		F->Close();
	}
	return 0;
}
