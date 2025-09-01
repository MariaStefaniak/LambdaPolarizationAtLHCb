// ==========================================================================
// toroidalVorticityPbPb::Loop()
//
// Author: Maria Stefaniak (2025)
//
// Description:
// This method implements the main analysis loop over Lambda and AntiLambda
// candidates reconstructed in Pb–Pb collisions at √sNN = 5.02 TeV recorded by
// LHCb in 2024. It applies event selection, topological, and kinematic cuts,
// calculates polarization-sensitive observables (cosθ*, ϕ*), and categorizes
// the signal in multiple phase-space dimensions.
//
// Categories include:
//   - Transverse momentum (pT)
//   - Feynman x (xF)
//   - Rapidity (y)
//   - Production-plane angle (ϕ*)
//
// The method creates histograms of signal and angular observables, binned
// accordingly, and writes the outputs to ROOT files separately for real data
// and Monte Carlo samples.
//
// Note:
//   - anti = 0: AntiLambda
//   - anti = 1: Lambda
//   - ϕ* and cosθ* are calculated in the Λ rest frame (helicity frame).
//
// ==========================================================================


void toroidalVorticityPbPb::Loop()
{
   // === Constants ===
   double pi = TMath::Pi();
   double yCM = 0; // Center-of-mass rapidity (0 for symmetric system)
   double alpha_lamb = 0.732;       // Decay parameter for Λ
   double alpha_Antilamb = -0.732;  // Decay parameter for anti-Λ

   // === Binning Configuration ===
   double multiplicity_bins[4] = {0, 335.427, 620.213, 2475}; // PbPb centrality proxy
   const int nrYBins = 4;
   double rapidity_bins[nrYBins+1] = {2.0, 3.1, 3.4, 3.7, 5.0};

   const int nrPtBins = 4;
   double pTbins[nrPtBins+1] = {1010, 1481.03, 1786.21, 2216.64, 5000}; // pT in MeV/c

   const int nrXfBins = 4;
   double xF_bins[nrXfBins+1] = {0.082, 0.312714, 0.496583, 1}; // Feynman-x bins

   const int nrPhiStarBins = 3;
   double phiStar_bins[nrPhiStarBins+1] = {0, 2.8, 4.8, 2*pi};

   const int nrCosThetaBins = 10; // Uniform binning for cosθ*

   int maxTVelo = 250; // max track multiplicity to bin

   // === Histograms Initialization ===
   // Basic event-level QA
   TH1D *hPVZ = new TH1D("hPVZ", "hPVZ; PVZ [cm]", 1000, -600, 500);
   TH1D *hBackwardTracks = new TH1D("hBackwardTracks", "hBackwardTracks; nr of Backward Tracks", 100, 0, 100);
   TH1D *hnVeloTracks = new TH1D("nVeloTracks", "nVeloTracks; nVeloTracks", maxTVelo, 0, maxTVelo);

   // Particle and daughter-level histograms — split by antiLambda (0) / Lambda (1)
   TH1D *hMassInvariant[2], *hRapidity[2], *hPhiLambda[2], *hPtLambda[2], *hIPchi2[2], *hXf[2], *hMassInvariantInPt[2][nrPtBins]; 
   TH2D *hPionPtRap[2], *hProtonPtRap[2];
   TH1D *hMassInvariantInPhi[2][nrPhiStarBins];

   // Angular distributions for polarization observables
   TH2D *hPhiStarCosThetaStar[2], *hxFCosThetaStar[2], *hpTCosThetaStar[2][nrXfBins], *hMultiCosThetaStar[2][nrXfBins]; 
   TH2D *hpTLambdaCosThetaStar[2], *hYCosThetaStar[2];
   TH1D *hCosThetaInPtBins[2][nrPtBins];
   TH1D *hCosThetaInXfBins[2][nrXfBins];
   TH1D *hCosThetaInYBins[2][nrYBins];
   TH2D *hPhiStarCosThetaStarInXf[2][nrXfBins];

   // Debug/test histogram
   TH2D *hYlambdaCosThetaStar = new TH2D("hYlambdaCosThetaStar", "hYlambdaCosThetaStar; y_Lambda; cos #theta^{*}", 50, -3, 1, nrCosThetaBins, -1, 1);

   // === Histogram Booking ===
   for(int iAnti = 0; iAnti < 2; iAnti++) {
      // QA and kinematics
      hMassInvariant[iAnti] = new TH1D(Form("MassInvariant_%d", iAnti), "mass_{inv} [MeV/c^{2}]", 200, 1108, 1125);
      hRapidity[iAnti] = new TH1D(Form("Rapidity_%d", iAnti), "y-y_{NN}", 100, -5, 5);
      hPhiLambda[iAnti] = new TH1D(Form("LambdaPhi_%d", iAnti), "#phi_{#Lambda}", 80, -pi, pi);
      hPtLambda[iAnti] = new TH1D(Form("LambdaPt_%d", iAnti), "p_{T, #Lambda} [MeV/c]", 500, 0, 5000);
      hIPchi2[iAnti] = new TH1D(Form("LambdaIPchi2_%d", iAnti), "IP Chi^{2}", 500, 0, 10);
      hXf[iAnti] = new TH1D(Form("LambdaXf_%d", iAnti), "xF", 500, 0.0, 1.0);

      // Daughter QA
      hPionPtRap[iAnti] = new TH2D(Form("pion_pt_rap_%d", iAnti), "pion pT vs y", 500, 0, 1000, 100, 2, 5);
      hProtonPtRap[iAnti] = new TH2D(Form("proton_pt_rap_%d", iAnti), "proton pT vs y", 500, 0, 1000, 100, 2, 5);

      // Polarization 2D histograms
      hPhiStarCosThetaStar[iAnti] = new TH2D(Form("PhiStarCosThetaStar_%d", iAnti), "#phi^{*} vs cos #theta^{*}", 80, 0, 2*pi, nrCosThetaBins, -1, 1);
      hxFCosThetaStar[iAnti] = new TH2D(Form("xFCosThetaStar_%d", iAnti), "x_{F} vs cos #theta^{*}", 500, -0.3, 0.01, nrCosThetaBins, -1, 1);
      hpTLambdaCosThetaStar[iAnti] = new TH2D(Form("pTLambdaCosThetaStar_%d", iAnti), "pT vs cos #theta^{*}", 100, 300, 3000, nrCosThetaBins, -1, 1);
      hYCosThetaStar[iAnti] = new TH2D(Form("YCosThetaStar_%d", iAnti), "y vs cos #theta^{*}", 80, 2, 5, nrCosThetaBins, -1, 1);

      for(int i = 0; i < nrXfBins; i++) {
         hpTCosThetaStar[iAnti][i] = new TH2D(Form("hpTCosThetaStar_%d_xf%d", iAnti, i), "pT vs cos #theta^{*}", 100, 0, 2000, nrCosThetaBins, -1, 1);
         hMultiCosThetaStar[iAnti][i] = new TH2D(Form("hMultiCosThetaStar_%d_xf%d", iAnti, i), "Multiplicity vs cos #theta^{*}", maxTVelo, 0, maxTVelo, nrCosThetaBins, -1, 1);
         hCosThetaInXfBins[iAnti][i] = new TH1D(Form("CosTheta_%d_xF%d", iAnti, i), "cos #theta^{*}", 10, -1, 1);
         hPhiStarCosThetaStarInXf[iAnti][i] = new TH2D(Form("PhiStarCosThetaStar_%d_xF%d", iAnti, i), "#phi^{*} vs cos #theta^{*}", 20, 0, 2*pi, nrCosThetaBins, -1, 1);
      }

      for(int i = 0; i < nrYBins; i++) {
         hCosThetaInYBins[iAnti][i] = new TH1D(Form("CosTheta_%d_y%d", iAnti, i), "cos #theta^{*}", 10, -1, 1);
      }

      for(int i = 0; i < nrPhiStarBins; i++) {
         hMassInvariantInPhi[iAnti][i] = new TH1D(Form("MassInvariant_%d_phi%d", iAnti, i), "mass_{inv} [MeV/c^{2}]", 200, 1108, 1125);
      }

      for(int i = 0; i < nrPtBins; i++) {
         hMassInvariantInPt[iAnti][i] = new TH1D(Form("MassInvariant_%d_pT%d", iAnti, i), "mass_{inv} [MeV/c^{2}]", 200, 1108, 1125);
         hCosThetaInPtBins[iAnti][i] = new TH1D(Form("CosTheta_%d_pT%d", iAnti, i), "cos #theta^{*}", 10, -1, 1);
      }
   }

   // ========== EVENT LOOP STARTS HERE ==========
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

   for (Long64_t jentry=0; jentry < nentries*0.1; jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry); nbytes += nb;

      // Determine particle type
      anti = (L0_ID < 0) ? 0 : 1;

      // === Event Selection ===
      hBackwardTracks->Fill(nBackTracks);
      hPVZ->Fill(PVZ[0]);
      if (nBackTracks < 5) continue; // enforce collider mode
      if (nPVs != 1) continue;
      int multiplicity = nVeloTracks;
      hnVeloTracks->Fill(multiplicity);

      // === Lambda Topological Cuts ===
      hIPchi2[anti]->Fill(L0_BPVIPCHI2);
      if (L0_BPVIPCHI2 > 1.5) continue;
      hMassInvariant[anti]->Fill(L0_MASS);
      if (L0_MASS < 1111 || L0_MASS > 1121) continue;
      if (L0_PT < 300) continue;

      // === Daughters PID + Track Quality Cuts ===
      if (p_PT < 100 || pi_PT < 100) continue;
      if (L0_BPVDIRA < 0.9999 || L0_BPVIPCHI2 > 25 || pi_BPVIPCHI2 < 25 || p_BPVIPCHI2 < 25 || 
          pi_PT < 200 || p_PT < 500 || pi_GHOSTPROB > 0.1 || p_GHOSTPROB > 0.1 || L0_BPVFDCHI2 < 130)
          continue;

      // === Kinematic Calculations ===

      // Construct momentum vectors
      TVector3 Lambda3Mom(L0_PX, L0_PY, L0_PZ);
      TVector3 p3Mom(p_PX, p_PY, p_PZ);
      TVector3 pi3Mom(pi_PX, pi_PY, pi_PZ);

      // Extract azimuthal angles (for QA)
      double L0phi = Lambda3Mom.Phi();
      double pphi  = p3Mom.Phi();
      double piphi = pi3Mom.Phi();

      // Construct Lorentz vectors for Λ and daughters
      TLorentzVector Lambda4Momentum; Lambda4Momentum.SetPtEtaPhiM(L0_PT, L0_ETA, L0_PHI, L0_MASS);
      TLorentzVector Proton4Momentum; Proton4Momentum.SetPtEtaPhiM(p_PT, p_ETA, p_PHI, p_MASS);
      TLorentzVector Pion4Momentum;   Pion4Momentum.SetPtEtaPhiM(pi_PT, pi_ETA, pi_PHI, pi_MASS);

      // Calculate rapidity (lab and CM frame)
      double L0_Y = Lambda4Momentum.Rapidity();
      double pi_Y = Pion4Momentum.Rapidity();
      double p_Y  = Proton4Momentum.Rapidity();
      double L0_YSTAR = L0_Y - yCM;

      // Calculate Feynman-x (momentum fraction in z-direction)
      double xf = Lambda3Mom.Pz() / 68000.0;

      // === Fill QA histograms for daughters and Λ kinematics ===
      hPionPtRap[anti]->Fill(pi_PT, pi_Y);
      hProtonPtRap[anti]->Fill(p_PT, p_Y);
      hPhiLambda[anti]->Fill(L0phi);
      hRapidity[anti]->Fill(L0_YSTAR);
      hPtLambda[anti]->Fill(L0_PT);
      hXf[anti]->Fill(xf);

      // === Boost proton into Λ rest frame to compute polarization observables ===
      TLorentzVector Proton4MomStar = Proton4Momentum;
      Proton4MomStar.Boost(-Lambda4Momentum.BoostVector()); // rest frame of Λ
      TVector3 Proton3MomStar(Proton4MomStar.Vect());

      // Beam direction (LHCb beam along +z)
      TVector3 BeamMomHat(0, 0, 1);

      // Normal to production plane: n = ẑ × pΛ
      TVector3 nVec = BeamMomHat.Cross(Lambda3Mom).Unit();

      // cosθ* = angle between p*_p and normal to production plane
      double cosThetaStar = Proton3MomStar.Dot(nVec) / (Proton3MomStar.Mag() * nVec.Mag());

      // Compute φ* (azimuthal angle of p* relative to production plane)
      TVector3 uVec = Proton3MomStar.Mag() * cosThetaStar * nVec;
      TVector3 aVec = Proton3MomStar - uVec;
      double phiStar = acos(aVec.Dot(Lambda3Mom) / (aVec.Mag() * Lambda3Mom.Mag()));
      if (nVec.Dot(aVec.Cross(Lambda3Mom)) > 0) phiStar = 2 * pi - phiStar;

      // === Fill angular histograms (cosθ*, ϕ*, binned) ===
      hPhiStarCosThetaStar[anti]->Fill(phiStar, cosThetaStar);
      hpTLambdaCosThetaStar[anti]->Fill(L0_PT, cosThetaStar);
      hxFCosThetaStar[anti]->Fill(xf, cosThetaStar);

      // Fill xF-binned polarization histograms
      for (int ixf = 0; ixf < nrXfBins; ixf++) {
         if (xf >= xF_bins[ixf] && xf < xF_bins[ixf+1]) {
            hpTCosThetaStar[anti][ixf]->Fill(L0_PT, cosThetaStar);
            hMultiCosThetaStar[anti][ixf]->Fill(multiplicity, cosThetaStar);
            hCosThetaInXfBins[anti][ixf]->Fill(cosThetaStar);
            hPhiStarCosThetaStarInXf[anti][ixf]->Fill(phiStar, cosThetaStar);
         }
      }

      // Fill rapidity-binned polarization histograms
      for (int iY = 0; iY < nrYBins; iY++) {
         if (L0_Y >= rapidity_bins[iY] && L0_Y < rapidity_bins[iY+1]) {
            hCosThetaInYBins[anti][iY]->Fill(cosThetaStar);
         }
      }

      // Fill invariant mass histograms in φ* bins
      for (int iphi = 0; iphi < nrPhiStarBins; iphi++) {
         if (phiStar >= phiStar_bins[iphi] && phiStar < phiStar_bins[iphi+1]) {
            hMassInvariantInPhi[anti][iphi]->Fill(L0_MASS);
         }
      }

      // Fill invariant mass and cosθ* histograms in pT bins
      for (int ipt = 0; ipt < nrPtBins; ipt++) {
         if (L0_PT >= pTbins[ipt] && L0_PT < pTbins[ipt+1]) {
            hMassInvariantInPt[anti][ipt]->Fill(L0_MASS);
            hCosThetaInPtBins[anti][ipt]->Fill(cosThetaStar);
         }
      }

   } // === End of candidate loop ===

   // === Save output ROOT file depending on data/MC flag ===
   TFile *outFile = nullptr;
   if (MC == 0)
      outFile = new TFile(Form("out_root_new/Polarization_PbPb_data_L0_AL0%d.root", iFile), "RECREATE");
   if (MC == 1)
      outFile = new TFile(Form("out_root_new/Polarization_PbPb_MC_L0_AL0%d.root", iFile), "RECREATE");

   // Write QA histograms
   hPVZ->Write();
   hBackwardTracks->Write();
   hnVeloTracks->Write();

   // Write particle and angular histograms
   for (int iAnti = 0; iAnti < 2; iAnti++) {
      hMassInvariant[iAnti]->Write();
      hRapidity[iAnti]->Write();
      hPhiLambda[iAnti]->Write();
      hPtLambda[iAnti]->Write();
      hIPchi2[iAnti]->Write();
      hXf[iAnti]->Write();
      hPionPtRap[iAnti]->Write();
      hProtonPtRap[iAnti]->Write();
      hPhiStarCosThetaStar[iAnti]->Write();
      hxFCosThetaStar[iAnti]->Write();
      hpTLambdaCosThetaStar[iAnti]->Write();
      hYCosThetaStar[iAnti]->Write();

      for (int i = 0; i < nrPhiStarBins; i++) {
         hMassInvariantInPhi[iAnti][i]->Write();
      }

      for (int i = 0; i < nrXfBins; i++) {
         hpTCosThetaStar[iAnti][i]->Write();
         hMultiCosThetaStar[iAnti][i]->Write();
         hCosThetaInXfBins[iAnti][i]->Write();
         hPhiStarCosThetaStarInXf[iAnti][i]->Write();
      }

      for (int ipt = 0; ipt < nrPtBins; ipt++) {
         hMassInvariantInPt[iAnti][ipt]->Write();
         hCosThetaInPtBins[iAnti][ipt]->Write();
      }

      for (int i = 0; i < nrYBins; i++) {
         hCosThetaInYBins[iAnti][i]->Write();
      }
   }

   // File is automatically closed on destruction
}