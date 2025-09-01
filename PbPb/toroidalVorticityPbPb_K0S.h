//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Feb 13 11:49:23 2025 by ROOT version 6.32.08
// from TTree DecayTree/DecayTree
// found on file: pbpb_0.root
//////////////////////////////////////////////////////////

#ifndef toroidalVorticityPbPb_K0S_h
#define toroidalVorticityPbPb_K0S_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
#include "TVector2.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TProfile.h"

// Header file for the classes stored in the TTree if any.

int iFile;
class toroidalVorticityPbPb_K0S {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   ULong64_t       totCandidates;
   UInt_t          nCandidate;
   UShort_t        BUNCHCROSSING_ID;
   UChar_t         BUNCHCROSSING_TYPE;
   ULong64_t       EVENTNUMBER;
   ULong64_t       GPSTIME;
   Bool_t          Hlt1BeamGasDecision;
   Bool_t          Hlt1GECPassthroughDecision;
   Bool_t          Hlt1HeavyIonPbPbCentralDecision;
   Bool_t          Hlt1HeavyIonPbPbHadronicDecision;
   Bool_t          Hlt1HeavyIonPbPbMBOneTrackDecision;
   Bool_t          Hlt1HeavyIonPbPbMicroBiasDecision;
   Bool_t          Hlt1HeavyIonPbPbPeripheralDecision;
   Bool_t          Hlt1HeavyIonPbPbUPCMBDecision;
   Bool_t          Hlt1HeavyIonPbSMOGHadronicDecision;
   Bool_t          Hlt1HeavyIonPbSMOGMBOneTrackDecision;
   Bool_t          Hlt1HeavyIonPbSMOGMicroBiasDecision;
   Bool_t          Hlt1ODIN1kHzLumiDecision;
   Bool_t          Hlt1ODINLumiDecision;
   Bool_t          Hlt1RICH1AlignmentDecision;
   Bool_t          Hlt1RICH2AlignmentDecision;
   Bool_t          Hlt1VeloMicroBiasDecision;
   UInt_t          Hlt1_TCK;
   UInt_t          ODINTCK;
   Int_t           indx;
   Float_t         PVX[10000];   //[indx]
   Float_t         PVY[10000];   //[indx]
   Float_t         PVZ[10000];   //[indx]
   UInt_t          RUNNUMBER;
   Int_t           eCalTot;
   Int_t           hCalTot;
   Int_t           nBackTracks;
   Int_t           nDownTracks;
   Int_t           nEcalClusters;
   Int_t           nFTClusters;
   Int_t           nLongTracks;
   Int_t           nMuonTracks;
   Int_t           nPVs;
   Int_t           nRich1Hits;
   Int_t           nRich2Hits;
   Int_t           nUpTracks;
   Int_t           nVPClusters;
   Int_t           nVeloTracks;
   Int_t           Ks_ID;
   Int_t           Ks_KEY;
   Int_t           Ks_CHARGE;
   Float_t         Ks_ETA;
   Float_t         Ks_PHI;
   Double_t        Ks_MASS;
   Double_t        Ks_FOURMOMENTUME;
   Double_t        Ks_FOURMOMENTUMX;
   Double_t        Ks_FOURMOMENTUMY;
   Double_t        Ks_FOURMOMENTUMZ;
   Float_t         Ks_PT;
   Float_t         Ks_PX;
   Float_t         Ks_PY;
   Float_t         Ks_PZ;
   Double_t        Ks_CHI2;
   Double_t        Ks_CHI2DOF;
   Float_t         Ks_B_PV_Z;
   Float_t         Ks_B_PV_X;
   Float_t         Ks_B_PV_Y;
   Float_t         Ks_BPVIP;
   Float_t         Ks_BPVIPCHI2;
   Double_t        Ks_DOCA;
   Double_t        Ks_DOCACHI2;
   Float_t         Ks_SDOCA;
   Float_t         Ks_SDOCACHI2;
   Float_t         Ks_END_VX;
   Float_t         Ks_END_VY;
   Float_t         Ks_END_VZ;
   Float_t         Ks_BPVFDCHI2;
   Float_t         Ks_BPVLTIME;
   Float_t         Ks_BPVFD;
   Float_t         Ks_BPVDIRA;
   Int_t           pi_plus_ID;
   Int_t           pi_plus_KEY;
   Int_t           pi_plus_CHARGE;
   Float_t         pi_plus_ETA;
   Float_t         pi_plus_PHI;
   Double_t        pi_plus_MASS;
   Double_t        pi_plus_FOURMOMENTUME;
   Double_t        pi_plus_FOURMOMENTUMX;
   Double_t        pi_plus_FOURMOMENTUMY;
   Double_t        pi_plus_FOURMOMENTUMZ;
   Float_t         pi_plus_PT;
   Float_t         pi_plus_PX;
   Float_t         pi_plus_PY;
   Float_t         pi_plus_PZ;
   Double_t        pi_plus_CHI2;
   Double_t        pi_plus_CHI2DOF;
   Float_t         pi_plus_B_PV_Z;
   Float_t         pi_plus_B_PV_X;
   Float_t         pi_plus_B_PV_Y;
   Float_t         pi_plus_BPVIP;
   Float_t         pi_plus_BPVIPCHI2;
   Float_t         pi_plus_PIDE;
   Float_t         pi_plus_PIDK;
   Float_t         pi_plus_PIDMU;
   Float_t         pi_plus_PIDP;
   Float_t         pi_plus_PIDPI;
   Float_t         pi_plus_PROBNNE;
   Float_t         pi_plus_PROBNNK;
   Float_t         pi_plus_PROBNNMU;
   Float_t         pi_plus_PROBNNP;
   Float_t         pi_plus_PROBNNPI;
   Float_t         pi_plus_PROBNNGHOST;
   Float_t         pi_plus_PROBNND;
   Double_t        pi_plus_GHOSTPROB;
   Bool_t          pi_plus_ISMUON;
   Float_t         pi_plus_IS_NOT_H;
   Float_t         pi_plus_IS_PHOTON;
   Int_t           pi_plus_TRACK_NVPHITS;
   Int_t           pi_plus_TRACK_NFTHITS;
   Int_t           pi_minus_ID;
   Int_t           pi_minus_KEY;
   Int_t           pi_minus_CHARGE;
   Float_t         pi_minus_ETA;
   Float_t         pi_minus_PHI;
   Double_t        pi_minus_MASS;
   Double_t        pi_minus_FOURMOMENTUME;
   Double_t        pi_minus_FOURMOMENTUMX;
   Double_t        pi_minus_FOURMOMENTUMY;
   Double_t        pi_minus_FOURMOMENTUMZ;
   Float_t         pi_minus_PT;
   Float_t         pi_minus_PX;
   Float_t         pi_minus_PY;
   Float_t         pi_minus_PZ;
   Double_t        pi_minus_CHI2;
   Double_t        pi_minus_CHI2DOF;
   Float_t         pi_minus_B_PV_Z;
   Float_t         pi_minus_B_PV_X;
   Float_t         pi_minus_B_PV_Y;
   Float_t         pi_minus_BPVIP;
   Float_t         pi_minus_BPVIPCHI2;
   Float_t         pi_minus_PIDE;
   Float_t         pi_minus_PIDK;
   Float_t         pi_minus_PIDMU;
   Float_t         pi_minus_PIDP;
   Float_t         pi_minus_PIDPI;
   Float_t         pi_minus_PROBNNE;
   Float_t         pi_minus_PROBNNK;
   Float_t         pi_minus_PROBNNMU;
   Float_t         pi_minus_PROBNNP;
   Float_t         pi_minus_PROBNNPI;
   Float_t         pi_minus_PROBNNGHOST;
   Float_t         pi_minus_PROBNND;
   Double_t        pi_minus_GHOSTPROB;
   Bool_t          pi_minus_ISMUON;
   Float_t         pi_minus_IS_NOT_H;
   Float_t         pi_minus_IS_PHOTON;
   Int_t           pi_minus_TRACK_NVPHITS;
   Int_t           pi_minus_TRACK_NFTHITS;

