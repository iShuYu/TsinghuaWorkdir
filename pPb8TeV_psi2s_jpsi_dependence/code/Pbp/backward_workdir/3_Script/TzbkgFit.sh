numn=$(head -1 0_Bin/nbin)
numpt=$(head -1 0_Bin/ptbin)
numy=$(head -1 0_Bin/ybin)
for i in $(seq 1 $numn)
do
	for j in $( seq 1 $numy )
        do
		for k in $( seq 1 $numpt )
		do
			./../2_Exe/TzbkgFit ../0_File/Data/SideBand/Jpsi_n${i}y${j}pt${k}.root ../4_Result/TzbkgFit/PDF/Jpsi_n${i}y${j}pt${k}.root ../4_Result/TzbkgFit/Jpsi_n${i}y${j}pt${k}.txt >& ../4_Result/TzbkgFit/log/Jpsi_n${i}y${j}pt${k}.log &
			./../2_Exe/TzbkgFit ../0_File/Data/SideBand/Psi2S_n${i}y${j}pt${k}.root ../4_Result/TzbkgFit/PDF/Psi2S_n${i}y${j}pt${k}.root ../4_Result/TzbkgFit/Psi2S_n${i}y${j}pt${k}.txt >& ../4_Result/TzbkgFit/log/Psi2S_n${i}y${j}pt${k}.log &
		done
	done
done
