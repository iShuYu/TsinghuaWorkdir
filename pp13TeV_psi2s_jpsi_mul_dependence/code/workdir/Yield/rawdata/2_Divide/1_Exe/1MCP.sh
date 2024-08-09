numn=$(head -1 ../../3_Bins/nbin)
for i in $(seq 4 $numn)
do
	./MCPsi2S_MagUp_divide ${i} ../../3_Bins/nbin >/dev/null 2>&1 &
	./MCPsi2S_MagDown_divide ${i} ../../3_Bins/nbin >/dev/null 2>&1 &
done