   // List of branches
   TBranch        *b_totCandidates;   //!
   TBranch        *b_nCandidate;   //!
   TBranch        *b_BUNCHCROSSING_ID;   //!
   TBranch        *b_BUNCHCROSSING_TYPE;   //!
   TBranch        *b_EVENTNUMBER;   //!
   TBranch        *b_GPSTIME;   //!
   TBranch        *b_Hlt1BeamGasDecision;   //!
   TBranch        *b_Hlt1GECPassthroughDecision;   //!
   TBranch        *b_Hlt1HeavyIonPbPbCentralDecision;   //!
   TBranch        *b_Hlt1HeavyIonPbPbHadronicDecision;   //!
   TBranch        *b_Hlt1HeavyIonPbPbMBOneTrackDecision;   //!
   TBranch        *b_Hlt1HeavyIonPbPbMicroBiasDecision;   //!
   TBranch        *b_Hlt1HeavyIonPbPbPeripheralDecision;   //!
   TBranch        *b_Hlt1HeavyIonPbPbUPCMBDecision;   //!
   TBranch        *b_Hlt1HeavyIonPbSMOGHadronicDecision;   //!
   TBranch        *b_Hlt1HeavyIonPbSMOGMBOneTrackDecision;   //!
   TBranch        *b_Hlt1HeavyIonPbSMOGMicroBiasDecision;   //!
   TBranch        *b_Hlt1ODIN1kHzLumiDecision;   //!
   TBranch        *b_Hlt1ODINLumiDecision;   //!
   TBranch        *b_Hlt1RICH1AlignmentDecision;   //!
   TBranch        *b_Hlt1RICH2AlignmentDecision;   //!
   TBranch        *b_Hlt1VeloMicroBiasDecision;   //!
   TBranch        *b_Hlt1_TCK;   //!
   TBranch        *b_ODINTCK;   //!
   TBranch        *b_indx;   //!
   TBranch        *b_PVX;   //!
   TBranch        *b_PVY;   //!
   TBranch        *b_PVZ;   //!
   TBranch        *b_RUNNUMBER;   //!
   TBranch        *b_eCalTot;   //!
   TBranch        *b_hCalTot;   //!
   TBranch        *b_nBackTracks;   //!
   TBranch        *b_nDownTracks;   //!
   TBranch        *b_nEcalClusters;   //!
   TBranch        *b_nFTClusters;   //!
   TBranch        *b_nLongTracks;   //!
   TBranch        *b_nMuonTracks;   //!
   TBranch        *b_nPVs;   //!
   TBranch        *b_nRich1Hits;   //!
   TBranch        *b_nRich2Hits;   //!
   TBranch        *b_nUpTracks;   //!
   TBranch        *b_nVPClusters;   //!
   TBranch        *b_nVeloTracks;   //!
   TBranch        *b_Ks_ID;   //!
   TBranch        *b_Ks_KEY;   //!
   TBranch        *b_Ks_CHARGE;   //!
   TBranch        *b_Ks_ETA;   //!
   TBranch        *b_Ks_PHI;   //!
   TBranch        *b_Ks_MASS;   //!
   TBranch        *b_Ks_FOURMOMENTUME;   //!
   TBranch        *b_Ks_FOURMOMENTUMX;   //!
   TBranch        *b_Ks_FOURMOMENTUMY;   //!
   TBranch        *b_Ks_FOURMOMENTUMZ;   //!
   TBranch        *b_Ks_PT;   //!
   TBranch        *b_Ks_PX;   //!
   TBranch        *b_Ks_PY;   //!
   TBranch        *b_Ks_PZ;   //!
   TBranch        *b_Ks_CHI2;   //!
   TBranch        *b_Ks_CHI2DOF;   //!
   TBranch        *b_Ks_B_PV_Z;   //!
   TBranch        *b_Ks_B_PV_X;   //!
   TBranch        *b_Ks_B_PV_Y;   //!
   TBranch        *b_Ks_BPVIP;   //!
   TBranch        *b_Ks_BPVIPCHI2;   //!
   TBranch        *b_Ks_DOCA;   //!
   TBranch        *b_Ks_DOCACHI2;   //!
   TBranch        *b_Ks_SDOCA;   //!
   TBranch        *b_Ks_SDOCACHI2;   //!
   TBranch        *b_Ks_END_VX;   //!
   TBranch        *b_Ks_END_VY;   //!
   TBranch        *b_Ks_END_VZ;   //!
   TBranch        *b_Ks_BPVFDCHI2;   //!
   TBranch        *b_Ks_BPVLTIME;   //!
   TBranch        *b_Ks_BPVFD;   //!
   TBranch        *b_Ks_BPVDIRA;   //!
   TBranch        *b_pi_plus_ID;   //!
   TBranch        *b_pi_plus_KEY;   //!
   TBranch        *b_pi_plus_CHARGE;   //!
   TBranch        *b_pi_plus_ETA;   //!
   TBranch        *b_pi_plus_PHI;   //!
   TBranch        *b_pi_plus_MASS;   //!
   TBranch        *b_pi_plus_FOURMOMENTUME;   //!
   TBranch        *b_pi_plus_FOURMOMENTUMX;   //!
   TBranch        *b_pi_plus_FOURMOMENTUMY;   //!
   TBranch        *b_pi_plus_FOURMOMENTUMZ;   //!
   TBranch        *b_pi_plus_PT;   //!
   TBranch        *b_pi_plus_PX;   //!
   TBranch        *b_pi_plus_PY;   //!
   TBranch        *b_pi_plus_PZ;   //!
   TBranch        *b_pi_plus_CHI2;   //!
   TBranch        *b_pi_plus_CHI2DOF;   //!
   TBranch        *b_pi_plus_B_PV_Z;   //!
   TBranch        *b_pi_plus_B_PV_X;   //!
   TBranch        *b_pi_plus_B_PV_Y;   //!
   TBranch        *b_pi_plus_BPVIP;   //!
   TBranch        *b_pi_plus_BPVIPCHI2;   //!
   TBranch        *b_pi_plus_PIDE;   //!
   TBranch        *b_pi_plus_PIDK;   //!
   TBranch        *b_pi_plus_PIDMU;   //!
   TBranch        *b_pi_plus_PIDP;   //!
   TBranch        *b_pi_plus_PIDPI;   //!
   TBranch        *b_pi_plus_PROBNNE;   //!
   TBranch        *b_pi_plus_PROBNNK;   //!
   TBranch        *b_pi_plus_PROBNNMU;   //!
   TBranch        *b_pi_plus_PROBNNP;   //!
   TBranch        *b_pi_plus_PROBNNPI;   //!
   TBranch        *b_pi_plus_PROBNNGHOST;   //!
   TBranch        *b_pi_plus_PROBNND;   //!
   TBranch        *b_pi_plus_GHOSTPROB;   //!
   TBranch        *b_pi_plus_ISMUON;   //!
   TBranch        *b_pi_plus_IS_NOT_H;   //!
   TBranch        *b_pi_plus_IS_PHOTON;   //!
   TBranch        *b_pi_plus_TRACK_NVPHITS;   //!
   TBranch        *b_pi_plus_TRACK_NFTHITS;   //!
   TBranch        *b_pi_minus_ID;   //!
   TBranch        *b_pi_minus_KEY;   //!
   TBranch        *b_pi_minus_CHARGE;   //!
   TBranch        *b_pi_minus_ETA;   //!
   TBranch        *b_pi_minus_PHI;   //!
   TBranch        *b_pi_minus_MASS;   //!
   TBranch        *b_pi_minus_FOURMOMENTUME;   //!
   TBranch        *b_pi_minus_FOURMOMENTUMX;   //!
   TBranch        *b_pi_minus_FOURMOMENTUMY;   //!
   TBranch        *b_pi_minus_FOURMOMENTUMZ;   //!
   TBranch        *b_pi_minus_PT;   //!
   TBranch        *b_pi_minus_PX;   //!
   TBranch        *b_pi_minus_PY;   //!
   TBranch        *b_pi_minus_PZ;   //!
   TBranch        *b_pi_minus_CHI2;   //!
   TBranch        *b_pi_minus_CHI2DOF;   //!
   TBranch        *b_pi_minus_B_PV_Z;   //!
   TBranch        *b_pi_minus_B_PV_X;   //!
   TBranch        *b_pi_minus_B_PV_Y;   //!
   TBranch        *b_pi_minus_BPVIP;   //!
   TBranch        *b_pi_minus_BPVIPCHI2;   //!
   TBranch        *b_pi_minus_PIDE;   //!
   TBranch        *b_pi_minus_PIDK;   //!
   TBranch        *b_pi_minus_PIDMU;   //!
   TBranch        *b_pi_minus_PIDP;   //!
   TBranch        *b_pi_minus_PIDPI;   //!
   TBranch        *b_pi_minus_PROBNNE;   //!
   TBranch        *b_pi_minus_PROBNNK;   //!
   TBranch        *b_pi_minus_PROBNNMU;   //!
   TBranch        *b_pi_minus_PROBNNP;   //!
   TBranch        *b_pi_minus_PROBNNPI;   //!
   TBranch        *b_pi_minus_PROBNNGHOST;   //!
   TBranch        *b_pi_minus_PROBNND;   //!
   TBranch        *b_pi_minus_GHOSTPROB;   //!
   TBranch        *b_pi_minus_ISMUON;   //!
   TBranch        *b_pi_minus_IS_NOT_H;   //!
   TBranch        *b_pi_minus_IS_PHOTON;   //!
   TBranch        *b_pi_minus_TRACK_NVPHITS;   //!
   TBranch        *b_pi_minus_TRACK_NFTHITS;   //!

