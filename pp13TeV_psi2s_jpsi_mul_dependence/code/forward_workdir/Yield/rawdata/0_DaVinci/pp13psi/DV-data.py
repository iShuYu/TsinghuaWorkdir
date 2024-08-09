from os import environ
from GaudiKernel.SystemOfUnits import *
from Gaudi.Configuration import *
from Configurables import GaudiSequencer, CombineParticles
from Configurables import DecayTreeTuple, EventTuple, TupleToolTrigger, TupleToolTISTOS,FilterDesktop, TupleToolPrimaries
from Configurables import BackgroundCategory, TupleToolDecay, TupleToolVtxIsoln,TupleToolPid,EventCountHisto,TupleToolRecoStats
from Configurables import LoKi__Hybrid__TupleTool, TupleToolVeto
# Unit

from Configurables import TCKANNSvc
TCKANNSvc().AdditionalIDs = {"Hlt2SelectionID" : {"Hlt2RecSummary" : 0}}

SeqPhys = GaudiSequencer("SeqPhys")
mtl= [
	    "L0HadronDecision",
      "L0ElectronDecision",
      "L0PhotonDecision",
      "L0MuonDecision",
	    "L0DiMuonDecision",
	    "L0PhysDecision",
      "Hlt1DiMuonHighMassDecision",
      "Hlt1SingleMuonNoIPDecision",
      "Hlt1TrackAllL0Decision",
      "Hlt1TrackMuonDecision",
      "Hlt1GlobalDecision",
      "Hlt2DiMuonDecision",
      "Hlt2DiMuonJPsiDecision",
      "Hlt2DiMuonPsi2SDecision",
      "Hlt2DiMuonBDecision",
      "Hlt2DiMuonDetachedDecision",
      "Hlt2DiMuonDetachedJPsiDecision",
      "Hlt2DiMuonDetachedPsi2SDecision",
      "Hlt2SingleMuonDecision",
      "Hlt2DiMuonJPsiTurboDecision",
      "Hlt2JPsiReFitPVsTurboDecision",
	]
importOptions("$STDOPTS/PreloadUnits.opts")
#
#"""


tuple = DecayTreeTuple("tuple")
tuple.TupleName="tree"
#tuple.Inputs = ["/Event/Turbo/Hlt2DiMuonPsi2STurbo/Particles"]
tuple.Inputs = ["/Event/Turbo/Hlt2DiMuonJPsiTurbo/Particles"]
#tuple.Inputs = ["/Event/Turbo/Hlt2JPsiReFitPVsTurbo/Particles"]
tuple.Decay = "J/psi(1S) -> ^mu+ ^mu-" 
tuple.Branches = {
	"mup":"J/psi(1S) -> ^mu+ mu-",
	"mum":"J/psi(1S) -> mu+ ^mu-",
	"psi":"J/psi(1S) -> mu+ mu-",
    }


tl= [ "TupleToolKinematic", 
       "TupleToolPid" ,
       "TupleToolANNPID" ,
       "TupleToolTrackInfo" ,
       "TupleToolPrimaries" ,
       "TupleToolPropertime" ,
       "TupleToolEventInfo" ,
       "TupleToolTrackInfo" ,
       "TupleToolRecoStats",
       "TupleToolTISTOS",
       "TupleToolGeometry"]
tuple.ToolList += tl
#tuple.InputPrimaryVertices = "/Event/Turbo/Primary"
tuple.addTool(TupleToolPrimaries)
tuple.TupleToolPrimaries.InputLocation= "/Event/Turbo/Primary"

"""
tuple.addTool(TupleToolDecay, name='psi')
tuple.psi.ToolList+=[ "TupleToolTISTOS" ]
tuple.psi.addTool(TupleToolTISTOS, name="TupleToolTISTOS" )
tuple.psi.TupleToolTISTOS.Verbose=True
tuple.psi.TupleToolTISTOS.TriggerList = mtl
"""

from Configurables import LoKi__Hybrid__EvtTupleTool
LoKi_EvtTuple=LoKi__Hybrid__EvtTupleTool("LoKi_EvtTuple")
tuple.ToolList+=["LoKi::Hybrid::EvtTupleTool/LoKi_EvtTuple"]
tuple.addTool(LoKi_EvtTuple)


tuple.ToolList+=[ "TupleToolTISTOS" ]
tuple.addTool(TupleToolTISTOS, name="TupleToolTISTOS" )
tuple.TupleToolTISTOS.Verbose=True
tuple.TupleToolTISTOS.TriggerList = mtl



from Configurables import CheckPV
checkpv = CheckPV()
checkpv.PVLocation = "/Event/Turbo/Primary"
SeqPhys.Members += [checkpv,tuple]
########################################################################
from Configurables import DaVinci
DaVinci().EvtMax = -1		# Number of events
DaVinci().PrintFreq = 1000
DaVinci().SkipEvents = 0                       # Events to skip
DaVinci().DataType = "2015"
DaVinci().Simulation   =  False
DaVinci().DDDBtag ="dddb-20150724"
DaVinci().CondDBtag = "cond-20170111"
DaVinci().HistogramFile = "DVHistos.root"      # Histogram file
DaVinci().TupleFile = "Tuple.root"             # Ntuple
DaVinci().UserAlgorithms = [SeqPhys]  
DaVinci().Lumi = True
DaVinci().InputType = "MDST"


from GaudiConf import IOHelper
IOHelper().inputFiles(['./00047765_00000018_1.turbo.mdst'])

