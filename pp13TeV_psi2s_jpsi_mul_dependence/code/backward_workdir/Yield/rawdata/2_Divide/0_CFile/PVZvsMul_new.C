#include "/nishome/kangye/disk402_ppAnalysis/workdir/Yield/Jpsi/0_CFile/header/lhcbStyle.h"
void PVZvsMul_new()
{
	setLHCbStyle();
	int color[10]={1,2,3,4,6,7,8,28,42,46};
	int d[11]={-180,-120,-90,-60,-30,0,30,60,90,120,180};
	//TChain
	TChain *F_inJ = new TChain("DecayTree");
	TChain *F_inP = new TChain("DecayTree");
	TChain *Jcut = new TChain("DecayTree");
        TChain *Pcut = new TChain("DecayTree");
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=3;j++)
		{
			for(int k=1;k<=5;k++)
			{
				Jcut -> Add(Form("../2_AfterDivide/data/Jpsi/n%dy%dpt%d.root",i,j,k));
				Pcut -> Add(Form("../2_AfterDivide/data/Psi2S/n%dy%dpt%d.root",i,j,k));
				//Jcut -> Add(Form("../../../Jpsi/2_Rootfile/Data_after_cut/n%dy%dpt%d.root",i,j,k));
				//Pcut -> Add(Form("../../../Psi2S/2_Rootfile/Data_after_cut/n%dy%dpt%d.root",i,j,k));
			}
		}
	}
	//plot	
	TCanvas *can3=new TCanvas("can3","can3",800,600);
        TLegend *leg3 = new TLegend(0.55, 0.4, 0.90, 0.90);
        leg3->SetTextFont(132);
        leg3->SetBorderSize(2);
        leg3->SetTextSize(0.035);
        for(int i=0; i<10; i++)
        {
                TH1F *hist=new TH1F(Form("hist%d",i),"J/#psi, nPV=1",30,0,120);
                Jcut->Draw(Form("psi_nBackTracks>>hist%d",i),Form("psi_OWNPV_Z>=%d && psi_OWNPV_Z<=%d && nPV==1",d[i],d[i+1]),"same");
                hist->Scale(1.0/hist->Integral());
                hist->SetLineColor(color[i]);
		hist->SetMarkerColor(color[i]);
		hist->GetXaxis()->SetTitle("#font[12]{N}^{PV}_{bwd}");
                hist->GetYaxis()->SetTitle("Normalized");
                hist->GetXaxis()->SetTitleSize(0.06);
		hist->GetYaxis()->SetTitleSize(0.06);
		hist->GetYaxis()->SetRangeUser(0,1.1);

		//hist->GetXaxis()->SetTitleOffset(0.18);
                //hist->GetYaxis()->SetTitleOffset(0.18);
		hist->SetStats(0);
                hist->Draw("same");
                leg3->AddEntry(Form("hist%d",i),Form("%d < #font[12]{z}_{PV} < %d mm",d[i],d[i+1]));
        }
        leg3->Draw();
        can3->SaveAs("../3_result/PVZ_n/J_cutnew.pdf");
        can3->Close();

	TCanvas *can4=new TCanvas("can4","can4",800,600);
        TLegend *leg4 = new TLegend(0.55, 0.4, 0.90, 0.90);
        leg4->SetTextFont(132);
        leg4->SetBorderSize(2);
        leg4->SetTextSize(0.035);
        for(int i=0; i<10; i++)
        {
                TH1F *hist=new TH1F(Form("hist%d",i),"#psi(2S), nPV=1",30,0,120);
                Pcut->Draw(Form("psi_nBackTracks>>hist%d",i),Form("psi_OWNPV_Z>=%d && psi_OWNPV_Z<=%d && nPV==1",d[i],d[i+1]),"same");
                hist->Scale(1.0/hist->Integral());
                hist->SetLineColor(color[i]);
		hist->SetMarkerColor(color[i]);
                hist->SetStats(0);
		hist->GetXaxis()->SetTitle("#font[12]{N}^{PV}_{bwd}");
                hist->GetYaxis()->SetTitle("Normalized");
		hist->GetXaxis()->SetTitleSize(0.06);
                hist->GetYaxis()->SetTitleSize(0.06);
                hist->GetYaxis()->SetRangeUser(0,1.1);
                //hist->GetYaxis()->SetTitleOffset(0.18);
                hist->Draw("same");
                leg4->AddEntry(Form("hist%d",i),Form("%d < #font[12]{z}_{PV} < %d mm",d[i],d[i+1]));
        }
        leg4->Draw();
        can4->SaveAs("../3_result/PVZ_n/P_cutnew.pdf");
        can4->Close();
}
