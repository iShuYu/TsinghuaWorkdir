numn=$(head -1 ../../../rawdata/3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./script_for_eff_tot/eff_tot.sh ${i} >/dev/null 2>&1 &
done
