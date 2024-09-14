"""This file is an example of a user-defined binning scheme file, which """ \
"""can be passed as an argument to the multi-track calibration scripts.
The methods for constructing binning schema are defined in """ \
"""$PIDPERFSCRIPTSROOT/python/PIDPerfScripts/binning.py."""

from PIDPerfScripts.Binning import *
from PIDPerfScripts.Definitions import *

### DLL(K-pi), RICH (alternative schemes)

for trType in ["Mu"]:
    # momentum
    AddBinScheme(trType, 'P', 'custom_Muon', 3000, 1000000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 6000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 8000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 10000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 13000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 14000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 15000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 16000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 18000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 20000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 24000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 28000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 32000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 40000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 60000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 80000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 90000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 100000)
    AddBinBoundary(trType, 'P', 'custom_Muon', 200000)
    #AddUniformBins(trType, 'P', 'custom_Muon', 15, 3000,100000)
    #AddUniformBins(trType, 'P', 'custom_Muon', 10, 100000,1000000)

    # eta
    AddBinScheme(trType, 'ETA', 'custom_Muon', 2, 5)
    AddBinBoundary(trType, 'ETA', 'custom_Muon', 2.5);
    AddBinBoundary(trType, 'ETA', 'custom_Muon', 3.0);
    AddBinBoundary(trType, 'ETA', 'custom_Muon', 3.5);
    AddBinBoundary(trType, 'ETA', 'custom_Muon', 4.0);
    AddBinBoundary(trType, 'ETA', 'custom_Muon', 4.5);

    # nTrack
    AddBinScheme(trType, 'nSPDHits', 'custom_Muon', 0, 900)
    #AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 33);
    #AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 66);
    #AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 100);
    #AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 200);
    #AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 150);
    AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 300);
    #AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 400);
    AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 500);
    #AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 600);
    #AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 275);
    #AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 300);
    #AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 700);
    #AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 350);
    #AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 375);
    #AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 800);
    #AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 567);
    #AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 734);
    #AddBinBoundary(trType, 'nSPDHits', 'custom_Muon', 900);
    #AddUniformBins(trType, 'nSPDHits', 'custom_Muon', 1, 0, 5000)

for trType in ["e","Mu"]:
    # momentum
    AddBinScheme(trType, 'P', 'emu', 3800, 150000)
    AddBinBoundary(trType, 'P', 'emu', 120000)
    AddBinBoundary(trType, 'P', 'emu', 100000)
    AddUniformBins(trType, 'P', 'emu', 10, 3800, 100000)

    # eta
    AddBinScheme(trType, 'ETA', 'emu', 1.5, 5)
    AddBinBoundary(trType, 'ETA', 'emu', 2.2)
    AddBinBoundary(trType, 'ETA', 'emu', 4)
    AddUniformBins(trType, 'ETA', 'emu', 2, 2.2, 4)

    # nTrack
    AddBinScheme(trType, 'nTracks', 'emu', 0, 500)
    AddBinBoundary(trType, 'nTracks', 'emu', 300)
    AddUniformBins(trType, 'nTracks', 'emu', 4, 0, 300)

for trType in ["Pi"]:
    # momentum
    AddBinScheme(trType, 'P', 'emu', 1000, 20000)
    AddBinBoundary(trType, 'P', 'emu', 15000)
    AddUniformBins(trType, 'P', 'emu', 10, 1000, 15000)

    # eta
    AddBinScheme(trType, 'ETA', 'emu', 1.5, 5)
    AddBinBoundary(trType, 'ETA', 'emu', 2.2)
    AddBinBoundary(trType, 'ETA', 'emu', 4)
    AddUniformBins(trType, 'ETA', 'emu', 2, 2.2, 4)

    # nTrack
    AddBinScheme(trType, 'nTracks', 'emu', 0, 500)
    AddBinBoundary(trType, 'nTracks', 'emu', 300)
    AddUniformBins(trType, 'nTracks', 'emu', 4, 0, 300)
 
for trType in ["P_IncLc","P"]:
    # momentum
    AddBinScheme(trType, 'P', 'P_Expand', 3000, 150000)
    AddBinBoundary(trType, 'P', 'P_Expand', 120000)
    AddBinBoundary(trType, 'P', 'P_Expand', 100000)
    AddBinBoundary(trType, 'P', 'P_Expand', 7000)
    AddUniformBins(trType, 'P', 'P_Expand', 10, 10000, 100000)

    # eta
    AddBinScheme(trType, 'ETA', 'P_Expand', 1.5, 5.1)
    AddBinBoundary(trType, 'ETA', 'P_Expand', 2.2)
    AddBinBoundary(trType, 'ETA', 'P_Expand', 4)
    AddUniformBins(trType, 'ETA', 'P_Expand', 2, 2.2, 4)

    # nTracks
    AddBinScheme(trType, 'nTracks', 'P_Expand', 0, 1000)
    #AddBinBoundary(trType, 'nTracks', 'P_Expand', 300)
    AddUniformBins(trType, 'nTracks', 'P_Expand', 1, 0, 1000)
