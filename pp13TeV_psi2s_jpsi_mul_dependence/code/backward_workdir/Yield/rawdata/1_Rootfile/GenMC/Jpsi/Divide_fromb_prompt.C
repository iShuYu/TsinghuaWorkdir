#define MCDecayTree_cxx
#include <TFile.h>
#include <TChain.h>
#include "MCDecayTree.h"
#include <iostream>
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

int main()
{
	TChain* chain_up = new TChain("MCDecayTreeTuple/MCDecayTree");
	TChain* chain_down = new TChain("MCDecayTreeTuple/MCDecayTree");
	chain_up -> Add("Tuple_MagUp.root");
	chain_down -> Add("Tuple_MagDown.root");
	MCDecayTree myTree_up(chain_up);
	MCDecayTree myTree_down(chain_down);
	int Nu = chain_up->GetEntries();
	int Nd = chain_down->GetEntries();
	double flag;

	TFile *fromb_up = new TFile("Tuple_fromb_MagUp.root","recreate");
	TDirectoryFile *DF_up = new TDirectoryFile("MCDecayTreeTuple","recreate");
	TTree *tree_up = chain_up->CloneTree(0);
	for(int i=0; i<Nu; i++)
        {
                chain_up -> GetEntry(i);
		flag = type(myTree_up.psi_MC_GD_GD_MOTHER_ID,myTree_up.psi_MC_GD_MOTHER_ID,myTree_up.psi_MC_MOTHER_ID);
		//if(flag==511||flag==521||flag==531||flag==541||flag==5122||flag==5132||flag==5232||flag==5332)
		if(flag==1)
		{
			tree_up->Fill();
		}
	}
	DF_up->WriteObject(tree_up,"MCDecayTree");
	fromb_up->Close();

	TFile *prompt_up = new TFile("Tuple_prompt_MagUp.root","recreate");
	TDirectoryFile *DFp_up = new TDirectoryFile("MCDecayTreeTuple","recreate");
        TTree *treep_up = chain_up->CloneTree(0);
	for(int i=0; i<Nu; i++)
        {
                chain_up -> GetEntry(i);
                flag = type(myTree_up.psi_MC_GD_GD_MOTHER_ID,myTree_up.psi_MC_GD_MOTHER_ID,myTree_up.psi_MC_MOTHER_ID);
		//if(flag!=511&&flag!=521&&flag!=531&&flag!=541&&flag!=5122&&flag!=5132&&flag!=5232&&flag!=5332)
                if(flag==2)
		{
                        treep_up->Fill();
                }
        }
        DFp_up->WriteObject(treep_up,"MCDecayTree");
        prompt_up->Close();

	TFile *fromb_down = new TFile("Tuple_fromb_MagDown.root","recreate");
        TDirectoryFile *DF_down = new TDirectoryFile("MCDecayTreeTuple","recreate");
        TTree *tree_down = chain_down->CloneTree(0);
        for(int i=0; i<Nd; i++)
        {
                chain_down -> GetEntry(i);
                flag = type(myTree_down.psi_MC_GD_GD_MOTHER_ID,myTree_down.psi_MC_GD_MOTHER_ID,myTree_down.psi_MC_MOTHER_ID);
                //if(flag==511||flag==521||flag==531||flag==541||flag==5122||flag==5132||flag==5232||flag==5332)
                if(flag==1)
		{
                        tree_down->Fill();
                }
        }
        DF_down->WriteObject(tree_down,"MCDecayTree");
        fromb_down->Close();

	TFile *prompt_down = new TFile("Tuple_prompt_MagDown.root","recreate");
        TDirectoryFile *DFp_down = new TDirectoryFile("MCDecayTreeTuple","recreate");
        TTree *treep_down = chain_down->CloneTree(0);
        for(int i=0; i<Nu; i++)
        {
                chain_down -> GetEntry(i);
                flag = type(myTree_down.psi_MC_GD_GD_MOTHER_ID,myTree_down.psi_MC_GD_MOTHER_ID,myTree_down.psi_MC_MOTHER_ID);
		if(flag==2)
		{
                        treep_down->Fill();
                }
        }
        DFp_down->WriteObject(treep_down,"MCDecayTree");
        prompt_down->Close();
	return 0;
}


//TFile *prompt = new TFile("Tuple_prompt.root","recreate");
