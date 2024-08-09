#include <TAxis.h>
#include <fstream>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include "../header/lhcbStyle.h"
using namespace std;
int main(int argc, char* argv[])
{
	double ybin, ptbin;
        int Nybin, Nptbin;
        ifstream yconfig(argv[4]);
        ifstream ptconfig(argv[5]);
        yconfig >> Nybin;
        ptconfig >> Nptbin;
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
	TH1::SetDefaultSumw2();
	TFile inputU(argv[1]);
	TFile inputD(argv[2]);
	TH2D *hU = (TH2D*)inputU.Get("h_3");
	TH2D *hD = (TH2D*)inputD.Get("h_3");
	TH2D *hCompare = new TH2D("hCompare", "Compare", Nptbin, pt, Nybin, y);
	hCompare -> Add(hU,hD,1.,-1.);
	hCompare -> Divide(hCompare,hU,1.,1.,"B");
	//plot
	hCompare ->SetTitle("Relative Error With different reweight");
	TCanvas *can = new TCanvas("can","can",800,600);
	hCompare -> SetStats(0);
	hCompare -> GetXaxis()->SetTitle("#font[12]{p}_{T}[MeV/#font[12]{c}]");
	hCompare -> GetYaxis()->SetTitle("y");
	hCompare -> Draw("colz text");
	can -> SaveAs(argv[3]);
	return 0;
}
