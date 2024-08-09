myJobName = 'MCcc2mumu2SMagDown'

#for the first time, uncomment the following line
#myApplication = prepareGaudiExec('DaVinci','v44r8')
#for more submissions, uncomment the following two lines
myApplication = GaudiExec()
myApplication.directory='/afs/cern.ch/user/y/yokang/cmtuser/DaVinciDev_v44r8'

myApplication.platform='x86_64-slc6-gcc62-opt'
myApplication.options = [ './DaVinci2SMagDown.py',
                           ]

data = BKQuery(dqflag = "OK" ,path  = "/MC/2015/Beam6500GeV-2015-MagDown-Nu1.6-25ns-Pythia8/Sim09b/Trig0x411400a2/Reco15a/Turbo02/Stripping24NoPrescalingFlagged/28142001/ALLSTREAMS.DST",type = "Path").getDataset()

mySplitter = SplitByFiles( filesPerJob =1 , maxFiles = 20, ignoremissing = True)

myBackend = Dirac()
j = Job (
    name         = myJobName,
    application  = myApplication,
    splitter     = mySplitter,
    outputfiles  = [ DiracFile('Tuple.root'),
                     LocalFile('DVHistos.root')
                     ],
    #inputsandbox = [ '/afs/ihep.ac.cn/users/q/qianch/D0Kpi_600000.xml' ],
    backend      = myBackend,
    inputdata    = data,
    do_auto_resubmit = True
    )
j.submit(keep_going=True, keep_on_fail=True)

