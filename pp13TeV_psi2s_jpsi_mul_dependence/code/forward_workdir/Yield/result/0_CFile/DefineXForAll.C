#define DecayTree_cxx
#include "/nishome/kangye/disk402_ppAnalysis/workdir/Yield/result/0_CFile/DecayTree.h"
#include <TStyle.h>
#include <TH1.h>
#include <TH2D.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
        TH1::SetDefaultSumw2();
	//input binning scheme
	double y_lo, y_hi, pt_lo, pt_hi;
	int flagVar; //for three scheme
	int flagY;
	int flagPT;
	int flagpb;
	sscanf(argv[1],"%lf",&y_lo);
	sscanf(argv[2],"%lf",&y_hi);
	sscanf(argv[3],"%lf",&pt_lo);
	sscanf(argv[4],"%lf",&pt_hi);
	sscanf(argv[5],"%d",&flagVar);
	sscanf(argv[6],"%d",&flagY);
        sscanf(argv[7],"%d",&flagPT);
	sscanf(argv[8],"%d",&flagpb);
	TFile *input = TFile::Open("../../../../workdir/Yield/Jpsi/3_Result/RegenVar/newVar.root");
	TTree *DT = (TTree*)input->Get("DecayTree");
	DecayTree t(DT);
	int N = DT->GetEntries();
	cout << N << endl;
	TH1D *TN[5];
	TN[0] = new TH1D("TN0","TN0", 200, 0, 200);
        TN[1] = new TH1D("TN1","TN1", 200, 0, 200);
        TN[2] = new TH1D("TN2","TN2", 200, 0, 200);
        TN[3] = new TH1D("TN3","TN3", 200, 0, 200);
        TN[4] = new TH1D("TN4","TN4", 200, 0, 200);
	TH1D *TNcor[5];
	TNcor[0] = new TH1D("TNcor0","TNcor0", 200, 0, 200);
        TNcor[1] = new TH1D("TNcor1","TNcor1", 200, 0, 200);
        TNcor[2] = new TH1D("TNcor2","TNcor2", 200, 0, 200);
        TNcor[3] = new TH1D("TNcor3","TNcor3", 200, 0, 200);
        TNcor[4] = new TH1D("TNcor4","TNcor4", 200, 0, 200);
	int Bin[3][6] = {{4,20,45,70,95,200},{0,12,24,36,48,130},{0,8,15,22,30,80}};
	double mean, meancor;
	for(int i=0;i<N;i++)
	{
		DT->GetEntry(i);
		if(t.psi_PT<pt_lo||t.psi_PT>pt_hi) continue;
		if(t.psi_Y<y_lo||t.psi_Y>y_hi) continue;
		double MUL = 0;
		double MULcor = 0;
		double w = 0;
		int type = 0;
		if(flagpb==1) w = t.prompt_sw;
		if(flagpb==2) w = t.fromb_sw;
		if(flagVar==1)
		{
			if(t.PVZ[0]<-60) continue;
			if(t.PVZ[0]>180) continue;
			mean = 26.74;
			meancor = 27.58;
			type = 0;
			MUL = t.PVNTRACKS[0];
			MULcor = t.PVNcor;
		}
		if(flagVar==2)
                {
			if(t.PVZ[0]<-180) continue;
                        if(t.PVZ[0]>180) continue;
			mean = 16.53;
			meancor = 18.22;
			type = 1;
                        MUL = t.psi_nForWardTracks;
                        MULcor = t.nFcor;
                }
		if(flagVar==3)
                {
			if(t.PVZ[0]<-30) continue;
                        if(t.PVZ[0]>180) continue;
			type = 2;
			mean = 11.26;
			meancor = 11.98;
                        MUL = t.psi_nBackTracks;
                        MULcor = t.nBcor;
                }
		/*if(flagVar=4)
		{
			if(t.PVZ[0]<-30) continue;
                        if(t.PVZ[0]>180) continue;
			type = 2;
			mean = 16.53;
                        meancor = 18.22;
			MUL = t.psi_nForWardTracks;
                        MULcor = t.nFcor;
		}*/
		//cout << MUL << endl;
		//if(flagVar!=4){
		if(MUL>=Bin[type][0]&&MUL<Bin[type][1]) {TN[0]->Fill(MUL,w); TNcor[0]->Fill(MULcor,w);}
		if(MUL>=Bin[type][1]&&MUL<Bin[type][2]) {TN[1]->Fill(MUL,w); TNcor[1]->Fill(MULcor,w);}
		if(MUL>=Bin[type][2]&&MUL<Bin[type][3]) {TN[2]->Fill(MUL,w); TNcor[2]->Fill(MULcor,w);}
		if(MUL>=Bin[type][3]&&MUL<Bin[type][4]) {TN[3]->Fill(MUL,w); TNcor[3]->Fill(MULcor,w);}
		if(MUL>=Bin[type][4]&&MUL<Bin[type][5]) {TN[4]->Fill(MUL,w); TNcor[4]->Fill(MULcor,w);}
		//}
		//else
		/*{
			double MUL1 = t.psi_nBackTracks;
			if(MUL1>=Bin[type][0]&&MUL1<Bin[type][1]) {TN[0]->Fill(MUL,w); TNcor[0]->Fill(MULcor,w);}
        	        if(MUL1>=Bin[type][1]&&MUL1<Bin[type][2]) {TN[1]->Fill(MUL,w); TNcor[1]->Fill(MULcor,w);}
               		if(MUL1>=Bin[type][2]&&MUL1<Bin[type][3]) {TN[2]->Fill(MUL,w); TNcor[2]->Fill(MULcor,w);}
                	if(MUL1>=Bin[type][3]&&MUL1<Bin[type][4]) {TN[3]->Fill(MUL,w); TNcor[3]->Fill(MULcor,w);}
                	if(MUL1>=Bin[type][4]&&MUL1<Bin[type][5]) {TN[4]->Fill(MUL,w); TNcor[4]->Fill(MULcor,w);}

		}*/
	}
	string path = "../../../../workdir/Yield/result/3_Result/promptBin.txt";
	if(flagPT==0&&flagpb==1&&flagY==0&&flagVar==1) path = "../../../../workdir/Yield/result/3_Result/promptBin.txt";
	if(flagPT==0&&flagpb==2&&flagY==0&&flagVar==1) path = "../../../../workdir/Yield/result/3_Result/frombBin.txt";
	if(flagPT!=0&&flagpb==1&&flagY==0&&flagVar==1) path = Form("../../../../workdir/Yield/result/3_Result/promptBinPT%d.txt",flagPT);
        if(flagPT!=0&&flagpb==2&&flagY==0&&flagVar==1) path = Form("../../../../workdir/Yield/result/3_Result/frombBinPT%d.txt",flagPT);
	if(flagPT==0&&flagpb==1&&flagY!=0&&flagVar==1) path = Form("../../../../workdir/Yield/result/3_Result/promptBinY%d.txt",flagY);
	if(flagPT==0&&flagpb==2&&flagY!=0&&flagVar==1) path = Form("../../../../workdir/Yield/result/3_Result/frombBinY%d.txt",flagY);
	
	
	if(flagPT==0&&flagpb==1&&flagY==0&&flagVar==2) path = "../../../../ForWorkdir/Yield/result/3_Result/promptBin.txt";
        if(flagPT==0&&flagpb==2&&flagY==0&&flagVar==2) path = "../../../../ForWorkdir/Yield/result/3_Result/frombBin.txt";
        if(flagPT!=0&&flagpb==1&&flagY==0&&flagVar==2) path = Form("../../../../ForWorkdir/Yield/result/3_Result/promptBinPT%d.txt",flagPT);
        if(flagPT!=0&&flagpb==2&&flagY==0&&flagVar==2) path = Form("../../../../ForWorkdir/Yield/result/3_Result/frombBinPT%d.txt",flagPT);
        if(flagPT==0&&flagpb==1&&flagY!=0&&flagVar==2) path = Form("../../../../ForWorkdir/Yield/result/3_Result/promptBinY%d.txt",flagY);
        if(flagPT==0&&flagpb==2&&flagY!=0&&flagVar==2) path = Form("../../../../ForWorkdir/Yield/result/3_Result/frombBinY%d.txt",flagY);
	
	
	if(flagPT==0&&flagpb==1&&flagY==0&&flagVar==3) path = "../../../../BackWorkdir/Yield/result/3_Result/promptBin.txt";
        if(flagPT==0&&flagpb==2&&flagY==0&&flagVar==3) path = "../../../../BackWorkdir/Yield/result/3_Result/frombBin.txt";
        if(flagPT!=0&&flagpb==1&&flagY==0&&flagVar==3) path = Form("../../../../BackWorkdir/Yield/result/3_Result/promptBinPT%d.txt",flagPT);
        if(flagPT!=0&&flagpb==2&&flagY==0&&flagVar==3) path = Form("../../../../BackWorkdir/Yield/result/3_Result/frombBinPT%d.txt",flagPT);
        if(flagPT==0&&flagpb==1&&flagY!=0&&flagVar==3) path = Form("../../../../BackWorkdir/Yield/result/3_Result/promptBinY%d.txt",flagY);
        if(flagPT==0&&flagpb==2&&flagY!=0&&flagVar==3) path = Form("../../../../BackWorkdir/Yield/result/3_Result/frombBinY%d.txt",flagY);
	
	
	string patherr = "../../../../workdir/Yield/result/3_Result/promptBinErr.txt";
        if(flagPT==0&&flagpb==1&&flagY==0&&flagVar==1) patherr = "../../../../workdir/Yield/result/3_Result/promptBinErr.txt";
        if(flagPT==0&&flagpb==2&&flagY==0&&flagVar==1) patherr = "../../../../workdir/Yield/result/3_Result/frombBinErr.txt";
        if(flagPT!=0&&flagpb==1&&flagY==0&&flagVar==1) patherr = Form("../../../../workdir/Yield/result/3_Result/promptBinPTErr%d.txt",flagPT);
        if(flagPT!=0&&flagpb==2&&flagY==0&&flagVar==1) patherr = Form("../../../../workdir/Yield/result/3_Result/frombBinPTErr%d.txt",flagPT);
        if(flagPT==0&&flagpb==1&&flagY!=0&&flagVar==1) patherr = Form("../../../../workdir/Yield/result/3_Result/promptBinYErr%d.txt",flagY);
        if(flagPT==0&&flagpb==2&&flagY!=0&&flagVar==1) patherr = Form("../../../../workdir/Yield/result/3_Result/frombBinYErr%d.txt",flagY);
        
	
	if(flagPT==0&&flagpb==1&&flagY==0&&flagVar==2) patherr = "../../../../ForWorkdir/Yield/result/3_Result/promptBinErr.txt";
        if(flagPT==0&&flagpb==2&&flagY==0&&flagVar==2) patherr = "../../../../ForWorkdir/Yield/result/3_Result/frombBinErr.txt";
        if(flagPT!=0&&flagpb==1&&flagY==0&&flagVar==2) patherr = Form("../../../../ForWorkdir/Yield/result/3_Result/promptBinPTErr%d.txt",flagPT);
        if(flagPT!=0&&flagpb==2&&flagY==0&&flagVar==2) patherr = Form("../../../../ForWorkdir/Yield/result/3_Result/frombBinPTErr%d.txt",flagPT);
        if(flagPT==0&&flagpb==1&&flagY!=0&&flagVar==2) patherr = Form("../../../../ForWorkdir/Yield/result/3_Result/promptBinYErr%d.txt",flagY);
        if(flagPT==0&&flagpb==2&&flagY!=0&&flagVar==2) patherr = Form("../../../../ForWorkdir/Yield/result/3_Result/frombBinYErr%d.txt",flagY);
        
	
	if(flagPT==0&&flagpb==1&&flagY==0&&flagVar==3) patherr = "../../../../BackWorkdir/Yield/result/3_Result/promptBinErr.txt";
        if(flagPT==0&&flagpb==2&&flagY==0&&flagVar==3) patherr = "../../../../BackWorkdir/Yield/result/3_Result/frombBinErr.txt";
        if(flagPT!=0&&flagpb==1&&flagY==0&&flagVar==3) patherr = Form("../../../../BackWorkdir/Yield/result/3_Result/promptBinPTErr%d.txt",flagPT);
        if(flagPT!=0&&flagpb==2&&flagY==0&&flagVar==3) patherr = Form("../../../../BackWorkdir/Yield/result/3_Result/frombBinPTErr%d.txt",flagPT);
        if(flagPT==0&&flagpb==1&&flagY!=0&&flagVar==3) patherr = Form("../../../../BackWorkdir/Yield/result/3_Result/promptBinYErr%d.txt",flagY);
        if(flagPT==0&&flagpb==2&&flagY!=0&&flagVar==3) patherr = Form("../../../../BackWorkdir/Yield/result/3_Result/frombBinYErr%d.txt",flagY);
	/*if(flagVar==4)
	{
		patherr = "../../../../BackWorkdir/Yield/result/3_Result/XBackInForwardPrompterr.txt";
		path = "../../../../BackWorkdir/Yield/result/3_Result/XBackInForwardPrompt.txt";		
	}*/			
	cout << path << endl;
	cout << patherr << endl;	
	ofstream txt(path);
	ofstream txterr(patherr);
	for(int i=0;i<5;i++)
	{
		txt << TNcor[i]->GetMean()/mean << endl;
		//txterr << abs(TN[i]->GetMean()/meancor-TNcor[i]->GetMean()/meancor) << endl;
		txterr << 0.03 << endl;
	}

	txt.close();
	txterr.close();
	return 0;
}
	
