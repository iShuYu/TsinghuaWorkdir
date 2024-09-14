	rm -rf ../2_AfterDivide/MC/Jpsi/n${1}_fromb.root
	rm -rf ../2_AfterDivide/MC/Jpsi/n${1}_prompt.root
	rm -rf ../2_AfterDivide/MC/Jpsi/n${1}_total.root
	rm -rf ../2_AfterDivide/MC/Jpsi/mctn${1}_fromb.root
	rm -rf ../2_AfterDivide/MC/Jpsi/mctn${1}_prompt.root
	rm -rf ../2_AfterDivide/MC/Jpsi/mctn${1}_total.root
	hadd ../2_AfterDivide/MC/Jpsi/n${1}_fromb.root ../2_AfterDivide/MC/Jpsi/n${1}_MagUp_fromb.root ../2_AfterDivide/MC/Jpsi/n${1}_MagDown_fromb.root >/dev/null 2>&1 &
	hadd ../2_AfterDivide/MC/Jpsi/n${1}_prompt.root ../2_AfterDivide/MC/Jpsi/n${1}_MagUp_prompt.root ../2_AfterDivide/MC/Jpsi/n${1}_MagDown_prompt.root >/dev/null 2>&1 &
	hadd ../2_AfterDivide/MC/Jpsi/n${1}_total.root ../2_AfterDivide/MC/Jpsi/n${1}_MagUp.root ../2_AfterDivide/MC/Jpsi/n${1}_MagDown.root >/dev/null 2>&1 &
	hadd ../2_AfterDivide/MC/Jpsi/mctn${1}_fromb.root ../2_AfterDivide/MC/Jpsi/mctn${1}_MagUp_fromb.root ../2_AfterDivide/MC/Jpsi/mctn${1}_MagDown_fromb.root >/dev/null 2>&1 &
        hadd ../2_AfterDivide/MC/Jpsi/mctn${1}_prompt.root ../2_AfterDivide/MC/Jpsi/mctn${1}_MagUp_prompt.root ../2_AfterDivide/MC/Jpsi/mctn${1}_MagDown_prompt.root >/dev/null 2>&1 &
        hadd ../2_AfterDivide/MC/Jpsi/mctn${1}_total.root ../2_AfterDivide/MC/Jpsi/mctn${1}_MagUp.root ../2_AfterDivide/MC/Jpsi/mctn${1}_MagDown.root >/dev/null 2>&1 &
