rm -rf ../4_Result/CBFit/sPlot/Jpsi.root >/dev/null 2>&1 &  #
rm -rf ../4_Result/CBFit/sPlot/Psi2S.root >/dev/null 2>&1 &  #
rm -rf ../0_File/MC/Cut/Jpsi.root >/dev/null 2>&1 &  #
rm -rf ../0_File/MC/Cut/Psi2S.root >/dev/null 2>&1 &  #
wait
hadd ../0_File/MC/Cut/Jpsi.root ../0_File/MC/Cut/Jpsi_*  >/dev/null 2>&1 & #
hadd ../4_Result/CBFit/sPlot/Jpsi.root ../4_Result/CBFit/sPlot/Jpsi_*  >/dev/null 2>&1 & #
hadd ../0_File/MC/Cut/Psi2S.root ../0_File/MC/Cut/Psi2S_*  >/dev/null 2>&1 & #
hadd ../4_Result/CBFit/sPlot/Psi2S.root ../4_Result/CBFit/sPlot/Psi2S_* >/dev/null 2>&1 & #
wait
./../2_Exe/Reweight >/dev/null 2>&1 & #
