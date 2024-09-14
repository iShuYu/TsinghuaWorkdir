numn=$(head -1 ../../../rawdata/3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./script_for_eff_rec_sel/eff_rec_sel.sh ${i}
	./script_for_eff_rec_sel/draw.sh ${i}
	./script_for_eff_rec_sel/MulEff.sh ${i}
done
