/*
////////////////////////////////////////////////////////////////////////
// ExecuteAnalysisOnMultipleFiles.cxx
//
// Author: Maria Stefaniak
// Affiliation: The Ohio State University
//
// Description:
// This macro automates the batch execution of the toroidal vorticity
// analysis on multiple input ROOT files. It compiles the class 
// `toroidalVorticitySmog`, instantiates it for each input index,
// and calls the Loop() method to process the data.
//
// How to Use:
// root -l ExecuteAnalysisOnMultipleFiles.cxx
//
// Inside:
// - Modify the loop range (`ii = 1; ii < N; ii++`) to process multiple files.
// - Each iteration loads and executes toroidalVorticitySmog.C++.
// - Input file index `ii` is passed to the constructor of toroidalVorticitySmog.
// - Output is written by the Loop() method inside the class.
//
// Requirements:
// - toroidalVorticitySmog.h and toroidalVorticitySmog.C must be in the same directory.
// - Output files are saved in "out_root_new/" (modify if needed).
////////////////////////////////////////////////////////////////////////
*/
#ifndef toroidalVorticitySmog_h
#define toroidalVorticitySmog_h

// Include ROOT headers for data handling and math
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
#include "TVector2.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TProfile.h"

// Global variable to keep track of input file number
int iFile;

// Main analysis class
class toroidalVorticitySmog {
public:
   TTree          *fChain;   //! Pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //! Current Tree number in a TChain

   // Event-level data members (just a few shown here)
   Int_t           nPV;                          // Number of primary vertices
   Float_t         ALLPVX_ERR[10000];            // X error of PV positions [nPV]
   Float_t         ALLPVY_ERR[10000];   //[nPV]
   Float_t         ALLPVZ_ERR[10000];   //[nPV]
   UShort_t        BUNCHCROSSING_ID;
   UChar_t         BUNCHCROSSING_TYPE;
   ULong64_t       EVENTNUMBER;
   UInt_t          FILLNUMBER;
   ULong64_t       GPSTIME;
   Bool_t          Hlt1PassthroughPVinSMOG2Decision;
   Bool_t          Hlt1SMOG22BodyGenericDecision;
   Bool_t          Hlt1SMOG22BodyGenericPromptDecision;
   Bool_t          Hlt1SMOG2BELowMultElectronsDecision;
   Bool_t          Hlt1SMOG2BENoBiasDecision;
   Bool_t          Hlt1SMOG2D2KpiDecision;
   Bool_t          Hlt1SMOG2DiMuonHighMassDecision;
   Bool_t          Hlt1SMOG2KsTopipiDecision;
   Bool_t          Hlt1SMOG2L0ToppiDecision;
   Bool_t          Hlt1SMOG2MinimumBiasDecision;
   Bool_t          Hlt1SMOG2PassThroughLowMult5Decision;
   Bool_t          Hlt1SMOG2SingleMuonDecision;
   Bool_t          Hlt1SMOG2SingleTrackHighPtDecision;
   Bool_t          Hlt1SMOG2SingleTrackVeryHighPtDecision;
   Bool_t          Hlt1SMOG2etacToppDecision;
   Bool_t          Hlt1TrackMVADecision;
   Bool_t          Hlt1TrackMuonMVADecision;
   Bool_t          Hlt1TwoTrackMVADecision;
   UInt_t          Hlt1_TCK;
   UInt_t          ODINTCK;
   Float_t         PVCHI2NDOF[10000];   //[nPV]
   Float_t         PVCHI2[10000];   //[nPV]
   Float_t         PVNDOF[10000];   //[nPV]
   Float_t         PVX[10000];   //[nPV]
   Float_t         PVY[10000];   //[nPV]
   Float_t         PVZ[10000];   //[nPV]
   UInt_t          RUNNUMBER;
   Int_t           SMOGInjectedGas;
   Int_t           SMOGInjectionMode;
   Int_t           SMOGInjectionStable;
   Int_t           eCalTot;
   Int_t           hCalTot;
   Int_t           nBackTracks;
   Int_t           nDownTracks;
   Int_t           nEcalClusters;
   Int_t           nFTClusters;
   Int_t           nLongTracks;
   Int_t           nMuonCoordsS0;
   Int_t           nMuonCoordsS1;
   Int_t           nMuonCoordsS2;
   Int_t           nMuonCoordsS3;
   Int_t           nMuonCoordsS4;
   Int_t           nMuonTracks;
   Float_t         nPVTracks[10000];   //[nPV]
   Float_t         nPVbackTracks[10000];   //[nPV]
   Int_t           nPVs;
   Int_t           nRich1Hits;
   Int_t           nRich2Hits;
   Int_t           nTTracks;
   Int_t           nTracks;
   Int_t           nUpTracks;
   Int_t           nVPClusters;
   Int_t           nVeloClusters;
   Int_t           nVeloTracks;
   Int_t           LambdaT_ID;
   Int_t           LambdaT_KEY;
   Int_t           LambdaT_CHARGE;
   Float_t         LambdaT_PT;
   Float_t         LambdaT_PX;
   Float_t         LambdaT_PY;
   Float_t         LambdaT_PZ;
   Float_t         LambdaT_ETA;
   Float_t         LambdaT_PHI;
   Float_t         LambdaT_YSTAR;
   Float_t         LambdaT_Y;
   Double_t        LambdaT_MASS;
   Float_t         LambdaT_ENERGY;
   Float_t         LambdaT_P;
   Double_t        LambdaT_FOURMOMENTUME;
   Double_t        LambdaT_FOURMOMENTUMX;
   Double_t        LambdaT_FOURMOMENTUMY;
   Double_t        LambdaT_FOURMOMENTUMZ;
   Double_t        LambdaT_CHI2;
   Double_t        LambdaT_CHI2DOF;
   Float_t         LambdaT_B_PV_Z;
   Float_t         LambdaT_B_PV_X;
   Float_t         LambdaT_B_PV_Y;
   Float_t         LambdaT_BPVIP;
   Float_t         LambdaT_BPVIPCHI2;
   Int_t           LambdaT_nBestPVTracks;
   Int_t           LambdaT_nBestPVbackTracks;
   Bool_t          LambdaT_Hlt1SMOG2D2KpiDecision_TOS;
   Bool_t          LambdaT_Hlt1SMOG2etacToppDecision_TOS;
   Bool_t          LambdaT_Hlt1SMOG2L0ToppiDecision_TOS;
   Bool_t          LambdaT_Hlt1SMOG22BodyGenericDecision_TOS;
   Bool_t          LambdaT_Hlt1TrackMuonMVADecision_TOS;
   Bool_t          LambdaT_Hlt1TwoTrackMVADecision_TOS;
   Bool_t          LambdaT_Hlt1SMOG2BELowMultElectronsDecision_TOS;
   Bool_t          LambdaT_Hlt1SMOG2SingleMuonDecision_TOS;
   Bool_t          LambdaT_Hlt1TrackMVADecision_TOS;
   Bool_t          LambdaT_Hlt1SMOG2BENoBiasDecision_TOS;
   Bool_t          LambdaT_Hlt1SMOG22BodyGenericPromptDecision_TOS;
   Bool_t          LambdaT_Hlt1SMOG2DiMuonHighMassDecision_TOS;
   Bool_t          LambdaT_Hlt1SMOG2MinimumBiasDecision_TOS;
   Bool_t          LambdaT_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS;
   Bool_t          LambdaT_Hlt1PassthroughPVinSMOG2Decision_TOS;
   Bool_t          LambdaT_Hlt1SMOG2SingleTrackHighPtDecision_TOS;
   Bool_t          LambdaT_Hlt1SMOG2PassThroughLowMult5Decision_TOS;
   Bool_t          LambdaT_Hlt1SMOG2KsTopipiDecision_TOS;
   Bool_t          LambdaT_Hlt1SMOG2D2KpiDecision_TIS;
   Bool_t          LambdaT_Hlt1SMOG2etacToppDecision_TIS;
   Bool_t          LambdaT_Hlt1SMOG2L0ToppiDecision_TIS;
   Bool_t          LambdaT_Hlt1SMOG22BodyGenericDecision_TIS;
   Bool_t          LambdaT_Hlt1TrackMuonMVADecision_TIS;
   Bool_t          LambdaT_Hlt1TwoTrackMVADecision_TIS;
   Bool_t          LambdaT_Hlt1SMOG2BELowMultElectronsDecision_TIS;
   Bool_t          LambdaT_Hlt1SMOG2SingleMuonDecision_TIS;
   Bool_t          LambdaT_Hlt1TrackMVADecision_TIS;
   Bool_t          LambdaT_Hlt1SMOG2BENoBiasDecision_TIS;
   Bool_t          LambdaT_Hlt1SMOG22BodyGenericPromptDecision_TIS;
   Bool_t          LambdaT_Hlt1SMOG2DiMuonHighMassDecision_TIS;
   Bool_t          LambdaT_Hlt1SMOG2MinimumBiasDecision_TIS;
   Bool_t          LambdaT_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS;
   Bool_t          LambdaT_Hlt1PassthroughPVinSMOG2Decision_TIS;
   Bool_t          LambdaT_Hlt1SMOG2SingleTrackHighPtDecision_TIS;
   Bool_t          LambdaT_Hlt1SMOG2PassThroughLowMult5Decision_TIS;
   Bool_t          LambdaT_Hlt1SMOG2KsTopipiDecision_TIS;
   Double_t        LambdaT_DOCA;
   Double_t        LambdaT_DOCACHI2;
   Float_t         LambdaT_SDOCA;
   Float_t         LambdaT_SDOCACHI2;
   Float_t         LambdaT_END_VX;
   Float_t         LambdaT_END_VY;
   Float_t         LambdaT_END_VZ;
   Float_t         LambdaT_END_VRHO;
   Float_t         LambdaT_BPVFDCHI2;
   Float_t         LambdaT_BPVLTIME;
   Float_t         LambdaT_BPVFD;
   Float_t         LambdaT_BPVDIRA;
   Int_t           pbar_ID;
   Int_t           pbar_KEY;
   Int_t           pbar_CHARGE;
   Float_t         pbar_PT;
   Float_t         pbar_PX;
   Float_t         pbar_PY;
   Float_t         pbar_PZ;
   Float_t         pbar_ETA;
   Float_t         pbar_PHI;
   Float_t         pbar_YSTAR;
   Float_t         pbar_Y;
   Double_t        pbar_MASS;
   Float_t         pbar_ENERGY;
   Float_t         pbar_P;
   Double_t        pbar_FOURMOMENTUME;
   Double_t        pbar_FOURMOMENTUMX;
   Double_t        pbar_FOURMOMENTUMY;
   Double_t        pbar_FOURMOMENTUMZ;
   Double_t        pbar_CHI2;
   Double_t        pbar_CHI2DOF;
   Float_t         pbar_B_PV_Z;
   Float_t         pbar_B_PV_X;
   Float_t         pbar_B_PV_Y;
   Float_t         pbar_BPVIP;
   Float_t         pbar_BPVIPCHI2;
   Int_t           pbar_nBestPVTracks;
   Int_t           pbar_nBestPVbackTracks;
   Bool_t          pbar_Hlt1SMOG2D2KpiDecision_TOS;
   Bool_t          pbar_Hlt1SMOG2etacToppDecision_TOS;
   Bool_t          pbar_Hlt1SMOG2L0ToppiDecision_TOS;
   Bool_t          pbar_Hlt1SMOG22BodyGenericDecision_TOS;
   Bool_t          pbar_Hlt1TrackMuonMVADecision_TOS;
   Bool_t          pbar_Hlt1TwoTrackMVADecision_TOS;
   Bool_t          pbar_Hlt1SMOG2BELowMultElectronsDecision_TOS;
   Bool_t          pbar_Hlt1SMOG2SingleMuonDecision_TOS;
   Bool_t          pbar_Hlt1TrackMVADecision_TOS;
   Bool_t          pbar_Hlt1SMOG2BENoBiasDecision_TOS;
   Bool_t          pbar_Hlt1SMOG22BodyGenericPromptDecision_TOS;
   Bool_t          pbar_Hlt1SMOG2DiMuonHighMassDecision_TOS;
   Bool_t          pbar_Hlt1SMOG2MinimumBiasDecision_TOS;
   Bool_t          pbar_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS;
   Bool_t          pbar_Hlt1PassthroughPVinSMOG2Decision_TOS;
   Bool_t          pbar_Hlt1SMOG2SingleTrackHighPtDecision_TOS;
   Bool_t          pbar_Hlt1SMOG2PassThroughLowMult5Decision_TOS;
   Bool_t          pbar_Hlt1SMOG2KsTopipiDecision_TOS;
   Bool_t          pbar_Hlt1SMOG2D2KpiDecision_TIS;
   Bool_t          pbar_Hlt1SMOG2etacToppDecision_TIS;
   Bool_t          pbar_Hlt1SMOG2L0ToppiDecision_TIS;
   Bool_t          pbar_Hlt1SMOG22BodyGenericDecision_TIS;
   Bool_t          pbar_Hlt1TrackMuonMVADecision_TIS;
   Bool_t          pbar_Hlt1TwoTrackMVADecision_TIS;
   Bool_t          pbar_Hlt1SMOG2BELowMultElectronsDecision_TIS;
   Bool_t          pbar_Hlt1SMOG2SingleMuonDecision_TIS;
   Bool_t          pbar_Hlt1TrackMVADecision_TIS;
   Bool_t          pbar_Hlt1SMOG2BENoBiasDecision_TIS;
   Bool_t          pbar_Hlt1SMOG22BodyGenericPromptDecision_TIS;
   Bool_t          pbar_Hlt1SMOG2DiMuonHighMassDecision_TIS;
   Bool_t          pbar_Hlt1SMOG2MinimumBiasDecision_TIS;
   Bool_t          pbar_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS;
   Bool_t          pbar_Hlt1PassthroughPVinSMOG2Decision_TIS;
   Bool_t          pbar_Hlt1SMOG2SingleTrackHighPtDecision_TIS;
   Bool_t          pbar_Hlt1SMOG2PassThroughLowMult5Decision_TIS;
   Bool_t          pbar_Hlt1SMOG2KsTopipiDecision_TIS;
   Float_t         pbar_PIDE;
   Float_t         pbar_PIDK;
   Float_t         pbar_PIDMU;
   Float_t         pbar_PIDP;
   Float_t         pbar_PIDPI;
   Float_t         pbar_PROBNNE;
   Float_t         pbar_PROBNNK;
   Float_t         pbar_PROBNNMU;
   Float_t         pbar_PROBNNP;
   Float_t         pbar_PROBNNPI;
   Float_t         pbar_PROBNNGHOST;
   Float_t         pbar_PROBNND;
   Double_t        pbar_GHOSTPROB;
   Bool_t          pbar_ISMUON;
   Float_t         pbar_IS_NOT_H;
   Float_t         pbar_IS_PHOTON;
   Int_t           pbar_TRACK_NVPHITS;
   Int_t           pbar_TRACK_NFTHITS;
   Int_t           pbar_TRACK_NUTHITS;
   Double_t        pbar_TRACK_POS_CLOSESTTOBEAM_X;
   Double_t        pbar_TRACK_POS_CLOSESTTOBEAM_Y;
   Double_t        pbar_TRACK_POS_CLOSESTTOBEAM_Z;
   Int_t           pim_ID;
   Int_t           pim_KEY;
   Int_t           pim_CHARGE;
   Float_t         pim_PT;
   Float_t         pim_PX;
   Float_t         pim_PY;
   Float_t         pim_PZ;
   Float_t         pim_ETA;
   Float_t         pim_PHI;
   Float_t         pim_YSTAR;
   Float_t         pim_Y;
   Double_t        pim_MASS;
   Float_t         pim_ENERGY;
   Float_t         pim_P;
   Double_t        pim_FOURMOMENTUME;
   Double_t        pim_FOURMOMENTUMX;
   Double_t        pim_FOURMOMENTUMY;
   Double_t        pim_FOURMOMENTUMZ;
   Double_t        pim_CHI2;
   Double_t        pim_CHI2DOF;
   Float_t         pim_B_PV_Z;
   Float_t         pim_B_PV_X;
   Float_t         pim_B_PV_Y;
   Float_t         pim_BPVIP;
   Float_t         pim_BPVIPCHI2;
   Int_t           pim_nBestPVTracks;
   Int_t           pim_nBestPVbackTracks;
   Bool_t          pim_Hlt1SMOG2D2KpiDecision_TOS;
   Bool_t          pim_Hlt1SMOG2etacToppDecision_TOS;
   Bool_t          pim_Hlt1SMOG2L0ToppiDecision_TOS;
   Bool_t          pim_Hlt1SMOG22BodyGenericDecision_TOS;
   Bool_t          pim_Hlt1TrackMuonMVADecision_TOS;
   Bool_t          pim_Hlt1TwoTrackMVADecision_TOS;
   Bool_t          pim_Hlt1SMOG2BELowMultElectronsDecision_TOS;
   Bool_t          pim_Hlt1SMOG2SingleMuonDecision_TOS;
   Bool_t          pim_Hlt1TrackMVADecision_TOS;
   Bool_t          pim_Hlt1SMOG2BENoBiasDecision_TOS;
   Bool_t          pim_Hlt1SMOG22BodyGenericPromptDecision_TOS;
   Bool_t          pim_Hlt1SMOG2DiMuonHighMassDecision_TOS;
   Bool_t          pim_Hlt1SMOG2MinimumBiasDecision_TOS;
   Bool_t          pim_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS;
   Bool_t          pim_Hlt1PassthroughPVinSMOG2Decision_TOS;
   Bool_t          pim_Hlt1SMOG2SingleTrackHighPtDecision_TOS;
   Bool_t          pim_Hlt1SMOG2PassThroughLowMult5Decision_TOS;
   Bool_t          pim_Hlt1SMOG2KsTopipiDecision_TOS;
   Bool_t          pim_Hlt1SMOG2D2KpiDecision_TIS;
   Bool_t          pim_Hlt1SMOG2etacToppDecision_TIS;
   Bool_t          pim_Hlt1SMOG2L0ToppiDecision_TIS;
   Bool_t          pim_Hlt1SMOG22BodyGenericDecision_TIS;
   Bool_t          pim_Hlt1TrackMuonMVADecision_TIS;
   Bool_t          pim_Hlt1TwoTrackMVADecision_TIS;
   Bool_t          pim_Hlt1SMOG2BELowMultElectronsDecision_TIS;
   Bool_t          pim_Hlt1SMOG2SingleMuonDecision_TIS;
   Bool_t          pim_Hlt1TrackMVADecision_TIS;
   Bool_t          pim_Hlt1SMOG2BENoBiasDecision_TIS;
   Bool_t          pim_Hlt1SMOG22BodyGenericPromptDecision_TIS;
   Bool_t          pim_Hlt1SMOG2DiMuonHighMassDecision_TIS;
   Bool_t          pim_Hlt1SMOG2MinimumBiasDecision_TIS;
   Bool_t          pim_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS;
   Bool_t          pim_Hlt1PassthroughPVinSMOG2Decision_TIS;
   Bool_t          pim_Hlt1SMOG2SingleTrackHighPtDecision_TIS;
   Bool_t          pim_Hlt1SMOG2PassThroughLowMult5Decision_TIS;
   Bool_t          pim_Hlt1SMOG2KsTopipiDecision_TIS;
   Float_t         pim_PIDE;
   Float_t         pim_PIDK;
   Float_t         pim_PIDMU;
   Float_t         pim_PIDP;
   Float_t         pim_PIDPI;
   Float_t         pim_PROBNNE;
   Float_t         pim_PROBNNK;
   Float_t         pim_PROBNNMU;
   Float_t         pim_PROBNNP;
   Float_t         pim_PROBNNPI;
   Float_t         pim_PROBNNGHOST;
   Float_t         pim_PROBNND;
   Double_t        pim_GHOSTPROB;
   Bool_t          pim_ISMUON;
   Float_t         pim_IS_NOT_H;
   Float_t         pim_IS_PHOTON;
   Int_t           pim_TRACK_NVPHITS;
   Int_t           pim_TRACK_NFTHITS;
   Int_t           pim_TRACK_NUTHITS;
   Double_t        pim_TRACK_POS_CLOSESTTOBEAM_X;
   Double_t        pim_TRACK_POS_CLOSESTTOBEAM_Y;
   Double_t        pim_TRACK_POS_CLOSESTTOBEAM_Z;

