void GetErr()
{
	double Np[75], Nb[75], NpErr[75], NbErr[75];
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=3;j++)
		{
			for(int k=1;k<=5;k++)
			{
				int index = 15*(i-1)+5*(j-1)+(k-1);
				ifstream file(Form("txt_n%dy%dpt%d.txt",i,j,k));
				for(int iter = 1; iter<=11; iter++)
				{
					file >> Np[index];
				}
				file >> NpErr[index];
				file >> Nb[index];
				file >> NbErr[index];
			}
		}
	}
	TH1D *th1 = new TH1D("th1","Errors with floated parameters for J/#psi",20,0,0.03);
	for(int i=0;i<75;i++)
	{
		th1->Fill(NpErr[i]/Np[i]);
		th1->Fill(NbErr[i]/Nb[i]);
	}
	th1->Draw();
}
