void ETA_T()
{
//=========Macro generated from canvas: c_T/c_T
//=========  (Mon Nov 22 01:50:53 2021) by ROOT version 6.20/06
   TCanvas *c_T = new TCanvas("c_T", "c_T",0,0,1000,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c_T->SetHighLightColor(2);
   c_T->Range(1.520253,0.81,5.317722,1.076667);
   c_T->SetFillColor(0);
   c_T->SetBorderMode(0);
   c_T->SetBorderSize(2);
   c_T->SetBottomMargin(0.15);
   c_T->SetFrameBorderMode(0);
   c_T->SetFrameBorderMode(0);
   
   TH1D *hist__6 = new TH1D("hist__6","",100,1.9,4.9);
   hist__6->SetMinimum(0.85);
   hist__6->SetMaximum(1.05);
   hist__6->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hist__6->SetLineColor(ci);
   hist__6->SetMarkerStyle(20);
   hist__6->GetXaxis()->SetTitle("#eta");
   hist__6->GetXaxis()->SetLabelFont(132);
   hist__6->GetXaxis()->SetLabelSize(0.05);
   hist__6->GetXaxis()->SetTitleSize(0.06);
   hist__6->GetXaxis()->SetTitleOffset(0.8);
   hist__6->GetXaxis()->SetTitleFont(132);
   hist__6->GetYaxis()->SetTitle("#varepsilon");
   hist__6->GetYaxis()->SetLabelFont(132);
   hist__6->GetYaxis()->SetLabelSize(0.05);
   hist__6->GetYaxis()->SetTitleSize(0.06);
   hist__6->GetYaxis()->SetTitleOffset(0.8);
   hist__6->GetYaxis()->SetTitleFont(132);
   hist__6->GetZaxis()->SetLabelFont(42);
   hist__6->GetZaxis()->SetTitleOffset(1);
   hist__6->GetZaxis()->SetTitleFont(42);
   hist__6->Draw("AXIS");
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
   
   Double_t Efficiency_ETA_fx3011[2] = {
   2.55,
   4.05};
   Double_t Efficiency_ETA_fy3011[2] = {
   0.9871821,
   0.9871874};
   Double_t Efficiency_ETA_felx3011[2] = {
   0.65,
   0.85};
   Double_t Efficiency_ETA_fely3011[2] = {
   0.000402365,
   0.0004409944};
   Double_t Efficiency_ETA_fehx3011[2] = {
   0.65,
   0.85};
   Double_t Efficiency_ETA_fehy3011[2] = {
   0.0004024496,
   0.00044119};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(2,Efficiency_ETA_fx3011,Efficiency_ETA_fy3011,Efficiency_ETA_felx3011,Efficiency_ETA_fehx3011,Efficiency_ETA_fely3011,Efficiency_ETA_fehy3011);
   grae->SetName("Efficiency_ETA");
   grae->SetTitle("");
   grae->SetFillStyle(1000);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Efficiency_ETA3011 = new TH1F("Graph_Efficiency_ETA3011","",100,1.6,5.2);
   Graph_Efficiency_ETA3011->SetMinimum(0.85);
   Graph_Efficiency_ETA3011->SetMaximum(1.05);
   Graph_Efficiency_ETA3011->SetDirectory(0);
   Graph_Efficiency_ETA3011->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Efficiency_ETA3011->SetLineColor(ci);
   Graph_Efficiency_ETA3011->GetXaxis()->SetTitle("#eta");
   Graph_Efficiency_ETA3011->GetXaxis()->SetLabelFont(132);
   Graph_Efficiency_ETA3011->GetXaxis()->SetLabelSize(0.05);
   Graph_Efficiency_ETA3011->GetXaxis()->SetTitleSize(0.06);
   Graph_Efficiency_ETA3011->GetXaxis()->SetTitleOffset(0.5);
   Graph_Efficiency_ETA3011->GetXaxis()->SetTitleFont(132);
   Graph_Efficiency_ETA3011->GetYaxis()->SetTitle("#varepsilon");
   Graph_Efficiency_ETA3011->GetYaxis()->SetLabelFont(132);
   Graph_Efficiency_ETA3011->GetYaxis()->SetLabelSize(0.05);
   Graph_Efficiency_ETA3011->GetYaxis()->SetTitleSize(0.06);
   Graph_Efficiency_ETA3011->GetYaxis()->SetTitleOffset(0.5);
   Graph_Efficiency_ETA3011->GetYaxis()->SetTitleFont(132);
   Graph_Efficiency_ETA3011->GetZaxis()->SetLabelFont(42);
   Graph_Efficiency_ETA3011->GetZaxis()->SetTitleOffset(1);
   Graph_Efficiency_ETA3011->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Efficiency_ETA3011);
   
   grae->Draw("p");
   
   Double_t Efficiency_ETA_fx3012[2] = {
   2.55,
   4.05};
   Double_t Efficiency_ETA_fy3012[2] = {
   0.9914261,
   0.9892642};
   Double_t Efficiency_ETA_felx3012[2] = {
   0.65,
   0.85};
   Double_t Efficiency_ETA_fely3012[2] = {
   0.0004957697,
   0.0003595254};
   Double_t Efficiency_ETA_fehx3012[2] = {
   0.65,
   0.85};
   Double_t Efficiency_ETA_fehy3012[2] = {
   9.172552e-05,
   0.0001274845};
   grae = new TGraphAsymmErrors(2,Efficiency_ETA_fx3012,Efficiency_ETA_fy3012,Efficiency_ETA_felx3012,Efficiency_ETA_fehx3012,Efficiency_ETA_fely3012,Efficiency_ETA_fehy3012);
   grae->SetName("Efficiency_ETA");
   grae->SetTitle("Efficiency_ETA");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Efficiency_ETA3012 = new TH1F("Graph_Efficiency_ETA3012","Efficiency_ETA",100,1.6,5.2);
   Graph_Efficiency_ETA3012->SetMinimum(0.9886434);
   Graph_Efficiency_ETA3012->SetMaximum(0.9917792);
   Graph_Efficiency_ETA3012->SetDirectory(0);
   Graph_Efficiency_ETA3012->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Efficiency_ETA3012->SetLineColor(ci);
   Graph_Efficiency_ETA3012->GetXaxis()->SetLabelFont(42);
   Graph_Efficiency_ETA3012->GetXaxis()->SetTitleOffset(1);
   Graph_Efficiency_ETA3012->GetXaxis()->SetTitleFont(42);
   Graph_Efficiency_ETA3012->GetYaxis()->SetLabelFont(42);
   Graph_Efficiency_ETA3012->GetYaxis()->SetTitleFont(42);
   Graph_Efficiency_ETA3012->GetZaxis()->SetLabelFont(42);
   Graph_Efficiency_ETA3012->GetZaxis()->SetTitleOffset(1);
   Graph_Efficiency_ETA3012->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Efficiency_ETA3012);
   
   grae->Draw("p");
   c_T->Modified();
   c_T->cd();
   c_T->SetSelected(c_T);
}
