for i in $( seq 1 3 )
do
	for j in $( seq 1 4 )
	do
		hadd ./merged/SPD5y${i}pt${j}.root SPD5y${i}pt${j}.root SPD6y${i}pt${j}.root
	done
done
