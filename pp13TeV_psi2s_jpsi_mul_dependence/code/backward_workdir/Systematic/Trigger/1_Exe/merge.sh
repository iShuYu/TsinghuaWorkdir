rm -rf ../2_Rootfile/Jpsi/pt*
rm -rf ../2_Rootfile/Psi2S/pt*
numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
numy=$(head -1 ../../../Yield/rawdata/3_Bins/ybin)
numpt=$(head -1 ../../../Yield/rawdata/3_Bins/ptbin)
for j in $( seq 1 $numn )
do
	hadd ../2_Rootfile/Jpsi/n${j}TIS.root ../2_Rootfile/Jpsi/n${j}y*pt*TIS.root &
	hadd ../2_Rootfile/Jpsi/n${j}TISTOS.root ../2_Rootfile/Jpsi/n${j}y*pt*TISTOS.root &
	hadd ../2_Rootfile/Psi2S/n${j}TIS.root ../2_Rootfile/Psi2S/n${j}y*pt*TIS.root &
        hadd ../2_Rootfile/Psi2S/n${j}TISTOS.root ../2_Rootfile/Psi2S/n${j}y*pt*TISTOS.root &
done
