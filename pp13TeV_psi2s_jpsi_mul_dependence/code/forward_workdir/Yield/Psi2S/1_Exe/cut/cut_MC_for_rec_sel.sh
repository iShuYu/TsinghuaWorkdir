numn=$(head -1 ../../../rawdata/3_Bins/nbin)
for i in $(seq 1 $numn)
do
	./cut_MC_for_rec_sel ../../../rawdata/2_Divide/2_AfterDivide/MC/Psi2S/n${i}_MagUp.root ../../2_Rootfile/MC_after_cut/n${i}_MagUp.root >/dev/null 2>&1 &
	./cut_MC_for_rec_sel ../../../rawdata/2_Divide/2_AfterDivide/MC/Psi2S/n${i}_MagDown.root ../../2_Rootfile/MC_after_cut/n${i}_MagDown.root >/dev/null 2>&1 &
	./cut_MC_for_rec_sel ../../../rawdata/2_Divide/2_AfterDivide/MC/Psi2S/n${i}_MagUp_fromb.root ../../2_Rootfile/MC_after_cut/n${i}_MagUp_fromb.root >/dev/null 2>&1 &
        ./cut_MC_for_rec_sel ../../../rawdata/2_Divide/2_AfterDivide/MC/Psi2S/n${i}_MagDown_fromb.root ../../2_Rootfile/MC_after_cut/n${i}_MagDown_fromb.root >/dev/null 2>&1 &
	./cut_MC_for_rec_sel ../../../rawdata/2_Divide/2_AfterDivide/MC/Psi2S/n${i}_MagUp_prompt.root ../../2_Rootfile/MC_after_cut/n${i}_MagUp_prompt.root >/dev/null 2>&1 &
        ./cut_MC_for_rec_sel ../../../rawdata/2_Divide/2_AfterDivide/MC/Psi2S/n${i}_MagDown_prompt.root ../../2_Rootfile/MC_after_cut/n${i}_MagDown_prompt.root >/dev/null 2>&1 &
	./cut_MC_for_rec_sel ../../../rawdata/2_Divide/2_AfterDivide/MC/Psi2S/n${i}_total.root ../../2_Rootfile/MC_after_cut/n${i}_total.root >/dev/null 2>&1 &
        ./cut_MC_for_rec_sel ../../../rawdata/2_Divide/2_AfterDivide/MC/Psi2S/n${i}_fromb.root ../../2_Rootfile/MC_after_cut/n${i}_fromb.root >/dev/null 2>&1 &
        ./cut_MC_for_rec_sel ../../../rawdata/2_Divide/2_AfterDivide/MC/Psi2S/n${i}_prompt.root ../../2_Rootfile/MC_after_cut/n${i}_prompt.root >/dev/null 2>&1 &
done
