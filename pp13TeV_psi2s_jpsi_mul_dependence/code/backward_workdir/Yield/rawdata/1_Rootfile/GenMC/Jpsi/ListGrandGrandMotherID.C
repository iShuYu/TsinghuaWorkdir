#define MCDecayTree_cxx
#include "MCDecayTree.h"
#include <iostream>
using namespace std;
int main()
{
	TChain *t = new TChain("MCDecayTreeTuple/MCDecayTree");
	t->Add("./Tuple.root");
	int N = t->GetEntries();
	MCDecayTree tree(t);
	int count = 1;
	vector<double> MID;
	t->GetEntry(0);
	MID.push_back(abs(tree.psi_MC_GD_GD_MOTHER_ID));
	cout << "total Entries = " << N << endl;
	//cout << MID[0] << endl;
	for(int i=1; i<=N; i++)
	{
		t->GetEntry(i);
		//cout << "count =" << count << endl;
		int M = count;
		int flag = 0;
		for(int j=0; j<M; j++)
		{
			//cout << tree.psi_MC_GD_GD_MOTHER_ID << endl;
			if(abs(tree.psi_MC_GD_GD_MOTHER_ID)!=MID[j])
			{
				flag = flag + 1;
				//MID.push_back(tree.psi_MC_GD_GD_MOTHER_ID);
			}
		}
		if(flag == count)
		{
			count = count+1;
			MID.push_back(abs(tree.psi_MC_GD_GD_MOTHER_ID));
		}
	}
	for(int i=0;i<count;i++)
	{
		cout<< "Mother id " << i << " = " << MID[i] << endl;
	}
	return 0;
}

