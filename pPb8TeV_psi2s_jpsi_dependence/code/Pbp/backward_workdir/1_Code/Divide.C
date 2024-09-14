#define DecayTree_cxx
#include "0_header/DecayTree.h"
#include <math.h>
#include <TStyle.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(int argc, char* argv[])
{
	int num_n, num_y, num_pt;
	sscanf(argv[1],"%d",&num_n);
        sscanf(argv[2],"%d",&num_y);
        sscanf(argv[3],"%d",&num_pt);
	vector<double> n, y, pt;
        double nbin, ybin, ptbin;
        int Nnbin, Nybin, Nptbin;
        ifstream nconfig(argv[4]);
        ifstream yconfig(argv[5]);
        ifstream ptconfig(argv[6]);
        nconfig >> Nnbin;
        yconfig >> Nybin;
        ptconfig >> Nptbin;
        for(int i=0; i<=Nnbin; i++)
        {
                nconfig >> nbin;
                n.push_back(nbin);
        }
        for(int i=0; i<=Nybin; i++)
        {
                yconfig >> ybin;
                y.push_back(ybin);
        }
        for(int i=0; i<=Nptbin; i++)
	{
		ptconfig >> ptbin;
                pt.push_back(ptbin);
        }
	//input
	TChain *F_in = new TChain("DecayTree");
	F_in -> Add(argv[7]);
	DecayTree tree(F_in);
	//select and output
	TFile *F_out = new TFile(Form("../0_File/Data/Divide/%sn%dy%dpt%d.root",argv[8],num_n,num_y, num_pt),"recreate");
	TTree *T_out = F_in -> CloneTree(0);

	//Loop
	long Num_Entries = F_in -> GetEntries();
	for(long jentry = 0; jentry <= Num_Entries; jentry++)
	{
		F_in -> GetEntry(jentry);
		//For pLead, y*=y-0.465
		//For Leadp, y*=-y-0.465
		double psi_Y =  -0.5 * log((tree.psi_PE + tree.psi_PZ)/(tree.psi_PE - tree.psi_PZ))-0.465;
		if(!(
					tree.psi_nBackTracks >=n[num_n-1] &&
					tree.psi_nBackTracks < n[num_n]    &&
					tree.psi_PT >= pt[num_pt-1]       &&
					tree.psi_PT <  pt[num_pt]         &&
					psi_Y >= y[num_y-1]      &&
					psi_Y < y[num_y]
		)) continue;
		T_out -> Fill();
	}
	T_out -> Write();
	F_out -> Close();
	return 0;
}
