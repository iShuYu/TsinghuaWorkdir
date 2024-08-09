#Remove all the output before, add comment after "#"
#Before executing the commands, cd ../1_CFile/ and run root PVZvsMul.C
rm -rf ../0_File/Data/Divide/* #
rm -rf ../0_File/Data/Cut/* #
rm -rf ../4_Result/CBFit/log/* #
rm -rf ../4_Result/CBFit/*txt #
rm -rf ../4_Result/CBFit/sPlot/* #
rm -rf ../5_Plots/CBFit/* #
rm -rf ../0_File/Data/SideBand/* #
rm -rf ../0_File/MC/Divide/* #
rm -rf ../0_File/MC/Cut/* #
rm -rf ../4_Result/TzbkgFit/PDF/* #
rm -rf ../4_Result/TzbkgFit/log/* #
rm -rf ../4_Result/TzbkgFit/*.txt #
rm -rf ../4_Result/TwoDimFit/log/* #
rm -rf ../4_Result/TwoDimFit/PDF/* #
rm -rf ../5_Plots/TzbkgFit/* #
rm -rf ../5_Plots/TwoDimFit/ProjTz/* #
rm -rf ../5_Plots/TwoDimFit/ProjMass/* #
rm -rf ../4_Result/Eff_Acc/* #
rm -rf ../5_Plots/Reweight/* #
rm -rf ../4_Result/Eff_RecselPIDTrigger/* #
rm -rf ../5_Plots/Eff_RecselPIDTrigger/* #
rm -rf ../4_Result/SysErr/PIDCalibBinScheme/* #
rm -rf ../4_Result/SysErr/General/* #
rm -rf ../5_Plots/TwoDimFit/*txt #
rm -rf ../5_Plots/Results/* #
wait

#Run in order to do the whole analysis automatically
#Check all the RAW data of Data, MC, PIDTable, TrackTable
source Divide.sh #check definition of psi_Y
source Divide_FullMC.sh #check definition of psi_Y
wait
source Cut.sh #check PVZ and definition of psi_Y
source SideBand.sh #check PVZ and definition of psi_Y
source Cut_MC.sh #check PVZ and definition of psi_Y
wait
source CBFit.sh #check fit status
wait
source Reweight.sh #check mean value for low/high Mul., check Mul. Variable, check its limits
wait
source TzbkgFit.sh #check fit status
wait
source TwoDimFit.sh #check fit status
wait
source Draw_TzbkgFit.sh #
wait
source Draw_TwoProjTz.sh #
source Draw_TwoProjMass.sh #
source Draw_Reweight.sh #
wait
source Eff_Acc.sh #check PVZ and definition of psi_Y
source Eff_RecselPIDTrigger.sh #check PVZ for mct
wait
source SysErr_General.sh #
source SysErr_PIDCalibBinScheme.sh #no need for others
wait
source GetEffMean.sh #
source ttCut.sh #
wait
source ttCBFit.sh #
wait
./../2_Exe/ttMC  >/dev/null 2>&1 & #
wait
source Draw_Result.sh #
wait
./../2_Exe/DrawNoNorm >/dev/null 2>&1 & #
./../2_Exe/DrawNorm2pp >/dev/null 2>&1 & #
wait


