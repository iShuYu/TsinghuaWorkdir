from os import environ
from GaudiKernel.SystemOfUnits import *
from Gaudi.Configuration import *
from Configurables import GaudiSequencer, CombineParticles, OfflineVertexFitter
from Configurables import DecayTreeTuple, EventTuple, TupleToolTrigger, TupleToolTISTOS,FilterDesktop, TupleToolPrimaries, MCDecayTreeTuple
from Configurables import BackgroundCategory, TupleToolDecay, TupleToolVtxIsoln, TupleToolPid, EventCountHisto, TupleToolRecoStats
from Configurables import LoKi__Hybrid__TupleTool, TupleToolVeto
from Configurables import RawEventJuggler
from DecayTreeTuple.Configuration import *
# Unit
importOptions("$STDOPTS/PreloadUnits.opts")

#trigger list
mtl= [
      "L0MuonDecision",
      "L0DiMuonDecision",
      "Hlt1DiMuonHighMassDecision",
      "Hlt2DiMuonPsi2STurboDecision",
      ]

SeqPhys1 = GaudiSequencer("SeqPhys1")

# MCMatch
from Configurables import LoKi__Hybrid__Tool as MyFactory
mf = MyFactory("HybridFactory")
mf.Modules.append ( 'LoKiPhysMC.decorators' )

Psi2SMuMu = CombineParticles("Psi2SMuMu")
Psi2SMuMu.Inputs = ["Phys/StdAllNoPIDsMuons/Particles"]
Psi2SMuMu.DecayDescriptor = "psi(2S) -> mu+ mu-"
Psi2SMuMu.DaughtersCuts = { "mu+" : "ALL" }
Psi2SMuMu.CombinationCut = "AALL"
Psi2SMuMu.MotherCut = "MCMATCH('psi(2S) => mu+ mu-','Relations/Rec/ProtoP/Charged')"
#Psi2SMuMu.CombinationCut = "(ADAMASS('psi(2S)') < 120.*MeV) & (ADOCACHI2CUT(30,''))"
#Psi2SMuMu.MotherCut = "(VFASPF(VCHI2) < 25.)"
#Psi2SMuMu.ReFitPVs = True

tl= [ "TupleToolKinematic", 
       "TupleToolPid" ,
       "TupleToolANNPID" ,
       "TupleToolTrackInfo" ,
       "TupleToolPrimaries" ,
       "TupleToolPropertime" ,
       "TupleToolEventInfo" ,
       "TupleToolTrackInfo" ,
       "TupleToolRecoStats",
       "TupleToolGeometry",
       ]
from Configurables import LoKi__Hybrid__EvtTupleTool
LoKi_EvtTuple=LoKi__Hybrid__EvtTupleTool("LoKi_EvtTuple")

tuple1 = DecayTreeTuple("tuple1")
tuple1.Inputs = ["Phys/Psi2SMuMu/Particles"]
tuple1.Decay = "psi(2S) -> ^mu+ ^mu-" 
tuple1.Branches = {
	"mup":"psi(2S) -> ^mu+ mu-",
	"mum":"psi(2S) -> mu+ ^mu-",
	"psi":"psi(2S) -> mu+ mu-",
    }
tuple1.ToolList += tl
#tuple1.WriteP2PVRelations = False
#tuple1.InputPrimaryVertices = "/Event/Turbo/Primary"
#tuple1.addTool(TupleToolPrimaries)
#tuple1.TupleToolPrimaries.InputLocation= "Primary"

#MC Information 
tuple1.ToolList += [
        "TupleToolMCTruth",
        "TupleToolMCBackgroundInfo"
        ]

tuple1.ToolList+=["LoKi::Hybrid::EvtTupleTool/LoKi_EvtTuple"]
tuple1.addTool(LoKi_EvtTuple)

tuple1.addTool(TupleToolDecay, name="psi")
tuple1.psi.addTupleTool(TupleToolTISTOS, name="TupleToolTISTOS" )
tuple1.psi.TupleToolTISTOS.Verbose=True
tuple1.psi.TupleToolTISTOS.TriggerList = mtl

from Configurables import TupleToolMCTruth
MCTruth = TupleToolMCTruth()
MCTruth.ToolList = ['MCTupleToolAngles',
        'MCTupleToolHierarchy',
        'MCTupleToolKinematic',
        'MCTupleToolReconstructed']
tuple1.addTool( MCTruth )

#fill the truth information
tuple_truth = MCDecayTreeTuple('mct')
tuple_truth.TupleName="mct"
tuple_truth.Decay = "psi(2S) => ^mu+ ^mu-"
tuple_truth.Branches = {
        "mup":"psi(2S) => ^mu+ mu-",
        "mum":"psi(2S) => mu+ ^mu-",
        "psi":"psi(2S) => mu+ mu-",
        }

tuple_truthl=[ 'TupleToolRecoStats',
	'MCTupleToolAngles',
        'MCTupleToolHierarchy',
        'MCTupleToolKinematic',
        'MCTupleToolPrimaries',
        'MCTupleToolReconstructed',
        'MCTupleToolInteractions']
tuple_truth.ToolList=tuple_truthl
tuple_truth.ToolList+=["LoKi::Hybrid::EvtTupleTool/LoKi_EvtTuple"]
tuple_truth.addTool(LoKi_EvtTuple)


from Configurables import CheckPV
checkpv = CheckPV()
#checkpv.PVLocation = "Primary"

SeqPhys1.Members += [checkpv,Psi2SMuMu,tuple1]

########################################################################
from Configurables import DaVinci
DaVinci().EvtMax = -1		# Number of events
DaVinci().PrintFreq = 1000
DaVinci().SkipEvents = 0                       # Events to skip
DaVinci().DataType = "2015"
DaVinci().Simulation   =  True
DaVinci().DDDBtag ="dddb-20150724"
DaVinci().CondDBtag = "sim-20161124-vc-mu100"
DaVinci().HistogramFile = "DVHistos.root"      # Histogram file
DaVinci().TupleFile = "Tuple.root"             # Ntuple
DaVinci().UserAlgorithms = [SeqPhys1,tuple_truth]
DaVinci().Lumi = False
DaVinci().InputType = "DST"

from GaudiConf import IOHelper
IOHelper().inputFiles(['./00068029_00001440_6.AllStreams.dst'])
