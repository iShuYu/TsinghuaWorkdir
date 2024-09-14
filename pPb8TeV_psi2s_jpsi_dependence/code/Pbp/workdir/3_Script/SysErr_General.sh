numn=$(head -1 0_Bin/nbin)
./../2_Exe/SysErr_Acc
for i in $(seq 1 $numn)
do
	./../2_Exe/SysErr_General ${i}  >/dev/null 2>&1 &
done
