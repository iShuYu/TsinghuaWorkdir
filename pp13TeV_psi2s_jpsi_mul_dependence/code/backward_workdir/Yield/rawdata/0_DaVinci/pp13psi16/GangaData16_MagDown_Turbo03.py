myJobName = 'Data16DOWN'
myApplication = GaudiExec()
#myApplication.version = DaVinciVersion
myApplication.directory = '~/cmtuser/DaVinciDev_v44r8'
myApplication.platform='x86_64-slc6-gcc62-opt'
myApplication.options = [ './DaVinci16.py',
                           ]

data = BKQuery(dqflag = "OK" ,path  = "/LHCb/Collision16/Beam6500GeV-VeloClosed-MagDown/Real Data/Turbo03/94000000/LEPTONS.MDST", type = "Path" ).getDataset()

mySplitter = SplitByFiles( filesPerJob = 50 , maxFiles = -1, ignoremissing = True)

myBackend = Dirac()
j = Job (
    name         = myJobName,
    application  = myApplication,
    splitter     = mySplitter,
    outputfiles  = [ DiracFile('Tuple.root'),
                     LocalFile('DVHistos.root')
                     ],
    backend      = myBackend,
    inputdata    = data,
    do_auto_resubmit = True
    )
j.submit(keep_going=True, keep_on_fail=True)
