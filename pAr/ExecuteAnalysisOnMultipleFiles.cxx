/*
////////////////////////////////////////////////////////////////////////
// ExecuteAnalysisOnMultipleFiles.cxx
//
// Author: Maria Stefaniak
// Purpose: Batch execution of toroidal vorticity analysis for SMOG data
//
// HOW TO RUN:
// 1. From ROOT, execute this file to loop over one or multiple input files.
// 
//    root -l ExecuteAnalysisOnMultipleFiles.cxx
//
//    Internally, it loads and compiles toroidalVorticitySmog.C,
//    then instantiates the toroidalVorticitySmog class and calls its Loop() function.
//
//    You can modify the loop range (currently ii = 1 to 1) to process multiple input files.
//
// NOTE:
// - Assumes toroidalVorticitySmog class is defined in toroidalVorticitySmog.{h,C}
// - Input files are accessed inside the class using the `iFile` index passed in the constructor
// - Output ROOT files are saved in "out_root_new/" directory
////////////////////////////////////////////////////////////////////////
*/

void ExecuteAnalysisOnMultipleFiles(){
  
    // Loop over input files by index.
    // Currently set to run only for ii = 1. You can extend this to (ii = 1; ii < N; ii++) to process more files.
    for(int ii = 1; ii < 2; ii++){  // <--- Adjust this loop to process multiple input files

        // Load and compile the macro toroidalVorticitySmog.C if not already loaded
        gROOT->ProcessLine(".L toroidalVorticitySmog.C+");

        // Construct the analysis object `xx` with argument (0, ii)
        // - 0 is unused in this context (legacy format)
        // - ii is the file index used inside toroidalVorticitySmog to select input file
        gROOT->ProcessLine(Form("toroidalVorticitySmog xx(0,%d)",ii));

        // Run the analysis loop for this file
        gROOT->ProcessLine("xx.Loop()");
    }
}