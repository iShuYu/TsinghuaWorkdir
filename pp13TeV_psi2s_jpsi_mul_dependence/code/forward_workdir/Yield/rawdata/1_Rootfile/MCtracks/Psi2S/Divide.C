#define mct_cxx
#include "mct.h"
#include <TTree.h>
#include <TFile.h>
using namespace std;
int main(int argc, char* argv[])
{
	TChain *c = new TChain("mct");
	c -> Add("./Tuple.root");
	mct m(c);
	int N = c->GetEntries();
	TFile *prompt = new TFile("Tuplep.root","recreate");
	TTree* cp = c->CloneTree(0);
	for(int i=0; i<N; i++)
	{
		c->GetEntry(i);
		if(abs(m.psi_MC_MOTHER_ID)==0) cp->Fill();
		//else cb->Fill();
	}
	cp->Write();
	prompt->Close();
	TFile *fromb = new TFile("Tupleb.root","recreate");
        TTree* cb = c->CloneTree(0);
	for(int i=0; i<N; i++)
        {
                c->GetEntry(i);
                if(abs(m.psi_MC_MOTHER_ID)!=0) cb->Fill();
                //else cb->Fill();
        }
	cb->Write();
        fromb->Close();
	return 0;
}

