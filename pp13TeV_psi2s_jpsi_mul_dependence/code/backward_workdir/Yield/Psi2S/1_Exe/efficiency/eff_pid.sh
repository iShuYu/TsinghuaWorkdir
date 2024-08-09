numn=$(head -1 ../../../rawdata/3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./script_for_eff_pid/eff_pid.sh ${i}
	./script_for_eff_pid/draw.sh ${i}
done
