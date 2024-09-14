#include <fstream>
#include <TCanvas.h>
#include <TFile.h>
#include <TH1.h>
#include <TF1.h>
#include <TRandom3.h>
#include <math.h>
using namespace std;
double weight(double mu1, double sigma1, double mu2, double sigma2)
{
	double w1 = 1/sigma1/sigma1;
	double w2 = 1/sigma2/sigma2;
	return (w1*mu1+w2*mu2)/(w1+w2);
}
int main(int argc, char* argv[])
{
	//用类型3的随机数生成器，seed设置为0表示随机数种子本身也将会是一个随机数
	TRandom3 *r = new TRandom3(0);
	
	//输入想要算某一区间的均值的TH1D
	TFile *input = TFile::Open(argv[1]);
	TH1D *t1 = (TH1D*)input->Get(argv[2]);
	input = TFile::Open(argv[3]);
        TH1D *t2 = (TH1D*)input->Get(argv[4]);

	//输入分bin方式
	ifstream Nbin(argv[5]);
	int N;
	Nbin >> N;
	int n[N+1];
	for(int i=0; i<=N; i++) Nbin >> n[i];

	//输入想要抽样的次数
	int times;
	sscanf(argv[6],"%d",&times);
		
	//循环
	ofstream out(argv[9]);
	out << N << endl;
	for(int j=0;j<N;j++)
	{
		int a = n[j];
		int b = n[j+1];
		double mean1[times], mean2[times];
		for(int i=0; i<times; i++)
		{
			//定义一个新的TH1D为b-a个区间从a到b，这里默认宽度是1，因为back的和forward的区间定义比较零散，区间之间没啥最小公约数，所以之前输入的TH1D也需要是提前fill好的一个sweight的bin宽为1的TH1D
			TH1D Tab1 = TH1D("Tab1","Tab1",b-a,a,b);
			TH1D Tab2 = TH1D("Tab2","Tab2",b-a,a,b);
			for(int i=0;i<b-a;i++)
			{
				double con1 = t1->GetBinContent(t1->FindBin(i+a));
				double err1 = t1->GetBinError(t1->FindBin(i+a));
				double con2 = t2->GetBinContent(t2->FindBin(i+a));
                                double err2 = t2->GetBinError(t2->FindBin(i+a));
				Tab1.SetBinContent(i+1,r->Gaus(con1,err1));
				Tab2.SetBinContent(i+1,r->Gaus(con2,err2));
			}
			mean1[i] = Tab1.GetMean();
			mean2[i] = Tab2.GetMean();
		}
		//计算mean[]的均值和标准差以用于拟合
		double sum1, mu1, sigma1;
		double sum2, mu2, sigma2;
		sum1 = 0;
		sum2 = 0;
		for(int i=0; i<times; i++)
		{
			sum1 = sum1+mean1[i];
			sum2 = sum2+mean2[i];
		}
		mu1 = sum1/times;
		mu2 = sum2/times;
		sum1 = 0;
		sum2 = 0;
		for(int i=0; i<times; i++)
		{
			sum1 = sum1+(mean1[i]-mu1)*(mean1[i]-mu1);
			sum2 = sum2+(mean2[i]-mu2)*(mean2[i]-mu2);
		}
		sigma1 = sqrt(sum1/(times-1));
		sigma2 = sqrt(sum2/(times-1));
		//拟合+画图
		TH1D *tMean1 = new TH1D("tMean1","tMean1",60,mu1-4*sigma1,mu1+4*sigma1);
		TH1D *tMean2 = new TH1D("tMean2","tMean2",60,mu2-4*sigma2,mu2+4*sigma2);
		for(int i=0; i<times; i++)
		{
			tMean1 -> Fill(mean1[i]);
			tMean2 -> Fill(mean2[i]);
		}
		TCanvas *can1 = new TCanvas("can1","can1",800,600);
		tMean1 -> Fit("gaus");
		tMean1 -> SetStats(0);
		tMean1 -> SetTitle(0);
		TF1 *g1 = (TF1*)tMean1->GetListOfFunctions()->FindObject("gaus");
		can1 -> SaveAs(Form("%s_%d_to_%d.pdf",argv[7],a,b));
		TCanvas *can2 = new TCanvas("can2","can2",800,600);
                tMean2 -> Fit("gaus");
		tMean2 -> SetStats(0);
                tMean2 -> SetTitle(0);
		TF1 *g2 = (TF1*)tMean2->GetListOfFunctions()->FindObject("gaus");
                can2 -> SaveAs(Form("%s_%d_to_%d.pdf",argv[8],a,b));
		double FitMean1 = g1->GetParameter(1);
		double FitSigma1 = g1->GetParameter(2);
		double FitMean2 = g2->GetParameter(1);
                double FitSigma2 = g2->GetParameter(2);
		out << weight(FitMean1,FitSigma1,FitMean2,FitSigma2)/25.88 << endl;
	}
	out.close();
	return 0;
}
	
