#include "/nishome/kangye/disk402_ppAnalysis/workdir/Yield/Jpsi/0_CFile/header/lhcbStyle.h"
void PVZvsMul()
{
	setLHCbStyle();
	int color[10]={1,2,3,4,6,7,8,28,42,46};
	//TChain
	TChain *F_inJ = new TChain("DecayTree");
	TChain *F_inP = new TChain("DecayTree");
	F_inJ -> Add("../../Workdir/0_File/Data/RAW/Jpsi.root");
	F_inP -> Add("../../Workdir/0_File/Data/RAW/Psi2S.root");
	//plot
	TCanvas *can1=new TCanvas("can1","can1",800,600);
	TLegend *leg1 = new TLegend(0.60, 0.4, 0.90, 0.90);
        leg1->SetTextFont(132);
        leg1->SetBorderSize(2);
        leg1->SetTextSize(0.035);
	int d[11]={-180,-120,-90,-60,-30,0,30,60,90,120,180};
	for(int i=0; i<10; i++)
	{
		TH1F *histJ=new TH1F(Form("histJ%d",i),"J/#psi, nPV=1",30,0,150);
		F_inJ->Draw(Form("psi_nBackTracks>>histJ%d",i),Form("psi_OWNPV_Z>=%d && psi_OWNPV_Z<=%d && nPV==1",d[i],d[i+1]),"same");
		histJ->Scale(1.0/histJ->Integral());
		histJ->SetLineColor(color[i]);
		histJ->SetMarkerColor(color[i]);
		histJ->SetStats(0);
		histJ->GetXaxis()->SetTitle("#font[12]{N}^{PV}_{fwd}");
                histJ->GetYaxis()->SetTitle("Normalized");
                histJ->GetXaxis()->SetTitleSize(0.06);
                histJ->GetYaxis()->SetTitleSize(0.06);

		histJ->Draw("same");
		leg1->AddEntry(Form("histJ%d",i),Form("%d < #font[12]{z}_{PV} < %d mm",d[i],d[i+1]));
	}
	leg1->Draw();
	can1->SaveAs("../5_Plots/PVZvsMul/Jpsi.pdf");
	can1->Close();

	TCanvas *can2=new TCanvas("can2","can2",800,600);
        TLegend *leg2 = new TLegend(0.60, 0.4, 0.90, 0.90);
        leg2->SetTextFont(132);
        leg2->SetBorderSize(2);
        leg2->SetTextSize(0.035);
        for(int i=0; i<10; i++)
        {
                TH1F *histP=new TH1F(Form("histP%d",i),"PVNTRACKS-PVZ (#psi(2S), nPV=1, rawdata)",30,0,150);
                F_inP->Draw(Form("psi_nBackTracks>>histP%d",i),Form("psi_OWNPV_Z>=%d && psi_OWNPV_Z<=%d && nPV==1",d[i],d[i+1]),"same");
                histP->Scale(1.0/histP->Integral());
                histP->SetLineColor(color[i]);
		histP->SetMarkerColor(color[i]);
                histP->SetStats(0);
                histP->GetXaxis()->SetTitle("#font[12]{N}^{PV}_{fwd}");
                histP->GetYaxis()->SetTitle("Normalized");
                histP->GetXaxis()->SetTitleSize(0.06);
                histP->GetYaxis()->SetTitleSize(0.06);

		histP->Draw("same");
                leg2->AddEntry(Form("histP%d",i),Form("%d < #font[12]{z}_{PV} < %d mm",d[i],d[i+1]));
        }
        leg2->Draw();
	can2->SaveAs("../5_Plots/PVZvsMul/Psi2S.pdf");
	can2->Close();
}
