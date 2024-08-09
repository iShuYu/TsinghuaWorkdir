#!/usr/bin/python
import sys, os
import subprocess
import time
#inpit
with open('../../../Yield/rawdata/3_Bins/nbin','r') as fN:
	n = fN.readlines()
	Nn = int(n[0])
with open('../../../Yield/rawdata/3_Bins/ybin','r') as fy:
        y = fy.readlines()
        Ny = int(y[0])
with open('../../../Yield/rawdata/3_Bins/ptbin','r') as fpt:
        pt = fpt.readlines()
        Npt = int(pt[0])
#parameters
core = int(sys.argv[1])
task = int(sys.argv[2])-1
total = int(sys.argv[3])
rest = total-task
done = 0
taskList = []
flag = True
while flag:
	time.sleep(0.1)
	if core > 0 and rest > 0:
		core -= 1
		rest -= 1
		nn = task//(Ny*Npt)+1;
		yy = (task-(nn-1)*Ny*Npt)//Npt+1;
		pp = (task-(nn-1)*Ny*Npt-(yy-1)*Npt)+1;	
		ps = subprocess.Popen("%s %d %d %d"%(sys.argv[4],nn,yy,pp), shell = True )
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
