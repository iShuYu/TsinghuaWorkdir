myJobName = 'cc2mumuMagDown108A2'
myApplication = GaudiExec()
#myApplication.version = DaVinciVersion
myApplication.directory = '~/cmtuser/DaVinciDev_v44r8'
myApplication.platform='x86_64-slc6-gcc62-opt'
myApplication.options = [ './DaVinci.py',
                           ]

data = BKQuery(dqflag = "OK" ,path  = "165506-165854/Real Data/Turbo01/94000000/TURBO.MDST" ,type = "Run" ).getDataset()
data1 = BKQuery(dqflag = "OK" ,path  = "165885-165887/Real Data/Turbo01/94000000/TURBO.MDST" ,type = "Run" ).getDataset()
data2 = BKQuery(dqflag = "OK" ,path  = "165973/Real Data/Turbo01/94000000/TURBO.MDST" ,type = "Run" ).getDataset()
data3 = BKQuery(dqflag = "OK" ,path  = "166004/Real Data/Turbo01/94000000/TURBO.MDST" ,type = "Run" ).getDataset()
data4 = BKQuery(dqflag = "OK" ,path  = "166059/Real Data/Turbo01/94000000/TURBO.MDST" ,type = "Run" ).getDataset()
data5 = BKQuery(dqflag = "OK" ,path  = "166085-166086/Real Data/Turbo01/94000000/TURBO.MDST" ,type = "Run" ).getDataset()
data6 = BKQuery(dqflag = "OK" ,path  = "166108/Real Data/Turbo01/94000000/TURBO.MDST" ,type = "Run" ).getDataset()
data7 = BKQuery(dqflag = "OK" ,path  = "166130/Real Data/Turbo01/94000000/TURBO.MDST" ,type = "Run" ).getDataset()
data.extend(data1)
data.extend(data2)
data.extend(data3)
data.extend(data4)
data.extend(data5)
data.extend(data6)
data.extend(data7)

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

