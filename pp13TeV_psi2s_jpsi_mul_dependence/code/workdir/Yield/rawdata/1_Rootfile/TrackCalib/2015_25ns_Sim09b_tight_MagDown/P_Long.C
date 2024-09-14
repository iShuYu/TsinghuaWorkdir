void P_Long()
{
//=========Macro generated from canvas: c_Long/c_Long
//=========  (Mon Nov 22 01:50:53 2021) by ROOT version 6.20/06
   TCanvas *c_Long = new TCanvas("c_Long", "c_Long",0,0,1000,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c_Long->SetHighLightColor(2);
   c_Long->Range(-19683.55,0.81,227151.9,1.076667);
   c_Long->SetFillColor(0);
   c_Long->SetBorderMode(0);
   c_Long->SetBorderSize(2);
   c_Long->SetBottomMargin(0.15);
   c_Long->SetFrameBorderMode(0);
   c_Long->SetFrameBorderMode(0);
   
   TH1D *hist__3 = new TH1D("hist__3","",100,5000,200000);
   hist__3->SetMinimum(0.85);
   hist__3->SetMaximum(1.05);
   hist__3->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hist__3->SetLineColor(ci);
   hist__3->SetMarkerStyle(20);
   hist__3->GetXaxis()->SetTitle("#it{p} [MeV/#it{c}]");
   hist__3->GetXaxis()->SetLabelFont(132);
   hist__3->GetXaxis()->SetLabelSize(0.05);
   hist__3->GetXaxis()->SetTitleSize(0.06);
   hist__3->GetXaxis()->SetTitleOffset(0.8);
   hist__3->GetXaxis()->SetTitleFont(132);
   hist__3->GetYaxis()->SetTitle("#varepsilon");
   hist__3->GetYaxis()->SetLabelFont(132);
   hist__3->GetYaxis()->SetLabelSize(0.05);
   hist__3->GetYaxis()->SetTitleSize(0.06);
   hist__3->GetYaxis()->SetTitleOffset(0.8);
   hist__3->GetYaxis()->SetTitleFont(132);
   hist__3->GetZaxis()->SetLabelFont(42);
   hist__3->GetZaxis()->SetTitleOffset(1);
   hist__3->GetZaxis()->SetTitleFont(42);
   hist__3->Draw("AXIS");
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
   
   Double_t Efficiency_P_fx3005[5] = {
   7500,
   15000,
   30000,
   70000,
   150000};
   Double_t Efficiency_P_fy3005[5] = {
   0.9258387,
   0.9641422,
   0.9644061,
   0.9576031,
   0.9532884};
   Double_t Efficiency_P_felx3005[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Efficiency_P_fely3005[5] = {
   0.0110401,
   0.00335946,
   0.001043501,
   0.0009858887,
   0.005058591};
   Double_t Efficiency_P_fehx3005[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Efficiency_P_fehy3005[5] = {
   0.01114443,
   0.002206106,
   0.001043154,
   0.0009848505,
   0.002469392};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,Efficiency_P_fx3005,Efficiency_P_fy3005,Efficiency_P_felx3005,Efficiency_P_fehx3005,Efficiency_P_fely3005,Efficiency_P_fehy3005);
   grae->SetName("Efficiency_P");
   grae->SetTitle("");
   grae->SetFillStyle(1000);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Efficiency_P3005 = new TH1F("Graph_Efficiency_P3005","",100,0,219500);
   Graph_Efficiency_P3005->SetMinimum(0.85);
   Graph_Efficiency_P3005->SetMaximum(1.05);
   Graph_Efficiency_P3005->SetDirectory(0);
   Graph_Efficiency_P3005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Efficiency_P3005->SetLineColor(ci);
   Graph_Efficiency_P3005->GetXaxis()->SetTitle("#it{p} [MeV/#it{c}]");
   Graph_Efficiency_P3005->GetXaxis()->SetLabelFont(132);
   Graph_Efficiency_P3005->GetXaxis()->SetLabelSize(0.05);
   Graph_Efficiency_P3005->GetXaxis()->SetTitleSize(0.06);
   Graph_Efficiency_P3005->GetXaxis()->SetTitleOffset(0.5);
   Graph_Efficiency_P3005->GetXaxis()->SetTitleFont(132);
   Graph_Efficiency_P3005->GetYaxis()->SetTitle("#varepsilon");
   Graph_Efficiency_P3005->GetYaxis()->SetLabelFont(132);
   Graph_Efficiency_P3005->GetYaxis()->SetLabelSize(0.05);
   Graph_Efficiency_P3005->GetYaxis()->SetTitleSize(0.06);
   Graph_Efficiency_P3005->GetYaxis()->SetTitleOffset(0.5);
   Graph_Efficiency_P3005->GetYaxis()->SetTitleFont(132);
   Graph_Efficiency_P3005->GetZaxis()->SetLabelFont(42);
   Graph_Efficiency_P3005->GetZaxis()->SetTitleOffset(1);
   Graph_Efficiency_P3005->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Efficiency_P3005);
   
   grae->Draw("p");
   
   Double_t Efficiency_P_fx3006[5] = {
   7500,
   15000,
   30000,
   70000,
   150000};
   Double_t Efficiency_P_fy3006[5] = {
   0.958624,
   0.9679754,
   0.9657621,
   0.9576415,
   0.9403722};
   Double_t Efficiency_P_felx3006[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Efficiency_P_fely3006[5] = {
   0.004590261,
   0.001308403,
   0.0008863305,
   0.0008921427,
   0.002108521};
   Double_t Efficiency_P_fehx3006[5] = {
   2500,
   5000,
   10000,
   30000,
   50000};
   Double_t Efficiency_P_fehy3006[5] = {
   0.001335397,
   0.0005601904,
   0.0004169168,
   0.0004354875,
   0.0009337958};
   grae = new TGraphAsymmErrors(5,Efficiency_P_fx3006,Efficiency_P_fy3006,Efficiency_P_felx3006,Efficiency_P_fehx3006,Efficiency_P_fely3006,Efficiency_P_fehy3006);
   grae->SetName("Efficiency_P");
   grae->SetTitle("Efficiency_P");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Efficiency_P3006 = new TH1F("Graph_Efficiency_P3006","Efficiency_P",100,0,219500);
   Graph_Efficiency_P3006->SetMinimum(0.9352365);
   Graph_Efficiency_P3006->SetMaximum(0.9715627);
   Graph_Efficiency_P3006->SetDirectory(0);
   Graph_Efficiency_P3006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Efficiency_P3006->SetLineColor(ci);
   Graph_Efficiency_P3006->GetXaxis()->SetLabelFont(42);
   Graph_Efficiency_P3006->GetXaxis()->SetTitleOffset(1);
   Graph_Efficiency_P3006->GetXaxis()->SetTitleFont(42);
   Graph_Efficiency_P3006->GetYaxis()->SetLabelFont(42);
   Graph_Efficiency_P3006->GetYaxis()->SetTitleFont(42);
   Graph_Efficiency_P3006->GetZaxis()->SetLabelFont(42);
   Graph_Efficiency_P3006->GetZaxis()->SetTitleOffset(1);
   Graph_Efficiency_P3006->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Efficiency_P3006);
   
   grae->Draw("p");
   c_Long->Modified();
   c_Long->cd();
   c_Long->SetSelected(c_Long);
}
