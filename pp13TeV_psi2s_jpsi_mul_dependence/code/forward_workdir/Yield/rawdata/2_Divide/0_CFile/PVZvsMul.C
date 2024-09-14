void PVZvsMul()
{
	int color[10]={1,2,3,4,6,7,8,28,42,46};
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
				F_inJ -> Add(Form("../2_AfterDivide/data/Jpsi/n%dy%dpt%d.root",i,j,k));
				F_inP -> Add(Form("../2_AfterDivide/data/Psi2S/n%dy%dpt%d.root",i,j,k));
				Jcut -> Add(Form("../../../Jpsi/2_Rootfile/Data_after_cut/n%dy%dpt%d.root",i,j,k));
				Pcut -> Add(Form("../../../Psi2S/2_Rootfile/Data_after_cut/n%dy%dpt%d.root",i,j,k));
			}
		}
	}
	//plot
	TCanvas *can1=new TCanvas("can1","can1",800,600);
	TLegend *leg1 = new TLegend(0.7, 0.6, 0.90, 0.90);
        leg1->SetTextFont(132);
        leg1->SetBorderSize(2);
        leg1->SetTextSize(0.02);
	int d[11]={-180,-120,-90,-60,-30,0,30,60,90,120,180};
	TH1F *hist;
	for(int i=0; i<10; i++)
	{
		hist = new TH1F(Form("hist%d",i),"J/#psi, nPV=1",30,0,150);
		F_inJ->Draw(Form("psi_nForWardTracks>>hist%d",i),Form("psi_OWNPV_Z>=%d && psi_OWNPV_Z<=%d && nPV==1",d[i],d[i+1]),"same");
		hist->Scale(1.0/hist->Integral());
		hist->SetLineColor(color[i]);
		hist->SetStats(0);
		hist->GetXaxis()->SetTitle("nForwardTracks");
                hist->GetYaxis()->SetTitle("Normalized");
		hist->Draw("same");
		leg1->AddEntry(Form("hist%d",i),Form("PVZ in %d to %d",d[i],d[i+1]));
		//delete hist;
		//hist = NULL;
	}
	leg1->Draw();
	can1->SaveAs("../3_result/PVZ_n/Jpsi_rawdata.pdf");
	can1->Close();

	TCanvas *can2=new TCanvas("can2","can2",800,600);
        TLegend *leg2 = new TLegend(0.7, 0.6, 0.90, 0.90);
        leg2->SetTextFont(132);
        leg2->SetBorderSize(2);
        leg2->SetTextSize(0.02);
        for(int i=0; i<10; i++)
        {
                hist = new TH1F(Form("hist%d",i),"#psi(2S), nPV=1",30,0,150);
                F_inP->Draw(Form("psi_nForWardTracks>>hist%d",i),Form("psi_OWNPV_Z>=%d && psi_OWNPV_Z<=%d && nPV==1",d[i],d[i+1]),"same");
                hist->Scale(1.0/hist->Integral());
                hist->SetLineColor(color[i]);
                hist->SetStats(0);
		hist->GetXaxis()->SetTitle("nForwardTracks");
		hist->GetYaxis()->SetTitle("Normalized");
                hist->Draw("same");
                leg2->AddEntry(Form("hist%d",i),Form("PVZ in %d to %d",d[i],d[i+1]));
		//delete hist;
                //hist = NULL;
        }
        leg2->Draw();
	can2->SaveAs("../3_result/PVZ_n/Psi2S_rawdata.pdf");
	can2->Close();
	
	/*TCanvas *can3=new TCanvas("can3","can3",800,600);
        TLegend *leg3 = new TLegend(0.7, 0.6, 0.90, 0.90);
        leg3->SetTextFont(132);
        leg3->SetBorderSize(2);
        leg3->SetTextSize(0.02);
        for(int i=0; i<10; i++)
        {
                *hist=new TH1F(Form("hist%d",i),"J/#psi, nPV=1",30,0,90);
                Jcut->Draw(Form("psi_nForWardTracks>>hist%d",i),Form("psi_OWNPV_Z>=%d && psi_OWNPV_Z<=%d && nPV==1",d[i],d[i+1]),"same");
                hist->Scale(1.0/hist->Integral());
                hist->SetLineColor(color[i]);
                hist->GetXaxis()->SetTitle("nForwardTracks");
                hist->GetYaxis()->SetTitle("Normalized");
		hist->SetStats(0);
                hist->Draw("same");
                leg3->AddEntry(Form("hist%d",i),Form("PVZ in %d to %d",d[i],d[i+1]));
		delete hist;
                //hist = NULL;
        }
        leg3->Draw();
        can3->SaveAs("../3_result/PVZ_n/J_cut.pdf");
        can3->Close();

	TCanvas *can4=new TCanvas("can4","can4",800,600);
        TLegend *leg4 = new TLegend(0.7, 0.6, 0.90, 0.90);
        leg4->SetTextFont(132);
        leg4->SetBorderSize(2);
        leg4->SetTextSize(0.02);
        for(int i=0; i<10; i++)
        {
                TH1F *hist=new TH1F(Form("hist%d",i),"#psi(2S), nPV=1",30,0,90);
                Pcut->Draw(Form("psi_nForWardTracks>>hist%d",i),Form("psi_OWNPV_Z>=%d && psi_OWNPV_Z<=%d && nPV==1",d[i],d[i+1]),"same");
                hist->Scale(1.0/hist->Integral());
                hist->SetLineColor(color[i]);
                hist->GetXaxis()->SetTitle("nForwardTracks");
                hist->GetYaxis()->SetTitle("Normalized");
		hist->SetStats(0);
                hist->Draw("same");
                leg4->AddEntry(Form("hist%d",i),Form("PVZ in %d to %d",d[i],d[i+1]));
        	delete hist;
                //hist = NULL;
	}
        leg4->Draw();
        can4->SaveAs("../3_result/PVZ_n/P_cut.pdf");
        can4->Close();*/
}
