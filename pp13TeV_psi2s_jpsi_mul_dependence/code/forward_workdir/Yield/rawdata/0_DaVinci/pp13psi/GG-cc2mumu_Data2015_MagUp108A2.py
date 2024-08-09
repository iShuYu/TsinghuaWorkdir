myJobName = 'cc2mumuMagUp108A2'

#for the first time, uncomment the following line
#myApplication = prepareGaudiExec('DaVinci','v44r8')
#for more submissions, uncomment the following two lines
myApplication = GaudiExec()
myApplication.directory='/afs/cern.ch/user/x/xianglei/cmtuser/DaVinciDev_v44r8'

myApplication.platform='x86_64-slc6-gcc62-opt'
myApplication.options = [ './DaVinci.py',
                           ]

data = BKQuery(dqflag = "OK" ,path  = "166227-166688/Real Data/Turbo01/94000000/TURBO.MDST" ,type = "Run" ).getDataset()

mySplitter = SplitByFiles( filesPerJob =20 , maxFiles = -1, ignoremissing = True)

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

