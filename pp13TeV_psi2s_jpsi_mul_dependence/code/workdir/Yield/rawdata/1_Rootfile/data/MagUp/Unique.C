#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
	int Num;
	sscanf(argv[1],"%d",&Num);
	ifstream in(argv[2]);
	int List[Num];
	ofstream out(argv[3]);
	for(int i=0;i<Num;i++)
	{
		in >> List[i];
		int flag = 0;
		for(int j=0;j<i;j++)
		{
			int Next;
			if(List[i]!=List[j])
			{
				flag = flag+1;
			}
		}
		if(flag == i)
		{
			out << List[i] << endl;
		}
	}
	return 0;
}

