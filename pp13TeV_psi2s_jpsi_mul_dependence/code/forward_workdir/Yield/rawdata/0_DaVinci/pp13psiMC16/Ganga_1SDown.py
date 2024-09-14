myJobName = '16MC1SMagDown'

#for the first time, uncomment the following line
#myApplication = prepareGaudiExec('DaVinci','v44r8')
#for more submissions, uncomment the following two lines
myApplication = GaudiExec()
myApplication.directory='/afs/cern.ch/user/y/yokang/cmtuser/DaVinciDev_v44r8'

myApplication.platform='x86_64-slc6-gcc62-opt'
myApplication.options = [ './DaVinci1S16.py',
                           ]

#data = BKQuery(dqflag = "OK" ,path  = "/MC/2018/24142001/Beam6500GeV-2018-MagDown-Nu1.6-25ns-Pythia8/Sim09g/Trig0x617d18a4/Reco18/Turbo05-WithTurcal/Stripping34NoPrescalingFlagged/ALLSTREAMS.DST",type = "Path").getDataset()
#data = BKQuery(dqflag = "OK" ,path  = "/MC/2018/Beam6500GeV-2018-MagDown-Nu1.6-25ns-Pythia8/Sim09g/Trig0x617d18a4/Reco18/Turbo05-WithTurcal/Stripping34NoPrescalingFlagged/24142001/ALLSTREAMS.DST",type = "Path").getDataset()
data = BKQuery(dqflag = "OK" ,path  = "/MC/2016/Beam6500GeV-2016-MagDown-Nu1.6-25ns-Pythia8/Sim09b/Trig0x6138160F/Reco16/Turbo03/Stripping26NoPrescalingFlagged/24142001/ALLSTREAMS.DST",type = "Path").getDataset()
mySplitter = SplitByFiles( filesPerJob = 25, maxFiles = 800, ignoremissing = True)

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
#j.backend.settings['BannedSites'] = ['LCG.RAL.uk']
#j.backend.settings['BannedSites'] = ['LCG.CERN.cern']
j.submit(keep_going=True, keep_on_fail=True)
