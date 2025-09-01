Λ and K0S Polarization Analysis – LHCb p+Ar @ 2024 (SMOG2)
==========================================================

This repository contains two sets of C++/ROOT-based macros used for analyzing
Lambda (Λ/Λ̄) and K0S polarization in proton–argon collisions recorded by LHCb
in 2024, using data from the official Analysis Production:
https://lhcb-productions.web.cern.ch/ana-prod/productions/?wg=ift&analysis=l02ppiturbo_k0sfull_smog2

The input files are ROOT TTrees (DecayFunTuple) from the L0_2ppiTurbo line.

----------------------------------------------------------
Lambda Analysis
----------------------------------------------------------

Main macro: ExecuteAnalysisOnMultipleFiles.cxx
- Loops over ROOT files containing Lambda and AntiLambda candidates and runs 
  the analysis on each.

Supporting logic is contained in associated .C files.

How to run:
> root -l ExecuteAnalysisOnMultipleFiles.cxx

- Before running, verify how many Lambda candidate ROOT files you have 
  and modify the 'for' loop accordingly.
- Alternatively, you can modify the code to analyze K0S files instead.

----------------------------------------------------------
K0S Analysis
----------------------------------------------------------

Main class: K0S_analysis.C
- ROOT-generated analysis skeleton with extensions to apply selection and 
  polarization extraction for K0S → π⁺π⁻ decays.

Main macro: toroidalVorticitySmog.C
- Applies physics cuts and computes polarization/vorticity-related observables.

----------------------------------------------------------
Important Physics Note
----------------------------------------------------------

For Λ and Λ̄ decays, the polarization is extracted from angular distributions.

Alpha (α) decay parameter:
- Λ:     +0.732
- Λ̄:     –0.732

IMPORTANT:
The Lambda analysis macros do NOT flip the sign of α for anti-Lambdas.
This MUST be accounted for in the plotting procedure to obtain correct
combined polarization results.

----------------------------------------------------------
Outputs
----------------------------------------------------------

- ROOT files containing:
  - Polarization histograms
  - QA plots
  - Kinematic distributions (pT, y, angles, etc.)

----------------------------------------------------------
Code Documentation
----------------------------------------------------------

Each macro or class contains a detailed description at the top:
- Purpose
- Inputs/outputs
- Customization notes

Please refer to those comments before modifying the code.

----------------------------------------------------------
Requirements
----------------------------------------------------------

- ROOT 6.26 or newer (tested with ROOT 6.32)
- C++17-compatible compiler (for batch compilation)
- Input ROOT files from the LHCb Analysis Production system

----------------------------------------------------------
Contact
----------------------------------------------------------

Maria Stefaniak
Presidential Postdoctoral Fellow
The Ohio State University / LHCb Collaboration
Email: stefaniak.9@osu.edu
