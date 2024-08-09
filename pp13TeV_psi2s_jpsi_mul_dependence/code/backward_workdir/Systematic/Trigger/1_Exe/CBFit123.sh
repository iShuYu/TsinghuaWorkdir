numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
numpt=$(head -1 ../../../Yield/rawdata/3_Bins/ptbin)
numy=$(head -1 ../../../Yield/rawdata/3_Bins/ybin)
for i in $( seq 1 $numn )
do
	for j in $( seq 1 $numpt )
	do
		./script_for_CBFit/CBFitJ.sh ${i} 123  >/dev/null 2>&1 &
        	./script_for_CBFit/CBFitP.sh ${i} 123  >/dev/null 2>&1 &
		./script_for_CBFit/CBFitJ.sh ${i} 4  >/dev/null 2>&1 &
                ./script_for_CBFit/CBFitP.sh ${i} 4  >/dev/null 2>&1 &
		./script_for_CBFit/CBFitJ.sh ${i} 5  >/dev/null 2>&1 &
        	./script_for_CBFit/CBFitP.sh ${i} 5  >/dev/null 2>&1 &
	done
done



