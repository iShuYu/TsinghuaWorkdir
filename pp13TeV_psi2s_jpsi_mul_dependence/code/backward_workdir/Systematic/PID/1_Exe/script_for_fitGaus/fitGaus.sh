./fitGaus ../../../Yield/Jpsi/3_Result/eff_pid/n${1}_prompt.root ../3_Result/StatCalibVar/n${1}_prompt.root ${1} 1 
./fitGaus ../../../Yield/Jpsi/3_Result/eff_pid/n${1}_fromb.root ../3_Result/StatCalibVar/n${1}_fromb.root ${1} 2 
./fitGaus_int_pt ../../../Yield/Jpsi/3_Result/eff_pid/n${1}_prompt.root ../3_Result/StatCalibVar/n${1}_int_pt_prompt.root ${1} 1 
./fitGaus_int_pt ../../../Yield/Jpsi/3_Result/eff_pid/n${1}_fromb.root ../3_Result/StatCalibVar/n${1}_int_pt_fromb.root ${1} 2 
./fitGaus_int ../../../Yield/Jpsi/3_Result/eff_pid/n${1}_prompt.root ../3_Result/StatCalibVar/n${1}_int_y_prompt.root ${1} 1 
./fitGaus_int ../../../Yield/Jpsi/3_Result/eff_pid/n${1}_fromb.root ../3_Result/StatCalibVar/n${1}_int_y_fromb.root ${1} 2 
