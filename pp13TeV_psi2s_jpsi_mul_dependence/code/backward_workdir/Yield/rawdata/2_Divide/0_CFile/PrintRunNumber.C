#define DecayTree_cxx
#include "DecayTree.h"
#include <math.h>
#include <TStyle.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <TChain.h>
//输出直接放到了对应的root文件夹下使用
using namespace std;
int main(int argc, char* argv[])
{
	TChain *C = new TChain("DecayTree");
	for(int i=1;i<=7;i++)
	{
		C->Add(Form("Jpsi16MagDown%d.root",i));
	}
	DecayTree T(C);
	long N = C->GetEntries();
	C -> GetEntry(0);
	vector<int> RunNo;
	cout << T.runNumber << endl;
	RunNo.push_back(T.runNumber);
	int L = 1;
	for(int i=1;i<N;i++)
	{
		C ->GetEntry(i);
		for(int l=0;l<L;l++)
		{
			int flag = 0;
			if(T.runNumber!=RunNo[l])
			{
				flag = flag+1;
			}
			if(flag==L)
			{
				L = L+1;
				RunNo.push_back(T.runNumber);
			}
		}
	}
	ofstream RunNum("./runNoJD.txt");
	for(int l=0;l<L;l++)
	{
		RunNum << RunNo[l] << endl;
	}
	RunNum.close();
	return 0;
}
