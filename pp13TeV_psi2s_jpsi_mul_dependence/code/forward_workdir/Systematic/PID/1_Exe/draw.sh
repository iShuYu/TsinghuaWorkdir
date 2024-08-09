numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
numpt=$(head -1 ../../../Yield/rawdata/3_Bins/ptbin)
numy=$(head -1 ../../../Yield/rawdata/3_Bins/ybin)
for i in $(seq 1 $numn)
do
                        ./script_for_draw/draw.sh ${i} 
done
