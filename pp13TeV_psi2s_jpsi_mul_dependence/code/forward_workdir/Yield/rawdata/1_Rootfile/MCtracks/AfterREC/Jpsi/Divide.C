#define mct_cxx
#include "mct.h"
#include <TTree.h>
#include <TFile.h>
using namespace std;
int type(int gdgdID,int gdID,int mID)
{
        gdgdID = abs(gdgdID);
        gdID = abs(gdID);
        mID = abs(mID);
        if(gdgdID==5) return 1;
        if(gdgdID==525) return 1;
        if(gdgdID==523) return 1;
        if(gdgdID==531) return 1;
        if(gdgdID==20523) return 1;
        if(gdgdID==513) return 1;
        if(gdgdID==10533) return 1;
        if(gdgdID==20513) return 1;
        if(gdgdID==533) return 1;
        if(gdgdID==515) return 1;
        if(gdgdID==10513) return 1;
        if(gdgdID==10521) return 1;
        if(gdgdID==20533) return 1;
        if(gdgdID==511) return 1;
        if(gdgdID==535) return 1;
        if(gdgdID==10511) return 1;
        if(gdgdID==521) return 1;
        if(gdgdID==541) return 1;
        if(gdgdID==10531) return 1;
        if(gdgdID==10523) return 1;
        if(gdgdID==5132) return 1;
        if(gdgdID==543) return 1;
        if(gdgdID==5122) return 1;
        if(gdgdID==5214) return 1;
        if(gdgdID==5114) return 1;
if(gdgdID==5222) return 1;
        if(gdgdID==20543) return 1;
        if(gdgdID==5212) return 1;
        if(gdgdID==5224) return 1;
        if(gdgdID==545) return 1;
        if(gdgdID==5312) return 1;
        if(gdgdID==10541) return 1;
        if(gdgdID==5112) return 1;
        if(gdgdID==10543) return 1;
        if(gdgdID==5314) return 1;
        if(gdID==521) return 1;
        if(gdID==513) return 1;
        if(gdID==525) return 1;
        if(gdID==523) return 1;
        if(gdID==533) return 1;
        if(gdID==511) return 1;
        if(gdID==531) return 1;
        if(gdID==10511) return 1;
        if(gdID==10521) return 1;
        if(gdID==515) return 1;
        if(gdID==5222) return 1;
        if(gdID==535) return 1;
        if(gdID==541) return 1;
        if(gdID==5112) return 1;
        if(gdID==5114) return 1;
        if(gdID==5212) return 1;
        if(gdID==5214) return 1;
        if(gdID==543) return 1;
        if(gdID==5122) return 1;
        if(gdID==5224) return 1;
        if(gdID==5132) return 1;
        if(gdID==10531) return 1;
        if(gdID==545) return 1;
        if(gdID==5324) return 1;
        if(gdID==5314) return 1;
        if(gdID==5322) return 1;
	if(gdID==5334) return 1;
        if(mID==511) return 1;
        if(mID==521) return 1;
        if(mID==531) return 1;
        if(mID==5122) return 1;
        if(mID==541) return 1;
        if(mID==5232) return 1;
        if(mID==5132) return 1;
        if(mID==5332) return 1;
        return 2;
}

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
		double flag = type(m.psi_MC_GD_GD_MOTHER_ID,m.psi_MC_GD_MOTHER_ID,m.psi_MC_MOTHER_ID);
		if(flag==1) cp->Fill();
		//else cb->Fill();
	}
	cp->Write();
	prompt->Close();

	TFile *fromb = new TFile("Tupleb.root","recreate");
	TTree* cb = c->CloneTree(0);
	for(int i=0; i<N; i++)
        {
                c->GetEntry(i);
                double flag = type(m.psi_MC_GD_GD_MOTHER_ID,m.psi_MC_GD_MOTHER_ID,m.psi_MC_MOTHER_ID);
                if(flag!=1) cb->Fill();
                //else cb->Fill();
        }
        cb->Write();
        fromb->Close();
	return 0;
}

