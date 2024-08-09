numn=$(head -1 0_Bin/nbin)
numpt=$(head -1 0_Bin/ptbin)
numy=$(head -1 0_Bin/ybin)
for i in $(seq 1 $numn)
do
	for j in $( seq 1 $numy )
        do
		for k in $( seq 1 $numpt )
		do
			./../2_Exe/Divide ${i} ${j} ${k} 0_Bin/nbin 0_Bin/ybin 0_Bin/ptbin ../../Workdir/0_File/Data/RAW/Jpsi.root "Jpsi_" >/dev/null 2>&1 &
			 ./../2_Exe/Divide ${i} ${j} ${k} 0_Bin/nbin 0_Bin/ybin 0_Bin/ptbin ../../Workdir/0_File/Data/RAW/Psi2S.root "Psi2S_" >/dev/null 2>&1 &
		 done
	 done
 done


