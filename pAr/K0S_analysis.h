//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jan 27 14:54:24 2025 by ROOT version 6.32.08
// from TTree DecayFunTuple/DecayFunTuple
// found on file: K0S_ppref.root
//
// This class provides an interface to loop over and analyze
// entries in the DecayFunTuple TTree from a K0S -> pi+ pi- analysis.
// It includes initialization, file loading, entry access,
// and a function (CheckSister) to identify the best candidate
// among nearby entries for given selection criteria.
//
// Custom analysis code should go inside the Loop() function.
//
// Author: ROOT / User modifications by Maria
//////////////////////////////////////////////////////////


#ifndef K0S_analysis_h
#define K0S_analysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
#include "TVector2.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TProfile.h"

// Main analysis class
class K0S_analysis {
public :
   TTree          *fChain;   //! pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //! current Tree number in a TChain

   // === Leaf declarations ===
   ULong64_t       totCandidates;       // total number of candidates in event
   UInt_t          nCandidate;          // number of K0S candidates
   Int_t           nPV;                 // number of primary vertices
   Float_t         ALLPVX_ERR[10000];   // error in X of PVs (size nPV)
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
   Int_t           KS0_ID;
   Int_t           KS0_KEY;
   Int_t           KS0_CHARGE;
   Float_t         KS0_PT;
   Float_t         KS0_PX;
   Float_t         KS0_PY;
   Float_t         KS0_PZ;
   Float_t         KS0_ETA;
   Float_t         KS0_PHI;
   Float_t         KS0_YSTAR;
   Float_t         KS0_Y;
   Double_t        KS0_MASS;
   Float_t         KS0_ENERGY;
   Float_t         KS0_P;
   Double_t        KS0_FOURMOMENTUME;
   Double_t        KS0_FOURMOMENTUMX;
   Double_t        KS0_FOURMOMENTUMY;
   Double_t        KS0_FOURMOMENTUMZ;
   Double_t        KS0_CHI2;
   Double_t        KS0_CHI2DOF;
   Float_t         KS0_B_PV_Z;
   Float_t         KS0_B_PV_X;
   Float_t         KS0_B_PV_Y;
   Float_t         KS0_BPVIP;
   Float_t         KS0_BPVIPCHI2;
   Int_t           KS0_nBestPVTracks;
   Int_t           KS0_nBestPVbackTracks;
   Bool_t          KS0_Hlt1SMOG2D2KpiDecision_TOS;
   Bool_t          KS0_Hlt1SMOG2etacToppDecision_TOS;
   Bool_t          KS0_Hlt1SMOG2L0ToppiDecision_TOS;
   Bool_t          KS0_Hlt1SMOG22BodyGenericDecision_TOS;
   Bool_t          KS0_Hlt1TrackMuonMVADecision_TOS;
   Bool_t          KS0_Hlt1TwoTrackMVADecision_TOS;
   Bool_t          KS0_Hlt1SMOG2BELowMultElectronsDecision_TOS;
   Bool_t          KS0_Hlt1SMOG2SingleMuonDecision_TOS;
   Bool_t          KS0_Hlt1TrackMVADecision_TOS;
   Bool_t          KS0_Hlt1SMOG2BENoBiasDecision_TOS;
   Bool_t          KS0_Hlt1SMOG22BodyGenericPromptDecision_TOS;
   Bool_t          KS0_Hlt1SMOG2DiMuonHighMassDecision_TOS;
   Bool_t          KS0_Hlt1SMOG2MinimumBiasDecision_TOS;
   Bool_t          KS0_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS;
   Bool_t          KS0_Hlt1PassthroughPVinSMOG2Decision_TOS;
   Bool_t          KS0_Hlt1SMOG2SingleTrackHighPtDecision_TOS;
   Bool_t          KS0_Hlt1SMOG2PassThroughLowMult5Decision_TOS;
   Bool_t          KS0_Hlt1SMOG2KsTopipiDecision_TOS;
   Bool_t          KS0_Hlt1SMOG2D2KpiDecision_TIS;
   Bool_t          KS0_Hlt1SMOG2etacToppDecision_TIS;
   Bool_t          KS0_Hlt1SMOG2L0ToppiDecision_TIS;
   Bool_t          KS0_Hlt1SMOG22BodyGenericDecision_TIS;
   Bool_t          KS0_Hlt1TrackMuonMVADecision_TIS;
   Bool_t          KS0_Hlt1TwoTrackMVADecision_TIS;
   Bool_t          KS0_Hlt1SMOG2BELowMultElectronsDecision_TIS;
   Bool_t          KS0_Hlt1SMOG2SingleMuonDecision_TIS;
   Bool_t          KS0_Hlt1TrackMVADecision_TIS;
   Bool_t          KS0_Hlt1SMOG2BENoBiasDecision_TIS;
   Bool_t          KS0_Hlt1SMOG22BodyGenericPromptDecision_TIS;
   Bool_t          KS0_Hlt1SMOG2DiMuonHighMassDecision_TIS;
   Bool_t          KS0_Hlt1SMOG2MinimumBiasDecision_TIS;
   Bool_t          KS0_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS;
   Bool_t          KS0_Hlt1PassthroughPVinSMOG2Decision_TIS;
   Bool_t          KS0_Hlt1SMOG2SingleTrackHighPtDecision_TIS;
   Bool_t          KS0_Hlt1SMOG2PassThroughLowMult5Decision_TIS;
   Bool_t          KS0_Hlt1SMOG2KsTopipiDecision_TIS;
   Double_t        KS0_DOCA;
   Double_t        KS0_DOCACHI2;
   Float_t         KS0_SDOCA;
   Float_t         KS0_SDOCACHI2;
   Float_t         KS0_END_VX;
   Float_t         KS0_END_VY;
   Float_t         KS0_END_VZ;
   Float_t         KS0_END_VRHO;
   Float_t         KS0_BPVFDCHI2;
   Float_t         KS0_BPVLTIME;
   Float_t         KS0_BPVFD;
   Float_t         KS0_BPVDIRA;
   Int_t           pip_ID;
   Int_t           pip_KEY;
   Int_t           pip_CHARGE;
   Float_t         pip_PT;
   Float_t         pip_PX;
   Float_t         pip_PY;
   Float_t         pip_PZ;
   Float_t         pip_ETA;
   Float_t         pip_PHI;
   Float_t         pip_YSTAR;
   Float_t         pip_Y;
   Double_t        pip_MASS;
   Float_t         pip_ENERGY;
   Float_t         pip_P;
   Double_t        pip_FOURMOMENTUME;
   Double_t        pip_FOURMOMENTUMX;
   Double_t        pip_FOURMOMENTUMY;
   Double_t        pip_FOURMOMENTUMZ;
   Double_t        pip_CHI2;
   Double_t        pip_CHI2DOF;
   Float_t         pip_B_PV_Z;
   Float_t         pip_B_PV_X;
   Float_t         pip_B_PV_Y;
   Float_t         pip_BPVIP;
   Float_t         pip_BPVIPCHI2;
   Int_t           pip_nBestPVTracks;
   Int_t           pip_nBestPVbackTracks;
   Bool_t          pip_Hlt1SMOG2D2KpiDecision_TOS;
   Bool_t          pip_Hlt1SMOG2etacToppDecision_TOS;
   Bool_t          pip_Hlt1SMOG2L0ToppiDecision_TOS;
   Bool_t          pip_Hlt1SMOG22BodyGenericDecision_TOS;
   Bool_t          pip_Hlt1TrackMuonMVADecision_TOS;
   Bool_t          pip_Hlt1TwoTrackMVADecision_TOS;
   Bool_t          pip_Hlt1SMOG2BELowMultElectronsDecision_TOS;
   Bool_t          pip_Hlt1SMOG2SingleMuonDecision_TOS;
   Bool_t          pip_Hlt1TrackMVADecision_TOS;
   Bool_t          pip_Hlt1SMOG2BENoBiasDecision_TOS;
   Bool_t          pip_Hlt1SMOG22BodyGenericPromptDecision_TOS;
   Bool_t          pip_Hlt1SMOG2DiMuonHighMassDecision_TOS;
   Bool_t          pip_Hlt1SMOG2MinimumBiasDecision_TOS;
   Bool_t          pip_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS;
   Bool_t          pip_Hlt1PassthroughPVinSMOG2Decision_TOS;
   Bool_t          pip_Hlt1SMOG2SingleTrackHighPtDecision_TOS;
   Bool_t          pip_Hlt1SMOG2PassThroughLowMult5Decision_TOS;
   Bool_t          pip_Hlt1SMOG2KsTopipiDecision_TOS;
   Bool_t          pip_Hlt1SMOG2D2KpiDecision_TIS;
   Bool_t          pip_Hlt1SMOG2etacToppDecision_TIS;
   Bool_t          pip_Hlt1SMOG2L0ToppiDecision_TIS;
   Bool_t          pip_Hlt1SMOG22BodyGenericDecision_TIS;
   Bool_t          pip_Hlt1TrackMuonMVADecision_TIS;
   Bool_t          pip_Hlt1TwoTrackMVADecision_TIS;
   Bool_t          pip_Hlt1SMOG2BELowMultElectronsDecision_TIS;
   Bool_t          pip_Hlt1SMOG2SingleMuonDecision_TIS;
   Bool_t          pip_Hlt1TrackMVADecision_TIS;
   Bool_t          pip_Hlt1SMOG2BENoBiasDecision_TIS;
   Bool_t          pip_Hlt1SMOG22BodyGenericPromptDecision_TIS;
   Bool_t          pip_Hlt1SMOG2DiMuonHighMassDecision_TIS;
   Bool_t          pip_Hlt1SMOG2MinimumBiasDecision_TIS;
   Bool_t          pip_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS;
   Bool_t          pip_Hlt1PassthroughPVinSMOG2Decision_TIS;
   Bool_t          pip_Hlt1SMOG2SingleTrackHighPtDecision_TIS;
   Bool_t          pip_Hlt1SMOG2PassThroughLowMult5Decision_TIS;
   Bool_t          pip_Hlt1SMOG2KsTopipiDecision_TIS;
   Float_t         pip_PIDE;
   Float_t         pip_PIDK;
   Float_t         pip_PIDMU;
   Float_t         pip_PIDP;
   Float_t         pip_PIDPI;
   Float_t         pip_PROBNNE;
   Float_t         pip_PROBNNK;
   Float_t         pip_PROBNNMU;
   Float_t         pip_PROBNNP;
   Float_t         pip_PROBNNPI;
   Float_t         pip_PROBNNGHOST;
   Float_t         pip_PROBNND;
   Double_t        pip_GHOSTPROB;
   Bool_t          pip_ISMUON;
   Float_t         pip_IS_NOT_H;
   Float_t         pip_IS_PHOTON;
   Int_t           pip_TRACK_NVPHITS;
   Int_t           pip_TRACK_NFTHITS;
   Int_t           pip_TRACK_NUTHITS;
   Double_t        pip_TRACK_POS_CLOSESTTOBEAM_X;
   Double_t        pip_TRACK_POS_CLOSESTTOBEAM_Y;
   Double_t        pip_TRACK_POS_CLOSESTTOBEAM_Z;
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
   TBranch        *b_totCandidates;   //!
   TBranch        *b_nCandidate;   //!
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
   TBranch        *b_KS0_ID;   //!
   TBranch        *b_KS0_KEY;   //!
   TBranch        *b_KS0_CHARGE;   //!
   TBranch        *b_KS0_PT;   //!
   TBranch        *b_KS0_PX;   //!
   TBranch        *b_KS0_PY;   //!
   TBranch        *b_KS0_PZ;   //!
   TBranch        *b_KS0_ETA;   //!
   TBranch        *b_KS0_PHI;   //!
   TBranch        *b_KS0_YSTAR;   //!
   TBranch        *b_KS0_Y;   //!
   TBranch        *b_KS0_MASS;   //!
   TBranch        *b_KS0_ENERGY;   //!
   TBranch        *b_KS0_P;   //!
   TBranch        *b_KS0_FOURMOMENTUME;   //!
   TBranch        *b_KS0_FOURMOMENTUMX;   //!
   TBranch        *b_KS0_FOURMOMENTUMY;   //!
   TBranch        *b_KS0_FOURMOMENTUMZ;   //!
   TBranch        *b_KS0_CHI2;   //!
   TBranch        *b_KS0_CHI2DOF;   //!
   TBranch        *b_KS0_B_PV_Z;   //!
   TBranch        *b_KS0_B_PV_X;   //!
   TBranch        *b_KS0_B_PV_Y;   //!
   TBranch        *b_KS0_BPVIP;   //!
   TBranch        *b_KS0_BPVIPCHI2;   //!
   TBranch        *b_KS0_nBestPVTracks;   //!
   TBranch        *b_KS0_nBestPVbackTracks;   //!
   TBranch        *b_KS0_Hlt1SMOG2D2KpiDecision_TOS;   //!
   TBranch        *b_KS0_Hlt1SMOG2etacToppDecision_TOS;   //!
   TBranch        *b_KS0_Hlt1SMOG2L0ToppiDecision_TOS;   //!
   TBranch        *b_KS0_Hlt1SMOG22BodyGenericDecision_TOS;   //!
   TBranch        *b_KS0_Hlt1TrackMuonMVADecision_TOS;   //!
   TBranch        *b_KS0_Hlt1TwoTrackMVADecision_TOS;   //!
   TBranch        *b_KS0_Hlt1SMOG2BELowMultElectronsDecision_TOS;   //!
   TBranch        *b_KS0_Hlt1SMOG2SingleMuonDecision_TOS;   //!
   TBranch        *b_KS0_Hlt1TrackMVADecision_TOS;   //!
   TBranch        *b_KS0_Hlt1SMOG2BENoBiasDecision_TOS;   //!
   TBranch        *b_KS0_Hlt1SMOG22BodyGenericPromptDecision_TOS;   //!
   TBranch        *b_KS0_Hlt1SMOG2DiMuonHighMassDecision_TOS;   //!
   TBranch        *b_KS0_Hlt1SMOG2MinimumBiasDecision_TOS;   //!
   TBranch        *b_KS0_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS;   //!
   TBranch        *b_KS0_Hlt1PassthroughPVinSMOG2Decision_TOS;   //!
   TBranch        *b_KS0_Hlt1SMOG2SingleTrackHighPtDecision_TOS;   //!
   TBranch        *b_KS0_Hlt1SMOG2PassThroughLowMult5Decision_TOS;   //!
   TBranch        *b_KS0_Hlt1SMOG2KsTopipiDecision_TOS;   //!
   TBranch        *b_KS0_Hlt1SMOG2D2KpiDecision_TIS;   //!
   TBranch        *b_KS0_Hlt1SMOG2etacToppDecision_TIS;   //!
   TBranch        *b_KS0_Hlt1SMOG2L0ToppiDecision_TIS;   //!
   TBranch        *b_KS0_Hlt1SMOG22BodyGenericDecision_TIS;   //!
   TBranch        *b_KS0_Hlt1TrackMuonMVADecision_TIS;   //!
   TBranch        *b_KS0_Hlt1TwoTrackMVADecision_TIS;   //!
   TBranch        *b_KS0_Hlt1SMOG2BELowMultElectronsDecision_TIS;   //!
   TBranch        *b_KS0_Hlt1SMOG2SingleMuonDecision_TIS;   //!
   TBranch        *b_KS0_Hlt1TrackMVADecision_TIS;   //!
   TBranch        *b_KS0_Hlt1SMOG2BENoBiasDecision_TIS;   //!
   TBranch        *b_KS0_Hlt1SMOG22BodyGenericPromptDecision_TIS;   //!
   TBranch        *b_KS0_Hlt1SMOG2DiMuonHighMassDecision_TIS;   //!
   TBranch        *b_KS0_Hlt1SMOG2MinimumBiasDecision_TIS;   //!
   TBranch        *b_KS0_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS;   //!
   TBranch        *b_KS0_Hlt1PassthroughPVinSMOG2Decision_TIS;   //!
   TBranch        *b_KS0_Hlt1SMOG2SingleTrackHighPtDecision_TIS;   //!
   TBranch        *b_KS0_Hlt1SMOG2PassThroughLowMult5Decision_TIS;   //!
   TBranch        *b_KS0_Hlt1SMOG2KsTopipiDecision_TIS;   //!
   TBranch        *b_KS0_DOCA;   //!
   TBranch        *b_KS0_DOCACHI2;   //!
   TBranch        *b_KS0_SDOCA;   //!
   TBranch        *b_KS0_SDOCACHI2;   //!
   TBranch        *b_KS0_END_VX;   //!
   TBranch        *b_KS0_END_VY;   //!
   TBranch        *b_KS0_END_VZ;   //!
   TBranch        *b_KS0_END_VRHO;   //!
   TBranch        *b_KS0_BPVFDCHI2;   //!
   TBranch        *b_KS0_BPVLTIME;   //!
   TBranch        *b_KS0_BPVFD;   //!
   TBranch        *b_KS0_BPVDIRA;   //!
   TBranch        *b_pip_ID;   //!
   TBranch        *b_pip_KEY;   //!
   TBranch        *b_pip_CHARGE;   //!
   TBranch        *b_pip_PT;   //!
   TBranch        *b_pip_PX;   //!
   TBranch        *b_pip_PY;   //!
   TBranch        *b_pip_PZ;   //!
   TBranch        *b_pip_ETA;   //!
   TBranch        *b_pip_PHI;   //!
   TBranch        *b_pip_YSTAR;   //!
   TBranch        *b_pip_Y;   //!
   TBranch        *b_pip_MASS;   //!
   TBranch        *b_pip_ENERGY;   //!
   TBranch        *b_pip_P;   //!
   TBranch        *b_pip_FOURMOMENTUME;   //!
   TBranch        *b_pip_FOURMOMENTUMX;   //!
   TBranch        *b_pip_FOURMOMENTUMY;   //!
   TBranch        *b_pip_FOURMOMENTUMZ;   //!
   TBranch        *b_pip_CHI2;   //!
   TBranch        *b_pip_CHI2DOF;   //!
   TBranch        *b_pip_B_PV_Z;   //!
   TBranch        *b_pip_B_PV_X;   //!
   TBranch        *b_pip_B_PV_Y;   //!
   TBranch        *b_pip_BPVIP;   //!
   TBranch        *b_pip_BPVIPCHI2;   //!
   TBranch        *b_pip_nBestPVTracks;   //!
   TBranch        *b_pip_nBestPVbackTracks;   //!
   TBranch        *b_pip_Hlt1SMOG2D2KpiDecision_TOS;   //!
   TBranch        *b_pip_Hlt1SMOG2etacToppDecision_TOS;   //!
   TBranch        *b_pip_Hlt1SMOG2L0ToppiDecision_TOS;   //!
   TBranch        *b_pip_Hlt1SMOG22BodyGenericDecision_TOS;   //!
   TBranch        *b_pip_Hlt1TrackMuonMVADecision_TOS;   //!
   TBranch        *b_pip_Hlt1TwoTrackMVADecision_TOS;   //!
   TBranch        *b_pip_Hlt1SMOG2BELowMultElectronsDecision_TOS;   //!
   TBranch        *b_pip_Hlt1SMOG2SingleMuonDecision_TOS;   //!
   TBranch        *b_pip_Hlt1TrackMVADecision_TOS;   //!
   TBranch        *b_pip_Hlt1SMOG2BENoBiasDecision_TOS;   //!
   TBranch        *b_pip_Hlt1SMOG22BodyGenericPromptDecision_TOS;   //!
   TBranch        *b_pip_Hlt1SMOG2DiMuonHighMassDecision_TOS;   //!
   TBranch        *b_pip_Hlt1SMOG2MinimumBiasDecision_TOS;   //!
   TBranch        *b_pip_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS;   //!
   TBranch        *b_pip_Hlt1PassthroughPVinSMOG2Decision_TOS;   //!
   TBranch        *b_pip_Hlt1SMOG2SingleTrackHighPtDecision_TOS;   //!
   TBranch        *b_pip_Hlt1SMOG2PassThroughLowMult5Decision_TOS;   //!
   TBranch        *b_pip_Hlt1SMOG2KsTopipiDecision_TOS;   //!
   TBranch        *b_pip_Hlt1SMOG2D2KpiDecision_TIS;   //!
   TBranch        *b_pip_Hlt1SMOG2etacToppDecision_TIS;   //!
   TBranch        *b_pip_Hlt1SMOG2L0ToppiDecision_TIS;   //!
   TBranch        *b_pip_Hlt1SMOG22BodyGenericDecision_TIS;   //!
   TBranch        *b_pip_Hlt1TrackMuonMVADecision_TIS;   //!
   TBranch        *b_pip_Hlt1TwoTrackMVADecision_TIS;   //!
   TBranch        *b_pip_Hlt1SMOG2BELowMultElectronsDecision_TIS;   //!
   TBranch        *b_pip_Hlt1SMOG2SingleMuonDecision_TIS;   //!
   TBranch        *b_pip_Hlt1TrackMVADecision_TIS;   //!
   TBranch        *b_pip_Hlt1SMOG2BENoBiasDecision_TIS;   //!
   TBranch        *b_pip_Hlt1SMOG22BodyGenericPromptDecision_TIS;   //!
   TBranch        *b_pip_Hlt1SMOG2DiMuonHighMassDecision_TIS;   //!
   TBranch        *b_pip_Hlt1SMOG2MinimumBiasDecision_TIS;   //!
   TBranch        *b_pip_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS;   //!
   TBranch        *b_pip_Hlt1PassthroughPVinSMOG2Decision_TIS;   //!
   TBranch        *b_pip_Hlt1SMOG2SingleTrackHighPtDecision_TIS;   //!
   TBranch        *b_pip_Hlt1SMOG2PassThroughLowMult5Decision_TIS;   //!
   TBranch        *b_pip_Hlt1SMOG2KsTopipiDecision_TIS;   //!
   TBranch        *b_pip_PIDE;   //!
   TBranch        *b_pip_PIDK;   //!
   TBranch        *b_pip_PIDMU;   //!
   TBranch        *b_pip_PIDP;   //!
   TBranch        *b_pip_PIDPI;   //!
   TBranch        *b_pip_PROBNNE;   //!
   TBranch        *b_pip_PROBNNK;   //!
   TBranch        *b_pip_PROBNNMU;   //!
   TBranch        *b_pip_PROBNNP;   //!
   TBranch        *b_pip_PROBNNPI;   //!
   TBranch        *b_pip_PROBNNGHOST;   //!
   TBranch        *b_pip_PROBNND;   //!
   TBranch        *b_pip_GHOSTPROB;   //!
   TBranch        *b_pip_ISMUON;   //!
   TBranch        *b_pip_IS_NOT_H;   //!
   TBranch        *b_pip_IS_PHOTON;   //!
   TBranch        *b_pip_TRACK_NVPHITS;   //!
   TBranch        *b_pip_TRACK_NFTHITS;   //!
   TBranch        *b_pip_TRACK_NUTHITS;   //!
   TBranch        *b_pip_TRACK_POS_CLOSESTTOBEAM_X;   //!
   TBranch        *b_pip_TRACK_POS_CLOSESTTOBEAM_Y;   //!
   TBranch        *b_pip_TRACK_POS_CLOSESTTOBEAM_Z;   //!
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
// === Constructor & Destructor ===
   K0S_analysis(TTree *tree=0);     // constructor
   virtual ~K0S_analysis();         // destructor

