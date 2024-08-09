rm -rf ../2_Rootfile/Jpsi/pt*
rm -rf ../2_Rootfile/Psi2S/pt*
numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
numy=$(head -1 ../../../Yield/rawdata/3_Bins/ybin)
numpt=$(head -1 ../../../Yield/rawdata/3_Bins/ptbin)
#	hadd ../2_Rootfile/Jpsi/pt12TIS.root ../2_Rootfile/Jpsi/n*y*pt1TIS.root ../2_Rootfile/Jpsi/n*y*pt2TIS.root &
#        hadd ../2_Rootfile/Jpsi/pt12TISTOS.root ../2_Rootfile/Jpsi/n*y*pt1TISTOS.root ../2_Rootfile/Jpsi/n*y*pt2TISTOS.root &
#        hadd ../2_Rootfile/Psi2S/pt12TIS.root ../2_Rootfile/Psi2S/n*y*pt1TIS.root ../2_Rootfile/Psi2S/n*y*pt2TIS.root &
#        hadd ../2_Rootfile/Psi2S/pt12TISTOS.root ../2_Rootfile/Psi2S/n*y*pt1TISTOS.root ../2_Rootfile/Psi2S/n*y*pt2TISTOS.root &
for j in $(seq 1 $numn)
do
	hadd ../2_Rootfile/Jpsi/n${j}TIS.root ../2_Rootfile/Jpsi/n${j}y*pt*TIS.root &
	hadd ../2_Rootfile/Jpsi/n${j}TISTOS.root ../2_Rootfile/Jpsi/n${j}y*pt*TISTOS.root &
	hadd ../2_Rootfile/Psi2S/n${j}TIS.root ../2_Rootfile/Psi2S/n${j}y*pt*TIS.root &
        hadd ../2_Rootfile/Psi2S/n${j}TISTOS.root ../2_Rootfile/Psi2S/n${j}y*pt*TISTOS.root &
done
