numn=$(head -1 ../../../../rawdata/3_Bins/nbin)
numpt=$(head -1 ../../../../rawdata/3_Bins/ptbin)
numy=$(head -1 ../../../../rawdata/3_Bins/ybin)
for i in $(seq 1 $numn)
do
	for j in $( seq 1 $numy )
        do
		for k in $( seq 1 $numpt )
		do
			./Scan n${i}y${j}pt${k}.log ../Tzbkg_n${i}y${j}pt${k}.txt  >/dev/null 2>&1 &
		done
	done
done
