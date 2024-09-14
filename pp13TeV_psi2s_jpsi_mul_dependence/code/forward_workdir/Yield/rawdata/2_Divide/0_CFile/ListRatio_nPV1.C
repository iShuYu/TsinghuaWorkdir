#include <TStyle.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <TChain.h>
using namespace std;
int main(int argc, char *argv[])
{
	//input MCJpsi
	TChain *F_DecayTree_J = new TChain("tuple1/DecayTree");
	TChain *F_MCDecayTree_J = new TChain("mct/mct");
	for (int i = 0; i <= 25; i++)
	{
		F_DecayTree_J -> Add(Form("../../1_Rootfile/MC/MagDown/Jpsi/%d/output/Tuple.root",i));
		F_MCDecayTree_J -> Add(Form("../../1_Rootfile/MC/MagDown/Jpsi/%d/output/Tuple.root",i));
		F_DecayTree_J -> Add(Form("../../1_Rootfile/MC/MagUp/Jpsi/%d/output/Tuple.root",i));
                F_MCDecayTree_J -> Add(Form("../../1_Rootfile/MC/MagUp/Jpsi/%d/output/Tuple.root",i));
	}
	//input MCPsi2S
	TChain *F_DecayTree_P = new TChain("tuple1/DecayTree");
        TChain *F_MCDecayTree_P = new TChain("mct/mct");
        for (int i = 0; i <= 100; i++) 
        {
                F_DecayTree_P -> Add(Form("../../1_Rootfile/MC/MagDown/Psi2S/%d/output/Tuple.root",i));
                F_MCDecayTree_P -> Add(Form("../../1_Rootfile/MC/MagDown/Psi2S/%d/output/Tuple.root",i));
                F_DecayTree_P -> Add(Form("../../1_Rootfile/MC/MagUp/Psi2S/%d/output/Tuple.root",i));
                F_MCDecayTree_P -> Add(Form("../../1_Rootfile/MC/MagUp/Psi2S/%d/output/Tuple.root",i));
        }
	double mJ, J, mP ,P;
	double tmJ, tJ, tmP, tP;
	mJ = F_MCDecayTree_J->GetEntries("nPVs==1");
	tmJ = F_MCDecayTree_J->GetEntries();
	J = F_DecayTree_J->GetEntries("nPVs==1");
	tJ = F_DecayTree_J->GetEntries();
	mP = F_MCDecayTree_P->GetEntries("nPVs==1");
        tmP = F_MCDecayTree_P->GetEntries();
        P = F_DecayTree_P->GetEntries("nPVs==1");
        tP = F_DecayTree_P->GetEntries();
	cout << "Ratio of nPVs=1 for Jpsi(DecayTree) is: " << J/tJ << endl;
	cout << "Ratio of nPVs=1 for Jpsi(MCDecayTree) is: " << mJ/tmJ << endl;
	cout << "Ratio of nPVs=1 for Psi2S(DecayTree) is: " << P/tP << endl;
        cout << "Ratio of nPVs=1 for Psi2S(MCDecayTree) is: " << mP/tmP << endl;
	return 0;
}