   // List of branches
   TBranch        *b_nPV;   //!
   TBranch        *b_ALLPVX_ERR;   //!
   TBranch        *b_ALLPVY_ERR;   //!
   TBranch        *b_ALLPVZ_ERR;   //!
   TBranch        *b_BUNCHCROSSING_ID;   //!
   TBranch        *b_BUNCHCROSSING_TYPE;   //!
   TBranch        *b_EVENTNUMBER;   //!
   TBranch        *b_FILLNUMBER;   //!
   TBranch        *b_GPSTIME;   //!
   TBranch        *b_Hlt1PassthroughPVinSMOG2Decision;   //!
   TBranch        *b_Hlt1SMOG22BodyGenericDecision;   //!
   TBranch        *b_Hlt1SMOG22BodyGenericPromptDecision;   //!
   TBranch        *b_Hlt1SMOG2BELowMultElectronsDecision;   //!
   TBranch        *b_Hlt1SMOG2BENoBiasDecision;   //!
   TBranch        *b_Hlt1SMOG2D2KpiDecision;   //!
   TBranch        *b_Hlt1SMOG2DiMuonHighMassDecision;   //!
   TBranch        *b_Hlt1SMOG2KsTopipiDecision;   //!
   TBranch        *b_Hlt1SMOG2L0ToppiDecision;   //!
   TBranch        *b_Hlt1SMOG2MinimumBiasDecision;   //!
   TBranch        *b_Hlt1SMOG2PassThroughLowMult5Decision;   //!
   TBranch        *b_Hlt1SMOG2SingleMuonDecision;   //!
   TBranch        *b_Hlt1SMOG2SingleTrackHighPtDecision;   //!
   TBranch        *b_Hlt1SMOG2SingleTrackVeryHighPtDecision;   //!
   TBranch        *b_Hlt1SMOG2etacToppDecision;   //!
   TBranch        *b_Hlt1TrackMVADecision;   //!
   TBranch        *b_Hlt1TrackMuonMVADecision;   //!
   TBranch        *b_Hlt1TwoTrackMVADecision;   //!
   TBranch        *b_Hlt1_TCK;   //!
   TBranch        *b_ODINTCK;   //!
   TBranch        *b_PVCHI2NDOF;   //!
   TBranch        *b_PVCHI2;   //!
   TBranch        *b_PVNDOF;   //!
   TBranch        *b_PVX;   //!
   TBranch        *b_PVY;   //!
   TBranch        *b_PVZ;   //!
   TBranch        *b_RUNNUMBER;   //!
   TBranch        *b_SMOGInjectedGas;   //!
   TBranch        *b_SMOGInjectionMode;   //!
   TBranch        *b_SMOGInjectionStable;   //!
   TBranch        *b_eCalTot;   //!
   TBranch        *b_hCalTot;   //!
   TBranch        *b_nBackTracks;   //!
   TBranch        *b_nDownTracks;   //!
   TBranch        *b_nEcalClusters;   //!
   TBranch        *b_nFTClusters;   //!
   TBranch        *b_nLongTracks;   //!
   TBranch        *b_nMuonCoordsS0;   //!
   TBranch        *b_nMuonCoordsS1;   //!
   TBranch        *b_nMuonCoordsS2;   //!
   TBranch        *b_nMuonCoordsS3;   //!
   TBranch        *b_nMuonCoordsS4;   //!
   TBranch        *b_nMuonTracks;   //!
   TBranch        *b_nPVTracks;   //!
   TBranch        *b_nPVbackTracks;   //!
   TBranch        *b_nPVs;   //!
   TBranch        *b_nRich1Hits;   //!
   TBranch        *b_nRich2Hits;   //!
   TBranch        *b_nTTracks;   //!
   TBranch        *b_nTracks;   //!
   TBranch        *b_nUpTracks;   //!
   TBranch        *b_nVPClusters;   //!
   TBranch        *b_nVeloClusters;   //!
   TBranch        *b_nVeloTracks;   //!
   TBranch        *b_LambdaT_ID;   //!
   TBranch        *b_LambdaT_KEY;   //!
   TBranch        *b_LambdaT_CHARGE;   //!
   TBranch        *b_LambdaT_PT;   //!
   TBranch        *b_LambdaT_PX;   //!
   TBranch        *b_LambdaT_PY;   //!
   TBranch        *b_LambdaT_PZ;   //!
   TBranch        *b_LambdaT_ETA;   //!
   TBranch        *b_LambdaT_PHI;   //!
   TBranch        *b_LambdaT_YSTAR;   //!
   TBranch        *b_LambdaT_Y;   //!
   TBranch        *b_LambdaT_MASS;   //!
   TBranch        *b_LambdaT_ENERGY;   //!
   TBranch        *b_LambdaT_P;   //!
   TBranch        *b_LambdaT_FOURMOMENTUME;   //!
   TBranch        *b_LambdaT_FOURMOMENTUMX;   //!
   TBranch        *b_LambdaT_FOURMOMENTUMY;   //!
   TBranch        *b_LambdaT_FOURMOMENTUMZ;   //!
   TBranch        *b_LambdaT_CHI2;   //!
   TBranch        *b_LambdaT_CHI2DOF;   //!
   TBranch        *b_LambdaT_B_PV_Z;   //!
   TBranch        *b_LambdaT_B_PV_X;   //!
   TBranch        *b_LambdaT_B_PV_Y;   //!
   TBranch        *b_LambdaT_BPVIP;   //!
   TBranch        *b_LambdaT_BPVIPCHI2;   //!
   TBranch        *b_LambdaT_nBestPVTracks;   //!
   TBranch        *b_LambdaT_nBestPVbackTracks;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2D2KpiDecision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2etacToppDecision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2L0ToppiDecision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG22BodyGenericDecision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1TrackMuonMVADecision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1TwoTrackMVADecision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2BELowMultElectronsDecision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2SingleMuonDecision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1TrackMVADecision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2BENoBiasDecision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG22BodyGenericPromptDecision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2DiMuonHighMassDecision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2MinimumBiasDecision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1PassthroughPVinSMOG2Decision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2SingleTrackHighPtDecision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2PassThroughLowMult5Decision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2KsTopipiDecision_TOS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2D2KpiDecision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2etacToppDecision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2L0ToppiDecision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG22BodyGenericDecision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1TrackMuonMVADecision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1TwoTrackMVADecision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2BELowMultElectronsDecision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2SingleMuonDecision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1TrackMVADecision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2BENoBiasDecision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG22BodyGenericPromptDecision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2DiMuonHighMassDecision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2MinimumBiasDecision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1PassthroughPVinSMOG2Decision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2SingleTrackHighPtDecision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2PassThroughLowMult5Decision_TIS;   //!
   TBranch        *b_LambdaT_Hlt1SMOG2KsTopipiDecision_TIS;   //!
   TBranch        *b_LambdaT_DOCA;   //!
   TBranch        *b_LambdaT_DOCACHI2;   //!
   TBranch        *b_LambdaT_SDOCA;   //!
   TBranch        *b_LambdaT_SDOCACHI2;   //!
   TBranch        *b_LambdaT_END_VX;   //!
   TBranch        *b_LambdaT_END_VY;   //!
   TBranch        *b_LambdaT_END_VZ;   //!
   TBranch        *b_LambdaT_END_VRHO;   //!
   TBranch        *b_LambdaT_BPVFDCHI2;   //!
   TBranch        *b_LambdaT_BPVLTIME;   //!
   TBranch        *b_LambdaT_BPVFD;   //!
   TBranch        *b_LambdaT_BPVDIRA;   //!
   TBranch        *b_pbar_ID;   //!
   TBranch        *b_pbar_KEY;   //!
   TBranch        *b_pbar_CHARGE;   //!
   TBranch        *b_pbar_PT;   //!
   TBranch        *b_pbar_PX;   //!
   TBranch        *b_pbar_PY;   //!
   TBranch        *b_pbar_PZ;   //!
   TBranch        *b_pbar_ETA;   //!
   TBranch        *b_pbar_PHI;   //!
   TBranch        *b_pbar_YSTAR;   //!
   TBranch        *b_pbar_Y;   //!
   TBranch        *b_pbar_MASS;   //!
   TBranch        *b_pbar_ENERGY;   //!
   TBranch        *b_pbar_P;   //!
   TBranch        *b_pbar_FOURMOMENTUME;   //!
   TBranch        *b_pbar_FOURMOMENTUMX;   //!
   TBranch        *b_pbar_FOURMOMENTUMY;   //!
   TBranch        *b_pbar_FOURMOMENTUMZ;   //!
   TBranch        *b_pbar_CHI2;   //!
   TBranch        *b_pbar_CHI2DOF;   //!
   TBranch        *b_pbar_B_PV_Z;   //!
   TBranch        *b_pbar_B_PV_X;   //!
   TBranch        *b_pbar_B_PV_Y;   //!
   TBranch        *b_pbar_BPVIP;   //!
   TBranch        *b_pbar_BPVIPCHI2;   //!
   TBranch        *b_pbar_nBestPVTracks;   //!
   TBranch        *b_pbar_nBestPVbackTracks;   //!
   TBranch        *b_pbar_Hlt1SMOG2D2KpiDecision_TOS;   //!
   TBranch        *b_pbar_Hlt1SMOG2etacToppDecision_TOS;   //!
   TBranch        *b_pbar_Hlt1SMOG2L0ToppiDecision_TOS;   //!
   TBranch        *b_pbar_Hlt1SMOG22BodyGenericDecision_TOS;   //!
   TBranch        *b_pbar_Hlt1TrackMuonMVADecision_TOS;   //!
   TBranch        *b_pbar_Hlt1TwoTrackMVADecision_TOS;   //!
   TBranch        *b_pbar_Hlt1SMOG2BELowMultElectronsDecision_TOS;   //!
   TBranch        *b_pbar_Hlt1SMOG2SingleMuonDecision_TOS;   //!
   TBranch        *b_pbar_Hlt1TrackMVADecision_TOS;   //!
   TBranch        *b_pbar_Hlt1SMOG2BENoBiasDecision_TOS;   //!
   TBranch        *b_pbar_Hlt1SMOG22BodyGenericPromptDecision_TOS;   //!
   TBranch        *b_pbar_Hlt1SMOG2DiMuonHighMassDecision_TOS;   //!
   TBranch        *b_pbar_Hlt1SMOG2MinimumBiasDecision_TOS;   //!
   TBranch        *b_pbar_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS;   //!
   TBranch        *b_pbar_Hlt1PassthroughPVinSMOG2Decision_TOS;   //!
   TBranch        *b_pbar_Hlt1SMOG2SingleTrackHighPtDecision_TOS;   //!
   TBranch        *b_pbar_Hlt1SMOG2PassThroughLowMult5Decision_TOS;   //!
   TBranch        *b_pbar_Hlt1SMOG2KsTopipiDecision_TOS;   //!
   TBranch        *b_pbar_Hlt1SMOG2D2KpiDecision_TIS;   //!
   TBranch        *b_pbar_Hlt1SMOG2etacToppDecision_TIS;   //!
   TBranch        *b_pbar_Hlt1SMOG2L0ToppiDecision_TIS;   //!
   TBranch        *b_pbar_Hlt1SMOG22BodyGenericDecision_TIS;   //!
   TBranch        *b_pbar_Hlt1TrackMuonMVADecision_TIS;   //!
   TBranch        *b_pbar_Hlt1TwoTrackMVADecision_TIS;   //!
   TBranch        *b_pbar_Hlt1SMOG2BELowMultElectronsDecision_TIS;   //!
   TBranch        *b_pbar_Hlt1SMOG2SingleMuonDecision_TIS;   //!
   TBranch        *b_pbar_Hlt1TrackMVADecision_TIS;   //!
   TBranch        *b_pbar_Hlt1SMOG2BENoBiasDecision_TIS;   //!
   TBranch        *b_pbar_Hlt1SMOG22BodyGenericPromptDecision_TIS;   //!
   TBranch        *b_pbar_Hlt1SMOG2DiMuonHighMassDecision_TIS;   //!
   TBranch        *b_pbar_Hlt1SMOG2MinimumBiasDecision_TIS;   //!
   TBranch        *b_pbar_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS;   //!
   TBranch        *b_pbar_Hlt1PassthroughPVinSMOG2Decision_TIS;   //!
   TBranch        *b_pbar_Hlt1SMOG2SingleTrackHighPtDecision_TIS;   //!
   TBranch        *b_pbar_Hlt1SMOG2PassThroughLowMult5Decision_TIS;   //!
   TBranch        *b_pbar_Hlt1SMOG2KsTopipiDecision_TIS;   //!
   TBranch        *b_pbar_PIDE;   //!
   TBranch        *b_pbar_PIDK;   //!
   TBranch        *b_pbar_PIDMU;   //!
   TBranch        *b_pbar_PIDP;   //!
   TBranch        *b_pbar_PIDPI;   //!
   TBranch        *b_pbar_PROBNNE;   //!
   TBranch        *b_pbar_PROBNNK;   //!
   TBranch        *b_pbar_PROBNNMU;   //!
   TBranch        *b_pbar_PROBNNP;   //!
   TBranch        *b_pbar_PROBNNPI;   //!
   TBranch        *b_pbar_PROBNNGHOST;   //!
   TBranch        *b_pbar_PROBNND;   //!
   TBranch        *b_pbar_GHOSTPROB;   //!
   TBranch        *b_pbar_ISMUON;   //!
   TBranch        *b_pbar_IS_NOT_H;   //!
   TBranch        *b_pbar_IS_PHOTON;   //!
   TBranch        *b_pbar_TRACK_NVPHITS;   //!
   TBranch        *b_pbar_TRACK_NFTHITS;   //!
   TBranch        *b_pbar_TRACK_NUTHITS;   //!
   TBranch        *b_pbar_TRACK_POS_CLOSESTTOBEAM_X;   //!
   TBranch        *b_pbar_TRACK_POS_CLOSESTTOBEAM_Y;   //!
   TBranch        *b_pbar_TRACK_POS_CLOSESTTOBEAM_Z;   //!
   TBranch        *b_pim_ID;   //!
   TBranch        *b_pim_KEY;   //!
   TBranch        *b_pim_CHARGE;   //!
   TBranch        *b_pim_PT;   //!
   TBranch        *b_pim_PX;   //!
   TBranch        *b_pim_PY;   //!
   TBranch        *b_pim_PZ;   //!
   TBranch        *b_pim_ETA;   //!
   TBranch        *b_pim_PHI;   //!
   TBranch        *b_pim_YSTAR;   //!
   TBranch        *b_pim_Y;   //!
   TBranch        *b_pim_MASS;   //!
   TBranch        *b_pim_ENERGY;   //!
   TBranch        *b_pim_P;   //!
   TBranch        *b_pim_FOURMOMENTUME;   //!
   TBranch        *b_pim_FOURMOMENTUMX;   //!
   TBranch        *b_pim_FOURMOMENTUMY;   //!
   TBranch        *b_pim_FOURMOMENTUMZ;   //!
   TBranch        *b_pim_CHI2;   //!
   TBranch        *b_pim_CHI2DOF;   //!
   TBranch        *b_pim_B_PV_Z;   //!
   TBranch        *b_pim_B_PV_X;   //!
   TBranch        *b_pim_B_PV_Y;   //!
   TBranch        *b_pim_BPVIP;   //!
   TBranch        *b_pim_BPVIPCHI2;   //!
   TBranch        *b_pim_nBestPVTracks;   //!
   TBranch        *b_pim_nBestPVbackTracks;   //!
   TBranch        *b_pim_Hlt1SMOG2D2KpiDecision_TOS;   //!
   TBranch        *b_pim_Hlt1SMOG2etacToppDecision_TOS;   //!
   TBranch        *b_pim_Hlt1SMOG2L0ToppiDecision_TOS;   //!
   TBranch        *b_pim_Hlt1SMOG22BodyGenericDecision_TOS;   //!
   TBranch        *b_pim_Hlt1TrackMuonMVADecision_TOS;   //!
   TBranch        *b_pim_Hlt1TwoTrackMVADecision_TOS;   //!
   TBranch        *b_pim_Hlt1SMOG2BELowMultElectronsDecision_TOS;   //!
   TBranch        *b_pim_Hlt1SMOG2SingleMuonDecision_TOS;   //!
   TBranch        *b_pim_Hlt1TrackMVADecision_TOS;   //!
   TBranch        *b_pim_Hlt1SMOG2BENoBiasDecision_TOS;   //!
   TBranch        *b_pim_Hlt1SMOG22BodyGenericPromptDecision_TOS;   //!
   TBranch        *b_pim_Hlt1SMOG2DiMuonHighMassDecision_TOS;   //!
   TBranch        *b_pim_Hlt1SMOG2MinimumBiasDecision_TOS;   //!
   TBranch        *b_pim_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS;   //!
   TBranch        *b_pim_Hlt1PassthroughPVinSMOG2Decision_TOS;   //!
   TBranch        *b_pim_Hlt1SMOG2SingleTrackHighPtDecision_TOS;   //!
   TBranch        *b_pim_Hlt1SMOG2PassThroughLowMult5Decision_TOS;   //!
   TBranch        *b_pim_Hlt1SMOG2KsTopipiDecision_TOS;   //!
   TBranch        *b_pim_Hlt1SMOG2D2KpiDecision_TIS;   //!
   TBranch        *b_pim_Hlt1SMOG2etacToppDecision_TIS;   //!
   TBranch        *b_pim_Hlt1SMOG2L0ToppiDecision_TIS;   //!
   TBranch        *b_pim_Hlt1SMOG22BodyGenericDecision_TIS;   //!
   TBranch        *b_pim_Hlt1TrackMuonMVADecision_TIS;   //!
   TBranch        *b_pim_Hlt1TwoTrackMVADecision_TIS;   //!
   TBranch        *b_pim_Hlt1SMOG2BELowMultElectronsDecision_TIS;   //!
   TBranch        *b_pim_Hlt1SMOG2SingleMuonDecision_TIS;   //!
   TBranch        *b_pim_Hlt1TrackMVADecision_TIS;   //!
   TBranch        *b_pim_Hlt1SMOG2BENoBiasDecision_TIS;   //!
   TBranch        *b_pim_Hlt1SMOG22BodyGenericPromptDecision_TIS;   //!
   TBranch        *b_pim_Hlt1SMOG2DiMuonHighMassDecision_TIS;   //!
   TBranch        *b_pim_Hlt1SMOG2MinimumBiasDecision_TIS;   //!
   TBranch        *b_pim_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS;   //!
   TBranch        *b_pim_Hlt1PassthroughPVinSMOG2Decision_TIS;   //!
   TBranch        *b_pim_Hlt1SMOG2SingleTrackHighPtDecision_TIS;   //!
   TBranch        *b_pim_Hlt1SMOG2PassThroughLowMult5Decision_TIS;   //!
   TBranch        *b_pim_Hlt1SMOG2KsTopipiDecision_TIS;   //!
   TBranch        *b_pim_PIDE;   //!
   TBranch        *b_pim_PIDK;   //!
   TBranch        *b_pim_PIDMU;   //!
   TBranch        *b_pim_PIDP;   //!
   TBranch        *b_pim_PIDPI;   //!
   TBranch        *b_pim_PROBNNE;   //!
   TBranch        *b_pim_PROBNNK;   //!
   TBranch        *b_pim_PROBNNMU;   //!
   TBranch        *b_pim_PROBNNP;   //!
   TBranch        *b_pim_PROBNNPI;   //!
   TBranch        *b_pim_PROBNNGHOST;   //!
   TBranch        *b_pim_PROBNND;   //!
   TBranch        *b_pim_GHOSTPROB;   //!
   TBranch        *b_pim_ISMUON;   //!
   TBranch        *b_pim_IS_NOT_H;   //!
   TBranch        *b_pim_IS_PHOTON;   //!
   TBranch        *b_pim_TRACK_NVPHITS;   //!
   TBranch        *b_pim_TRACK_NFTHITS;   //!
   TBranch        *b_pim_TRACK_NUTHITS;   //!
   TBranch        *b_pim_TRACK_POS_CLOSESTTOBEAM_X;   //!
   TBranch        *b_pim_TRACK_POS_CLOSESTTOBEAM_Y;   //!
   TBranch        *b_pim_TRACK_POS_CLOSESTTOBEAM_Z;   //!

