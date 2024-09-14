#!/usr/bin/python
import sys, os
import subprocess
import time
#inpit
with open('../../../Yield/rawdata/3_Bins/nbin','r') as fN:
	n = fN.readlines()
	Nn = int(n[0])
#parameters
core = int(sys.argv[1])
M = 200
total = Nn*M
rest = total
task = 0
done = 0
taskList = []
flag = True
while flag:
	time.sleep(0.1)
	if core > 0 and rest > 0:
		core -= 1
		rest -= 1
		n = task//(M)+1;
		m = (task-M*(n-1))+0
		ps = subprocess.Popen("%s %d %d"%(sys.argv[2],n,m), shell = True )
		taskList.append((ps, task))
		task += 1
	
	for proc, num in taskList:
		if proc.poll() is not None:
			core += 1
			done += 1
			taskList.remove((proc, num))
			print "Job %d finished, %d jobs to do" %(num, total-done)
	if rest == 0 and done == total:
		flag = False
print "Finished"
