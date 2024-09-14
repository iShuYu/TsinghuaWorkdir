void Draw()
{
	TFile *F = TFile::Open("TrackTable.root");
	TH2D *pPb = (TH2D*)F->Get("pPb");
	pPb -> SetStats(0);
	pPb -> GetXaxis() -> SetTitle("p");
	pPb -> GetYaxis() -> SetTitle("#eta");
	TCanvas *cpPb = new TCanvas("cpPb","cpPb",1200,800);
	pPb -> Draw("colz text e");
	cpPb -> SetLogx();
	cpPb -> SaveAs("../../5_Plots/TrackCalib/pPb.pdf","recreate");	
	cpPb -> Close();
	TH2D *Pbp = (TH2D*)F->Get("Pbp");
        Pbp -> SetStats(0);
        Pbp -> GetXaxis() -> SetTitle("p");
        Pbp -> GetYaxis() -> SetTitle("#eta");
        TCanvas *cPbp = new TCanvas("cPbp","cPbp",1200,800);
        Pbp -> Draw("colz text e");
        cPbp -> SetLogx();
        cPbp -> SaveAs("../../5_Plots/TrackCalib/Pbp.pdf","recreate");
        cPbp -> Close();
}
