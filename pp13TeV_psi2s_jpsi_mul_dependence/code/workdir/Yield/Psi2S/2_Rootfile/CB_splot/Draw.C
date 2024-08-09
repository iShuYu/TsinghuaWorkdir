void draw()
{
	TFile F("./Data_Splot.root");
	TTree *T = (TTree*)F.Get("DecayTree");
	long int N = T->GetEntries();
	TH1D *m = new TH1D("mass","mass",60,3686-120,3686+120);
	double psi_M,sig_sw;
	T->SetBranchAddress("psi_M",&psi_M);
	T->SetBranchAddress("sig_sw",&sig_sw);
	for(int i=0;i<N;i++)
	{
		T->GetEntry(i);
		m->Fill(psi_M,sig_sw);
	}
	TCanvas *can = new TCanvas("can","can",800,600);
	m->Draw();
	can->SaveAs("mass.pdf");
}
