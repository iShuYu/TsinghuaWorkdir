numn=$(head -1 0_Bin/nbin)
for i in $(seq 1 $numn)
do
	./../2_Exe/GetEffMean ${i} "h_eff_tot_J"  >/dev/null 2>&1 &
	./../2_Exe/GetEffMean ${i} "h_eff_tot_P"  >/dev/null 2>&1 &
done
