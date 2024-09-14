void DrawMCb()
{
	TFile *out = TFile::Open("newVarMCb.root");
	TTree *mct = (TTree*)out->Get("mct");
	TH2D *h1 = new TH2D("h1", "h1", 60,-60,180,100,0,200);
	mct->Draw("PVNTRACKS:PVZ>>h1");
	TH2D *h2 = new TH2D("h2", "h2", 60,-60,180,100,0,200);
	mct->Draw("PVNcor:PVZ>>h2");
	TH2D *h3 = new TH2D("h3", "h3", 60,-60,180,100,0,200);
        mct->Draw("PVNrew:PVZ>>h3");
	TH2D *h4 = new TH2D("h4", "h4", 60,-60,180,100,0,200);
        mct->Draw("Nch:PVZ>>h4");
	

	TProfile *Pro = h1->ProfileX();
	Pro->SetStats(0);
	Pro->SetLineColor(kBlue);
	Pro->SetTitle("2016 pp 13TeV MC (non-prompt J/#psi)");
	Pro->GetXaxis()->SetTitle("z_{PV}");
	Pro->GetYaxis()->SetTitle("#LT#font[12]{N}^{PV}_{tracks}#GT");
	TCanvas *can = new TCanvas("can", "can", 1200, 800);
	Pro->Draw();
	Pro->GetYaxis()->SetRangeUser(0,70);
	Pro->Draw();
	TProfile *Pro1 = h2->ProfileX();
	Pro1->SetLineColor(kRed);
	Pro1->Draw("same");
	TProfile *Pro2 = h3->ProfileX();
	Pro2->SetLineColor(kMagenta);
	Pro2->Draw("same");
	TProfile *Pro4 = h4->ProfileX();
        Pro4->SetLineColor(kBlack);
        Pro4->Draw("same");

	TLegend *leg = new TLegend(0.2,0.13,0.6,0.33);
        leg->AddEntry(Pro, "RAW");
	leg->AddEntry(Pro2, "Reweighted");
        leg->AddEntry(Pro1, "Reweighted then Corrected");
	leg->AddEntry(Pro4, "#font[12]{N}_{ch} with 2<#eta<4.9");
	leg->Draw("same");
	can -> SaveAs("MCb.pdf");
	can -> Close();
}
