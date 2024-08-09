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
        TH1::SetDefaultSumw2();
	double ybin, ptbin;
        int Nybin, Nptbin;
	ifstream yconfig(argv[7]);
        ifstream ptconfig(argv[8]);
        yconfig >> Nybin;
        ptconfig >> Nptbin;
        double color[Nybin], marker[Nybin];
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
        for(int i=0; i<Nybin; i++)
        {
                color[i] = i+1;
                marker[i] = 20+i*2;
        }
        gROOT->SetBatch(true);
        setLHCbStyle();
	TFile Acc(argv[1]);
	TFile Rec(argv[2]);
	TFile Pid(argv[3]);
	TFile Tri(argv[4]);
	TH2D *acc = (TH2D*)Acc.Get("h_eff");
	TH2D *rec = (TH2D*)Rec.Get("h_eff");
	TH2D *pid = (TH2D*)Pid.Get("h_eff");
	TH2D *tri = (TH2D*)Tri.Get("h_eff");
	TH2D *h_1 = new TH2D("h_1", "acc*rec", Nptbin, pt, Nybin, y);
	TH2D *h_2 = new TH2D("h_2", "pid*tri", Nptbin, pt, Nybin, y);
	TH2D *h_3 = new TH2D("h_3", "acc*rec*pid*tri", Nptbin, pt, Nybin, y);
	h_1 -> Multiply(acc,rec,1.,1.);
	h_2 -> Multiply(pid,tri,1.,1.);
	h_3 -> Multiply(h_1,h_2,1.,1.);
	TFile *f = new TFile(argv[5],"recreate");
	h_3 -> Write();
	f -> Close();
	TCanvas *can = new TCanvas("can","can",800,600);
	h_3 -> SetStats(0);
	h_3 -> GetXaxis()->SetTitle("#font[12]{p}_{T}[GeV/#font[12]{c}]");
	h_3 -> GetYaxis()->SetTitle("#font[12]{y}");
	h_3 ->Draw("colz text e");
	can -> SaveAs(argv[6]);
	TCanvas *can1 = new TCanvas("can1","can1",800,600);
	TH1D* line[Nybin];
	double maxRERR = 0;
        double minRERR = 1;
	for (int i=0; i<Nybin; i++)
        {
                line[i] = new TH1D(Form("line%d",i), "", Nptbin, pt);
                line[i]->GetXaxis()->SetTitle("#font[12]{p}_{T}[MeV/#font[12]{c}]");
                line[i]->GetYaxis()->SetTitle(argv[10]);
                line[i]->GetYaxis()->SetRangeUser(0.,0.7);
                line[i]->SetLineColor(color[i]);
                line[i]->SetMarkerColor(color[i]);
                line[i]->SetMarkerStyle(marker[i]);
                for (int j=0; j<Nptbin; j++)
                {
                        line[i]->SetBinContent(j+1, h_3->GetBinContent(j+1,i+1));
                        line[i]->SetBinError(j+1, h_3->GetBinError(j+1,i+1));
			double flag = h_3->GetBinError(j+1,i+1)/h_3->GetBinContent(j+1,i+1);
			if(flag>=maxRERR) maxRERR = flag;
			if(flag<=minRERR) minRERR = flag;
                }
                if(i==0)
		{
                        line[i] -> Draw();
			//cout << "draw1" << endl;
			//cout << "i = " << i <<endl;
		}
                else
		{
                        line[i] -> Draw("same");
			//cout << "drawt" << endl;
                        //cout << "i = " << i <<endl;
		}
        }
	cout << "maxRERR = " << maxRERR << endl;
	cout << "minRERR = " << minRERR << endl;
	TLegend* leg = new TLegend(0.65, 0.18, 0.85, 0.4);
        leg->SetTextFont(132);
        leg->SetTextSize(0.04);
        for(int i=0;i<Nybin;i++)
        {
                leg->AddEntry(Form("line%d",i), Form("%1.1f < #font[12]{y} < %1.1f", y[i], y[i+1]));
        }
        leg->Draw();
	can1 -> SaveAs(argv[9]);
	return 0;
}

