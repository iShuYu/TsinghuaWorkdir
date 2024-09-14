#define mct_cxx
#define MCDecayTree_cxx
#include "0_header/mct.h"
#include "0_header/MCDecayTree.h"
#include <TStyle.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
	int num_n;
	sscanf(argv[1],"%d",&num_n);
	vector<double> n;
	double nbin;
	int Nnbin;
	ifstream nconfig(argv[2]);
	nconfig >> Nnbin;
	for(int i=0; i<=Nnbin; i++)
        {
                nconfig >> nbin;
                n.push_back(nbin);
        }
	//input
	TChain *F_DecayTree = new TChain("tuple1/DecayTree");
	TChain *F_MCDecayTree = new TChain("mct/mct");
	F_DecayTree -> Add(argv[3]);
	F_MCDecayTree -> Add(argv[3]);

	MCDecayTree tree(F_DecayTree);
	mct Tree(F_MCDecayTree);

	//output 1
	TFile *F_DecayTree_out = new TFile(Form("../0_File/MC/Divide/%s_n%d.root", argv[4], num_n),"recreate");
	TTree *DecayTree_out = F_DecayTree -> CloneTree(0);
	long Num_Entries = F_DecayTree -> GetEntries();
	cout << "total entries = " << Num_Entries << endl;
	for(long jentry = 0; jentry <= Num_Entries; jentry++)
	{
		F_DecayTree -> GetEntry(jentry);
		if(!(
			tree.nPVs == 1 &&
			tree.PVNTRACKS[0] >=n[num_n-1] &&
			tree.PVNTRACKS[0] < n[num_n]
		)) continue;
		DecayTree_out->Fill();
	}
	DecayTree_out->Write();
	F_DecayTree_out->Close();

	//output 2
        TFile *F_MCDecayTree_out = new TFile(Form("../0_File/MC/Divide/mct%s_n%d.root", argv[4], num_n),"recreate");
        TTree *MCDecayTree_out = F_MCDecayTree -> CloneTree(0);
        long Num = F_MCDecayTree -> GetEntries();
        cout << "total entries = " << Num << endl;
        for(long jentry = 0; jentry <= Num; jentry++)
        {
                F_MCDecayTree -> GetEntry(jentry);
                if(!(
			Tree.nPVs == 1 &&
                        Tree.PVNTRACKS[0] >=n[num_n-1] &&
                        Tree.PVNTRACKS[0] < n[num_n]
                )) continue;
                MCDecayTree_out->Fill();
        }
        MCDecayTree_out->Write();
        F_MCDecayTree_out->Close();
	return 0;
}

