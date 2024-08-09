#ifdef __CLING__
#pragma cling optimize(0)
#endif
void All()
{
//=========Macro generated from canvas: can/can
//=========  (Tue Apr 16 11:07:13 2024) by ROOT version 6.30/06
   TCanvas *can = new TCanvas("can", "can",0,0,1600,1200);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   can->SetHighLightColor(2);
   can->Range(-0.9973333,0.4379747,4.869333,1.450633);
   can->SetFillColor(0);
   can->SetBorderMode(0);
   can->SetBorderSize(2);
   can->SetTickx(1);
   can->SetTicky(1);
   can->SetLeftMargin(0.17);
   can->SetRightMargin(0.08);
   can->SetTopMargin(0.05);
   can->SetBottomMargin(0.16);
   can->SetFrameLineWidth(2);
   can->SetFrameBorderMode(0);
   can->SetFrameLineWidth(2);
   can->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[38] = { 0.35, 0.45, 0.55, 0.65, 0.75, 0.85, 0.95, 1.05, 1.15, 1.25, 1.35, 1.45, 1.55, 1.65, 1.75, 1.85, 1.95,
   2.05, 2.15, 2.25, 2.35, 2.45, 2.55, 2.65, 2.75, 2.85, 2.95, 3.05, 3.15, 3.25, 3.35, 3.45, 3.55,
   3.65, 3.75, 3.85, 3.95, 4.05 };
   Double_t Graph0_fy1001[38] = { 1.1212, 1.112885, 1.104045, 1.094805, 1.085235, 1.075405, 1.065355, 1.05513, 1.044755, 1.034265, 1.023675, 1.013003, 1.002267, 0.9914875, 0.980668, 0.969827, 0.958971,
   0.94811, 0.9372535, 0.926408, 0.915581, 0.904779, 0.894007, 0.883271, 0.8725755, 0.861925, 0.8513245, 0.8407765, 0.8302855, 0.8198545, 0.8094855, 0.799183, 0.788948,
   0.778784, 0.7686925, 0.758676, 0.7487355, 0.738873 };
   Double_t Graph0_fex1001[38] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0 };
   Double_t Graph0_fey1001[38] = { 0.04043, 0.032585, 0.025485, 0.019015, 0.013095, 0.007645, 0.002625, 0.00201, 0.006285, 0.010235, 0.013895, 0.0172675, 0.020383, 0.0232625, 0.025912, 0.028352, 0.030593,
   0.032647, 0.0345255, 0.036238, 0.037794, 0.039202, 0.040471, 0.041609, 0.0426215, 0.043517, 0.0443005, 0.0449795, 0.0455585, 0.0460435, 0.0464395, 0.046752, 0.046984,
   0.047141, 0.0472275, 0.047247, 0.0472035, 0.0471 };
   TGraphErrors *gre = new TGraphErrors(38,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillColor(6);
   gre->SetFillStyle(3005);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_Graph01001 = new TH1F("Graph_Graph01001","Graph",100,0,4.4);
   Graph_Graph01001->SetMinimum(0.6);
   Graph_Graph01001->SetMaximum(1.4);
   Graph_Graph01001->SetDirectory(nullptr);
   Graph_Graph01001->SetStats(0);
   Graph_Graph01001->SetLineWidth(2);
   Graph_Graph01001->SetMarkerStyle(20);
   Graph_Graph01001->SetMarkerSize(0.8);
   Graph_Graph01001->GetXaxis()->SetTitle("#font[12]{N}_{tracks}^{PV}/#LT#font[12]{N}_{tracks}^{PV}#GT_{NB}");
   Graph_Graph01001->GetXaxis()->SetNdivisions(505);
   Graph_Graph01001->GetXaxis()->SetLabelFont(132);
   Graph_Graph01001->GetXaxis()->SetLabelOffset(0.01);
   Graph_Graph01001->GetXaxis()->SetLabelSize(0.06);
   Graph_Graph01001->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph01001->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01001->GetXaxis()->SetTitleFont(132);
   Graph_Graph01001->GetYaxis()->SetTitle("Normalised #sigma_{#psi(2S)}/#sigma_{J/#psi}");
   Graph_Graph01001->GetYaxis()->SetLabelFont(132);
   Graph_Graph01001->GetYaxis()->SetLabelOffset(0.01);
   Graph_Graph01001->GetYaxis()->SetLabelSize(0.06);
   Graph_Graph01001->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph01001->GetYaxis()->SetTitleOffset(1);
   Graph_Graph01001->GetYaxis()->SetTitleFont(132);
   Graph_Graph01001->GetZaxis()->SetLabelFont(132);
   Graph_Graph01001->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph01001->GetZaxis()->SetTitleSize(0.072);
   Graph_Graph01001->GetZaxis()->SetTitleOffset(1.2);
   Graph_Graph01001->GetZaxis()->SetTitleFont(132);
   gre->SetHistogram(Graph_Graph01001);
   
   gre->Draw("a3");
   
   TGraphMultiErrors* tgme = new TGraphMultiErrors(5, 2);
   tgme->GetAttFill(0)->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   tgme->GetAttLine(0)->SetLineColor(ci);
   tgme->GetAttLine(0)->SetLineWidth(2);

   ci = 1434;
   color = new TColor(ci, 1, 0, 0, " ", 0);
   tgme->GetAttFill(1)->SetFillColor(ci);

   ci = TColor::GetColor("#ff0000");
   tgme->GetAttLine(1)->SetLineColor(ci);
   tgme->GetAttLine(1)->SetLineWidth(2);
   tgme->SetPoint(0, 0.547981, 1.247357);
   tgme->SetPointEX(0, 0.03, 0.03);
   tgme->SetPointEY(0, 0, 0.005637793, 0.005637793);
   tgme->SetPointEY(0, 1, 0.0320834, 0.0320834);
   tgme->SetPoint(1, 1.2809, 1.061413);
   tgme->SetPointEX(1, 0.03, 0.03);
   tgme->SetPointEY(1, 0, 0.003657862, 0.003657862);
   tgme->SetPointEY(1, 1, 0.04659369, 0.04659369);
   tgme->SetPoint(2, 2.19179, 0.9278677);
   tgme->SetPointEX(2, 0.03, 0.03);
   tgme->SetPointEY(2, 0, 0.004902806, 0.004902806);
   tgme->SetPointEY(2, 1, 0.01683254, 0.01683254);
   tgme->SetPoint(3, 3.10346, 0.8436339);
   tgme->SetPointEX(3, 0.03, 0.03);
   tgme->SetPointEY(3, 0, 0.008906833, 0.008906833);
   tgme->SetPointEY(3, 1, 0.01159895, 0.01159895);
   tgme->SetPoint(4, 4.15601, 0.8135458);
   tgme->SetPointEX(4, 0.03, 0.03);
   tgme->SetPointEY(4, 0, 0.01966413, 0.01966413);
   tgme->SetPointEY(4, 1, 0.02785988, 0.02785988);
   tgme->SetName("gmep");
   tgme->SetTitle("");
   tgme->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   tgme->SetLineColor(ci);
   tgme->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   tgme->SetMarkerColor(ci);
   tgme->SetMarkerStyle(20);
   tgme->SetMarkerSize(1.5);
   
   TH1F *Graph_gmep5001 = new TH1F("Graph_gmep5001","",100,0,4.4);
   Graph_gmep5001->SetMinimum(0.6);
   Graph_gmep5001->SetMaximum(1.4);
   Graph_gmep5001->SetDirectory(nullptr);
   Graph_gmep5001->SetStats(0);
   Graph_gmep5001->SetLineWidth(2);
   Graph_gmep5001->SetMarkerStyle(20);
   Graph_gmep5001->SetMarkerSize(0.8);
   Graph_gmep5001->GetXaxis()->SetTitle("#font[12]{N}_{tracks}^{PV}/#LT#font[12]{N}_{tracks}^{PV}#GT_{NB}");
   Graph_gmep5001->GetXaxis()->SetNdivisions(505);
   Graph_gmep5001->GetXaxis()->SetLabelFont(132);
   Graph_gmep5001->GetXaxis()->SetLabelOffset(0.01);
   Graph_gmep5001->GetXaxis()->SetLabelSize(0.06);
   Graph_gmep5001->GetXaxis()->SetTitleSize(0.06);
   Graph_gmep5001->GetXaxis()->SetTitleOffset(1);
   Graph_gmep5001->GetXaxis()->SetTitleFont(132);
   Graph_gmep5001->GetYaxis()->SetTitle("Normalised #sigma_{#psi(2S)}/#sigma_{J/#psi}");
   Graph_gmep5001->GetYaxis()->SetLabelFont(132);
   Graph_gmep5001->GetYaxis()->SetLabelOffset(0.01);
   Graph_gmep5001->GetYaxis()->SetLabelSize(0.06);
   Graph_gmep5001->GetYaxis()->SetTitleSize(0.06);
   Graph_gmep5001->GetYaxis()->SetTitleOffset(1);
   Graph_gmep5001->GetYaxis()->SetTitleFont(132);
   Graph_gmep5001->GetZaxis()->SetLabelFont(132);
   Graph_gmep5001->GetZaxis()->SetLabelSize(0.06);
   Graph_gmep5001->GetZaxis()->SetTitleSize(0.072);
   Graph_gmep5001->GetZaxis()->SetTitleOffset(1.2);
   Graph_gmep5001->GetZaxis()->SetTitleFont(132);
   tgme->SetHistogram(Graph_gmep5001);
   
   tgme->Draw("ps ; z ; 5 s=1 ; ");
   
   tgme = new TGraphMultiErrors(5, 2);
   tgme->GetAttFill(0)->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   tgme->GetAttLine(0)->SetLineColor(ci);
   tgme->GetAttLine(0)->SetLineWidth(2);

   ci = 1435;
   color = new TColor(ci, 0, 0, 1, " ", 0);
   tgme->GetAttFill(1)->SetFillColor(ci);

   ci = TColor::GetColor("#0000ff");
   tgme->GetAttLine(1)->SetLineColor(ci);
   tgme->GetAttLine(1)->SetLineWidth(2);
   tgme->SetPoint(0, 0.567943, 1.032629);
   tgme->SetPointEX(0, 0.03, 0.03);
   tgme->SetPointEY(0, 0, 0.01578838, 0.01578838);
   tgme->SetPointEY(0, 1, 0.04021636, 0.04021636);
   tgme->SetPoint(1, 1.30157, 1.015373);
   tgme->SetPointEX(1, 0.03, 0.03);
   tgme->SetPointEY(1, 0, 0.007502771, 0.007502771);
   tgme->SetPointEY(1, 1, 0.04432639, 0.04432639);
   tgme->SetPoint(2, 2.19653, 0.9789521);
   tgme->SetPointEX(2, 0.03, 0.03);
   tgme->SetPointEY(2, 0, 0.007962875, 0.007962875);
   tgme->SetPointEY(2, 1, 0.01521184, 0.01521184);
   tgme->SetPoint(3, 3.10222, 0.9872985);
   tgme->SetPointEX(3, 0.03, 0.03);
   tgme->SetPointEY(3, 0, 0.01227212, 0.01227212);
   tgme->SetPointEY(3, 1, 0.02186372, 0.02186372);
   tgme->SetPoint(4, 4.14834, 1.027601);
   tgme->SetPointEX(4, 0.03, 0.03);
   tgme->SetPointEY(4, 0, 0.02521928, 0.02521928);
   tgme->SetPointEY(4, 1, 0.0348179, 0.0348179);
   tgme->SetName("gmeb");
   tgme->SetTitle("");
   tgme->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   tgme->SetLineColor(ci);
   tgme->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   tgme->SetMarkerColor(ci);
   tgme->SetMarkerStyle(20);
   tgme->SetMarkerSize(1.5);
   
   TH1F *Graph_gmeb5002 = new TH1F("Graph_gmeb5002","",100,0,4.4);
   Graph_gmeb5002->SetMinimum(0.6);
   Graph_gmeb5002->SetMaximum(1.4);
   Graph_gmeb5002->SetDirectory(nullptr);
   Graph_gmeb5002->SetStats(0);
   Graph_gmeb5002->SetLineWidth(2);
   Graph_gmeb5002->SetMarkerStyle(20);
   Graph_gmeb5002->SetMarkerSize(0.8);
   Graph_gmeb5002->GetXaxis()->SetTitle("#font[12]{N}_{tracks}^{PV}/#LT#font[12]{N}_{tracks}^{PV}#GT_{NB}");
   Graph_gmeb5002->GetXaxis()->SetNdivisions(505);
   Graph_gmeb5002->GetXaxis()->SetLabelFont(132);
   Graph_gmeb5002->GetXaxis()->SetLabelOffset(0.01);
   Graph_gmeb5002->GetXaxis()->SetLabelSize(0.06);
   Graph_gmeb5002->GetXaxis()->SetTitleSize(0.06);
   Graph_gmeb5002->GetXaxis()->SetTitleOffset(1);
   Graph_gmeb5002->GetXaxis()->SetTitleFont(132);
   Graph_gmeb5002->GetYaxis()->SetTitle("Normalised #sigma_{#psi(2S)}/#sigma_{J/#psi}");
   Graph_gmeb5002->GetYaxis()->SetLabelFont(132);
   Graph_gmeb5002->GetYaxis()->SetLabelOffset(0.01);
   Graph_gmeb5002->GetYaxis()->SetLabelSize(0.06);
   Graph_gmeb5002->GetYaxis()->SetTitleSize(0.06);
   Graph_gmeb5002->GetYaxis()->SetTitleOffset(1);
   Graph_gmeb5002->GetYaxis()->SetTitleFont(132);
   Graph_gmeb5002->GetZaxis()->SetLabelFont(132);
   Graph_gmeb5002->GetZaxis()->SetLabelSize(0.06);
   Graph_gmeb5002->GetZaxis()->SetTitleSize(0.072);
   Graph_gmeb5002->GetZaxis()->SetTitleOffset(1.2);
   Graph_gmeb5002->GetZaxis()->SetTitleFont(132);
   tgme->SetHistogram(Graph_gmeb5002);
   
   tgme->Draw("ps ; z ; 5 s=1 ; ");
   
   TF1 *unit1 = new TF1("unit","1+x-x",0,4.4, TF1::EAddToList::kDefault);
   unit1->SetFillColor(1);
   unit1->SetFillStyle(0);
   unit1->SetMarkerStyle(20);
   unit1->SetMarkerSize(0.8);
   unit1->SetLineStyle(2);
   unit1->SetLineWidth(2);
   unit1->GetXaxis()->SetNdivisions(505);
   unit1->GetXaxis()->SetLabelFont(132);
   unit1->GetXaxis()->SetLabelOffset(0.01);
   unit1->GetXaxis()->SetLabelSize(0.06);
   unit1->GetXaxis()->SetTitleSize(0.06);
   unit1->GetXaxis()->SetTitleOffset(1);
   unit1->GetXaxis()->SetTitleFont(132);
   unit1->GetYaxis()->SetLabelFont(132);
   unit1->GetYaxis()->SetLabelOffset(0.01);
   unit1->GetYaxis()->SetLabelSize(0.06);
   unit1->GetYaxis()->SetTitleSize(0.06);
   unit1->GetYaxis()->SetTitleOffset(1);
   unit1->GetYaxis()->SetTitleFont(132);
   unit1->Draw("same");
   
   TLegend *leg = new TLegend(0.18,0.19,0.38,0.39,NULL,"brNDC");
   leg->SetBorderSize(2);
   leg->SetTextFont(132);
   leg->SetTextSize(0.05);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("gmep","prompt","PLEZ");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(132);
   entry=leg->AddEntry("gmeb","non-prompt","PLEZ");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(132);
   entry=leg->AddEntry("Graph0","co-mover model","F");
   entry->SetFillColor(6);
   entry->SetFillStyle(3005);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.5,0.8,0.77,0.9,"BRNDC");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetLineWidth(2);
   pt->SetTextAlign(12);
   pt->SetTextFont(132);
   pt->SetTextSize(0.05);
   TText *pt_LaTex = pt->AddText("LHCb #font[12]{pp} #sqrt{s} = 13 TeV");
   pt->Draw();
   can->Modified();
   can->SetSelected(can);
}
