#define mct_cxx
#include "mct.h"
#include <TTree.h>
int main()
{
	TFile *input = TFile::Open("Tuple.root");
	TTree *mtree = (TTree*)input->Get("mct");
	mct m(mtree);
	TFile *Fout = new TFile("Tuplenew.root","recreate");
	TTree *newmct = mtree->CloneTree(0);
	double NchL;
	newmct -> Branch("NchL", &NchL, "NchL/D");
	for(int i=0; i<mtree->GetEntries(); i++)
	{
		mtree->GetEntry(i);
		int Np = m.n_Particles;
		NchL = 0;
		for(int n=0; n<Np; n++)
	        {
            	if(m.H_TRUEETA[n]>5.2) continue;
            	if(m.H_TRUEETA[n]<1.5) continue;
           	 NchL = NchL + 1;
        	}
        	newmct -> Fill();
    	}
    	newmct -> Write();
   	Fout ->Close();
    	return 0;
}

