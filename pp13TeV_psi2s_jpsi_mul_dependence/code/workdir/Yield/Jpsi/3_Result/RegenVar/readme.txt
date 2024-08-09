before draw MC. first run /nishome/kangye/disk402_ppAnalysis/ForWorkdir/Yield/Jpsi/0_CFile/Resample/RegenVarMC.C, the weight there should be in the weight here.


因为之前想要放在一起所以这里make a mistake了，就是把/nishome/kangye/disk402_ppAnalysis/ForWorkdir/Yield/Jpsi/0_CFile/Resample/RegenVarMC.C 和这里的drawDataMC互用输入输出了。先跑前者，再生成的root文件跑drawDataMC，生成weight再去重新跑一次
