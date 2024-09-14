numn=$(head -1 ../../../rawdata/3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./script_for_eff_acc/draw_eff_acc.sh ${i}
	./script_for_eff_rec_sel/draw.sh ${i}
	./script_for_eff_pid/draw.sh ${i}
	./script_for_eff_trigger/draw.sh ${i}
done
