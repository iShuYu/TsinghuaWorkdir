./fitGaus ../../../Yield/Jpsi/3_Result/eff_rec_sel/n${1}_prompt.root ../../../Yield/Jpsi/3_Result/eff_pid/n${1}_prompt.root ../../../Yield/Jpsi/3_Result/eff_trigger/n${1}_prompt.root ../../../Yield/Psi2S/3_Result/eff_rec_sel/n${1}_prompt.root ../../../Yield/Psi2S/3_Result/eff_pid/n${1}_prompt.root ../../../Yield/Psi2S/3_Result/eff_trigger/n${1}_prompt.root ../3_Result/StatsErr/n${1}_prompt.root ${1} 1 >/dev/null 2>&1 &

./fitGaus ../../../Yield/Jpsi/3_Result/eff_rec_sel/n${1}_fromb.root ../../../Yield/Jpsi/3_Result/eff_pid/n${1}_fromb.root ../../../Yield/Jpsi/3_Result/eff_trigger/n${1}_fromb.root ../../../Yield/Psi2S/3_Result/eff_rec_sel/n${1}_fromb.root ../../../Yield/Psi2S/3_Result/eff_pid/n${1}_fromb.root ../../../Yield/Psi2S/3_Result/eff_trigger/n${1}_fromb.root ../3_Result/StatsErr/n${1}_fromb.root ${1} 2 >/dev/null 2>&1 & 

./fitGaus ../../../Yield/Jpsi/3_Result/eff_rec_sel/n${1}_total.root ../../../Yield/Jpsi/3_Result/eff_pid/n${1}_total.root ../../../Yield/Jpsi/3_Result/eff_trigger/n${1}_total.root ../../../Yield/Psi2S/3_Result/eff_rec_sel/n${1}_total.root ../../../Yield/Psi2S/3_Result/eff_pid/n${1}_total.root ../../../Yield/Psi2S/3_Result/eff_trigger/n${1}_total.root ../3_Result/StatsErr/n${1}_total.root ${1} 3 >/dev/null 2>&1 &

./fitGaus_int_pt ../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_prompt.root ../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_prompt.root ${1} 1 ../3_Result/StatsErr/n${1}_int_pt_prompt.root >/dev/null 2>&1 &

./fitGaus_int_pt ../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_fromb.root ../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_fromb.root ${1} 2 ../3_Result/StatsErr/n${1}_int_pt_fromb.root >/dev/null 2>&1 &

./fitGaus_int_pt ../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_total.root ../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_total.root ${1} 3 ../3_Result/StatsErr/n${1}_int_pt_total.root >/dev/null 2>&1 &

./fitGaus_int_y ../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_prompt.root ../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_prompt.root ${1} 1 ../3_Result/StatsErr/n${1}_int_y_prompt.root >/dev/null 2>&1 &

./fitGaus_int_y ../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_fromb.root ../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_fromb.root ${1} 2 ../3_Result/StatsErr/n${1}_int_y_fromb.root >/dev/null 2>&1 &

./fitGaus_int_y ../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_total.root ../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_total.root ${1} 3 ../3_Result/StatsErr/n${1}_int_y_total.root >/dev/null 2>&1 &

./fitGaus_int ../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_prompt.root ../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_prompt.root ${1} 1 ../3_Result/StatsErr/n${1}_int_prompt.txt >/dev/null 2>&1 &

./fitGaus_int ../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_fromb.root ../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_fromb.root ${1} 2 ../3_Result/StatsErr/n${1}_int_fromb.txt >/dev/null 2>&1 &

./fitGaus_int ../../../Yield/Jpsi/3_Result/eff_acc/eff_acc_total.root ../../../Yield/Psi2S/3_Result/eff_acc/eff_acc_total.root ${1} 3 ../3_Result/StatsErr/n${1}_int_total.txt >/dev/null 2>&1 &


