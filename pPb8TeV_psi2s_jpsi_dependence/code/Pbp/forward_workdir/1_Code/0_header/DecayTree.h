//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Nov 21 06:32:18 2022 by ROOT version 6.24/08
// from TTree DecayTree/DecayTree
// found on file: Tuple.root
//////////////////////////////////////////////////////////

#ifndef DecayTree_h
#define DecayTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class DecayTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxpsi_ENDVERTEX_COV = 1;
   static constexpr Int_t kMaxpsi_OWNPV_COV = 1;
   static constexpr Int_t kMaxmup_OWNPV_COV = 1;
   static constexpr Int_t kMaxmup_ORIVX_COV = 1;
   static constexpr Int_t kMaxmum_OWNPV_COV = 1;
   static constexpr Int_t kMaxmum_ORIVX_COV = 1;

   // Declaration of leaf types
   Int_t           psi_nBackTracks;
   Int_t           psi_nForWardTracks;
   Double_t        psi_ENDVERTEX_X;
   Double_t        psi_ENDVERTEX_Y;
   Double_t        psi_ENDVERTEX_Z;
   Double_t        psi_ENDVERTEX_XERR;
   Double_t        psi_ENDVERTEX_YERR;
   Double_t        psi_ENDVERTEX_ZERR;
   Double_t        psi_ENDVERTEX_CHI2;
   Int_t           psi_ENDVERTEX_NDOF;
   Float_t         psi_ENDVERTEX_COV_[3][3];
   Double_t        psi_OWNPV_X;
   Double_t        psi_OWNPV_Y;
   Double_t        psi_OWNPV_Z;
   Double_t        psi_OWNPV_XERR;
   Double_t        psi_OWNPV_YERR;
   Double_t        psi_OWNPV_ZERR;
   Double_t        psi_OWNPV_CHI2;
   Int_t           psi_OWNPV_NDOF;
   Float_t         psi_OWNPV_COV_[3][3];
   Double_t        psi_IP_OWNPV;
   Double_t        psi_IPCHI2_OWNPV;
   Double_t        psi_FD_OWNPV;
   Double_t        psi_FDCHI2_OWNPV;
   Double_t        psi_DIRA_OWNPV;
   Double_t        psi_P;
   Double_t        psi_PT;
   Double_t        psi_PE;
   Double_t        psi_PX;
   Double_t        psi_PY;
   Double_t        psi_PZ;
   Double_t        psi_MM;
   Double_t        psi_MMERR;
   Double_t        psi_M;
   Int_t           psi_ID;
   Double_t        psi_TAU;
   Double_t        psi_TAUERR;
   Double_t        psi_TAUCHI2;
   Bool_t          psi_L0Global_Dec;
   Bool_t          psi_L0Global_TIS;
   Bool_t          psi_L0Global_TOS;
   Bool_t          psi_Hlt1Global_Dec;
   Bool_t          psi_Hlt1Global_TIS;
   Bool_t          psi_Hlt1Global_TOS;
   Bool_t          psi_Hlt1Phys_Dec;
   Bool_t          psi_Hlt1Phys_TIS;
   Bool_t          psi_Hlt1Phys_TOS;
   Bool_t          psi_L0MuonDecision_Dec;
   Bool_t          psi_L0MuonDecision_TIS;
   Bool_t          psi_L0MuonDecision_TOS;
   Bool_t          psi_L0DiMuonDecision_Dec;
   Bool_t          psi_L0DiMuonDecision_TIS;
   Bool_t          psi_L0DiMuonDecision_TOS;
   Bool_t          psi_Hlt1DiMuonHighMassDecision_Dec;
   Bool_t          psi_Hlt1DiMuonHighMassDecision_TIS;
   Bool_t          psi_Hlt1DiMuonHighMassDecision_TOS;
   Double_t        mup_MC12TuneV2_ProbNNe;
   Double_t        mup_MC12TuneV2_ProbNNmu;
   Double_t        mup_MC12TuneV2_ProbNNpi;
   Double_t        mup_MC12TuneV2_ProbNNk;
   Double_t        mup_MC12TuneV2_ProbNNp;
   Double_t        mup_MC12TuneV2_ProbNNghost;
   Double_t        mup_MC12TuneV3_ProbNNe;
   Double_t        mup_MC12TuneV3_ProbNNmu;
   Double_t        mup_MC12TuneV3_ProbNNpi;
   Double_t        mup_MC12TuneV3_ProbNNk;
   Double_t        mup_MC12TuneV3_ProbNNp;
   Double_t        mup_MC12TuneV3_ProbNNghost;
   Double_t        mup_MC12TuneV4_ProbNNe;
   Double_t        mup_MC12TuneV4_ProbNNmu;
   Double_t        mup_MC12TuneV4_ProbNNpi;
   Double_t        mup_MC12TuneV4_ProbNNk;
   Double_t        mup_MC12TuneV4_ProbNNp;
   Double_t        mup_MC12TuneV4_ProbNNghost;
   Double_t        mup_MC15TuneV1_ProbNNe;
   Double_t        mup_MC15TuneV1_ProbNNmu;
   Double_t        mup_MC15TuneV1_ProbNNpi;
   Double_t        mup_MC15TuneV1_ProbNNk;
   Double_t        mup_MC15TuneV1_ProbNNp;
   Double_t        mup_MC15TuneV1_ProbNNghost;
   Int_t           mup_nBackTracks;
   Int_t           mup_nForWardTracks;
   Double_t        mup_OWNPV_X;
   Double_t        mup_OWNPV_Y;
   Double_t        mup_OWNPV_Z;
   Double_t        mup_OWNPV_XERR;
   Double_t        mup_OWNPV_YERR;
   Double_t        mup_OWNPV_ZERR;
   Double_t        mup_OWNPV_CHI2;
   Int_t           mup_OWNPV_NDOF;
   Float_t         mup_OWNPV_COV_[3][3];
   Double_t        mup_IP_OWNPV;
   Double_t        mup_IPCHI2_OWNPV;
   Double_t        mup_ORIVX_X;
   Double_t        mup_ORIVX_Y;
   Double_t        mup_ORIVX_Z;
   Double_t        mup_ORIVX_XERR;
   Double_t        mup_ORIVX_YERR;
   Double_t        mup_ORIVX_ZERR;
   Double_t        mup_ORIVX_CHI2;
   Int_t           mup_ORIVX_NDOF;
   Float_t         mup_ORIVX_COV_[3][3];
   Double_t        mup_P;
   Double_t        mup_PT;
   Double_t        mup_PE;
   Double_t        mup_PX;
   Double_t        mup_PY;
   Double_t        mup_PZ;
   Double_t        mup_M;
   Int_t           mup_ID;
   Double_t        mup_PIDe;
   Double_t        mup_PIDmu;
   Double_t        mup_PIDK;
   Double_t        mup_PIDp;
   Double_t        mup_PIDd;
   Double_t        mup_ProbNNe;
   Double_t        mup_ProbNNk;
   Double_t        mup_ProbNNp;
   Double_t        mup_ProbNNpi;
   Double_t        mup_ProbNNmu;
   Double_t        mup_ProbNNd;
   Double_t        mup_ProbNNghost;
   Bool_t          mup_hasMuon;
   Bool_t          mup_isMuon;
   Bool_t          mup_hasRich;
   Bool_t          mup_UsedRichAerogel;
   Bool_t          mup_UsedRich1Gas;
   Bool_t          mup_UsedRich2Gas;
   Bool_t          mup_RichAboveElThres;
   Bool_t          mup_RichAboveMuThres;
   Bool_t          mup_RichAbovePiThres;
   Bool_t          mup_RichAboveKaThres;
   Bool_t          mup_RichAbovePrThres;
   Bool_t          mup_hasCalo;
   Int_t           mup_TRACK_Type;
   Int_t           mup_TRACK_Key;
   Double_t        mup_TRACK_CHI2NDOF;
   Double_t        mup_TRACK_PCHI2;
   Double_t        mup_TRACK_MatchCHI2;
   Double_t        mup_TRACK_GhostProb;
   Double_t        mup_TRACK_CloneDist;
   Double_t        mup_TRACK_Likelihood;
   Double_t        mum_MC12TuneV2_ProbNNe;
   Double_t        mum_MC12TuneV2_ProbNNmu;
   Double_t        mum_MC12TuneV2_ProbNNpi;
   Double_t        mum_MC12TuneV2_ProbNNk;
   Double_t        mum_MC12TuneV2_ProbNNp;
   Double_t        mum_MC12TuneV2_ProbNNghost;
   Double_t        mum_MC12TuneV3_ProbNNe;
   Double_t        mum_MC12TuneV3_ProbNNmu;
   Double_t        mum_MC12TuneV3_ProbNNpi;
   Double_t        mum_MC12TuneV3_ProbNNk;
   Double_t        mum_MC12TuneV3_ProbNNp;
   Double_t        mum_MC12TuneV3_ProbNNghost;
   Double_t        mum_MC12TuneV4_ProbNNe;
   Double_t        mum_MC12TuneV4_ProbNNmu;
   Double_t        mum_MC12TuneV4_ProbNNpi;
   Double_t        mum_MC12TuneV4_ProbNNk;
   Double_t        mum_MC12TuneV4_ProbNNp;
   Double_t        mum_MC12TuneV4_ProbNNghost;
   Double_t        mum_MC15TuneV1_ProbNNe;
   Double_t        mum_MC15TuneV1_ProbNNmu;
   Double_t        mum_MC15TuneV1_ProbNNpi;
   Double_t        mum_MC15TuneV1_ProbNNk;
   Double_t        mum_MC15TuneV1_ProbNNp;
   Double_t        mum_MC15TuneV1_ProbNNghost;
   Int_t           mum_nBackTracks;
   Int_t           mum_nForWardTracks;
   Double_t        mum_OWNPV_X;
   Double_t        mum_OWNPV_Y;
   Double_t        mum_OWNPV_Z;
   Double_t        mum_OWNPV_XERR;
   Double_t        mum_OWNPV_YERR;
   Double_t        mum_OWNPV_ZERR;
   Double_t        mum_OWNPV_CHI2;
   Int_t           mum_OWNPV_NDOF;
   Float_t         mum_OWNPV_COV_[3][3];
   Double_t        mum_IP_OWNPV;
   Double_t        mum_IPCHI2_OWNPV;
   Double_t        mum_ORIVX_X;
   Double_t        mum_ORIVX_Y;
   Double_t        mum_ORIVX_Z;
   Double_t        mum_ORIVX_XERR;
   Double_t        mum_ORIVX_YERR;
   Double_t        mum_ORIVX_ZERR;
   Double_t        mum_ORIVX_CHI2;
   Int_t           mum_ORIVX_NDOF;
   Float_t         mum_ORIVX_COV_[3][3];
   Double_t        mum_P;
   Double_t        mum_PT;
   Double_t        mum_PE;
   Double_t        mum_PX;
   Double_t        mum_PY;
   Double_t        mum_PZ;
   Double_t        mum_M;
   Int_t           mum_ID;
   Double_t        mum_PIDe;
   Double_t        mum_PIDmu;
   Double_t        mum_PIDK;
   Double_t        mum_PIDp;
   Double_t        mum_PIDd;
   Double_t        mum_ProbNNe;
   Double_t        mum_ProbNNk;
   Double_t        mum_ProbNNp;
   Double_t        mum_ProbNNpi;
   Double_t        mum_ProbNNmu;
   Double_t        mum_ProbNNd;
   Double_t        mum_ProbNNghost;
   Bool_t          mum_hasMuon;
   Bool_t          mum_isMuon;
   Bool_t          mum_hasRich;
   Bool_t          mum_UsedRichAerogel;
   Bool_t          mum_UsedRich1Gas;
   Bool_t          mum_UsedRich2Gas;
   Bool_t          mum_RichAboveElThres;
   Bool_t          mum_RichAboveMuThres;
   Bool_t          mum_RichAbovePiThres;
   Bool_t          mum_RichAboveKaThres;
   Bool_t          mum_RichAbovePrThres;
   Bool_t          mum_hasCalo;
   Int_t           mum_TRACK_Type;
   Int_t           mum_TRACK_Key;
   Double_t        mum_TRACK_CHI2NDOF;
   Double_t        mum_TRACK_PCHI2;
   Double_t        mum_TRACK_MatchCHI2;
   Double_t        mum_TRACK_GhostProb;
   Double_t        mum_TRACK_CloneDist;
   Double_t        mum_TRACK_Likelihood;
   UInt_t          nCandidate;
   ULong64_t       totCandidates;
   ULong64_t       EventInSequence;
   UInt_t          runNumber;
   ULong64_t       eventNumber;
   UInt_t          BCID;
   Int_t           BCType;
   UInt_t          OdinTCK;
   UInt_t          L0DUTCK;
   UInt_t          HLT1TCK;
   UInt_t          HLT2TCK;
   ULong64_t       GpsTime;
   Short_t         Polarity;
   Int_t           nPV;
   Float_t         PVX[100];   //[nPV]
   Float_t         PVY[100];   //[nPV]
   Float_t         PVZ[100];   //[nPV]
   Float_t         PVXERR[100];   //[nPV]
   Float_t         PVYERR[100];   //[nPV]
   Float_t         PVZERR[100];   //[nPV]
   Float_t         PVCHI2[100];   //[nPV]
   Float_t         PVNDOF[100];   //[nPV]
   Float_t         PVNTRACKS[100];   //[nPV]
   Int_t           nPVs;
   Int_t           nTracks;
   Int_t           nLongTracks;
   Int_t           nDownstreamTracks;
   Int_t           nUpstreamTracks;
   Int_t           nVeloTracks;
   Int_t           nTTracks;
   Int_t           nBackTracks;
   Int_t           nRich1Hits;
   Int_t           nRich2Hits;
   Int_t           nVeloClusters;
   Int_t           nITClusters;
   Int_t           nTTClusters;
   Int_t           nOTClusters;
   Int_t           nSPDHits;
   Int_t           nMuonCoordsS0;
   Int_t           nMuonCoordsS1;
   Int_t           nMuonCoordsS2;
   Int_t           nMuonCoordsS3;
   Int_t           nMuonCoordsS4;
   Int_t           nMuonTracks;

   // List of branches
   TBranch        *b_psi_nBackTracks;   //!
   TBranch        *b_psi_nForWardTracks;   //!
   TBranch        *b_psi_ENDVERTEX_X;   //!
   TBranch        *b_psi_ENDVERTEX_Y;   //!
   TBranch        *b_psi_ENDVERTEX_Z;   //!
   TBranch        *b_psi_ENDVERTEX_XERR;   //!
   TBranch        *b_psi_ENDVERTEX_YERR;   //!
   TBranch        *b_psi_ENDVERTEX_ZERR;   //!
   TBranch        *b_psi_ENDVERTEX_CHI2;   //!
   TBranch        *b_psi_ENDVERTEX_NDOF;   //!
   TBranch        *b_psi_ENDVERTEX_COV_;   //!
   TBranch        *b_psi_OWNPV_X;   //!
   TBranch        *b_psi_OWNPV_Y;   //!
   TBranch        *b_psi_OWNPV_Z;   //!
   TBranch        *b_psi_OWNPV_XERR;   //!
   TBranch        *b_psi_OWNPV_YERR;   //!
   TBranch        *b_psi_OWNPV_ZERR;   //!
   TBranch        *b_psi_OWNPV_CHI2;   //!
   TBranch        *b_psi_OWNPV_NDOF;   //!
   TBranch        *b_psi_OWNPV_COV_;   //!
   TBranch        *b_psi_IP_OWNPV;   //!
   TBranch        *b_psi_IPCHI2_OWNPV;   //!
   TBranch        *b_psi_FD_OWNPV;   //!
   TBranch        *b_psi_FDCHI2_OWNPV;   //!
   TBranch        *b_psi_DIRA_OWNPV;   //!
   TBranch        *b_psi_P;   //!
   TBranch        *b_psi_PT;   //!
   TBranch        *b_psi_PE;   //!
   TBranch        *b_psi_PX;   //!
   TBranch        *b_psi_PY;   //!
   TBranch        *b_psi_PZ;   //!
   TBranch        *b_psi_MM;   //!
   TBranch        *b_psi_MMERR;   //!
   TBranch        *b_psi_M;   //!
   TBranch        *b_psi_ID;   //!
   TBranch        *b_psi_TAU;   //!
   TBranch        *b_psi_TAUERR;   //!
   TBranch        *b_psi_TAUCHI2;   //!
   TBranch        *b_psi_L0Global_Dec;   //!
   TBranch        *b_psi_L0Global_TIS;   //!
   TBranch        *b_psi_L0Global_TOS;   //!
   TBranch        *b_psi_Hlt1Global_Dec;   //!
   TBranch        *b_psi_Hlt1Global_TIS;   //!
   TBranch        *b_psi_Hlt1Global_TOS;   //!
   TBranch        *b_psi_Hlt1Phys_Dec;   //!
   TBranch        *b_psi_Hlt1Phys_TIS;   //!
   TBranch        *b_psi_Hlt1Phys_TOS;   //!
   TBranch        *b_psi_L0MuonDecision_Dec;   //!
   TBranch        *b_psi_L0MuonDecision_TIS;   //!
   TBranch        *b_psi_L0MuonDecision_TOS;   //!
   TBranch        *b_psi_L0DiMuonDecision_Dec;   //!
   TBranch        *b_psi_L0DiMuonDecision_TIS;   //!
   TBranch        *b_psi_L0DiMuonDecision_TOS;   //!
   TBranch        *b_psi_Hlt1DiMuonHighMassDecision_Dec;   //!
   TBranch        *b_psi_Hlt1DiMuonHighMassDecision_TIS;   //!
   TBranch        *b_psi_Hlt1DiMuonHighMassDecision_TOS;   //!
   TBranch        *b_mup_MC12TuneV2_ProbNNe;   //!
   TBranch        *b_mup_MC12TuneV2_ProbNNmu;   //!
   TBranch        *b_mup_MC12TuneV2_ProbNNpi;   //!
   TBranch        *b_mup_MC12TuneV2_ProbNNk;   //!
   TBranch        *b_mup_MC12TuneV2_ProbNNp;   //!
   TBranch        *b_mup_MC12TuneV2_ProbNNghost;   //!
   TBranch        *b_mup_MC12TuneV3_ProbNNe;   //!
   TBranch        *b_mup_MC12TuneV3_ProbNNmu;   //!
   TBranch        *b_mup_MC12TuneV3_ProbNNpi;   //!
   TBranch        *b_mup_MC12TuneV3_ProbNNk;   //!
   TBranch        *b_mup_MC12TuneV3_ProbNNp;   //!
   TBranch        *b_mup_MC12TuneV3_ProbNNghost;   //!
   TBranch        *b_mup_MC12TuneV4_ProbNNe;   //!
   TBranch        *b_mup_MC12TuneV4_ProbNNmu;   //!
   TBranch        *b_mup_MC12TuneV4_ProbNNpi;   //!
   TBranch        *b_mup_MC12TuneV4_ProbNNk;   //!
   TBranch        *b_mup_MC12TuneV4_ProbNNp;   //!
   TBranch        *b_mup_MC12TuneV4_ProbNNghost;   //!
   TBranch        *b_mup_MC15TuneV1_ProbNNe;   //!
   TBranch        *b_mup_MC15TuneV1_ProbNNmu;   //!
   TBranch        *b_mup_MC15TuneV1_ProbNNpi;   //!
   TBranch        *b_mup_MC15TuneV1_ProbNNk;   //!
   TBranch        *b_mup_MC15TuneV1_ProbNNp;   //!
   TBranch        *b_mup_MC15TuneV1_ProbNNghost;   //!
   TBranch        *b_mup_nBackTracks;   //!
   TBranch        *b_mup_nForWardTracks;   //!
   TBranch        *b_mup_OWNPV_X;   //!
   TBranch        *b_mup_OWNPV_Y;   //!
   TBranch        *b_mup_OWNPV_Z;   //!
   TBranch        *b_mup_OWNPV_XERR;   //!
   TBranch        *b_mup_OWNPV_YERR;   //!
   TBranch        *b_mup_OWNPV_ZERR;   //!
   TBranch        *b_mup_OWNPV_CHI2;   //!
   TBranch        *b_mup_OWNPV_NDOF;   //!
   TBranch        *b_mup_OWNPV_COV_;   //!
   TBranch        *b_mup_IP_OWNPV;   //!
   TBranch        *b_mup_IPCHI2_OWNPV;   //!
   TBranch        *b_mup_ORIVX_X;   //!
   TBranch        *b_mup_ORIVX_Y;   //!
   TBranch        *b_mup_ORIVX_Z;   //!
   TBranch        *b_mup_ORIVX_XERR;   //!
   TBranch        *b_mup_ORIVX_YERR;   //!
   TBranch        *b_mup_ORIVX_ZERR;   //!
   TBranch        *b_mup_ORIVX_CHI2;   //!
   TBranch        *b_mup_ORIVX_NDOF;   //!
   TBranch        *b_mup_ORIVX_COV_;   //!
   TBranch        *b_mup_P;   //!
   TBranch        *b_mup_PT;   //!
   TBranch        *b_mup_PE;   //!
   TBranch        *b_mup_PX;   //!
   TBranch        *b_mup_PY;   //!
   TBranch        *b_mup_PZ;   //!
   TBranch        *b_mup_M;   //!
   TBranch        *b_mup_ID;   //!
   TBranch        *b_mup_PIDe;   //!
   TBranch        *b_mup_PIDmu;   //!
   TBranch        *b_mup_PIDK;   //!
   TBranch        *b_mup_PIDp;   //!
   TBranch        *b_mup_PIDd;   //!
   TBranch        *b_mup_ProbNNe;   //!
   TBranch        *b_mup_ProbNNk;   //!
   TBranch        *b_mup_ProbNNp;   //!
   TBranch        *b_mup_ProbNNpi;   //!
   TBranch        *b_mup_ProbNNmu;   //!
   TBranch        *b_mup_ProbNNd;   //!
   TBranch        *b_mup_ProbNNghost;   //!
   TBranch        *b_mup_hasMuon;   //!
   TBranch        *b_mup_isMuon;   //!
   TBranch        *b_mup_hasRich;   //!
   TBranch        *b_mup_UsedRichAerogel;   //!
   TBranch        *b_mup_UsedRich1Gas;   //!
   TBranch        *b_mup_UsedRich2Gas;   //!
   TBranch        *b_mup_RichAboveElThres;   //!
   TBranch        *b_mup_RichAboveMuThres;   //!
   TBranch        *b_mup_RichAbovePiThres;   //!
   TBranch        *b_mup_RichAboveKaThres;   //!
   TBranch        *b_mup_RichAbovePrThres;   //!
   TBranch        *b_mup_hasCalo;   //!
   TBranch        *b_mup_TRACK_Type;   //!
   TBranch        *b_mup_TRACK_Key;   //!
   TBranch        *b_mup_TRACK_CHI2NDOF;   //!
   TBranch        *b_mup_TRACK_PCHI2;   //!
   TBranch        *b_mup_TRACK_MatchCHI2;   //!
   TBranch        *b_mup_TRACK_GhostProb;   //!
   TBranch        *b_mup_TRACK_CloneDist;   //!
   TBranch        *b_mup_TRACK_Likelihood;   //!
   TBranch        *b_mum_MC12TuneV2_ProbNNe;   //!
   TBranch        *b_mum_MC12TuneV2_ProbNNmu;   //!
   TBranch        *b_mum_MC12TuneV2_ProbNNpi;   //!
   TBranch        *b_mum_MC12TuneV2_ProbNNk;   //!
   TBranch        *b_mum_MC12TuneV2_ProbNNp;   //!
   TBranch        *b_mum_MC12TuneV2_ProbNNghost;   //!
   TBranch        *b_mum_MC12TuneV3_ProbNNe;   //!
   TBranch        *b_mum_MC12TuneV3_ProbNNmu;   //!
   TBranch        *b_mum_MC12TuneV3_ProbNNpi;   //!
   TBranch        *b_mum_MC12TuneV3_ProbNNk;   //!
   TBranch        *b_mum_MC12TuneV3_ProbNNp;   //!
   TBranch        *b_mum_MC12TuneV3_ProbNNghost;   //!
   TBranch        *b_mum_MC12TuneV4_ProbNNe;   //!
   TBranch        *b_mum_MC12TuneV4_ProbNNmu;   //!
   TBranch        *b_mum_MC12TuneV4_ProbNNpi;   //!
   TBranch        *b_mum_MC12TuneV4_ProbNNk;   //!
   TBranch        *b_mum_MC12TuneV4_ProbNNp;   //!
   TBranch        *b_mum_MC12TuneV4_ProbNNghost;   //!
   TBranch        *b_mum_MC15TuneV1_ProbNNe;   //!
   TBranch        *b_mum_MC15TuneV1_ProbNNmu;   //!
   TBranch        *b_mum_MC15TuneV1_ProbNNpi;   //!
   TBranch        *b_mum_MC15TuneV1_ProbNNk;   //!
   TBranch        *b_mum_MC15TuneV1_ProbNNp;   //!
   TBranch        *b_mum_MC15TuneV1_ProbNNghost;   //!
   TBranch        *b_mum_nBackTracks;   //!
   TBranch        *b_mum_nForWardTracks;   //!
   TBranch        *b_mum_OWNPV_X;   //!
   TBranch        *b_mum_OWNPV_Y;   //!
   TBranch        *b_mum_OWNPV_Z;   //!
   TBranch        *b_mum_OWNPV_XERR;   //!
   TBranch        *b_mum_OWNPV_YERR;   //!
   TBranch        *b_mum_OWNPV_ZERR;   //!
   TBranch        *b_mum_OWNPV_CHI2;   //!
   TBranch        *b_mum_OWNPV_NDOF;   //!
   TBranch        *b_mum_OWNPV_COV_;   //!
   TBranch        *b_mum_IP_OWNPV;   //!
   TBranch        *b_mum_IPCHI2_OWNPV;   //!
   TBranch        *b_mum_ORIVX_X;   //!
   TBranch        *b_mum_ORIVX_Y;   //!
   TBranch        *b_mum_ORIVX_Z;   //!
   TBranch        *b_mum_ORIVX_XERR;   //!
   TBranch        *b_mum_ORIVX_YERR;   //!
   TBranch        *b_mum_ORIVX_ZERR;   //!
   TBranch        *b_mum_ORIVX_CHI2;   //!
   TBranch        *b_mum_ORIVX_NDOF;   //!
   TBranch        *b_mum_ORIVX_COV_;   //!
   TBranch        *b_mum_P;   //!
   TBranch        *b_mum_PT;   //!
   TBranch        *b_mum_PE;   //!
   TBranch        *b_mum_PX;   //!
   TBranch        *b_mum_PY;   //!
   TBranch        *b_mum_PZ;   //!
   TBranch        *b_mum_M;   //!
   TBranch        *b_mum_ID;   //!
   TBranch        *b_mum_PIDe;   //!
   TBranch        *b_mum_PIDmu;   //!
   TBranch        *b_mum_PIDK;   //!
   TBranch        *b_mum_PIDp;   //!
   TBranch        *b_mum_PIDd;   //!
   TBranch        *b_mum_ProbNNe;   //!
   TBranch        *b_mum_ProbNNk;   //!
   TBranch        *b_mum_ProbNNp;   //!
   TBranch        *b_mum_ProbNNpi;   //!
   TBranch        *b_mum_ProbNNmu;   //!
   TBranch        *b_mum_ProbNNd;   //!
   TBranch        *b_mum_ProbNNghost;   //!
   TBranch        *b_mum_hasMuon;   //!
   TBranch        *b_mum_isMuon;   //!
   TBranch        *b_mum_hasRich;   //!
   TBranch        *b_mum_UsedRichAerogel;   //!
   TBranch        *b_mum_UsedRich1Gas;   //!
   TBranch        *b_mum_UsedRich2Gas;   //!
   TBranch        *b_mum_RichAboveElThres;   //!
   TBranch        *b_mum_RichAboveMuThres;   //!
   TBranch        *b_mum_RichAbovePiThres;   //!
   TBranch        *b_mum_RichAboveKaThres;   //!
   TBranch        *b_mum_RichAbovePrThres;   //!
   TBranch        *b_mum_hasCalo;   //!
   TBranch        *b_mum_TRACK_Type;   //!
   TBranch        *b_mum_TRACK_Key;   //!
   TBranch        *b_mum_TRACK_CHI2NDOF;   //!
   TBranch        *b_mum_TRACK_PCHI2;   //!
   TBranch        *b_mum_TRACK_MatchCHI2;   //!
   TBranch        *b_mum_TRACK_GhostProb;   //!
   TBranch        *b_mum_TRACK_CloneDist;   //!
   TBranch        *b_mum_TRACK_Likelihood;   //!
   TBranch        *b_nCandidate;   //!
   TBranch        *b_totCandidates;   //!
   TBranch        *b_EventInSequence;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_BCID;   //!
   TBranch        *b_BCType;   //!
   TBranch        *b_OdinTCK;   //!
   TBranch        *b_L0DUTCK;   //!
   TBranch        *b_HLT1TCK;   //!
   TBranch        *b_HLT2TCK;   //!
   TBranch        *b_GpsTime;   //!
   TBranch        *b_Polarity;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_PVX;   //!
   TBranch        *b_PVY;   //!
   TBranch        *b_PVZ;   //!
   TBranch        *b_PVXERR;   //!
   TBranch        *b_PVYERR;   //!
   TBranch        *b_PVZERR;   //!
   TBranch        *b_PVCHI2;   //!
   TBranch        *b_PVNDOF;   //!
   TBranch        *b_PVNTRACKS;   //!
   TBranch        *b_nPVs;   //!
   TBranch        *b_nTracks;   //!
   TBranch        *b_nLongTracks;   //!
   TBranch        *b_nDownstreamTracks;   //!
   TBranch        *b_nUpstreamTracks;   //!
   TBranch        *b_nVeloTracks;   //!
   TBranch        *b_nTTracks;   //!
   TBranch        *b_nBackTracks;   //!
   TBranch        *b_nRich1Hits;   //!
   TBranch        *b_nRich2Hits;   //!
   TBranch        *b_nVeloClusters;   //!
   TBranch        *b_nITClusters;   //!
   TBranch        *b_nTTClusters;   //!
   TBranch        *b_nOTClusters;   //!
   TBranch        *b_nSPDHits;   //!
   TBranch        *b_nMuonCoordsS0;   //!
   TBranch        *b_nMuonCoordsS1;   //!
   TBranch        *b_nMuonCoordsS2;   //!
   TBranch        *b_nMuonCoordsS3;   //!
   TBranch        *b_nMuonCoordsS4;   //!
   TBranch        *b_nMuonTracks;   //!

   DecayTree(TTree *tree=0);
   virtual ~DecayTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
