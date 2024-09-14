for i in $( seq 1 3 )
do
	for j in $( seq 1 5 )
	do
		hadd ./merged/n6y${i}pt${j}.root n6y${i}pt${j}.root n7y${i}pt${j}.root
	done
done