   // === Core Methods ===
   virtual Int_t    Cut(Long64_t entry);                       // custom selection function (returns 1 if entry is kept)
   virtual Int_t    GetEntry(Long64_t entry);                  // loads entry into memory
   virtual Long64_t LoadTree(Long64_t entry);                  // sets up Tree environment
   virtual void     Init(TTree *tree);                         // binds tree branches to member variables
   virtual void     Loop();                                    // user-defined event loop (to be implemented)
   virtual bool     Notify();                                  // called when a new file is opened
   virtual void     Show(Long64_t entry = -1);                 // prints contents of entry
   virtual bool     CheckSister(int nrentries, int jent,
                                float pim_PT, float pro_PT,
                                double lambda_quality, int runnr); // filters out overlapping or worse candidates
};

#endif

#ifdef K0S_analysis_cxx

// === Constructor ===
// If no TTree is passed, open the default file and retrieve the tree
K0S_analysis::K0S_analysis(TTree *tree) : fChain(0)
{
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/Volumes/Mike_disc/Maria/Smog2/ppref_K0S/K0S_ppref.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/Volumes/Mike_disc/Maria/Smog2/ppref_K0S/K0S_ppref.root");
      }
      TDirectory *dir = (TDirectory*)f->Get("/Volumes/Mike_disc/Maria/Smog2/ppref_K0S/K0S_ppref.root:/Ks0pipi");
      dir->GetObject("DecayFunTuple", tree);
   }
   Init(tree);
}

