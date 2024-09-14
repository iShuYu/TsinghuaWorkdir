numn=$(head -1 0_Bin/nbin)
for i in $(seq 1 $numn)
do
	./../2_Exe/Cut_MC 1  ../0_File/MC/Divide/Jpsi_n${i}.root ../0_File/MC/Cut/Jpsi_n${i}.root >/dev/null 2>&1 &
	./../2_Exe/Cut_MC 2  ../0_File/MC/Divide/Psi2S_n${i}.root ../0_File/MC/Cut/Psi2S_n${i}.root >/dev/null 2>&1 &
done
