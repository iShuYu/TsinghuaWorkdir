numn=$(head -1 ../../../rawdata/3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./script_for_eff_trigger/eff_trigger.sh ${i} 
	./script_for_eff_trigger/eff_trigger1.sh ${i} 
	./script_for_eff_trigger/draw.sh ${i} 
done
