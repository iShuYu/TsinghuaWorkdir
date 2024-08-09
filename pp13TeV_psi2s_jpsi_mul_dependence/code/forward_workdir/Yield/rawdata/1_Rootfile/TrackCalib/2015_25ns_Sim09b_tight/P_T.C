void P_T()
{
//=========Macro generated from canvas: c_T/c_T
//=========  (Mon Nov 22 01:51:45 2021) by ROOT version 6.20/06
   TCanvas *c_T = new TCanvas("c_T", "c_T",0,0,1000,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c_T->SetHighLightColor(2);
   c_T->Range(-19683.55,0.81,227151.9,1.076667);
   c_T->SetFillColor(0);
   c_T->SetBorderMode(0);
   c_T->SetBorderSize(2);
   c_T->SetBottomMargin(0.15);
   c_T->SetFrameBorderMode(0);
   c_T->SetFrameBorderMode(0);
   
   TH1D *hist__1 = new TH1D("hist__1","",100,5000,200000);
   hist__1->SetMinimum(0.85);
   hist__1->SetMaximum(1.05);
   hist__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hist__1->SetLineColor(ci);
   hist__1->SetMarkerStyle(20);
   hist__1->GetXaxis()->SetTitle("#it{p} [MeV/#it{c}]");
   hist__1->GetXaxis()->SetLabelFont(132);
   hist__1->GetXaxis()->SetLabelSize(0.05);
   hist__1->GetXaxis()->SetTitleSize(0.06);
   hist__1->GetXaxis()->SetTitleOffset(0.8);
   hist__1->GetXaxis()->SetTitleFont(132);
   hist__1->GetYaxis()->SetTitle("#varepsilon");
   hist__1->GetYaxis()->SetLabelFont(132);
   hist__1->GetYaxis()->SetLabelSize(0.05);
   hist__1->GetYaxis()->SetTitleSize(0.06);
   hist__1->GetYaxis()->SetTitleOffset(0.8);
   hist__1->GetYaxis()->SetTitleFont(132);
   hist__1->GetZaxis()->SetLabelFont(42);
   hist__1->GetZaxis()->SetTitleOffset(1);
   hist__1->GetZaxis()->SetTitleFont(42);
   hist__1->Draw("AXIS");
   TLatex *   tex = new TLatex(0.855,0.875,"LHCb preliminary");
tex->SetNDC();
   tex->SetTextAlign(33);
   tex->SetTextFont(132);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.135,0.875,"T method");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(132);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TLegend *leg = new TLegend(0.55,0.175,0.875,0.325,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(132);
   leg->SetTextSize(0.045);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Efficiency_P","2015 Data, 25ns","PL");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("Efficiency_P","2015 MC, Sim09b","PL");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   leg->Draw();
   
   Double_t Efficiency_P_fx3001[5] = {
   7500,
   15000,
   30000,
   70000,
   150000};
   Double_t Efficiency_P_fy3001[5] = {
   0.9714047,
   0.985638,
   0.9881014,
   0.9881332,
   0.9827107};
   Double_t Efficiency_P_felx3001[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Efficiency_P_fely3001[5] = {
   0.001155645,
   0.0004693575,
   0.0003501015,
   0.0003462606,
   0.001166529};
   Double_t Efficiency_P_fehx3001[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Efficiency_P_fehy3001[5] = {
   0.001159321,
   0.0004723844,
   0.0003501784,
   0.0003462433,
   0.001158887};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,Efficiency_P_fx3001,Efficiency_P_fy3001,Efficiency_P_felx3001,Efficiency_P_fehx3001,Efficiency_P_fely3001,Efficiency_P_fehy3001);
   grae->SetName("Efficiency_P");
   grae->SetTitle("");
   grae->SetFillStyle(1000);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Efficiency_P3001 = new TH1F("Graph_Efficiency_P3001","",100,0,219500);
   Graph_Efficiency_P3001->SetMinimum(0.85);
   Graph_Efficiency_P3001->SetMaximum(1.05);
   Graph_Efficiency_P3001->SetDirectory(0);
   Graph_Efficiency_P3001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Efficiency_P3001->SetLineColor(ci);
   Graph_Efficiency_P3001->GetXaxis()->SetTitle("#it{p} [MeV/#it{c}]");
   Graph_Efficiency_P3001->GetXaxis()->SetLabelFont(132);
   Graph_Efficiency_P3001->GetXaxis()->SetLabelSize(0.05);
   Graph_Efficiency_P3001->GetXaxis()->SetTitleSize(0.06);
   Graph_Efficiency_P3001->GetXaxis()->SetTitleOffset(0.5);
   Graph_Efficiency_P3001->GetXaxis()->SetTitleFont(132);
   Graph_Efficiency_P3001->GetYaxis()->SetTitle("#varepsilon");
   Graph_Efficiency_P3001->GetYaxis()->SetLabelFont(132);
   Graph_Efficiency_P3001->GetYaxis()->SetLabelSize(0.05);
   Graph_Efficiency_P3001->GetYaxis()->SetTitleSize(0.06);
   Graph_Efficiency_P3001->GetYaxis()->SetTitleOffset(0.5);
   Graph_Efficiency_P3001->GetYaxis()->SetTitleFont(132);
   Graph_Efficiency_P3001->GetZaxis()->SetLabelFont(42);
   Graph_Efficiency_P3001->GetZaxis()->SetTitleOffset(1);
   Graph_Efficiency_P3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Efficiency_P3001);
   
   grae->Draw("p");
   
   Double_t Efficiency_P_fx3002[5] = {
   7500,
   15000,
   30000,
   70000,
   150000};
   Double_t Efficiency_P_fy3002[5] = {
   0.9831438,
   0.9921197,
   0.9915829,
   0.9889951,
   0.9818231};
   Double_t Efficiency_P_felx3002[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Efficiency_P_fely3002[5] = {
   0.001085183,
   0.00031398,
   0.0002098687,
   0.0003217882,
   0.0006524534};
   Double_t Efficiency_P_fehx3002[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Efficiency_P_fehy3002[5] = {
   0.0006212134,
   0.0001829358,
   0.0001222304,
   9.057792e-05,
   0.0003904395};
   grae = new TGraphAsymmErrors(5,Efficiency_P_fx3002,Efficiency_P_fy3002,Efficiency_P_felx3002,Efficiency_P_fehx3002,Efficiency_P_fely3002,Efficiency_P_fehy3002);
   grae->SetName("Efficiency_P");
   grae->SetTitle("Efficiency_P");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Efficiency_P3002 = new TH1F("Graph_Efficiency_P3002","Efficiency_P",100,0,219500);
   Graph_Efficiency_P3002->SetMinimum(0.9800574);
   Graph_Efficiency_P3002->SetMaximum(0.9934158);
   Graph_Efficiency_P3002->SetDirectory(0);
   Graph_Efficiency_P3002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Efficiency_P3002->SetLineColor(ci);
   Graph_Efficiency_P3002->GetXaxis()->SetLabelFont(42);
   Graph_Efficiency_P3002->GetXaxis()->SetTitleOffset(1);
   Graph_Efficiency_P3002->GetXaxis()->SetTitleFont(42);
   Graph_Efficiency_P3002->GetYaxis()->SetLabelFont(42);
   Graph_Efficiency_P3002->GetYaxis()->SetTitleFont(42);
   Graph_Efficiency_P3002->GetZaxis()->SetLabelFont(42);
   Graph_Efficiency_P3002->GetZaxis()->SetTitleOffset(1);
   Graph_Efficiency_P3002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Efficiency_P3002);
   
   grae->Draw("p");
   c_T->Modified();
   c_T->cd();
   c_T->SetSelected(c_T);
}
