//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Mar  6 20:45:49 2023 by ROOT version 6.24/06
// from TTree MCDecayTree/MCDecayTree
// found on file: Tuple_MagUp.root
//////////////////////////////////////////////////////////

#ifndef MCDecayTree_h
#define MCDecayTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class MCDecayTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        psi_nPhotos;
   Double_t        psi_TRUECosTheta;
   Int_t           psi_MC_MOTHER_ID;
   Int_t           psi_MC_MOTHER_KEY;
   Int_t           psi_MC_GD_MOTHER_ID;
   Int_t           psi_MC_GD_MOTHER_KEY;
   Int_t           psi_MC_GD_GD_MOTHER_ID;
   Int_t           psi_MC_GD_GD_MOTHER_KEY;
   Double_t        psi_TRUEP_E;
   Double_t        psi_TRUEP_X;
   Double_t        psi_TRUEP_Y;
   Double_t        psi_TRUEP_Z;
   Double_t        psi_TRUEPT;
   Double_t        psi_TRUEORIGINVERTEX_X;
   Double_t        psi_TRUEORIGINVERTEX_Y;
   Double_t        psi_TRUEORIGINVERTEX_Z;
   Double_t        psi_TRUEENDVERTEX_X;
   Double_t        psi_TRUEENDVERTEX_Y;
   Double_t        psi_TRUEENDVERTEX_Z;
   Bool_t          psi_TRUEISSTABLE;
   Double_t        psi_TRUETAU;
   Bool_t          psi_OSCIL;
   Int_t           psi_Reconstructible;
   Int_t           psi_Reconstructed;
   Int_t           psi_ProtoParticles;
   Float_t         psi_PP_PX[20];   //[psi_ProtoParticles]
   Float_t         psi_PP_PY[20];   //[psi_ProtoParticles]
   Float_t         psi_PP_PZ[20];   //[psi_ProtoParticles]
   Float_t         psi_PP_Weight[20];   //[psi_ProtoParticles]
   Float_t         psi_PP_tr_pchi2[20];   //[psi_ProtoParticles]
   Float_t         psi_PP_DLLe[20];   //[psi_ProtoParticles]
   Float_t         psi_PP_DLLk[20];   //[psi_ProtoParticles]
   Float_t         psi_PP_DLLp[20];   //[psi_ProtoParticles]
   Float_t         psi_PP_DLLmu[20];   //[psi_ProtoParticles]
   Double_t        mup_nPhotos;
   Double_t        mup_TRUECosTheta;
   Int_t           mup_MC_MOTHER_ID;
   Int_t           mup_MC_MOTHER_KEY;
   Int_t           mup_MC_GD_MOTHER_ID;
   Int_t           mup_MC_GD_MOTHER_KEY;
   Int_t           mup_MC_GD_GD_MOTHER_ID;
   Int_t           mup_MC_GD_GD_MOTHER_KEY;
   Double_t        mup_TRUEP_E;
   Double_t        mup_TRUEP_X;
   Double_t        mup_TRUEP_Y;
   Double_t        mup_TRUEP_Z;
   Double_t        mup_TRUEPT;
   Double_t        mup_TRUEORIGINVERTEX_X;
   Double_t        mup_TRUEORIGINVERTEX_Y;
   Double_t        mup_TRUEORIGINVERTEX_Z;
   Double_t        mup_TRUEENDVERTEX_X;
   Double_t        mup_TRUEENDVERTEX_Y;
   Double_t        mup_TRUEENDVERTEX_Z;
   Bool_t          mup_TRUEISSTABLE;
   Double_t        mup_TRUETAU;
   Bool_t          mup_OSCIL;
   Int_t           mup_Reconstructible;
   Int_t           mup_Reconstructed;
   Int_t           mup_ProtoParticles;
   Float_t         mup_PP_PX[20];   //[mup_ProtoParticles]
   Float_t         mup_PP_PY[20];   //[mup_ProtoParticles]
   Float_t         mup_PP_PZ[20];   //[mup_ProtoParticles]
   Float_t         mup_PP_Weight[20];   //[mup_ProtoParticles]
   Float_t         mup_PP_tr_pchi2[20];   //[mup_ProtoParticles]
   Float_t         mup_PP_DLLe[20];   //[mup_ProtoParticles]
   Float_t         mup_PP_DLLk[20];   //[mup_ProtoParticles]
   Float_t         mup_PP_DLLp[20];   //[mup_ProtoParticles]
   Float_t         mup_PP_DLLmu[20];   //[mup_ProtoParticles]
   Double_t        mum_nPhotos;
   Double_t        mum_TRUECosTheta;
   Int_t           mum_MC_MOTHER_ID;
   Int_t           mum_MC_MOTHER_KEY;
   Int_t           mum_MC_GD_MOTHER_ID;
   Int_t           mum_MC_GD_MOTHER_KEY;
   Int_t           mum_MC_GD_GD_MOTHER_ID;
   Int_t           mum_MC_GD_GD_MOTHER_KEY;
   Double_t        mum_TRUEP_E;
   Double_t        mum_TRUEP_X;
   Double_t        mum_TRUEP_Y;
   Double_t        mum_TRUEP_Z;
   Double_t        mum_TRUEPT;
   Double_t        mum_TRUEORIGINVERTEX_X;
   Double_t        mum_TRUEORIGINVERTEX_Y;
   Double_t        mum_TRUEORIGINVERTEX_Z;
   Double_t        mum_TRUEENDVERTEX_X;
   Double_t        mum_TRUEENDVERTEX_Y;
   Double_t        mum_TRUEENDVERTEX_Z;
   Bool_t          mum_TRUEISSTABLE;
   Double_t        mum_TRUETAU;
   Bool_t          mum_OSCIL;
   Int_t           mum_Reconstructible;
   Int_t           mum_Reconstructed;
   Int_t           mum_ProtoParticles;
   Float_t         mum_PP_PX[20];   //[mum_ProtoParticles]
   Float_t         mum_PP_PY[20];   //[mum_ProtoParticles]
   Float_t         mum_PP_PZ[20];   //[mum_ProtoParticles]
   Float_t         mum_PP_Weight[20];   //[mum_ProtoParticles]
   Float_t         mum_PP_tr_pchi2[20];   //[mum_ProtoParticles]
   Float_t         mum_PP_DLLe[20];   //[mum_ProtoParticles]
   Float_t         mum_PP_DLLk[20];   //[mum_ProtoParticles]
   Float_t         mum_PP_DLLp[20];   //[mum_ProtoParticles]
   Float_t         mum_PP_DLLmu[20];   //[mum_ProtoParticles]
   UInt_t          nCandidate;
   ULong64_t       totCandidates;
   ULong64_t       EventInSequence;
   UInt_t          EVT_Int__I;
   Double_t        EVT_Int__Mean;
   Double_t        EVT_Int__Prob;
   Int_t           MCPVs;
   Float_t         MCPVX[50];   //[MCPVs]
   Float_t         MCPVY[50];   //[MCPVs]
   Float_t         MCPVZ[50];   //[MCPVs]
   Float_t         MCPVT[50];   //[MCPVs]

   // List of branches
   TBranch        *b_psi_nPhotos;   //!
   TBranch        *b_psi_TRUECosTheta;   //!
   TBranch        *b_psi_MC_MOTHER_ID;   //!
   TBranch        *b_psi_MC_MOTHER_KEY;   //!
   TBranch        *b_psi_MC_GD_MOTHER_ID;   //!
   TBranch        *b_psi_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_psi_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_psi_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_psi_TRUEP_E;   //!
   TBranch        *b_psi_TRUEP_X;   //!
   TBranch        *b_psi_TRUEP_Y;   //!
   TBranch        *b_psi_TRUEP_Z;   //!
   TBranch        *b_psi_TRUEPT;   //!
   TBranch        *b_psi_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_psi_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_psi_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_psi_TRUEENDVERTEX_X;   //!
   TBranch        *b_psi_TRUEENDVERTEX_Y;   //!
   TBranch        *b_psi_TRUEENDVERTEX_Z;   //!
   TBranch        *b_psi_TRUEISSTABLE;   //!
   TBranch        *b_psi_TRUETAU;   //!
   TBranch        *b_psi_OSCIL;   //!
   TBranch        *b_psi_Reconstructible;   //!
   TBranch        *b_psi_Reconstructed;   //!
   TBranch        *b_psi_ProtoParticles;   //!
   TBranch        *b_psi_PP_PX;   //!
   TBranch        *b_psi_PP_PY;   //!
   TBranch        *b_psi_PP_PZ;   //!
   TBranch        *b_psi_PP_Weight;   //!
   TBranch        *b_psi_PP_tr_pchi2;   //!
   TBranch        *b_psi_PP_DLLe;   //!
   TBranch        *b_psi_PP_DLLk;   //!
   TBranch        *b_psi_PP_DLLp;   //!
   TBranch        *b_psi_PP_DLLmu;   //!
   TBranch        *b_mup_nPhotos;   //!
   TBranch        *b_mup_TRUECosTheta;   //!
   TBranch        *b_mup_MC_MOTHER_ID;   //!
   TBranch        *b_mup_MC_MOTHER_KEY;   //!
   TBranch        *b_mup_MC_GD_MOTHER_ID;   //!
   TBranch        *b_mup_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_mup_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_mup_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_mup_TRUEP_E;   //!
   TBranch        *b_mup_TRUEP_X;   //!
   TBranch        *b_mup_TRUEP_Y;   //!
   TBranch        *b_mup_TRUEP_Z;   //!
   TBranch        *b_mup_TRUEPT;   //!
   TBranch        *b_mup_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_mup_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_mup_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_mup_TRUEENDVERTEX_X;   //!
   TBranch        *b_mup_TRUEENDVERTEX_Y;   //!
   TBranch        *b_mup_TRUEENDVERTEX_Z;   //!
   TBranch        *b_mup_TRUEISSTABLE;   //!
   TBranch        *b_mup_TRUETAU;   //!
   TBranch        *b_mup_OSCIL;   //!
   TBranch        *b_mup_Reconstructible;   //!
   TBranch        *b_mup_Reconstructed;   //!
   TBranch        *b_mup_ProtoParticles;   //!
   TBranch        *b_mup_PP_PX;   //!
   TBranch        *b_mup_PP_PY;   //!
   TBranch        *b_mup_PP_PZ;   //!
   TBranch        *b_mup_PP_Weight;   //!
   TBranch        *b_mup_PP_tr_pchi2;   //!
   TBranch        *b_mup_PP_DLLe;   //!
   TBranch        *b_mup_PP_DLLk;   //!
   TBranch        *b_mup_PP_DLLp;   //!
   TBranch        *b_mup_PP_DLLmu;   //!
   TBranch        *b_mum_nPhotos;   //!
   TBranch        *b_mum_TRUECosTheta;   //!
   TBranch        *b_mum_MC_MOTHER_ID;   //!
   TBranch        *b_mum_MC_MOTHER_KEY;   //!
   TBranch        *b_mum_MC_GD_MOTHER_ID;   //!
   TBranch        *b_mum_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_mum_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_mum_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_mum_TRUEP_E;   //!
   TBranch        *b_mum_TRUEP_X;   //!
   TBranch        *b_mum_TRUEP_Y;   //!
   TBranch        *b_mum_TRUEP_Z;   //!
   TBranch        *b_mum_TRUEPT;   //!
   TBranch        *b_mum_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_mum_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_mum_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_mum_TRUEENDVERTEX_X;   //!
   TBranch        *b_mum_TRUEENDVERTEX_Y;   //!
   TBranch        *b_mum_TRUEENDVERTEX_Z;   //!
   TBranch        *b_mum_TRUEISSTABLE;   //!
   TBranch        *b_mum_TRUETAU;   //!
   TBranch        *b_mum_OSCIL;   //!
   TBranch        *b_mum_Reconstructible;   //!
   TBranch        *b_mum_Reconstructed;   //!
   TBranch        *b_mum_ProtoParticles;   //!
   TBranch        *b_mum_PP_PX;   //!
   TBranch        *b_mum_PP_PY;   //!
   TBranch        *b_mum_PP_PZ;   //!
   TBranch        *b_mum_PP_Weight;   //!
   TBranch        *b_mum_PP_tr_pchi2;   //!
   TBranch        *b_mum_PP_DLLe;   //!
   TBranch        *b_mum_PP_DLLk;   //!
   TBranch        *b_mum_PP_DLLp;   //!
   TBranch        *b_mum_PP_DLLmu;   //!
   TBranch        *b_nCandidate;   //!
   TBranch        *b_totCandidates;   //!
   TBranch        *b_EventInSequence;   //!
   TBranch        *b_EVT_Int__I;   //!
   TBranch        *b_EVT_Int__Mean;   //!
   TBranch        *b_EVT_Int__Prob;   //!
   TBranch        *b_MCPVs;   //!
   TBranch        *b_MCPVX;   //!
   TBranch        *b_MCPVY;   //!
   TBranch        *b_MCPVZ;   //!
   TBranch        *b_MCPVT;   //!

   MCDecayTree(TTree *tree=0);
   virtual ~MCDecayTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   //virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef MCDecayTree_cxx
