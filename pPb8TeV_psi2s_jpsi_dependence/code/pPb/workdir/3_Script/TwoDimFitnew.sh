numn=$(head -1 0_Bin/nbin)
numpt=$(head -1 0_Bin/ptbin)
numy=$(head -1 0_Bin/ybin)
for i in $(seq 1 $numn)
do
	for j in $( seq 1 $numy )
        do
		for k in $( seq 1 $numpt )
		do
			./../2_Exe/TwoDimFitnew 1 ../0_File/Data/Cut/Jpsi_n${i}y${j}pt${j}.root ../4_Result/TwoDimFit/PDF/Jpsi_n${i}y${j}pt${j}.root ../4_Result/CBFit/n${i}y${j}pt${j}new.txt ../4_Result/TzbkgFit/Jpsi_n${i}y${j}pt${j}.txt ../4_Result/TwoDimFit/Jpsi_n${i}y${j}pt${j}new.txt  >/dev/null 2>&1 &
		./../2_Exe/TwoDimFitnew 2 ../0_File/Data/Cut/Psi2S_n${i}y${j}pt${j}.root ../4_Result/TwoDimFit/PDF/Psi2S_n${i}y${j}pt${j}.root ../4_Result/CBFit/n${i}y${j}pt${j}new.txt ../4_Result/TzbkgFit/Psi2S_n${i}y${j}pt${j}.txt ../4_Result/TwoDimFit/Psi2S_n${i}y${j}pt${j}new.txt  >& ../4_Result/TwoDimFit/log/Psi2S_n${i}y${j}pt${k}new.log &		done
	done
done
