numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
for j in $(seq 1 2)
do
        for i in $(seq 1 $numn)
        do
                ./script_for_InBin/FillInBin.sh ${i} ${j} >/dev/null 2>&1 &
        done
done