//   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef DecayTree_cxx
DecayTree::DecayTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Tuple.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("Tuple.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("Tuple.root:/tuple1");
      dir->GetObject("DecayTree",tree);

   }
   Init(tree);
}

DecayTree::~DecayTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DecayTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DecayTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void DecayTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("psi_nBackTracks", &psi_nBackTracks, &b_psi_nBackTracks);
   fChain->SetBranchAddress("psi_nForWardTracks", &psi_nForWardTracks, &b_psi_nForWardTracks);
   fChain->SetBranchAddress("psi_ENDVERTEX_X", &psi_ENDVERTEX_X, &b_psi_ENDVERTEX_X);
   fChain->SetBranchAddress("psi_ENDVERTEX_Y", &psi_ENDVERTEX_Y, &b_psi_ENDVERTEX_Y);
   fChain->SetBranchAddress("psi_ENDVERTEX_Z", &psi_ENDVERTEX_Z, &b_psi_ENDVERTEX_Z);
   fChain->SetBranchAddress("psi_ENDVERTEX_XERR", &psi_ENDVERTEX_XERR, &b_psi_ENDVERTEX_XERR);
   fChain->SetBranchAddress("psi_ENDVERTEX_YERR", &psi_ENDVERTEX_YERR, &b_psi_ENDVERTEX_YERR);
   fChain->SetBranchAddress("psi_ENDVERTEX_ZERR", &psi_ENDVERTEX_ZERR, &b_psi_ENDVERTEX_ZERR);
   fChain->SetBranchAddress("psi_ENDVERTEX_CHI2", &psi_ENDVERTEX_CHI2, &b_psi_ENDVERTEX_CHI2);
   fChain->SetBranchAddress("psi_ENDVERTEX_NDOF", &psi_ENDVERTEX_NDOF, &b_psi_ENDVERTEX_NDOF);
   fChain->SetBranchAddress("psi_ENDVERTEX_COV_", psi_ENDVERTEX_COV_, &b_psi_ENDVERTEX_COV_);
   fChain->SetBranchAddress("psi_OWNPV_X", &psi_OWNPV_X, &b_psi_OWNPV_X);
   fChain->SetBranchAddress("psi_OWNPV_Y", &psi_OWNPV_Y, &b_psi_OWNPV_Y);
   fChain->SetBranchAddress("psi_OWNPV_Z", &psi_OWNPV_Z, &b_psi_OWNPV_Z);
   fChain->SetBranchAddress("psi_OWNPV_XERR", &psi_OWNPV_XERR, &b_psi_OWNPV_XERR);
   fChain->SetBranchAddress("psi_OWNPV_YERR", &psi_OWNPV_YERR, &b_psi_OWNPV_YERR);
   fChain->SetBranchAddress("psi_OWNPV_ZERR", &psi_OWNPV_ZERR, &b_psi_OWNPV_ZERR);
   fChain->SetBranchAddress("psi_OWNPV_CHI2", &psi_OWNPV_CHI2, &b_psi_OWNPV_CHI2);
   fChain->SetBranchAddress("psi_OWNPV_NDOF", &psi_OWNPV_NDOF, &b_psi_OWNPV_NDOF);
   fChain->SetBranchAddress("psi_OWNPV_COV_", psi_OWNPV_COV_, &b_psi_OWNPV_COV_);
   fChain->SetBranchAddress("psi_IP_OWNPV", &psi_IP_OWNPV, &b_psi_IP_OWNPV);
   fChain->SetBranchAddress("psi_IPCHI2_OWNPV", &psi_IPCHI2_OWNPV, &b_psi_IPCHI2_OWNPV);
   fChain->SetBranchAddress("psi_FD_OWNPV", &psi_FD_OWNPV, &b_psi_FD_OWNPV);
   fChain->SetBranchAddress("psi_FDCHI2_OWNPV", &psi_FDCHI2_OWNPV, &b_psi_FDCHI2_OWNPV);
   fChain->SetBranchAddress("psi_DIRA_OWNPV", &psi_DIRA_OWNPV, &b_psi_DIRA_OWNPV);
   fChain->SetBranchAddress("psi_P", &psi_P, &b_psi_P);
   fChain->SetBranchAddress("psi_PT", &psi_PT, &b_psi_PT);
   fChain->SetBranchAddress("psi_PE", &psi_PE, &b_psi_PE);
   fChain->SetBranchAddress("psi_PX", &psi_PX, &b_psi_PX);
   fChain->SetBranchAddress("psi_PY", &psi_PY, &b_psi_PY);
   fChain->SetBranchAddress("psi_PZ", &psi_PZ, &b_psi_PZ);
   fChain->SetBranchAddress("psi_MM", &psi_MM, &b_psi_MM);
   fChain->SetBranchAddress("psi_MMERR", &psi_MMERR, &b_psi_MMERR);
   fChain->SetBranchAddress("psi_M", &psi_M, &b_psi_M);
   fChain->SetBranchAddress("psi_ID", &psi_ID, &b_psi_ID);
   fChain->SetBranchAddress("psi_TAU", &psi_TAU, &b_psi_TAU);
   fChain->SetBranchAddress("psi_TAUERR", &psi_TAUERR, &b_psi_TAUERR);
   fChain->SetBranchAddress("psi_TAUCHI2", &psi_TAUCHI2, &b_psi_TAUCHI2);
   fChain->SetBranchAddress("psi_L0Global_Dec", &psi_L0Global_Dec, &b_psi_L0Global_Dec);
   fChain->SetBranchAddress("psi_L0Global_TIS", &psi_L0Global_TIS, &b_psi_L0Global_TIS);
   fChain->SetBranchAddress("psi_L0Global_TOS", &psi_L0Global_TOS, &b_psi_L0Global_TOS);
   fChain->SetBranchAddress("psi_Hlt1Global_Dec", &psi_Hlt1Global_Dec, &b_psi_Hlt1Global_Dec);
   fChain->SetBranchAddress("psi_Hlt1Global_TIS", &psi_Hlt1Global_TIS, &b_psi_Hlt1Global_TIS);
   fChain->SetBranchAddress("psi_Hlt1Global_TOS", &psi_Hlt1Global_TOS, &b_psi_Hlt1Global_TOS);
   fChain->SetBranchAddress("psi_Hlt1Phys_Dec", &psi_Hlt1Phys_Dec, &b_psi_Hlt1Phys_Dec);
   fChain->SetBranchAddress("psi_Hlt1Phys_TIS", &psi_Hlt1Phys_TIS, &b_psi_Hlt1Phys_TIS);
   fChain->SetBranchAddress("psi_Hlt1Phys_TOS", &psi_Hlt1Phys_TOS, &b_psi_Hlt1Phys_TOS);
   fChain->SetBranchAddress("psi_L0MuonDecision_Dec", &psi_L0MuonDecision_Dec, &b_psi_L0MuonDecision_Dec);
   fChain->SetBranchAddress("psi_L0MuonDecision_TIS", &psi_L0MuonDecision_TIS, &b_psi_L0MuonDecision_TIS);
   fChain->SetBranchAddress("psi_L0MuonDecision_TOS", &psi_L0MuonDecision_TOS, &b_psi_L0MuonDecision_TOS);
   fChain->SetBranchAddress("psi_L0DiMuonDecision_Dec", &psi_L0DiMuonDecision_Dec, &b_psi_L0DiMuonDecision_Dec);
   fChain->SetBranchAddress("psi_L0DiMuonDecision_TIS", &psi_L0DiMuonDecision_TIS, &b_psi_L0DiMuonDecision_TIS);
   fChain->SetBranchAddress("psi_L0DiMuonDecision_TOS", &psi_L0DiMuonDecision_TOS, &b_psi_L0DiMuonDecision_TOS);
   fChain->SetBranchAddress("psi_Hlt1DiMuonHighMassDecision_Dec", &psi_Hlt1DiMuonHighMassDecision_Dec, &b_psi_Hlt1DiMuonHighMassDecision_Dec);
   fChain->SetBranchAddress("psi_Hlt1DiMuonHighMassDecision_TIS", &psi_Hlt1DiMuonHighMassDecision_TIS, &b_psi_Hlt1DiMuonHighMassDecision_TIS);
   fChain->SetBranchAddress("psi_Hlt1DiMuonHighMassDecision_TOS", &psi_Hlt1DiMuonHighMassDecision_TOS, &b_psi_Hlt1DiMuonHighMassDecision_TOS);
   fChain->SetBranchAddress("mup_MC12TuneV2_ProbNNe", &mup_MC12TuneV2_ProbNNe, &b_mup_MC12TuneV2_ProbNNe);
   fChain->SetBranchAddress("mup_MC12TuneV2_ProbNNmu", &mup_MC12TuneV2_ProbNNmu, &b_mup_MC12TuneV2_ProbNNmu);
   fChain->SetBranchAddress("mup_MC12TuneV2_ProbNNpi", &mup_MC12TuneV2_ProbNNpi, &b_mup_MC12TuneV2_ProbNNpi);
   fChain->SetBranchAddress("mup_MC12TuneV2_ProbNNk", &mup_MC12TuneV2_ProbNNk, &b_mup_MC12TuneV2_ProbNNk);
   fChain->SetBranchAddress("mup_MC12TuneV2_ProbNNp", &mup_MC12TuneV2_ProbNNp, &b_mup_MC12TuneV2_ProbNNp);
   fChain->SetBranchAddress("mup_MC12TuneV2_ProbNNghost", &mup_MC12TuneV2_ProbNNghost, &b_mup_MC12TuneV2_ProbNNghost);
   fChain->SetBranchAddress("mup_MC12TuneV3_ProbNNe", &mup_MC12TuneV3_ProbNNe, &b_mup_MC12TuneV3_ProbNNe);
   fChain->SetBranchAddress("mup_MC12TuneV3_ProbNNmu", &mup_MC12TuneV3_ProbNNmu, &b_mup_MC12TuneV3_ProbNNmu);
   fChain->SetBranchAddress("mup_MC12TuneV3_ProbNNpi", &mup_MC12TuneV3_ProbNNpi, &b_mup_MC12TuneV3_ProbNNpi);
   fChain->SetBranchAddress("mup_MC12TuneV3_ProbNNk", &mup_MC12TuneV3_ProbNNk, &b_mup_MC12TuneV3_ProbNNk);
   fChain->SetBranchAddress("mup_MC12TuneV3_ProbNNp", &mup_MC12TuneV3_ProbNNp, &b_mup_MC12TuneV3_ProbNNp);
   fChain->SetBranchAddress("mup_MC12TuneV3_ProbNNghost", &mup_MC12TuneV3_ProbNNghost, &b_mup_MC12TuneV3_ProbNNghost);
   fChain->SetBranchAddress("mup_MC12TuneV4_ProbNNe", &mup_MC12TuneV4_ProbNNe, &b_mup_MC12TuneV4_ProbNNe);
   fChain->SetBranchAddress("mup_MC12TuneV4_ProbNNmu", &mup_MC12TuneV4_ProbNNmu, &b_mup_MC12TuneV4_ProbNNmu);
   fChain->SetBranchAddress("mup_MC12TuneV4_ProbNNpi", &mup_MC12TuneV4_ProbNNpi, &b_mup_MC12TuneV4_ProbNNpi);
   fChain->SetBranchAddress("mup_MC12TuneV4_ProbNNk", &mup_MC12TuneV4_ProbNNk, &b_mup_MC12TuneV4_ProbNNk);
   fChain->SetBranchAddress("mup_MC12TuneV4_ProbNNp", &mup_MC12TuneV4_ProbNNp, &b_mup_MC12TuneV4_ProbNNp);
   fChain->SetBranchAddress("mup_MC12TuneV4_ProbNNghost", &mup_MC12TuneV4_ProbNNghost, &b_mup_MC12TuneV4_ProbNNghost);
   fChain->SetBranchAddress("mup_MC15TuneV1_ProbNNe", &mup_MC15TuneV1_ProbNNe, &b_mup_MC15TuneV1_ProbNNe);
   fChain->SetBranchAddress("mup_MC15TuneV1_ProbNNmu", &mup_MC15TuneV1_ProbNNmu, &b_mup_MC15TuneV1_ProbNNmu);
   fChain->SetBranchAddress("mup_MC15TuneV1_ProbNNpi", &mup_MC15TuneV1_ProbNNpi, &b_mup_MC15TuneV1_ProbNNpi);
   fChain->SetBranchAddress("mup_MC15TuneV1_ProbNNk", &mup_MC15TuneV1_ProbNNk, &b_mup_MC15TuneV1_ProbNNk);
   fChain->SetBranchAddress("mup_MC15TuneV1_ProbNNp", &mup_MC15TuneV1_ProbNNp, &b_mup_MC15TuneV1_ProbNNp);
   fChain->SetBranchAddress("mup_MC15TuneV1_ProbNNghost", &mup_MC15TuneV1_ProbNNghost, &b_mup_MC15TuneV1_ProbNNghost);
   fChain->SetBranchAddress("mup_nBackTracks", &mup_nBackTracks, &b_mup_nBackTracks);
   fChain->SetBranchAddress("mup_nForWardTracks", &mup_nForWardTracks, &b_mup_nForWardTracks);
   fChain->SetBranchAddress("mup_OWNPV_X", &mup_OWNPV_X, &b_mup_OWNPV_X);
   fChain->SetBranchAddress("mup_OWNPV_Y", &mup_OWNPV_Y, &b_mup_OWNPV_Y);
   fChain->SetBranchAddress("mup_OWNPV_Z", &mup_OWNPV_Z, &b_mup_OWNPV_Z);
   fChain->SetBranchAddress("mup_OWNPV_XERR", &mup_OWNPV_XERR, &b_mup_OWNPV_XERR);
   fChain->SetBranchAddress("mup_OWNPV_YERR", &mup_OWNPV_YERR, &b_mup_OWNPV_YERR);
   fChain->SetBranchAddress("mup_OWNPV_ZERR", &mup_OWNPV_ZERR, &b_mup_OWNPV_ZERR);
   fChain->SetBranchAddress("mup_OWNPV_CHI2", &mup_OWNPV_CHI2, &b_mup_OWNPV_CHI2);
   fChain->SetBranchAddress("mup_OWNPV_NDOF", &mup_OWNPV_NDOF, &b_mup_OWNPV_NDOF);
   fChain->SetBranchAddress("mup_OWNPV_COV_", mup_OWNPV_COV_, &b_mup_OWNPV_COV_);
   fChain->SetBranchAddress("mup_IP_OWNPV", &mup_IP_OWNPV, &b_mup_IP_OWNPV);
   fChain->SetBranchAddress("mup_IPCHI2_OWNPV", &mup_IPCHI2_OWNPV, &b_mup_IPCHI2_OWNPV);
   fChain->SetBranchAddress("mup_ORIVX_X", &mup_ORIVX_X, &b_mup_ORIVX_X);
   fChain->SetBranchAddress("mup_ORIVX_Y", &mup_ORIVX_Y, &b_mup_ORIVX_Y);
   fChain->SetBranchAddress("mup_ORIVX_Z", &mup_ORIVX_Z, &b_mup_ORIVX_Z);
   fChain->SetBranchAddress("mup_ORIVX_XERR", &mup_ORIVX_XERR, &b_mup_ORIVX_XERR);
   fChain->SetBranchAddress("mup_ORIVX_YERR", &mup_ORIVX_YERR, &b_mup_ORIVX_YERR);
   fChain->SetBranchAddress("mup_ORIVX_ZERR", &mup_ORIVX_ZERR, &b_mup_ORIVX_ZERR);
   fChain->SetBranchAddress("mup_ORIVX_CHI2", &mup_ORIVX_CHI2, &b_mup_ORIVX_CHI2);
   fChain->SetBranchAddress("mup_ORIVX_NDOF", &mup_ORIVX_NDOF, &b_mup_ORIVX_NDOF);
   fChain->SetBranchAddress("mup_ORIVX_COV_", mup_ORIVX_COV_, &b_mup_ORIVX_COV_);
   fChain->SetBranchAddress("mup_P", &mup_P, &b_mup_P);
   fChain->SetBranchAddress("mup_PT", &mup_PT, &b_mup_PT);
   fChain->SetBranchAddress("mup_PE", &mup_PE, &b_mup_PE);
   fChain->SetBranchAddress("mup_PX", &mup_PX, &b_mup_PX);
   fChain->SetBranchAddress("mup_PY", &mup_PY, &b_mup_PY);
   fChain->SetBranchAddress("mup_PZ", &mup_PZ, &b_mup_PZ);
   fChain->SetBranchAddress("mup_M", &mup_M, &b_mup_M);
   fChain->SetBranchAddress("mup_ID", &mup_ID, &b_mup_ID);
   fChain->SetBranchAddress("mup_PIDe", &mup_PIDe, &b_mup_PIDe);
   fChain->SetBranchAddress("mup_PIDmu", &mup_PIDmu, &b_mup_PIDmu);
   fChain->SetBranchAddress("mup_PIDK", &mup_PIDK, &b_mup_PIDK);
   fChain->SetBranchAddress("mup_PIDp", &mup_PIDp, &b_mup_PIDp);
   fChain->SetBranchAddress("mup_PIDd", &mup_PIDd, &b_mup_PIDd);
   fChain->SetBranchAddress("mup_ProbNNe", &mup_ProbNNe, &b_mup_ProbNNe);
   fChain->SetBranchAddress("mup_ProbNNk", &mup_ProbNNk, &b_mup_ProbNNk);
   fChain->SetBranchAddress("mup_ProbNNp", &mup_ProbNNp, &b_mup_ProbNNp);
   fChain->SetBranchAddress("mup_ProbNNpi", &mup_ProbNNpi, &b_mup_ProbNNpi);
   fChain->SetBranchAddress("mup_ProbNNmu", &mup_ProbNNmu, &b_mup_ProbNNmu);
   fChain->SetBranchAddress("mup_ProbNNd", &mup_ProbNNd, &b_mup_ProbNNd);
   fChain->SetBranchAddress("mup_ProbNNghost", &mup_ProbNNghost, &b_mup_ProbNNghost);
   fChain->SetBranchAddress("mup_hasMuon", &mup_hasMuon, &b_mup_hasMuon);
   fChain->SetBranchAddress("mup_isMuon", &mup_isMuon, &b_mup_isMuon);
   fChain->SetBranchAddress("mup_hasRich", &mup_hasRich, &b_mup_hasRich);
   fChain->SetBranchAddress("mup_UsedRichAerogel", &mup_UsedRichAerogel, &b_mup_UsedRichAerogel);
   fChain->SetBranchAddress("mup_UsedRich1Gas", &mup_UsedRich1Gas, &b_mup_UsedRich1Gas);
   fChain->SetBranchAddress("mup_UsedRich2Gas", &mup_UsedRich2Gas, &b_mup_UsedRich2Gas);
   fChain->SetBranchAddress("mup_RichAboveElThres", &mup_RichAboveElThres, &b_mup_RichAboveElThres);
   fChain->SetBranchAddress("mup_RichAboveMuThres", &mup_RichAboveMuThres, &b_mup_RichAboveMuThres);
   fChain->SetBranchAddress("mup_RichAbovePiThres", &mup_RichAbovePiThres, &b_mup_RichAbovePiThres);
   fChain->SetBranchAddress("mup_RichAboveKaThres", &mup_RichAboveKaThres, &b_mup_RichAboveKaThres);
   fChain->SetBranchAddress("mup_RichAbovePrThres", &mup_RichAbovePrThres, &b_mup_RichAbovePrThres);
   fChain->SetBranchAddress("mup_hasCalo", &mup_hasCalo, &b_mup_hasCalo);
   fChain->SetBranchAddress("mup_TRACK_Type", &mup_TRACK_Type, &b_mup_TRACK_Type);
   fChain->SetBranchAddress("mup_TRACK_Key", &mup_TRACK_Key, &b_mup_TRACK_Key);
   fChain->SetBranchAddress("mup_TRACK_CHI2NDOF", &mup_TRACK_CHI2NDOF, &b_mup_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("mup_TRACK_PCHI2", &mup_TRACK_PCHI2, &b_mup_TRACK_PCHI2);
   fChain->SetBranchAddress("mup_TRACK_MatchCHI2", &mup_TRACK_MatchCHI2, &b_mup_TRACK_MatchCHI2);
   fChain->SetBranchAddress("mup_TRACK_GhostProb", &mup_TRACK_GhostProb, &b_mup_TRACK_GhostProb);
   fChain->SetBranchAddress("mup_TRACK_CloneDist", &mup_TRACK_CloneDist, &b_mup_TRACK_CloneDist);
   fChain->SetBranchAddress("mup_TRACK_Likelihood", &mup_TRACK_Likelihood, &b_mup_TRACK_Likelihood);
   fChain->SetBranchAddress("mum_MC12TuneV2_ProbNNe", &mum_MC12TuneV2_ProbNNe, &b_mum_MC12TuneV2_ProbNNe);
   fChain->SetBranchAddress("mum_MC12TuneV2_ProbNNmu", &mum_MC12TuneV2_ProbNNmu, &b_mum_MC12TuneV2_ProbNNmu);
   fChain->SetBranchAddress("mum_MC12TuneV2_ProbNNpi", &mum_MC12TuneV2_ProbNNpi, &b_mum_MC12TuneV2_ProbNNpi);
   fChain->SetBranchAddress("mum_MC12TuneV2_ProbNNk", &mum_MC12TuneV2_ProbNNk, &b_mum_MC12TuneV2_ProbNNk);
   fChain->SetBranchAddress("mum_MC12TuneV2_ProbNNp", &mum_MC12TuneV2_ProbNNp, &b_mum_MC12TuneV2_ProbNNp);
   fChain->SetBranchAddress("mum_MC12TuneV2_ProbNNghost", &mum_MC12TuneV2_ProbNNghost, &b_mum_MC12TuneV2_ProbNNghost);
   fChain->SetBranchAddress("mum_MC12TuneV3_ProbNNe", &mum_MC12TuneV3_ProbNNe, &b_mum_MC12TuneV3_ProbNNe);
   fChain->SetBranchAddress("mum_MC12TuneV3_ProbNNmu", &mum_MC12TuneV3_ProbNNmu, &b_mum_MC12TuneV3_ProbNNmu);
   fChain->SetBranchAddress("mum_MC12TuneV3_ProbNNpi", &mum_MC12TuneV3_ProbNNpi, &b_mum_MC12TuneV3_ProbNNpi);
   fChain->SetBranchAddress("mum_MC12TuneV3_ProbNNk", &mum_MC12TuneV3_ProbNNk, &b_mum_MC12TuneV3_ProbNNk);
   fChain->SetBranchAddress("mum_MC12TuneV3_ProbNNp", &mum_MC12TuneV3_ProbNNp, &b_mum_MC12TuneV3_ProbNNp);
   fChain->SetBranchAddress("mum_MC12TuneV3_ProbNNghost", &mum_MC12TuneV3_ProbNNghost, &b_mum_MC12TuneV3_ProbNNghost);
   fChain->SetBranchAddress("mum_MC12TuneV4_ProbNNe", &mum_MC12TuneV4_ProbNNe, &b_mum_MC12TuneV4_ProbNNe);
   fChain->SetBranchAddress("mum_MC12TuneV4_ProbNNmu", &mum_MC12TuneV4_ProbNNmu, &b_mum_MC12TuneV4_ProbNNmu);
   fChain->SetBranchAddress("mum_MC12TuneV4_ProbNNpi", &mum_MC12TuneV4_ProbNNpi, &b_mum_MC12TuneV4_ProbNNpi);
   fChain->SetBranchAddress("mum_MC12TuneV4_ProbNNk", &mum_MC12TuneV4_ProbNNk, &b_mum_MC12TuneV4_ProbNNk);
   fChain->SetBranchAddress("mum_MC12TuneV4_ProbNNp", &mum_MC12TuneV4_ProbNNp, &b_mum_MC12TuneV4_ProbNNp);
   fChain->SetBranchAddress("mum_MC12TuneV4_ProbNNghost", &mum_MC12TuneV4_ProbNNghost, &b_mum_MC12TuneV4_ProbNNghost);
   fChain->SetBranchAddress("mum_MC15TuneV1_ProbNNe", &mum_MC15TuneV1_ProbNNe, &b_mum_MC15TuneV1_ProbNNe);
   fChain->SetBranchAddress("mum_MC15TuneV1_ProbNNmu", &mum_MC15TuneV1_ProbNNmu, &b_mum_MC15TuneV1_ProbNNmu);
   fChain->SetBranchAddress("mum_MC15TuneV1_ProbNNpi", &mum_MC15TuneV1_ProbNNpi, &b_mum_MC15TuneV1_ProbNNpi);
   fChain->SetBranchAddress("mum_MC15TuneV1_ProbNNk", &mum_MC15TuneV1_ProbNNk, &b_mum_MC15TuneV1_ProbNNk);
   fChain->SetBranchAddress("mum_MC15TuneV1_ProbNNp", &mum_MC15TuneV1_ProbNNp, &b_mum_MC15TuneV1_ProbNNp);
   fChain->SetBranchAddress("mum_MC15TuneV1_ProbNNghost", &mum_MC15TuneV1_ProbNNghost, &b_mum_MC15TuneV1_ProbNNghost);
   fChain->SetBranchAddress("mum_nBackTracks", &mum_nBackTracks, &b_mum_nBackTracks);
   fChain->SetBranchAddress("mum_nForWardTracks", &mum_nForWardTracks, &b_mum_nForWardTracks);
   fChain->SetBranchAddress("mum_OWNPV_X", &mum_OWNPV_X, &b_mum_OWNPV_X);
   fChain->SetBranchAddress("mum_OWNPV_Y", &mum_OWNPV_Y, &b_mum_OWNPV_Y);
   fChain->SetBranchAddress("mum_OWNPV_Z", &mum_OWNPV_Z, &b_mum_OWNPV_Z);
   fChain->SetBranchAddress("mum_OWNPV_XERR", &mum_OWNPV_XERR, &b_mum_OWNPV_XERR);
   fChain->SetBranchAddress("mum_OWNPV_YERR", &mum_OWNPV_YERR, &b_mum_OWNPV_YERR);
   fChain->SetBranchAddress("mum_OWNPV_ZERR", &mum_OWNPV_ZERR, &b_mum_OWNPV_ZERR);
   fChain->SetBranchAddress("mum_OWNPV_CHI2", &mum_OWNPV_CHI2, &b_mum_OWNPV_CHI2);
   fChain->SetBranchAddress("mum_OWNPV_NDOF", &mum_OWNPV_NDOF, &b_mum_OWNPV_NDOF);
   fChain->SetBranchAddress("mum_OWNPV_COV_", mum_OWNPV_COV_, &b_mum_OWNPV_COV_);
   fChain->SetBranchAddress("mum_IP_OWNPV", &mum_IP_OWNPV, &b_mum_IP_OWNPV);
   fChain->SetBranchAddress("mum_IPCHI2_OWNPV", &mum_IPCHI2_OWNPV, &b_mum_IPCHI2_OWNPV);
   fChain->SetBranchAddress("mum_ORIVX_X", &mum_ORIVX_X, &b_mum_ORIVX_X);
   fChain->SetBranchAddress("mum_ORIVX_Y", &mum_ORIVX_Y, &b_mum_ORIVX_Y);
   fChain->SetBranchAddress("mum_ORIVX_Z", &mum_ORIVX_Z, &b_mum_ORIVX_Z);
   fChain->SetBranchAddress("mum_ORIVX_XERR", &mum_ORIVX_XERR, &b_mum_ORIVX_XERR);
   fChain->SetBranchAddress("mum_ORIVX_YERR", &mum_ORIVX_YERR, &b_mum_ORIVX_YERR);
   fChain->SetBranchAddress("mum_ORIVX_ZERR", &mum_ORIVX_ZERR, &b_mum_ORIVX_ZERR);
   fChain->SetBranchAddress("mum_ORIVX_CHI2", &mum_ORIVX_CHI2, &b_mum_ORIVX_CHI2);
   fChain->SetBranchAddress("mum_ORIVX_NDOF", &mum_ORIVX_NDOF, &b_mum_ORIVX_NDOF);
   fChain->SetBranchAddress("mum_ORIVX_COV_", mum_ORIVX_COV_, &b_mum_ORIVX_COV_);
   fChain->SetBranchAddress("mum_P", &mum_P, &b_mum_P);
   fChain->SetBranchAddress("mum_PT", &mum_PT, &b_mum_PT);
   fChain->SetBranchAddress("mum_PE", &mum_PE, &b_mum_PE);
   fChain->SetBranchAddress("mum_PX", &mum_PX, &b_mum_PX);
   fChain->SetBranchAddress("mum_PY", &mum_PY, &b_mum_PY);
   fChain->SetBranchAddress("mum_PZ", &mum_PZ, &b_mum_PZ);
   fChain->SetBranchAddress("mum_M", &mum_M, &b_mum_M);
   fChain->SetBranchAddress("mum_ID", &mum_ID, &b_mum_ID);
   fChain->SetBranchAddress("mum_PIDe", &mum_PIDe, &b_mum_PIDe);
   fChain->SetBranchAddress("mum_PIDmu", &mum_PIDmu, &b_mum_PIDmu);
   fChain->SetBranchAddress("mum_PIDK", &mum_PIDK, &b_mum_PIDK);
   fChain->SetBranchAddress("mum_PIDp", &mum_PIDp, &b_mum_PIDp);
   fChain->SetBranchAddress("mum_PIDd", &mum_PIDd, &b_mum_PIDd);
   fChain->SetBranchAddress("mum_ProbNNe", &mum_ProbNNe, &b_mum_ProbNNe);
   fChain->SetBranchAddress("mum_ProbNNk", &mum_ProbNNk, &b_mum_ProbNNk);
   fChain->SetBranchAddress("mum_ProbNNp", &mum_ProbNNp, &b_mum_ProbNNp);
   fChain->SetBranchAddress("mum_ProbNNpi", &mum_ProbNNpi, &b_mum_ProbNNpi);
   fChain->SetBranchAddress("mum_ProbNNmu", &mum_ProbNNmu, &b_mum_ProbNNmu);
   fChain->SetBranchAddress("mum_ProbNNd", &mum_ProbNNd, &b_mum_ProbNNd);
   fChain->SetBranchAddress("mum_ProbNNghost", &mum_ProbNNghost, &b_mum_ProbNNghost);
   fChain->SetBranchAddress("mum_hasMuon", &mum_hasMuon, &b_mum_hasMuon);
   fChain->SetBranchAddress("mum_isMuon", &mum_isMuon, &b_mum_isMuon);
   fChain->SetBranchAddress("mum_hasRich", &mum_hasRich, &b_mum_hasRich);
   fChain->SetBranchAddress("mum_UsedRichAerogel", &mum_UsedRichAerogel, &b_mum_UsedRichAerogel);
   fChain->SetBranchAddress("mum_UsedRich1Gas", &mum_UsedRich1Gas, &b_mum_UsedRich1Gas);
   fChain->SetBranchAddress("mum_UsedRich2Gas", &mum_UsedRich2Gas, &b_mum_UsedRich2Gas);
   fChain->SetBranchAddress("mum_RichAboveElThres", &mum_RichAboveElThres, &b_mum_RichAboveElThres);
   fChain->SetBranchAddress("mum_RichAboveMuThres", &mum_RichAboveMuThres, &b_mum_RichAboveMuThres);
   fChain->SetBranchAddress("mum_RichAbovePiThres", &mum_RichAbovePiThres, &b_mum_RichAbovePiThres);
   fChain->SetBranchAddress("mum_RichAboveKaThres", &mum_RichAboveKaThres, &b_mum_RichAboveKaThres);
   fChain->SetBranchAddress("mum_RichAbovePrThres", &mum_RichAbovePrThres, &b_mum_RichAbovePrThres);
   fChain->SetBranchAddress("mum_hasCalo", &mum_hasCalo, &b_mum_hasCalo);
   fChain->SetBranchAddress("mum_TRACK_Type", &mum_TRACK_Type, &b_mum_TRACK_Type);
   fChain->SetBranchAddress("mum_TRACK_Key", &mum_TRACK_Key, &b_mum_TRACK_Key);
   fChain->SetBranchAddress("mum_TRACK_CHI2NDOF", &mum_TRACK_CHI2NDOF, &b_mum_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("mum_TRACK_PCHI2", &mum_TRACK_PCHI2, &b_mum_TRACK_PCHI2);
   fChain->SetBranchAddress("mum_TRACK_MatchCHI2", &mum_TRACK_MatchCHI2, &b_mum_TRACK_MatchCHI2);
   fChain->SetBranchAddress("mum_TRACK_GhostProb", &mum_TRACK_GhostProb, &b_mum_TRACK_GhostProb);
   fChain->SetBranchAddress("mum_TRACK_CloneDist", &mum_TRACK_CloneDist, &b_mum_TRACK_CloneDist);
   fChain->SetBranchAddress("mum_TRACK_Likelihood", &mum_TRACK_Likelihood, &b_mum_TRACK_Likelihood);
   fChain->SetBranchAddress("nCandidate", &nCandidate, &b_nCandidate);
   fChain->SetBranchAddress("totCandidates", &totCandidates, &b_totCandidates);
   fChain->SetBranchAddress("EventInSequence", &EventInSequence, &b_EventInSequence);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("BCID", &BCID, &b_BCID);
   fChain->SetBranchAddress("BCType", &BCType, &b_BCType);
   fChain->SetBranchAddress("OdinTCK", &OdinTCK, &b_OdinTCK);
   fChain->SetBranchAddress("L0DUTCK", &L0DUTCK, &b_L0DUTCK);
   fChain->SetBranchAddress("HLT1TCK", &HLT1TCK, &b_HLT1TCK);
   fChain->SetBranchAddress("HLT2TCK", &HLT2TCK, &b_HLT2TCK);
   fChain->SetBranchAddress("GpsTime", &GpsTime, &b_GpsTime);
   fChain->SetBranchAddress("Polarity", &Polarity, &b_Polarity);
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("PVX", PVX, &b_PVX);
   fChain->SetBranchAddress("PVY", PVY, &b_PVY);
   fChain->SetBranchAddress("PVZ", PVZ, &b_PVZ);
   fChain->SetBranchAddress("PVXERR", PVXERR, &b_PVXERR);
   fChain->SetBranchAddress("PVYERR", PVYERR, &b_PVYERR);
   fChain->SetBranchAddress("PVZERR", PVZERR, &b_PVZERR);
   fChain->SetBranchAddress("PVCHI2", PVCHI2, &b_PVCHI2);
   fChain->SetBranchAddress("PVNDOF", PVNDOF, &b_PVNDOF);
   fChain->SetBranchAddress("PVNTRACKS", PVNTRACKS, &b_PVNTRACKS);
   fChain->SetBranchAddress("nPVs", &nPVs, &b_nPVs);
   fChain->SetBranchAddress("nTracks", &nTracks, &b_nTracks);
   fChain->SetBranchAddress("nLongTracks", &nLongTracks, &b_nLongTracks);
   fChain->SetBranchAddress("nDownstreamTracks", &nDownstreamTracks, &b_nDownstreamTracks);
   fChain->SetBranchAddress("nUpstreamTracks", &nUpstreamTracks, &b_nUpstreamTracks);
   fChain->SetBranchAddress("nVeloTracks", &nVeloTracks, &b_nVeloTracks);
   fChain->SetBranchAddress("nTTracks", &nTTracks, &b_nTTracks);
   fChain->SetBranchAddress("nBackTracks", &nBackTracks, &b_nBackTracks);
   fChain->SetBranchAddress("nRich1Hits", &nRich1Hits, &b_nRich1Hits);
   fChain->SetBranchAddress("nRich2Hits", &nRich2Hits, &b_nRich2Hits);
   fChain->SetBranchAddress("nVeloClusters", &nVeloClusters, &b_nVeloClusters);
   fChain->SetBranchAddress("nITClusters", &nITClusters, &b_nITClusters);
   fChain->SetBranchAddress("nTTClusters", &nTTClusters, &b_nTTClusters);
   fChain->SetBranchAddress("nOTClusters", &nOTClusters, &b_nOTClusters);
   fChain->SetBranchAddress("nSPDHits", &nSPDHits, &b_nSPDHits);
   fChain->SetBranchAddress("nMuonCoordsS0", &nMuonCoordsS0, &b_nMuonCoordsS0);
   fChain->SetBranchAddress("nMuonCoordsS1", &nMuonCoordsS1, &b_nMuonCoordsS1);
   fChain->SetBranchAddress("nMuonCoordsS2", &nMuonCoordsS2, &b_nMuonCoordsS2);
   fChain->SetBranchAddress("nMuonCoordsS3", &nMuonCoordsS3, &b_nMuonCoordsS3);
   fChain->SetBranchAddress("nMuonCoordsS4", &nMuonCoordsS4, &b_nMuonCoordsS4);
   fChain->SetBranchAddress("nMuonTracks", &nMuonTracks, &b_nMuonTracks);
   Notify();
}

Bool_t DecayTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void DecayTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t DecayTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef DecayTree_cxx
