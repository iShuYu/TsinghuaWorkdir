void INTratio()
{
	//1 for pPb, 2 for Pbp
	double r1=1.7054;
	double r2=1.35315; 
	double Acc1=0.8;
	double Tri1=3.2;
	double Br1=2.2;
	double Reff1=2.2;
	double PIDs1=1.7;
	double Acc2=0.8;
        double Tri2=3.6;
        double Br2=2.2;
        double Reff2=2.2;
        double PIDs2=1.8;
	double SJ1 = 0;
	double SJ2 = 0;
	double SP1 = 0;
       	double SP2 = 0;
	double SJErr1 = 0;
	double SJErr2 = 0;
	double SPErr1 = 0;
        double SPErr2 = 0;
	double stats1, stats2;
	for(int i=1;i<=5;i++)
	{
		double Jp, JpErr, Pp, PpErr;
		double Jeff, Peff;
		double sigJ, sigJErr, sigP, sigPErr;
		ifstream J(Form("../4_Result/TwoDimFit/Jpsi_n%dy1pt1.txt",i));
		ifstream P(Form("../4_Result/TwoDimFit/Psi2S_n%dy1pt1.txt",i));
		J>>Jp>>JpErr;
		P>>Pp>>PpErr;
		ifstream eJ(Form("../4_Result/Eff_RecselPIDTrigger/h_eff_tot_J_n%d.txt",i));
		ifstream eP(Form("../4_Result/Eff_RecselPIDTrigger/h_eff_tot_P_n%d.txt",i));
		eJ>>Jeff;
		eP>>Peff;
		sigJ = Jp/Jeff;
		sigJErr = JpErr/Jeff;
		sigP = Pp/Peff;
                sigPErr = PpErr/Peff;
		SJ1 = SJ1+sigJ;
		SJErr1 = SJErr1+sigJErr*sigJErr;
		SP1 = SP1+sigP;
                SPErr1 = SPErr1+sigPErr*sigPErr;
	}
	SJErr1 = sqrt(SJErr1)/SJ1;
	SPErr1 = sqrt(SPErr1)/SP1;
	stats1 = sqrt(SJErr1*SJErr1+SPErr1*SPErr1);
	for(int i=1;i<=5;i++)
        {
                double Jp, JpErr, Pp, PpErr;
                double Jeff, Peff;
                double sigJ, sigJErr, sigP, sigPErr;
                ifstream J(Form("/disk411/lhcb/kangye/Leadp/FWorkdir/4_Result/TwoDimFit/Jpsi_n%dy1pt1.txt",i));
                ifstream P(Form("/disk411/lhcb/kangye/Leadp/FWorkdir/4_Result/TwoDimFit/Psi2S_n%dy1pt1.txt",i));
                J>>Jp>>JpErr;
                P>>Pp>>PpErr;
                ifstream eJ(Form("/disk411/lhcb/kangye/Leadp/FWorkdir/4_Result/Eff_RecselPIDTrigger/h_eff_tot_J_n%d.txt",i));
                ifstream eP(Form("/disk411/lhcb/kangye/Leadp/FWorkdir/4_Result/Eff_RecselPIDTrigger/h_eff_tot_P_n%d.txt",i));
                eJ>>Jeff;
                eP>>Peff;
                sigJ = Jp/Jeff;
                sigJErr = JpErr/Jeff;
                sigP = Pp/Peff;
                sigPErr = PpErr/Peff;
                SJ2 = SJ2+sigJ;
                SJErr2 = SJErr2+sigJErr*sigJErr;
                SP2 = SP2+sigP;
                SPErr2 = SPErr2+sigPErr*sigPErr;
        }
        SJErr2 = sqrt(SJErr2)/SJ2;
        SPErr2 = sqrt(SPErr2)/SP2;
        stats2 = sqrt(SJErr2*SJErr2+SPErr2*SPErr2);
	double err1 = sqrt(Acc1*Acc1+Tri1*Tri1+Br1*Br1+Reff1*Reff1+PIDs1*PIDs1+stats1*stats1*10000)/100;
	double err2 = sqrt(Acc2*Acc2+Tri2*Tri2+Br2*Br2+Reff2*Reff2+PIDs2*PIDs2+stats2*stats2*10000)/100;
	cout << "pPb: " << r1 << "+-" << r1*err1 << endl;
	cout << "Pbp: " << r2 << "+-" << r2*err2 << endl;
}
	


