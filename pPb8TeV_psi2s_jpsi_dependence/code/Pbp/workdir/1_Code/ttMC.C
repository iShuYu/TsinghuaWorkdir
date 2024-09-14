#define MCDecayTree_Cut_cxx
#define mct_cxx
#include <TH1.h>
#include <TH2.h>
#include <TH3F.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <TAxis.h>
#include <TROOT.h>
#include <TRandom3.h>
#include "0_header/MCDecayTree_Cut.h"
#include "0_header/mct.h"
using namespace std;
int main(int argc, char *argv[])
{
	double tMCJ, ttMCJ, tMCP, ttMCP;
	double tDTJ, ttDTJ, tDTP, ttDTP;
        TChain *MCJ = new TChain("DecayTree");
        MCJ -> Add("../0_File/MC/Cut/Jpsi.root");
	MCDecayTree_Cut tj(MCJ);
	int NJ = MCJ->GetEntries();
	TChain *MCP = new TChain("DecayTree");
        MCP -> Add("../0_File/MC/Cut/Psi2S.root");
        MCDecayTree_Cut tp(MCP);
        int NP = MCP->GetEntries();
	tMCJ = 0;
	ttMCJ = 0;
	tMCP = 0;
	ttMCP = 0;
	for(int i=0; i<NJ; i++)
	{
		MCJ -> GetEntry(i);
		if (!( tj.mup_isMuon == 1 ))  continue;
                if (!( tj.mum_isMuon == 1 ))  continue;
                if (!( tj.mum_ProbNNmu > 0.9 ))  continue;
                if (!( tj.mup_ProbNNmu > 0.9 ))  continue;
		if (!( tj.psi_Hlt1DiMuonHighMassDecision_TOS==1 )) continue;
		if(!( tj.psi_L0Global_TIS==1 )) continue;
		tMCJ = tMCJ+1;
		if(!( tj.psi_L0MuonDecision_TOS==1 )) continue;
		ttMCJ = ttMCJ+1;
	}
	for(int i=0; i<NP; i++)
        {
		MCP -> GetEntry(i);
                if (!( tp.mup_isMuon == 1 ))  continue;
                if (!( tp.mum_isMuon == 1 ))  continue;
                if (!( tp.mum_ProbNNmu > 0.9 ))  continue;
                if (!( tp.mup_ProbNNmu > 0.9 ))  continue;
                if (!( tp.psi_Hlt1DiMuonHighMassDecision_TOS==1 )) continue;
                if(!( tp.psi_L0Global_TIS==1 )) continue;
                tMCP = tMCP+1;
                if(!( tp.psi_L0MuonDecision_TOS==1 )) continue;
                ttMCP = ttMCP+1;
        }
	ifstream tis("../4_Result/CBFit/tis.txt");
	ifstream tistos("../4_Result/CBFit/tistos.txt");
	double tDTJerr, ttDTJerr, tDTPerr, ttDTPerr;
	tis >> tDTJ >> tDTP >> tDTJerr >> tDTPerr;
	tistos >> ttDTJ >> ttDTP >> ttDTJerr >> ttDTPerr;
	double rMC = (ttMCJ/tMCJ)/(ttMCP/tMCP);
	double rDT = (ttDTJ/tDTJ)/(ttDTP/tDTP);
	double error = abs(rMC/rDT-1);
	double stats = sqrt(tDTJerr*tDTJerr/tDTJ/tDTJ+tDTPerr*tDTPerr/tDTP/tDTP);
	ofstream out("../4_Result/SysErr/TISTOS.txt");
	out << stats << endl;
	out << error << endl;
	return 0;
}
