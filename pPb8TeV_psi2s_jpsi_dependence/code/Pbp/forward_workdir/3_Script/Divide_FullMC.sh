numn=$(head -1 0_Bin/nbin)
for i in $(seq 1 $numn)
do
	./../2_Exe/Divide_FullMC ${i} 0_Bin/nbin  ../../Workdir/0_File/MC/RAW/Jpsi.root "Jpsi" >/dev/null 2>&1 &
	./../2_Exe/Divide_FullMC ${i} 0_Bin/nbin  ../../Workdir/0_File/MC/RAW/Psi2S.root "Psi2S" >/dev/null 2>&1 &
done


