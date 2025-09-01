/***********************************************************************************************
 *  MACRO: toroidalVorticityPbPb.C
 *  Author: Maria Stefaniak (2025)
 *
 *  ANALYSIS PURPOSE:
 *  -----------------
 *  Analyze polarization of Λ and anti-Λ hyperons produced in Pb–Pb collisions at LHCb (2024 data),
 *  using cosθ* and ϕ* observables defined in the Λ rest frame (helicity frame).
 *
 *  The polarization is studied differentially in:
 *    • Transverse momentum (pT)
 *    • Feynman-x (xF)
 *    • Rapidity (y)
 *    • Production-plane angle (ϕ*)
 *    • Multiplicity / event centrality proxy (nVELO)
 *
 *  The output consists of ROOT histograms that can be directly used for:
 *    • Signal shape & yield evaluation in phase-space bins
 *    • Differential angular fits (1D or 2D) for polarization extraction
 *    • Systematics studies (mass/ϕ*/pT cuts, binning variations, etc.)
 *
 *  PHYSICS OBSERVABLES:
 *  --------------------
 *    • cosθ*  = angle between the proton in Λ rest frame and the normal vector to the production plane
 *    • ϕ*     = azimuthal angle of the proton w.r.t. the production plane (used for 2D polarization fits)
 *    • xF     = longitudinal momentum fraction of Λ (Pz_Λ / Pz_beam)
 *    • pT     = transverse momentum of Λ
 *    • y      = rapidity of Λ
 *
 *  ANALYSIS FLOW:
 *  --------------
 *  1. Define binning for xF, pT, y, ϕ*, multiplicity
 *  2. Initialize QA and physics histograms for Λ and anti-Λ separately
 *  3. Loop over all events in the input TTree
 *     - Apply event-level cuts (single PV, backward tracks, etc.)
 *     - Apply Λ and daughter track quality & topological cuts
 *     - Construct TLorentzVectors and compute kinematic observables
 *     - Fill histograms binned in pT, xF, y, ϕ* with cosθ* values
 *  4. Write all histograms to a ROOT file
 *     - Output path depends on MC flag (real data vs simulation)
 *
 *  OUTPUT FILES:
 *  -------------
 *    • Format: Polarization_PbPb_{data|MC}_L0_AL0<fileNr>.root
 *    • Location: out_root_new/
 *    • Histograms are categorized by particle type, observable, and bin
 *
 *  FLAGS:
 *  ------
 *    • MC = 0 → real data
 *    • MC = 1 → Monte Carlo
 *    • iFile = file index number, used in output file naming
 *
 *  NOTES:
 *  ------
 *    • Boosts and angular observables are calculated using TLorentzVectors
 *    • All cuts and histograms can be modified for systematics studies
 *    • Supports only one file at a time; use merge tool for multiple outputs
 *
 *  Contact:
 *    Maria Stefaniak — mzstefaniak@gmail.com
 *
 ***********************************************************************************************/
