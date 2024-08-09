#DaVinciVersion = 'v41r4'
myJobName = 'cc2mumuMagDown106A2'
myApplication = GaudiExec()
#myApplication.version = DaVinciVersion
myApplication.directory = '~/cmtuser/DaVinciDev_v44r8'
myApplication.platform='x86_64-slc6-gcc62-opt'
myApplication.options = [ './DaVinci.py',
                           ]
data = BKQuery(dqflag = "OK", path  = "/164235-165420/Real Data/Turbo01/94000000/TURBO.MDST" ,type = "Run" ).getDataset()

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
