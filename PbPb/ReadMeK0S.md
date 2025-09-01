/***********************************************************************************************
 *  MACRO: toroidalVorticityPbPb_K0S::Loop()
 *  Author: Maria Stefaniak (2025)
 *
 *  ANALYSIS PURPOSE:
 *  -----------------
 *  This macro analyzes the decay of neutral K⁰ₛ mesons in Pb–Pb collisions recorded by LHCb 
 *  in 2024. It focuses on extracting toroidal vorticity signals via polarization-sensitive 
 *  observables derived from the π⁺π⁻ final state of K0S decays.
 *
 *  In particular, it calculates:
 *    • cosθ* — angle between π⁺ (boosted to K0S rest frame) and normal to production plane
 *    • ϕ*    — azimuthal angle of π⁺ in the K0S rest frame relative to production plane
 *    • Triple product observable (∝ Λ polarization): 
 *           (3/α)·p̂*_π⁺·(ẑ × p̂_K0S)
 *    • Various QA and acceptance correlations
 *
 *  HISTOGRAM STRUCTURE:
 *  --------------------
 *  Histograms are categorized by:
 *    • Particle type (π⁺, π⁻, K0S)
 *    • Event activity (nVELO = multiplicity)
 *    • Rapidity (y), η, and pT bins
 *    • PVZ bins and production-plane cuts
 *    • Angular variables: ϕ*, cosθ*, ϕ_lab, etc.
 *
 *  ANALYSIS FLOW:
 *  --------------
 *  1. Define binning for multiplicity, rapidity, ϕ*, pT
 *  2. Initialize histograms (1D/2D/3D and TProfile)
 *  3. Loop over all TTree entries (event-level)
 *     a. Apply event-level and topological cuts
 *     b. Construct 4-vectors for K0S and daughters
 *     c. Compute physics observables:
 *        - Rapidity, cosθ*, ϕ*, lab-frame QA
 *        - Triple product observable R = (3/α)·p̂*_π⁺·(ẑ × p̂_K0S)
 *     d. Fill histograms and correlation plots
 *  4. Write all output histograms to ROOT file
 *
 *  OUTPUT:
 *  -------
 *    • ROOT file: out_root/TV_PbPb2024_K0S<fileNr>.root
 *    • Organized histograms per particle and observable
 *    • Suitable for angular fits, QA, and acceptance/systematics studies
 *
 *  FLAGS:
 *  ------
 *    • anti = 0 → Ks from π⁻π⁺ (interpreted as anti-Λ-like)
 *    • anti = 1 → Ks from π⁺π⁻ (interpreted as Λ-like)
 *    • iFile  = file index for batch naming
 *
 *  NOTES:
 *  ------
 *    • This macro mirrors toroidal vorticity analysis performed for Λ/anti-Λ decays,
 *      adapted to the K0S→π⁺π⁻ channel.
 *    • Beam crossing angles can be optionally rotated in the boost frame.
 *    • PVZ binning is used for possible acceptance correction studies.
 *    • Cuts are configured for Pb–Pb conditions, adjust for other systems.
 *
 *  CONTACT:
 *    Maria Stefaniak — mzstefaniak@gmail.com
 *
 ***********************************************************************************************/
