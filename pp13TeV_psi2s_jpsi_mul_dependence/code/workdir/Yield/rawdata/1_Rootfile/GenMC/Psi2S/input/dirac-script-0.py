resultdict = {}

# dirac job created by ganga
from DIRAC.Core.Base.Script import parseCommandLine
parseCommandLine()
from LHCbDIRAC.Interfaces.API.DiracLHCb import DiracLHCb
from LHCbDIRAC.Interfaces.API.LHCbJob import LHCbJob
dirac = DiracLHCb()
sjNo='167.0'

j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.0)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.0_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.1'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.1)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.1_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.2'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.2)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.2_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.3'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.3)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.3_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.4'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.4)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.4_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.5'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.5)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.5_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.6'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.6)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.6_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.7'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.7)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.7_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.8'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.8)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.8_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.9'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.9)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.9_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.10'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.10)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.10_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.11'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.11)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.11_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.12'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.12)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.12_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.13'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.13)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.13_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.14'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.14)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.14_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.15'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.15)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.15_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.16'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.16)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.16_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.17'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.17)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.17_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.18'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.18)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.18_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.19'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.19)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.19_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.20'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.20)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.20_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.21'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.21)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.21_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.22'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.22)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.22_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.23'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.23)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.23_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.24'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.24)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.24_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.25'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.25)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.25_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.26'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.26)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.26_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.27'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.27)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.27_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.28'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.28)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.28_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.29'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.29)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.29_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.30'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.30)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.30_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.31'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.31)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.31_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.32'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.32)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.32_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.33'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.33)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.33_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.34'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.34)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.34_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.35'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.35)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.35_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.36'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.36)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.36_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.37'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.37)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.37_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.38'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.38)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.38_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.39'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.39)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.39_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.40'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.40)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.40_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.41'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.41)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.41_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.42'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.42)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.42_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.43'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.43)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.43_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.44'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.44)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.44_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.45'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.45)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.45_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.46'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.46)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.46_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.47'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.47)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.47_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.48'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.48)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.48_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.49'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.49)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.49_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.50'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.50)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.50_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.51'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.51)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.51_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.52'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.52)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.52_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.53'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.53)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.53_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.54'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.54)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.54_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.55'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.55)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.55_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.56'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.56)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.56_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.57'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.57)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.57_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.58'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.58)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.58_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.59'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.59)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.59_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.60'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.60)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.60_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.61'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.61)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.61_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.62'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.62)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.62_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.63'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.63)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.63_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.64'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.64)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.64_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.65'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.65)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.65_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.66'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.66)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.66_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.67'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.67)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.67_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.68'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.68)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.68_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.69'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.69)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.69_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.70'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.70)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.70_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.71'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.71)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.71_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.72'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.72)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.72_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.73'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.73)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.73_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.74'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.74)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.74_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.75'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.75)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.75_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.76'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.76)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.76_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.77'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.77)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.77_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.78'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.78)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.78_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.79'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.79)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.79_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.80'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.80)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.80_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.81'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.81)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.81_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.82'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.82)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.82_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.83'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.83)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.83_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.84'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.84)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.84_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.85'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.85)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.85_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.86'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.86)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.86_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.87'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.87)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.87_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.88'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.88)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.88_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.89'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.89)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.89_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.90'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.90)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.90_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.91'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.91)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.91_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.92'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.92)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.92_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.93'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.93)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.93_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.94'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.94)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.94_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.95'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.95)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.95_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.96'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.96)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.96_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.97'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.97)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.97_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.98'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.98)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.98_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
sjNo='167.99'
# dirac job created by ganga




j = LHCbJob()

# default commands added by ganga
j.setName('GenMC_Psi2S__{Ganga_GaudiExec_(167.99)}')


j.setExecutable('jobScript/GaudiExec_yokang_Job_167.99_fe9b6703-376e-467c-a167-09a25a782f92_script.py','','Ganga_GaudiExec.log', systemConfig='x86_64-slc6-gcc49-opt')
j.setInputSandbox(['LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/diracInputFiles_167_fe9b6703-376e-467c-a167-09a25a782f92.tgz', 'LFN:/lhcb/user/y/yokang/GangaFiles_05.06_Wednesday_16_June_2021/jobScripts-167_df8776a5-e038-48d8-bfe2-c597d1bd571e.tar.gz'])
j.setOutputSandbox(['__postprocesslocations__', '*.root', '*.xml'])

j.setOutputData(['*.xgen'], OutputPath='', OutputSE=[])


# <-- user settings
j.setCPUTime(1000000)

# user settings -->

# diracOpts added by user


# submit the job to dirac
j.setDIRACPlatform()

try:
	j.setNumberOfProcessors(minNumberOfProcessors=1, maxNumberOfProcessors=1)
except (AttributeError, TypeError):
	pass

j._addParameter(j.workflow, 'GangaVersion', 'JDL', '8.4.8', 'The version of ganga used to submit this job')

result = dirac.submitJob(j)
if isinstance(result, dict) and 'Value' in result:
	resultdict.update({sjNo : result['Value']})
else:
	resultdict.update({sjNo : result['Message']})
output(resultdict)
