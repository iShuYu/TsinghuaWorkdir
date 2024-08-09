import os
from os import environ
from Gaudi.Configuration import *
from Configurables import DaVinci, PrintMCTree
from Configurables import MCDecayTreeTuple, MCTupleToolKinematic, MCTupleToolHierarchy
from Configurables import LoKi__Hybrid__MCTupleTool

if os.path.isfile("Gauss-24142000-1000ev-20180409.xgen"):
	data = "20180409"
elif os.path.isfile("Gauss-24142000-1000ev-20180410.xgen"):
	data = "20180410"

EventSelector().Input = [
	"DATAFILE='/home/xuli/workdir/Jpsi5TeV/2015/MC/generator/workspace/$No$/Gauss-24142000-1000ev-%s.xgen'  TYP='POOL_ROOTTREE' Opt='READ'"%data
]
