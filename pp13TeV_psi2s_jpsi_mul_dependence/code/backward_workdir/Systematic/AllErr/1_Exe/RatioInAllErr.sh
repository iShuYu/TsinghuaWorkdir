numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./script_for_RatioInAllErr/SampleSizeErr2AllErr.sh ${i}
	./script_for_RatioInAllErr/StatsErr2AllErr.sh ${i}
done
