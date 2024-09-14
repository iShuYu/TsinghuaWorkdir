numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./script_for_fitGaus/fitGaus.sh ${i} >/dev/null 2>&1 &
done
./fitGaus_intNYtoPT
