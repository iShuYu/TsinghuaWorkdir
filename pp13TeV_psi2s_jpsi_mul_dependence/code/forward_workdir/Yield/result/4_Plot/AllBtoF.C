#ifdef __CLING__
#pragma cling optimize(0)
#endif
void AllBtoF()
{
//=========Macro generated from canvas: can/can
//=========  (Tue Apr 16 11:06:21 2024) by ROOT version 6.30/06
   TCanvas *can = new TCanvas("can", "can",0,0,1600,1200);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   can->SetHighLightColor(2);
   can->Range(-0.9973333,0.3898734,4.869333,1.453165);
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
   
   TF1 *unit1 = new TF1("unit","1+x-x",0,4.4, TF1::EAddToList::kDefault);
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
   color = new TColor(ci, 0, 1, 0, " ", 0);
   tgme->GetAttFill(1)->SetFillColor(ci);

   ci = TColor::GetColor("#00ff00");
   tgme->GetAttLine(1)->SetLineColor(ci);
   tgme->GetAttLine(1)->SetLineWidth(2);
   tgme->SetPoint(0, 0.524778, 1.291465);
   tgme->SetPointEX(0, 0.03, 0.03);
   tgme->SetPointEY(0, 0, 0.006685593, 0.006685593);
   tgme->SetPointEY(0, 1, 0.04620462, 0.04620462);
   tgme->SetPoint(1, 1.11432, 1.114112);
   tgme->SetPointEX(1, 0.03, 0.03);
   tgme->SetPointEY(1, 0, 0.004124197, 0.004124197);
   tgme->SetPointEY(1, 1, 0.0390328, 0.0390328);
   tgme->SetPoint(2, 1.8223, 1.008529);
   tgme->SetPointEX(2, 0.03, 0.03);
   tgme->SetPointEY(2, 0, 0.004542586, 0.004542586);
   tgme->SetPointEY(2, 1, 0.04353144, 0.04353144);
   tgme->SetPoint(3, 2.55903, 0.9215281);
   tgme->SetPointEX(3, 0.03, 0.03);
   tgme->SetPointEY(3, 0, 0.005903438, 0.005903438);
   tgme->SetPointEY(3, 1, 0.0222138, 0.0222138);
   tgme->SetPoint(4, 3.76662, 0.8383141);
   tgme->SetPointEX(4, 0.03, 0.03);
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
   tgme->SetMarkerSize(0.8);
   
   TH1F *Graph_gmep5001 = new TH1F("Graph_gmep5001","",100,0,4.4);
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
   tgme->GetAttLine(0)->SetLineWidth(2);

   ci = 1435;
   color = new TColor(ci, 0, 0, 0, " ", 0);
   tgme->GetAttFill(1)->SetFillColor(ci);
   tgme->GetAttLine(1)->SetLineWidth(2);
   tgme->SetPoint(0, 1.1979, 1.109678);
   tgme->SetPointEX(0, 0.036, 0.036);
   tgme->SetPointEY(0, 0, 0.004633273, 0.004633273);
   tgme->SetPointEY(0, 1, 0.04620462, 0.04620462);
   tgme->SetPoint(1, 1.85536, 1.020153);
   tgme->SetPointEX(1, 0.036, 0.036);
   tgme->SetPointEY(1, 0, 0.00522645, 0.00522645);
   tgme->SetPointEY(1, 1, 0.0390328, 0.0390328);
   tgme->SetPoint(2, 2.35338, 0.9358178);
   tgme->SetPointEX(2, 0.036, 0.036);
   tgme->SetPointEY(2, 0, 0.00650515, 0.00650515);
   tgme->SetPointEY(2, 1, 0.04353144, 0.04353144);
   tgme->SetPoint(3, 2.78493, 0.8906389);
   tgme->SetPointEX(3, 0.036, 0.036);
   tgme->SetPointEY(3, 0, 0.009075877, 0.009075877);
   tgme->SetPointEY(3, 1, 0.0222138, 0.0222138);
   tgme->SetPoint(4, 3.30265, 0.9012423);
   tgme->SetPointEX(4, 0.036, 0.036);
   tgme->SetPointEY(4, 0, 0.01315769, 0.01315769);
   tgme->SetPointEY(4, 1, 0.01609387, 0.01609387);
   tgme->SetName("gmeb");
   tgme->SetTitle("");
   tgme->SetFillStyle(1000);
   tgme->SetLineWidth(2);
   tgme->SetMarkerStyle(20);
   tgme->SetMarkerSize(0.8);
   
   TH1F *Graph_gmeb5002 = new TH1F("Graph_gmeb5002","",100,0.944225,3.556325);
   Graph_gmeb5002->SetMinimum(0.8396793);
   Graph_gmeb5002->SetMaximum(1.184629);
   Graph_gmeb5002->SetDirectory(nullptr);
   Graph_gmeb5002->SetStats(0);
   Graph_gmeb5002->SetLineWidth(2);
   Graph_gmeb5002->SetMarkerStyle(20);
   Graph_gmeb5002->SetMarkerSize(0.8);
   Graph_gmeb5002->GetXaxis()->SetNdivisions(505);
   Graph_gmeb5002->GetXaxis()->SetLabelFont(132);
   Graph_gmeb5002->GetXaxis()->SetLabelOffset(0.01);
   Graph_gmeb5002->GetXaxis()->SetLabelSize(0.06);
   Graph_gmeb5002->GetXaxis()->SetTitleSize(0.06);
   Graph_gmeb5002->GetXaxis()->SetTitleOffset(1);
   Graph_gmeb5002->GetXaxis()->SetTitleFont(132);
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
   TLegendEntry *entry=leg->AddEntry("gmep","Result of #font[12]{N}_{fwd}^{PV}","PLEZ");

   ci = TColor::GetColor("#00ff00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#00ff00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.8);
   entry->SetTextFont(132);
   entry=leg->AddEntry("gmeb","Migrated from #font[12]{N}_{bwd}^{PV}","PLEZ");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.8);
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
   
   leg = new TLegend(0.6,0.7,0.7,0.8,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(132);
   leg->SetTextSize(0.06);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("NULL","prompt","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   leg->Draw();
   can->Modified();
   can->SetSelected(can);
}