   //toroidalVorticityPbPb_K0S(TTree *tree=0);
   toroidalVorticityPbPb_K0S(TTree *tree, int iiFile);
   virtual ~toroidalVorticityPbPb_K0S();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual bool     Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef toroidalVorticityPbPb_K0S_cxx

toroidalVorticityPbPb_K0S::toroidalVorticityPbPb_K0S(TTree *tree, int iiFile) : fChain(0) 
{
   iFile=iiFile;
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(Form("/Volumes/Mike_disc/Maria/PbPb/pbpb_%d.root",iFile));
      if (!f || !f->IsOpen()) {
         f = new TFile(Form("/Volumes/Mike_disc/Maria/PbPb/pbpb_%d.root",iFile));
      }
      TDirectory * dir = (TDirectory*)f->Get(Form("/Volumes/Mike_disc/Maria/PbPb/pbpb_%d.root:/KsTuple",iFile));
      dir->GetObject("DecayTree",tree);

   }
   Init(tree);
/*
      if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(Form("pbpb_%d.root",iFile));
      if (!f || !f->IsOpen()) {
         f = new TFile(Form("pbpb_%d.root",iFile));
      }
      TDirectory * dir = (TDirectory*)f->Get(Form("pbpb_%d.root:/L0Tuple",iFile));
      dir->GetObject("DecayTree",tree);

   }
   Init(tree);*/
}

