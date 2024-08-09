numn=$(head -1 0_Bin/nbin)
numpt=$(head -1 0_Bin/ptbin)
numy=$(head -1 0_Bin/ybin)
for i in $(seq 1 $numn)
do
	for j in $( seq 1 $numy )
        do
		for k in $( seq 1 $numpt )
		do
			./../2_Exe/CBFit  ../0_File/Data/Cut/Jpsi_n${i}y${j}pt${k}.root ../0_File/Data/Cut/Psi2S_n${i}y${j}pt${k}.root ../5_Plots/CBFit/Jpsi_n${i}y${j}pt${k}.pdf ../5_Plots/CBFit/Psi2S_n${i}y${j}pt${k}.pdf ../4_Result/CBFit/n${i}y${j}pt${k}.txt ../4_Result/CBFit/sPlot/Jpsi_n${i}y${j}pt${k}.root ../4_Result/CBFit/sPlot/Psi2S_n${i}y${j}pt${k}.root >& ../4_Result/CBFit/log/n${i}y${j}pt${k}.log &
		done
	done
done
