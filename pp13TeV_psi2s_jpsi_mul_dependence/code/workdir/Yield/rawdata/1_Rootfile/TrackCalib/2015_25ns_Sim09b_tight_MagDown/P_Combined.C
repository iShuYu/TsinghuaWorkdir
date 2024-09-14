void P_Combined()
{
//=========Macro generated from canvas: c_Combined/c_Combined
//=========  (Mon Nov 22 01:50:53 2021) by ROOT version 6.20/06
   TCanvas *c_Combined = new TCanvas("c_Combined", "c_Combined",0,0,1000,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c_Combined->SetHighLightColor(2);
   c_Combined->Range(-19683.55,0.81,227151.9,1.076667);
   c_Combined->SetFillColor(0);
   c_Combined->SetBorderMode(0);
   c_Combined->SetBorderSize(2);
   c_Combined->SetBottomMargin(0.15);
   c_Combined->SetFrameBorderMode(0);
   c_Combined->SetFrameBorderMode(0);
   
   TH1D *hist__4 = new TH1D("hist__4","",100,5000,200000);
   hist__4->SetMinimum(0.85);
   hist__4->SetMaximum(1.05);
   hist__4->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hist__4->SetLineColor(ci);
   hist__4->SetMarkerStyle(20);
   hist__4->GetXaxis()->SetTitle("#it{p} [MeV/#it{c}]");
   hist__4->GetXaxis()->SetLabelFont(132);
   hist__4->GetXaxis()->SetLabelSize(0.05);
   hist__4->GetXaxis()->SetTitleSize(0.06);
   hist__4->GetXaxis()->SetTitleOffset(0.8);
   hist__4->GetXaxis()->SetTitleFont(132);
   hist__4->GetYaxis()->SetTitle("#varepsilon");
   hist__4->GetYaxis()->SetLabelFont(132);
   hist__4->GetYaxis()->SetLabelSize(0.05);
   hist__4->GetYaxis()->SetTitleSize(0.06);
   hist__4->GetYaxis()->SetTitleOffset(0.8);
   hist__4->GetYaxis()->SetTitleFont(132);
   hist__4->GetZaxis()->SetLabelFont(42);
   hist__4->GetZaxis()->SetTitleOffset(1);
   hist__4->GetZaxis()->SetTitleFont(42);
   hist__4->Draw("AXIS");
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
   
   Double_t Graph0_fx3007[5] = {
   7500,
   15000,
   30000,
   70000,
   150000};
   Double_t Graph0_fy3007[5] = {
   0.9384635,
   0.9636009,
   0.9678951,
   0.9628518,
   0.9404517};
   Double_t Graph0_felx3007[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Graph0_fely3007[5] = {
   0.003158469,
   0.0007920835,
   0.0005519147,
   0.0005678405,
   0.001674411};
   Double_t Graph0_fehx3007[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Graph0_fehy3007[5] = {
   0.002261701,
   0.0007948871,
   0.0005546334,
   0.0005380053,
   0.00167402};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,Graph0_fx3007,Graph0_fy3007,Graph0_felx3007,Graph0_fehx3007,Graph0_fely3007,Graph0_fehy3007);
   grae->SetName("Graph0");
   grae->SetTitle("");
   grae->SetFillStyle(1000);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph03007 = new TH1F("Graph_Graph03007","",100,0,219500);
   Graph_Graph03007->SetMinimum(0.85);
   Graph_Graph03007->SetMaximum(1.05);
   Graph_Graph03007->SetDirectory(0);
   Graph_Graph03007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph03007->SetLineColor(ci);
   Graph_Graph03007->GetXaxis()->SetTitle("#it{p} [MeV/#it{c}]");
   Graph_Graph03007->GetXaxis()->SetLabelFont(132);
   Graph_Graph03007->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph03007->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph03007->GetXaxis()->SetTitleOffset(0.5);
   Graph_Graph03007->GetXaxis()->SetTitleFont(132);
   Graph_Graph03007->GetYaxis()->SetTitle("#varepsilon");
   Graph_Graph03007->GetYaxis()->SetLabelFont(132);
   Graph_Graph03007->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph03007->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph03007->GetYaxis()->SetTitleOffset(0.5);
   Graph_Graph03007->GetYaxis()->SetTitleFont(132);
   Graph_Graph03007->GetZaxis()->SetLabelFont(42);
   Graph_Graph03007->GetZaxis()->SetTitleOffset(1);
   Graph_Graph03007->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph03007);
   
   grae->Draw("p");
   
   Double_t Graph1_fx3008[5] = {
   7500,
   15000,
   30000,
   70000,
   150000};
   Double_t Graph1_fy3008[5] = {
   0.9490159,
   0.9704082,
   0.9700474,
   0.9623207,
   0.9347034};
   Double_t Graph1_felx3008[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Graph1_fely3008[5] = {
   0.003882781,
   0.001091752,
   0.000711771,
   0.000686407,
   0.001722138};
   Double_t Graph1_fehx3008[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Graph1_fehy3008[5] = {
   0.001290442,
   0.0005300961,
   0.0003454825,
   0.0003157146,
   0.0008198514};
   grae = new TGraphAsymmErrors(5,Graph1_fx3008,Graph1_fy3008,Graph1_felx3008,Graph1_fehx3008,Graph1_fely3008,Graph1_fehy3008);
   grae->SetName("Graph1");
   grae->SetTitle("Graph");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph13008 = new TH1F("Graph_Graph13008","Graph",100,0,219500);
   Graph_Graph13008->SetMinimum(0.9291856);
   Graph_Graph13008->SetMaximum(0.974734);
   Graph_Graph13008->SetDirectory(0);
   Graph_Graph13008->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph13008->SetLineColor(ci);
   Graph_Graph13008->GetXaxis()->SetLabelFont(42);
   Graph_Graph13008->GetXaxis()->SetTitleOffset(1);
   Graph_Graph13008->GetXaxis()->SetTitleFont(42);
   Graph_Graph13008->GetYaxis()->SetLabelFont(42);
   Graph_Graph13008->GetYaxis()->SetTitleFont(42);
   Graph_Graph13008->GetZaxis()->SetLabelFont(42);
   Graph_Graph13008->GetZaxis()->SetTitleOffset(1);
   Graph_Graph13008->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph13008);
   
   grae->Draw("p");
   c_Combined->Modified();
   c_Combined->cd();
   c_Combined->SetSelected(c_Combined);
}
