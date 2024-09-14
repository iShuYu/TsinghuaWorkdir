numn=$(head -1 ../../../rawdata/3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./script_for_eff_rec_sel/MulEff.sh ${i} &
	./script_for_eff_trigger/MulEff.sh ${i} &
	./script_for_eff_pid/MulEff.sh ${i} &
done
