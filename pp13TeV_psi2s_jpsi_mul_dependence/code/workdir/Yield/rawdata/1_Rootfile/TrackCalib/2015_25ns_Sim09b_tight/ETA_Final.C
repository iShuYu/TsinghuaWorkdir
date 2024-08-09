void ETA_Final()
{
//=========Macro generated from canvas: c_Final/c_Final
//=========  (Mon Nov 22 01:51:45 2021) by ROOT version 6.20/06
   TCanvas *c_Final = new TCanvas("c_Final", "c_Final",0,0,1000,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c_Final->SetHighLightColor(2);
   c_Final->Range(1.520253,0.81,5.317722,1.076667);
   c_Final->SetFillColor(0);
   c_Final->SetBorderMode(0);
   c_Final->SetBorderSize(2);
   c_Final->SetBottomMargin(0.15);
   c_Final->SetFrameBorderMode(0);
   c_Final->SetFrameBorderMode(0);
   
   TH1D *hist__10 = new TH1D("hist__10","",100,1.9,4.9);
   hist__10->SetMinimum(0.85);
   hist__10->SetMaximum(1.05);
   hist__10->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hist__10->SetLineColor(ci);
   hist__10->SetMarkerStyle(20);
   hist__10->GetXaxis()->SetTitle("#eta");
   hist__10->GetXaxis()->SetLabelFont(132);
   hist__10->GetXaxis()->SetLabelSize(0.05);
   hist__10->GetXaxis()->SetTitleSize(0.06);
   hist__10->GetXaxis()->SetTitleOffset(0.8);
   hist__10->GetXaxis()->SetTitleFont(132);
   hist__10->GetYaxis()->SetTitle("#varepsilon");
   hist__10->GetYaxis()->SetLabelFont(132);
   hist__10->GetYaxis()->SetLabelSize(0.05);
   hist__10->GetYaxis()->SetTitleSize(0.06);
   hist__10->GetYaxis()->SetTitleOffset(0.8);
   hist__10->GetYaxis()->SetTitleFont(132);
   hist__10->GetZaxis()->SetLabelFont(42);
   hist__10->GetZaxis()->SetTitleOffset(1);
   hist__10->GetZaxis()->SetTitleFont(42);
   hist__10->Draw("AXIS");
   TLatex *   tex = new TLatex(0.855,0.875,"LHCb preliminary");
tex->SetNDC();
   tex->SetTextAlign(33);
   tex->SetTextFont(132);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.135,0.875,"Final method");
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
   TLegendEntry *entry=leg->AddEntry("Graph","2015 Data, 25ns","PL");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("Graph","2015 MC, Sim09b","PL");

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
   
   Double_t Graph0_fx3019[2] = {
   2.55,
   4.05};
   Double_t Graph0_fy3019[2] = {
   0.965146,
   0.9603385};
   Double_t Graph0_felx3019[2] = {
   0.65,
   0.85};
   Double_t Graph0_fely3019[2] = {
   0.0003742564,
   0.0003627305};
   Double_t Graph0_fehx3019[2] = {
   0.65,
   0.85};
   Double_t Graph0_fehy3019[2] = {
   0.0003749873,
   0.0003629584};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(2,Graph0_fx3019,Graph0_fy3019,Graph0_felx3019,Graph0_fehx3019,Graph0_fely3019,Graph0_fehy3019);
   grae->SetName("Graph0");
   grae->SetTitle("");
   grae->SetFillStyle(1000);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph03019 = new TH1F("Graph_Graph03019","",100,1.6,5.2);
   Graph_Graph03019->SetMinimum(0.85);
   Graph_Graph03019->SetMaximum(1.05);
   Graph_Graph03019->SetDirectory(0);
   Graph_Graph03019->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph03019->SetLineColor(ci);
   Graph_Graph03019->GetXaxis()->SetTitle("#eta");
   Graph_Graph03019->GetXaxis()->SetLabelFont(132);
   Graph_Graph03019->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph03019->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph03019->GetXaxis()->SetTitleOffset(0.5);
   Graph_Graph03019->GetXaxis()->SetTitleFont(132);
   Graph_Graph03019->GetYaxis()->SetTitle("#varepsilon");
   Graph_Graph03019->GetYaxis()->SetLabelFont(132);
   Graph_Graph03019->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph03019->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph03019->GetYaxis()->SetTitleOffset(0.5);
   Graph_Graph03019->GetYaxis()->SetTitleFont(132);
   Graph_Graph03019->GetZaxis()->SetLabelFont(42);
   Graph_Graph03019->GetZaxis()->SetTitleOffset(1);
   Graph_Graph03019->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph03019);
   
   grae->Draw("p");
   
   Double_t Graph1_fx3020[2] = {
   2.55,
   4.05};
   Double_t Graph1_fy3020[2] = {
   0.968999,
   0.9570475};
   Double_t Graph1_felx3020[2] = {
   0.65,
   0.85};
   Double_t Graph1_fely3020[2] = {
   0.0004276501,
   0.000528198};
   Double_t Graph1_fehx3020[2] = {
   0.65,
   0.85};
   Double_t Graph1_fehy3020[2] = {
   0.0001624033,
   0.0001693891};
   grae = new TGraphAsymmErrors(2,Graph1_fx3020,Graph1_fy3020,Graph1_felx3020,Graph1_fehx3020,Graph1_fely3020,Graph1_fehy3020);
   grae->SetName("Graph1");
   grae->SetTitle("Graph");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph13020 = new TH1F("Graph_Graph13020","Graph",100,1.6,5.2);
   Graph_Graph13020->SetMinimum(0.9552551);
   Graph_Graph13020->SetMaximum(0.9704256);
   Graph_Graph13020->SetDirectory(0);
   Graph_Graph13020->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph13020->SetLineColor(ci);
   Graph_Graph13020->GetXaxis()->SetLabelFont(42);
   Graph_Graph13020->GetXaxis()->SetTitleOffset(1);
   Graph_Graph13020->GetXaxis()->SetTitleFont(42);
   Graph_Graph13020->GetYaxis()->SetLabelFont(42);
   Graph_Graph13020->GetYaxis()->SetTitleFont(42);
   Graph_Graph13020->GetZaxis()->SetLabelFont(42);
   Graph_Graph13020->GetZaxis()->SetTitleOffset(1);
   Graph_Graph13020->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph13020);
   
   grae->Draw("p");
   c_Final->Modified();
   c_Final->cd();
   c_Final->SetSelected(c_Final);
}
