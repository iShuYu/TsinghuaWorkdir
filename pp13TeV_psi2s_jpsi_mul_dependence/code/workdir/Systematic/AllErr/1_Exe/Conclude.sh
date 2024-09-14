numn=$(head -1 ../../../Yield/rawdata/3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./Conclude ${i}
	./Conclude_int_pt ${i}
	./Conclude_int_y ${i}
	./Conclude_int ${i}
	./OnlyStatsConclude ${i}
	./OnlyStatsConclude_int ${i}
	./OnlyStatsConclude_int_pt ${i}
	./OnlyStatsConclude_int_y ${i}
	./OnlySysConclude ${i}
        ./OnlySysConclude_int ${i}
        ./OnlySysConclude_int_pt ${i}
        ./OnlySysConclude_int_y ${i}
done
