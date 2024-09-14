#define mct_cxx
#include "/nishome/kangye/disk402_ppAnalysis/ForWorkdir/Yield/Jpsi/0_CFile/reweight/mct.h"
#include <TStyle.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
//type=1, fromb, 2, prompt
//任何一级别的ID为0表示直接由pp碰撞产生
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
	TChain *F_DecayTree = new TChain("mct");
	F_DecayTree -> Add("../../1_Rootfile/MCtracks/Jpsi/Tuple.root");
	mct Tree(F_DecayTree);
	int Num_Entries  = F_DecayTree->GetEntries();

	//output 1 from b
	TFile *F_DecayTree_out_fromb = new TFile("../../1_Rootfile/MCtracks/Jpsi/Tupleb.root","recreate");
        TTree *DecayTree_out_fromb = F_DecayTree -> CloneTree(0);
        for(long jentry = 0; jentry <= Num_Entries; jentry++)
        {
        	F_DecayTree -> GetEntry(jentry);
		//if(abs(Tree.psi_MC_GD_GD_MOTHER_ID)!=0&&abs(Tree.psi_MC_GD_GD_MOTHER_ID)!=4)
		if(type(Tree.psi_MC_GD_GD_MOTHER_ID,Tree.psi_MC_GD_MOTHER_ID,Tree.psi_MC_MOTHER_ID)==1)
		{
			DecayTree_out_fromb->Fill();
		}
        }
        DecayTree_out_fromb->Write();
        F_DecayTree_out_fromb->Close();

	//output 1 prompt
	TFile *F_DecayTree_out_prompt = new TFile("../../1_Rootfile/MCtracks/Jpsi/Tuplep.root","recreate");
        TTree *DecayTree_out_prompt = F_DecayTree -> CloneTree(0);
        for(long jentry = 0; jentry <= Num_Entries; jentry++)
        {
		F_DecayTree -> GetEntry(jentry);
		if(type(Tree.psi_MC_GD_GD_MOTHER_ID,Tree.psi_MC_GD_MOTHER_ID,Tree.psi_MC_MOTHER_ID)==2)
		{
                        DecayTree_out_prompt->Fill();
                }
        }
        DecayTree_out_prompt->Write();
        F_DecayTree_out_prompt->Close();


	return 0;
}

