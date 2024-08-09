import os
from os import environ
from Gaudi.Configuration import *
from Configurables import DaVinci, PrintMCTree
from Configurables import MCDecayTreeTuple, MCTupleToolKinematic, MCTupleToolHierarchy
from Configurables import LoKi__Hybrid__MCTupleTool


EventSelector().Input = [
"./Psi2S.xgen"
]
