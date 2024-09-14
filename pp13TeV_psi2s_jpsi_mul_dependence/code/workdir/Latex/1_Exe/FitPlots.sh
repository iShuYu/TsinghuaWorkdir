numn=$(head -1 ../../Yield/rawdata/3_Bins/nbin)
numpt=$(head -1 ../../Yield/rawdata/3_Bins/ptbin)
numy=$(head -1 ../../Yield/rawdata/3_Bins/ybin)
for i in $(seq 1 $numn)
do
	for j in $(seq 1 $numy)
	do
		for k in $(seq 1 $numpt)
		do
			./FitPlots ${i} ${j} ${k}
		done
	done
done
