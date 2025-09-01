/****************************************************************************************
 *  toroidalVorticitySmog.C
 *  
 *  Author: Maria Stefaniak
 *  Created: 2025
 *  
 *  Description:
 *  -----------------------------------------------------------------------------
 *  This macro performs event-by-event analysis of Λ and anti-Λ hyperon decays 
 *  from SMOG fixed-target p+Ar collisions in LHCb data. The goal is to extract 
 *  observables related to the polarization of hyperons, with a special focus on
 *  the toroidal vorticity signatures by analyzing the angular distributions 
 *  of daughter protons in the Lambda rest frame.
 * 
 *  The analysis includes:
 *    - Selection of high-purity Lambda and anti-Lambda candidates
 *    - Boosting proton tracks to the Lambda rest frame
 *    - Calculation of polarization observables: cos(θ*) and φ*
 *    - Event categorization by pT, xF, and φ* bins
 *    - Histogramming of mass, rapidity, pT, xF, and angular correlations
 *
 *  The output is a ROOT file containing histograms to be used for polarization
 *  extraction and fitting in various phase space bins.
 *
 *  Input:
 *    - A ROOT TTree (from a LHCb ntuple) accessible via fChain
 *
 *  Output:
 *    - ROOT file with polarization-related histograms and diagnostics
 *
 *  Dependencies:
 *    - Requires ROOT libraries (TTree, TLorentzVector, TH1D, TH2D, etc.)
 *    - Header: toroidalVorticitySmog.h
 *
 *  Notes:
 *    - Assumes center-of-mass rapidity yCM = 4.29 for p+Ar fixed-target collisions
 *    - Alpha decay parameter for Λ/anti-Λ used for polarization scaling
 *    - Designed for data from LHCb SMOG runs (e.g., 2024 dataset)
 *
 ***************************************************************************************/


#define toroidalVorticitySmog_cxx
#include "toroidalVorticitySmog.h"
#include <TH2.h>
#include <TH3.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TProfile.h>

