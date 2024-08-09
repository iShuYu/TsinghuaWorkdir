#define MCJpsi_cxx
#define mctJpsi_cxx
#include "mctJpsi.h"
#include "MCJpsi.h"
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
	F_DecayTree -> Add("~/workdir_local/Yield/rawdata/1_Rootfile/MC/MagDown/Jpsi/MCJpsi16MagDown_b.root");
	F_MCDecayTree -> Add("~/workdir_local/Yield/rawdata/1_Rootfile/MC/MagDown/Jpsi/MCJpsi16MagDown_b.root");

	MCJpsi tree(F_DecayTree);
	mctJpsi Tree(F_MCDecayTree);

	//output 1
	TFile *F_DecayTree_out = new TFile(Form("../2_AfterDivide/MC/Jpsi/n%d_MagDown.root",num_n),"recreate");
	TTree *DecayTree_out = F_DecayTree -> CloneTree(0);
	long Num_Entries = F_DecayTree -> GetEntries();
	cout << "total entries = " << Num_Entries << endl;
	for(long jentry = 0; jentry <= Num_Entries; jentry++)
	{
		F_DecayTree -> GetEntry(jentry);
		if(!(
			tree.nPVs == 1 &&
			tree.nBackTracks >=n[num_n-1] &&
			tree.nBackTracks < n[num_n]
		)) continue;
		DecayTree_out->Fill();
	}
	DecayTree_out->Write();
	F_DecayTree_out->Close();

	//output 1 from b
	TFile *F_DecayTree_out_fromb = new TFile(Form("../2_AfterDivide/MC/Jpsi/n%d_MagDown_fromb.root",num_n),"recreate");
        TTree *DecayTree_out_fromb = F_DecayTree -> CloneTree(0);
        for(long jentry = 0; jentry <= Num_Entries; jentry++)
        {
                F_DecayTree -> GetEntry(jentry);
                if(!(
                        tree.nPVs == 1 &&
                        tree.nBackTracks >=n[num_n-1] &&
                        tree.nBackTracks < n[num_n]
                )) continue;
                //if(abs(tree.psi_MC_GD_GD_MOTHER_ID)!=0&&abs(tree.psi_MC_GD_GD_MOTHER_ID)!=4)
		if(type(tree.psi_MC_GD_GD_MOTHER_ID,tree.psi_MC_GD_MOTHER_ID,tree.psi_MC_MOTHER_ID)==1)
		{
			DecayTree_out_fromb->Fill();
		}
        }
        DecayTree_out_fromb->Write();
        F_DecayTree_out_fromb->Close();

	//output 1 prompt
	TFile *F_DecayTree_out_prompt = new TFile(Form("../2_AfterDivide/MC/Jpsi/n%d_MagDown_prompt.root",num_n),"recreate");
        TTree *DecayTree_out_prompt = F_DecayTree -> CloneTree(0);
        for(long jentry = 0; jentry <= Num_Entries; jentry++)
        {
                F_DecayTree -> GetEntry(jentry);
                if(!(
                        tree.nPVs == 1 &&
                        tree.nBackTracks >=n[num_n-1] &&
                        tree.nBackTracks < n[num_n]
                )) continue;
		if(type(tree.psi_MC_GD_GD_MOTHER_ID,tree.psi_MC_GD_MOTHER_ID,tree.psi_MC_MOTHER_ID)==2)
		{
                        DecayTree_out_prompt->Fill();
                }
        }
        DecayTree_out_prompt->Write();
        F_DecayTree_out_prompt->Close();

	//output 2
        TFile *F_MCDecayTree_out = new TFile(Form("../2_AfterDivide/MC/Jpsi/mctn%d_MagDown.root",num_n),"recreate");
        TTree *MCDecayTree_out = F_MCDecayTree -> CloneTree(0);
        long Num = F_MCDecayTree -> GetEntries();
        cout << "total entries = " << Num << endl;
        for(long jentry = 0; jentry <= Num; jentry++)
        {
                F_MCDecayTree -> GetEntry(jentry);
                if(!(
			Tree.nPVs == 1 &&
                        Tree.nBackTracks >=n[num_n-1] &&
                        Tree.nBackTracks < n[num_n]
                )) continue;
                MCDecayTree_out->Fill();
        }
        MCDecayTree_out->Write();
        F_MCDecayTree_out->Close();

	//output 2 from b
	TFile *F_MCDecayTree_out_fromb = new TFile(Form("../2_AfterDivide/MC/Jpsi/mctn%d_MagDown_fromb.root",num_n),"recreate");
        TTree *MCDecayTree_out_fromb = F_MCDecayTree -> CloneTree(0);
        for(long jentry = 0; jentry <= Num; jentry++)
        {
                F_MCDecayTree -> GetEntry(jentry);
                if(!(
                        Tree.nPVs == 1 &&
                        Tree.nBackTracks >=n[num_n-1] &&
                        Tree.nBackTracks < n[num_n]
                )) continue;
		if(type(Tree.psi_MC_GD_GD_MOTHER_ID,Tree.psi_MC_GD_MOTHER_ID,Tree.psi_MC_MOTHER_ID)==1)
		{
			MCDecayTree_out_fromb->Fill();
		}
        }
        MCDecayTree_out_fromb->Write();
        F_MCDecayTree_out_fromb->Close();

	//output 2 prompt
	TFile *F_MCDecayTree_out_prompt = new TFile(Form("../2_AfterDivide/MC/Jpsi/mctn%d_MagDown_prompt.root",num_n),"recreate");
        TTree *MCDecayTree_out_prompt = F_MCDecayTree -> CloneTree(0);
        for(long jentry = 0; jentry <= Num; jentry++)
        {
                F_MCDecayTree -> GetEntry(jentry);
                if(!(
                        Tree.nPVs == 1 &&
                        Tree.nBackTracks >=n[num_n-1] &&
                        Tree.nBackTracks < n[num_n]
                )) continue;
		if(type(Tree.psi_MC_GD_GD_MOTHER_ID,Tree.psi_MC_GD_MOTHER_ID,Tree.psi_MC_MOTHER_ID)==2)
		{
                        MCDecayTree_out_prompt->Fill();
                }
        }
        MCDecayTree_out_prompt->Write();
        F_MCDecayTree_out_prompt->Close();

	return 0;
}

