numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
for i in $(seq 1 $numn)
do
        ./script_for_Compare/Compare_tzsig.sh ${i} >/dev/null 2>&1 &
	./script_for_Compare/Compare_2D.sh ${i} >/dev/null 2>&1 &
done
./INT_2D
./INT_sig
