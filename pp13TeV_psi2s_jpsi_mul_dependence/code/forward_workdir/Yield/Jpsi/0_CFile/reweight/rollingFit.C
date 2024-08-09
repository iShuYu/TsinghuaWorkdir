#include <fstream>
#include <iostream>
#include <TF2.h>
#include <TROOT.h>
#include <TFile.h>
#include <TStyle.h>
#include <TH2D.h>
#include <TCanvas.h>
#include <TFile.h>
#include "../../0_CFile/header/lhcbStyle.h"
#include <TLegend.h>
using namespace std;
int main(int argc, char* argv[])
{
    setLHCbStyle();
    //input
    for(int ii=0; ii<13; ii++){
    TFile *input = TFile::Open(Form("../../3_Result/reweight/MUL/PVN_Nch%d.root",ii));
    TH2D *Tb = (TH2D*)input->Get("Tb");
    TH2D *Tp = (TH2D*)input->Get("Tp");

    // Fitting function (you can define your own)
    TF1* f1b = new TF1("f1b", "[0]*x^[1]",4,240);
    f1b -> SetParameters(1,1,1);
    
    TF1* f1p = new TF1("f1p", "[0]*x^[1]",4,240);
    f1p -> SetParameters(1,1,1);


    TF1* f2b = new TF1("f2b", "pol2");
    TF1* f2p = new TF1("f2p", "pol2");

    f2p -> SetLineColor(kMagenta);
    f2b -> SetLineColor(kMagenta);


    Tb -> Fit("f1b");
    TF1 *infob1 = Tb -> GetFunction("f1b");
    double p0b = infob1 -> GetParameter(0);
    double p1b = infob1 -> GetParameter(1);
    Tp -> Fit("f1p");
    TF1 *infop1 = Tp -> GetFunction("f1p");
    double p0p = infop1 -> GetParameter(0);
    double p1p = infop1 -> GetParameter(1);
    Tb -> Fit("f2b");
    TF1 *infob2 = Tb -> GetFunction("f2b");
    double q0b = infob2 -> GetParameter(0);
    double q1b = infob2 -> GetParameter(1);
    double q2b = infob2 -> GetParameter(2);
    double q0berr = infob2 -> GetParError(0);
    double q1berr = infob2 -> GetParError(1);
    double q2berr = infob2 -> GetParError(2);

    Tp -> Fit("f2p");
    TF1 *infop2 = Tp -> GetFunction("f2p");
    double q0p = infop2 -> GetParameter(0);
    double q1p = infop2 -> GetParameter(1);
    double q2p = infop2 -> GetParameter(2);
    double q0perr = infop2 -> GetParError(0);
    double q1perr = infop2 -> GetParError(1);
    double q2perr = infop2 -> GetParError(2);

    
    //plot
    TCanvas *canp = new TCanvas("canp","canp",1200,800);
    Tp -> GetXaxis() -> SetTitle("#font[12]{N}^{PV, cor}_{tracks}");
    Tp -> GetYaxis() -> SetTitle("#font[12]{N}_{ch}");
    Tp -> GetXaxis() -> SetRangeUser(0,240);
    Tp -> GetYaxis() -> SetRangeUser(0,120);
    Tp -> Draw("colz");
    f1p -> SetLineColor(kGreen);
    f1p -> SetLineStyle(2);
    f1p -> SetLineWidth(2);
    f1p -> Draw("same");
    f2p -> SetLineColor(kMagenta);
    f2p -> SetLineWidth(2);
    f2p -> Draw("same");
    TLegend *legp = new TLegend(0.6,0.2,0.8,0.32);
    legp -> SetHeader("prompt J/#psi");
    legp -> AddEntry(f1p, "power function", "L");
    legp -> AddEntry(f2p, "2nd order poly", "L");
    legp -> Draw("same");
    canp -> SaveAs(Form("../../4_Plot/reweight/fitWithPol12_prompt%d.pdf",ii ));
    canp -> Close();
    ofstream fp(Form("../../3_Result/reweight/MUL/fitp%d.txt",ii));
    //fp << p0p << p1p << q0p << q1p << q2p << endl;
    fp << p0p << endl << p1p << endl << q0p << endl << q1p << endl << q2p << endl <<  q0perr << endl << q1perr << endl << q2perr << endl;
    fp.close();

    TCanvas *canb = new TCanvas("canb","canb",1200,800);
    Tb -> GetXaxis() -> SetTitle("#font[12]{N}^{PV, cor}_{tracks}");
    Tb -> GetYaxis() -> SetTitle("#font[12]{N}_{ch}");
    Tb -> Draw("colz");
    f1b -> SetLineColor(kGreen);
    f1b -> SetLineStyle(2);
    f1b -> SetLineWidth(2);
    f1b -> Draw("same");
    f2b -> SetLineColor(kMagenta);
    f2b -> SetLineWidth(2);
    f2b -> Draw("same");
    TLegend *legb = new TLegend(0.6,0.2,0.8,0.32);
    legb -> SetHeader("non-prompt J/#psi");
    legb -> AddEntry(f1b, "power function", "L");
    legb -> AddEntry(f2b, "2nd order poly", "L");
    legb -> Draw("same");
    canb -> SaveAs(Form("../../4_Plot/reweight/fitWithPol12_fromb%d.pdf",ii));
    canb -> Close();
    ofstream fb(Form("../../3_Result/reweight/MUL/fitb%d.txt",ii));
    //fb << p0b << p1b << q0b << q1b << q2b << endl;
    fb << p0b << endl << p1b << endl << q0b << endl << q1b << endl << q2b << endl  <<  q0berr << endl << q1berr << endl << q2berr << endl;
    fb.close();
    }
    return 0;
}
