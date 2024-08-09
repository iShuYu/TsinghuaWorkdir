#Please run the commands one-by-one.
lb-sdb-query listPlatforms DaVinci v44r8
LbLogin -c x86_64-slc6-gcc62-opt
lb-run davinci/v44r8 bash --norc
gaudirun.py DaVinci1SDown.py
