
# 🧪 Lambda Polarization Plotting Suite (LHCb 2024)

This repository contains Jupyter notebooks for visualizing and comparing the transverse polarization of Λ and anti-Λ hyperons in various collision systems using data from the LHCb experiment in 2024.

The primary physics focus is on multi-differential studies of polarization and potential signatures of **toroidal vorticity**, explored through cos(θ*) and ϕ* distributions in Pb–Pb and SMOG-mode fixed-target data (e.g., pNe).

> 📌 Developed by **Maria Stefaniak**  
> 🧑‍🏫 With support from **Prof. Mike Lisa**

---

## 📁 Contents

| Notebook                     | Description                                                                                  |
|-----------------------------|----------------------------------------------------------------------------------------------|
| `PlotAll.ipynb`             | Primary plotting notebook for transverse polarization observables across all configurations. |
| `PlotAll_bck.ipynb`         | Backup version used for testing style/cut variations (included for reproducibility).         |
| `Plot_PbPb.ipynb`           | Dedicated to Pb–Pb collider-mode data (2024); includes centrality and PVZ slicing.          |
| `Plot_comparisonCamilla.ipynb` | Used to compare polarization results to external analysis (Camilla's output).                |

---

## ⚙️ Requirements

All notebooks rely on the Python ecosystem for high-energy physics data visualization.

Install via pip:
```bash
pip install uproot matplotlib numpy mplhep
```

Or with conda:
```bash
conda install -c conda-forge uproot matplotlib numpy
```

---

## 📦 Directory Structure

```bash
.
├── PlotAll.ipynb                # Main plotting code
├── PlotAll_bck.ipynb            # Older version (backup)
├── Plot_PbPb.ipynb              # PbPb-specific observables and binning
├── Plot_comparisonCamilla.ipynb # Comparison plots with external results
├── README.md
├── xf_3bins/                    # Multidifferential plots in xF
├── PbPb/                        # PbPb collider mode outputs
└── Camilla_comparison/         # Data vs MC comparison with Camilla's results
```

---

## 🔍 File Naming Convention

- Files containing `_phi` in the name apply a φ* cut.  
  ➤ You can verify the exact φ* selection by checking the included histograms in the `.root` file.
  
- Files with `_data.root` represent **experimental data**, while `_MC.root` indicates **Monte Carlo simulation**.

---

## 📊 Physics Observables

These notebooks are optimized for plotting:

- **cosθ***: Helicity angle, related to polarization direction
- **ϕ***: Azimuthal angle in Λ/anti-Λ rest frame
- **pT, y, xF**: Kinematic variables used in binning
- **PVZ**: z-position of primary vertex
- **Centrality**: Used in Pb–Pb analysis (custom bins defined)

Output plots include:

- 1D histograms
- TProfile plots of polarization vs variables
- 2D correlation maps
- Comparisons between MC and Data

---

## 🧵 Usage Instructions

### 1. Clone the repository:
```bash
git clone https://github.com/MariaStefaniak/LambdaPolarizationAtLHCb.git
cd LambdaPolarizationAtLHCb
```

### 2. Prepare your `.root` input files
- Adjust paths in the notebook to point to your desired data/MC files.
- Suggested ROOT file structure (inside each file):
  - `cosThetaStar`, `phiStar` histograms
  - Histograms binned in `pT`, `xF`, `rapidity`, `φ*`, `PVZ`

### 3. Run the notebook
Launch Jupyter or VSCode and execute each cell sequentially:
```bash
jupyter notebook PlotAll.ipynb
```

You can switch between `data` and `MC` comparisons, and modify labels/styles for publication-ready plots.

---

## 🔬 Physics Context

This analysis is part of the LHCb 2024 heavy-ion data campaign. We explore the possibility of **toroidal vorticity**, a novel QCD phenomenon, using polarization observables from weakly decaying strange hadrons.

Polarization is analyzed using:
- The angular distribution of decay products in the Λ rest frame
- Sensitivity to system vorticity and spin-orbit coupling
- Centrality and rapidity-dependent effects

This project complements previous work at RHIC and adds new insight via LHCb’s unique forward geometry.

---

## 🤝 Acknowledgments

- Developed with guidance from **Prof. Mike Lisa** (Ohio State University)
- Some comparison files derived from **Camilla's** p–Ne polarization framework
- Histograms generated from macros available in:

  🔗 [LambdaPolarizationAtLHCb GitHub](https://github.com/MariaStefaniak/LambdaPolarizationAtLHCb)

---

## 📬 Contact

For questions, collaboration, or feedback, feel free to reach out via:

- GitHub Issues  
- Collaboration email  
- Maria Stefaniak: `mzstefaniak@gmail.com`

---

## 📄 License

This repository is part of a physics collaboration effort and is released for academic use. Please cite or acknowledge the author in derivative works or talks.
