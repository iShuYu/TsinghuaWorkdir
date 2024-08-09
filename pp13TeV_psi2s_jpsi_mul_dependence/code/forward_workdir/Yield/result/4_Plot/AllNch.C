#ifdef __CLING__
#pragma cling optimize(0)
#endif
void AllNch()
{
//=========Macro generated from canvas: can/can
//=========  (Tue Apr 16 11:06:22 2024) by ROOT version 6.30/06
   TCanvas *can = new TCanvas("can", "can",0,0,1600,1200);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   can->SetHighLightColor(2);
   can->Range(-5.666667,0.3898734,27.66667,1.453165);
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
   
   TF1 *unit1 = new TF1("unit","1+x-x",0,25, TF1::EAddToList::kDefault);
   unit1->SetFillColor(1);
   unit1->SetFillStyle(0);
   unit1->SetMarkerStyle(20);
   unit1->SetMarkerSize(0.8);
   unit1->SetLineStyle(2);
   unit1->SetLineWidth(2);
   unit1->GetXaxis()->SetTitle("d#font[12]{N}_{ch}/d#eta");
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
   ci = TColor::GetColor("#ff0000");
   tgme->GetAttLine(0)->SetLineColor(ci);
   tgme->GetAttLine(0)->SetLineWidth(2);

   ci = 1434;
   color = new TColor(ci, 1, 0, 0, " ", 0.25);
   tgme->GetAttFill(1)->SetFillColor(ci);

   ci = TColor::GetColor("#ff0000");
   tgme->GetAttLine(1)->SetLineColor(ci);
   tgme->GetAttLine(1)->SetLineWidth(2);
   tgme->SetPoint(0, 2.94769, 1.247357);
   tgme->SetPointEX(0, 0.169125, 0.169125);
   tgme->SetPointEY(0, 0, 0.005637793, 0.005637793);
   tgme->SetPointEY(0, 1, 0.0320834, 0.0320834);
   tgme->SetPoint(1, 5.88871, 1.061413);
   tgme->SetPointEX(1, 0.0374108, 0.0374108);
   tgme->SetPointEY(1, 0, 0.003657862, 0.003657862);
   tgme->SetPointEY(1, 1, 0.04659369, 0.04659369);
   tgme->SetPoint(2, 9.33541, 0.9278677);
   tgme->SetPointEX(2, 0.0555371, 0.0555371);
   tgme->SetPointEY(2, 0, 0.004902806, 0.004902806);
   tgme->SetPointEY(2, 1, 0.01683254, 0.01683254);
   tgme->SetPoint(3, 12.6889, 0.8436339);
   tgme->SetPointEX(3, 0.0610979, 0.0610979);
   tgme->SetPointEY(3, 0, 0.008906833, 0.008906833);
   tgme->SetPointEY(3, 1, 0.01159895, 0.01159895);
   tgme->SetPoint(4, 16.6973, 0.8135458);
   tgme->SetPointEX(4, 0.139669, 0.139669);
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
   
   TH1F *Graph_gmep5001 = new TH1F("Graph_gmep5001","",100,0,5);
   Graph_gmep5001->SetMinimum(0.6);
   Graph_gmep5001->SetMaximum(1.4);
   Graph_gmep5001->SetDirectory(nullptr);
   Graph_gmep5001->SetStats(0);
   Graph_gmep5001->SetLineWidth(2);
   Graph_gmep5001->SetMarkerStyle(20);
   Graph_gmep5001->SetMarkerSize(0.8);
   Graph_gmep5001->GetXaxis()->SetTitle("d#font[12]{N}_{ch}/d#eta");
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
   tgme->SetPoint(0, 4.18986, 1.032629);
   tgme->SetPointEX(0, 0.459425, 0.459425);
   tgme->SetPointEY(0, 0, 0.01578838, 0.01578838);
   tgme->SetPointEY(0, 1, 0.04021636, 0.04021636);
   tgme->SetPoint(1, 7.26281, 1.015373);
   tgme->SetPointEX(1, 0.0314906, 0.0314906);
   tgme->SetPointEY(1, 0, 0.007502771, 0.007502771);
   tgme->SetPointEY(1, 1, 0.04432639, 0.04432639);
   tgme->SetPoint(2, 10.8327, 0.9789521);
   tgme->SetPointEX(2, 0.137504, 0.137504);
   tgme->SetPointEY(2, 0, 0.007962875, 0.007962875);
   tgme->SetPointEY(2, 1, 0.01521184, 0.01521184);
   tgme->SetPoint(3, 14.3497, 0.9872985);
   tgme->SetPointEX(3, 0.0998207, 0.0998207);
   tgme->SetPointEY(3, 0, 0.01227212, 0.01227212);
   tgme->SetPointEY(3, 1, 0.02186372, 0.02186372);
   tgme->SetPoint(4, 18.5481, 1.027601);
   tgme->SetPointEX(4, 0.25612, 0.25612);
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
   
   TH1F *Graph_gmeb5002 = new TH1F("Graph_gmeb5002","",100,0,5);
   Graph_gmeb5002->SetMinimum(0.6);
   Graph_gmeb5002->SetMaximum(1.4);
   Graph_gmeb5002->SetDirectory(nullptr);
   Graph_gmeb5002->SetStats(0);
   Graph_gmeb5002->SetLineWidth(2);
   Graph_gmeb5002->SetMarkerStyle(20);
   Graph_gmeb5002->SetMarkerSize(0.8);
   Graph_gmeb5002->GetXaxis()->SetTitle("d#font[12]{N}_{ch}/d#eta");
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