   // Constructor & destructor
   toroidalVorticitySmog(TTree *tree=0,  int iiFile=1);  // Constructor
   virtual ~toroidalVorticitySmog();                     // Destructor

   // Core ROOT methods
   virtual Int_t    Cut(Long64_t entry);                 // Optional event-level filter
   virtual Int_t    GetEntry(Long64_t entry);            // Load event entry
   virtual Long64_t LoadTree(Long64_t entry);            // Load tree for entry
   virtual void     Init(TTree *tree);                   // Set branch addresses
   virtual void     Loop();                              // Main analysis loop
   virtual bool     Notify();                            // Called when new file is opened
   virtual void     Show(Long64_t entry = -1);           // Print contents of entry
   virtual bool     CheckSister(int nrentreis, int jent, float pim_PT, float pro_pt, double lambda_quality, int runnr); // Sister candidate check
};

#endif // toroidalVorticitySmog_h

#ifdef toroidalVorticitySmog_cxx

// Constructor: Opens input file, finds TTree, initializes it
toroidalVorticitySmog::toroidalVorticitySmog(TTree *tree, int iiFile) : fChain(0) 
{
   iFile = iiFile;

   // Open ROOT file and access DecayFunTuple TTree inside Lambda02PPiLL directory
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(Form("/Volumes/Mike_disc/Maria/Smog2/TurboLambdaLine_pprefLine/Lambda_ppref_%d.root", iFile));
      if (!f || !f->IsOpen()) {
         f = new TFile(Form("/Volumes/Mike_disc/Maria/Smog2/TurboLambdaLine_pprefLine/Lambda_ppref_%d.root", iFile));
      }

      TDirectory *dir = (TDirectory*)f->Get(Form("/Volumes/Mike_disc/Maria/Smog2/TurboLambdaLine_pprefLine/Lambda_ppref_%d.root:/Lambda02PPiLL", iFile));
      dir->GetObject("DecayFunTuple", tree);
   }

   Init(tree); // Set branch addresses
}

