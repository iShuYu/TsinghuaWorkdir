numn=$(head -1 0_Bin/nbin)
numpt=$(head -1 0_Bin/ptbin)
numy=$(head -1 0_Bin/ybin)
for i in $(seq 1 $numn)
do
	for j in $( seq 1 $numy )
        do
		for k in $( seq 1 $numpt )
		do
			./../2_Exe/Draw_TwoProjTz ../4_Result/TwoDimFit/PDF/Jpsi_n${i}y${j}pt${k}.root ../5_Plots/TwoDimFit/ProjTz/Jpsi_n${i}y${j}pt${k}.pdf ../4_Result/TwoDimFit/PDF/Psi2S_n${i}y${j}pt${k}.root ../5_Plots/TwoDimFit/ProjTz/Psi2S_n${i}y${j}pt${k}.pdf >/dev/null 2>&1 &
		done
	done
done
