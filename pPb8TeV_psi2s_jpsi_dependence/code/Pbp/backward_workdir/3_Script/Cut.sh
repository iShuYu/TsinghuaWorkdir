numn=$(head -1 0_Bin/nbin)
numpt=$(head -1 0_Bin/ptbin)
numy=$(head -1 0_Bin/ybin)
for i in $(seq 1 $numn)
do
	for j in $( seq 1 $numy )
        do
		for k in $( seq 1 $numpt )
		do
			./../2_Exe/Cut 1 ../0_File/Data/Divide/Jpsi_n${i}y${j}pt${k}.root ../0_File/Data/Cut/Jpsi_n${i}y${j}pt${k}.root   >/dev/null 2>&1 &
			./../2_Exe/Cut 2 ../0_File/Data/Divide/Psi2S_n${i}y${j}pt${k}.root ../0_File/Data/Cut/Psi2S_n${i}y${j}pt${k}.root  >/dev/null 2>&1 &
		done
	done
done