/*
toroidalVorticityPbPb_K0S::toroidalVorticityPbPb_K0S(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("pbpb_0.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("pbpb_0.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("pbpb_0.root:/KsTuple");
      dir->GetObject("DecayTree",tree);

   }
   Init(tree);
}
*/


toroidalVorticityPbPb_K0S::~toroidalVorticityPbPb_K0S()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t toroidalVorticityPbPb_K0S::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t toroidalVorticityPbPb_K0S::LoadTree(Long64_t entry)
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

void toroidalVorticityPbPb_K0S::Init(TTree *tree)
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

   fChain->SetBranchAddress("totCandidates", &totCandidates, &b_totCandidates);
   fChain->SetBranchAddress("nCandidate", &nCandidate, &b_nCandidate);
   fChain->SetBranchAddress("BUNCHCROSSING_ID", &BUNCHCROSSING_ID, &b_BUNCHCROSSING_ID);
   fChain->SetBranchAddress("BUNCHCROSSING_TYPE", &BUNCHCROSSING_TYPE, &b_BUNCHCROSSING_TYPE);
   fChain->SetBranchAddress("EVENTNUMBER", &EVENTNUMBER, &b_EVENTNUMBER);
   fChain->SetBranchAddress("GPSTIME", &GPSTIME, &b_GPSTIME);
   fChain->SetBranchAddress("Hlt1BeamGasDecision", &Hlt1BeamGasDecision, &b_Hlt1BeamGasDecision);
   fChain->SetBranchAddress("Hlt1GECPassthroughDecision", &Hlt1GECPassthroughDecision, &b_Hlt1GECPassthroughDecision);
   fChain->SetBranchAddress("Hlt1HeavyIonPbPbCentralDecision", &Hlt1HeavyIonPbPbCentralDecision, &b_Hlt1HeavyIonPbPbCentralDecision);
   fChain->SetBranchAddress("Hlt1HeavyIonPbPbHadronicDecision", &Hlt1HeavyIonPbPbHadronicDecision, &b_Hlt1HeavyIonPbPbHadronicDecision);
   fChain->SetBranchAddress("Hlt1HeavyIonPbPbMBOneTrackDecision", &Hlt1HeavyIonPbPbMBOneTrackDecision, &b_Hlt1HeavyIonPbPbMBOneTrackDecision);
   fChain->SetBranchAddress("Hlt1HeavyIonPbPbMicroBiasDecision", &Hlt1HeavyIonPbPbMicroBiasDecision, &b_Hlt1HeavyIonPbPbMicroBiasDecision);
   fChain->SetBranchAddress("Hlt1HeavyIonPbPbPeripheralDecision", &Hlt1HeavyIonPbPbPeripheralDecision, &b_Hlt1HeavyIonPbPbPeripheralDecision);
   fChain->SetBranchAddress("Hlt1HeavyIonPbPbUPCMBDecision", &Hlt1HeavyIonPbPbUPCMBDecision, &b_Hlt1HeavyIonPbPbUPCMBDecision);
   fChain->SetBranchAddress("Hlt1HeavyIonPbSMOGHadronicDecision", &Hlt1HeavyIonPbSMOGHadronicDecision, &b_Hlt1HeavyIonPbSMOGHadronicDecision);
   fChain->SetBranchAddress("Hlt1HeavyIonPbSMOGMBOneTrackDecision", &Hlt1HeavyIonPbSMOGMBOneTrackDecision, &b_Hlt1HeavyIonPbSMOGMBOneTrackDecision);
   fChain->SetBranchAddress("Hlt1HeavyIonPbSMOGMicroBiasDecision", &Hlt1HeavyIonPbSMOGMicroBiasDecision, &b_Hlt1HeavyIonPbSMOGMicroBiasDecision);
   fChain->SetBranchAddress("Hlt1ODIN1kHzLumiDecision", &Hlt1ODIN1kHzLumiDecision, &b_Hlt1ODIN1kHzLumiDecision);
   fChain->SetBranchAddress("Hlt1ODINLumiDecision", &Hlt1ODINLumiDecision, &b_Hlt1ODINLumiDecision);
   fChain->SetBranchAddress("Hlt1RICH1AlignmentDecision", &Hlt1RICH1AlignmentDecision, &b_Hlt1RICH1AlignmentDecision);
   fChain->SetBranchAddress("Hlt1RICH2AlignmentDecision", &Hlt1RICH2AlignmentDecision, &b_Hlt1RICH2AlignmentDecision);
   fChain->SetBranchAddress("Hlt1VeloMicroBiasDecision", &Hlt1VeloMicroBiasDecision, &b_Hlt1VeloMicroBiasDecision);
   fChain->SetBranchAddress("Hlt1_TCK", &Hlt1_TCK, &b_Hlt1_TCK);
   fChain->SetBranchAddress("ODINTCK", &ODINTCK, &b_ODINTCK);
   fChain->SetBranchAddress("indx", &indx, &b_indx);
   fChain->SetBranchAddress("PVX", PVX, &b_PVX);
   fChain->SetBranchAddress("PVY", PVY, &b_PVY);
   fChain->SetBranchAddress("PVZ", PVZ, &b_PVZ);
   fChain->SetBranchAddress("RUNNUMBER", &RUNNUMBER, &b_RUNNUMBER);
   fChain->SetBranchAddress("eCalTot", &eCalTot, &b_eCalTot);
   fChain->SetBranchAddress("hCalTot", &hCalTot, &b_hCalTot);
   fChain->SetBranchAddress("nBackTracks", &nBackTracks, &b_nBackTracks);
   fChain->SetBranchAddress("nDownTracks", &nDownTracks, &b_nDownTracks);
   fChain->SetBranchAddress("nEcalClusters", &nEcalClusters, &b_nEcalClusters);
   fChain->SetBranchAddress("nFTClusters", &nFTClusters, &b_nFTClusters);
   fChain->SetBranchAddress("nLongTracks", &nLongTracks, &b_nLongTracks);
   fChain->SetBranchAddress("nMuonTracks", &nMuonTracks, &b_nMuonTracks);
   fChain->SetBranchAddress("nPVs", &nPVs, &b_nPVs);
   fChain->SetBranchAddress("nRich1Hits", &nRich1Hits, &b_nRich1Hits);
   fChain->SetBranchAddress("nRich2Hits", &nRich2Hits, &b_nRich2Hits);
   fChain->SetBranchAddress("nUpTracks", &nUpTracks, &b_nUpTracks);
   fChain->SetBranchAddress("nVPClusters", &nVPClusters, &b_nVPClusters);
   fChain->SetBranchAddress("nVeloTracks", &nVeloTracks, &b_nVeloTracks);
   fChain->SetBranchAddress("Ks_ID", &Ks_ID, &b_Ks_ID);
   fChain->SetBranchAddress("Ks_KEY", &Ks_KEY, &b_Ks_KEY);
   fChain->SetBranchAddress("Ks_CHARGE", &Ks_CHARGE, &b_Ks_CHARGE);
   fChain->SetBranchAddress("Ks_ETA", &Ks_ETA, &b_Ks_ETA);
   fChain->SetBranchAddress("Ks_PHI", &Ks_PHI, &b_Ks_PHI);
   fChain->SetBranchAddress("Ks_MASS", &Ks_MASS, &b_Ks_MASS);
   fChain->SetBranchAddress("Ks_FOURMOMENTUME", &Ks_FOURMOMENTUME, &b_Ks_FOURMOMENTUME);
   fChain->SetBranchAddress("Ks_FOURMOMENTUMX", &Ks_FOURMOMENTUMX, &b_Ks_FOURMOMENTUMX);
   fChain->SetBranchAddress("Ks_FOURMOMENTUMY", &Ks_FOURMOMENTUMY, &b_Ks_FOURMOMENTUMY);
   fChain->SetBranchAddress("Ks_FOURMOMENTUMZ", &Ks_FOURMOMENTUMZ, &b_Ks_FOURMOMENTUMZ);
   fChain->SetBranchAddress("Ks_PT", &Ks_PT, &b_Ks_PT);
   fChain->SetBranchAddress("Ks_PX", &Ks_PX, &b_Ks_PX);
   fChain->SetBranchAddress("Ks_PY", &Ks_PY, &b_Ks_PY);
   fChain->SetBranchAddress("Ks_PZ", &Ks_PZ, &b_Ks_PZ);
   fChain->SetBranchAddress("Ks_CHI2", &Ks_CHI2, &b_Ks_CHI2);
   fChain->SetBranchAddress("Ks_CHI2DOF", &Ks_CHI2DOF, &b_Ks_CHI2DOF);
   fChain->SetBranchAddress("Ks_B_PV_Z", &Ks_B_PV_Z, &b_Ks_B_PV_Z);
   fChain->SetBranchAddress("Ks_B_PV_X", &Ks_B_PV_X, &b_Ks_B_PV_X);
   fChain->SetBranchAddress("Ks_B_PV_Y", &Ks_B_PV_Y, &b_Ks_B_PV_Y);
   fChain->SetBranchAddress("Ks_BPVIP", &Ks_BPVIP, &b_Ks_BPVIP);
   fChain->SetBranchAddress("Ks_BPVIPCHI2", &Ks_BPVIPCHI2, &b_Ks_BPVIPCHI2);
   fChain->SetBranchAddress("Ks_DOCA", &Ks_DOCA, &b_Ks_DOCA);
   fChain->SetBranchAddress("Ks_DOCACHI2", &Ks_DOCACHI2, &b_Ks_DOCACHI2);
   fChain->SetBranchAddress("Ks_SDOCA", &Ks_SDOCA, &b_Ks_SDOCA);
   fChain->SetBranchAddress("Ks_SDOCACHI2", &Ks_SDOCACHI2, &b_Ks_SDOCACHI2);
   fChain->SetBranchAddress("Ks_END_VX", &Ks_END_VX, &b_Ks_END_VX);
   fChain->SetBranchAddress("Ks_END_VY", &Ks_END_VY, &b_Ks_END_VY);
   fChain->SetBranchAddress("Ks_END_VZ", &Ks_END_VZ, &b_Ks_END_VZ);
   fChain->SetBranchAddress("Ks_BPVFDCHI2", &Ks_BPVFDCHI2, &b_Ks_BPVFDCHI2);
   fChain->SetBranchAddress("Ks_BPVLTIME", &Ks_BPVLTIME, &b_Ks_BPVLTIME);
   fChain->SetBranchAddress("Ks_BPVFD", &Ks_BPVFD, &b_Ks_BPVFD);
   fChain->SetBranchAddress("Ks_BPVDIRA", &Ks_BPVDIRA, &b_Ks_BPVDIRA);
   fChain->SetBranchAddress("pi_plus_ID", &pi_plus_ID, &b_pi_plus_ID);
   fChain->SetBranchAddress("pi_plus_KEY", &pi_plus_KEY, &b_pi_plus_KEY);
   fChain->SetBranchAddress("pi_plus_CHARGE", &pi_plus_CHARGE, &b_pi_plus_CHARGE);
   fChain->SetBranchAddress("pi_plus_ETA", &pi_plus_ETA, &b_pi_plus_ETA);
   fChain->SetBranchAddress("pi_plus_PHI", &pi_plus_PHI, &b_pi_plus_PHI);
   fChain->SetBranchAddress("pi_plus_MASS", &pi_plus_MASS, &b_pi_plus_MASS);
   fChain->SetBranchAddress("pi_plus_FOURMOMENTUME", &pi_plus_FOURMOMENTUME, &b_pi_plus_FOURMOMENTUME);
   fChain->SetBranchAddress("pi_plus_FOURMOMENTUMX", &pi_plus_FOURMOMENTUMX, &b_pi_plus_FOURMOMENTUMX);
   fChain->SetBranchAddress("pi_plus_FOURMOMENTUMY", &pi_plus_FOURMOMENTUMY, &b_pi_plus_FOURMOMENTUMY);
   fChain->SetBranchAddress("pi_plus_FOURMOMENTUMZ", &pi_plus_FOURMOMENTUMZ, &b_pi_plus_FOURMOMENTUMZ);
   fChain->SetBranchAddress("pi_plus_PT", &pi_plus_PT, &b_pi_plus_PT);
   fChain->SetBranchAddress("pi_plus_PX", &pi_plus_PX, &b_pi_plus_PX);
   fChain->SetBranchAddress("pi_plus_PY", &pi_plus_PY, &b_pi_plus_PY);
   fChain->SetBranchAddress("pi_plus_PZ", &pi_plus_PZ, &b_pi_plus_PZ);
   fChain->SetBranchAddress("pi_plus_CHI2", &pi_plus_CHI2, &b_pi_plus_CHI2);
   fChain->SetBranchAddress("pi_plus_CHI2DOF", &pi_plus_CHI2DOF, &b_pi_plus_CHI2DOF);
   fChain->SetBranchAddress("pi_plus_B_PV_Z", &pi_plus_B_PV_Z, &b_pi_plus_B_PV_Z);
   fChain->SetBranchAddress("pi_plus_B_PV_X", &pi_plus_B_PV_X, &b_pi_plus_B_PV_X);
   fChain->SetBranchAddress("pi_plus_B_PV_Y", &pi_plus_B_PV_Y, &b_pi_plus_B_PV_Y);
   fChain->SetBranchAddress("pi_plus_BPVIP", &pi_plus_BPVIP, &b_pi_plus_BPVIP);
   fChain->SetBranchAddress("pi_plus_BPVIPCHI2", &pi_plus_BPVIPCHI2, &b_pi_plus_BPVIPCHI2);
   fChain->SetBranchAddress("pi_plus_PIDE", &pi_plus_PIDE, &b_pi_plus_PIDE);
   fChain->SetBranchAddress("pi_plus_PIDK", &pi_plus_PIDK, &b_pi_plus_PIDK);
   fChain->SetBranchAddress("pi_plus_PIDMU", &pi_plus_PIDMU, &b_pi_plus_PIDMU);
   fChain->SetBranchAddress("pi_plus_PIDP", &pi_plus_PIDP, &b_pi_plus_PIDP);
   fChain->SetBranchAddress("pi_plus_PIDPI", &pi_plus_PIDPI, &b_pi_plus_PIDPI);
   fChain->SetBranchAddress("pi_plus_PROBNNE", &pi_plus_PROBNNE, &b_pi_plus_PROBNNE);
   fChain->SetBranchAddress("pi_plus_PROBNNK", &pi_plus_PROBNNK, &b_pi_plus_PROBNNK);
   fChain->SetBranchAddress("pi_plus_PROBNNMU", &pi_plus_PROBNNMU, &b_pi_plus_PROBNNMU);
   fChain->SetBranchAddress("pi_plus_PROBNNP", &pi_plus_PROBNNP, &b_pi_plus_PROBNNP);
   fChain->SetBranchAddress("pi_plus_PROBNNPI", &pi_plus_PROBNNPI, &b_pi_plus_PROBNNPI);
   fChain->SetBranchAddress("pi_plus_PROBNNGHOST", &pi_plus_PROBNNGHOST, &b_pi_plus_PROBNNGHOST);
   fChain->SetBranchAddress("pi_plus_PROBNND", &pi_plus_PROBNND, &b_pi_plus_PROBNND);
   fChain->SetBranchAddress("pi_plus_GHOSTPROB", &pi_plus_GHOSTPROB, &b_pi_plus_GHOSTPROB);
   fChain->SetBranchAddress("pi_plus_ISMUON", &pi_plus_ISMUON, &b_pi_plus_ISMUON);
   fChain->SetBranchAddress("pi_plus_IS_NOT_H", &pi_plus_IS_NOT_H, &b_pi_plus_IS_NOT_H);
   fChain->SetBranchAddress("pi_plus_IS_PHOTON", &pi_plus_IS_PHOTON, &b_pi_plus_IS_PHOTON);
   fChain->SetBranchAddress("pi_plus_TRACK_NVPHITS", &pi_plus_TRACK_NVPHITS, &b_pi_plus_TRACK_NVPHITS);
   fChain->SetBranchAddress("pi_plus_TRACK_NFTHITS", &pi_plus_TRACK_NFTHITS, &b_pi_plus_TRACK_NFTHITS);
   fChain->SetBranchAddress("pi_minus_ID", &pi_minus_ID, &b_pi_minus_ID);
   fChain->SetBranchAddress("pi_minus_KEY", &pi_minus_KEY, &b_pi_minus_KEY);
   fChain->SetBranchAddress("pi_minus_CHARGE", &pi_minus_CHARGE, &b_pi_minus_CHARGE);
   fChain->SetBranchAddress("pi_minus_ETA", &pi_minus_ETA, &b_pi_minus_ETA);
   fChain->SetBranchAddress("pi_minus_PHI", &pi_minus_PHI, &b_pi_minus_PHI);
   fChain->SetBranchAddress("pi_minus_MASS", &pi_minus_MASS, &b_pi_minus_MASS);
   fChain->SetBranchAddress("pi_minus_FOURMOMENTUME", &pi_minus_FOURMOMENTUME, &b_pi_minus_FOURMOMENTUME);
   fChain->SetBranchAddress("pi_minus_FOURMOMENTUMX", &pi_minus_FOURMOMENTUMX, &b_pi_minus_FOURMOMENTUMX);
   fChain->SetBranchAddress("pi_minus_FOURMOMENTUMY", &pi_minus_FOURMOMENTUMY, &b_pi_minus_FOURMOMENTUMY);
   fChain->SetBranchAddress("pi_minus_FOURMOMENTUMZ", &pi_minus_FOURMOMENTUMZ, &b_pi_minus_FOURMOMENTUMZ);
   fChain->SetBranchAddress("pi_minus_PT", &pi_minus_PT, &b_pi_minus_PT);
   fChain->SetBranchAddress("pi_minus_PX", &pi_minus_PX, &b_pi_minus_PX);
   fChain->SetBranchAddress("pi_minus_PY", &pi_minus_PY, &b_pi_minus_PY);
   fChain->SetBranchAddress("pi_minus_PZ", &pi_minus_PZ, &b_pi_minus_PZ);
   fChain->SetBranchAddress("pi_minus_CHI2", &pi_minus_CHI2, &b_pi_minus_CHI2);
   fChain->SetBranchAddress("pi_minus_CHI2DOF", &pi_minus_CHI2DOF, &b_pi_minus_CHI2DOF);
   fChain->SetBranchAddress("pi_minus_B_PV_Z", &pi_minus_B_PV_Z, &b_pi_minus_B_PV_Z);
   fChain->SetBranchAddress("pi_minus_B_PV_X", &pi_minus_B_PV_X, &b_pi_minus_B_PV_X);
   fChain->SetBranchAddress("pi_minus_B_PV_Y", &pi_minus_B_PV_Y, &b_pi_minus_B_PV_Y);
   fChain->SetBranchAddress("pi_minus_BPVIP", &pi_minus_BPVIP, &b_pi_minus_BPVIP);
   fChain->SetBranchAddress("pi_minus_BPVIPCHI2", &pi_minus_BPVIPCHI2, &b_pi_minus_BPVIPCHI2);
   fChain->SetBranchAddress("pi_minus_PIDE", &pi_minus_PIDE, &b_pi_minus_PIDE);
   fChain->SetBranchAddress("pi_minus_PIDK", &pi_minus_PIDK, &b_pi_minus_PIDK);
   fChain->SetBranchAddress("pi_minus_PIDMU", &pi_minus_PIDMU, &b_pi_minus_PIDMU);
   fChain->SetBranchAddress("pi_minus_PIDP", &pi_minus_PIDP, &b_pi_minus_PIDP);
   fChain->SetBranchAddress("pi_minus_PIDPI", &pi_minus_PIDPI, &b_pi_minus_PIDPI);
   fChain->SetBranchAddress("pi_minus_PROBNNE", &pi_minus_PROBNNE, &b_pi_minus_PROBNNE);
   fChain->SetBranchAddress("pi_minus_PROBNNK", &pi_minus_PROBNNK, &b_pi_minus_PROBNNK);
   fChain->SetBranchAddress("pi_minus_PROBNNMU", &pi_minus_PROBNNMU, &b_pi_minus_PROBNNMU);
   fChain->SetBranchAddress("pi_minus_PROBNNP", &pi_minus_PROBNNP, &b_pi_minus_PROBNNP);
   fChain->SetBranchAddress("pi_minus_PROBNNPI", &pi_minus_PROBNNPI, &b_pi_minus_PROBNNPI);
   fChain->SetBranchAddress("pi_minus_PROBNNGHOST", &pi_minus_PROBNNGHOST, &b_pi_minus_PROBNNGHOST);
   fChain->SetBranchAddress("pi_minus_PROBNND", &pi_minus_PROBNND, &b_pi_minus_PROBNND);
   fChain->SetBranchAddress("pi_minus_GHOSTPROB", &pi_minus_GHOSTPROB, &b_pi_minus_GHOSTPROB);
   fChain->SetBranchAddress("pi_minus_ISMUON", &pi_minus_ISMUON, &b_pi_minus_ISMUON);
   fChain->SetBranchAddress("pi_minus_IS_NOT_H", &pi_minus_IS_NOT_H, &b_pi_minus_IS_NOT_H);
   fChain->SetBranchAddress("pi_minus_IS_PHOTON", &pi_minus_IS_PHOTON, &b_pi_minus_IS_PHOTON);
   fChain->SetBranchAddress("pi_minus_TRACK_NVPHITS", &pi_minus_TRACK_NVPHITS, &b_pi_minus_TRACK_NVPHITS);
   fChain->SetBranchAddress("pi_minus_TRACK_NFTHITS", &pi_minus_TRACK_NFTHITS, &b_pi_minus_TRACK_NFTHITS);
   Notify();
}

bool toroidalVorticityPbPb_K0S::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return true;
}

void toroidalVorticityPbPb_K0S::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t toroidalVorticityPbPb_K0S::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef toroidalVorticityPbPb_K0S_cxx