MCDecayTree::MCDecayTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Tuple_MagUp.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("Tuple_MagUp.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("Tuple_MagUp.root:/MCDecayTreeTuple");
      dir->GetObject("MCDecayTree",tree);

   }
   Init(tree);
}

MCDecayTree::~MCDecayTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MCDecayTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MCDecayTree::LoadTree(Long64_t entry)
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

void MCDecayTree::Init(TTree *tree)
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

   fChain->SetBranchAddress("psi_nPhotos", &psi_nPhotos, &b_psi_nPhotos);
   fChain->SetBranchAddress("psi_TRUECosTheta", &psi_TRUECosTheta, &b_psi_TRUECosTheta);
   fChain->SetBranchAddress("psi_MC_MOTHER_ID", &psi_MC_MOTHER_ID, &b_psi_MC_MOTHER_ID);
   fChain->SetBranchAddress("psi_MC_MOTHER_KEY", &psi_MC_MOTHER_KEY, &b_psi_MC_MOTHER_KEY);
   fChain->SetBranchAddress("psi_MC_GD_MOTHER_ID", &psi_MC_GD_MOTHER_ID, &b_psi_MC_GD_MOTHER_ID);
   fChain->SetBranchAddress("psi_MC_GD_MOTHER_KEY", &psi_MC_GD_MOTHER_KEY, &b_psi_MC_GD_MOTHER_KEY);
   fChain->SetBranchAddress("psi_MC_GD_GD_MOTHER_ID", &psi_MC_GD_GD_MOTHER_ID, &b_psi_MC_GD_GD_MOTHER_ID);
   fChain->SetBranchAddress("psi_MC_GD_GD_MOTHER_KEY", &psi_MC_GD_GD_MOTHER_KEY, &b_psi_MC_GD_GD_MOTHER_KEY);
   fChain->SetBranchAddress("psi_TRUEP_E", &psi_TRUEP_E, &b_psi_TRUEP_E);
   fChain->SetBranchAddress("psi_TRUEP_X", &psi_TRUEP_X, &b_psi_TRUEP_X);
   fChain->SetBranchAddress("psi_TRUEP_Y", &psi_TRUEP_Y, &b_psi_TRUEP_Y);
   fChain->SetBranchAddress("psi_TRUEP_Z", &psi_TRUEP_Z, &b_psi_TRUEP_Z);
   fChain->SetBranchAddress("psi_TRUEPT", &psi_TRUEPT, &b_psi_TRUEPT);
   fChain->SetBranchAddress("psi_TRUEORIGINVERTEX_X", &psi_TRUEORIGINVERTEX_X, &b_psi_TRUEORIGINVERTEX_X);
   fChain->SetBranchAddress("psi_TRUEORIGINVERTEX_Y", &psi_TRUEORIGINVERTEX_Y, &b_psi_TRUEORIGINVERTEX_Y);
   fChain->SetBranchAddress("psi_TRUEORIGINVERTEX_Z", &psi_TRUEORIGINVERTEX_Z, &b_psi_TRUEORIGINVERTEX_Z);
   fChain->SetBranchAddress("psi_TRUEENDVERTEX_X", &psi_TRUEENDVERTEX_X, &b_psi_TRUEENDVERTEX_X);
   fChain->SetBranchAddress("psi_TRUEENDVERTEX_Y", &psi_TRUEENDVERTEX_Y, &b_psi_TRUEENDVERTEX_Y);
   fChain->SetBranchAddress("psi_TRUEENDVERTEX_Z", &psi_TRUEENDVERTEX_Z, &b_psi_TRUEENDVERTEX_Z);
   fChain->SetBranchAddress("psi_TRUEISSTABLE", &psi_TRUEISSTABLE, &b_psi_TRUEISSTABLE);
   fChain->SetBranchAddress("psi_TRUETAU", &psi_TRUETAU, &b_psi_TRUETAU);
   fChain->SetBranchAddress("psi_OSCIL", &psi_OSCIL, &b_psi_OSCIL);
   fChain->SetBranchAddress("psi_Reconstructible", &psi_Reconstructible, &b_psi_Reconstructible);
   fChain->SetBranchAddress("psi_Reconstructed", &psi_Reconstructed, &b_psi_Reconstructed);
   fChain->SetBranchAddress("psi_ProtoParticles", &psi_ProtoParticles, &b_psi_ProtoParticles);
   fChain->SetBranchAddress("psi_PP_PX", psi_PP_PX, &b_psi_PP_PX);
   fChain->SetBranchAddress("psi_PP_PY", psi_PP_PY, &b_psi_PP_PY);
   fChain->SetBranchAddress("psi_PP_PZ", psi_PP_PZ, &b_psi_PP_PZ);
   fChain->SetBranchAddress("psi_PP_Weight", psi_PP_Weight, &b_psi_PP_Weight);
   fChain->SetBranchAddress("psi_PP_tr_pchi2", psi_PP_tr_pchi2, &b_psi_PP_tr_pchi2);
   fChain->SetBranchAddress("psi_PP_DLLe", psi_PP_DLLe, &b_psi_PP_DLLe);
   fChain->SetBranchAddress("psi_PP_DLLk", psi_PP_DLLk, &b_psi_PP_DLLk);
   fChain->SetBranchAddress("psi_PP_DLLp", psi_PP_DLLp, &b_psi_PP_DLLp);
   fChain->SetBranchAddress("psi_PP_DLLmu", psi_PP_DLLmu, &b_psi_PP_DLLmu);
   fChain->SetBranchAddress("mup_nPhotos", &mup_nPhotos, &b_mup_nPhotos);
   fChain->SetBranchAddress("mup_TRUECosTheta", &mup_TRUECosTheta, &b_mup_TRUECosTheta);
   fChain->SetBranchAddress("mup_MC_MOTHER_ID", &mup_MC_MOTHER_ID, &b_mup_MC_MOTHER_ID);
   fChain->SetBranchAddress("mup_MC_MOTHER_KEY", &mup_MC_MOTHER_KEY, &b_mup_MC_MOTHER_KEY);
   fChain->SetBranchAddress("mup_MC_GD_MOTHER_ID", &mup_MC_GD_MOTHER_ID, &b_mup_MC_GD_MOTHER_ID);
   fChain->SetBranchAddress("mup_MC_GD_MOTHER_KEY", &mup_MC_GD_MOTHER_KEY, &b_mup_MC_GD_MOTHER_KEY);
   fChain->SetBranchAddress("mup_MC_GD_GD_MOTHER_ID", &mup_MC_GD_GD_MOTHER_ID, &b_mup_MC_GD_GD_MOTHER_ID);
   fChain->SetBranchAddress("mup_MC_GD_GD_MOTHER_KEY", &mup_MC_GD_GD_MOTHER_KEY, &b_mup_MC_GD_GD_MOTHER_KEY);
   fChain->SetBranchAddress("mup_TRUEP_E", &mup_TRUEP_E, &b_mup_TRUEP_E);
   fChain->SetBranchAddress("mup_TRUEP_X", &mup_TRUEP_X, &b_mup_TRUEP_X);
   fChain->SetBranchAddress("mup_TRUEP_Y", &mup_TRUEP_Y, &b_mup_TRUEP_Y);
   fChain->SetBranchAddress("mup_TRUEP_Z", &mup_TRUEP_Z, &b_mup_TRUEP_Z);
   fChain->SetBranchAddress("mup_TRUEPT", &mup_TRUEPT, &b_mup_TRUEPT);
   fChain->SetBranchAddress("mup_TRUEORIGINVERTEX_X", &mup_TRUEORIGINVERTEX_X, &b_mup_TRUEORIGINVERTEX_X);
   fChain->SetBranchAddress("mup_TRUEORIGINVERTEX_Y", &mup_TRUEORIGINVERTEX_Y, &b_mup_TRUEORIGINVERTEX_Y);
   fChain->SetBranchAddress("mup_TRUEORIGINVERTEX_Z", &mup_TRUEORIGINVERTEX_Z, &b_mup_TRUEORIGINVERTEX_Z);
   fChain->SetBranchAddress("mup_TRUEENDVERTEX_X", &mup_TRUEENDVERTEX_X, &b_mup_TRUEENDVERTEX_X);
   fChain->SetBranchAddress("mup_TRUEENDVERTEX_Y", &mup_TRUEENDVERTEX_Y, &b_mup_TRUEENDVERTEX_Y);
   fChain->SetBranchAddress("mup_TRUEENDVERTEX_Z", &mup_TRUEENDVERTEX_Z, &b_mup_TRUEENDVERTEX_Z);
   fChain->SetBranchAddress("mup_TRUEISSTABLE", &mup_TRUEISSTABLE, &b_mup_TRUEISSTABLE);
   fChain->SetBranchAddress("mup_TRUETAU", &mup_TRUETAU, &b_mup_TRUETAU);
   fChain->SetBranchAddress("mup_OSCIL", &mup_OSCIL, &b_mup_OSCIL);
   fChain->SetBranchAddress("mup_Reconstructible", &mup_Reconstructible, &b_mup_Reconstructible);
   fChain->SetBranchAddress("mup_Reconstructed", &mup_Reconstructed, &b_mup_Reconstructed);
   fChain->SetBranchAddress("mup_ProtoParticles", &mup_ProtoParticles, &b_mup_ProtoParticles);
   fChain->SetBranchAddress("mup_PP_PX", mup_PP_PX, &b_mup_PP_PX);
   fChain->SetBranchAddress("mup_PP_PY", mup_PP_PY, &b_mup_PP_PY);
   fChain->SetBranchAddress("mup_PP_PZ", mup_PP_PZ, &b_mup_PP_PZ);
   fChain->SetBranchAddress("mup_PP_Weight", mup_PP_Weight, &b_mup_PP_Weight);
   fChain->SetBranchAddress("mup_PP_tr_pchi2", mup_PP_tr_pchi2, &b_mup_PP_tr_pchi2);
   fChain->SetBranchAddress("mup_PP_DLLe", mup_PP_DLLe, &b_mup_PP_DLLe);
   fChain->SetBranchAddress("mup_PP_DLLk", mup_PP_DLLk, &b_mup_PP_DLLk);
   fChain->SetBranchAddress("mup_PP_DLLp", mup_PP_DLLp, &b_mup_PP_DLLp);
   fChain->SetBranchAddress("mup_PP_DLLmu", mup_PP_DLLmu, &b_mup_PP_DLLmu);
   fChain->SetBranchAddress("mum_nPhotos", &mum_nPhotos, &b_mum_nPhotos);
   fChain->SetBranchAddress("mum_TRUECosTheta", &mum_TRUECosTheta, &b_mum_TRUECosTheta);
   fChain->SetBranchAddress("mum_MC_MOTHER_ID", &mum_MC_MOTHER_ID, &b_mum_MC_MOTHER_ID);
   fChain->SetBranchAddress("mum_MC_MOTHER_KEY", &mum_MC_MOTHER_KEY, &b_mum_MC_MOTHER_KEY);
   fChain->SetBranchAddress("mum_MC_GD_MOTHER_ID", &mum_MC_GD_MOTHER_ID, &b_mum_MC_GD_MOTHER_ID);
   fChain->SetBranchAddress("mum_MC_GD_MOTHER_KEY", &mum_MC_GD_MOTHER_KEY, &b_mum_MC_GD_MOTHER_KEY);
   fChain->SetBranchAddress("mum_MC_GD_GD_MOTHER_ID", &mum_MC_GD_GD_MOTHER_ID, &b_mum_MC_GD_GD_MOTHER_ID);
   fChain->SetBranchAddress("mum_MC_GD_GD_MOTHER_KEY", &mum_MC_GD_GD_MOTHER_KEY, &b_mum_MC_GD_GD_MOTHER_KEY);
   fChain->SetBranchAddress("mum_TRUEP_E", &mum_TRUEP_E, &b_mum_TRUEP_E);
   fChain->SetBranchAddress("mum_TRUEP_X", &mum_TRUEP_X, &b_mum_TRUEP_X);
   fChain->SetBranchAddress("mum_TRUEP_Y", &mum_TRUEP_Y, &b_mum_TRUEP_Y);
   fChain->SetBranchAddress("mum_TRUEP_Z", &mum_TRUEP_Z, &b_mum_TRUEP_Z);
   fChain->SetBranchAddress("mum_TRUEPT", &mum_TRUEPT, &b_mum_TRUEPT);
   fChain->SetBranchAddress("mum_TRUEORIGINVERTEX_X", &mum_TRUEORIGINVERTEX_X, &b_mum_TRUEORIGINVERTEX_X);
   fChain->SetBranchAddress("mum_TRUEORIGINVERTEX_Y", &mum_TRUEORIGINVERTEX_Y, &b_mum_TRUEORIGINVERTEX_Y);
   fChain->SetBranchAddress("mum_TRUEORIGINVERTEX_Z", &mum_TRUEORIGINVERTEX_Z, &b_mum_TRUEORIGINVERTEX_Z);
   fChain->SetBranchAddress("mum_TRUEENDVERTEX_X", &mum_TRUEENDVERTEX_X, &b_mum_TRUEENDVERTEX_X);
   fChain->SetBranchAddress("mum_TRUEENDVERTEX_Y", &mum_TRUEENDVERTEX_Y, &b_mum_TRUEENDVERTEX_Y);
   fChain->SetBranchAddress("mum_TRUEENDVERTEX_Z", &mum_TRUEENDVERTEX_Z, &b_mum_TRUEENDVERTEX_Z);
   fChain->SetBranchAddress("mum_TRUEISSTABLE", &mum_TRUEISSTABLE, &b_mum_TRUEISSTABLE);
   fChain->SetBranchAddress("mum_TRUETAU", &mum_TRUETAU, &b_mum_TRUETAU);
   fChain->SetBranchAddress("mum_OSCIL", &mum_OSCIL, &b_mum_OSCIL);
   fChain->SetBranchAddress("mum_Reconstructible", &mum_Reconstructible, &b_mum_Reconstructible);
   fChain->SetBranchAddress("mum_Reconstructed", &mum_Reconstructed, &b_mum_Reconstructed);
   fChain->SetBranchAddress("mum_ProtoParticles", &mum_ProtoParticles, &b_mum_ProtoParticles);
   fChain->SetBranchAddress("mum_PP_PX", mum_PP_PX, &b_mum_PP_PX);
   fChain->SetBranchAddress("mum_PP_PY", mum_PP_PY, &b_mum_PP_PY);
   fChain->SetBranchAddress("mum_PP_PZ", mum_PP_PZ, &b_mum_PP_PZ);
   fChain->SetBranchAddress("mum_PP_Weight", mum_PP_Weight, &b_mum_PP_Weight);
   fChain->SetBranchAddress("mum_PP_tr_pchi2", mum_PP_tr_pchi2, &b_mum_PP_tr_pchi2);
   fChain->SetBranchAddress("mum_PP_DLLe", mum_PP_DLLe, &b_mum_PP_DLLe);
   fChain->SetBranchAddress("mum_PP_DLLk", mum_PP_DLLk, &b_mum_PP_DLLk);
   fChain->SetBranchAddress("mum_PP_DLLp", mum_PP_DLLp, &b_mum_PP_DLLp);
   fChain->SetBranchAddress("mum_PP_DLLmu", mum_PP_DLLmu, &b_mum_PP_DLLmu);
   fChain->SetBranchAddress("nCandidate", &nCandidate, &b_nCandidate);
   fChain->SetBranchAddress("totCandidates", &totCandidates, &b_totCandidates);
   fChain->SetBranchAddress("EventInSequence", &EventInSequence, &b_EventInSequence);
   fChain->SetBranchAddress("EVT_Int__I", &EVT_Int__I, &b_EVT_Int__I);
   fChain->SetBranchAddress("EVT_Int__Mean", &EVT_Int__Mean, &b_EVT_Int__Mean);
   fChain->SetBranchAddress("EVT_Int__Prob", &EVT_Int__Prob, &b_EVT_Int__Prob);
   fChain->SetBranchAddress("MCPVs", &MCPVs, &b_MCPVs);
   fChain->SetBranchAddress("MCPVX", MCPVX, &b_MCPVX);
   fChain->SetBranchAddress("MCPVY", MCPVY, &b_MCPVY);
   fChain->SetBranchAddress("MCPVZ", MCPVZ, &b_MCPVZ);
   fChain->SetBranchAddress("MCPVT", MCPVT, &b_MCPVT);
   Notify();
}

Bool_t MCDecayTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MCDecayTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MCDecayTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef MCDecayTree_cxx
