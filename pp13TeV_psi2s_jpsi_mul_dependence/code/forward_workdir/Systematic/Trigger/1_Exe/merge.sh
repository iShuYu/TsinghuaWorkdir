rm -rf ../2_Rootfile/Jpsi/n1T*
rm -rf ../2_Rootfile/Psi2S/n1T*
rm -rf ../2_Rootfile/Jpsi/n2T*
rm -rf ../2_Rootfile/Psi2S/n2T*
rm -rf ../2_Rootfile/Jpsi/n3T*
rm -rf ../2_Rootfile/Psi2S/n3T*
rm -rf ../2_Rootfile/Jpsi/n4T*
rm -rf ../2_Rootfile/Psi2S/n4T*
rm -rf ../2_Rootfile/Jpsi/n5T*
rm -rf ../2_Rootfile/Psi2S/n5T*
rm -rf ../2_Rootfile/Jpsi/n12T*
rm -rf ../2_Rootfile/Psi2S/n12T*

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
wait
hadd ../2_Rootfile/Jpsi/n12TIS.root ../2_Rootfile/Jpsi/n1TIS.root ../2_Rootfile/Jpsi/n2TIS.root 
hadd ../2_Rootfile/Jpsi/n12TISTOS.root ../2_Rootfile/Jpsi/n1TISTOS.root ../2_Rootfile/Jpsi/n2TISTOS.root 
hadd ../2_Rootfile/Psi2S/n12TIS.root ../2_Rootfile/Psi2S/n1TIS.root ../2_Rootfile/Psi2S/n2TIS.root 
hadd ../2_Rootfile/Psi2S/n12TISTOS.root ../2_Rootfile/Psi2S/n1TISTOS.root ../2_Rootfile/Psi2S/n2TISTOS.root 

