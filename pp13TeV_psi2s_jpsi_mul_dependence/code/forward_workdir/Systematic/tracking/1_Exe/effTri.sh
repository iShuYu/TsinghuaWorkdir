numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
for j in $(seq 0 199)
do
        for i in $(seq 1 $numn)
        do
                ./script_for_effTri/effTri.sh ${i} ${j} >/dev/null 2>&1 &
        done
        if [ $j%50=49 ]; then
                wait
        fi
done
