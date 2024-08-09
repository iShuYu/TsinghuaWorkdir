#define DecayTree_cxx
#include "DecayTree.h"
#include <math.h>
#include <TStyle.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(int argc, char* argv[])
{	
	int num_y;
	sscanf(argv[1],"%d",&num_y);
	//input
	TChain *F_in = new TChain("DecayTree");
	F_in -> Add("Data_Splot.root");
	DecayTree tree(F_in);

	//select and output
	double y[8] = {2.0, 2.5, 2.8, 3.1, 3.3, 3.7, 4.0, 4.5};
	TFile *F_out = new TFile(Form("./Y%d.root",num_y),"recreate");
	TTree *T_out = F_in -> CloneTree(0);
	//Loop
	long Num_Entries = F_in -> GetEntries();
	for(long jentry = 0; jentry <= Num_Entries; jentry++)
	{
		F_in -> GetEntry(jentry);	
		double psi_Y = 0.5 * log((tree.psi_PE + tree.psi_PZ)/(tree.psi_PE - tree.psi_PZ));
		if(!(
			psi_Y >= y[num_y-1]      &&
			psi_Y < y[num_y]
		)) continue;
		T_out -> Fill();
	}
	T_out -> Write();
	F_out -> Close();
	return 0;
}
