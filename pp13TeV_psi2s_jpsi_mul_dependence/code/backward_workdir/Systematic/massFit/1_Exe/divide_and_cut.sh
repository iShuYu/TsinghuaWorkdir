numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
numpt=$(head -1 ../../../Yield/rawdata/3_Bins/ptbin)
numy=$(head -1 ../../../Yield/rawdata/3_Bins/ybin)
for i in $(seq 1 $numn)
do
        for j in $( seq 1 $numy )
        do
                for k in $( seq 1 $numpt )
                do
                        ./script_for_divide_and_cut/divide_and_cut.sh ${i} ${j} ${k} >/dev/null 2>&1 &
                done
        done
done
