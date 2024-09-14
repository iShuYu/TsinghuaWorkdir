numn=$(head -1 ../../rawdata/3_Bins/nbin)
numy=$(head -1 ../../rawdata/3_Bins/ybin)
numpt=$(head -1 ../../rawdata/3_Bins/ptbin)
for i in $(seq 1 $numn)
do
	for j in $(seq 1 $numy)
	do
		for k in $(seq 1 $numpt)
		do
			./result 1 ${j} ${k} ../../Jpsi/3_Result/2DFit/txt_n${i}y${j}pt${k}.txt ../../Jpsi/3_Result/eff_tot/n${i}_fromb.root ../../Jpsi/3_Result/eff_tot/n${i}_prompt.root ../Jpsi_result/cross_section_ub/n${i}y${j}pt${k}.txt
			./result 2 ${j} ${k} ../../Psi2S/3_Result/2DFit/txt_n${i}y${j}pt${k}.txt ../../Psi2S/3_Result/eff_tot/n${i}_fromb.root ../../Psi2S/3_Result/eff_tot/n${i}_prompt.root ../Psi2S_result/cross_section_ub/n${i}y${j}pt${k}.txt
		done
	done
done
