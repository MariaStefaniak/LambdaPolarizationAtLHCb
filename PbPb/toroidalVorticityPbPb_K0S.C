#define toroidalVorticityPbPb_K0S_cxx
#include "toroidalVorticityPbPb_K0S.h"
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TProfile.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <TVector3.h>
#include <TMath.h>
#include <iostream>

// ===================================================================================
// Full analysis macro for toroidal vorticity in PbPb 2024 using K0S → π⁺π⁻ decays
// Author: Maria Stefaniak (2025)
// This function is executed from the ROOT-based class toroidalVorticityPbPb_K0S
// ===================================================================================

void toroidalVorticityPbPb_K0S::Loop()
{
    // Check if the input chain exists
    if (fChain == nullptr) return;

    // Load number of events
    Long64_t nentries = fChain->GetEntriesFast();
    std::cout << "Number of entries in tree: " << nentries << std::endl;

    Long64_t nbytes = 0, nb = 0;

    // Loop over all entries in the tree
    for (Long64_t jentry = 0; jentry < nentries; jentry++) {
        // Load current entry
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry); nbytes += nb;

        // Skip events with too few backward tracks (selects collider mode)
        if (nBackTracks < 10) continue;

        // Only accept events with one primary vertex (PV)
        if (nPVs != 1) continue;

        // Extract PVZ of first PV and apply cut
        float pvz_ = PVZ[0];
        if (pvz_ < -100 || pvz_ > 100) continue;

        // Apply topological and quality cuts for Ks decay candidates
        if (Ks_BPVDIRA < 0.9999 || Ks_BPVIPCHI2 > 25) continue;
        if (pi_minus_BPVIPCHI2 < 25 || pi_plus_BPVIPCHI2 < 25) continue;
        if (pi_minus_PT < 200 || pi_plus_PT < 500) continue;
        if (pi_minus_GHOSTPROB > 0.1 || pi_plus_GHOSTPROB > 0.1) continue;
        if (Ks_BPVFDCHI2 < 130) continue;

        // Classify decay as antiLambda-like or Lambda-like using Ks_ID sign
        int anti = (Ks_ID < 0) ? 0 : 1;

        // Fill invariant mass histogram
        hMassInvariant[anti]->Fill(Ks_MASS);

        // Create decay vector between PV and Ks decay vertex
        TVector3 lambdaPosition(Ks_END_VX - PVX[0], Ks_END_VY - PVY[0], Ks_END_VZ - PVZ[0]);
        TVector3 lambdaMomentum(Ks_PX, Ks_PY, Ks_PZ);

        // Compute direction angle between flight path and momentum
        double DIRA = lambdaPosition.Dot(lambdaMomentum) / (lambdaPosition.Mag() * lambdaMomentum.Mag());
        hDIRA->Fill(DIRA);

        // Fill DOCA chi2 for Lambda-like candidates only
        if (anti == 1) hDOCchi2->Fill(Ks_DOCA);

        // Fill event-level QA histograms
        hnVeloTracks[anti]->Fill(nVeloTracks);
        hProtonIpChi2[anti]->Fill(pi_plus_BPVIPCHI2);
        hPhiLambda[anti]->Fill(Ks_PHI);
        hLambdaPt_Phi_Eta[anti]->Fill(Ks_PT, Ks_PHI, Ks_ETA);

        // Construct Lorentz vectors for Ks, pi+, and pi-
        TLorentzVector LambdaFourMomentum; LambdaFourMomentum.SetPtEtaPhiM(Ks_PT, Ks_ETA, Ks_PHI, Ks_MASS);
        TLorentzVector ProtonFourMomentum; ProtonFourMomentum.SetPtEtaPhiM(pi_plus_PT, pi_plus_ETA, pi_plus_PHI, pi_plus_MASS);
        TLorentzVector PionFourMomentum;   PionFourMomentum.SetPtEtaPhiM(pi_minus_PT, pi_minus_ETA, pi_minus_PHI, pi_minus_MASS);

        // Compute particle kinematics
        double Ks_P = LambdaFourMomentum.P();
        double pi_plus_P  = ProtonFourMomentum.P();
        double pi_minus_P = PionFourMomentum.P();
        double Ks_Y = LambdaFourMomentum.Rapidity();
        double pi_plus_Y  = ProtonFourMomentum.Rapidity();
        double pi_minus_Y = PionFourMomentum.Rapidity();

        // Fill single-particle QA histograms
        hpi_plus_pt[anti]->Fill(ProtonFourMomentum.Pt());
        hpi_minus_pt[anti]->Fill(PionFourMomentum.Pt());
        hKs_pt[anti]->Fill(LambdaFourMomentum.Pt());
        hpi_plus_phi[anti]->Fill(ProtonFourMomentum.Phi());
        hpi_minus_phi[anti]->Fill(PionFourMomentum.Phi());
        hKs_phi[anti]->Fill(LambdaFourMomentum.Phi());

        // Fill angular correlations between daughter and mother
        hPionPhi_LambdaPhi[anti]->Fill(PionFourMomentum.Phi(), LambdaFourMomentum.Phi());
        hProtonPhi_LambdaPhi[anti]->Fill(ProtonFourMomentum.Phi(), LambdaFourMomentum.Phi());

        // === BOOST PROTON TO LAMBDA REST FRAME ===
        TLorentzVector BoostedProtonFourMomentum = ProtonFourMomentum;
        BoostedProtonFourMomentum.Boost(-LambdaFourMomentum.BoostVector());

        // Compute triple-product observable: R = (3/alpha) * (p* · (z × p_Lambda))
        TVector3 BeamMomentumHat(0, 0, 1);
        TVector3 LambdaMomentumVec3(LambdaFourMomentum.Px(), LambdaFourMomentum.Py(), LambdaFourMomentum.Pz());
        TVector3 CrossPart = BeamMomentumHat.Cross(LambdaMomentumVec3).Unit();
        TVector3 pStar = BoostedProtonFourMomentum.Vect().Unit();

        double PPP = (3 / alpha_lamb) * pStar.Dot(CrossPart);
        if (anti == 0) PPP *= -1;

        // Fill toroidal observable profiles and QA
        double LambdapT = LambdaFourMomentum.Pt();
        hPtLambda[anti]->Fill(LambdapT);
        hRapidity[anti]->Fill(Ks_Y);

        // === COMPUTE cos(theta*) ===
        double protonCosTheta = pStar.Dot(CrossPart);
        double thetaStar = acos(protonCosTheta);

        // === COMPUTE phi* ===
        TVector3 ProjPmomStarOnNormal = protonCosTheta * ProtonFourMomentum.P() * CrossPart;
        TVector3 ProjPmomStarOnProductionPlane = BoostedProtonFourMomentum.Vect() - ProjPmomStarOnNormal;
        TVector3 CrossALambda = ProjPmomStarOnProductionPlane.Cross(LambdaMomentumVec3);
        double sinPhiStar = CrossALambda.Unit().Dot(CrossPart);
        double phiStar = acos(LambdaMomentumVec3.Dot(ProjPmomStarOnProductionPlane) /
                             (ProjPmomStarOnProductionPlane.Mag() * LambdaMomentumVec3.Mag()));
        if (sinPhiStar > 0) phiStar = 2 * TMath::Pi() - phiStar;

        // Fill 2D angular correlations
        hPhiStarCosThetaStar[anti]->Fill(phiStar, protonCosTheta);
        hPhiStar[anti]->Fill(phiStar);

        // Fill lab-frame correlations with phi*
        hProtonPhiStarProtonPhi[anti]->Fill(phiStar, pi_plus_PHI);
        hProtonPhiStarProtonTheta[anti]->Fill(phiStar, pi_plus_ETA);

        // Fill kinematic and correlation histograms
        hPtLambdaPtProton[anti]->Fill(LambdapT, pi_plus_PT);
        hPLambdaPProton[anti]->Fill(Ks_P, pi_plus_P);
        hProtonPhiThetaLabFrame[anti]->Fill(pi_plus_PHI, pi_plus_ETA);
        hProtonPhiLabFrame[anti]->Fill(pi_plus_PHI);
        hProtonPhiLambdaPt[anti]->Fill(phiStar, LambdapT);
        hProtonPhiStarPionPt[anti]->Fill(phiStar, pi_minus_PT);
        hProtonPhiStarPionRap[anti]->Fill(phiStar, pi_minus_Y);
        hPionPtRap[anti]->Fill(pi_minus_PT, pi_minus_Y);
        hProtonPtRap[anti]->Fill(pi_plus_PT, pi_plus_Y);

        // Fill cos(theta*) histograms in centrality bins
        if (nVeloTracks < multiplicity_bins[1]) hCosTheta[anti][0]->Fill(protonCosTheta);
        else if (nVeloTracks < multiplicity_bins[2]) hCosTheta[anti][1]->Fill(protonCosTheta);
        else hCosTheta[anti][2]->Fill(protonCosTheta);

        // Fill toroidal observable profiles
        pToroidalMulti[anti]->Fill(nVeloTracks, PPP);
        if (Ks_Y > -0.5) pToroidalMulti_rapCut[anti]->Fill(nVeloTracks, PPP);
        pToroidalRap[anti]->Fill(Ks_Y, PPP);
        if (phiStar > 1.7 && phiStar < 2.8) {
            pToroidalMulti_phiStarCut[anti]->Fill(nVeloTracks, PPP);
            pToroidalRap_phiStarCut[anti]->Fill(Ks_Y, PPP);
        }

        // Fill PVZ binned phi* correlations
        if (pvz_ < -500) {
            hPhiStarCosThetaStar_PVZ[anti][0]->Fill(phiStar, protonCosTheta);
            hPhiStar_PVZ[anti][0]->Fill(phiStar);
        }
        if (pvz_ > -500 && pvz_ < -450) {
            hPhiStarCosThetaStar_PVZ[anti][1]->Fill(phiStar, protonCosTheta);
            hPhiStar_PVZ[anti][1]->Fill(phiStar);
        }
        if (pvz_ > -450 && pvz_ < -400) {
            hPhiStarCosThetaStar_PVZ[anti][2]->Fill(phiStar, protonCosTheta);
            hPhiStar_PVZ[anti][2]->Fill(phiStar);
        }
        if (pvz_ > -400 && pvz_ < -350) {
            hPhiStarCosThetaStar_PVZ[anti][3]->Fill(phiStar, protonCosTheta);
            hPhiStar_PVZ[anti][3]->Fill(phiStar);
        }

        // Fill rapidity-binned phi* vs cos(theta*)
        if (Ks_Y > rapidity_bins[0] && Ks_Y < rapidity_bins[1]) hPhiStarCosThetaStar_rapidity[anti][0]->Fill(phiStar, protonCosTheta);
        if (Ks_Y > rapidity_bins[1] && Ks_Y < rapidity_bins[2]) hPhiStarCosThetaStar_rapidity[anti][1]->Fill(phiStar, protonCosTheta);
        if (Ks_Y > rapidity_bins[2] && Ks_Y < rapidity_bins[3]) hPhiStarCosThetaStar_rapidity[anti][2]->Fill(phiStar, protonCosTheta);
        if (Ks_Y > rapidity_bins[3] && Ks_Y < rapidity_bins[4]) hPhiStarCosThetaStar_rapidity[anti][3]->Fill(phiStar, protonCosTheta);

        // Fill pT-binned phi* vs cos(theta*)
        if (LambdapT > 600 && LambdapT < 700) hPhiStarCosThetaStar_pT[anti][0]->Fill(phiStar, protonCosTheta);
        if (LambdapT > 700 && LambdapT < 800) hPhiStarCosThetaStar_pT[anti][1]->Fill(phiStar, protonCosTheta);
        if (LambdapT > 850 && LambdapT < 900) hPhiStarCosThetaStar_pT[anti][2]->Fill(phiStar, protonCosTheta);
        if (LambdapT > 900 && LambdapT < 1000) hPhiStarCosThetaStar_pT[anti][3]->Fill(phiStar, protonCosTheta);

        // Fill phi* vs BPVIPCHI2
        hPhi_BPVIPCHI2[anti]->Fill(phiStar, pi_minus_BPVIPCHI2);

        // Fill particle-wise phi* correlations (Ks, proton, pion)
        hPhiStar_Mom[0]->Fill(phiStar, Ks_PT);
        hPhiStar_rap[0]->Fill(phiStar, Ks_Y);
        hPhiStar_eta[0]->Fill(phiStar, Ks_ETA);
        hPhiStar_phi[0]->Fill(phiStar, Ks_PHI);

        hPhiStar_Mom[1]->Fill(phiStar, pi_plus_PT);
        hPhiStar_rap[1]->Fill(phiStar, pi_plus_Y);
        hPhiStar_eta[1]->Fill(phiStar, pi_plus_ETA);
        hPhiStar_phi[1]->Fill(phiStar, pi_plus_PHI);

        hPhiStar_Mom[2]->Fill(phiStar, pi_minus_PT);
        hPhiStar_rap[2]->Fill(phiStar, pi_minus_Y);
        hPhiStar_eta[2]->Fill(phiStar, pi_minus_ETA);
        hPhiStar_phi[2]->Fill(phiStar, pi_minus_PHI);
    }

    // Normalize cos(theta*) distributions
    for (int iAnti = 0; iAnti < 2; iAnti++) {
        for (int iCent = 0; iCent < 3; iCent++) {
            hCosTheta[iAnti][iCent]->Sumw2();
            hCosTheta[iAnti][iCent]->Scale(1. / hCosTheta[iAnti][iCent]->GetEntries());
        }
    }

    // === WRITE OUTPUT ROOT FILE ===
    TFile *outFile = new TFile(Form("out_root/TV_PbPb2024_K0S%d.root", iFile), "RECREATE");

    // Write global QA
    hPVZ->Write();
    hDIRA->Write();
    hDOCchi2->Write();
   for(int iAnti = 0; iAnti < 2; iAnti++){
      hMassInvariant[iAnti] -> Write();
      hRapidity[iAnti] -> Write();
      hCosTheta[iAnti][0] -> Write();
      hCosTheta[iAnti][1] -> Write();
      hCosTheta[iAnti][2] -> Write();

      pToroidalMulti[iAnti] -> Write();
      pToroidalRap[iAnti] -> Write();
      pToroidalMulti_rapCut[iAnti] -> Write();
      pToroidalMulti_phiStarCut[iAnti] -> Write();
      pToroidalRap_phiStarCut[iAnti] -> Write();

      for(int iPVZ = 0; iPVZ <4; iPVZ++){
         hPhiStarCosThetaStar_PVZ[iAnti][iPVZ] -> Write();
         hPhiStarCosThetaStar_rapidity[iAnti][iPVZ] -> Write();
         hPhiStar_PVZ[iAnti][iPVZ] -> Write();
         hPhiStarCosThetaStar_pT[iAnti][iPVZ] -> Write();
      }

      hProtonIpChi2[iAnti] -> Write();
      hMassInvariant[iAnti] -> Write(); 
      hRapidity[iAnti] -> Write();
      hnVeloTracks[iAnti] -> Write();
      hPhiStarCosThetaStar[iAnti] -> Write();
      hPhiStar[iAnti] -> Write();
      hPhiLambda[iAnti]->Write();
      hPtLambda[iAnti]->Write();
      hLambdaPt_Phi_Eta[iAnti]->Write();
      hPtLambdaPtProton[iAnti]->Write();
      hPLambdaPProton[iAnti]->Write();
      hProtonPhiThetaLabFrame[iAnti]->Write();
      hProtonPhiLabFrame[iAnti]->Write();
      hProtonPhiLambdaPt[iAnti]->Write();
      hProtonPhiStarProtonPhi[iAnti]->Write();
      hProtonPhiStarProtonTheta[iAnti]->Write();
      hProtonPhiStarPionPt[iAnti]->Write();
      hProtonPhiStarPionRap[iAnti]->Write();
      hPionPtRap[iAnti]->Write();
      hProtonPtRap[iAnti]->Write();


      hpi_plus_pt[iAnti]->Write();
      hpi_minus_pt[iAnti]->Write();
      hpi_plus_phi[iAnti]->Write();
      hpi_minus_phi[iAnti]->Write();
      hKs_pt[iAnti]->Write();
      hKs_phi[iAnti]->Write();

      hPhi_BPVIPCHI2[iAnti]->Write();
      hPionPhi_LambdaPhi[iAnti]->Write();
      hProtonPhi_LambdaPhi[iAnti]->Write();
   }

   for(int iPart = 0; iPart < 3; iPart++){
      hPhiStar_Mom[iPart]->Write();
      hPhiStar_rap[iPart]->Write();
      hPhiStar_eta[iPart]->Write();
      hPhiStar_phi[iPart]->Write();
   }
   outFile->Close();

}
