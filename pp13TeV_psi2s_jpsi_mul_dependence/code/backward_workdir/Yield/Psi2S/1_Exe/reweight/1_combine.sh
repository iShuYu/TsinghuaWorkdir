rm -rf ../../3_Result/2DFit/2D.root
rm -rf ../../2_Rootfile/MC_after_cut/MC_total.root
hadd ../../3_Result/2DFit/2D.root ../../3_Result/2DFit/splot*.root
hadd ../../2_Rootfile/MC_after_cut/MC_total.root ../../2_Rootfile/MC_after_cut/n*_total.root
