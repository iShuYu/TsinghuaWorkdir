void ETA_Velo()
{
//=========Macro generated from canvas: c_Velo/c_Velo
//=========  (Mon Nov 22 01:50:53 2021) by ROOT version 6.20/06
   TCanvas *c_Velo = new TCanvas("c_Velo", "c_Velo",0,0,1000,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c_Velo->SetHighLightColor(2);
   c_Velo->Range(1.520253,0.81,5.317722,1.076667);
   c_Velo->SetFillColor(0);
   c_Velo->SetBorderMode(0);
   c_Velo->SetBorderSize(2);
   c_Velo->SetBottomMargin(0.15);
   c_Velo->SetFrameBorderMode(0);
   c_Velo->SetFrameBorderMode(0);
   
   TH1D *hist__7 = new TH1D("hist__7","",100,1.9,4.9);
   hist__7->SetMinimum(0.85);
   hist__7->SetMaximum(1.05);
   hist__7->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hist__7->SetLineColor(ci);
   hist__7->SetMarkerStyle(20);
   hist__7->GetXaxis()->SetTitle("#eta");
   hist__7->GetXaxis()->SetLabelFont(132);
   hist__7->GetXaxis()->SetLabelSize(0.05);
   hist__7->GetXaxis()->SetTitleSize(0.06);
   hist__7->GetXaxis()->SetTitleOffset(0.8);
   hist__7->GetXaxis()->SetTitleFont(132);
   hist__7->GetYaxis()->SetTitle("#varepsilon");
   hist__7->GetYaxis()->SetLabelFont(132);
   hist__7->GetYaxis()->SetLabelSize(0.05);
   hist__7->GetYaxis()->SetTitleSize(0.06);
   hist__7->GetYaxis()->SetTitleOffset(0.8);
   hist__7->GetYaxis()->SetTitleFont(132);
   hist__7->GetZaxis()->SetLabelFont(42);
   hist__7->GetZaxis()->SetTitleOffset(1);
   hist__7->GetZaxis()->SetTitleFont(42);
   hist__7->Draw("AXIS");
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
   
   Double_t Efficiency_ETA_fx3013[2] = {
   2.55,
   4.05};
   Double_t Efficiency_ETA_fy3013[2] = {
   0.9785504,
   0.9734287};
   Double_t Efficiency_ETA_felx3013[2] = {
   0.65,
   0.85};
   Double_t Efficiency_ETA_fely3013[2] = {
   0.0003764488,
   0.0003272432};
   Double_t Efficiency_ETA_fehx3013[2] = {
   0.65,
   0.85};
   Double_t Efficiency_ETA_fehy3013[2] = {
   0.0003759769,
   0.0003262737};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(2,Efficiency_ETA_fx3013,Efficiency_ETA_fy3013,Efficiency_ETA_felx3013,Efficiency_ETA_fehx3013,Efficiency_ETA_fely3013,Efficiency_ETA_fehy3013);
   grae->SetName("Efficiency_ETA");
   grae->SetTitle("");
   grae->SetFillStyle(1000);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Efficiency_ETA3013 = new TH1F("Graph_Efficiency_ETA3013","",100,1.6,5.2);
   Graph_Efficiency_ETA3013->SetMinimum(0.85);
   Graph_Efficiency_ETA3013->SetMaximum(1.05);
   Graph_Efficiency_ETA3013->SetDirectory(0);
   Graph_Efficiency_ETA3013->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Efficiency_ETA3013->SetLineColor(ci);
   Graph_Efficiency_ETA3013->GetXaxis()->SetTitle("#eta");
   Graph_Efficiency_ETA3013->GetXaxis()->SetLabelFont(132);
   Graph_Efficiency_ETA3013->GetXaxis()->SetLabelSize(0.05);
   Graph_Efficiency_ETA3013->GetXaxis()->SetTitleSize(0.06);
   Graph_Efficiency_ETA3013->GetXaxis()->SetTitleOffset(0.5);
   Graph_Efficiency_ETA3013->GetXaxis()->SetTitleFont(132);
   Graph_Efficiency_ETA3013->GetYaxis()->SetTitle("#varepsilon");
   Graph_Efficiency_ETA3013->GetYaxis()->SetLabelFont(132);
   Graph_Efficiency_ETA3013->GetYaxis()->SetLabelSize(0.05);
   Graph_Efficiency_ETA3013->GetYaxis()->SetTitleSize(0.06);
   Graph_Efficiency_ETA3013->GetYaxis()->SetTitleOffset(0.5);
   Graph_Efficiency_ETA3013->GetYaxis()->SetTitleFont(132);
   Graph_Efficiency_ETA3013->GetZaxis()->SetLabelFont(42);
   Graph_Efficiency_ETA3013->GetZaxis()->SetTitleOffset(1);
   Graph_Efficiency_ETA3013->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Efficiency_ETA3013);
   
   grae->Draw("p");
   
   Double_t Efficiency_ETA_fx3014[2] = {
   2.55,
   4.05};
   Double_t Efficiency_ETA_fy3014[2] = {
   0.9779391,
   0.9690586};
   Double_t Efficiency_ETA_felx3014[2] = {
   0.65,
   0.85};
   Double_t Efficiency_ETA_fely3014[2] = {
   0.0005982048,
   0.00734393};
   Double_t Efficiency_ETA_fehx3014[2] = {
   0.65,
   0.85};
   Double_t Efficiency_ETA_fehy3014[2] = {
   0.0002726799,
   0.0003029009};
   grae = new TGraphAsymmErrors(2,Efficiency_ETA_fx3014,Efficiency_ETA_fy3014,Efficiency_ETA_felx3014,Efficiency_ETA_fehx3014,Efficiency_ETA_fely3014,Efficiency_ETA_fehy3014);
   grae->SetName("Efficiency_ETA");
   grae->SetTitle("Efficiency_ETA");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Efficiency_ETA3014 = new TH1F("Graph_Efficiency_ETA3014","Efficiency_ETA",100,1.6,5.2);
   Graph_Efficiency_ETA3014->SetMinimum(0.9600649);
   Graph_Efficiency_ETA3014->SetMaximum(0.9798615);
   Graph_Efficiency_ETA3014->SetDirectory(0);
   Graph_Efficiency_ETA3014->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Efficiency_ETA3014->SetLineColor(ci);
   Graph_Efficiency_ETA3014->GetXaxis()->SetLabelFont(42);
   Graph_Efficiency_ETA3014->GetXaxis()->SetTitleOffset(1);
   Graph_Efficiency_ETA3014->GetXaxis()->SetTitleFont(42);
   Graph_Efficiency_ETA3014->GetYaxis()->SetLabelFont(42);
   Graph_Efficiency_ETA3014->GetYaxis()->SetTitleFont(42);
   Graph_Efficiency_ETA3014->GetZaxis()->SetLabelFont(42);
   Graph_Efficiency_ETA3014->GetZaxis()->SetTitleOffset(1);
   Graph_Efficiency_ETA3014->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Efficiency_ETA3014);
   
   grae->Draw("p");
   c_Velo->Modified();
   c_Velo->cd();
   c_Velo->SetSelected(c_Velo);
}