// Destructor: Clean up
toroidalVorticitySmog::~toroidalVorticitySmog()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

// GetEntry: Load one event
Int_t toroidalVorticitySmog::GetEntry(Long64_t entry)
{
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}

// LoadTree: Prepare to read one event
Long64_t toroidalVorticitySmog::LoadTree(Long64_t entry)
{
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify(); // Handle tree change
   }
   return centry;
}

// Init: Connect branches in TTree to local variables
void toroidalVorticitySmog::Init(TTree *tree)
{
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   // Connect TTree branches to C++ variables
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("ALLPVX_ERR", ALLPVX_ERR, &b_ALLPVX_ERR);
   fChain->SetBranchAddress("ALLPVY_ERR", ALLPVY_ERR, &b_ALLPVY_ERR);
   fChain->SetBranchAddress("ALLPVZ_ERR", ALLPVZ_ERR, &b_ALLPVZ_ERR);
   fChain->SetBranchAddress("BUNCHCROSSING_ID", &BUNCHCROSSING_ID, &b_BUNCHCROSSING_ID);
   fChain->SetBranchAddress("BUNCHCROSSING_TYPE", &BUNCHCROSSING_TYPE, &b_BUNCHCROSSING_TYPE);
   fChain->SetBranchAddress("EVENTNUMBER", &EVENTNUMBER, &b_EVENTNUMBER);
   fChain->SetBranchAddress("FILLNUMBER", &FILLNUMBER, &b_FILLNUMBER);
   fChain->SetBranchAddress("GPSTIME", &GPSTIME, &b_GPSTIME);
   fChain->SetBranchAddress("Hlt1PassthroughPVinSMOG2Decision", &Hlt1PassthroughPVinSMOG2Decision, &b_Hlt1PassthroughPVinSMOG2Decision);
   fChain->SetBranchAddress("Hlt1SMOG22BodyGenericDecision", &Hlt1SMOG22BodyGenericDecision, &b_Hlt1SMOG22BodyGenericDecision);
   fChain->SetBranchAddress("Hlt1SMOG22BodyGenericPromptDecision", &Hlt1SMOG22BodyGenericPromptDecision, &b_Hlt1SMOG22BodyGenericPromptDecision);
   fChain->SetBranchAddress("Hlt1SMOG2BELowMultElectronsDecision", &Hlt1SMOG2BELowMultElectronsDecision, &b_Hlt1SMOG2BELowMultElectronsDecision);
   fChain->SetBranchAddress("Hlt1SMOG2BENoBiasDecision", &Hlt1SMOG2BENoBiasDecision, &b_Hlt1SMOG2BENoBiasDecision);
   fChain->SetBranchAddress("Hlt1SMOG2D2KpiDecision", &Hlt1SMOG2D2KpiDecision, &b_Hlt1SMOG2D2KpiDecision);
   fChain->SetBranchAddress("Hlt1SMOG2DiMuonHighMassDecision", &Hlt1SMOG2DiMuonHighMassDecision, &b_Hlt1SMOG2DiMuonHighMassDecision);
   fChain->SetBranchAddress("Hlt1SMOG2KsTopipiDecision", &Hlt1SMOG2KsTopipiDecision, &b_Hlt1SMOG2KsTopipiDecision);
   fChain->SetBranchAddress("Hlt1SMOG2L0ToppiDecision", &Hlt1SMOG2L0ToppiDecision, &b_Hlt1SMOG2L0ToppiDecision);
   fChain->SetBranchAddress("Hlt1SMOG2MinimumBiasDecision", &Hlt1SMOG2MinimumBiasDecision, &b_Hlt1SMOG2MinimumBiasDecision);
   fChain->SetBranchAddress("Hlt1SMOG2PassThroughLowMult5Decision", &Hlt1SMOG2PassThroughLowMult5Decision, &b_Hlt1SMOG2PassThroughLowMult5Decision);
   fChain->SetBranchAddress("Hlt1SMOG2SingleMuonDecision", &Hlt1SMOG2SingleMuonDecision, &b_Hlt1SMOG2SingleMuonDecision);
   fChain->SetBranchAddress("Hlt1SMOG2SingleTrackHighPtDecision", &Hlt1SMOG2SingleTrackHighPtDecision, &b_Hlt1SMOG2SingleTrackHighPtDecision);
   fChain->SetBranchAddress("Hlt1SMOG2SingleTrackVeryHighPtDecision", &Hlt1SMOG2SingleTrackVeryHighPtDecision, &b_Hlt1SMOG2SingleTrackVeryHighPtDecision);
   fChain->SetBranchAddress("Hlt1SMOG2etacToppDecision", &Hlt1SMOG2etacToppDecision, &b_Hlt1SMOG2etacToppDecision);
   fChain->SetBranchAddress("Hlt1TrackMVADecision", &Hlt1TrackMVADecision, &b_Hlt1TrackMVADecision);
   fChain->SetBranchAddress("Hlt1TrackMuonMVADecision", &Hlt1TrackMuonMVADecision, &b_Hlt1TrackMuonMVADecision);
   fChain->SetBranchAddress("Hlt1TwoTrackMVADecision", &Hlt1TwoTrackMVADecision, &b_Hlt1TwoTrackMVADecision);
   fChain->SetBranchAddress("Hlt1_TCK", &Hlt1_TCK, &b_Hlt1_TCK);
   fChain->SetBranchAddress("ODINTCK", &ODINTCK, &b_ODINTCK);
   fChain->SetBranchAddress("PVCHI2NDOF", PVCHI2NDOF, &b_PVCHI2NDOF);
   fChain->SetBranchAddress("PVCHI2", PVCHI2, &b_PVCHI2);
   fChain->SetBranchAddress("PVNDOF", PVNDOF, &b_PVNDOF);
   fChain->SetBranchAddress("PVX", PVX, &b_PVX);
   fChain->SetBranchAddress("PVY", PVY, &b_PVY);
   fChain->SetBranchAddress("PVZ", PVZ, &b_PVZ);
   fChain->SetBranchAddress("RUNNUMBER", &RUNNUMBER, &b_RUNNUMBER);
   fChain->SetBranchAddress("SMOGInjectedGas", &SMOGInjectedGas, &b_SMOGInjectedGas);
   fChain->SetBranchAddress("SMOGInjectionMode", &SMOGInjectionMode, &b_SMOGInjectionMode);
   fChain->SetBranchAddress("SMOGInjectionStable", &SMOGInjectionStable, &b_SMOGInjectionStable);
   fChain->SetBranchAddress("eCalTot", &eCalTot, &b_eCalTot);
   fChain->SetBranchAddress("hCalTot", &hCalTot, &b_hCalTot);
   fChain->SetBranchAddress("nBackTracks", &nBackTracks, &b_nBackTracks);
   fChain->SetBranchAddress("nDownTracks", &nDownTracks, &b_nDownTracks);
   fChain->SetBranchAddress("nEcalClusters", &nEcalClusters, &b_nEcalClusters);
   fChain->SetBranchAddress("nFTClusters", &nFTClusters, &b_nFTClusters);
   fChain->SetBranchAddress("nLongTracks", &nLongTracks, &b_nLongTracks);
   fChain->SetBranchAddress("nMuonCoordsS0", &nMuonCoordsS0, &b_nMuonCoordsS0);
   fChain->SetBranchAddress("nMuonCoordsS1", &nMuonCoordsS1, &b_nMuonCoordsS1);
   fChain->SetBranchAddress("nMuonCoordsS2", &nMuonCoordsS2, &b_nMuonCoordsS2);
   fChain->SetBranchAddress("nMuonCoordsS3", &nMuonCoordsS3, &b_nMuonCoordsS3);
   fChain->SetBranchAddress("nMuonCoordsS4", &nMuonCoordsS4, &b_nMuonCoordsS4);
   fChain->SetBranchAddress("nMuonTracks", &nMuonTracks, &b_nMuonTracks);
   fChain->SetBranchAddress("nPVTracks", nPVTracks, &b_nPVTracks);
   fChain->SetBranchAddress("nPVbackTracks", nPVbackTracks, &b_nPVbackTracks);
   fChain->SetBranchAddress("nPVs", &nPVs, &b_nPVs);
   fChain->SetBranchAddress("nRich1Hits", &nRich1Hits, &b_nRich1Hits);
   fChain->SetBranchAddress("nRich2Hits", &nRich2Hits, &b_nRich2Hits);
   fChain->SetBranchAddress("nTTracks", &nTTracks, &b_nTTracks);
   fChain->SetBranchAddress("nTracks", &nTracks, &b_nTracks);
   fChain->SetBranchAddress("nUpTracks", &nUpTracks, &b_nUpTracks);
   fChain->SetBranchAddress("nVPClusters", &nVPClusters, &b_nVPClusters);
   fChain->SetBranchAddress("nVeloClusters", &nVeloClusters, &b_nVeloClusters);
   fChain->SetBranchAddress("nVeloTracks", &nVeloTracks, &b_nVeloTracks);
   fChain->SetBranchAddress("LambdaT_ID", &LambdaT_ID, &b_LambdaT_ID);
   fChain->SetBranchAddress("LambdaT_KEY", &LambdaT_KEY, &b_LambdaT_KEY);
   fChain->SetBranchAddress("LambdaT_CHARGE", &LambdaT_CHARGE, &b_LambdaT_CHARGE);
   fChain->SetBranchAddress("LambdaT_PT", &LambdaT_PT, &b_LambdaT_PT);
   fChain->SetBranchAddress("LambdaT_PX", &LambdaT_PX, &b_LambdaT_PX);
   fChain->SetBranchAddress("LambdaT_PY", &LambdaT_PY, &b_LambdaT_PY);
   fChain->SetBranchAddress("LambdaT_PZ", &LambdaT_PZ, &b_LambdaT_PZ);
   fChain->SetBranchAddress("LambdaT_ETA", &LambdaT_ETA, &b_LambdaT_ETA);
   fChain->SetBranchAddress("LambdaT_PHI", &LambdaT_PHI, &b_LambdaT_PHI);
   fChain->SetBranchAddress("LambdaT_YSTAR", &LambdaT_YSTAR, &b_LambdaT_YSTAR);
   fChain->SetBranchAddress("LambdaT_Y", &LambdaT_Y, &b_LambdaT_Y);
   fChain->SetBranchAddress("LambdaT_MASS", &LambdaT_MASS, &b_LambdaT_MASS);
   fChain->SetBranchAddress("LambdaT_ENERGY", &LambdaT_ENERGY, &b_LambdaT_ENERGY);
   fChain->SetBranchAddress("LambdaT_P", &LambdaT_P, &b_LambdaT_P);
   fChain->SetBranchAddress("LambdaT_FOURMOMENTUME", &LambdaT_FOURMOMENTUME, &b_LambdaT_FOURMOMENTUME);
   fChain->SetBranchAddress("LambdaT_FOURMOMENTUMX", &LambdaT_FOURMOMENTUMX, &b_LambdaT_FOURMOMENTUMX);
   fChain->SetBranchAddress("LambdaT_FOURMOMENTUMY", &LambdaT_FOURMOMENTUMY, &b_LambdaT_FOURMOMENTUMY);
   fChain->SetBranchAddress("LambdaT_FOURMOMENTUMZ", &LambdaT_FOURMOMENTUMZ, &b_LambdaT_FOURMOMENTUMZ);
   fChain->SetBranchAddress("LambdaT_CHI2", &LambdaT_CHI2, &b_LambdaT_CHI2);
   fChain->SetBranchAddress("LambdaT_CHI2DOF", &LambdaT_CHI2DOF, &b_LambdaT_CHI2DOF);
   fChain->SetBranchAddress("LambdaT_B_PV_Z", &LambdaT_B_PV_Z, &b_LambdaT_B_PV_Z);
   fChain->SetBranchAddress("LambdaT_B_PV_X", &LambdaT_B_PV_X, &b_LambdaT_B_PV_X);
   fChain->SetBranchAddress("LambdaT_B_PV_Y", &LambdaT_B_PV_Y, &b_LambdaT_B_PV_Y);
   fChain->SetBranchAddress("LambdaT_BPVIP", &LambdaT_BPVIP, &b_LambdaT_BPVIP);
   fChain->SetBranchAddress("LambdaT_BPVIPCHI2", &LambdaT_BPVIPCHI2, &b_LambdaT_BPVIPCHI2);
   fChain->SetBranchAddress("LambdaT_nBestPVTracks", &LambdaT_nBestPVTracks, &b_LambdaT_nBestPVTracks);
   fChain->SetBranchAddress("LambdaT_nBestPVbackTracks", &LambdaT_nBestPVbackTracks, &b_LambdaT_nBestPVbackTracks);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2D2KpiDecision_TOS", &LambdaT_Hlt1SMOG2D2KpiDecision_TOS, &b_LambdaT_Hlt1SMOG2D2KpiDecision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2etacToppDecision_TOS", &LambdaT_Hlt1SMOG2etacToppDecision_TOS, &b_LambdaT_Hlt1SMOG2etacToppDecision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2L0ToppiDecision_TOS", &LambdaT_Hlt1SMOG2L0ToppiDecision_TOS, &b_LambdaT_Hlt1SMOG2L0ToppiDecision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG22BodyGenericDecision_TOS", &LambdaT_Hlt1SMOG22BodyGenericDecision_TOS, &b_LambdaT_Hlt1SMOG22BodyGenericDecision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1TrackMuonMVADecision_TOS", &LambdaT_Hlt1TrackMuonMVADecision_TOS, &b_LambdaT_Hlt1TrackMuonMVADecision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1TwoTrackMVADecision_TOS", &LambdaT_Hlt1TwoTrackMVADecision_TOS, &b_LambdaT_Hlt1TwoTrackMVADecision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2BELowMultElectronsDecision_TOS", &LambdaT_Hlt1SMOG2BELowMultElectronsDecision_TOS, &b_LambdaT_Hlt1SMOG2BELowMultElectronsDecision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2SingleMuonDecision_TOS", &LambdaT_Hlt1SMOG2SingleMuonDecision_TOS, &b_LambdaT_Hlt1SMOG2SingleMuonDecision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1TrackMVADecision_TOS", &LambdaT_Hlt1TrackMVADecision_TOS, &b_LambdaT_Hlt1TrackMVADecision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2BENoBiasDecision_TOS", &LambdaT_Hlt1SMOG2BENoBiasDecision_TOS, &b_LambdaT_Hlt1SMOG2BENoBiasDecision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG22BodyGenericPromptDecision_TOS", &LambdaT_Hlt1SMOG22BodyGenericPromptDecision_TOS, &b_LambdaT_Hlt1SMOG22BodyGenericPromptDecision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2DiMuonHighMassDecision_TOS", &LambdaT_Hlt1SMOG2DiMuonHighMassDecision_TOS, &b_LambdaT_Hlt1SMOG2DiMuonHighMassDecision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2MinimumBiasDecision_TOS", &LambdaT_Hlt1SMOG2MinimumBiasDecision_TOS, &b_LambdaT_Hlt1SMOG2MinimumBiasDecision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS", &LambdaT_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS, &b_LambdaT_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1PassthroughPVinSMOG2Decision_TOS", &LambdaT_Hlt1PassthroughPVinSMOG2Decision_TOS, &b_LambdaT_Hlt1PassthroughPVinSMOG2Decision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2SingleTrackHighPtDecision_TOS", &LambdaT_Hlt1SMOG2SingleTrackHighPtDecision_TOS, &b_LambdaT_Hlt1SMOG2SingleTrackHighPtDecision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2PassThroughLowMult5Decision_TOS", &LambdaT_Hlt1SMOG2PassThroughLowMult5Decision_TOS, &b_LambdaT_Hlt1SMOG2PassThroughLowMult5Decision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2KsTopipiDecision_TOS", &LambdaT_Hlt1SMOG2KsTopipiDecision_TOS, &b_LambdaT_Hlt1SMOG2KsTopipiDecision_TOS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2D2KpiDecision_TIS", &LambdaT_Hlt1SMOG2D2KpiDecision_TIS, &b_LambdaT_Hlt1SMOG2D2KpiDecision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2etacToppDecision_TIS", &LambdaT_Hlt1SMOG2etacToppDecision_TIS, &b_LambdaT_Hlt1SMOG2etacToppDecision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2L0ToppiDecision_TIS", &LambdaT_Hlt1SMOG2L0ToppiDecision_TIS, &b_LambdaT_Hlt1SMOG2L0ToppiDecision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG22BodyGenericDecision_TIS", &LambdaT_Hlt1SMOG22BodyGenericDecision_TIS, &b_LambdaT_Hlt1SMOG22BodyGenericDecision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1TrackMuonMVADecision_TIS", &LambdaT_Hlt1TrackMuonMVADecision_TIS, &b_LambdaT_Hlt1TrackMuonMVADecision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1TwoTrackMVADecision_TIS", &LambdaT_Hlt1TwoTrackMVADecision_TIS, &b_LambdaT_Hlt1TwoTrackMVADecision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2BELowMultElectronsDecision_TIS", &LambdaT_Hlt1SMOG2BELowMultElectronsDecision_TIS, &b_LambdaT_Hlt1SMOG2BELowMultElectronsDecision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2SingleMuonDecision_TIS", &LambdaT_Hlt1SMOG2SingleMuonDecision_TIS, &b_LambdaT_Hlt1SMOG2SingleMuonDecision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1TrackMVADecision_TIS", &LambdaT_Hlt1TrackMVADecision_TIS, &b_LambdaT_Hlt1TrackMVADecision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2BENoBiasDecision_TIS", &LambdaT_Hlt1SMOG2BENoBiasDecision_TIS, &b_LambdaT_Hlt1SMOG2BENoBiasDecision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG22BodyGenericPromptDecision_TIS", &LambdaT_Hlt1SMOG22BodyGenericPromptDecision_TIS, &b_LambdaT_Hlt1SMOG22BodyGenericPromptDecision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2DiMuonHighMassDecision_TIS", &LambdaT_Hlt1SMOG2DiMuonHighMassDecision_TIS, &b_LambdaT_Hlt1SMOG2DiMuonHighMassDecision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2MinimumBiasDecision_TIS", &LambdaT_Hlt1SMOG2MinimumBiasDecision_TIS, &b_LambdaT_Hlt1SMOG2MinimumBiasDecision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS", &LambdaT_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS, &b_LambdaT_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1PassthroughPVinSMOG2Decision_TIS", &LambdaT_Hlt1PassthroughPVinSMOG2Decision_TIS, &b_LambdaT_Hlt1PassthroughPVinSMOG2Decision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2SingleTrackHighPtDecision_TIS", &LambdaT_Hlt1SMOG2SingleTrackHighPtDecision_TIS, &b_LambdaT_Hlt1SMOG2SingleTrackHighPtDecision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2PassThroughLowMult5Decision_TIS", &LambdaT_Hlt1SMOG2PassThroughLowMult5Decision_TIS, &b_LambdaT_Hlt1SMOG2PassThroughLowMult5Decision_TIS);
   fChain->SetBranchAddress("LambdaT_Hlt1SMOG2KsTopipiDecision_TIS", &LambdaT_Hlt1SMOG2KsTopipiDecision_TIS, &b_LambdaT_Hlt1SMOG2KsTopipiDecision_TIS);
   fChain->SetBranchAddress("LambdaT_DOCA", &LambdaT_DOCA, &b_LambdaT_DOCA);
   fChain->SetBranchAddress("LambdaT_DOCACHI2", &LambdaT_DOCACHI2, &b_LambdaT_DOCACHI2);
   fChain->SetBranchAddress("LambdaT_SDOCA", &LambdaT_SDOCA, &b_LambdaT_SDOCA);
   fChain->SetBranchAddress("LambdaT_SDOCACHI2", &LambdaT_SDOCACHI2, &b_LambdaT_SDOCACHI2);
   fChain->SetBranchAddress("LambdaT_END_VX", &LambdaT_END_VX, &b_LambdaT_END_VX);
   fChain->SetBranchAddress("LambdaT_END_VY", &LambdaT_END_VY, &b_LambdaT_END_VY);
   fChain->SetBranchAddress("LambdaT_END_VZ", &LambdaT_END_VZ, &b_LambdaT_END_VZ);
   fChain->SetBranchAddress("LambdaT_END_VRHO", &LambdaT_END_VRHO, &b_LambdaT_END_VRHO);
   fChain->SetBranchAddress("LambdaT_BPVFDCHI2", &LambdaT_BPVFDCHI2, &b_LambdaT_BPVFDCHI2);
   fChain->SetBranchAddress("LambdaT_BPVLTIME", &LambdaT_BPVLTIME, &b_LambdaT_BPVLTIME);
   fChain->SetBranchAddress("LambdaT_BPVFD", &LambdaT_BPVFD, &b_LambdaT_BPVFD);
   fChain->SetBranchAddress("LambdaT_BPVDIRA", &LambdaT_BPVDIRA, &b_LambdaT_BPVDIRA);
   fChain->SetBranchAddress("pbar_ID", &pbar_ID, &b_pbar_ID);
   fChain->SetBranchAddress("pbar_KEY", &pbar_KEY, &b_pbar_KEY);
   fChain->SetBranchAddress("pbar_CHARGE", &pbar_CHARGE, &b_pbar_CHARGE);
   fChain->SetBranchAddress("pbar_PT", &pbar_PT, &b_pbar_PT);
   fChain->SetBranchAddress("pbar_PX", &pbar_PX, &b_pbar_PX);
   fChain->SetBranchAddress("pbar_PY", &pbar_PY, &b_pbar_PY);
   fChain->SetBranchAddress("pbar_PZ", &pbar_PZ, &b_pbar_PZ);
   fChain->SetBranchAddress("pbar_ETA", &pbar_ETA, &b_pbar_ETA);
   fChain->SetBranchAddress("pbar_PHI", &pbar_PHI, &b_pbar_PHI);
   fChain->SetBranchAddress("pbar_YSTAR", &pbar_YSTAR, &b_pbar_YSTAR);
   fChain->SetBranchAddress("pbar_Y", &pbar_Y, &b_pbar_Y);
   fChain->SetBranchAddress("pbar_MASS", &pbar_MASS, &b_pbar_MASS);
   fChain->SetBranchAddress("pbar_ENERGY", &pbar_ENERGY, &b_pbar_ENERGY);
   fChain->SetBranchAddress("pbar_P", &pbar_P, &b_pbar_P);
   fChain->SetBranchAddress("pbar_FOURMOMENTUME", &pbar_FOURMOMENTUME, &b_pbar_FOURMOMENTUME);
   fChain->SetBranchAddress("pbar_FOURMOMENTUMX", &pbar_FOURMOMENTUMX, &b_pbar_FOURMOMENTUMX);
   fChain->SetBranchAddress("pbar_FOURMOMENTUMY", &pbar_FOURMOMENTUMY, &b_pbar_FOURMOMENTUMY);
   fChain->SetBranchAddress("pbar_FOURMOMENTUMZ", &pbar_FOURMOMENTUMZ, &b_pbar_FOURMOMENTUMZ);
   fChain->SetBranchAddress("pbar_CHI2", &pbar_CHI2, &b_pbar_CHI2);
   fChain->SetBranchAddress("pbar_CHI2DOF", &pbar_CHI2DOF, &b_pbar_CHI2DOF);
   fChain->SetBranchAddress("pbar_B_PV_Z", &pbar_B_PV_Z, &b_pbar_B_PV_Z);
   fChain->SetBranchAddress("pbar_B_PV_X", &pbar_B_PV_X, &b_pbar_B_PV_X);
   fChain->SetBranchAddress("pbar_B_PV_Y", &pbar_B_PV_Y, &b_pbar_B_PV_Y);
   fChain->SetBranchAddress("pbar_BPVIP", &pbar_BPVIP, &b_pbar_BPVIP);
   fChain->SetBranchAddress("pbar_BPVIPCHI2", &pbar_BPVIPCHI2, &b_pbar_BPVIPCHI2);
   fChain->SetBranchAddress("pbar_nBestPVTracks", &pbar_nBestPVTracks, &b_pbar_nBestPVTracks);
   fChain->SetBranchAddress("pbar_nBestPVbackTracks", &pbar_nBestPVbackTracks, &b_pbar_nBestPVbackTracks);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2D2KpiDecision_TOS", &pbar_Hlt1SMOG2D2KpiDecision_TOS, &b_pbar_Hlt1SMOG2D2KpiDecision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2etacToppDecision_TOS", &pbar_Hlt1SMOG2etacToppDecision_TOS, &b_pbar_Hlt1SMOG2etacToppDecision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2L0ToppiDecision_TOS", &pbar_Hlt1SMOG2L0ToppiDecision_TOS, &b_pbar_Hlt1SMOG2L0ToppiDecision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG22BodyGenericDecision_TOS", &pbar_Hlt1SMOG22BodyGenericDecision_TOS, &b_pbar_Hlt1SMOG22BodyGenericDecision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1TrackMuonMVADecision_TOS", &pbar_Hlt1TrackMuonMVADecision_TOS, &b_pbar_Hlt1TrackMuonMVADecision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1TwoTrackMVADecision_TOS", &pbar_Hlt1TwoTrackMVADecision_TOS, &b_pbar_Hlt1TwoTrackMVADecision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2BELowMultElectronsDecision_TOS", &pbar_Hlt1SMOG2BELowMultElectronsDecision_TOS, &b_pbar_Hlt1SMOG2BELowMultElectronsDecision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2SingleMuonDecision_TOS", &pbar_Hlt1SMOG2SingleMuonDecision_TOS, &b_pbar_Hlt1SMOG2SingleMuonDecision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1TrackMVADecision_TOS", &pbar_Hlt1TrackMVADecision_TOS, &b_pbar_Hlt1TrackMVADecision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2BENoBiasDecision_TOS", &pbar_Hlt1SMOG2BENoBiasDecision_TOS, &b_pbar_Hlt1SMOG2BENoBiasDecision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG22BodyGenericPromptDecision_TOS", &pbar_Hlt1SMOG22BodyGenericPromptDecision_TOS, &b_pbar_Hlt1SMOG22BodyGenericPromptDecision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2DiMuonHighMassDecision_TOS", &pbar_Hlt1SMOG2DiMuonHighMassDecision_TOS, &b_pbar_Hlt1SMOG2DiMuonHighMassDecision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2MinimumBiasDecision_TOS", &pbar_Hlt1SMOG2MinimumBiasDecision_TOS, &b_pbar_Hlt1SMOG2MinimumBiasDecision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS", &pbar_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS, &b_pbar_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1PassthroughPVinSMOG2Decision_TOS", &pbar_Hlt1PassthroughPVinSMOG2Decision_TOS, &b_pbar_Hlt1PassthroughPVinSMOG2Decision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2SingleTrackHighPtDecision_TOS", &pbar_Hlt1SMOG2SingleTrackHighPtDecision_TOS, &b_pbar_Hlt1SMOG2SingleTrackHighPtDecision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2PassThroughLowMult5Decision_TOS", &pbar_Hlt1SMOG2PassThroughLowMult5Decision_TOS, &b_pbar_Hlt1SMOG2PassThroughLowMult5Decision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2KsTopipiDecision_TOS", &pbar_Hlt1SMOG2KsTopipiDecision_TOS, &b_pbar_Hlt1SMOG2KsTopipiDecision_TOS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2D2KpiDecision_TIS", &pbar_Hlt1SMOG2D2KpiDecision_TIS, &b_pbar_Hlt1SMOG2D2KpiDecision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2etacToppDecision_TIS", &pbar_Hlt1SMOG2etacToppDecision_TIS, &b_pbar_Hlt1SMOG2etacToppDecision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2L0ToppiDecision_TIS", &pbar_Hlt1SMOG2L0ToppiDecision_TIS, &b_pbar_Hlt1SMOG2L0ToppiDecision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG22BodyGenericDecision_TIS", &pbar_Hlt1SMOG22BodyGenericDecision_TIS, &b_pbar_Hlt1SMOG22BodyGenericDecision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1TrackMuonMVADecision_TIS", &pbar_Hlt1TrackMuonMVADecision_TIS, &b_pbar_Hlt1TrackMuonMVADecision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1TwoTrackMVADecision_TIS", &pbar_Hlt1TwoTrackMVADecision_TIS, &b_pbar_Hlt1TwoTrackMVADecision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2BELowMultElectronsDecision_TIS", &pbar_Hlt1SMOG2BELowMultElectronsDecision_TIS, &b_pbar_Hlt1SMOG2BELowMultElectronsDecision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2SingleMuonDecision_TIS", &pbar_Hlt1SMOG2SingleMuonDecision_TIS, &b_pbar_Hlt1SMOG2SingleMuonDecision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1TrackMVADecision_TIS", &pbar_Hlt1TrackMVADecision_TIS, &b_pbar_Hlt1TrackMVADecision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2BENoBiasDecision_TIS", &pbar_Hlt1SMOG2BENoBiasDecision_TIS, &b_pbar_Hlt1SMOG2BENoBiasDecision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG22BodyGenericPromptDecision_TIS", &pbar_Hlt1SMOG22BodyGenericPromptDecision_TIS, &b_pbar_Hlt1SMOG22BodyGenericPromptDecision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2DiMuonHighMassDecision_TIS", &pbar_Hlt1SMOG2DiMuonHighMassDecision_TIS, &b_pbar_Hlt1SMOG2DiMuonHighMassDecision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2MinimumBiasDecision_TIS", &pbar_Hlt1SMOG2MinimumBiasDecision_TIS, &b_pbar_Hlt1SMOG2MinimumBiasDecision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS", &pbar_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS, &b_pbar_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1PassthroughPVinSMOG2Decision_TIS", &pbar_Hlt1PassthroughPVinSMOG2Decision_TIS, &b_pbar_Hlt1PassthroughPVinSMOG2Decision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2SingleTrackHighPtDecision_TIS", &pbar_Hlt1SMOG2SingleTrackHighPtDecision_TIS, &b_pbar_Hlt1SMOG2SingleTrackHighPtDecision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2PassThroughLowMult5Decision_TIS", &pbar_Hlt1SMOG2PassThroughLowMult5Decision_TIS, &b_pbar_Hlt1SMOG2PassThroughLowMult5Decision_TIS);
   fChain->SetBranchAddress("pbar_Hlt1SMOG2KsTopipiDecision_TIS", &pbar_Hlt1SMOG2KsTopipiDecision_TIS, &b_pbar_Hlt1SMOG2KsTopipiDecision_TIS);
   fChain->SetBranchAddress("pbar_PIDE", &pbar_PIDE, &b_pbar_PIDE);
   fChain->SetBranchAddress("pbar_PIDK", &pbar_PIDK, &b_pbar_PIDK);
   fChain->SetBranchAddress("pbar_PIDMU", &pbar_PIDMU, &b_pbar_PIDMU);
   fChain->SetBranchAddress("pbar_PIDP", &pbar_PIDP, &b_pbar_PIDP);
   fChain->SetBranchAddress("pbar_PIDPI", &pbar_PIDPI, &b_pbar_PIDPI);
   fChain->SetBranchAddress("pbar_PROBNNE", &pbar_PROBNNE, &b_pbar_PROBNNE);
   fChain->SetBranchAddress("pbar_PROBNNK", &pbar_PROBNNK, &b_pbar_PROBNNK);
   fChain->SetBranchAddress("pbar_PROBNNMU", &pbar_PROBNNMU, &b_pbar_PROBNNMU);
   fChain->SetBranchAddress("pbar_PROBNNP", &pbar_PROBNNP, &b_pbar_PROBNNP);
   fChain->SetBranchAddress("pbar_PROBNNPI", &pbar_PROBNNPI, &b_pbar_PROBNNPI);
   fChain->SetBranchAddress("pbar_PROBNNGHOST", &pbar_PROBNNGHOST, &b_pbar_PROBNNGHOST);
   fChain->SetBranchAddress("pbar_PROBNND", &pbar_PROBNND, &b_pbar_PROBNND);
   fChain->SetBranchAddress("pbar_GHOSTPROB", &pbar_GHOSTPROB, &b_pbar_GHOSTPROB);
   fChain->SetBranchAddress("pbar_ISMUON", &pbar_ISMUON, &b_pbar_ISMUON);
   fChain->SetBranchAddress("pbar_IS_NOT_H", &pbar_IS_NOT_H, &b_pbar_IS_NOT_H);
   fChain->SetBranchAddress("pbar_IS_PHOTON", &pbar_IS_PHOTON, &b_pbar_IS_PHOTON);
   fChain->SetBranchAddress("pbar_TRACK_NVPHITS", &pbar_TRACK_NVPHITS, &b_pbar_TRACK_NVPHITS);
   fChain->SetBranchAddress("pbar_TRACK_NFTHITS", &pbar_TRACK_NFTHITS, &b_pbar_TRACK_NFTHITS);
   fChain->SetBranchAddress("pbar_TRACK_NUTHITS", &pbar_TRACK_NUTHITS, &b_pbar_TRACK_NUTHITS);
   fChain->SetBranchAddress("pbar_TRACK_POS_CLOSESTTOBEAM_X", &pbar_TRACK_POS_CLOSESTTOBEAM_X, &b_pbar_TRACK_POS_CLOSESTTOBEAM_X);
   fChain->SetBranchAddress("pbar_TRACK_POS_CLOSESTTOBEAM_Y", &pbar_TRACK_POS_CLOSESTTOBEAM_Y, &b_pbar_TRACK_POS_CLOSESTTOBEAM_Y);
   fChain->SetBranchAddress("pbar_TRACK_POS_CLOSESTTOBEAM_Z", &pbar_TRACK_POS_CLOSESTTOBEAM_Z, &b_pbar_TRACK_POS_CLOSESTTOBEAM_Z);
   fChain->SetBranchAddress("pim_ID", &pim_ID, &b_pim_ID);
   fChain->SetBranchAddress("pim_KEY", &pim_KEY, &b_pim_KEY);
   fChain->SetBranchAddress("pim_CHARGE", &pim_CHARGE, &b_pim_CHARGE);
   fChain->SetBranchAddress("pim_PT", &pim_PT, &b_pim_PT);
   fChain->SetBranchAddress("pim_PX", &pim_PX, &b_pim_PX);
   fChain->SetBranchAddress("pim_PY", &pim_PY, &b_pim_PY);
   fChain->SetBranchAddress("pim_PZ", &pim_PZ, &b_pim_PZ);
   fChain->SetBranchAddress("pim_ETA", &pim_ETA, &b_pim_ETA);
   fChain->SetBranchAddress("pim_PHI", &pim_PHI, &b_pim_PHI);
   fChain->SetBranchAddress("pim_YSTAR", &pim_YSTAR, &b_pim_YSTAR);
   fChain->SetBranchAddress("pim_Y", &pim_Y, &b_pim_Y);
   fChain->SetBranchAddress("pim_MASS", &pim_MASS, &b_pim_MASS);
   fChain->SetBranchAddress("pim_ENERGY", &pim_ENERGY, &b_pim_ENERGY);
   fChain->SetBranchAddress("pim_P", &pim_P, &b_pim_P);
   fChain->SetBranchAddress("pim_FOURMOMENTUME", &pim_FOURMOMENTUME, &b_pim_FOURMOMENTUME);
   fChain->SetBranchAddress("pim_FOURMOMENTUMX", &pim_FOURMOMENTUMX, &b_pim_FOURMOMENTUMX);
   fChain->SetBranchAddress("pim_FOURMOMENTUMY", &pim_FOURMOMENTUMY, &b_pim_FOURMOMENTUMY);
   fChain->SetBranchAddress("pim_FOURMOMENTUMZ", &pim_FOURMOMENTUMZ, &b_pim_FOURMOMENTUMZ);
   fChain->SetBranchAddress("pim_CHI2", &pim_CHI2, &b_pim_CHI2);
   fChain->SetBranchAddress("pim_CHI2DOF", &pim_CHI2DOF, &b_pim_CHI2DOF);
   fChain->SetBranchAddress("pim_B_PV_Z", &pim_B_PV_Z, &b_pim_B_PV_Z);
   fChain->SetBranchAddress("pim_B_PV_X", &pim_B_PV_X, &b_pim_B_PV_X);
   fChain->SetBranchAddress("pim_B_PV_Y", &pim_B_PV_Y, &b_pim_B_PV_Y);
   fChain->SetBranchAddress("pim_BPVIP", &pim_BPVIP, &b_pim_BPVIP);
   fChain->SetBranchAddress("pim_BPVIPCHI2", &pim_BPVIPCHI2, &b_pim_BPVIPCHI2);
   fChain->SetBranchAddress("pim_nBestPVTracks", &pim_nBestPVTracks, &b_pim_nBestPVTracks);
   fChain->SetBranchAddress("pim_nBestPVbackTracks", &pim_nBestPVbackTracks, &b_pim_nBestPVbackTracks);
   fChain->SetBranchAddress("pim_Hlt1SMOG2D2KpiDecision_TOS", &pim_Hlt1SMOG2D2KpiDecision_TOS, &b_pim_Hlt1SMOG2D2KpiDecision_TOS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2etacToppDecision_TOS", &pim_Hlt1SMOG2etacToppDecision_TOS, &b_pim_Hlt1SMOG2etacToppDecision_TOS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2L0ToppiDecision_TOS", &pim_Hlt1SMOG2L0ToppiDecision_TOS, &b_pim_Hlt1SMOG2L0ToppiDecision_TOS);
   fChain->SetBranchAddress("pim_Hlt1SMOG22BodyGenericDecision_TOS", &pim_Hlt1SMOG22BodyGenericDecision_TOS, &b_pim_Hlt1SMOG22BodyGenericDecision_TOS);
   fChain->SetBranchAddress("pim_Hlt1TrackMuonMVADecision_TOS", &pim_Hlt1TrackMuonMVADecision_TOS, &b_pim_Hlt1TrackMuonMVADecision_TOS);
   fChain->SetBranchAddress("pim_Hlt1TwoTrackMVADecision_TOS", &pim_Hlt1TwoTrackMVADecision_TOS, &b_pim_Hlt1TwoTrackMVADecision_TOS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2BELowMultElectronsDecision_TOS", &pim_Hlt1SMOG2BELowMultElectronsDecision_TOS, &b_pim_Hlt1SMOG2BELowMultElectronsDecision_TOS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2SingleMuonDecision_TOS", &pim_Hlt1SMOG2SingleMuonDecision_TOS, &b_pim_Hlt1SMOG2SingleMuonDecision_TOS);
   fChain->SetBranchAddress("pim_Hlt1TrackMVADecision_TOS", &pim_Hlt1TrackMVADecision_TOS, &b_pim_Hlt1TrackMVADecision_TOS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2BENoBiasDecision_TOS", &pim_Hlt1SMOG2BENoBiasDecision_TOS, &b_pim_Hlt1SMOG2BENoBiasDecision_TOS);
   fChain->SetBranchAddress("pim_Hlt1SMOG22BodyGenericPromptDecision_TOS", &pim_Hlt1SMOG22BodyGenericPromptDecision_TOS, &b_pim_Hlt1SMOG22BodyGenericPromptDecision_TOS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2DiMuonHighMassDecision_TOS", &pim_Hlt1SMOG2DiMuonHighMassDecision_TOS, &b_pim_Hlt1SMOG2DiMuonHighMassDecision_TOS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2MinimumBiasDecision_TOS", &pim_Hlt1SMOG2MinimumBiasDecision_TOS, &b_pim_Hlt1SMOG2MinimumBiasDecision_TOS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS", &pim_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS, &b_pim_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS);
   fChain->SetBranchAddress("pim_Hlt1PassthroughPVinSMOG2Decision_TOS", &pim_Hlt1PassthroughPVinSMOG2Decision_TOS, &b_pim_Hlt1PassthroughPVinSMOG2Decision_TOS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2SingleTrackHighPtDecision_TOS", &pim_Hlt1SMOG2SingleTrackHighPtDecision_TOS, &b_pim_Hlt1SMOG2SingleTrackHighPtDecision_TOS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2PassThroughLowMult5Decision_TOS", &pim_Hlt1SMOG2PassThroughLowMult5Decision_TOS, &b_pim_Hlt1SMOG2PassThroughLowMult5Decision_TOS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2KsTopipiDecision_TOS", &pim_Hlt1SMOG2KsTopipiDecision_TOS, &b_pim_Hlt1SMOG2KsTopipiDecision_TOS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2D2KpiDecision_TIS", &pim_Hlt1SMOG2D2KpiDecision_TIS, &b_pim_Hlt1SMOG2D2KpiDecision_TIS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2etacToppDecision_TIS", &pim_Hlt1SMOG2etacToppDecision_TIS, &b_pim_Hlt1SMOG2etacToppDecision_TIS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2L0ToppiDecision_TIS", &pim_Hlt1SMOG2L0ToppiDecision_TIS, &b_pim_Hlt1SMOG2L0ToppiDecision_TIS);
   fChain->SetBranchAddress("pim_Hlt1SMOG22BodyGenericDecision_TIS", &pim_Hlt1SMOG22BodyGenericDecision_TIS, &b_pim_Hlt1SMOG22BodyGenericDecision_TIS);
   fChain->SetBranchAddress("pim_Hlt1TrackMuonMVADecision_TIS", &pim_Hlt1TrackMuonMVADecision_TIS, &b_pim_Hlt1TrackMuonMVADecision_TIS);
   fChain->SetBranchAddress("pim_Hlt1TwoTrackMVADecision_TIS", &pim_Hlt1TwoTrackMVADecision_TIS, &b_pim_Hlt1TwoTrackMVADecision_TIS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2BELowMultElectronsDecision_TIS", &pim_Hlt1SMOG2BELowMultElectronsDecision_TIS, &b_pim_Hlt1SMOG2BELowMultElectronsDecision_TIS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2SingleMuonDecision_TIS", &pim_Hlt1SMOG2SingleMuonDecision_TIS, &b_pim_Hlt1SMOG2SingleMuonDecision_TIS);
   fChain->SetBranchAddress("pim_Hlt1TrackMVADecision_TIS", &pim_Hlt1TrackMVADecision_TIS, &b_pim_Hlt1TrackMVADecision_TIS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2BENoBiasDecision_TIS", &pim_Hlt1SMOG2BENoBiasDecision_TIS, &b_pim_Hlt1SMOG2BENoBiasDecision_TIS);
   fChain->SetBranchAddress("pim_Hlt1SMOG22BodyGenericPromptDecision_TIS", &pim_Hlt1SMOG22BodyGenericPromptDecision_TIS, &b_pim_Hlt1SMOG22BodyGenericPromptDecision_TIS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2DiMuonHighMassDecision_TIS", &pim_Hlt1SMOG2DiMuonHighMassDecision_TIS, &b_pim_Hlt1SMOG2DiMuonHighMassDecision_TIS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2MinimumBiasDecision_TIS", &pim_Hlt1SMOG2MinimumBiasDecision_TIS, &b_pim_Hlt1SMOG2MinimumBiasDecision_TIS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS", &pim_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS, &b_pim_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS);
   fChain->SetBranchAddress("pim_Hlt1PassthroughPVinSMOG2Decision_TIS", &pim_Hlt1PassthroughPVinSMOG2Decision_TIS, &b_pim_Hlt1PassthroughPVinSMOG2Decision_TIS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2SingleTrackHighPtDecision_TIS", &pim_Hlt1SMOG2SingleTrackHighPtDecision_TIS, &b_pim_Hlt1SMOG2SingleTrackHighPtDecision_TIS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2PassThroughLowMult5Decision_TIS", &pim_Hlt1SMOG2PassThroughLowMult5Decision_TIS, &b_pim_Hlt1SMOG2PassThroughLowMult5Decision_TIS);
   fChain->SetBranchAddress("pim_Hlt1SMOG2KsTopipiDecision_TIS", &pim_Hlt1SMOG2KsTopipiDecision_TIS, &b_pim_Hlt1SMOG2KsTopipiDecision_TIS);
   fChain->SetBranchAddress("pim_PIDE", &pim_PIDE, &b_pim_PIDE);
   fChain->SetBranchAddress("pim_PIDK", &pim_PIDK, &b_pim_PIDK);
   fChain->SetBranchAddress("pim_PIDMU", &pim_PIDMU, &b_pim_PIDMU);
   fChain->SetBranchAddress("pim_PIDP", &pim_PIDP, &b_pim_PIDP);
   fChain->SetBranchAddress("pim_PIDPI", &pim_PIDPI, &b_pim_PIDPI);
   fChain->SetBranchAddress("pim_PROBNNE", &pim_PROBNNE, &b_pim_PROBNNE);
   fChain->SetBranchAddress("pim_PROBNNK", &pim_PROBNNK, &b_pim_PROBNNK);
   fChain->SetBranchAddress("pim_PROBNNMU", &pim_PROBNNMU, &b_pim_PROBNNMU);
   fChain->SetBranchAddress("pim_PROBNNP", &pim_PROBNNP, &b_pim_PROBNNP);
   fChain->SetBranchAddress("pim_PROBNNPI", &pim_PROBNNPI, &b_pim_PROBNNPI);
   fChain->SetBranchAddress("pim_PROBNNGHOST", &pim_PROBNNGHOST, &b_pim_PROBNNGHOST);
   fChain->SetBranchAddress("pim_PROBNND", &pim_PROBNND, &b_pim_PROBNND);
   fChain->SetBranchAddress("pim_GHOSTPROB", &pim_GHOSTPROB, &b_pim_GHOSTPROB);
   fChain->SetBranchAddress("pim_ISMUON", &pim_ISMUON, &b_pim_ISMUON);
   fChain->SetBranchAddress("pim_IS_NOT_H", &pim_IS_NOT_H, &b_pim_IS_NOT_H);
   fChain->SetBranchAddress("pim_IS_PHOTON", &pim_IS_PHOTON, &b_pim_IS_PHOTON);
   fChain->SetBranchAddress("pim_TRACK_NVPHITS", &pim_TRACK_NVPHITS, &b_pim_TRACK_NVPHITS);
   fChain->SetBranchAddress("pim_TRACK_NFTHITS", &pim_TRACK_NFTHITS, &b_pim_TRACK_NFTHITS);
   fChain->SetBranchAddress("pim_TRACK_NUTHITS", &pim_TRACK_NUTHITS, &b_pim_TRACK_NUTHITS);
   fChain->SetBranchAddress("pim_TRACK_POS_CLOSESTTOBEAM_X", &pim_TRACK_POS_CLOSESTTOBEAM_X, &b_pim_TRACK_POS_CLOSESTTOBEAM_X);
   fChain->SetBranchAddress("pim_TRACK_POS_CLOSESTTOBEAM_Y", &pim_TRACK_POS_CLOSESTTOBEAM_Y, &b_pim_TRACK_POS_CLOSESTTOBEAM_Y);
  fChain->SetBranchAddress("pim_TRACK_POS_CLOSESTTOBEAM_Z", &pim_TRACK_POS_CLOSESTTOBEAM_Z, &b_pim_TRACK_POS_CLOSESTTOBEAM_Z);
   Notify(); // Call Notify after initializing
}

// Notify: Called when switching input files or TTrees
bool toroidalVorticitySmog::Notify()
{
   return true;
}

// Show: Print all variables of an entry
void toroidalVorticitySmog::Show(Long64_t entry)
{
   if (!fChain) return;
   fChain->Show(entry);
}

// Cut: Event filter (currently accepts all)
Int_t toroidalVorticitySmog::Cut(Long64_t entry)
{
   return 1;
}

// CheckSister: Find nearby "sister" Lambda candidates in the same event
bool toroidalVorticitySmog::CheckSister(int nrentreis, int jent, float pi_pt, float pro_pt, double lambda_quality, int runnr)
{
   int betterSister = 1;

   // If this candidate is early in list, only check forward sisters
   if (jent < 3){
      for(int i = jent+1; i < jent+3; i++){
         fChain->GetEntry(i);
         if ((pim_PT == pi_pt || pbar_PT == pro_pt) && LambdaT_DOCACHI2 < lambda_quality) {
            betterSister = 0; break;
         }
      }
   }
   // If candidate is late in list, only check backward sisters
   else if (nrentreis - jent < 3){
      for(int i = jent-3; i < jent; i++){
         fChain->GetEntry(i);
         if ((pim_PT == pi_pt || pbar_PT == pro_pt) && LambdaT_DOCACHI2 < lambda_quality) {
            betterSister = 0; break;
         }
      }
   }
   // Check both sides for middle-of-list entries
   else {
      for(int i = jent-3; i < jent+3; i++){
         if(i == jent) continue;
         fChain->GetEntry(i);
         if (runnr == RUNNUMBER && (pim_PT == pi_pt || pbar_PT == pro_pt) && LambdaT_DOCACHI2 < lambda_quality) {
            betterSister = 0; break;
         }
      }
   }

   // Return true if no better sister found
   return betterSister == 1;
}

#endif // #ifdef toroidalVorticitySmog_cxx