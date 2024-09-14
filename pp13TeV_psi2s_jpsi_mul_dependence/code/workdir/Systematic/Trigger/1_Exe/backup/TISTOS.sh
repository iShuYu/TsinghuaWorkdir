numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./script_for_TISTOS/TISTOS.sh ${i} >/dev/null 2>&1 &
done
wait
sleep 5
wait
for i in $(seq 1 $numn)
do
        ./script_for_TISTOS/TISTOS_int.sh ${i} >/dev/null 2>&1 &
done
./INT_TISTOS
