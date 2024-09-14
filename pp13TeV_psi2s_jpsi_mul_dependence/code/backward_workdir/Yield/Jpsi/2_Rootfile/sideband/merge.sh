for i in $( seq 1 3 )
do
	for j in $( seq 1 5 )
	do
		hadd ./merged/SPD6y${i}pt${j}.root SPD6y${i}pt${j}.root SPD7y${i}pt${j}.root
	done
done
