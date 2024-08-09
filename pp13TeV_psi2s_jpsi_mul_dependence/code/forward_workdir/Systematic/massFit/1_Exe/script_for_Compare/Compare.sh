./eff_p_and_b ${1} ../../../Yield/Jpsi/3_Result/eff_tot/n${1}_prompt.root ../../../Yield/Jpsi/3_Result/eff_tot/n${1}_fromb.root ../3_Result/Jpsi/n${1}_total.root "Jpsi"
./eff_p_and_b ${1} ../../../Yield/Psi2S/3_Result/eff_tot/n${1}_prompt.root ../../../Yield/Psi2S/3_Result/eff_tot/n${1}_fromb.root ../3_Result/Psi2S/n${1}_total.root "Psi2S"
wait
./Compare ../../../Yield/Jpsi/3_Result/eff_rec_sel/n1_prompt.root ${1}
./Compare_int_pt ../../../Yield/Jpsi/3_Result/eff_rec_sel/n1_prompt.root ${1}
./Compare_int_y ../../../Yield/Jpsi/3_Result/eff_rec_sel/n1_prompt.root ${1}
./Compare_int ../../../Yield/Jpsi/3_Result/eff_rec_sel/n1_prompt.root ${1}
./Compare_intNYtoPT ../../../Yield/Jpsi/3_Result/eff_rec_sel/n1_prompt.root
