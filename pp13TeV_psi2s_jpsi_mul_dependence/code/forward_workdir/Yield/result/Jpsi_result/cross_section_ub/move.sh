for i in $(seq 1 5)
do
	mv SPD1y${i}pt10.txt SPD1y${i}ptA.txt
	mv SPD1y${i}pt11.txt SPD1y${i}ptB.txt
	mv SPD1y${i}pt12.txt SPD1y${i}ptC.txt
done
rm -rf *10*
rm -rf *11*
rm -rf *12*
rm -rf all.txt
cbtxt
mv all.txt ../../compare/Jpsi/MyResult.txt
