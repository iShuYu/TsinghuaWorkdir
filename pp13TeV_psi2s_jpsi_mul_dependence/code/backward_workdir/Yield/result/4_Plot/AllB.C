#ifdef __CLING__
#pragma cling optimize(0)
#endif
void AllB()
{
//=========Macro generated from canvas: can/can
//=========  (Tue Apr 16 11:08:02 2024) by ROOT version 6.30/06
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
   unit1->GetXaxis()->SetTitle("#font[12]{N}_{bwd}^{PV}/#LT#font[12]{N}_{bwd}^{PV}#GT_{NB}");
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
   tgme->GetAttLine(0)->SetLineWidth(2);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = 1434;
   color = new TColor(ci, 0, 0, 0, " ", 0);
   tgme->GetAttFill(1)->SetFillColor(ci);
   tgme->GetAttLine(1)->SetLineWidth(2);
   tgme->SetPoint(0, 0.402229, 1.109678);
   tgme->SetPointEX(0, 0.03, 0.03);
   tgme->SetPointEY(0, 0, 0.004633273, 0.004633273);
   tgme->SetPointEY(0, 1, 0.05436159, 0.05436159);
   tgme->SetPoint(1, 1.09118, 1.020153);
   tgme->SetPointEX(1, 0.03, 0.03);
   tgme->SetPointEY(1, 0, 0.00522645, 0.00522645);
   tgme->SetPointEY(1, 1, 0.03492291, 0.03492291);
   tgme->SetPoint(2, 1.75279, 0.9358178);
   tgme->SetPointEX(2, 0.03, 0.03);
   tgme->SetPointEY(2, 0, 0.00650515, 0.00650515);
   tgme->SetPointEY(2, 1, 0.0206171, 0.0206171);
   tgme->SetPoint(3, 2.43033, 0.8906389);
   tgme->SetPointEX(3, 0.03, 0.03);
   tgme->SetPointEY(3, 0, 0.009075877, 0.009075877);
   tgme->SetPointEY(3, 1, 0.02070851, 0.02070851);
   tgme->SetPoint(4, 3.43437, 0.9012423);
   tgme->SetPointEX(4, 0.03, 0.03);
   tgme->SetPointEY(4, 0, 0.01315769, 0.01315769);
   tgme->SetPointEY(4, 1, 0.02961158, 0.02961158);
   tgme->SetName("gmep");
   tgme->SetTitle("");
   tgme->SetFillStyle(1000);
   tgme->SetLineWidth(2);
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
   Graph_gmep5001->GetXaxis()->SetTitle("#font[12]{N}_{bwd}^{PV}/#LT#font[12]{N}_{bwd}^{PV}#GT_{NB}");
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
   tgme->SetPoint(0, 0.433981, 1.029854);
   tgme->SetPointEX(0, 0.03, 0.03);
   tgme->SetPointEY(0, 0, 0.01081574, 0.01081574);
   tgme->SetPointEY(0, 1, 0.04624684, 0.04624684);
   tgme->SetPoint(1, 1.09871, 0.9977619);
   tgme->SetPointEX(1, 0.03, 0.03);
   tgme->SetPointEY(1, 0, 0.009539012, 0.009539012);
   tgme->SetPointEY(1, 1, 0.0390987, 0.0390987);
   tgme->SetPoint(2, 1.75743, 0.9940928);
   tgme->SetPointEX(2, 0.03, 0.03);
   tgme->SetPointEY(2, 0, 0.01073431, 0.01073431);
   tgme->SetPointEY(2, 1, 0.02910465, 0.02910465);
   tgme->SetPoint(3, 2.43401, 0.9702669);
   tgme->SetPointEX(3, 0.03, 0.03);
   tgme->SetPointEY(3, 0, 0.01325608, 0.01325608);
   tgme->SetPointEY(3, 1, 0.0285536, 0.0285536);
   tgme->SetPoint(4, 3.43798, 1.000636);
   tgme->SetPointEX(4, 0.03, 0.03);
   tgme->SetPointEY(4, 0, 0.01827952, 0.01827952);
   tgme->SetPointEY(4, 1, 0.03493522, 0.03493522);
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
   Graph_gmeb5002->GetXaxis()->SetTitle("#font[12]{N}_{bwd}^{PV}/#LT#font[12]{N}_{bwd}^{PV}#GT_{NB}");
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
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
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
