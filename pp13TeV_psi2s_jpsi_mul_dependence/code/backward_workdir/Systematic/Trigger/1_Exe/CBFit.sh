numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
numpt=$(head -1 ../../../Yield/rawdata/3_Bins/ptbin)
numy=$(head -1 ../../../Yield/rawdata/3_Bins/ybin)
for j in $( seq 1 $numn )
do
	./script_for_CBFit/CBFitJ.sh ${j}  >/dev/null 2>&1 &
        ./script_for_CBFit/CBFitP.sh ${j}  >/dev/null 2>&1 &
done



