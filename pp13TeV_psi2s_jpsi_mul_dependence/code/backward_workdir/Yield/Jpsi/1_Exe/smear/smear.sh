for i in $(seq 10 30)
do
	./smear ../../../rawdata/1_Rootfile/MC/MagDown/Jpsi/2/output/Tuple.root  ../../2_Rootfile/smear/smear_sigma${i}.root  ${i} >/dev/null 2>&1 &
done
