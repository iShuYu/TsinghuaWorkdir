numn=$(head -1 ../../Yield/rawdata/3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./Jtzbkg ${i} 
	./Ptzbkg ${i}
done
