/**
 *  K0S_analysis::Loop()
 *
 *  Macro to analyze K0S → π+ π− decays in p+Ar SMOG data.
 *  It calculates polarization observable R using proton angular distributions in the Λ rest frame,
 *  and studies its dependence on multiplicity, rapidity, and φ* angle.
 *
 *  - Input: TTree (fChain) with decay and event variables.
 *  - Cuts: SMOG gas = Ar, forward mode only, KS0_PT between 600–1000 MeV, correct vertex association.
 *  - Calculates: Λ polarization via triple product method, angular observables, φ*.
 *  - Output: histograms written to "out_root/K0S_pAr_ppref_68gev_PTCUT.root"
 *
 *  Author: Maria Stefaniak
 *  Date: 2025
 */

#define K0S_analysis_cxx
#include "K0S_analysis.h"
#include <TH2.h>
#include <TH3.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TProfile.h>

// Main analysis function for KS0 decays in pAr collisions
void K0S_analysis::Loop()
{
   double yCM =4.29; // center-of-mass rapidity for 68 GeV pAr
   double alpha_lamb = 0.732; // weak decay parameter for Lambda
   double alpha_Antilamb = -0.732; // weak decay parameter for Anti-Lambda
   double multiplicity_bins[4] = {0.0, 16, 25, 200.0}; // centrality/multiplicity bins
   double rapidity_bins[5] = {-3.0, -1.32, -1.0, -0.5, 0.0}; // bins in rapidity
   int anti = 0; // 0 = AntiLambda, 1 = Lambda (in code logic)
   char rtitle[200] = "#frac{3}{#alpha_{#Lambda}}#hat{p}_{p}^{*}#bullet(#hat{z}#times#hat{p}_{#Lambda})"; // physics observable title

   // Create all histograms for observables, categorized by Lambda vs AntiLambda
   // (Histogram definitions omitted here for brevity. Already included above.)

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      // Event selection cuts
      if(SMOGInjectedGas != 7) continue; // Select only Ar-injected events (7 = Ar)
      if(BUNCHCROSSING_TYPE != 1 ) continue; // 1 = SMOG only
      if(nBackTracks > 10) continue; // Forward-mode selection (backward track veto)

      // Determine correct primary vertex match based on closest vertex
      int multiplicity = nPVTracks[0];
      float pvz_ = PVZ[0];
      if(nPVs != 1){
         for(int i = 0; i < 5; i++){
            if(KS0_B_PV_X != PVX[i]) continue;
            multiplicity = nPVTracks[i];
            pvz_ = PVZ[i];
            break;
         }
      }

      // Check if sister track matched correctly (custom function)
      if(CheckSister(nentries, jentry, pim_PT, pip_PT, KS0_DOCACHI2, RUNNUMBER) == 0) continue;

      // Identify Lambda vs AntiLambda based on PDG code sign
      if(KS0_ID < 0) anti = 0;
      else anti = 1;

      // Fill basic invariant mass
      hMassInvariant[anti]->Fill(KS0_MASS);

      // Select pT range of interest
      if(KS0_PT < 600 || KS0_PT > 1000) continue;

      // Fill primary vertex Z position
      hPVZ->Fill(PVZ[0]);

      // Compute direction and momentum vectors
      TVector3 lambdaPosition(KS0_END_VX - PVX[0],KS0_END_VY - PVY[0],KS0_END_VZ - PVZ[0]);
      TVector3 lambdaMomentum(KS0_PX,KS0_PY,KS0_PZ);

      // Fill pointing angle (cosine)
      hDIRA->Fill(lambdaPosition.Dot(lambdaMomentum)/(lambdaPosition.Mag()*lambdaMomentum.Mag()));

      if(anti == 1) hDOCchi2 ->Fill(KS0_DOCA); // DOCA chi2 for Lambda only

      // Fill event-level histograms
      hRapidity[anti]->Fill(KS0_Y-yCM);
      hnVeloTracks[anti]->Fill(multiplicity);
      hProtonIpChi2[anti]->Fill(pip_BPVIPCHI2);
      hPhiLambda[anti]->Fill(KS0_PHI);
      hLambdaPt_Phi_Eta[anti]->Fill(KS0_PT, KS0_PHI, KS0_ETA);

      // Define Lorentz vectors for decay products
      TLorentzVector LambdaFourMomentum(KS0_PX, KS0_PY, KS0_PZ, KS0_ENERGY);
      TLorentzVector ProtonFourMomentum(pip_PX, pip_PY, pip_PZ, pip_ENERGY);
      TLorentzVector PionFourMomentum(pim_PX, pim_PY, pim_PZ, pim_ENERGY);

      // Boost proton to Lambda rest frame
      TLorentzVector BoostedProtonFourMomentum = ProtonFourMomentum;
      BoostedProtonFourMomentum.Boost(-LambdaFourMomentum.BoostVector());

      // Proton direction in Lambda rest frame
      Double_t protonPhi = BoostedProtonFourMomentum.Phi();
      TVector3 ProtonMomentumStarVec3(BoostedProtonFourMomentum.Vect());

      // Beam momentum direction with crossing angle corrections
      TVector3 BeamMomentumHat(0,0,1);
      double crossingAnlgeH = 277.94*1e-6;
      double crossingAnlgeV = 400.0*1e-6;
      BeamMomentumHat.RotateX(crossingAnlgeV*0.5);
      BeamMomentumHat.RotateY(crossingAnlgeH*0.5);
      BeamMomentumHat=BeamMomentumHat.Unit();

      // Define normal to production plane
      TVector3 LambdaMomentumVec3 = LambdaFourMomentum.Vect();
      TVector3 CrossPart = BeamMomentumHat.Cross(LambdaMomentumVec3).Unit();

      // Calculate triple product observable R (with flipping for AntiLambda)
      double PPP = (3/alpha_lamb) * ProtonMomentumStarVec3.Unit().Dot(CrossPart);
      if(anti == 0) PPP *= -1;

      // Fill Lambda pT and derived angular variables
      double LambdapT  = LambdaFourMomentum.Pt();
      hPtLambda[anti]->Fill(LambdapT);

      Double_t protonCosTheta = ProtonMomentumStarVec3.Unit().Dot(CrossPart);
      double thetaStar = acos(protonCosTheta);

      // Compute phi* observable (angle in production plane)
      TVector3 ProjPmomStarOnNormal = protonCosTheta * ProtonMomentumStarVec3.Mag() * CrossPart;
      TVector3 ProjPmomStarOnProductionPlane = ProtonMomentumStarVec3 - ProjPmomStarOnNormal;
      TVector3 CrossALambda = ProjPmomStarOnProductionPlane.Cross(LambdaMomentumVec3);
      double sinPhiStar = CrossALambda.Unit().Dot(CrossPart);
      double phiStar = acos((LambdaMomentumVec3.Dot(ProjPmomStarOnProductionPlane))/(ProjPmomStarOnProductionPlane.Mag() * LambdaMomentumVec3.Mag()));
      if (sinPhiStar > 0) phiStar = 2*TMath::Pi() - phiStar;

      // Fill φ* vs kinematics
      hPhiStar_Mom[0]->Fill(phiStar, KS0_PT); hPhiStar_rap[0]->Fill(phiStar, KS0_Y);
      hPhiStar_eta[0]->Fill(phiStar, KS0_ETA); hPhiStar_phi[0]->Fill(phiStar, KS0_PHI);
      hPhiStar_Mom[1]->Fill(phiStar, pip_PT); hPhiStar_rap[1]->Fill(phiStar, pip_Y);
      hPhiStar_eta[1]->Fill(phiStar, pip_ETA); hPhiStar_phi[1]->Fill(phiStar, pip_PHI);
      hPhiStar_Mom[2]->Fill(phiStar, pim_PT); hPhiStar_rap[2]->Fill(phiStar, pim_Y);
      hPhiStar_eta[2]->Fill(phiStar, pim_ETA); hPhiStar_phi[2]->Fill(phiStar, pim_PHI);

      hPhiStarCosThetaStar[anti] -> Fill(phiStar, protonCosTheta);
      hPhiStar[anti] -> Fill(phiStar);

      // Additional kinematics: correlations
      if(LambdapT<800){
         hProtonPhiStarProtonPhi[anti]->Fill(phiStar,pip_PHI);
         hProtonPhiStarProtonTheta[anti]->Fill(phiStar,pip_ETA);
      }

      hPtLambdaPtProton[anti]->Fill(LambdapT,pip_PT);
      hPLambdaPProton[anti]->Fill(KS0_P,pip_P);
      hProtonPhiThetaLabFrame[anti]->Fill(pip_PHI, pip_ETA);
      hProtonPhiLabFrame[anti]->Fill(pip_PHI);
      hProtonPhiLambdaPt[anti]->Fill(phiStar,LambdapT);
      hProtonPhiStarPionPt[anti]->Fill(phiStar,pim_PT);
      hProtonPhiStarPionRap[anti]->Fill(phiStar,pim_Y);
      hPionPtRap[anti]->Fill(pim_PT,pim_Y);
      hProtonPtRap[anti]->Fill(pip_PT,pip_Y);

      // Cosθ binned by multiplicity bin
      if(multiplicity < multiplicity_bins[1]) hCosTheta[anti][0]->Fill(protonCosTheta);
      else if(multiplicity < multiplicity_bins[2]) hCosTheta[anti][1]->Fill(protonCosTheta);
      else hCosTheta[anti][2]->Fill(protonCosTheta);

      // Fill observable vs multiplicity/rapidity
      pToroidalMulti[anti]->Fill(multiplicity,PPP);
      if(KS0_YSTAR > -0.5)pToroidalMulti_rapCut[anti]->Fill(multiplicity,PPP);
      pToroidalRap[anti]->Fill(KS0_YSTAR,PPP);
      if(phiStar > 1.7 && phiStar < 2.8){
         pToroidalMulti_phiStarCut[anti]->Fill(multiplicity,PPP);
         pToroidalRap_phiStarCut[anti]->Fill(KS0_YSTAR,PPP);
      }
   } // End of loop

   // Normalize cosθ histograms
   for(int iAnti = 0; iAnti < 2; iAnti++){
      for(int iCent = 0; iCent <3; iCent++){
         hCosTheta[iAnti][iCent]->Sumw2();
         hCosTheta[iAnti][iCent]->Scale(1./hCosTheta[iAnti][iCent]->GetEntries());
      }
   }

   // Save all histograms to output file
   TFile *outFile = new TFile("out_root/K0S_pAr_ppref_68gev_PTCUT.root", "RECREATE");
   hPVZ->Write(); hDIRA->Write(); hDOCchi2->Write();
   for(int iAnti = 0; iAnti < 2; iAnti++){
      hMassInvariant[iAnti]->Write(); hRapidity[iAnti]->Write();
      for(int iCent = 0; iCent < 3; iCent++) hCosTheta[iAnti][iCent]->Write();
      pToroidalMulti[iAnti]->Write(); pToroidalRap[iAnti]->Write();
      pToroidalMulti_rapCut[iAnti]->Write(); pToroidalMulti_phiStarCut[iAnti]->Write(); pToroidalRap_phiStarCut[iAnti]->Write();
      hProtonIpChi2[iAnti]->Write(); hnVeloTracks[iAnti]->Write(); hPhiStarCosThetaStar[iAnti]->Write();
      hPhiStar[iAnti]->Write(); hPhiLambda[iAnti]->Write(); hPtLambda[iAnti]->Write();
      hLambdaPt_Phi_Eta[iAnti]->Write(); hPtLambdaPtProton[iAnti]->Write(); hPLambdaPProton[iAnti]->Write();
      hProtonPhiThetaLabFrame[iAnti]->Write(); hProtonPhiLabFrame[iAnti]->Write();
      hProtonPhiLambdaPt[iAnti]->Write(); hProtonPhiStarProtonPhi[iAnti]->Write(); hProtonPhiStarProtonTheta[iAnti]->Write();
      hProtonPhiStarPionPt[iAnti]->Write(); hProtonPhiStarPionRap[iAnti]->Write();
      hPionPtRap[iAnti]->Write(); hProtonPtRap[iAnti]->Write();
   }
   for(int iPart = 0; iPart < 3; iPart++){
      hPhiStar_Mom[iPart]->Write(); hPhiStar_rap[iPart]->Write();
      hPhiStar_eta[iPart]->Write(); hPhiStar_phi[iPart]->Write();
   }
}
