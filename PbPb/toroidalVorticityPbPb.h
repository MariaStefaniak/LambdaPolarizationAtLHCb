// ===========================================================
// toroidalVorticityPbPb.C
//
// Author: Maria Stefaniak (2025)
//
// Description:
// This class processes Lambda candidates in Pb–Pb collisions
// recorded by LHCb in 2024. It is based on the DecayTree TTree
// structure from Analysis Productions. The code applies 
// polarization and quality cuts for toroidal vorticity studies.
//
// ROOT version used: 6.32.08
// ===========================================================

#ifndef toroidalVorticityPbPb_h
#define toroidalVorticityPbPb_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
#include "TVector2.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TProfile.h"

// Global flags (file index and MC/data type)
int iFile;
int MC;

class toroidalVorticityPbPb {
public:
   TTree          *fChain;   //! pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //! current Tree number in a TChain

   // Fixed-size dimension arrays (if any) go here

   // === Leaf declarations (branches of TTree) ===
   ULong64_t       totCandidates;     // total number of Lambda candidates
   UInt_t          nCandidate;        // number of candidates in current event
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
   Int_t           L0_ID;
   Int_t           L0_KEY;
   Int_t           L0_CHARGE;
   Float_t         L0_ETA;
   Float_t         L0_PHI;
   Double_t        L0_MASS;
   Double_t        L0_FOURMOMENTUME;
   Double_t        L0_FOURMOMENTUMX;
   Double_t        L0_FOURMOMENTUMY;
   Double_t        L0_FOURMOMENTUMZ;
   Float_t         L0_PT;
   Float_t         L0_PX;
   Float_t         L0_PY;
   Float_t         L0_PZ;
   Double_t        L0_CHI2;
   Double_t        L0_CHI2DOF;
   Float_t         L0_B_PV_Z;
   Float_t         L0_B_PV_X;
   Float_t         L0_B_PV_Y;
   Float_t         L0_BPVIP;
   Float_t         L0_BPVIPCHI2;
   Double_t        L0_DOCA;
   Double_t        L0_DOCACHI2;
   Float_t         L0_SDOCA;
   Float_t         L0_SDOCACHI2;
   Float_t         L0_END_VX;
   Float_t         L0_END_VY;
   Float_t         L0_END_VZ;
   Float_t         L0_BPVFDCHI2;
   Float_t         L0_BPVLTIME;
   Float_t         L0_BPVFD;
   Float_t         L0_BPVDIRA;
   Int_t           p_ID;
   Int_t           p_KEY;
   Int_t           p_CHARGE;
   Float_t         p_ETA;
   Float_t         p_PHI;
   Double_t        p_MASS;
   Double_t        p_FOURMOMENTUME;
   Double_t        p_FOURMOMENTUMX;
   Double_t        p_FOURMOMENTUMY;
   Double_t        p_FOURMOMENTUMZ;
   Float_t         p_PT;
   Float_t         p_PX;
   Float_t         p_PY;
   Float_t         p_PZ;
   Double_t        p_CHI2;
   Double_t        p_CHI2DOF;
   Float_t         p_B_PV_Z;
   Float_t         p_B_PV_X;
   Float_t         p_B_PV_Y;
   Float_t         p_BPVIP;
   Float_t         p_BPVIPCHI2;
   Float_t         p_PIDE;
   Float_t         p_PIDK;
   Float_t         p_PIDMU;
   Float_t         p_PIDP;
   Float_t         p_PIDPI;
   Float_t         p_PROBNNE;
   Float_t         p_PROBNNK;
   Float_t         p_PROBNNMU;
   Float_t         p_PROBNNP;
   Float_t         p_PROBNNPI;
   Float_t         p_PROBNNGHOST;
   Float_t         p_PROBNND;
   Double_t        p_GHOSTPROB;
   Bool_t          p_ISMUON;
   Float_t         p_IS_NOT_H;
   Float_t         p_IS_PHOTON;
   Int_t           p_TRACK_NVPHITS;
   Int_t           p_TRACK_NFTHITS;
   Int_t           pi_ID;
   Int_t           pi_KEY;
   Int_t           pi_CHARGE;
   Float_t         pi_ETA;
   Float_t         pi_PHI;
   Double_t        pi_MASS;
   Double_t        pi_FOURMOMENTUME;
   Double_t        pi_FOURMOMENTUMX;
   Double_t        pi_FOURMOMENTUMY;
   Double_t        pi_FOURMOMENTUMZ;
   Float_t         pi_PT;
   Float_t         pi_PX;
   Float_t         pi_PY;
   Float_t         pi_PZ;
   Double_t        pi_CHI2;
   Double_t        pi_CHI2DOF;
   Float_t         pi_B_PV_Z;
   Float_t         pi_B_PV_X;
   Float_t         pi_B_PV_Y;
   Float_t         pi_BPVIP;
   Float_t         pi_BPVIPCHI2;
   Float_t         pi_PIDE;
   Float_t         pi_PIDK;
   Float_t         pi_PIDMU;
   Float_t         pi_PIDP;
   Float_t         pi_PIDPI;
   Float_t         pi_PROBNNE;
   Float_t         pi_PROBNNK;
   Float_t         pi_PROBNNMU;
   Float_t         pi_PROBNNP;
   Float_t         pi_PROBNNPI;
   Float_t         pi_PROBNNGHOST;
   Float_t         pi_PROBNND;
   Double_t        pi_GHOSTPROB;
   Bool_t          pi_ISMUON;
   Float_t         pi_IS_NOT_H;
   Float_t         pi_IS_PHOTON;
   Int_t           pi_TRACK_NVPHITS;
   Int_t           pi_TRACK_NFTHITS;

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
   TBranch        *b_L0_ID;   //!
   TBranch        *b_L0_KEY;   //!
   TBranch        *b_L0_CHARGE;   //!
   TBranch        *b_L0_ETA;   //!
   TBranch        *b_L0_PHI;   //!
   TBranch        *b_L0_MASS;   //!
   TBranch        *b_L0_FOURMOMENTUME;   //!
   TBranch        *b_L0_FOURMOMENTUMX;   //!
   TBranch        *b_L0_FOURMOMENTUMY;   //!
   TBranch        *b_L0_FOURMOMENTUMZ;   //!
   TBranch        *b_L0_PT;   //!
   TBranch        *b_L0_PX;   //!
   TBranch        *b_L0_PY;   //!
   TBranch        *b_L0_PZ;   //!
   TBranch        *b_L0_CHI2;   //!
   TBranch        *b_L0_CHI2DOF;   //!
   TBranch        *b_L0_B_PV_Z;   //!
   TBranch        *b_L0_B_PV_X;   //!
   TBranch        *b_L0_B_PV_Y;   //!
   TBranch        *b_L0_BPVIP;   //!
   TBranch        *b_L0_BPVIPCHI2;   //!
   TBranch        *b_L0_DOCA;   //!
   TBranch        *b_L0_DOCACHI2;   //!
   TBranch        *b_L0_SDOCA;   //!
   TBranch        *b_L0_SDOCACHI2;   //!
   TBranch        *b_L0_END_VX;   //!
   TBranch        *b_L0_END_VY;   //!
   TBranch        *b_L0_END_VZ;   //!
   TBranch        *b_L0_BPVFDCHI2;   //!
   TBranch        *b_L0_BPVLTIME;   //!
   TBranch        *b_L0_BPVFD;   //!
   TBranch        *b_L0_BPVDIRA;   //!
   TBranch        *b_p_ID;   //!
   TBranch        *b_p_KEY;   //!
   TBranch        *b_p_CHARGE;   //!
   TBranch        *b_p_ETA;   //!
   TBranch        *b_p_PHI;   //!
   TBranch        *b_p_MASS;   //!
   TBranch        *b_p_FOURMOMENTUME;   //!
   TBranch        *b_p_FOURMOMENTUMX;   //!
   TBranch        *b_p_FOURMOMENTUMY;   //!
   TBranch        *b_p_FOURMOMENTUMZ;   //!
   TBranch        *b_p_PT;   //!
   TBranch        *b_p_PX;   //!
   TBranch        *b_p_PY;   //!
   TBranch        *b_p_PZ;   //!
   TBranch        *b_p_CHI2;   //!
   TBranch        *b_p_CHI2DOF;   //!
   TBranch        *b_p_B_PV_Z;   //!
   TBranch        *b_p_B_PV_X;   //!
   TBranch        *b_p_B_PV_Y;   //!
   TBranch        *b_p_BPVIP;   //!
   TBranch        *b_p_BPVIPCHI2;   //!
   TBranch        *b_p_PIDE;   //!
   TBranch        *b_p_PIDK;   //!
   TBranch        *b_p_PIDMU;   //!
   TBranch        *b_p_PIDP;   //!
   TBranch        *b_p_PIDPI;   //!
   TBranch        *b_p_PROBNNE;   //!
   TBranch        *b_p_PROBNNK;   //!
   TBranch        *b_p_PROBNNMU;   //!
   TBranch        *b_p_PROBNNP;   //!
   TBranch        *b_p_PROBNNPI;   //!
   TBranch        *b_p_PROBNNGHOST;   //!
   TBranch        *b_p_PROBNND;   //!
   TBranch        *b_p_GHOSTPROB;   //!
   TBranch        *b_p_ISMUON;   //!
   TBranch        *b_p_IS_NOT_H;   //!
   TBranch        *b_p_IS_PHOTON;   //!
   TBranch        *b_p_TRACK_NVPHITS;   //!
   TBranch        *b_p_TRACK_NFTHITS;   //!
   TBranch        *b_pi_ID;   //!
   TBranch        *b_pi_KEY;   //!
   TBranch        *b_pi_CHARGE;   //!
   TBranch        *b_pi_ETA;   //!
   TBranch        *b_pi_PHI;   //!
   TBranch        *b_pi_MASS;   //!
   TBranch        *b_pi_FOURMOMENTUME;   //!
   TBranch        *b_pi_FOURMOMENTUMX;   //!
   TBranch        *b_pi_FOURMOMENTUMY;   //!
   TBranch        *b_pi_FOURMOMENTUMZ;   //!
   TBranch        *b_pi_PT;   //!
   TBranch        *b_pi_PX;   //!
   TBranch        *b_pi_PY;   //!
   TBranch        *b_pi_PZ;   //!
   TBranch        *b_pi_CHI2;   //!
   TBranch        *b_pi_CHI2DOF;   //!
   TBranch        *b_pi_B_PV_Z;   //!
   TBranch        *b_pi_B_PV_X;   //!
   TBranch        *b_pi_B_PV_Y;   //!
   TBranch        *b_pi_BPVIP;   //!
   TBranch        *b_pi_BPVIPCHI2;   //!
   TBranch        *b_pi_PIDE;   //!
   TBranch        *b_pi_PIDK;   //!
   TBranch        *b_pi_PIDMU;   //!
   TBranch        *b_pi_PIDP;   //!
   TBranch        *b_pi_PIDPI;   //!
   TBranch        *b_pi_PROBNNE;   //!
   TBranch        *b_pi_PROBNNK;   //!
   TBranch        *b_pi_PROBNNMU;   //!
   TBranch        *b_pi_PROBNNP;   //!
   TBranch        *b_pi_PROBNNPI;   //!
   TBranch        *b_pi_PROBNNGHOST;   //!
   TBranch        *b_pi_PROBNND;   //!
   TBranch        *b_pi_GHOSTPROB;   //!
   TBranch        *b_pi_ISMUON;   //!
   TBranch        *b_pi_IS_NOT_H;   //!
   TBranch        *b_pi_IS_PHOTON;   //!
   TBranch        *b_pi_TRACK_NVPHITS;   //!
   TBranch        *b_pi_TRACK_NFTHITS;   //!

