/*
 HOW TO RUN:

 1. Open ROOT and execute:
    root -l ExecuteMakeLambdaChain.cxx

 2. (Optional) Load the analysis macro (compiles it with dictionary generation):
    .L PrepareLambdaFile.C++

 3. Create an instance of the class with a specific file number:
    PrepareLambdaFile xx(0);  // or any index you want

 4. Run the analysis loop:
    xx.Loop();  // this processes the given file and fills histograms
*/

void ExecuteAnalysisOnMultipleFiles() {
    int MC = 0;  // MC = 0 → real data, MC = 1 → Monte Carlo

    // === First loop: Loop over 56 real data files (p+Ar or p+H)
    for (int ii = 0; ii < 56; ii++) {
        /*
        // Uncomment this block if analyzing K0S files with a different macro:
        gROOT->ProcessLine(".L toroidalVorticityPbPb_K0S.C+");
        gROOT->ProcessLine(Form("toroidalVorticityPbPb_K0S xx(0,%d)", ii));
        gROOT->ProcessLine("xx.Loop()");
        */

        // Load and compile the Lambda polarization macro
        gROOT->ProcessLine(".L toroidalVorticityPbPb.C+");

        // Instantiate analysis class for file index `ii` and data type `MC = 0`
        gROOT->ProcessLine(Form("toroidalVorticityPbPb xx(0,%d,%d)", ii, MC));

        // Run the analysis loop for that file
        gROOT->ProcessLine("xx.Loop()");
    }

    // === Second loop: Loop over 38 MC files (MC = 1)
    MC = 1;
    for (int ii = 1; ii < 39; ii++) {
        // Load and compile the analysis macro again (safe in ROOT)
        gROOT->ProcessLine(".L toroidalVorticityPbPb.C+");

        // Instantiate analysis class for file `ii` and MC flag `1`
        gROOT->ProcessLine(Form("toroidalVorticityPbPb xx(0,%d,%d)", ii, MC));

        // Run the event loop for MC file
        gROOT->ProcessLine("xx.Loop()");
    }
}