void P_Velo()
{
//=========Macro generated from canvas: c_Velo/c_Velo
//=========  (Mon Nov 22 01:49:56 2021) by ROOT version 6.20/06
   TCanvas *c_Velo = new TCanvas("c_Velo", "c_Velo",0,0,1000,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c_Velo->SetHighLightColor(2);
   c_Velo->Range(-19683.55,0.81,227151.9,1.076667);
   c_Velo->SetFillColor(0);
   c_Velo->SetBorderMode(0);
   c_Velo->SetBorderSize(2);
   c_Velo->SetBottomMargin(0.15);
   c_Velo->SetFrameBorderMode(0);
   c_Velo->SetFrameBorderMode(0);
   
   TH1D *hist__2 = new TH1D("hist__2","",100,5000,200000);
   hist__2->SetMinimum(0.85);
   hist__2->SetMaximum(1.05);
   hist__2->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hist__2->SetLineColor(ci);
   hist__2->SetMarkerStyle(20);
   hist__2->GetXaxis()->SetTitle("#it{p} [MeV/#it{c}]");
   hist__2->GetXaxis()->SetLabelFont(132);
   hist__2->GetXaxis()->SetLabelSize(0.05);
   hist__2->GetXaxis()->SetTitleSize(0.06);
   hist__2->GetXaxis()->SetTitleOffset(0.8);
   hist__2->GetXaxis()->SetTitleFont(132);
   hist__2->GetYaxis()->SetTitle("#varepsilon");
   hist__2->GetYaxis()->SetLabelFont(132);
   hist__2->GetYaxis()->SetLabelSize(0.05);
   hist__2->GetYaxis()->SetTitleSize(0.06);
   hist__2->GetYaxis()->SetTitleOffset(0.8);
   hist__2->GetYaxis()->SetTitleFont(132);
   hist__2->GetZaxis()->SetLabelFont(42);
   hist__2->GetZaxis()->SetTitleOffset(1);
   hist__2->GetZaxis()->SetTitleFont(42);
   hist__2->Draw("AXIS");
   TLatex *   tex = new TLatex(0.855,0.875,"LHCb preliminary");
tex->SetNDC();
   tex->SetTextAlign(33);
   tex->SetTextFont(132);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.135,0.875,"Velo method");
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
   
   Double_t Efficiency_P_fx3003[5] = {
   7500,
   15000,
   30000,
   70000,
   150000};
   Double_t Efficiency_P_fy3003[5] = {
   0.9706336,
   0.9771094,
   0.9790674,
   0.973555,
   0.9600499};
   Double_t Efficiency_P_felx3003[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Efficiency_P_fely3003[5] = {
   0.005988288,
   0.0006279602,
   0.0003914571,
   0.0005621741,
   0.0009143573};
   Double_t Efficiency_P_fehx3003[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Efficiency_P_fehy3003[5] = {
   0.002069231,
   0.0006343667,
   0.0003913728,
   0.0003942939,
   0.00091413};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,Efficiency_P_fx3003,Efficiency_P_fy3003,Efficiency_P_felx3003,Efficiency_P_fehx3003,Efficiency_P_fely3003,Efficiency_P_fehy3003);
   grae->SetName("Efficiency_P");
   grae->SetTitle("");
   grae->SetFillStyle(1000);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Efficiency_P3003 = new TH1F("Graph_Efficiency_P3003","",100,0,219500);
   Graph_Efficiency_P3003->SetMinimum(0.85);
   Graph_Efficiency_P3003->SetMaximum(1.05);
   Graph_Efficiency_P3003->SetDirectory(0);
   Graph_Efficiency_P3003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Efficiency_P3003->SetLineColor(ci);
   Graph_Efficiency_P3003->GetXaxis()->SetTitle("#it{p} [MeV/#it{c}]");
   Graph_Efficiency_P3003->GetXaxis()->SetLabelFont(132);
   Graph_Efficiency_P3003->GetXaxis()->SetLabelSize(0.05);
   Graph_Efficiency_P3003->GetXaxis()->SetTitleSize(0.06);
   Graph_Efficiency_P3003->GetXaxis()->SetTitleOffset(0.5);
   Graph_Efficiency_P3003->GetXaxis()->SetTitleFont(132);
   Graph_Efficiency_P3003->GetYaxis()->SetTitle("#varepsilon");
   Graph_Efficiency_P3003->GetYaxis()->SetLabelFont(132);
   Graph_Efficiency_P3003->GetYaxis()->SetLabelSize(0.05);
   Graph_Efficiency_P3003->GetYaxis()->SetTitleSize(0.06);
   Graph_Efficiency_P3003->GetYaxis()->SetTitleOffset(0.5);
   Graph_Efficiency_P3003->GetYaxis()->SetTitleFont(132);
   Graph_Efficiency_P3003->GetZaxis()->SetLabelFont(42);
   Graph_Efficiency_P3003->GetZaxis()->SetTitleOffset(1);
   Graph_Efficiency_P3003->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Efficiency_P3003);
   
   grae->Draw("p");
   
   Double_t Efficiency_P_fx3004[5] = {
   7500,
   15000,
   30000,
   70000,
   150000};
   Double_t Efficiency_P_fy3004[5] = {
   0.9659029,
   0.9761874,
   0.9774771,
   0.9723649,
   0.9564258};
   Double_t Efficiency_P_felx3004[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Efficiency_P_fely3004[5] = {
   0.002687801,
   0.001013197,
   0.0006678067,
   0.0005799775,
   0.003421285};
   Double_t Efficiency_P_fehx3004[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Efficiency_P_fehy3004[5] = {
   0.001236145,
   0.0004696539,
   0.0002863248,
   0.0002660934,
   0.0006422518};
   grae = new TGraphAsymmErrors(5,Efficiency_P_fx3004,Efficiency_P_fy3004,Efficiency_P_felx3004,Efficiency_P_fehx3004,Efficiency_P_fely3004,Efficiency_P_fehy3004);
   grae->SetName("Efficiency_P");
   grae->SetTitle("Efficiency_P");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Efficiency_P3004 = new TH1F("Graph_Efficiency_P3004","Efficiency_P",100,0,219500);
   Graph_Efficiency_P3004->SetMinimum(0.9505286);
   Graph_Efficiency_P3004->SetMaximum(0.9802394);
   Graph_Efficiency_P3004->SetDirectory(0);
   Graph_Efficiency_P3004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Efficiency_P3004->SetLineColor(ci);
   Graph_Efficiency_P3004->GetXaxis()->SetLabelFont(42);
   Graph_Efficiency_P3004->GetXaxis()->SetTitleOffset(1);
   Graph_Efficiency_P3004->GetXaxis()->SetTitleFont(42);
   Graph_Efficiency_P3004->GetYaxis()->SetLabelFont(42);
   Graph_Efficiency_P3004->GetYaxis()->SetTitleFont(42);
   Graph_Efficiency_P3004->GetZaxis()->SetLabelFont(42);
   Graph_Efficiency_P3004->GetZaxis()->SetTitleOffset(1);
   Graph_Efficiency_P3004->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Efficiency_P3004);
   
   grae->Draw("p");
   c_Velo->Modified();
   c_Velo->cd();
   c_Velo->SetSelected(c_Velo);
}
