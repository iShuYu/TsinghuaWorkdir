void P_Final()
{
//=========Macro generated from canvas: c_Final/c_Final
//=========  (Mon Nov 22 01:49:56 2021) by ROOT version 6.20/06
   TCanvas *c_Final = new TCanvas("c_Final", "c_Final",0,0,1000,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c_Final->SetHighLightColor(2);
   c_Final->Range(-19683.55,0.81,227151.9,1.076667);
   c_Final->SetFillColor(0);
   c_Final->SetBorderMode(0);
   c_Final->SetBorderSize(2);
   c_Final->SetBottomMargin(0.15);
   c_Final->SetFrameBorderMode(0);
   c_Final->SetFrameBorderMode(0);
   
   TH1D *hist__5 = new TH1D("hist__5","",100,5000,200000);
   hist__5->SetMinimum(0.85);
   hist__5->SetMaximum(1.05);
   hist__5->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hist__5->SetLineColor(ci);
   hist__5->SetMarkerStyle(20);
   hist__5->GetXaxis()->SetTitle("#it{p} [MeV/#it{c}]");
   hist__5->GetXaxis()->SetLabelFont(132);
   hist__5->GetXaxis()->SetLabelSize(0.05);
   hist__5->GetXaxis()->SetTitleSize(0.06);
   hist__5->GetXaxis()->SetTitleOffset(0.8);
   hist__5->GetXaxis()->SetTitleFont(132);
   hist__5->GetYaxis()->SetTitle("#varepsilon");
   hist__5->GetYaxis()->SetLabelFont(132);
   hist__5->GetYaxis()->SetLabelSize(0.05);
   hist__5->GetYaxis()->SetTitleSize(0.06);
   hist__5->GetYaxis()->SetTitleOffset(0.8);
   hist__5->GetYaxis()->SetTitleFont(132);
   hist__5->GetZaxis()->SetLabelFont(42);
   hist__5->GetZaxis()->SetTitleOffset(1);
   hist__5->GetZaxis()->SetTitleFont(42);
   hist__5->Draw("AXIS");
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
   
   Double_t Graph0_fx3009[5] = {
   7500,
   15000,
   30000,
   70000,
   150000};
   Double_t Graph0_fy3009[5] = {
   0.9413816,
   0.9630067,
   0.967003,
   0.9604826,
   0.9484959};
   Double_t Graph0_felx3009[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Graph0_fely3009[5] = {
   0.004771317,
   0.0008750545,
   0.0005756799,
   0.0006319337,
   0.001575033};
   Double_t Graph0_fehx3009[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Graph0_fehy3009[5] = {
   0.002387745,
   0.0008598237,
   0.0005773497,
   0.0005621508,
   0.001587149};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,Graph0_fx3009,Graph0_fy3009,Graph0_felx3009,Graph0_fehx3009,Graph0_fely3009,Graph0_fehy3009);
   grae->SetName("Graph0");
   grae->SetTitle("");
   grae->SetFillStyle(1000);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph03009 = new TH1F("Graph_Graph03009","",100,0,219500);
   Graph_Graph03009->SetMinimum(0.85);
   Graph_Graph03009->SetMaximum(1.05);
   Graph_Graph03009->SetDirectory(0);
   Graph_Graph03009->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph03009->SetLineColor(ci);
   Graph_Graph03009->GetXaxis()->SetTitle("#it{p} [MeV/#it{c}]");
   Graph_Graph03009->GetXaxis()->SetLabelFont(132);
   Graph_Graph03009->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph03009->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph03009->GetXaxis()->SetTitleOffset(0.5);
   Graph_Graph03009->GetXaxis()->SetTitleFont(132);
   Graph_Graph03009->GetYaxis()->SetTitle("#varepsilon");
   Graph_Graph03009->GetYaxis()->SetLabelFont(132);
   Graph_Graph03009->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph03009->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph03009->GetYaxis()->SetTitleOffset(0.5);
   Graph_Graph03009->GetYaxis()->SetTitleFont(132);
   Graph_Graph03009->GetZaxis()->SetLabelFont(42);
   Graph_Graph03009->GetZaxis()->SetTitleOffset(1);
   Graph_Graph03009->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph03009);
   
   grae->Draw("p");
   
   Double_t Graph1_fx3010[5] = {
   7500,
   15000,
   30000,
   70000,
   150000};
   Double_t Graph1_fy3010[5] = {
   0.9522173,
   0.9679895,
   0.9671865,
   0.9604239,
   0.9436054};
   Double_t Graph1_felx3010[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Graph1_fely3010[5] = {
   0.002430063,
   0.0008334281,
   0.000561943,
   0.0005304215,
   0.001744923};
   Double_t Graph1_fehx3010[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Graph1_fehy3010[5] = {
   0.001102991,
   0.0003869624,
   0.0002562124,
   0.0002459611,
   0.0006293329};
   grae = new TGraphAsymmErrors(5,Graph1_fx3010,Graph1_fy3010,Graph1_felx3010,Graph1_fehx3010,Graph1_fely3010,Graph1_fehy3010);
   grae->SetName("Graph1");
   grae->SetTitle("Graph");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph13010 = new TH1F("Graph_Graph13010","Graph",100,0,219500);
   Graph_Graph13010->SetMinimum(0.9392089);
   Graph_Graph13010->SetMaximum(0.971028);
   Graph_Graph13010->SetDirectory(0);
   Graph_Graph13010->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph13010->SetLineColor(ci);
   Graph_Graph13010->GetXaxis()->SetLabelFont(42);
   Graph_Graph13010->GetXaxis()->SetTitleOffset(1);
   Graph_Graph13010->GetXaxis()->SetTitleFont(42);
   Graph_Graph13010->GetYaxis()->SetLabelFont(42);
   Graph_Graph13010->GetYaxis()->SetTitleFont(42);
   Graph_Graph13010->GetZaxis()->SetLabelFont(42);
   Graph_Graph13010->GetZaxis()->SetTitleOffset(1);
   Graph_Graph13010->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph13010);
   
   grae->Draw("p");
   c_Final->Modified();
   c_Final->cd();
   c_Final->SetSelected(c_Final);
}
