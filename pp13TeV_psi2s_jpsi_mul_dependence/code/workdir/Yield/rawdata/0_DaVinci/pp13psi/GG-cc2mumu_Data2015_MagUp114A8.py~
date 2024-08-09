myJobName = 'cc2mumuMagUp114A8'
myApplication = GaudiExec()
myApplication.user_release_area = '~/cmtuser/DaVinciDev_v44r8'
myApplication.platform='x86_64-slc6-gcc62-opt'
myApplication.optsfile = [ './DaVinci,py',
                           ]

data = BKQuery(dqflag = "OK" ,path  = "166704-167136/Real Data/Turbo01/94000000/TURBO.MDST" ,type = "Run" ).getDataset()

mySplitter = SplitByFiles( filesPerJob =20 , maxFiles = -1, ignoremissing = True)

myBackend = Dirac()
j = Job (
    name         = myJobName,
    application  = myApplication,
    splitter     = mySplitter,
    outputfiles  = [ LocalFile('Tuple.root'),
                     LocalFile('DVHistos.root')
                     ],
    #inputsandbox = [ '/afs/ihep.ac.cn/users/q/qianch/D0Kpi_600000.xml' ],
    backend      = myBackend,
    inputdata    = data,
    do_auto_resubmit = True
    )
j.submit(keep_going=True, keep_on_fail=True)

