import sys
myLumiDict = {}
with open("run2_pp_lumi.csv") as lumiFile:
    for line in lumiFile.readlines()[1:]:
        myList = line[:-1].split(',')
        run = myList[0]
        fill = myList[1]
        year = myList[2]
        energy = myList[3]
        events = int(myList[4])
        quality = myList[5]
        proxylumi = float(myList[6])
        proxyphys = float(myList[7])
        lumi = float(myList[8])
        myLumiDict[run] = lumi

inteLumi = 0
for i in range(1,len(sys.argv)):
    with open(sys.argv[i]) as myRun:
        for line in myRun.readlines():
            if line[:-1] in myLumiDict:
                inteLumi += myLumiDict[line[:-1]]
print(inteLumi)
