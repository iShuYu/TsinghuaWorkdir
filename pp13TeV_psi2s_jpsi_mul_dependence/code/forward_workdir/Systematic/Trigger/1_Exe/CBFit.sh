numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
numpt=$(head -1 ../../../Yield/rawdata/3_Bins/ptbin)
numy=$(head -1 ../../../Yield/rawdata/3_Bins/ybin)
for j in $( seq 3 $numn )
do
	./script_for_CBFit/CBFitJ.sh ${j}  >/dev/null 2>&1 &
        ./script_for_CBFit/CBFitP.sh ${j}  >/dev/null 2>&1 &
done
./script_for_CBFit/CBFitJ.sh 12 >/dev/null 2>&1 &

./script_for_CBFit/CBFitP.sh 12>/dev/null 2>&1 &




