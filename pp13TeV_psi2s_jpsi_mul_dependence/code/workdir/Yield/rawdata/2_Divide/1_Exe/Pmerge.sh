numn=$(head -1 ../../3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./script_for_merge/merge_Psi2S.sh ${i} >/dev/null 2>&1 &
done


