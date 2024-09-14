from os import environ
from GaudiKernel.SystemOfUnits import *
from Gaudi.Configuration import *
from Configurables import GaudiSequencer, CombineParticles
from Configurables import DecayTreeTuple, EventTuple, TupleToolTrigger, TupleToolTISTOS,FilterDesktop, TupleToolPrimaries
from Configurables import BackgroundCategory, TupleToolDecay, TupleToolVtxIsoln, TupleToolPid, EventCountHisto, TupleToolRecoStats
from Configurables import LoKi__Hybrid__TupleTool, TupleToolVeto
from DecayTreeTuple.Configuration import *
# Unit
importOptions("$STDOPTS/PreloadUnits.opts")

#trigger list
mtl= [
      "L0MuonDecision",
      "L0DiMuonDecision",
      "Hlt1DiMuonHighMassDecision",
      "Hlt2DiMuonJPsiTurboDecision",
      "Hlt2DiMuonPsi2STurboDecision",
      ]

SeqPhys1 = GaudiSequencer("SeqPhys1")
SeqPhys2 = GaudiSequencer("SeqPhys2")

hlt2lines = [
        "Hlt2DiMuonJPsiTurbo",
        "Hlt2DiMuonPsi2STurbo",
	]

cods = [
        "(INTREE((ID=='mu+')&(TRCHI2DOF<3)&(TRGHOSTPROB<0.3)&(PT>1200*MeV)&(ETA>2.0)&(ETA<4.9)&(PIDmu-PIDpi>2)))&(INTREE((ID=='mu-')&(TRCHI2DOF<3)&(TRGHOSTPROB<0.3)&(PT>1200*MeV)&(ETA>2.0)&(ETA<4.9)&(PIDmu-PIDpi>2)))&(INTREE((ABSID=='J/psi(1S)')&(PT>0*MeV)))",
        "(INTREE((ID=='mu+')&(TRCHI2DOF<3)&(TRGHOSTPROB<0.3)&(PT>1200*MeV)&(ETA>2.0)&(ETA<4.9)&(PIDmu-PIDpi>2)))&(INTREE((ID=='mu-')&(TRCHI2DOF<3)&(TRGHOSTPROB<0.3)&(PT>1200*MeV)&(ETA>2.0)&(ETA<4.9)&(PIDmu-PIDpi>2)))&(INTREE((ABSID=='J/psi(1S)')&(PT>0*MeV)))",
        ]

Filter=[]
for i in [1,2]:
   filt = FilterDesktop("Filter"+str(i))
   dks=[]
   dks.append("{0}/Particles".format(hlt2lines[i-1]))
   filt.Inputs = dks
   filt.Code = cods[i-1]
   filt.Output="Filter"+str(i)+"/Particles"
   Filter.append(filt)

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
tuple1.Inputs = ["Filter1/Particles"]
tuple1.Decay = "J/psi(1S) -> ^mu+ ^mu-" 
tuple1.Branches = {
	"mup":"J/psi(1S) -> ^mu+ mu-",
	"mum":"J/psi(1S) -> mu+ ^mu-",
	"psi":"J/psi(1S) -> mu+ mu-",
    }
tuple1.ToolList += tl
tuple1.WriteP2PVRelations = False
#/Event/Leptons/Turbo/Primary
tuple1.InputPrimaryVertices = "/Event/Turbo/Primary"
tuple1.addTool(TupleToolPrimaries)
#tuple1.TupleToolPrimaries.InputLocation= "Primary"

tuple1.ToolList+=["LoKi::Hybrid::EvtTupleTool/LoKi_EvtTuple"]
tuple1.addTool(LoKi_EvtTuple)

tuple1.addTool(TupleToolDecay, name="psi")
tuple1.psi.addTupleTool(TupleToolTISTOS, name="TupleToolTISTOS" )
tuple1.psi.TupleToolTISTOS.Verbose=True
tuple1.psi.TupleToolTISTOS.TriggerList = mtl

tuple2 = DecayTreeTuple("tuple2")
tuple2.Inputs = ["Filter2/Particles"]
tuple2.Decay = "J/psi(1S) -> ^mu+ ^mu-" 
tuple2.Branches = {
	"mup":"J/psi(1S) -> ^mu+ mu-",
	"mum":"J/psi(1S) -> mu+ ^mu-",
	"psi":"J/psi(1S) -> mu+ mu-",
    }
tuple2.ToolList += tl
tuple2.WriteP2PVRelations = False
tuple2.InputPrimaryVertices = "/Event/Turbo/Primary"
tuple2.addTool(TupleToolPrimaries)
#tuple2.TupleToolPrimaries.InputLocation= "Primary"
tuple2.ToolList+=["LoKi::Hybrid::EvtTupleTool/LoKi_EvtTuple"]
tuple2.addTool(LoKi_EvtTuple)

tuple2.addTool(TupleToolDecay, name="psi")
tuple2.psi.addTupleTool(TupleToolTISTOS, name="TupleToolTISTOS" )
tuple2.psi.TupleToolTISTOS.Verbose=True
tuple2.psi.TupleToolTISTOS.TriggerList = mtl

from Configurables import CheckPV
checkpv = CheckPV()
#checkpv.PVLocation = "Primary"

SeqPhys1.Members += [checkpv,Filter[0],tuple1]
SeqPhys2.Members += [checkpv,Filter[1],tuple2]

########################################################################
from Configurables import DaVinci
DaVinci().EvtMax = -1		# Number of events
DaVinci().PrintFreq = 1000
DaVinci().SkipEvents = 0                       # Events to skip
DaVinci().DataType = "2016"
DaVinci().Simulation   =  False
#DaVinci().DDDBtag ="dddb-20150724"
#DaVinci().CondDBtag = "cond-20170111"
from Configurables import CondDB
CondDB( LatestGlobalTagByDataType = "2016")
DaVinci().HistogramFile = "DVHistos.root"      # Histogram file
DaVinci().TupleFile = "Tuple.root"             # Ntuple
DaVinci().UserAlgorithms = [SeqPhys1, SeqPhys2]
DaVinci().Lumi = True
DaVinci().InputType = "MDST"
DaVinci().RootInTES = '/Event/Turbo'
DaVinci().Turbo = True

hlt2codes=[]
for i in [1,2]:
   hlt2codes.append("HLT_PASS_RE('.*{0}.*')".format(hlt2lines[i-1]))
from PhysConf.Filters import LoKi_Filters
trigger_filter = LoKi_Filters(
    # Adjust this regular expression to match whatever set of lines you're
    # interested in studying
    HLT2_Code="|".join(hlt2codes)
)
DaVinci().EventPreFilters = trigger_filter.filters('TriggerFilter')

from GaudiConf import IOHelper
IOHelper().inputFiles(['00047765_00000018_1.turbo.mdst'])