   // === Constructor and destructor ===
   toroidalVorticityPbPb(TTree *tree, int iiFile, int iMC);
   virtual ~toroidalVorticityPbPb();

   // === Core I/O methods ===
   virtual Int_t    Cut(Long64_t entry);                     // selection cut (returns 1 if accepted)
   virtual Int_t    GetEntry(Long64_t entry);                // loads an entry into memory
   virtual Long64_t LoadTree(Long64_t entry);                // prepares environment to read an entry
   virtual void     Init(TTree *tree);                       // binds TTree branches
   virtual void     Loop();                                  // user-defined analysis loop
   virtual bool     Notify();                                // called when file changes (e.g., in chain)
   virtual void     Show(Long64_t entry = -1);               // print event info
   virtual bool     CheckSister(int nrentries, int jent,
                                float pi_pt, float pro_pt,
                                double lambda_quality, int runnr);  // selects best candidate per event
};

#endif

#ifdef toroidalVorticityPbPb_cxx

// === Constructor ===
// Loads input ROOT file and retrieves TTree depending on real/MC data
toroidalVorticityPbPb::toroidalVorticityPbPb(TTree *tree, int iiFile, int iMC) : fChain(0)
{
   iFile = iiFile;
   MC = iMC;

   if (MC == 0) {  // === Real data path ===
      if (tree == 0) {
         TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(Form("/Volumes/Mike_disc/Maria/PbPb/pbpb_%d.root", iFile));
         if (!f || !f->IsOpen()) {
            f = new TFile(Form("/Volumes/Mike_disc/Maria/PbPb/pbpb_%d.root", iFile));
         }
         TDirectory *dir = (TDirectory*)f->Get(Form("/Volumes/Mike_disc/Maria/PbPb/pbpb_%d.root:/L0Tuple", iFile));
         dir->GetObject("DecayTree", tree);  // Tree should be named "DecayTree"
      }
   } else if (MC == 1) {  // === MC path ===
      if (tree == 0) {
         TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(Form("/Volumes/Mike_disc/Maria/MC/PbPb2024/PbPb2024/MCPbPb_%d.root", iFile));
         if (!f || !f->IsOpen()) {
            f = new TFile(Form("/Volumes/Mike_disc/Maria/MC/PbPb2024/PbPb2024/MCPbPb_%d.root", iFile));
         }
         TDirectory *dir = (TDirectory*)f->Get(Form("/Volumes/Mike_disc/Maria/MC/PbPb2024/PbPb2024/MCPbPb_%d.root:/L0Tuple", iFile));
         dir->GetObject("DecayTree", tree);
      }
   }

   // Initialize branch pointers and bind leaves
   Init(tree);
}