// === Destructor ===
// Clean up the file when done
K0S_analysis::~K0S_analysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

// === GetEntry ===
// Load the contents of a given tree entry into memory
Int_t K0S_analysis::GetEntry(Long64_t entry)
{
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}

// === LoadTree ===
// Prepare to read the specified entry
Long64_t K0S_analysis::LoadTree(Long64_t entry)
{
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();  // react to file/tree change
   }
   return centry;
}

// === Init ===
// Set branch addresses and bind them to class members
void K0S_analysis::Init(TTree *tree)
{
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);  // required for branch bindings

   // Branch address setup
   fChain->SetBranchAddress("totCandidates", &totCandidates, &b_totCandidates);
   fChain->SetBranchAddress("nCandidate", &nCandidate, &b_nCandidate);
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
   fChain->SetBranchAddress("KS0_ID", &KS0_ID, &b_KS0_ID);
   fChain->SetBranchAddress("KS0_KEY", &KS0_KEY, &b_KS0_KEY);
   fChain->SetBranchAddress("KS0_CHARGE", &KS0_CHARGE, &b_KS0_CHARGE);
   fChain->SetBranchAddress("KS0_PT", &KS0_PT, &b_KS0_PT);
   fChain->SetBranchAddress("KS0_PX", &KS0_PX, &b_KS0_PX);
   fChain->SetBranchAddress("KS0_PY", &KS0_PY, &b_KS0_PY);
   fChain->SetBranchAddress("KS0_PZ", &KS0_PZ, &b_KS0_PZ);
   fChain->SetBranchAddress("KS0_ETA", &KS0_ETA, &b_KS0_ETA);
   fChain->SetBranchAddress("KS0_PHI", &KS0_PHI, &b_KS0_PHI);
   fChain->SetBranchAddress("KS0_YSTAR", &KS0_YSTAR, &b_KS0_YSTAR);
   fChain->SetBranchAddress("KS0_Y", &KS0_Y, &b_KS0_Y);
   fChain->SetBranchAddress("KS0_MASS", &KS0_MASS, &b_KS0_MASS);
   fChain->SetBranchAddress("KS0_ENERGY", &KS0_ENERGY, &b_KS0_ENERGY);
   fChain->SetBranchAddress("KS0_P", &KS0_P, &b_KS0_P);
   fChain->SetBranchAddress("KS0_FOURMOMENTUME", &KS0_FOURMOMENTUME, &b_KS0_FOURMOMENTUME);
   fChain->SetBranchAddress("KS0_FOURMOMENTUMX", &KS0_FOURMOMENTUMX, &b_KS0_FOURMOMENTUMX);
   fChain->SetBranchAddress("KS0_FOURMOMENTUMY", &KS0_FOURMOMENTUMY, &b_KS0_FOURMOMENTUMY);
   fChain->SetBranchAddress("KS0_FOURMOMENTUMZ", &KS0_FOURMOMENTUMZ, &b_KS0_FOURMOMENTUMZ);
   fChain->SetBranchAddress("KS0_CHI2", &KS0_CHI2, &b_KS0_CHI2);
   fChain->SetBranchAddress("KS0_CHI2DOF", &KS0_CHI2DOF, &b_KS0_CHI2DOF);
   fChain->SetBranchAddress("KS0_B_PV_Z", &KS0_B_PV_Z, &b_KS0_B_PV_Z);
   fChain->SetBranchAddress("KS0_B_PV_X", &KS0_B_PV_X, &b_KS0_B_PV_X);
   fChain->SetBranchAddress("KS0_B_PV_Y", &KS0_B_PV_Y, &b_KS0_B_PV_Y);
   fChain->SetBranchAddress("KS0_BPVIP", &KS0_BPVIP, &b_KS0_BPVIP);
   fChain->SetBranchAddress("KS0_BPVIPCHI2", &KS0_BPVIPCHI2, &b_KS0_BPVIPCHI2);
   fChain->SetBranchAddress("KS0_nBestPVTracks", &KS0_nBestPVTracks, &b_KS0_nBestPVTracks);
   fChain->SetBranchAddress("KS0_nBestPVbackTracks", &KS0_nBestPVbackTracks, &b_KS0_nBestPVbackTracks);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2D2KpiDecision_TOS", &KS0_Hlt1SMOG2D2KpiDecision_TOS, &b_KS0_Hlt1SMOG2D2KpiDecision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2etacToppDecision_TOS", &KS0_Hlt1SMOG2etacToppDecision_TOS, &b_KS0_Hlt1SMOG2etacToppDecision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2L0ToppiDecision_TOS", &KS0_Hlt1SMOG2L0ToppiDecision_TOS, &b_KS0_Hlt1SMOG2L0ToppiDecision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG22BodyGenericDecision_TOS", &KS0_Hlt1SMOG22BodyGenericDecision_TOS, &b_KS0_Hlt1SMOG22BodyGenericDecision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1TrackMuonMVADecision_TOS", &KS0_Hlt1TrackMuonMVADecision_TOS, &b_KS0_Hlt1TrackMuonMVADecision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1TwoTrackMVADecision_TOS", &KS0_Hlt1TwoTrackMVADecision_TOS, &b_KS0_Hlt1TwoTrackMVADecision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2BELowMultElectronsDecision_TOS", &KS0_Hlt1SMOG2BELowMultElectronsDecision_TOS, &b_KS0_Hlt1SMOG2BELowMultElectronsDecision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2SingleMuonDecision_TOS", &KS0_Hlt1SMOG2SingleMuonDecision_TOS, &b_KS0_Hlt1SMOG2SingleMuonDecision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1TrackMVADecision_TOS", &KS0_Hlt1TrackMVADecision_TOS, &b_KS0_Hlt1TrackMVADecision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2BENoBiasDecision_TOS", &KS0_Hlt1SMOG2BENoBiasDecision_TOS, &b_KS0_Hlt1SMOG2BENoBiasDecision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG22BodyGenericPromptDecision_TOS", &KS0_Hlt1SMOG22BodyGenericPromptDecision_TOS, &b_KS0_Hlt1SMOG22BodyGenericPromptDecision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2DiMuonHighMassDecision_TOS", &KS0_Hlt1SMOG2DiMuonHighMassDecision_TOS, &b_KS0_Hlt1SMOG2DiMuonHighMassDecision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2MinimumBiasDecision_TOS", &KS0_Hlt1SMOG2MinimumBiasDecision_TOS, &b_KS0_Hlt1SMOG2MinimumBiasDecision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS", &KS0_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS, &b_KS0_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1PassthroughPVinSMOG2Decision_TOS", &KS0_Hlt1PassthroughPVinSMOG2Decision_TOS, &b_KS0_Hlt1PassthroughPVinSMOG2Decision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2SingleTrackHighPtDecision_TOS", &KS0_Hlt1SMOG2SingleTrackHighPtDecision_TOS, &b_KS0_Hlt1SMOG2SingleTrackHighPtDecision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2PassThroughLowMult5Decision_TOS", &KS0_Hlt1SMOG2PassThroughLowMult5Decision_TOS, &b_KS0_Hlt1SMOG2PassThroughLowMult5Decision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2KsTopipiDecision_TOS", &KS0_Hlt1SMOG2KsTopipiDecision_TOS, &b_KS0_Hlt1SMOG2KsTopipiDecision_TOS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2D2KpiDecision_TIS", &KS0_Hlt1SMOG2D2KpiDecision_TIS, &b_KS0_Hlt1SMOG2D2KpiDecision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2etacToppDecision_TIS", &KS0_Hlt1SMOG2etacToppDecision_TIS, &b_KS0_Hlt1SMOG2etacToppDecision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2L0ToppiDecision_TIS", &KS0_Hlt1SMOG2L0ToppiDecision_TIS, &b_KS0_Hlt1SMOG2L0ToppiDecision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG22BodyGenericDecision_TIS", &KS0_Hlt1SMOG22BodyGenericDecision_TIS, &b_KS0_Hlt1SMOG22BodyGenericDecision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1TrackMuonMVADecision_TIS", &KS0_Hlt1TrackMuonMVADecision_TIS, &b_KS0_Hlt1TrackMuonMVADecision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1TwoTrackMVADecision_TIS", &KS0_Hlt1TwoTrackMVADecision_TIS, &b_KS0_Hlt1TwoTrackMVADecision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2BELowMultElectronsDecision_TIS", &KS0_Hlt1SMOG2BELowMultElectronsDecision_TIS, &b_KS0_Hlt1SMOG2BELowMultElectronsDecision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2SingleMuonDecision_TIS", &KS0_Hlt1SMOG2SingleMuonDecision_TIS, &b_KS0_Hlt1SMOG2SingleMuonDecision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1TrackMVADecision_TIS", &KS0_Hlt1TrackMVADecision_TIS, &b_KS0_Hlt1TrackMVADecision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2BENoBiasDecision_TIS", &KS0_Hlt1SMOG2BENoBiasDecision_TIS, &b_KS0_Hlt1SMOG2BENoBiasDecision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG22BodyGenericPromptDecision_TIS", &KS0_Hlt1SMOG22BodyGenericPromptDecision_TIS, &b_KS0_Hlt1SMOG22BodyGenericPromptDecision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2DiMuonHighMassDecision_TIS", &KS0_Hlt1SMOG2DiMuonHighMassDecision_TIS, &b_KS0_Hlt1SMOG2DiMuonHighMassDecision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2MinimumBiasDecision_TIS", &KS0_Hlt1SMOG2MinimumBiasDecision_TIS, &b_KS0_Hlt1SMOG2MinimumBiasDecision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS", &KS0_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS, &b_KS0_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1PassthroughPVinSMOG2Decision_TIS", &KS0_Hlt1PassthroughPVinSMOG2Decision_TIS, &b_KS0_Hlt1PassthroughPVinSMOG2Decision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2SingleTrackHighPtDecision_TIS", &KS0_Hlt1SMOG2SingleTrackHighPtDecision_TIS, &b_KS0_Hlt1SMOG2SingleTrackHighPtDecision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2PassThroughLowMult5Decision_TIS", &KS0_Hlt1SMOG2PassThroughLowMult5Decision_TIS, &b_KS0_Hlt1SMOG2PassThroughLowMult5Decision_TIS);
   fChain->SetBranchAddress("KS0_Hlt1SMOG2KsTopipiDecision_TIS", &KS0_Hlt1SMOG2KsTopipiDecision_TIS, &b_KS0_Hlt1SMOG2KsTopipiDecision_TIS);
   fChain->SetBranchAddress("KS0_DOCA", &KS0_DOCA, &b_KS0_DOCA);
   fChain->SetBranchAddress("KS0_DOCACHI2", &KS0_DOCACHI2, &b_KS0_DOCACHI2);
   fChain->SetBranchAddress("KS0_SDOCA", &KS0_SDOCA, &b_KS0_SDOCA);
   fChain->SetBranchAddress("KS0_SDOCACHI2", &KS0_SDOCACHI2, &b_KS0_SDOCACHI2);
   fChain->SetBranchAddress("KS0_END_VX", &KS0_END_VX, &b_KS0_END_VX);
   fChain->SetBranchAddress("KS0_END_VY", &KS0_END_VY, &b_KS0_END_VY);
   fChain->SetBranchAddress("KS0_END_VZ", &KS0_END_VZ, &b_KS0_END_VZ);
   fChain->SetBranchAddress("KS0_END_VRHO", &KS0_END_VRHO, &b_KS0_END_VRHO);
   fChain->SetBranchAddress("KS0_BPVFDCHI2", &KS0_BPVFDCHI2, &b_KS0_BPVFDCHI2);
   fChain->SetBranchAddress("KS0_BPVLTIME", &KS0_BPVLTIME, &b_KS0_BPVLTIME);
   fChain->SetBranchAddress("KS0_BPVFD", &KS0_BPVFD, &b_KS0_BPVFD);
   fChain->SetBranchAddress("KS0_BPVDIRA", &KS0_BPVDIRA, &b_KS0_BPVDIRA);
   fChain->SetBranchAddress("pip_ID", &pip_ID, &b_pip_ID);
   fChain->SetBranchAddress("pip_KEY", &pip_KEY, &b_pip_KEY);
   fChain->SetBranchAddress("pip_CHARGE", &pip_CHARGE, &b_pip_CHARGE);
   fChain->SetBranchAddress("pip_PT", &pip_PT, &b_pip_PT);
   fChain->SetBranchAddress("pip_PX", &pip_PX, &b_pip_PX);
   fChain->SetBranchAddress("pip_PY", &pip_PY, &b_pip_PY);
   fChain->SetBranchAddress("pip_PZ", &pip_PZ, &b_pip_PZ);
   fChain->SetBranchAddress("pip_ETA", &pip_ETA, &b_pip_ETA);
   fChain->SetBranchAddress("pip_PHI", &pip_PHI, &b_pip_PHI);
   fChain->SetBranchAddress("pip_YSTAR", &pip_YSTAR, &b_pip_YSTAR);
   fChain->SetBranchAddress("pip_Y", &pip_Y, &b_pip_Y);
   fChain->SetBranchAddress("pip_MASS", &pip_MASS, &b_pip_MASS);
   fChain->SetBranchAddress("pip_ENERGY", &pip_ENERGY, &b_pip_ENERGY);
   fChain->SetBranchAddress("pip_P", &pip_P, &b_pip_P);
   fChain->SetBranchAddress("pip_FOURMOMENTUME", &pip_FOURMOMENTUME, &b_pip_FOURMOMENTUME);
   fChain->SetBranchAddress("pip_FOURMOMENTUMX", &pip_FOURMOMENTUMX, &b_pip_FOURMOMENTUMX);
   fChain->SetBranchAddress("pip_FOURMOMENTUMY", &pip_FOURMOMENTUMY, &b_pip_FOURMOMENTUMY);
   fChain->SetBranchAddress("pip_FOURMOMENTUMZ", &pip_FOURMOMENTUMZ, &b_pip_FOURMOMENTUMZ);
   fChain->SetBranchAddress("pip_CHI2", &pip_CHI2, &b_pip_CHI2);
   fChain->SetBranchAddress("pip_CHI2DOF", &pip_CHI2DOF, &b_pip_CHI2DOF);
   fChain->SetBranchAddress("pip_B_PV_Z", &pip_B_PV_Z, &b_pip_B_PV_Z);
   fChain->SetBranchAddress("pip_B_PV_X", &pip_B_PV_X, &b_pip_B_PV_X);
   fChain->SetBranchAddress("pip_B_PV_Y", &pip_B_PV_Y, &b_pip_B_PV_Y);
   fChain->SetBranchAddress("pip_BPVIP", &pip_BPVIP, &b_pip_BPVIP);
   fChain->SetBranchAddress("pip_BPVIPCHI2", &pip_BPVIPCHI2, &b_pip_BPVIPCHI2);
   fChain->SetBranchAddress("pip_nBestPVTracks", &pip_nBestPVTracks, &b_pip_nBestPVTracks);
   fChain->SetBranchAddress("pip_nBestPVbackTracks", &pip_nBestPVbackTracks, &b_pip_nBestPVbackTracks);
   fChain->SetBranchAddress("pip_Hlt1SMOG2D2KpiDecision_TOS", &pip_Hlt1SMOG2D2KpiDecision_TOS, &b_pip_Hlt1SMOG2D2KpiDecision_TOS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2etacToppDecision_TOS", &pip_Hlt1SMOG2etacToppDecision_TOS, &b_pip_Hlt1SMOG2etacToppDecision_TOS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2L0ToppiDecision_TOS", &pip_Hlt1SMOG2L0ToppiDecision_TOS, &b_pip_Hlt1SMOG2L0ToppiDecision_TOS);
   fChain->SetBranchAddress("pip_Hlt1SMOG22BodyGenericDecision_TOS", &pip_Hlt1SMOG22BodyGenericDecision_TOS, &b_pip_Hlt1SMOG22BodyGenericDecision_TOS);
   fChain->SetBranchAddress("pip_Hlt1TrackMuonMVADecision_TOS", &pip_Hlt1TrackMuonMVADecision_TOS, &b_pip_Hlt1TrackMuonMVADecision_TOS);
   fChain->SetBranchAddress("pip_Hlt1TwoTrackMVADecision_TOS", &pip_Hlt1TwoTrackMVADecision_TOS, &b_pip_Hlt1TwoTrackMVADecision_TOS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2BELowMultElectronsDecision_TOS", &pip_Hlt1SMOG2BELowMultElectronsDecision_TOS, &b_pip_Hlt1SMOG2BELowMultElectronsDecision_TOS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2SingleMuonDecision_TOS", &pip_Hlt1SMOG2SingleMuonDecision_TOS, &b_pip_Hlt1SMOG2SingleMuonDecision_TOS);
   fChain->SetBranchAddress("pip_Hlt1TrackMVADecision_TOS", &pip_Hlt1TrackMVADecision_TOS, &b_pip_Hlt1TrackMVADecision_TOS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2BENoBiasDecision_TOS", &pip_Hlt1SMOG2BENoBiasDecision_TOS, &b_pip_Hlt1SMOG2BENoBiasDecision_TOS);
   fChain->SetBranchAddress("pip_Hlt1SMOG22BodyGenericPromptDecision_TOS", &pip_Hlt1SMOG22BodyGenericPromptDecision_TOS, &b_pip_Hlt1SMOG22BodyGenericPromptDecision_TOS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2DiMuonHighMassDecision_TOS", &pip_Hlt1SMOG2DiMuonHighMassDecision_TOS, &b_pip_Hlt1SMOG2DiMuonHighMassDecision_TOS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2MinimumBiasDecision_TOS", &pip_Hlt1SMOG2MinimumBiasDecision_TOS, &b_pip_Hlt1SMOG2MinimumBiasDecision_TOS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS", &pip_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS, &b_pip_Hlt1SMOG2SingleTrackVeryHighPtDecision_TOS);
   fChain->SetBranchAddress("pip_Hlt1PassthroughPVinSMOG2Decision_TOS", &pip_Hlt1PassthroughPVinSMOG2Decision_TOS, &b_pip_Hlt1PassthroughPVinSMOG2Decision_TOS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2SingleTrackHighPtDecision_TOS", &pip_Hlt1SMOG2SingleTrackHighPtDecision_TOS, &b_pip_Hlt1SMOG2SingleTrackHighPtDecision_TOS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2PassThroughLowMult5Decision_TOS", &pip_Hlt1SMOG2PassThroughLowMult5Decision_TOS, &b_pip_Hlt1SMOG2PassThroughLowMult5Decision_TOS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2KsTopipiDecision_TOS", &pip_Hlt1SMOG2KsTopipiDecision_TOS, &b_pip_Hlt1SMOG2KsTopipiDecision_TOS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2D2KpiDecision_TIS", &pip_Hlt1SMOG2D2KpiDecision_TIS, &b_pip_Hlt1SMOG2D2KpiDecision_TIS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2etacToppDecision_TIS", &pip_Hlt1SMOG2etacToppDecision_TIS, &b_pip_Hlt1SMOG2etacToppDecision_TIS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2L0ToppiDecision_TIS", &pip_Hlt1SMOG2L0ToppiDecision_TIS, &b_pip_Hlt1SMOG2L0ToppiDecision_TIS);
   fChain->SetBranchAddress("pip_Hlt1SMOG22BodyGenericDecision_TIS", &pip_Hlt1SMOG22BodyGenericDecision_TIS, &b_pip_Hlt1SMOG22BodyGenericDecision_TIS);
   fChain->SetBranchAddress("pip_Hlt1TrackMuonMVADecision_TIS", &pip_Hlt1TrackMuonMVADecision_TIS, &b_pip_Hlt1TrackMuonMVADecision_TIS);
   fChain->SetBranchAddress("pip_Hlt1TwoTrackMVADecision_TIS", &pip_Hlt1TwoTrackMVADecision_TIS, &b_pip_Hlt1TwoTrackMVADecision_TIS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2BELowMultElectronsDecision_TIS", &pip_Hlt1SMOG2BELowMultElectronsDecision_TIS, &b_pip_Hlt1SMOG2BELowMultElectronsDecision_TIS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2SingleMuonDecision_TIS", &pip_Hlt1SMOG2SingleMuonDecision_TIS, &b_pip_Hlt1SMOG2SingleMuonDecision_TIS);
   fChain->SetBranchAddress("pip_Hlt1TrackMVADecision_TIS", &pip_Hlt1TrackMVADecision_TIS, &b_pip_Hlt1TrackMVADecision_TIS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2BENoBiasDecision_TIS", &pip_Hlt1SMOG2BENoBiasDecision_TIS, &b_pip_Hlt1SMOG2BENoBiasDecision_TIS);
   fChain->SetBranchAddress("pip_Hlt1SMOG22BodyGenericPromptDecision_TIS", &pip_Hlt1SMOG22BodyGenericPromptDecision_TIS, &b_pip_Hlt1SMOG22BodyGenericPromptDecision_TIS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2DiMuonHighMassDecision_TIS", &pip_Hlt1SMOG2DiMuonHighMassDecision_TIS, &b_pip_Hlt1SMOG2DiMuonHighMassDecision_TIS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2MinimumBiasDecision_TIS", &pip_Hlt1SMOG2MinimumBiasDecision_TIS, &b_pip_Hlt1SMOG2MinimumBiasDecision_TIS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS", &pip_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS, &b_pip_Hlt1SMOG2SingleTrackVeryHighPtDecision_TIS);
   fChain->SetBranchAddress("pip_Hlt1PassthroughPVinSMOG2Decision_TIS", &pip_Hlt1PassthroughPVinSMOG2Decision_TIS, &b_pip_Hlt1PassthroughPVinSMOG2Decision_TIS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2SingleTrackHighPtDecision_TIS", &pip_Hlt1SMOG2SingleTrackHighPtDecision_TIS, &b_pip_Hlt1SMOG2SingleTrackHighPtDecision_TIS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2PassThroughLowMult5Decision_TIS", &pip_Hlt1SMOG2PassThroughLowMult5Decision_TIS, &b_pip_Hlt1SMOG2PassThroughLowMult5Decision_TIS);
   fChain->SetBranchAddress("pip_Hlt1SMOG2KsTopipiDecision_TIS", &pip_Hlt1SMOG2KsTopipiDecision_TIS, &b_pip_Hlt1SMOG2KsTopipiDecision_TIS);
   fChain->SetBranchAddress("pip_PIDE", &pip_PIDE, &b_pip_PIDE);
   fChain->SetBranchAddress("pip_PIDK", &pip_PIDK, &b_pip_PIDK);
   fChain->SetBranchAddress("pip_PIDMU", &pip_PIDMU, &b_pip_PIDMU);
   fChain->SetBranchAddress("pip_PIDP", &pip_PIDP, &b_pip_PIDP);
   fChain->SetBranchAddress("pip_PIDPI", &pip_PIDPI, &b_pip_PIDPI);
   fChain->SetBranchAddress("pip_PROBNNE", &pip_PROBNNE, &b_pip_PROBNNE);
   fChain->SetBranchAddress("pip_PROBNNK", &pip_PROBNNK, &b_pip_PROBNNK);
   fChain->SetBranchAddress("pip_PROBNNMU", &pip_PROBNNMU, &b_pip_PROBNNMU);
   fChain->SetBranchAddress("pip_PROBNNP", &pip_PROBNNP, &b_pip_PROBNNP);
   fChain->SetBranchAddress("pip_PROBNNPI", &pip_PROBNNPI, &b_pip_PROBNNPI);
   fChain->SetBranchAddress("pip_PROBNNGHOST", &pip_PROBNNGHOST, &b_pip_PROBNNGHOST);
   fChain->SetBranchAddress("pip_PROBNND", &pip_PROBNND, &b_pip_PROBNND);
   fChain->SetBranchAddress("pip_GHOSTPROB", &pip_GHOSTPROB, &b_pip_GHOSTPROB);
   fChain->SetBranchAddress("pip_ISMUON", &pip_ISMUON, &b_pip_ISMUON);
   fChain->SetBranchAddress("pip_IS_NOT_H", &pip_IS_NOT_H, &b_pip_IS_NOT_H);
   fChain->SetBranchAddress("pip_IS_PHOTON", &pip_IS_PHOTON, &b_pip_IS_PHOTON);
   fChain->SetBranchAddress("pip_TRACK_NVPHITS", &pip_TRACK_NVPHITS, &b_pip_TRACK_NVPHITS);
   fChain->SetBranchAddress("pip_TRACK_NFTHITS", &pip_TRACK_NFTHITS, &b_pip_TRACK_NFTHITS);
   fChain->SetBranchAddress("pip_TRACK_NUTHITS", &pip_TRACK_NUTHITS, &b_pip_TRACK_NUTHITS);
   fChain->SetBranchAddress("pip_TRACK_POS_CLOSESTTOBEAM_X", &pip_TRACK_POS_CLOSESTTOBEAM_X, &b_pip_TRACK_POS_CLOSESTTOBEAM_X);
   fChain->SetBranchAddress("pip_TRACK_POS_CLOSESTTOBEAM_Y", &pip_TRACK_POS_CLOSESTTOBEAM_Y, &b_pip_TRACK_POS_CLOSESTTOBEAM_Y);
   fChain->SetBranchAddress("pip_TRACK_POS_CLOSESTTOBEAM_Z", &pip_TRACK_POS_CLOSESTTOBEAM_Z, &b_pip_TRACK_POS_CLOSESTTOBEAM_Z);
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
   Notify();  // call Notify after setting up branches
}

// === Notify ===
// Called when new file is opened (useful in TChain or PROOF)
bool K0S_analysis::Notify()
{
   return true;
}

// === Show ===
// Print contents of a given entry
void K0S_analysis::Show(Long64_t entry)
{
   if (!fChain) return;
   fChain->Show(entry);
}

// === Cut ===
// Placeholder cut function — accepts all entries by default
Int_t K0S_analysis::Cut(Long64_t entry)
{
   return 1;
}

// === CheckSister ===
// Function to check for better candidates with same daughter tracks
// Compares current candidate (jent) to neighbors and looks for one with better KS0_DOCACHI2
bool K0S_analysis::CheckSister(int nrentries, int jent, float pi_pt, float pro_pt, double lambda_quality, int runnr)
{
   int betterSister = 1;  // assume current is best

   // === Check next 2 entries (if near beginning) ===
   if (jent < 3) {
      for (int i = jent + 1; i < jent + 3; i++) {
         fChain->GetEntry(i);
         float pi_pt_a = pim_PT;
         float pro_pt_a = pip_PT;
         double lambda_quality_a = KS0_DOCACHI2;
         if (pi_pt_a == pi_pt || pro_pt_a == pro_pt) {
            if (lambda_quality_a < lambda_quality) {
               betterSister = 0; break;
            }
         }
      }
   }
   // === Check previous 3 entries (if near end) ===
   else if (nrentries - jent < 3) {
      for (int i = jent - 3; i < jent; i++) {
         fChain->GetEntry(i);
         float pi_pt_a = pim_PT;
         float pro_pt_a = pip_PT;
         double lambda_quality_a = KS0_DOCACHI2;
         if (pi_pt_a == pi_pt || pro_pt_a == pro_pt) {
            if (lambda_quality_a < lambda_quality) {
               betterSister = 0; break;
            }
         }
      }
   }
   // === Otherwise, check surrounding 6 entries ===
   else {
      for (int i = jent - 3; i < jent + 3; i++) {
         if (i == jent) continue;  // skip current
         fChain->GetEntry(i);
         int runnr_a = RUNNUMBER;
         float pi_pt_a = pim_PT;
         float pro_pt_a = pip_PT;
         double lambda_quality_a = KS0_DOCACHI2;
         if (runnr_a == runnr) {
            if (pi_pt_a == pi_pt || pro_pt_a == pro_pt) {
               if (lambda_quality_a < lambda_quality) {
                  betterSister = 0; break;
               }
            }
         }
      }
   }

   return betterSister == 1;
}

#endif // #ifdef K0S_analysis_cxx