numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./script_for_fitGaus/fitGaus.sh ${i} 
	./script_for_fitGaus/fitGausY.sh ${i}
done
