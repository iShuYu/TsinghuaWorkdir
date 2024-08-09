#ifdef __CLING__
#pragma cling optimize(0)
#endif
void All()
{
//=========Macro generated from canvas: can/can
//=========  (Sun Apr 14 19:30:28 2024) by ROOT version 6.30/04
   TCanvas *can = new TCanvas("can", "can",0,0,1600,1200);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   can->SetHighLightColor(2);
   can->Range(-1.133333,0.3898734,5.533333,1.453165);
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
   
   TF1 *unit1 = new TF1("unit","1+x-x",0,5, TF1::EAddToList::kDefault);
   unit1->SetFillColor(1);
   unit1->SetFillStyle(0);
   unit1->SetMarkerStyle(20);
   unit1->SetMarkerSize(0.8);
   unit1->SetLineStyle(2);
   unit1->SetLineWidth(2);
   unit1->GetXaxis()->SetTitle("#font[12]{N}_{fwd}^{PV}/#LT#font[12]{N}_{fwd}^{PV}#GT_{NB}");
   unit1->GetXaxis()->SetNdivisions(505);
   unit1->GetXaxis()->SetLabelFont(132);
   unit1->GetXaxis()->SetLabelOffset(0.01);
   unit1->GetXaxis()->SetLabelSize(0.06);
   unit1->GetXaxis()->SetTitleSize(0.06);
   unit1->GetXaxis()->SetTitleOffset(1);
   unit1->GetXaxis()->SetTitleFont(132);
   unit1->GetYaxis()->SetTitle("Normalised #sigma_{#psi(2S)}/#sigma_{J/#psi}");
   unit1->GetYaxis()->SetLabelFont(132);
   unit1->GetYaxis()->SetLabelOffset(0.01);
   unit1->GetYaxis()->SetLabelSize(0.06);
   unit1->GetYaxis()->SetTitleSize(0.06);
   unit1->GetYaxis()->SetTitleOffset(1);
   unit1->GetYaxis()->SetTitleFont(132);
   unit1->Draw("");
   
   TGraphMultiErrors* tgme = new TGraphMultiErrors(5, 2);
   tgme->GetAttFill(0)->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00ff00");
   tgme->GetAttLine(0)->SetLineColor(ci);
   tgme->GetAttLine(0)->SetLineWidth(2);

   ci = 1434;
   color = new TColor(ci, 0, 1, 0, " ", 0.25);
   tgme->GetAttFill(1)->SetFillColor(ci);

   ci = TColor::GetColor("#00ff00");
   tgme->GetAttLine(1)->SetLineColor(ci);
   tgme->GetAttLine(1)->SetLineWidth(2);
   tgme->SetPoint(0, 0.522535, 1.291465);
   tgme->SetPointEX(0, 0.0532578, 0.0532578);
   tgme->SetPointEY(0, 0, 0.006685593, 0.006685593);
   tgme->SetPointEY(0, 1, 0.04620462, 0.04620462);
   tgme->SetPoint(1, 1.10992, 1.114112);
   tgme->SetPointEX(1, 0.11258, 0.11258);
   tgme->SetPointEY(1, 0, 0.004124197, 0.004124197);
   tgme->SetPointEY(1, 1, 0.0390328, 0.0390328);
   tgme->SetPoint(2, 1.82551, 1.008529);
   tgme->SetPointEX(2, 0.186004, 0.186004);
   tgme->SetPointEY(2, 0, 0.004542586, 0.004542586);
   tgme->SetPointEY(2, 1, 0.04353144, 0.04353144);
   tgme->SetPoint(3, 2.55043, 0.9215281);
   tgme->SetPointEX(3, 0.260306, 0.260306);
   tgme->SetPointEY(3, 0, 0.005903438, 0.005903438);
   tgme->SetPointEY(3, 1, 0.0222138, 0.0222138);
   tgme->SetPoint(4, 3.75727, 0.8383141);
   tgme->SetPointEX(4, 0.385605, 0.385605);
   tgme->SetPointEY(4, 0, 0.007160795, 0.007160795);
   tgme->SetPointEY(4, 1, 0.01609387, 0.01609387);
   tgme->SetName("gmep");
   tgme->SetTitle("");
   tgme->SetFillStyle(1000);

   ci = TColor::GetColor("#00ff00");
   tgme->SetLineColor(ci);
   tgme->SetLineWidth(2);

   ci = TColor::GetColor("#00ff00");
   tgme->SetMarkerColor(ci);
   tgme->SetMarkerStyle(20);
   tgme->SetMarkerSize(1.5);
   
   TH1F *Graph_gmep5001 = new TH1F("Graph_gmep5001","",100,0,5);
   Graph_gmep5001->SetMinimum(0.6);
   Graph_gmep5001->SetMaximum(1.4);
   Graph_gmep5001->SetDirectory(nullptr);
   Graph_gmep5001->SetStats(0);
   Graph_gmep5001->SetLineWidth(2);
   Graph_gmep5001->SetMarkerStyle(20);
   Graph_gmep5001->SetMarkerSize(0.8);
   Graph_gmep5001->GetXaxis()->SetTitle("#font[12]{N}_{fwd}^{PV}/#LT#font[12]{N}_{fwd}^{PV}#GT_{NB}");
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
   color = new TColor(ci, 0, 0, 1, " ", 0.25);
   tgme->GetAttFill(1)->SetFillColor(ci);

   ci = TColor::GetColor("#0000ff");
   tgme->GetAttLine(1)->SetLineColor(ci);
   tgme->GetAttLine(1)->SetLineWidth(2);
   tgme->SetPoint(0, 0.523733, 1.074908);
   tgme->SetPointEX(0, 0.0533544, 0.0533544);
   tgme->SetPointEY(0, 0, 0.01878026, 0.01878026);
   tgme->SetPointEY(0, 1, 0.05148122, 0.05148122);
   tgme->SetPoint(1, 1.12523, 1.019137);
   tgme->SetPointEX(1, 0.11417, 0.11417);
   tgme->SetPointEY(1, 0, 0.009451021, 0.009451021);
   tgme->SetPointEY(1, 1, 0.03988363, 0.03988363);
   tgme->SetPoint(2, 1.83023, 1.007846);
   tgme->SetPointEX(2, 0.186468, 0.186468);
   tgme->SetPointEY(2, 0, 0.00851807, 0.00851807);
   tgme->SetPointEY(2, 1, 0.04657174, 0.04657174);
   tgme->SetPoint(3, 2.5519, 0.9754469);
   tgme->SetPointEX(3, 0.260112, 0.260112);
   tgme->SetPointEY(3, 0, 0.00960031, 0.00960031);
   tgme->SetPointEY(3, 1, 0.02921795, 0.02921795);
   tgme->SetPoint(4, 3.74702, 0.9835016);
   tgme->SetPointEX(4, 0.385908, 0.385908);
   tgme->SetPointEY(4, 0, 0.009651869, 0.009651869);
   tgme->SetPointEY(4, 1, 0.02303597, 0.02303597);
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
   
   TH1F *Graph_gmeb5002 = new TH1F("Graph_gmeb5002","",100,0,5);
   Graph_gmeb5002->SetMinimum(0.6);
   Graph_gmeb5002->SetMaximum(1.4);
   Graph_gmeb5002->SetDirectory(nullptr);
   Graph_gmeb5002->SetStats(0);
   Graph_gmeb5002->SetLineWidth(2);
   Graph_gmeb5002->SetMarkerStyle(20);
   Graph_gmeb5002->SetMarkerSize(0.8);
   Graph_gmeb5002->GetXaxis()->SetTitle("#font[12]{N}_{fwd}^{PV}/#LT#font[12]{N}_{fwd}^{PV}#GT_{NB}");
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

   ci = TColor::GetColor("#00ff00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#00ff00");
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
