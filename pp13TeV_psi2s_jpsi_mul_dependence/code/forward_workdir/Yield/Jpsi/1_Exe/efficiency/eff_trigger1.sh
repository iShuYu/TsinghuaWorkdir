rm -rf ../../2_Rootfile/MCTIS_after_cut/n12*
hadd ../../2_Rootfile/MCTIS_after_cut/n12_MagUp.root  ../../2_Rootfile/MCTIS_after_cut/n1_MagUp.root ../../2_Rootfile/MCTIS_after_cut/n2_MagUp.root 
hadd ../../2_Rootfile/MCTIS_after_cut/n12_MagDown.root  ../../2_Rootfile/MCTIS_after_cut/n1_MagDown.root ../../2_Rootfile/MCTIS_after_cut/n2_MagDown.root 
wait
numn=$(head -1 ../../../rawdata/3_Bins/nbin)
for i in $(seq 3 $numn)
do
	./script_for_eff_trigger/eff_trigger1.sh ${i}
done
./script_for_eff_trigger/eff_trigger1.sh 12
