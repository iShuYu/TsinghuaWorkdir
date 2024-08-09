for j in $(seq 1 50)
do
./../2_Exe/Eff_Acc 0_Bin/ybin 0_Bin/ptbin 1 ../0_File/GenMC/RAW/Jpsi.root ../0_File/GenMC/RAW/Psi2S.root  ../4_Result/Eff_Acc/Eff_Acc_hi${j}.root  >/dev/null 2>&1 &
./../2_Exe/Eff_Acc 0_Bin/ybin 0_Bin/ptbin 2 ../0_File/GenMC/RAW/Jpsi.root ../0_File/GenMC/RAW/Psi2S.root  ../4_Result/Eff_Acc/Eff_Acc_lo${j}.root  >/dev/null 2>&1 &
done

