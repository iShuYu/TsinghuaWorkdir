numn=$(head -1 ../../Yield/rawdata/3_Bins/nbin)
numpt=$(head -1 ../../Yield/rawdata/3_Bins/ptbin)
numy=$(head -1 ../../Yield/rawdata/3_Bins/ybin)
for i in $(seq 1 $numn)
do
	./Ratio ${i} 
done
#./Ratio_int_pt