// === Destructor ===
toroidalVorticityPbPb::~toroidalVorticityPbPb()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

// === GetEntry ===
// Reads one entry from the tree
Int_t toroidalVorticityPbPb::GetEntry(Long64_t entry)
{
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}

// === LoadTree ===
// Prepares internal state for reading entry
Long64_t toroidalVorticityPbPb::LoadTree(Long64_t entry)
{
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();  // signal a new file in chain (if any)
   }
   return centry;
}

// === Init ===
// Binds leaf variables to class members and sets up branches
void toroidalVorticityPbPb::Init(TTree *tree)
{
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);  // use MakeClass-style branch access

   // Example of setting branch addresses (expand with your actual leaf list)

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
   fChain->SetBranchAddress("L0_ID", &L0_ID, &b_L0_ID);
   fChain->SetBranchAddress("L0_KEY", &L0_KEY, &b_L0_KEY);
   fChain->SetBranchAddress("L0_CHARGE", &L0_CHARGE, &b_L0_CHARGE);
   fChain->SetBranchAddress("L0_ETA", &L0_ETA, &b_L0_ETA);
   fChain->SetBranchAddress("L0_PHI", &L0_PHI, &b_L0_PHI);
   fChain->SetBranchAddress("L0_MASS", &L0_MASS, &b_L0_MASS);
   fChain->SetBranchAddress("L0_FOURMOMENTUME", &L0_FOURMOMENTUME, &b_L0_FOURMOMENTUME);
   fChain->SetBranchAddress("L0_FOURMOMENTUMX", &L0_FOURMOMENTUMX, &b_L0_FOURMOMENTUMX);
   fChain->SetBranchAddress("L0_FOURMOMENTUMY", &L0_FOURMOMENTUMY, &b_L0_FOURMOMENTUMY);
   fChain->SetBranchAddress("L0_FOURMOMENTUMZ", &L0_FOURMOMENTUMZ, &b_L0_FOURMOMENTUMZ);
   fChain->SetBranchAddress("L0_PT", &L0_PT, &b_L0_PT);
   fChain->SetBranchAddress("L0_PX", &L0_PX, &b_L0_PX);
   fChain->SetBranchAddress("L0_PY", &L0_PY, &b_L0_PY);
   fChain->SetBranchAddress("L0_PZ", &L0_PZ, &b_L0_PZ);
   fChain->SetBranchAddress("L0_CHI2", &L0_CHI2, &b_L0_CHI2);
   fChain->SetBranchAddress("L0_CHI2DOF", &L0_CHI2DOF, &b_L0_CHI2DOF);
   fChain->SetBranchAddress("L0_B_PV_Z", &L0_B_PV_Z, &b_L0_B_PV_Z);
   fChain->SetBranchAddress("L0_B_PV_X", &L0_B_PV_X, &b_L0_B_PV_X);
   fChain->SetBranchAddress("L0_B_PV_Y", &L0_B_PV_Y, &b_L0_B_PV_Y);
   fChain->SetBranchAddress("L0_BPVIP", &L0_BPVIP, &b_L0_BPVIP);
   fChain->SetBranchAddress("L0_BPVIPCHI2", &L0_BPVIPCHI2, &b_L0_BPVIPCHI2);
   fChain->SetBranchAddress("L0_DOCA", &L0_DOCA, &b_L0_DOCA);
   fChain->SetBranchAddress("L0_DOCACHI2", &L0_DOCACHI2, &b_L0_DOCACHI2);
   fChain->SetBranchAddress("L0_SDOCA", &L0_SDOCA, &b_L0_SDOCA);
   fChain->SetBranchAddress("L0_SDOCACHI2", &L0_SDOCACHI2, &b_L0_SDOCACHI2);
   fChain->SetBranchAddress("L0_END_VX", &L0_END_VX, &b_L0_END_VX);
   fChain->SetBranchAddress("L0_END_VY", &L0_END_VY, &b_L0_END_VY);
   fChain->SetBranchAddress("L0_END_VZ", &L0_END_VZ, &b_L0_END_VZ);
   fChain->SetBranchAddress("L0_BPVFDCHI2", &L0_BPVFDCHI2, &b_L0_BPVFDCHI2);
   fChain->SetBranchAddress("L0_BPVLTIME", &L0_BPVLTIME, &b_L0_BPVLTIME);
   fChain->SetBranchAddress("L0_BPVFD", &L0_BPVFD, &b_L0_BPVFD);
   fChain->SetBranchAddress("L0_BPVDIRA", &L0_BPVDIRA, &b_L0_BPVDIRA);
   fChain->SetBranchAddress("p_ID", &p_ID, &b_p_ID);
   fChain->SetBranchAddress("p_KEY", &p_KEY, &b_p_KEY);
   fChain->SetBranchAddress("p_CHARGE", &p_CHARGE, &b_p_CHARGE);
   fChain->SetBranchAddress("p_ETA", &p_ETA, &b_p_ETA);
   fChain->SetBranchAddress("p_PHI", &p_PHI, &b_p_PHI);
   fChain->SetBranchAddress("p_MASS", &p_MASS, &b_p_MASS);
   fChain->SetBranchAddress("p_FOURMOMENTUME", &p_FOURMOMENTUME, &b_p_FOURMOMENTUME);
   fChain->SetBranchAddress("p_FOURMOMENTUMX", &p_FOURMOMENTUMX, &b_p_FOURMOMENTUMX);
   fChain->SetBranchAddress("p_FOURMOMENTUMY", &p_FOURMOMENTUMY, &b_p_FOURMOMENTUMY);
   fChain->SetBranchAddress("p_FOURMOMENTUMZ", &p_FOURMOMENTUMZ, &b_p_FOURMOMENTUMZ);
   fChain->SetBranchAddress("p_PT", &p_PT, &b_p_PT);
   fChain->SetBranchAddress("p_PX", &p_PX, &b_p_PX);
   fChain->SetBranchAddress("p_PY", &p_PY, &b_p_PY);
   fChain->SetBranchAddress("p_PZ", &p_PZ, &b_p_PZ);
   fChain->SetBranchAddress("p_CHI2", &p_CHI2, &b_p_CHI2);
   fChain->SetBranchAddress("p_CHI2DOF", &p_CHI2DOF, &b_p_CHI2DOF);
   fChain->SetBranchAddress("p_B_PV_Z", &p_B_PV_Z, &b_p_B_PV_Z);
   fChain->SetBranchAddress("p_B_PV_X", &p_B_PV_X, &b_p_B_PV_X);
   fChain->SetBranchAddress("p_B_PV_Y", &p_B_PV_Y, &b_p_B_PV_Y);
   fChain->SetBranchAddress("p_BPVIP", &p_BPVIP, &b_p_BPVIP);
   fChain->SetBranchAddress("p_BPVIPCHI2", &p_BPVIPCHI2, &b_p_BPVIPCHI2);
   fChain->SetBranchAddress("p_PIDE", &p_PIDE, &b_p_PIDE);
   fChain->SetBranchAddress("p_PIDK", &p_PIDK, &b_p_PIDK);
   fChain->SetBranchAddress("p_PIDMU", &p_PIDMU, &b_p_PIDMU);
   fChain->SetBranchAddress("p_PIDP", &p_PIDP, &b_p_PIDP);
   fChain->SetBranchAddress("p_PIDPI", &p_PIDPI, &b_p_PIDPI);
   fChain->SetBranchAddress("p_PROBNNE", &p_PROBNNE, &b_p_PROBNNE);
   fChain->SetBranchAddress("p_PROBNNK", &p_PROBNNK, &b_p_PROBNNK);
   fChain->SetBranchAddress("p_PROBNNMU", &p_PROBNNMU, &b_p_PROBNNMU);
   fChain->SetBranchAddress("p_PROBNNP", &p_PROBNNP, &b_p_PROBNNP);
   fChain->SetBranchAddress("p_PROBNNPI", &p_PROBNNPI, &b_p_PROBNNPI);
   fChain->SetBranchAddress("p_PROBNNGHOST", &p_PROBNNGHOST, &b_p_PROBNNGHOST);
   fChain->SetBranchAddress("p_PROBNND", &p_PROBNND, &b_p_PROBNND);
   fChain->SetBranchAddress("p_GHOSTPROB", &p_GHOSTPROB, &b_p_GHOSTPROB);
   fChain->SetBranchAddress("p_ISMUON", &p_ISMUON, &b_p_ISMUON);
   fChain->SetBranchAddress("p_IS_NOT_H", &p_IS_NOT_H, &b_p_IS_NOT_H);
   fChain->SetBranchAddress("p_IS_PHOTON", &p_IS_PHOTON, &b_p_IS_PHOTON);
   fChain->SetBranchAddress("p_TRACK_NVPHITS", &p_TRACK_NVPHITS, &b_p_TRACK_NVPHITS);
   fChain->SetBranchAddress("p_TRACK_NFTHITS", &p_TRACK_NFTHITS, &b_p_TRACK_NFTHITS);
   fChain->SetBranchAddress("pi_ID", &pi_ID, &b_pi_ID);
   fChain->SetBranchAddress("pi_KEY", &pi_KEY, &b_pi_KEY);
   fChain->SetBranchAddress("pi_CHARGE", &pi_CHARGE, &b_pi_CHARGE);
   fChain->SetBranchAddress("pi_ETA", &pi_ETA, &b_pi_ETA);
   fChain->SetBranchAddress("pi_PHI", &pi_PHI, &b_pi_PHI);
   fChain->SetBranchAddress("pi_MASS", &pi_MASS, &b_pi_MASS);
   fChain->SetBranchAddress("pi_FOURMOMENTUME", &pi_FOURMOMENTUME, &b_pi_FOURMOMENTUME);
   fChain->SetBranchAddress("pi_FOURMOMENTUMX", &pi_FOURMOMENTUMX, &b_pi_FOURMOMENTUMX);
   fChain->SetBranchAddress("pi_FOURMOMENTUMY", &pi_FOURMOMENTUMY, &b_pi_FOURMOMENTUMY);
   fChain->SetBranchAddress("pi_FOURMOMENTUMZ", &pi_FOURMOMENTUMZ, &b_pi_FOURMOMENTUMZ);
   fChain->SetBranchAddress("pi_PT", &pi_PT, &b_pi_PT);
   fChain->SetBranchAddress("pi_PX", &pi_PX, &b_pi_PX);
   fChain->SetBranchAddress("pi_PY", &pi_PY, &b_pi_PY);
   fChain->SetBranchAddress("pi_PZ", &pi_PZ, &b_pi_PZ);
   fChain->SetBranchAddress("pi_CHI2", &pi_CHI2, &b_pi_CHI2);
   fChain->SetBranchAddress("pi_CHI2DOF", &pi_CHI2DOF, &b_pi_CHI2DOF);
   fChain->SetBranchAddress("pi_B_PV_Z", &pi_B_PV_Z, &b_pi_B_PV_Z);
   fChain->SetBranchAddress("pi_B_PV_X", &pi_B_PV_X, &b_pi_B_PV_X);
   fChain->SetBranchAddress("pi_B_PV_Y", &pi_B_PV_Y, &b_pi_B_PV_Y);
   fChain->SetBranchAddress("pi_BPVIP", &pi_BPVIP, &b_pi_BPVIP);
   fChain->SetBranchAddress("pi_BPVIPCHI2", &pi_BPVIPCHI2, &b_pi_BPVIPCHI2);
   fChain->SetBranchAddress("pi_PIDE", &pi_PIDE, &b_pi_PIDE);
   fChain->SetBranchAddress("pi_PIDK", &pi_PIDK, &b_pi_PIDK);
   fChain->SetBranchAddress("pi_PIDMU", &pi_PIDMU, &b_pi_PIDMU);
   fChain->SetBranchAddress("pi_PIDP", &pi_PIDP, &b_pi_PIDP);
   fChain->SetBranchAddress("pi_PIDPI", &pi_PIDPI, &b_pi_PIDPI);
   fChain->SetBranchAddress("pi_PROBNNE", &pi_PROBNNE, &b_pi_PROBNNE);
   fChain->SetBranchAddress("pi_PROBNNK", &pi_PROBNNK, &b_pi_PROBNNK);
   fChain->SetBranchAddress("pi_PROBNNMU", &pi_PROBNNMU, &b_pi_PROBNNMU);
   fChain->SetBranchAddress("pi_PROBNNP", &pi_PROBNNP, &b_pi_PROBNNP);
   fChain->SetBranchAddress("pi_PROBNNPI", &pi_PROBNNPI, &b_pi_PROBNNPI);
   fChain->SetBranchAddress("pi_PROBNNGHOST", &pi_PROBNNGHOST, &b_pi_PROBNNGHOST);
   fChain->SetBranchAddress("pi_PROBNND", &pi_PROBNND, &b_pi_PROBNND);
   fChain->SetBranchAddress("pi_GHOSTPROB", &pi_GHOSTPROB, &b_pi_GHOSTPROB);
   fChain->SetBranchAddress("pi_ISMUON", &pi_ISMUON, &b_pi_ISMUON);
   fChain->SetBranchAddress("pi_IS_NOT_H", &pi_IS_NOT_H, &b_pi_IS_NOT_H);
   fChain->SetBranchAddress("pi_IS_PHOTON", &pi_IS_PHOTON, &b_pi_IS_PHOTON);
   fChain->SetBranchAddress("pi_TRACK_NVPHITS", &pi_TRACK_NVPHITS, &b_pi_TRACK_NVPHITS);
   fChain->SetBranchAddress("pi_TRACK_NFTHITS", &pi_TRACK_NFTHITS, &b_pi_TRACK_NFTHITS);
   Notify();
}

