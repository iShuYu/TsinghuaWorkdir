void ETA_Long()
{
//=========Macro generated from canvas: c_Long/c_Long
//=========  (Mon Nov 22 01:49:56 2021) by ROOT version 6.20/06
   TCanvas *c_Long = new TCanvas("c_Long", "c_Long",0,0,1000,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c_Long->SetHighLightColor(2);
   c_Long->Range(1.520253,0.81,5.317722,1.076667);
   c_Long->SetFillColor(0);
   c_Long->SetBorderMode(0);
   c_Long->SetBorderSize(2);
   c_Long->SetBottomMargin(0.15);
   c_Long->SetFrameBorderMode(0);
   c_Long->SetFrameBorderMode(0);
   
   TH1D *hist__8 = new TH1D("hist__8","",100,1.9,4.9);
   hist__8->SetMinimum(0.85);
   hist__8->SetMaximum(1.05);
   hist__8->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hist__8->SetLineColor(ci);
   hist__8->SetMarkerStyle(20);
   hist__8->GetXaxis()->SetTitle("#eta");
   hist__8->GetXaxis()->SetLabelFont(132);
   hist__8->GetXaxis()->SetLabelSize(0.05);
   hist__8->GetXaxis()->SetTitleSize(0.06);
   hist__8->GetXaxis()->SetTitleOffset(0.8);
   hist__8->GetXaxis()->SetTitleFont(132);
   hist__8->GetYaxis()->SetTitle("#varepsilon");
   hist__8->GetYaxis()->SetLabelFont(132);
   hist__8->GetYaxis()->SetLabelSize(0.05);
   hist__8->GetYaxis()->SetTitleSize(0.06);
   hist__8->GetYaxis()->SetTitleOffset(0.8);
   hist__8->GetYaxis()->SetTitleFont(132);
   hist__8->GetZaxis()->SetLabelFont(42);
   hist__8->GetZaxis()->SetTitleOffset(1);
   hist__8->GetZaxis()->SetTitleFont(42);
   hist__8->Draw("AXIS");
   TLatex *   tex = new TLatex(0.855,0.875,"LHCb preliminary");
tex->SetNDC();
   tex->SetTextAlign(33);
   tex->SetTextFont(132);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.135,0.875,"Long method");
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
   TLegendEntry *entry=leg->AddEntry("Efficiency_ETA","2015 Data, 25ns","PL");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("Efficiency_ETA","2015 MC, Sim09b","PL");

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
   
   Double_t Efficiency_ETA_fx3015[2] = {
   2.55,
   4.05};
   Double_t Efficiency_ETA_fy3015[2] = {
   0.9664379,
   0.9540282};
   Double_t Efficiency_ETA_felx3015[2] = {
   0.65,
   0.85};
   Double_t Efficiency_ETA_fely3015[2] = {
   0.001398132,
   0.001349805};
   Double_t Efficiency_ETA_fehx3015[2] = {
   0.65,
   0.85};
   Double_t Efficiency_ETA_fehy3015[2] = {
   0.001398083,
   0.001351422};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(2,Efficiency_ETA_fx3015,Efficiency_ETA_fy3015,Efficiency_ETA_felx3015,Efficiency_ETA_fehx3015,Efficiency_ETA_fely3015,Efficiency_ETA_fehy3015);
   grae->SetName("Efficiency_ETA");
   grae->SetTitle("");
   grae->SetFillStyle(1000);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Efficiency_ETA3015 = new TH1F("Graph_Efficiency_ETA3015","",100,1.6,5.2);
   Graph_Efficiency_ETA3015->SetMinimum(0.85);
   Graph_Efficiency_ETA3015->SetMaximum(1.05);
   Graph_Efficiency_ETA3015->SetDirectory(0);
   Graph_Efficiency_ETA3015->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Efficiency_ETA3015->SetLineColor(ci);
   Graph_Efficiency_ETA3015->GetXaxis()->SetTitle("#eta");
   Graph_Efficiency_ETA3015->GetXaxis()->SetLabelFont(132);
   Graph_Efficiency_ETA3015->GetXaxis()->SetLabelSize(0.05);
   Graph_Efficiency_ETA3015->GetXaxis()->SetTitleSize(0.06);
   Graph_Efficiency_ETA3015->GetXaxis()->SetTitleOffset(0.5);
   Graph_Efficiency_ETA3015->GetXaxis()->SetTitleFont(132);
   Graph_Efficiency_ETA3015->GetYaxis()->SetTitle("#varepsilon");
   Graph_Efficiency_ETA3015->GetYaxis()->SetLabelFont(132);
   Graph_Efficiency_ETA3015->GetYaxis()->SetLabelSize(0.05);
   Graph_Efficiency_ETA3015->GetYaxis()->SetTitleSize(0.06);
   Graph_Efficiency_ETA3015->GetYaxis()->SetTitleOffset(0.5);
   Graph_Efficiency_ETA3015->GetYaxis()->SetTitleFont(132);
   Graph_Efficiency_ETA3015->GetZaxis()->SetLabelFont(42);
   Graph_Efficiency_ETA3015->GetZaxis()->SetTitleOffset(1);
   Graph_Efficiency_ETA3015->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Efficiency_ETA3015);
   
   grae->Draw("p");
   
   Double_t Efficiency_ETA_fx3016[2] = {
   2.55,
   4.05};
   Double_t Efficiency_ETA_fy3016[2] = {
   0.9681619,
   0.9576151};
   Double_t Efficiency_ETA_felx3016[2] = {
   0.65,
   0.85};
   Double_t Efficiency_ETA_fely3016[2] = {
   0.0008979268,
   0.0007346386};
   Double_t Efficiency_ETA_fehx3016[2] = {
   0.65,
   0.85};
   Double_t Efficiency_ETA_fehy3016[2] = {
   0.0003981663,
   0.0003096393};
   grae = new TGraphAsymmErrors(2,Efficiency_ETA_fx3016,Efficiency_ETA_fy3016,Efficiency_ETA_felx3016,Efficiency_ETA_fehx3016,Efficiency_ETA_fely3016,Efficiency_ETA_fehy3016);
   grae->SetName("Efficiency_ETA");
   grae->SetTitle("Efficiency_ETA");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Efficiency_ETA3016 = new TH1F("Graph_Efficiency_ETA3016","Efficiency_ETA",100,1.6,5.2);
   Graph_Efficiency_ETA3016->SetMinimum(0.9557125);
   Graph_Efficiency_ETA3016->SetMaximum(0.969728);
   Graph_Efficiency_ETA3016->SetDirectory(0);
   Graph_Efficiency_ETA3016->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Efficiency_ETA3016->SetLineColor(ci);
   Graph_Efficiency_ETA3016->GetXaxis()->SetLabelFont(42);
   Graph_Efficiency_ETA3016->GetXaxis()->SetTitleOffset(1);
   Graph_Efficiency_ETA3016->GetXaxis()->SetTitleFont(42);
   Graph_Efficiency_ETA3016->GetYaxis()->SetLabelFont(42);
   Graph_Efficiency_ETA3016->GetYaxis()->SetTitleFont(42);
   Graph_Efficiency_ETA3016->GetZaxis()->SetLabelFont(42);
   Graph_Efficiency_ETA3016->GetZaxis()->SetTitleOffset(1);
   Graph_Efficiency_ETA3016->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Efficiency_ETA3016);
   
   grae->Draw("p");
   c_Long->Modified();
   c_Long->cd();
   c_Long->SetSelected(c_Long);
}
