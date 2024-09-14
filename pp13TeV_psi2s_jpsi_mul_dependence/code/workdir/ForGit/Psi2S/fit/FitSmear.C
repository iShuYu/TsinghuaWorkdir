#include <TROOT.h>
#include <TAxis.h>
#include <RooFit.h>
#include <RooPlot.h>
#include <fstream>
#include <TF1.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TCanvas.h>
using namespace std;
using namespace RooFit;

int main(int argc, char* argv[])
{
	double alpha[21];
	double sigma[21];
	double alpha_err[21];
	double sigma_err[21];
	for(int i=10;i<=30;i++)
	{
		ifstream input(Form("../../3_Result/smear/sigma_%d.txt",i));
		input>>alpha[i-10];
		input>>sigma[i-10];
		input>>alpha_err[i-10];
		sigma_err[i-10]=0;
	}
	TGraphErrors *gr = new TGraphErrors(21,sigma,alpha,sigma_err,alpha_err);
	TF1 *F = new TF1("F","[0]*x*x+[1]*x+[2]",10.,31.);
	TCanvas *can = new TCanvas("can","can",800,600);
	gr->SetTitle("#psi(2S) smear result");
	gr->GetXaxis()->SetTitle("#sigma");
	gr->GetYaxis()->SetTitle("#alpha");
	gr->Draw();
	gr->Fit("F");
	can->SaveAs(argv[1]);
	ofstream output(argv[2]);
	for(int i=0; i<=2; i++)
	{
		output<<F->GetParameter(i)<<endl;
		//output<<F->GetParError(i)<<endl;
	}
	for(int i=0; i<=2; i++)
        {
                //output<<F->GetParameter(i)<<endl;
                output<<F->GetParError(i)<<endl;
        }
	output.close();
}
