void draw_compare()
{
	TH1::SetDefaultSumw2();
	gStyle->SetPaintTextFormat("4.3f");
	double ptbin[13] = {2000,3000,4000,5000,6000,7000,8000,9000,10000,11000,12000,13000,14000};
	double ybin[6] = {2.0,2.5,3.0,3.5,4.0,4.5};
	ifstream R("./Result.txt");
	ifstream MR("./MyResult.txt");
	TH2D *DRp = new TH2D("DRp","result p",12,ptbin,5,ybin);
	TH2D *DMRp = new TH2D("DMRp","my result p",12,ptbin,5,ybin);
	TH2D *DRb = new TH2D("DRb","result b",12,ptbin,5,ybin);
        TH2D *DMRb = new TH2D("DMRb","my result b",12,ptbin,5,ybin);
	double RP[60],MRP[60],Rb[60],MRb[60],RPErr[60],MRPErr[60],RbErr[60],MRbErr[60];
	for(int i=0; i<60; i++)
	{
		R >> RP[i];
	}
	for(int i=0; i<60; i++)
        {
                R >> Rb[i];
        }
	for(int i=0; i<60; i++)
        {
                R >> RPErr[i];
        }
	for(int i=0; i<60; i++)
        {
                R >> RbErr[i];
        }
	for(int i=0; i<60; i++)
        {
		MR >> MRP[i];
		MR >> MRb[i];
		MR >> MRPErr[i];
                MR >> MRbErr[i];
        }
	for(int i=1; i<=12; i++)
	{
		for(int j=1; j<=5; j++)
		{
			DRp -> SetBinContent(i,j,RP[(j-1)*12+i-1]);
			DRp -> SetBinError(i,j,RPErr[(j-1)*12+i-1]);
			DRb -> SetBinContent(i,j,Rb[(j-1)*12+i-1]);
                        DRb -> SetBinError(i,j,RbErr[(j-1)*12+i-1]);
			DMRp -> SetBinContent(i,j,MRP[(j-1)*12+i-1]);
                        DMRp -> SetBinError(i,j,MRPErr[(j-1)*12+i-1]);
                        DMRb -> SetBinContent(i,j,MRb[(j-1)*12+i-1]);
                        DMRb -> SetBinError(i,j,MRbErr[(j-1)*12+i-1]);
		}
	}
	TFile *F = new TFile("Psi2S13TeV_result.root","recreate");
	DRp->Write();
	DRb->Write();
	F->Close();
	TH2D *D_Compare_p = new TH2D("D_Compare_p","compare prompt",12,ptbin,5,ybin);
	TH2D *D_Compare_b = new TH2D("D_Compare_b","compare fromb",12,ptbin,5,ybin);
	TH2D *R_Compare_p = new TH2D("R_Compare_p","compare prompt ratio",12,ptbin,5,ybin);
        TH2D *R_Compare_b = new TH2D("R_Compare_b","compare fromb ratio",12,ptbin,5,ybin);
	D_Compare_p -> Add(DRp,DMRp,1.,-1.);
	D_Compare_b -> Add(DRb,DMRb,1.,-1.);
	R_Compare_p -> Divide(DRp,DMRp,1.,1.,"B");
        R_Compare_b -> Divide(DRb,DMRb,1.,1.,"B");
	TCanvas *canp = new TCanvas("canp","canp",1600,1200);
	TH1D* p_bins[5];
	for(int i=0;i<5;i++)
	{
		p_bins[i] = new TH1D(Form("py%d",i),"",12,2000,14000);
		p_bins[i]->GetYaxis()->SetRangeUser(-10.,10);
		p_bins[i]->SetLineColor(i);
		p_bins[i]->GetYaxis()->SetTitle("#sigma_{published} - #sigma_{calculated}");
		p_bins[i]->GetXaxis()->SetTitle("p_{T} (MeV)");
		p_bins[i]->SetTitle("#psi(2S) (Prompt)");
		for(int j=0;j<14;j++)
		{
			p_bins[i]->SetBinContent(j+1,D_Compare_p->GetBinContent(j+1,i+1));
			p_bins[i]->SetBinError(j+1,D_Compare_p->GetBinError(j+1,i+1));
		}
		p_bins[i]->SetStats(0);
		if(i==1) p_bins[i]->Draw();
		p_bins[i]->Draw("same");
	}
	TLegend* legp = new TLegend(0.65, 0.65, 0.85, 0.85);
        legp->SetTextFont(132);
        legp->SetTextSize(0.03);
        for(int i=0;i<5;i++)
        {
                legp->AddEntry(Form("py%d",i), Form("%1.1f < #font[12]{y} < %1.1f", 2+i*0.5, 2.5+i*0.5));
        }
        legp->Draw();
	canp ->SaveAs("D_Compare_Prompt.pdf");
	canp -> Close();

	TCanvas *Rcanp = new TCanvas("Rcanp","Rcanp",1600,1200);
        TH1D* rp_bins[5];
        for(int i=0;i<5;i++)
        {
                rp_bins[i] = new TH1D(Form("rpy%d",i),"",12,2000,14000);
                rp_bins[i]->GetYaxis()->SetRangeUser(0.6,1.4);
                rp_bins[i]->SetLineColor(i);
                rp_bins[i]->GetYaxis()->SetTitle("#sigma_{published} / #sigma_{calculated}");
                rp_bins[i]->GetXaxis()->SetTitle("p_{T} (MeV)");
                rp_bins[i]->SetTitle("#psi(2S) (Prompt)");
                for(int j=0;j<14;j++)
                {
                        rp_bins[i]->SetBinContent(j+1,R_Compare_p->GetBinContent(j+1,i+1));
                        rp_bins[i]->SetBinError(j+1,R_Compare_p->GetBinError(j+1,i+1));
                }
                rp_bins[i]->SetStats(0);
                if(i==1) rp_bins[i]->Draw();
                rp_bins[i]->Draw("same");
        }
        TLegend* rlegp = new TLegend(0.65, 0.65, 0.85, 0.85);
        rlegp->SetTextFont(132);
        rlegp->SetTextSize(0.03);
        for(int i=0;i<5;i++)
        {
                rlegp->AddEntry(Form("rpy%d",i), Form("%1.1f < #font[12]{y} < %1.1f", 2+i*0.5, 2.5+i*0.5));
        }
        rlegp->Draw();
        Rcanp ->SaveAs("R_Compare_Prompt.pdf");
        Rcanp -> Close();

	TCanvas *canb = new TCanvas("canb","canb",1600,1200);
        TH1D* b_bins[5];
        for(int i=0;i<5;i++)
        {
		b_bins[i] = new TH1D(Form("by%d",i),"",12,2000,14000);
                b_bins[i]->GetYaxis()->SetRangeUser(-10.,10.);
                b_bins[i]->SetLineColor(i);
                b_bins[i]->GetYaxis()->SetTitle("#sigma_{published} - #sigma_{calculated}");
                b_bins[i]->GetXaxis()->SetTitle("p_{T} (MeV)");
		b_bins[i]->SetTitle("#psi(2S) (From b)");
                for(int j=0;j<14;j++)
                {
                        b_bins[i]->SetBinContent(j+1,D_Compare_b->GetBinContent(j+1,i+1));
                        b_bins[i]->SetBinError(j+1,D_Compare_b->GetBinError(j+1,i+1));
                }
                b_bins[i]->SetStats(0);
                if(i==1) b_bins[i]->Draw();
                b_bins[i]->Draw("same");
        }
        TLegend* legb = new TLegend(0.65, 0.65, 0.85, 0.85);
        legb->SetTextFont(132);
        legb->SetTextSize(0.03);
        for(int i=0;i<5;i++)
        {
                legb->AddEntry(Form("by%d",i), Form("%1.1f < #font[12]{y} < %1.1f", 2+i*0.5, 2.5+i*0.5));
        }
        legb->Draw();
        canb ->SaveAs("D_Compare_Fromb.pdf");
        canb -> Close();

	TCanvas *Rcanb = new TCanvas("Rcanb","Rcanb",1600,1200);
        TH1D* rb_bins[5];
        for(int i=0;i<5;i++)
        {
                rb_bins[i] = new TH1D(Form("rby%d",i),"",12,2000,14000);
                rb_bins[i]->GetYaxis()->SetRangeUser(0.6,1.4);
                rb_bins[i]->SetLineColor(i);
                rb_bins[i]->GetYaxis()->SetTitle("#sigma_{published} / #sigma_{calculated}");
                rb_bins[i]->GetXaxis()->SetTitle("p_{T} (MeV)");
                rb_bins[i]->SetTitle("#psi(2S) (From b)");
                for(int j=0;j<14;j++)
                {
                        rb_bins[i]->SetBinContent(j+1,R_Compare_b->GetBinContent(j+1,i+1));
                        rb_bins[i]->SetBinError(j+1,R_Compare_b->GetBinError(j+1,i+1));
                }
                rb_bins[i]->SetStats(0);
                if(i==1) rb_bins[i]->Draw();
                rb_bins[i]->Draw("same");
        }
        TLegend* rlegb = new TLegend(0.65, 0.65, 0.85, 0.85);
        rlegb->SetTextFont(132);
        rlegb->SetTextSize(0.03);
        for(int i=0;i<5;i++)
        {
                rlegb->AddEntry(Form("rby%d",i), Form("%1.1f < #font[12]{y} < %1.1f", 2+i*0.5, 2.5+i*0.5));
        }
        rlegb->Draw();
        Rcanb ->SaveAs("R_Compare_Fromb.pdf");
        Rcanb -> Close();

}
