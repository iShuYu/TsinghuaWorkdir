for i in $(seq 10 30)
do
	./CB_smear ../../2_Rootfile/smear/smear_sigma${i}.root ../../3_Result/smear/sigma_${i}.txt ../../4_Plot/smear/sigma_${i}.pdf >/dev/null 2>&1 &
done
