numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./StatsErr_int_pt ${i} &
	./StatsErr_int_y ${i} &
	./StatsErr_int ${i} &
done
