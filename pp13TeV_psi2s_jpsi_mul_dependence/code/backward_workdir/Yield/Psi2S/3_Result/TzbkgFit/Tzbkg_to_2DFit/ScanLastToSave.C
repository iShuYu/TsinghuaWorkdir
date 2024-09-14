#include <string.h>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	ifstream fin(argv[1], std::ios::ate);
	if(!fin)
	{
		cerr<<"打开日志文件失败！";
		return -1;
	}
	fin.seekg(-2, fin.cur);
	int lineCount = 17;
	for(int i = 0; i < lineCount; i++)
	{
		while( fin.peek() != fin.widen('\n') )
		{
			fin.seekg(-1, fin.cur );
		}
		fin.seekg(-1, fin.cur);
	}
	fin.seekg(2,fin.cur);
	ofstream result(argv[2]);
	std::string line;
	string fill;
	while(fin >> line)
	{
		if(line=="beta")
		{
			result << line << endl;
			fin >> line;
                        result << line << endl;
                        fin >> line;
                        result << line << endl;
                }
		if(line=="bias")
		{
			result << line << endl;	
			fin >> line;
			result << line << endl;
			fin >> line;
                        result << line << endl;
		}
		if(line=="f1")
                {
			result << line << endl;
                        fin >> line;
                        result << line << endl;
                        fin >> line;
                        result << line << endl;
                }
                if(line=="f2")
                {
			result << line << endl;
                        fin >> line;
                        result << line << endl;
                        fin >> line;
                        result << line << endl;
                }
                if(line=="f3")
                {
                	result << line << endl; 
		       	fin >> line;
                        result << line << endl;
                        fin >> line;
                        result << line << endl;
                }
                if(line=="f4")
                {
			result << line << endl;
                        fin >> line;
                        result << line << endl;
                        fin >> line;
                        result << line << endl;
                }
                if(line=="sigma1")
                {
			result << line << endl;
                        fin >> line;
                        result << line << endl;
                        fin >> line;
                        result << line << endl;
                }
		if(line=="sigma2")
                {
                        result << line << endl;
                        fin >> line;
                        result << line << endl;
                        fin >> line;
                        result << line << endl;
                }
                if(line=="tau1")
                {
			result << line << endl;
                        fin >> line;
                        result << line << endl;
                        fin >> line;
                        result << line << endl;
                }
                if(line=="tau2")
                {
			result << line << endl;
                        fin >> line;
                        result << line << endl;
                        fin >> line;
                        result << line << endl;
                }
                if(line=="tau3")
                {
			result << line << endl;
                        fin >> line;
                        result << line << endl;
                        fin >> line;
                        result << line << endl;
                }
                if(line=="tau4")
                {
			result << line << endl;
                        fin >> line;
                        result << line << endl;
                        fin >> line;
                        result << line << endl;
                }		
	}
	fin.clear();
	fin.close();
	return 0;
}