void toroidalVorticitySmog::Loop()
{
    // Constants and physical parameters
    double pi = TMath::Pi();
    double yCM = 4.29;                     // Center-of-mass rapidity
    double alpha_lamb = 0.732;            // Decay parameter for Lambda
    double alpha_Antilamb = -0.732;       // Decay parameter for anti-Lambda

    // Multiplicity and rapidity binning
    double multiplicity_bins[4] = {0.0, 16, 25, 200.0};  // Bins for nVeloTracks
    double rapidity_bins[5] = {-3.0, -1.32, -1.0, -0.5, 1.0};

    // Particle type flag: 0 for anti-Lambda, 1 for Lambda
    int anti = 0;

    // Histogram title for polarization observable
    char rtitle[200] = "#frac{3}{#alpha_{#Lambda}}#hat{p}_{p}^{*}#bullet(#hat{z}#times#hat{p}_{#Lambda})";

    // pT binning
    const int nrPtBins = 4;
    double pTbins[nrPtBins+1] = {294.0, 622.977, 857.086, 1156.08, 3000};

    // Histogram binning setup
    const int nrCosThetaBins = 30;
    int maxTVelo = 250;

    // 1D histograms for event-level quantities
    TH1D *hPVZ = new TH1D("hPVZ", "hPVZ; PVZ [cm]", 1000, -600, 500);
    TH1D *hBackwardTracks = new TH1D("hBackwardTracks", "hBackwardTracks; nr of Backward Tracks", 100, 0, 100);
    TH1D *hnVeloTracks = new TH1D("nVeloTracks", "nVeloTracks; nVeloTracks", maxTVelo, 0, maxTVelo);

    // Arrays of histograms per particle type (0=anti-Lambda, 1=Lambda)
    TH1D *hMassInvariant[2], *hRapidity[2], *hPhiLambda[2], *hPtLambda[2], *hIPchi2[2], *hXf[2];
    TH1D *hMassInvariantInPt[2][nrPtBins];

    TH2D *hPionPtRap[2], *hProtonPtRap[2];

    const int nrPhiStarBins = 3;
    double phiStar_bins[nrPhiStarBins+1] = {0, 2.8, 4.8, 2*pi};
    TH1D *hMassInvariantInPhi[2][nrPhiStarBins];

    const int nrXfBins = 4;
    double xF_bins[nrXfBins+1] = {-0.3, -0.0443759, -0.024845, 0, 0.097};

    TH2D *hPhiStarCosThetaStar[2], *hxFCosThetaStar[2];
    TH2D *hpTCosThetaStar[2][nrXfBins], *hMultiCosThetaStar[2][nrXfBins];

    // Diagnostic histogram
    TH2D *hYlambdaCosThetaStar = new TH2D("hYlambdaCosThetaStar", "hYlambdaCosThetaStar; y_Lambda; cos #theta^{*}", 50, -3, 1, nrCosThetaBins, -1, 1);

    // Initialize histograms per particle type
    for(int iAnti = 0; iAnti < 2; iAnti++) {
        hMassInvariant[iAnti] = new TH1D(Form("MassInvariant_%d",iAnti), Form("MassInvariant %d; mass_{inv} [MeV/c^{2}]",iAnti), 200 ,1108, 1125);
        hRapidity[iAnti] = new TH1D(Form("Rapidity_%d",iAnti), Form("Rapidity %d; y-y_{NN}",iAnti), 100, -5, 5);
        hPhiLambda[iAnti] = new TH1D(Form("LambdaPhi_%d", iAnti), Form("LambdaPhi_%d; #phi_{#Lambda}", iAnti), 80, -pi, pi);
        hPtLambda[iAnti] = new TH1D(Form("LambdaPt_%d", iAnti), Form("LambdaPt_%d; p_{T, #Lambda} [MeV/c]", iAnti), 500, 0, 3000);
        hIPchi2[iAnti] = new TH1D(Form("LambdaIPchi2_%d", iAnti), Form("LambdaIPCHi2_%d; IP Chi^{2}", iAnti), 500, 0, 10);
        hXf[iAnti] = new TH1D(Form("LambdaXf_%d", iAnti), Form("LambdaXf_%d; xF", iAnti), 500, -0.3, 0.1);

        hPionPtRap[iAnti] = new TH2D(Form("pion_pt_rap_%d", iAnti), Form("pion_pt_rap_%d; p_{T, #pi}; y_{#pi}", iAnti), 500, 0, 1000, 100, 2, 5);
        hProtonPtRap[iAnti] = new TH2D(Form("proton_pt_rap_%d", iAnti), Form("proton_pt_rap_%d; p_{T, p}; y_{p}", iAnti), 500, 0, 1000, 100, 2, 5);

        hPhiStarCosThetaStar[iAnti] = new TH2D(Form("PhiStarCosThetaStar_%d",iAnti), Form("Phi * vs cos Theta * %d; #phi^{*}; cos #theta^{*}",iAnti), 80 ,0,2*pi, nrCosThetaBins, -1, 1);
        hxFCosThetaStar[iAnti] = new TH2D(Form("xFCosThetaStar_%d",iAnti), Form("x_{F} * vs cos Theta * %d; x_{F}; cos #theta^{*}",iAnti), 500, -0.3, 0.01, nrCosThetaBins, -1, 1);

        for(int i = 0; i < nrXfBins; i++) {
            hpTCosThetaStar[iAnti][i] = new TH2D(Form("hpTCosThetaStar_%d_xf%d", iAnti, i), Form("hpTCosThetaStar_%d_xf%d; p_{T, #Lambda}; cos #theta^{*}", iAnti, i), 100, 0, 2000, nrCosThetaBins, -1, 1);
            hMultiCosThetaStar[iAnti][i] = new TH2D(Form("hMultiCosThetaStar_%d_xf%d", iAnti, i), Form("hMultiCosThetaStar_%d_xf%d; nVeloTracks; cos #theta^{*}", iAnti, i), maxTVelo, 0, maxTVelo, nrCosThetaBins, -1, 1);
        }

        for(int i = 0; i < nrPhiStarBins; i++) {
            hMassInvariantInPhi[iAnti][i] = new TH1D(Form("MassInvariant_%d_phi%d",iAnti,i), Form("MassInvariant %d in phi bin %d; mass_{inv} [MeV/c^{2}]",iAnti,i), 200 ,1108, 1125);
        }

        for(int i = 0; i < nrPtBins; i++) {
            hMassInvariantInPt[iAnti][i] = new TH1D(Form("MassInvariant_%d_pT%d",iAnti,i), Form("MassInvariant %d in pT bin %d; mass_{inv} [MeV/c^{2}]",iAnti,i), 200 ,1108, 1125);
        }
    }

    // Load data entries
    if (fChain == 0) return;
    Long64_t nentries = fChain->GetEntriesFast();
    Long64_t nbytes = 0, nb = 0;

    // Event loop
    for (Long64_t jentry = 0; jentry < nentries; jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry); nbytes += nb;

        anti = (LambdaT_ID < 0) ? 0 : 1;

        // Event selection (SMOG p+Ar)
        if (SMOGInjectedGas != 7) continue;
        if (BUNCHCROSSING_TYPE != 1) continue;

        hBackwardTracks->Fill(nBackTracks);
        hPVZ->Fill(PVZ[0]);
        if (nBackTracks > 5) continue;
        if (nPVs != 1) continue;

        hnVeloTracks->Fill(nVeloTracks);

        // Lambda candidate selection
        hIPchi2[anti]->Fill(LambdaT_BPVIPCHI2);
        if (LambdaT_BPVIPCHI2 > 1.5) continue;
        if (LambdaT_MASS < 1111 || LambdaT_MASS > 1121) continue;
        if (LambdaT_PT < 300) continue;

        // Daughter cuts
        if (pbar_PT < 100 || pim_PT < 100) continue;
        if (pbar_P < 2000 || pim_P < 2000) continue;

        // Reconstruct momenta and derived variables
        TVector3 Lambda3Mom(LambdaT_PX, LambdaT_PY, LambdaT_PZ);
        TVector3 p3Mom(pbar_PX, pbar_PY, pbar_PZ);
        TVector3 pi3Mom(pim_PX, pim_PY, pim_PZ);

        double xf = (2.0 / 68000.0) * TMath::Sqrt(LambdaT_MASS*LambdaT_MASS + LambdaT_PT*LambdaT_PT) * TMath::SinH(LambdaT_Y - yCM);

        TLorentzVector Lambda4Momentum(LambdaT_PX, LambdaT_PY, LambdaT_PZ, LambdaT_ENERGY);
        TLorentzVector Proton4Momentum(pbar_PX, pbar_PY, pbar_PZ, pbar_ENERGY);

        // Boost proton to Lambda rest frame
        TLorentzVector Proton4MomStar = Proton4Momentum;
        Proton4MomStar.Boost(-Lambda4Momentum.BoostVector());
        TVector3 Proton3MomStar(Proton4MomStar.Vect());

        // Construct normal vector to production plane
        TVector3 BeamMomHat(0, 0, 1);
        TVector3 nVec = BeamMomHat.Cross(Lambda3Mom).Unit();

        // Polarization observable: cos(theta*)
        double cosThetaStar = (Proton3MomStar.Dot(nVec)) / (Proton3MomStar.Mag() * nVec.Mag());

        // Polarization observable: phi*
        TVector3 uVec = Proton3MomStar.Mag() * cosThetaStar * nVec;
        TVector3 aVec = Proton3MomStar - uVec;
        double phiStar = acos((aVec.Dot(Lambda3Mom)) / (aVec.Mag() * Lambda3Mom.Mag()));
        if (nVec.Dot(aVec.Cross(Lambda3Mom)) > 0) phiStar = 2 * pi - phiStar;

        // Fill histograms
        hMassInvariant[anti]->Fill(LambdaT_MASS);
        hPionPtRap[anti]->Fill(pim_PT, pim_Y);
        hProtonPtRap[anti]->Fill(pbar_PT, pbar_Y);
        hPhiLambda[anti]->Fill(Lambda3Mom.Phi());
        hRapidity[anti]->Fill(LambdaT_Y - yCM);
        hPtLambda[anti]->Fill(LambdaT_PT);
        hXf[anti]->Fill(xf);
        hPhiStarCosThetaStar[anti]->Fill(phiStar, cosThetaStar);
        hYlambdaCosThetaStar->Fill(LambdaT_Y - yCM, cosThetaStar);

        // Bin-by-bin population
        if (phiStar > 2.8 && phiStar < 4.8) {
            hxFCosThetaStar[anti]->Fill(xf, cosThetaStar);
            for (int ixf = 0; ixf < nrXfBins; ixf++) {
                if (xf >= xF_bins[ixf] && xf < xF_bins[ixf+1]) {
                    hpTCosThetaStar[anti][ixf]->Fill(LambdaT_PT, cosThetaStar);
                    hMultiCosThetaStar[anti][ixf]->Fill(nVeloTracks, cosThetaStar);
                }
            }
        }

        for (int iphi = 0; iphi < nrPhiStarBins; iphi++) {
            if (phiStar >= phiStar_bins[iphi] && phiStar < phiStar_bins[iphi+1]) {
                hMassInvariantInPhi[anti][iphi]->Fill(LambdaT_MASS);
            }
        }

        for (int ipt = 0; ipt < nrPtBins; ipt++) {
            if (LambdaT_PT >= pTbins[ipt] && LambdaT_PT < pTbins[ipt+1]) {
                hMassInvariantInPt[anti][ipt]->Fill(LambdaT_MASS);
            }
        }
    }

    // Save output
    TFile *outFile = new TFile(Form("out_root_new/Polarization_pAr_data_L0_AL0%d_test.root", iFile), "RECREATE");
    hPVZ->Write(); hBackwardTracks->Write(); hnVeloTracks->Write();
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
        for (int i = 0; i < nrXfBins; i++) {
            hpTCosThetaStar[iAnti][i]->Write();
            hMultiCosThetaStar[iAnti][i]->Write();
        }
        for (int i = 0; i < nrPhiStarBins; i++) {
            hMassInvariantInPhi[iAnti][i]->Write();
        }
        for (int i = 0; i < nrPtBins; i++) {
            hMassInvariantInPt[iAnti][i]->Write();
        }
    }
    hYlambdaCosThetaStar->Write();
}