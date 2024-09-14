#define MCPsi2S_cxx
#define mctPsi2S_cxx
#include "mctPsi2S.h"
#include "MCPsi2S.h"
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
	F_DecayTree -> Add("../../1_Rootfile/MC/MagDown/Psi2S/MCPsi2S16Down_i.root");
	F_MCDecayTree -> Add("../../1_Rootfile/MC/MagDown/Psi2S/MCPsi2S16Down_i.root");
	F_DecayTree -> Add("../../1_Rootfile/MC/MagDown/Psi2S/MCPsi2S16Down_l.root");
        F_MCDecayTree -> Add("../../1_Rootfile/MC/MagDown/Psi2S/MCPsi2S16Down_l.root");
	//F_DecayTree -> Add("../../1_Rootfile/MC/MagDown/Psi2S/MCPsi2S16Down_k.root");
	//F_MCDecayTree -> Add("../../1_Rootfile/MC/MagDown/Psi2S/MCPsi2S16Down_k.root");
	//F_DecayTree -> Add("../../1_Rootfile/MC/MagDown/Psi2S/MCPsi2S16Down_i.root");
	//F_DecayTree -> Add("../../1_Rootfile/MC/MagDown/Psi2S/MCPsi2S16Down_i.root");
	MCPsi2S tree(F_DecayTree);
	mctPsi2S Tree(F_MCDecayTree);

	//output 1
	TFile *F_DecayTree_out = new TFile(Form("../2_AfterDivide/MC/Psi2S/n%d_MagDown.root",num_n),"recreate");
	TTree *DecayTree_out = F_DecayTree -> CloneTree(0);
	long Num_Entries = F_DecayTree -> GetEntries();
	cout << "total entries = " << Num_Entries << endl;
	for(long jentry = 0; jentry <= Num_Entries; jentry++)
	{
		F_DecayTree -> GetEntry(jentry);
		if(!(
			tree.nPVs == 1 &&
			tree.PVZ[0] >= -60 &&
			tree.PVNTRACKS[0] >=n[num_n-1] &&
			tree.PVNTRACKS[0] < n[num_n]
		)) continue;
		DecayTree_out->Fill();
	}
	DecayTree_out->Write();
	F_DecayTree_out->Close();

	//output 1 fromb
	TFile *F_DecayTree_out_fromb = new TFile(Form("../2_AfterDivide/MC/Psi2S/n%d_MagDown_fromb.root",num_n),"recreate");
        TTree *DecayTree_out_fromb = F_DecayTree -> CloneTree(0);
        for(long jentry = 0; jentry <= Num_Entries; jentry++)
        {
                F_DecayTree -> GetEntry(jentry);
                if(!(
                        tree.nPVs == 1 &&
			tree.PVZ[0] >= -60 &&
                        tree.PVNTRACKS[0] >=n[num_n-1] &&
                        tree.PVNTRACKS[0] < n[num_n]
                )) continue;
		//if(abs(tree.psi_MC_MOTHER_ID)==511||abs(tree.psi_MC_MOTHER_ID)==521||abs(tree.psi_MC_MOTHER_ID)==531||abs(tree.psi_MC_MOTHER_ID)==541||abs(tree.psi_MC_MOTHER_ID)==5122||abs(tree.psi_MC_MOTHER_ID)==5132||abs(tree.psi_MC_MOTHER_ID)==5232||abs(tree.psi_MC_MOTHER_ID)==5332)
		if(tree.psi_MC_MOTHER_ID!=0)
		{
                	DecayTree_out_fromb->Fill();
		}
        }
        DecayTree_out_fromb->Write();
        F_DecayTree_out_fromb->Close();

	//output 1 prompt
	TFile *F_DecayTree_out_prompt = new TFile(Form("../2_AfterDivide/MC/Psi2S/n%d_MagDown_prompt.root",num_n),"recreate");
        TTree *DecayTree_out_prompt = F_DecayTree -> CloneTree(0);
        for(long jentry = 0; jentry <= Num_Entries; jentry++)
        {
                F_DecayTree -> GetEntry(jentry);
                if(!(
                        tree.nPVs == 1 &&
			tree.PVZ[0] >= -60 &&
                        tree.PVNTRACKS[0] >=n[num_n-1] &&
                        tree.PVNTRACKS[0] < n[num_n]
                )) continue;
                //if(!(abs(tree.psi_MC_MOTHER_ID)==511||abs(tree.psi_MC_MOTHER_ID)==521||abs(tree.psi_MC_MOTHER_ID)==531||abs(tree.psi_MC_MOTHER_ID)==541||abs(tree.psi_MC_MOTHER_ID)==5122||abs(tree.psi_MC_MOTHER_ID)==5132||abs(tree.psi_MC_MOTHER_ID)==5232||abs(tree.psi_MC_MOTHER_ID)==5332))
		if(tree.psi_MC_MOTHER_ID==0)
		{
                        DecayTree_out_prompt->Fill();
                }
        }
        DecayTree_out_prompt->Write();
        F_DecayTree_out_prompt->Close();

	//output 2
        TFile *F_MCDecayTree_out = new TFile(Form("../2_AfterDivide/MC/Psi2S/mctn%d_MagDown.root",num_n),"recreate");
        TTree *MCDecayTree_out = F_MCDecayTree -> CloneTree(0);
        long Num = F_MCDecayTree -> GetEntries();
        cout << "total entries = " << Num << endl;
        for(long jentry = 0; jentry <= Num; jentry++)
        {
                F_MCDecayTree -> GetEntry(jentry);
                if(!(
			Tree.nPVs == 1 &&
			Tree.PVZ[0] >= -60 &&
                        Tree.PVNTRACKS[0] >=n[num_n-1] &&
                        Tree.PVNTRACKS[0] < n[num_n]
                )) continue;
                MCDecayTree_out->Fill();
        }
        MCDecayTree_out->Write();
        F_MCDecayTree_out->Close();

	//output 2 fromb
	TFile *F_MCDecayTree_out_fromb = new TFile(Form("../2_AfterDivide/MC/Psi2S/mctn%d_MagDown_fromb.root",num_n),"recreate");
        TTree *MCDecayTree_out_fromb = F_MCDecayTree -> CloneTree(0);
        for(long jentry = 0; jentry <= Num; jentry++)
        {
                F_MCDecayTree -> GetEntry(jentry);
                if(!(
                        Tree.nPVs == 1 &&
                        Tree.PVZ[0] >= -60 &&
			Tree.PVNTRACKS[0] >=n[num_n-1] &&
                        Tree.PVNTRACKS[0] < n[num_n]
                )) continue;
		//if(abs(Tree.psi_MC_MOTHER_ID)==511||abs(Tree.psi_MC_MOTHER_ID)==521||abs(Tree.psi_MC_MOTHER_ID)==531||abs(Tree.psi_MC_MOTHER_ID)==541||abs(Tree.psi_MC_MOTHER_ID)==5122||abs(Tree.psi_MC_MOTHER_ID)==5132||abs(Tree.psi_MC_MOTHER_ID)==5232||abs(Tree.psi_MC_MOTHER_ID)==5332)
		if(Tree.psi_MC_MOTHER_ID!=0)
		{
                	MCDecayTree_out_fromb->Fill();
		}
        }
        MCDecayTree_out_fromb->Write();
        F_MCDecayTree_out_fromb->Close();

	//output 2 prompt
	TFile *F_MCDecayTree_out_prompt = new TFile(Form("../2_AfterDivide/MC/Psi2S/mctn%d_MagDown_prompt.root",num_n),"recreate");
        TTree *MCDecayTree_out_prompt = F_MCDecayTree -> CloneTree(0);
        for(long jentry = 0; jentry <= Num; jentry++)
        {
                F_MCDecayTree -> GetEntry(jentry);
                if(!(
                        Tree.nPVs == 1 &&
                        Tree.PVZ[0] >= -60 &&
			Tree.PVNTRACKS[0] >=n[num_n-1] &&
                        Tree.PVNTRACKS[0] < n[num_n]
                )) continue;
                //if(!(abs(Tree.psi_MC_MOTHER_ID)==511||abs(Tree.psi_MC_MOTHER_ID)==521||abs(Tree.psi_MC_MOTHER_ID)==531||abs(Tree.psi_MC_MOTHER_ID)==541||abs(Tree.psi_MC_MOTHER_ID)==5122||abs(Tree.psi_MC_MOTHER_ID)==5132||abs(Tree.psi_MC_MOTHER_ID)==5232||abs(Tree.psi_MC_MOTHER_ID)==5332))
		if(Tree.psi_MC_MOTHER_ID==0)
		{
                        MCDecayTree_out_prompt->Fill();
                }
        }
        MCDecayTree_out_prompt->Write();
        F_MCDecayTree_out_prompt->Close();

	return 0;
}

