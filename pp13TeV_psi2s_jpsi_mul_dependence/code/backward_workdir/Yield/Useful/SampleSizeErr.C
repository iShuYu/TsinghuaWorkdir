void SampleSizeErr()
{
	cout << "prompt" << endl;
	for(int i=1; i<=5;i++)
	{
		TFile *J = TFile::Open(Form("Jpsi/3_Result/eff_tot/n%d_prompt.root",i));
		TH2D *TJ = (TH2D*)J->Get("h_3");
		TFile *P = TFile::Open(Form("Psi2S/3_Result/eff_tot/n%d_prompt.root",i));
		TH2D *TP = (TH2D*)P->Get("h_3");
		TH1::SetDefaultSumw2();
		TJ->Divide(TJ,TP,1.,1.);
		double flag, max, min;
		max = 0;
		min = 10;
		for(int j=1;j<=3;j++)
		{
			for(int k=1;k<5;k++)
			{
				flag = TJ->GetBinError(k,j)/TJ->GetBinContent(k,j);
				if(flag>max) max = flag;
				if(flag<min) min = flag;
			}
		}
		max = max*100;
		min = min*100;
		cout << min << ", " <<max << endl;
	}
	cout << "fromb" << endl;
        for(int i=1; i<=5;i++)
        {
                TFile *J = TFile::Open(Form("Jpsi/3_Result/eff_tot/n%d_fromb.root",i));
                TH2D *TJ = (TH2D*)J->Get("h_3");
                TFile *P = TFile::Open(Form("Psi2S/3_Result/eff_tot/n%d_fromb.root",i));
                TH2D *TP = (TH2D*)P->Get("h_3");
                TH1::SetDefaultSumw2();
                TJ->Divide(TJ,TP,1.,1.);
                double flag, max, min;
                max = 0;
                min = 10;
                for(int j=1;j<=3;j++)
                {
                        for(int k=1;k<5;k++)
                        {
                                flag = TJ->GetBinError(k,j)/TJ->GetBinContent(k,j);
                                if(flag>max) max = flag;
                                if(flag<min) min = flag;
                        }
                }
                max = max*100;
                min = min*100;
                cout << min << ", " <<max << endl;
        }

}





