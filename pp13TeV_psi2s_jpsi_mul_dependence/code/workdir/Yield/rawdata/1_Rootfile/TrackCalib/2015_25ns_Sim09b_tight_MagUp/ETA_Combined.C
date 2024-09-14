void ETA_Combined()
{
//=========Macro generated from canvas: c_Combined/c_Combined
//=========  (Mon Nov 22 01:49:56 2021) by ROOT version 6.20/06
   TCanvas *c_Combined = new TCanvas("c_Combined", "c_Combined",0,0,1000,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c_Combined->SetHighLightColor(2);
   c_Combined->Range(1.520253,0.81,5.317722,1.076667);
   c_Combined->SetFillColor(0);
   c_Combined->SetBorderMode(0);
   c_Combined->SetBorderSize(2);
   c_Combined->SetBottomMargin(0.15);
   c_Combined->SetFrameBorderMode(0);
   c_Combined->SetFrameBorderMode(0);
   
   TH1D *hist__9 = new TH1D("hist__9","",100,1.9,4.9);
   hist__9->SetMinimum(0.85);
   hist__9->SetMaximum(1.05);
   hist__9->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hist__9->SetLineColor(ci);
   hist__9->SetMarkerStyle(20);
   hist__9->GetXaxis()->SetTitle("#eta");
   hist__9->GetXaxis()->SetLabelFont(132);
   hist__9->GetXaxis()->SetLabelSize(0.05);
   hist__9->GetXaxis()->SetTitleSize(0.06);
   hist__9->GetXaxis()->SetTitleOffset(0.8);
   hist__9->GetXaxis()->SetTitleFont(132);
   hist__9->GetYaxis()->SetTitle("#varepsilon");
   hist__9->GetYaxis()->SetLabelFont(132);
   hist__9->GetYaxis()->SetLabelSize(0.05);
   hist__9->GetYaxis()->SetTitleSize(0.06);
   hist__9->GetYaxis()->SetTitleOffset(0.8);
   hist__9->GetYaxis()->SetTitleFont(132);
   hist__9->GetZaxis()->SetLabelFont(42);
   hist__9->GetZaxis()->SetTitleOffset(1);
   hist__9->GetZaxis()->SetTitleFont(42);
   hist__9->Draw("AXIS");
   TLatex *   tex = new TLatex(0.855,0.875,"LHCb preliminary");
tex->SetNDC();
   tex->SetTextAlign(33);
   tex->SetTextFont(132);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.135,0.875,"Combined method");
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
   
   Double_t Graph0_fx3017[2] = {
   2.55,
   4.05};
   Double_t Graph0_fy3017[2] = {
   0.9645914,
   0.9610457};
   Double_t Graph0_felx3017[2] = {
   0.65,
   0.85};
   Double_t Graph0_fely3017[2] = {
   0.0006269092,
   0.0006283448};
   Double_t Graph0_fehx3017[2] = {
   0.65,
   0.85};
   Double_t Graph0_fehy3017[2] = {
   0.0006269398,
   0.0006328302};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(2,Graph0_fx3017,Graph0_fy3017,Graph0_felx3017,Graph0_fehx3017,Graph0_fely3017,Graph0_fehy3017);
   grae->SetName("Graph0");
   grae->SetTitle("");
   grae->SetFillStyle(1000);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph03017 = new TH1F("Graph_Graph03017","",100,1.6,5.2);
   Graph_Graph03017->SetMinimum(0.85);
   Graph_Graph03017->SetMaximum(1.05);
   Graph_Graph03017->SetDirectory(0);
   Graph_Graph03017->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph03017->SetLineColor(ci);
   Graph_Graph03017->GetXaxis()->SetTitle("#eta");
   Graph_Graph03017->GetXaxis()->SetLabelFont(132);
   Graph_Graph03017->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph03017->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph03017->GetXaxis()->SetTitleOffset(0.5);
   Graph_Graph03017->GetXaxis()->SetTitleFont(132);
   Graph_Graph03017->GetYaxis()->SetTitle("#varepsilon");
   Graph_Graph03017->GetYaxis()->SetLabelFont(132);
   Graph_Graph03017->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph03017->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph03017->GetYaxis()->SetTitleOffset(0.5);
   Graph_Graph03017->GetYaxis()->SetTitleFont(132);
   Graph_Graph03017->GetZaxis()->SetLabelFont(42);
   Graph_Graph03017->GetZaxis()->SetTitleOffset(1);
   Graph_Graph03017->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph03017);
   
   grae->Draw("p");
   
   Double_t Graph1_fx3018[2] = {
   2.55,
   4.05};
   Double_t Graph1_fy3018[2] = {
   0.9681381,
   0.9594597};
   Double_t Graph1_felx3018[2] = {
   0.65,
   0.85};
   Double_t Graph1_fely3018[2] = {
   0.0007447257,
   0.0005955258};
   Double_t Graph1_fehx3018[2] = {
   0.65,
   0.85};
   Double_t Graph1_fehy3018[2] = {
   0.0002865276,
   0.0002566091};
   grae = new TGraphAsymmErrors(2,Graph1_fx3018,Graph1_fy3018,Graph1_felx3018,Graph1_fehx3018,Graph1_fely3018,Graph1_fehy3018);
   grae->SetName("Graph1");
   grae->SetTitle("Graph");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph13018 = new TH1F("Graph_Graph13018","Graph",100,1.6,5.2);
   Graph_Graph13018->SetMinimum(0.9579082);
   Graph_Graph13018->SetMaximum(0.9693806);
   Graph_Graph13018->SetDirectory(0);
   Graph_Graph13018->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph13018->SetLineColor(ci);
   Graph_Graph13018->GetXaxis()->SetLabelFont(42);
   Graph_Graph13018->GetXaxis()->SetTitleOffset(1);
   Graph_Graph13018->GetXaxis()->SetTitleFont(42);
   Graph_Graph13018->GetYaxis()->SetLabelFont(42);
   Graph_Graph13018->GetYaxis()->SetTitleFont(42);
   Graph_Graph13018->GetZaxis()->SetLabelFont(42);
   Graph_Graph13018->GetZaxis()->SetTitleOffset(1);
   Graph_Graph13018->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph13018);
   
   grae->Draw("p");
   c_Combined->Modified();
   c_Combined->cd();
   c_Combined->SetSelected(c_Combined);
}
