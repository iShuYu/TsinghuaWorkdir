numn=$(head -1 0_Bin/nbin)
numpt=$(head -1 0_Bin/ptbin)
numy=$(head -1 0_Bin/ybin)
for i in $(seq 1 $numn)
do
	for j in $( seq 1 $numy )
        do
		for k in $( seq 1 $numpt )
		do
			./../2_Exe/TwoDimFit 1 ../0_File/Data/Cut/Jpsi_n${i}y${j}pt${k}.root ../4_Result/TwoDimFit/PDF/Jpsi_n${i}y${j}pt${k}.root ../4_Result/CBFit/n${i}y${j}pt${k}.txt ../4_Result/TzbkgFit/Jpsi_n${i}y${j}pt${k}.txt ../4_Result/TwoDimFit/Jpsi_n${i}y${j}pt${k}.txt  >& ../4_Result/TwoDimFit/log/Jpsi_n${i}y${j}pt${k}.log &
		./../2_Exe/TwoDimFit 2 ../0_File/Data/Cut/Psi2S_n${i}y${j}pt${k}.root ../4_Result/TwoDimFit/PDF/Psi2S_n${i}y${j}pt${k}.root ../4_Result/CBFit/n${i}y${j}pt${k}.txt ../4_Result/TzbkgFit/Psi2S_n${i}y${j}pt${k}.txt ../4_Result/TwoDimFit/Psi2S_n${i}y${j}pt${k}.txt  >& ../4_Result/TwoDimFit/log/Psi2S_n${i}y${j}pt${k}.log &
		done
	done
done
