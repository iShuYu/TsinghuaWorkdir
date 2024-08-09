numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./MCSampleErr_int_pt ${i} &
	./MCSampleErr_int_y ${i} &
	./MCSampleErr_int ${i} &
	./MCSampleErr ${i} &
done
./MCSampleErr_intBYtoPT
