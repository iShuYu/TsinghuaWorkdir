#define MCDecayTree_cxx
#include <TFile.h>
#include <TChain.h>
#include "MCDecayTree.h"
#include <iostream>
using namespace std;
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
		flag = abs(myTree_up.psi_MC_MOTHER_ID);
		if(flag!=0)
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
                flag = abs(myTree_up.psi_MC_MOTHER_ID);
                if(flag==0)
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
                flag = abs(myTree_down.psi_MC_MOTHER_ID);
                if(flag!=0)
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
                flag = abs(myTree_down.psi_MC_MOTHER_ID);
                if(flag==0)
		{
                        treep_down->Fill();
                }
        }
        DFp_down->WriteObject(treep_down,"MCDecayTree");
        prompt_down->Close();
	return 0;
}


//TFile *prompt = new TFile("Tuple_prompt.root","recreate");
