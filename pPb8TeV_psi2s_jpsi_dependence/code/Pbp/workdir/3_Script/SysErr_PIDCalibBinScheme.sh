numn=$(head -1 0_Bin/nbin)
for i in $(seq 1 $numn)
do
	./../2_Exe/Eff_RecselPIDTrigger 0 0_Bin/ybin 0_Bin/ptbin ../0_File/MC/Divide/mctJpsi_n${i}.root ../0_File/MC/Cut/Jpsi_n${i}.root ../0_File/MC/Divide/mctPsi2S_n${i}.root ../0_File/MC/Cut/Psi2S_n${i}.root ../0_File/PIDCalib/PerfHists_Mu_ApTurbo16_MagDown_custom_Muon_P_ETA_nSPDHits.root ../4_Result/Eff_RecselPIDTrigger/n${i}/Eff_RecselPIDTrigger_PIDCalib0.root >/dev/null 2>&1 &
	./../2_Exe/Eff_RecselPIDTrigger 0 0_Bin/ybin 0_Bin/ptbin ../0_File/MC/Divide/mctJpsi_n${i}.root ../0_File/MC/Cut/Jpsi_n${i}.root ../0_File/MC/Divide/mctPsi2S_n${i}.root ../0_File/MC/Cut/Psi2S_n${i}.root ../0_File/PIDCalib/PerfHists_Mu_ApTurbo16_MagDown_custom_Muon_P_ETA_nSPDHits1.root ../4_Result/Eff_RecselPIDTrigger/n${i}/Eff_RecselPIDTrigger_PIDCalib1.root >/dev/null 2>&1 &
	./../2_Exe/Eff_RecselPIDTrigger 0 0_Bin/ybin 0_Bin/ptbin ../0_File/MC/Divide/mctJpsi_n${i}.root ../0_File/MC/Cut/Jpsi_n${i}.root ../0_File/MC/Divide/mctPsi2S_n${i}.root ../0_File/MC/Cut/Psi2S_n${i}.root ../0_File/PIDCalib/PerfHists_Mu_ApTurbo16_MagDown_custom_Muon_P_ETA_nSPDHits2.root ../4_Result/Eff_RecselPIDTrigger/n${i}/Eff_RecselPIDTrigger_PIDCalib2.root >/dev/null 2>&1 &
done
wait
for i in $(seq 1 $numn)
do
	./../2_Exe/SysErr_PIDCalibBinScheme ${i}  >/dev/null 2>&1 &
done 
