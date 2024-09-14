void PTvsSPDHits()
{
	//TChain
	TChain *F_inJ = new TChain("tuple2/DecayTree");
	//TChain *F_inP = new TChain("DecayTree");
	//TChain *Jcut = new TChain("DecayTree");
        //TChain *Pcut = new TChain("DecayTree");
	for(int i=1;i<=100;i++)
	{
			F_inJ -> Add(Form("../../1_Rootfile/data/MagUp/60/%d/output/Tuple.root",i));
				//F_inP -> Add(Form("../2_AfterDivide/data/Psi2S/SPD%dy%dpt%d.root",i,j,k));
				//Jcut -> Add(Form("../../../Jpsi/2_Rootfile/Data_after_cut/SPD%dy%dpt%d.root",i,j,k));
				//Pcut -> Add(Form("../../../Psi2S/2_Rootfile/Data_after_cut/SPD%dy%dpt%d.root",i,j,k))
	}
	//plot
	TCanvas *can1=new TCanvas("can1","can1",800,600);
	TLegend *leg1 = new TLegend(0.7, 0.6, 0.90, 0.90);
        leg1->SetTextFont(132);
        leg1->SetBorderSize(2);
        leg1->SetTextSize(0.02);
	for(int i=1; i<=5; i++)
	{
		TH1F *hist=new TH1F(Form("hist%d",i),"nSPDHits-PT (J/#psi, nPV=1, rawdata)",100,0,1200);
		int d=2000*i;
		F_inJ->Draw(Form("nSPDHits>>hist%d",i),Form("psi_PT>=%d && psi_PT<=%d && nPV==1",d,d+2000),"same");
		hist->Scale(1.0/hist->Integral());
		hist->SetLineColor(i+1);
		//else hist->SetLineColor(15);
		hist->SetStats(0);
		hist->Draw("same");
		hist->GetYaxis()->SetRangeUser(0.,0.06);
		leg1->AddEntry(Form("hist%d",i),Form("PT in %d to %d",d,d+2000));
	}
	leg1->Draw();
	can1->SaveAs("../3_result/PT_SPD/Psi2S_rawdata.pdf");
	can1->Close();

}
