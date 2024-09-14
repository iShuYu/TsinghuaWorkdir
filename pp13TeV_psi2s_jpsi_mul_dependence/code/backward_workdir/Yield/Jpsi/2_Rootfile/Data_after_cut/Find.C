void Find()
{
	TFile *f = TFile::Open("./n1y1pt1.root");
	TTree *t = (TTree*)f->Get("DecayTree");
	Int_t N = t->GetEntries();
	for(int i=0;i<N;i++)
	{
		t->
}
