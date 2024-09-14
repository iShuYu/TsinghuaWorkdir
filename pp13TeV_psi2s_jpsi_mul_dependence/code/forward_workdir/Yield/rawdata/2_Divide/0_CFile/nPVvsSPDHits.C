void nPVvsSPDHits()
{
	//TChain
	TChain *F_inJ = new TChain("DecayTree");
	//TChain *F_inP = new TChain("DecayTree");
	//TChain *Jcut = new TChain("DecayTree");
        //TChain *Pcut = new TChain("DecayTree");
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=3;j++)
		{
			for(int k=1;k<=4;k++)
			{
				F_inJ -> Add(Form("../2_AfterDivide/data/Jpsi/SPD%dy%dpt%d.root",i,j,k));
				//F_inP -> Add(Form("../2_AfterDivide/data/Psi2S/SPD%dy%dpt%d.root",i,j,k));
				//Jcut -> Add(Form("../../../Jpsi/2_Rootfile/Data_after_cut/SPD%dy%dpt%d.root",i,j,k));
				//Pcut -> Add(Form("../../../Psi2S/2_Rootfile/Data_after_cut/SPD%dy%dpt%d.root",i,j,k));
			}
		}
	}
	//plot
	TCanvas *can1=new TCanvas("can1","can1",800,600);
	TLegend *leg1 = new TLegend(0.7, 0.6, 0.90, 0.90);
        leg1->SetTextFont(132);
        leg1->SetBorderSize(2);
        leg1->SetTextSize(0.02);
	for(int i=1; i<=5; i++)
	{
		TH1F *hist=new TH1F(Form("hist%d",i),Form("nPV = %d (J/#psi)",i),100,0,1200);
		F_inJ->Draw(Form("nSPDHits>>hist%d",i),Form("nPV==%d",i),"same");
		hist->Scale(1.0/hist->Integral());
		if(i!=9) hist->SetLineColor(i+1);
		else hist->SetLineColor(15);
		hist->SetStats(0);
		hist->Draw("same");
		leg1->AddEntry(Form("hist%d",i),Form("nPV = %d (J/#psi)",i));
	}
	leg1->Draw();
	can1->SaveAs("../3_result/PVZ_SPD/Jpsi_nPV_SPD.pdf");
	can1->Close();
}
