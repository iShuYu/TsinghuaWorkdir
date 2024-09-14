#include <math.h>
#include <fstream>
#include <iostream>
#include <TFile.h>
#include <TROOT.h>
#include <TAxis.h>
#include <fstream>
#include <TCanvas.h>
#include <TLegend.h>
#include <TStyle.h>
#include <TH1.h>
#include <TH2.h>
#include <TF1.h>
using namespace std;
int main()
{
	double sump=0;
	double sumb=0;
	double b, p;
	
	for(int n=1;n<=5;n++)
	{
		for(int y=1; y<=3; y++)
	{
			for(int pt=1;pt<=1;pt++)
			{
				ifstream Input(Form("./n%dy%dpt%d.txt",n,y,pt));
				Input >> p;
				//Input >> b;	//jump perr
				Input >> b;
				sump = sump+p;
				sumb = sumb+b;
			}
		}
	}
	cout << "sigma prompt: " << sump << "nb^-1" << endl;
        cout << "sigma fromb: " << sumb << "nb^-1" << endl;
	return 0;
} 
