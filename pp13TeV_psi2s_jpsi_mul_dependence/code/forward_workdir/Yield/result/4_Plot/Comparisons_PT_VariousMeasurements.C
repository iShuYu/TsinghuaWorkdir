void Comparisons_PT_VariousMeasurements()
{
//=========Macro generated from canvas: can/can
//=========  (Mon Jun 24 16:43:04 2024) by ROOT version 6.24/06
   TCanvas *can = new TCanvas("can", "can",0,0,1200,800);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   can->SetHighLightColor(2);
   can->Range(-2.419753,-2.025316,14.8642,10.63291);
   can->SetFillColor(0);
   can->SetBorderMode(0);
   can->SetBorderSize(2);
   can->SetTickx(1);
   can->SetTicky(1);
   can->SetLeftMargin(0.14);
   can->SetRightMargin(0.05);
   can->SetTopMargin(0.05);
   can->SetBottomMargin(0.16);
   can->SetFrameLineWidth(2);
   can->SetFrameBorderMode(0);
   can->SetFrameLineWidth(2);
   can->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle(";#font[12]{p}_{T} [GeV/c];B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
   
   Double_t Graph_fx1001[79] = {
   0.2,
   0.3,
   0.4,
   0.5,
   0.6,
   0.7,
   0.8,
   0.9,
   1,
   1.1,
   1.2,
   1.3,
   1.4,
   1.5,
   1.6,
   1.7,
   1.8,
   1.9,
   2,
   2.1,
   2.2,
   2.3,
   2.4,
   2.5,
   2.6,
   2.7,
   2.8,
   2.9,
   3,
   3.1,
   3.2,
   3.3,
   3.4,
   3.5,
   3.6,
   3.7,
   3.8,
   3.9,
   4,
   4.1,
   4.2,
   4.3,
   4.4,
   4.5,
   4.6,
   4.7,
   4.8,
   4.9,
   5,
   5.1,
   5.2,
   5.3,
   5.4,
   5.5,
   5.6,
   5.7,
   5.8,
   5.9,
   6,
   6.1,
   6.2,
   6.3,
   6.4,
   6.5,
   6.6,
   6.7,
   6.8,
   6.9,
   7,
   7.1,
   7.2,
   7.3,
   7.4,
   7.5,
   7.6,
   7.7,
   7.8,
   7.9,
   8};
   Double_t Graph_fy1001[79] = {
   1.616551,
   1.617642,
   1.616105,
   1.614788,
   1.616976,
   1.620143,
   1.623269,
   1.62581,
   1.627858,
   1.627612,
   1.629062,
   1.634783,
   1.643729,
   1.652875,
   1.659786,
   1.667036,
   1.676069,
   1.686272,
   1.695738,
   1.700374,
   1.706839,
   1.720215,
   1.739106,
   1.757531,
   1.770069,
   1.781609,
   1.794008,
   1.80783,
   1.822417,
   1.838168,
   1.85453,
   1.871299,
   1.888274,
   1.905269,
   1.921299,
   1.937296,
   1.953313,
   1.969383,
   1.985553,
   2.002594,
   2.019576,
   2.036384,
   2.052887,
   2.06899,
   2.08385,
   2.098364,
   2.112605,
   2.126639,
   2.140555,
   2.154882,
   2.16907,
   2.183071,
   2.196847,
   2.210343,
   2.223407,
   2.236178,
   2.248656,
   2.260835,
   2.272728,
   2.284415,
   2.295815,
   2.30693,
   2.317739,
   2.328255,
   2.338459,
   2.348363,
   2.357948,
   2.367213,
   2.37618,
   2.384734,
   2.392982,
   2.400937,
   2.40858,
   2.415943,
   2.423007,
   2.429791,
   2.436297,
   2.442529,
   2.448502};
   Double_t Graph_fex1001[79] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1001[79] = {
   0.1164091,
   0.1164224,
   0.1167882,
   0.1172938,
   0.1176729,
   0.1180454,
   0.1184578,
   0.1189899,
   0.1194555,
   0.119675,
   0.1199411,
   0.1204067,
   0.121012,
   0.1215774,
   0.1220097,
   0.1223955,
   0.1227813,
   0.1231405,
   0.1233733,
   0.1232735,
   0.1232336,
   0.1235329,
   0.1240917,
   0.1246105,
   0.1247635,
   0.1248765,
   0.1250761,
   0.1253821,
   0.125708,
   0.1259208,
   0.1261071,
   0.1263,
   0.1264995,
   0.1267323,
   0.1270915,
   0.127484,
   0.1278831,
   0.1282822,
   0.1286613,
   0.1289673,
   0.1292666,
   0.1295659,
   0.1298652,
   0.1301778,
   0.1305636,
   0.1309494,
   0.1313419,
   0.1317277,
   0.1321002,
   0.1324327,
   0.1327587,
   0.1330713,
   0.1333706,
   0.1336699,
   0.1339759,
   0.1342686,
   0.1345479,
   0.1348206,
   0.1350734,
   0.1352929,
   0.1354925,
   0.135672,
   0.1358383,
   0.1359913,
   0.1361243,
   0.1362507,
   0.1363638,
   0.1364636,
   0.1365567,
   0.1366764,
   0.1367829,
   0.136876,
   0.1369491,
   0.137009,
   0.1370489,
   0.1370622,
   0.1370622,
   0.137029,
   0.1369758};
   TGraphErrors *gre = new TGraphErrors(79,Graph_fx1001,Graph_fy1001,Graph_fex1001,Graph_fey1001);
   gre->SetName("Graph");
   gre->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#33cc33");
   gre->SetFillColor(ci);
   gre->SetFillStyle(3244);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","Graph",100,0,8.78);
   Graph_Graph1001->SetMinimum(1.388696);
   Graph_Graph1001->SetMaximum(2.694276);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);
   Graph_Graph1001->SetLineWidth(2);
   Graph_Graph1001->SetMarkerStyle(20);
   Graph_Graph1001->GetXaxis()->SetTitle("#font[12]{p}_{T} [GeV/c]");
   Graph_Graph1001->GetXaxis()->SetNdivisions(505);
   Graph_Graph1001->GetXaxis()->SetLabelFont(132);
   Graph_Graph1001->GetXaxis()->SetLabelOffset(0.01);
   Graph_Graph1001->GetXaxis()->SetLabelSize(0.048);
   Graph_Graph1001->GetXaxis()->SetTitleSize(0.054);
   Graph_Graph1001->GetXaxis()->SetTitleOffset(1.2);
   Graph_Graph1001->GetXaxis()->SetTitleFont(132);
   Graph_Graph1001->GetYaxis()->SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
   Graph_Graph1001->GetYaxis()->SetLabelFont(132);
   Graph_Graph1001->GetYaxis()->SetLabelOffset(0.01);
   Graph_Graph1001->GetYaxis()->SetLabelSize(0.048);
   Graph_Graph1001->GetYaxis()->SetTitleSize(0.054);
   Graph_Graph1001->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph1001->GetYaxis()->SetTitleFont(132);
   Graph_Graph1001->GetZaxis()->SetLabelFont(132);
   Graph_Graph1001->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1001->GetZaxis()->SetTitleSize(0.072);
   Graph_Graph1001->GetZaxis()->SetTitleOffset(1.2);
   Graph_Graph1001->GetZaxis()->SetTitleFont(132);
   gre->SetHistogram(Graph_Graph1001);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1002[31] = {
   5,
   5.5,
   6,
   6.5,
   7,
   7.5,
   8,
   8.5,
   9,
   9.5,
   10,
   10.5,
   11,
   11.5,
   12,
   12.5,
   13,
   13.5,
   14,
   14.5,
   15,
   15.5,
   16,
   16.5,
   17,
   17.5,
   18,
   18.5,
   19,
   19.5,
   20};
   Double_t Graph_fy1002[31] = {
   3.579216,
   3.654797,
   3.732208,
   3.820501,
   3.919264,
   4.02364,
   4.131801,
   4.240189,
   4.349281,
   4.459105,
   4.570126,
   4.68593,
   4.802931,
   4.920351,
   5.038064,
   5.15593,
   5.271175,
   5.38662,
   5.503202,
   5.621653,
   5.742798,
   5.874971,
   6.010311,
   6.145284,
   6.277943,
   6.406452,
   6.519608,
   6.626771,
   6.729432,
   6.828374,
   6.924383};
   Double_t Graph_fex1002[31] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1002[31] = {
   0.08788717,
   0.09109988,
   0.09425273,
   0.09690005,
   0.09957398,
   0.1025406,
   0.1055537,
   0.1084738,
   0.111314,
   0.1140611,
   0.1167018,
   0.1192693,
   0.1217437,
   0.1241316,
   0.1264131,
   0.1285682,
   0.1305636,
   0.1324261,
   0.1341488,
   0.135692,
   0.137029,
   0.1381265,
   0.1388781,
   0.1393969,
   0.1397295,
   0.1399024,
   0.1400754,
   0.1402417,
   0.1403747,
   0.1404878,
   0.1405676};
   gre = new TGraphErrors(31,Graph_fx1002,Graph_fy1002,Graph_fex1002,Graph_fey1002);
   gre->SetName("Graph");
   gre->SetTitle("Graph");

   ci = TColor::GetColor("#3333cc");
   gre->SetFillColor(ci);
   gre->SetFillStyle(3244);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,3.5,21.5);
   Graph_Graph1002->SetMinimum(3.133966);
   Graph_Graph1002->SetMaximum(7.422312);
   Graph_Graph1002->SetDirectory(0);
   Graph_Graph1002->SetStats(0);
   Graph_Graph1002->SetLineWidth(2);
   Graph_Graph1002->SetMarkerStyle(20);
   Graph_Graph1002->GetXaxis()->SetTitle("#font[12]{p}_{T} [GeV/c]");
   Graph_Graph1002->GetXaxis()->SetNdivisions(505);
   Graph_Graph1002->GetXaxis()->SetLabelFont(132);
   Graph_Graph1002->GetXaxis()->SetLabelOffset(0.01);
   Graph_Graph1002->GetXaxis()->SetLabelSize(0.048);
   Graph_Graph1002->GetXaxis()->SetTitleSize(0.054);
   Graph_Graph1002->GetXaxis()->SetTitleOffset(1.2);
   Graph_Graph1002->GetXaxis()->SetTitleFont(132);
   Graph_Graph1002->GetYaxis()->SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
   Graph_Graph1002->GetYaxis()->SetLabelFont(132);
   Graph_Graph1002->GetYaxis()->SetLabelOffset(0.01);
   Graph_Graph1002->GetYaxis()->SetLabelSize(0.048);
   Graph_Graph1002->GetYaxis()->SetTitleSize(0.054);
   Graph_Graph1002->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph1002->GetYaxis()->SetTitleFont(132);
   Graph_Graph1002->GetZaxis()->SetLabelFont(132);
   Graph_Graph1002->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1002->GetZaxis()->SetTitleSize(0.072);
   Graph_Graph1002->GetZaxis()->SetTitleOffset(1.2);
   Graph_Graph1002->GetZaxis()->SetTitleFont(132);
   gre->SetHistogram(Graph_Graph1002);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1003[8] = {
   0.2434613,
   0.6990818,
   1.097315,
   1.497287,
   1.898998,
   2.295492,
   2.697204,
   3.698873};
   Double_t Graph_fy1003[8] = {
   1.399877,
   1.522539,
   1.6682,
   1.729531,
   1.503373,
   1.767863,
   2.128182,
   2.5115};
   Double_t Graph_fex1003[8] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1003[8] = {
   0.1379945,
   0.107329,
   0.107329,
   0.1609936,
   0.1648267,
   0.2223244,
   0.3296535,
   0.3449862};
   gre = new TGraphErrors(8,Graph_fx1003,Graph_fy1003,Graph_fex1003,Graph_fey1003);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetLineColor(6);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(6);
   gre->SetMarkerStyle(22);
   gre->SetMarkerSize(1.1);
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","Graph",100,0,4.044414);
   Graph_Graph1003->SetMinimum(1.102423);
   Graph_Graph1003->SetMaximum(3.015946);
   Graph_Graph1003->SetDirectory(0);
   Graph_Graph1003->SetStats(0);
   Graph_Graph1003->SetLineWidth(2);
   Graph_Graph1003->SetMarkerStyle(20);
   Graph_Graph1003->GetXaxis()->SetTitle("#font[12]{p}_{T} [GeV/c]");
   Graph_Graph1003->GetXaxis()->SetNdivisions(505);
   Graph_Graph1003->GetXaxis()->SetLabelFont(132);
   Graph_Graph1003->GetXaxis()->SetLabelOffset(0.01);
   Graph_Graph1003->GetXaxis()->SetLabelSize(0.048);
   Graph_Graph1003->GetXaxis()->SetTitleSize(0.054);
   Graph_Graph1003->GetXaxis()->SetTitleOffset(1.2);
   Graph_Graph1003->GetXaxis()->SetTitleFont(132);
   Graph_Graph1003->GetYaxis()->SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
   Graph_Graph1003->GetYaxis()->SetLabelFont(132);
   Graph_Graph1003->GetYaxis()->SetLabelOffset(0.01);
   Graph_Graph1003->GetYaxis()->SetLabelSize(0.048);
   Graph_Graph1003->GetYaxis()->SetTitleSize(0.054);
   Graph_Graph1003->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph1003->GetYaxis()->SetTitleFont(132);
   Graph_Graph1003->GetZaxis()->SetLabelFont(132);
   Graph_Graph1003->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1003->GetZaxis()->SetTitleSize(0.072);
   Graph_Graph1003->GetZaxis()->SetTitleOffset(1.2);
   Graph_Graph1003->GetZaxis()->SetTitleFont(132);
   gre->SetHistogram(Graph_Graph1003);
   
   multigraph->Add(gre,"P");
   
   Double_t Graph_fx1004[6] = {
   0.4973567,
   1.497287,
   2.495479,
   3.498887,
   4.500556,
   5.507443};
   Double_t Graph_fy1004[6] = {
   1.338546,
   1.664367,
   1.721864,
   2.109016,
   2.446335,
   2.703159};
   Double_t Graph_fex1004[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1004[6] = {
   0.5213125,
   0.5788102,
   0.5289788,
   0.5864765,
   0.6554738,
   0.7513033};
   gre = new TGraphErrors(6,Graph_fx1004,Graph_fy1004,Graph_fex1004,Graph_fey1004);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetLineColor(7);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(7);
   gre->SetMarkerStyle(23);
   gre->SetMarkerSize(1.1);
   
   TH1F *Graph_Graph1004 = new TH1F("Graph_Graph1004","Graph",100,0,6.008452);
   Graph_Graph1004->SetMinimum(0.5535112);
   Graph_Graph1004->SetMaximum(3.718185);
   Graph_Graph1004->SetDirectory(0);
   Graph_Graph1004->SetStats(0);
   Graph_Graph1004->SetLineWidth(2);
   Graph_Graph1004->SetMarkerStyle(20);
   Graph_Graph1004->GetXaxis()->SetTitle("#font[12]{p}_{T} [GeV/c]");
   Graph_Graph1004->GetXaxis()->SetNdivisions(505);
   Graph_Graph1004->GetXaxis()->SetLabelFont(132);
   Graph_Graph1004->GetXaxis()->SetLabelOffset(0.01);
   Graph_Graph1004->GetXaxis()->SetLabelSize(0.048);
   Graph_Graph1004->GetXaxis()->SetTitleSize(0.054);
   Graph_Graph1004->GetXaxis()->SetTitleOffset(1.2);
   Graph_Graph1004->GetXaxis()->SetTitleFont(132);
   Graph_Graph1004->GetYaxis()->SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
   Graph_Graph1004->GetYaxis()->SetLabelFont(132);
   Graph_Graph1004->GetYaxis()->SetLabelOffset(0.01);
   Graph_Graph1004->GetYaxis()->SetLabelSize(0.048);
   Graph_Graph1004->GetYaxis()->SetTitleSize(0.054);
   Graph_Graph1004->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph1004->GetYaxis()->SetTitleFont(132);
   Graph_Graph1004->GetZaxis()->SetLabelFont(132);
   Graph_Graph1004->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1004->GetZaxis()->SetTitleSize(0.072);
   Graph_Graph1004->GetZaxis()->SetTitleOffset(1.2);
   Graph_Graph1004->GetZaxis()->SetTitleFont(132);
   gre->SetHistogram(Graph_Graph1004);
   
   multigraph->Add(gre,"P");
   
   Double_t Graph_fx1005[6] = {
   7.25,
   8.5,
   9.5,
   11,
   13.5,
   6.953097e-310};
   Double_t Graph_fy1005[6] = {
   3.58,
   3.23,
   3.67,
   3.55,
   4.22,
   6.953097e-310};
   Double_t Graph_fex1005[6] = {
   0,
   0,
   0,
   0,
   0,
   -1.384016e+221};
   Double_t Graph_fey1005[6] = {
   0.74,
   0.57,
   0.68,
   0.66,
   0.78,
   4.644051e-310};
   gre = new TGraphErrors(6,Graph_fx1005,Graph_fy1005,Graph_fex1005,Graph_fey1005);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#000066");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#000066");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(29);
   gre->SetMarkerSize(1.1);
   
   TH1F *Graph_Graph1005 = new TH1F("Graph_Graph1005","Graph",100,0,14.85);
   Graph_Graph1005->SetMinimum(2.078142e-310);
   Graph_Graph1005->SetMaximum(5.5);
   Graph_Graph1005->SetDirectory(0);
   Graph_Graph1005->SetStats(0);
   Graph_Graph1005->SetLineWidth(2);
   Graph_Graph1005->SetMarkerStyle(20);
   Graph_Graph1005->GetXaxis()->SetNdivisions(505);
   Graph_Graph1005->GetXaxis()->SetLabelFont(132);
   Graph_Graph1005->GetXaxis()->SetLabelOffset(0.01);
   Graph_Graph1005->GetXaxis()->SetLabelSize(0.048);
   Graph_Graph1005->GetXaxis()->SetTitleSize(0.054);
   Graph_Graph1005->GetXaxis()->SetTitleOffset(1.2);
   Graph_Graph1005->GetXaxis()->SetTitleFont(132);
   Graph_Graph1005->GetYaxis()->SetLabelFont(132);
   Graph_Graph1005->GetYaxis()->SetLabelOffset(0.01);
   Graph_Graph1005->GetYaxis()->SetLabelSize(0.048);
   Graph_Graph1005->GetYaxis()->SetTitleSize(0.054);
   Graph_Graph1005->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph1005->GetYaxis()->SetTitleFont(132);
   Graph_Graph1005->GetZaxis()->SetLabelFont(132);
   Graph_Graph1005->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1005->GetZaxis()->SetTitleSize(0.072);
   Graph_Graph1005->GetZaxis()->SetTitleOffset(1.2);
   Graph_Graph1005->GetZaxis()->SetTitleFont(132);
   gre->SetHistogram(Graph_Graph1005);
   
   multigraph->Add(gre,"P");
   
   Double_t Graph_fx1006[6] = {
   0.5,
   1.5,
   2.5,
   3.5,
   4.5,
   5.5};
   Double_t Graph_fy1006[6] = {
   0.8913102,
   1.835833,
   2.168411,
   2.03538,
   2.407868,
   2.727143};
   Double_t Graph_fex1006[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1006[6] = {
   0.224823,
   0.2820265,
   0.3285875,
   0.3152843,
   0.3911122,
   0.4310216};
   gre = new TGraphErrors(6,Graph_fx1006,Graph_fy1006,Graph_fex1006,Graph_fey1006);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetLineColor(46);
   gre->SetLineWidth(2);
   gre->SetMarkerColor(46);
   gre->SetMarkerStyle(32);
   gre->SetMarkerSize(1.1);
   
   TH1F *Graph_Graph1006 = new TH1F("Graph_Graph1006","Graph",100,0,6);
   Graph_Graph1006->SetMinimum(0.4173194);
   Graph_Graph1006->SetMaximum(3.407332);
   Graph_Graph1006->SetDirectory(0);
   Graph_Graph1006->SetStats(0);
   Graph_Graph1006->SetLineWidth(2);
   Graph_Graph1006->SetMarkerStyle(20);
   Graph_Graph1006->GetXaxis()->SetNdivisions(505);
   Graph_Graph1006->GetXaxis()->SetLabelFont(132);
   Graph_Graph1006->GetXaxis()->SetLabelOffset(0.01);
   Graph_Graph1006->GetXaxis()->SetLabelSize(0.048);
   Graph_Graph1006->GetXaxis()->SetTitleSize(0.054);
   Graph_Graph1006->GetXaxis()->SetTitleOffset(1.2);
   Graph_Graph1006->GetXaxis()->SetTitleFont(132);
   Graph_Graph1006->GetYaxis()->SetLabelFont(132);
   Graph_Graph1006->GetYaxis()->SetLabelOffset(0.01);
   Graph_Graph1006->GetYaxis()->SetLabelSize(0.048);
   Graph_Graph1006->GetYaxis()->SetTitleSize(0.054);
   Graph_Graph1006->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph1006->GetYaxis()->SetTitleFont(132);
   Graph_Graph1006->GetZaxis()->SetLabelFont(132);
   Graph_Graph1006->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1006->GetZaxis()->SetTitleSize(0.072);
   Graph_Graph1006->GetZaxis()->SetTitleOffset(1.2);
   Graph_Graph1006->GetZaxis()->SetTitleFont(132);
   gre->SetHistogram(Graph_Graph1006);
   
   multigraph->Add(gre,"P");
   
   Double_t Graph_fx1007[1] = {
   5.4844};
   Double_t Graph_fy1007[1] = {
   3.082};
   Double_t Graph_fex1007[1] = {
   0};
   Double_t Graph_fey1007[1] = {
   0.811};
   gre = new TGraphErrors(1,Graph_fx1007,Graph_fy1007,Graph_fex1007,Graph_fey1007);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#006600");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#006600");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(26);
   gre->SetMarkerSize(1.1);
   
   TH1F *Graph_Graph1007 = new TH1F("Graph_Graph1007","Graph",100,5.3844,6.5844);
   Graph_Graph1007->SetMinimum(2.1088);
   Graph_Graph1007->SetMaximum(4.0552);
   Graph_Graph1007->SetDirectory(0);
   Graph_Graph1007->SetStats(0);
   Graph_Graph1007->SetLineWidth(2);
   Graph_Graph1007->SetMarkerStyle(20);
   Graph_Graph1007->GetXaxis()->SetTitle("#font[12]{p}_{T} [GeV/c]");
   Graph_Graph1007->GetXaxis()->SetNdivisions(505);
   Graph_Graph1007->GetXaxis()->SetLabelFont(132);
   Graph_Graph1007->GetXaxis()->SetLabelOffset(0.01);
   Graph_Graph1007->GetXaxis()->SetLabelSize(0.048);
   Graph_Graph1007->GetXaxis()->SetTitleSize(0.054);
   Graph_Graph1007->GetXaxis()->SetTitleOffset(1.2);
   Graph_Graph1007->GetXaxis()->SetTitleFont(132);
   Graph_Graph1007->GetYaxis()->SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
   Graph_Graph1007->GetYaxis()->SetLabelFont(132);
   Graph_Graph1007->GetYaxis()->SetLabelOffset(0.01);
   Graph_Graph1007->GetYaxis()->SetLabelSize(0.048);
   Graph_Graph1007->GetYaxis()->SetTitleSize(0.054);
   Graph_Graph1007->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph1007->GetYaxis()->SetTitleFont(132);
   Graph_Graph1007->GetZaxis()->SetLabelFont(132);
   Graph_Graph1007->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1007->GetZaxis()->SetTitleSize(0.072);
   Graph_Graph1007->GetZaxis()->SetTitleOffset(1.2);
   Graph_Graph1007->GetZaxis()->SetTitleFont(132);
   gre->SetHistogram(Graph_Graph1007);
   
   multigraph->Add(gre,"P");
   
   Double_t Graph_fx1008[5] = {
   1.205,
   2.977,
   4.888,
   6.855,
   10.375};
   Double_t Graph_fy1008[5] = {
   1.44085,
   1.91254,
   2.615,
   3.29964,
   3.94047};
   Double_t Graph_fex1008[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1008[5] = {
   0.04870332,
   0.07302509,
   0.07646792,
   0.06307084,
   0.06717979};
   gre = new TGraphErrors(5,Graph_fx1008,Graph_fy1008,Graph_fex1008,Graph_fey1008);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(21);
   gre->SetMarkerSize(0.6);
   
   TH1F *Graph_Graph1008 = new TH1F("Graph_Graph1008","Graph",100,0.288,11.292);
   Graph_Graph1008->SetMinimum(1.130596);
   Graph_Graph1008->SetMaximum(4.2692);
   Graph_Graph1008->SetDirectory(0);
   Graph_Graph1008->SetStats(0);
   Graph_Graph1008->SetLineWidth(2);
   Graph_Graph1008->SetMarkerStyle(20);
   Graph_Graph1008->GetXaxis()->SetNdivisions(505);
   Graph_Graph1008->GetXaxis()->SetLabelFont(132);
   Graph_Graph1008->GetXaxis()->SetLabelOffset(0.01);
   Graph_Graph1008->GetXaxis()->SetLabelSize(0.048);
   Graph_Graph1008->GetXaxis()->SetTitleSize(0.054);
   Graph_Graph1008->GetXaxis()->SetTitleOffset(1.2);
   Graph_Graph1008->GetXaxis()->SetTitleFont(132);
   Graph_Graph1008->GetYaxis()->SetLabelFont(132);
   Graph_Graph1008->GetYaxis()->SetLabelOffset(0.01);
   Graph_Graph1008->GetYaxis()->SetLabelSize(0.048);
   Graph_Graph1008->GetYaxis()->SetTitleSize(0.054);
   Graph_Graph1008->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph1008->GetYaxis()->SetTitleFont(132);
   Graph_Graph1008->GetZaxis()->SetLabelFont(132);
   Graph_Graph1008->GetZaxis()->SetLabelSize(0.06);
   Graph_Graph1008->GetZaxis()->SetTitleSize(0.072);
   Graph_Graph1008->GetZaxis()->SetTitleOffset(1.2);
   Graph_Graph1008->GetZaxis()->SetTitleFont(132);
   gre->SetHistogram(Graph_Graph1008);
   
   multigraph->Add(gre,"P");
   multigraph->Draw("a3");
   multigraph->GetXaxis()->SetLimits(0, 14);
   multigraph->GetXaxis()->SetTitle("#font[12]{p}_{T} [GeV/c]");
   multigraph->GetXaxis()->SetNdivisions(505);
   multigraph->GetXaxis()->SetLabelFont(132);
   multigraph->GetXaxis()->SetLabelOffset(0.01);
   multigraph->GetXaxis()->SetLabelSize(0.048);
   multigraph->GetXaxis()->SetTitleSize(0.054);
   multigraph->GetXaxis()->SetTitleOffset(1.2);
   multigraph->GetXaxis()->SetTitleFont(132);
   multigraph->GetYaxis()->SetTitle("B^{#psi(2S)}_{ll}#sigma_{#psi(2S)}/B^{J/#psi}_{ll}#sigma_{J/#psi} (%)");
   multigraph->GetYaxis()->SetLabelFont(132);
   multigraph->GetYaxis()->SetLabelOffset(0.01);
   multigraph->GetYaxis()->SetLabelSize(0.048);
   multigraph->GetYaxis()->SetTitleSize(0.054);
   multigraph->GetYaxis()->SetTitleOffset(1.2);
   multigraph->GetYaxis()->SetTitleFont(132);
   multigraph->SetMinimum(0);
   multigraph->SetMaximum(10);
   
   TLegend *leg = new TLegend(0.2,0.65,0.5,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(132);
   leg->SetTextSize(0.032);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("Graph","CDF 1.8 TeV, p+#bar{p}","lpf");
   entry->SetFillStyle(1000);

   ci = TColor::GetColor("#006600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#006600");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(26);
   entry->SetMarkerSize(1.1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("Graph","LHCb 7 TeV p+p (prompt)","lpf");
   entry->SetFillStyle(1000);
   entry->SetLineColor(7);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(7);
   entry->SetMarkerStyle(23);
   entry->SetMarkerSize(1.1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("Graph","HERA-B 41.6 GeV p+A","lpf");
   entry->SetFillStyle(1000);
   entry->SetLineColor(6);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(6);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1.1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("Graph","ALICE 13 TeV p+p","lpf");
   entry->SetFillStyle(1000);
   entry->SetLineColor(46);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(46);
   entry->SetMarkerStyle(32);
   entry->SetMarkerSize(1.1);
   entry->SetTextFont(132);
   leg->Draw();
   
   leg = new TLegend(0.51,0.65,0.81,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(132);
   leg->SetTextSize(0.032);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   entry=leg->AddEntry("Graph","NLO NRQCD","F");

   ci = TColor::GetColor("#3333cc");
   entry->SetFillColor(ci);
   entry->SetFillStyle(3244);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("Graph","CGC+NRQCD","F");

   ci = TColor::GetColor("#33cc33");
   entry->SetFillColor(ci);
   entry->SetFillStyle(3244);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("Graph","CMS 7TeV p+p","lpf");
   entry->SetFillStyle(1000);

   ci = TColor::GetColor("#000066");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#000066");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(29);
   entry->SetMarkerSize(1.1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("Graph","LHCb 13 TeV p+p, prompt","lpf");
   entry->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(0.6);
   entry->SetTextFont(132);
   leg->Draw();
   can->Modified();
   can->cd();
   can->SetSelected(can);
}
