import os
from os import environ
from Gaudi.Configuration import *
from Configurables import DaVinci, PrintMCTree
from Configurables import MCDecayTreeTuple, MCTupleToolKinematic, MCTupleToolHierarchy
from Configurables import LoKi__Hybrid__MCTupleTool


EventSelector().Input = [
"./Gauss-24142000-50ev-20210607.xgen"
]