// === Notify ===
// Called when a new file is opened (e.g., in a TChain)
bool toroidalVorticityPbPb::Notify()
{
   return true;
}

// === Show ===
// Print all branches for a specific entry
void toroidalVorticityPbPb::Show(Long64_t entry)
{
   if (!fChain) return;
   fChain->Show(entry);
}

// === Cut ===
// Dummy cut function (accepts all entries)
Int_t toroidalVorticityPbPb::Cut(Long64_t entry)
{
   return 1;
}

// === CheckSister ===
// Candidate disambiguation: avoids duplicated decay products.
// Returns true only if current candidate is best (lowest χ²) in its vicinity.
bool toroidalVorticityPbPb::CheckSister(int nrentries, int jent, float pi_pt, float pro_pt, double lambda_quality, int runnr)
{
   int betterSister = 1;

   if (jent < 3) {
      // Check next few candidates
      for (int i = jent + 1; i < jent + 3; i++) {
         fChain->GetEntry(i);
         if (pi_PT == pi_pt || p_PT == pro_pt) {
            if (L0_DOCACHI2 < lambda_quality) {
               betterSister = 0;
               break;
            }
         }
      }
   } else if (nrentries - jent < 3) {
      // Check previous few candidates
      for (int i = jent - 3; i < jent; i++) {
         fChain->GetEntry(i);
         if (pi_PT == pi_pt || p_PT == pro_pt) {
            if (L0_DOCACHI2 < lambda_quality) {
               betterSister = 0;
               break;
            }
         }
      }
   } else {
      // Check neighborhood ±3 candidates
      for (int i = jent - 3; i < jent + 3; i++) {
         if (i == jent) continue;
         fChain->GetEntry(i);
         if (runnr == RUNNUMBER && (pi_PT == pi_pt || p_PT == pro_pt)) {
            if (L0_DOCACHI2 < lambda_quality) {
               betterSister = 0;
               break;
            }
         }
      }
   }

   return betterSister == 1;
}

#endif // #ifdef toroidalVorticityPbPb_cxx