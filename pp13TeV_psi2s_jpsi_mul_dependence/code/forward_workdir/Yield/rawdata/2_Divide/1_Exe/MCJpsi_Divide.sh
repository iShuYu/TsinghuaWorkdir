numn=$(head -1 ../../3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./MCJpsi_MagUp_divide ${i} ../../3_Bins/nbin >/dev/null 2>&1 &
	./MCJpsi_MagDown_divide ${i} ../../3_Bins/nbin  >/dev/null 2>&1 &
done


