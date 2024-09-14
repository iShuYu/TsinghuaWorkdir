void  drawMCDATAp()
{
	TFile *out1 = TFile::Open("newVarMCp.root");
        TTree *mct = (TTree*)out1->Get("mct");
        TH2D *h2 = new TH2D("h2", "h2", 60,-60,180,100,0,200);
        mct->Draw("PVNTRACKS:PVZ>>h2");
	TProfile *Pro1 = h2->ProfileX();
	TH2D *h3 = new TH2D("h3", "h3", 60,-60,180,100,0,200);

	TFile *out = TFile::Open("newVar.root");
	TTree *DecayTree = (TTree*)out->Get("DecayTree");
	TH2D *h1 = new TH2D("h1", "h1", 60,-60,180,100,0,200);
	DecayTree->Draw("PVNTRACKS:PVZ>>h1","prompt_sw");
	TProfile *Pro = h1->ProfileX();
	Pro->SetStats(0);
	Pro->SetLineColor(kBlue);
	Pro->SetTitle("2016 pp 13TeV Data (prompt_sw)");
	Pro->GetXaxis()->SetTitle("z_{PV}");
	Pro->GetYaxis()->SetTitle("#LT#font[12]{N}^{PV}_{tracks}#GT");
	TProfile *Pro2 = new TProfile("Pro2","Pro2", 60, -60, 180);
       	Pro2 -> Divide(Pro, Pro1, 1., 1., "B");
	TH1D *Pro3  = new TH1D("Pro3","Pro3", 60, -60, 180);;
       	for(int i=0;i<Pro3->GetNbinsX();i++)
	{
		Pro3->SetBinContent(i+1,Pro2->GetBinContent(i+1)*Pro1->GetBinContent(i+1));
		cout << Pro2->GetBinContent(i+1)*Pro1->GetBinContent(i+1) << endl;
	}
	TCanvas *can = new TCanvas("can", "can", 1200, 800);
	Pro->GetYaxis()->SetRangeUser(0,70);
	Pro->Draw();
	Pro1->SetLineColor(kCyan);
	Pro1->Draw("same");
	Pro3->SetMarkerStyle(8);
	Pro3->SetMarkerSize(1);
	Pro3->SetMarkerColor(kBlack);
	Pro3->SetLineColor(kMagenta);
	Pro3->Draw("Psame");

	TLegend *leg = new TLegend(0.2,0.2,0.4,0.35);
	leg->AddEntry(Pro, "Data (sw)");
	leg->AddEntry(Pro1, "MC");
	leg->AddEntry(Pro3, "MC reweight");
	leg->Draw("same");
	can -> SaveAs("DataMCp.pdf");
	can -> Close();
	TFile *outF = new TFile("./weightp.root","recreate");
	Pro2->Write();
	outF->Close();
}
