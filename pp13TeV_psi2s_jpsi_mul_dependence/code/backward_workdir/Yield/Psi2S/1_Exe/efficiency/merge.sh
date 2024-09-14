rm -rf ../2_Rootfile/Psi2S/n12*.root
rm -rf ../2_Rootfile/Psi2S/*pt12*.root
numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
numy=$(head -1 ../../../Yield/rawdata/3_Bins/ybin)
for i in $(seq 1 $numn)
do
	for j in $(seq 1 $numy)
	do
		hadd ../2_Rootfile/Psi2S/n${i}y${j}pt12TIS.root ../2_Rootfile/Psi2S/n${i}y${j}pt1TIS.root ../2_Rootfile/Psi2S/n${i}y${j}pt2TIS.root >/dev/null 2>&1
		hadd ../2_Rootfile/Psi2S/n${i}y${j}pt12TISTOS.root ../2_Rootfile/Psi2S/n${i}y${j}pt1TISTOS.root ../2_Rootfile/Psi2S/n${i}y${j}pt2TISTOS.root >/dev/null 2>&1
	done
done
