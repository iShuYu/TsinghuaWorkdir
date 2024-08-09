#define MCJpsi_cxx
#define MCPsi2S_cxx
#include "MCJpsi.h"
#include "MCPsi2S.h"
#include <math.h>
#include <iostream>
#include <fstream>
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

int main(int argc, char *argv[])
{
	//input
	TChain *CJ = new TChain("DecayTree");
	TChain *CP = new TChain("DecayTree");
	CJ -> Add(argv[1]);
	CP -> Add(argv[2]);
	MCJpsi tJ(CJ);
	MCPsi2S tP(CP);
	int NJfromb = 0;
	int NPfromb = 0;
	int NJprompt = 0;
	int NPprompt = 0;
	int NJ = CJ->GetEntries();
	int flag;
	for(int i=0; i<NJ; i++)
	{
		CJ -> GetEntry(i);
		flag = type(tJ.psi_MC_GD_GD_MOTHER_ID,tJ.psi_MC_GD_MOTHER_ID,tJ.psi_MC_MOTHER_ID);
		if(flag==1)
		{
			NJfromb = NJfromb+1;
		}
		else
		{
			NJprompt = NJprompt+1;
		}
	}
	int NP = CP->GetEntries();
	for(int i=0; i<NP; i++)
	{
		CP -> GetEntry(i);
		//flag = type(tP.psi_MC_GD_GD_MOTHER_ID,tP.psi_MC_GD_MOTHER_ID,tP.psi_MC_MOTHER_ID);
		if(tP.psi_MC_MOTHER_ID==0)
		{
			NPprompt = NPprompt+1;
		}
		else
		{
			NPfromb = NPfromb+1;
		}
	}
	ofstream J(argv[3]);
	J << NJprompt << endl;
	J << NJfromb << endl;
	J.close();
	ofstream P(argv[4]);
        P << NPprompt << endl;
        P << NPfromb << endl;
        P.close();
	return 0;
}

