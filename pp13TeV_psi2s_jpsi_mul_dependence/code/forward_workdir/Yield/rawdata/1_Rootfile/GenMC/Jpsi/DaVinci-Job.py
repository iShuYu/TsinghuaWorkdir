################
# CONFIGURATION
################
EventType = '24142000'
DecayDescriptor = '[J/psi(1S) => ^mu+ ^mu-]CC'
DecayHeader = 'J/psi(1S)'

################
import sys, os
from DaVinci.Configuration import *
from Gaudi.Configuration import *

from Configurables import DaVinci, PrintMCTree
from Configurables import MCDecayTreeTuple, MCTupleToolKinematic, MCTupleToolHierarchy, LoKi__Hybrid__MCTupleTool

mctuple = MCDecayTreeTuple( 'MCDecayTreeTuple' )
mctuple.Decay = DecayDescriptor
mctuple.Branches = {
	"mup":"J/psi(1S) => ^mu+ mu-",
	"mum":"J/psi(1S) => mu+ ^mu-",
	"psi":"J/psi(1S) => mu+ mu- ",
}
mctuple.ToolList = [ "MCTupleToolHierarchy", "MCTupleToolKinematic", "LoKi::Hybrid::MCTupleTool/LoKi_Photos" ]

mctuple.addTool(MCTupleToolKinematic())
mctuple.MCTupleToolKinematic.Verbose=True
#mctuple.Decay = "Upsilon(1S) -> ^mu+ ^mu-" 


# LoKi variables
LoKi_Photos = LoKi__Hybrid__MCTupleTool("LoKi_Photos")
LoKi_Photos.Variables = {
    "nPhotos"  : "MCNINTREE ( ('gamma'==MCABSID) )"
}
mctuple.addTool(LoKi_Photos)

pMC = PrintMCTree()
pMC.ParticleNames = [ DecayHeader ]

#ApplicationMgr().ExtSvc += [ 'DataOnDemandSvc' ]
#DataOnDemandSvc().AlgMap[ '/Event/MC/Particles' ] = 'UnpackMCParticle'

DaVinci().TupleFile  = 'Tuple.root'
#'tupleProduction-'+EventType+'.root'
DaVinci().EvtMax     = -1
DaVinci().Simulation = True
DaVinci().Lumi       = False
DaVinci().InputType  = "DST"
DaVinci().DataType   = "2015"
#DaVinci().DDDBtag   = "dddb-20150724"
#LHCbApp().CondDBtag = 'sim-20161124-2015at5TeV-vc-md100'
DaVinci().UserAlgorithms = [ pMC, mctuple ]
