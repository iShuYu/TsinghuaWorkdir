for i in $(seq 67 100)
do
	cd ${i}/output/
	lb-run DaVinci/v45r6 gaudirun.py DaVinci-Job.py input_test.py > log 2>&1 &
	cd ../../
done
