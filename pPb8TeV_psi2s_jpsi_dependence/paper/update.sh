rm -rf LHCb-latex-template/latest/latex/pdf/*
wait
mkdir LHCb-latex-template/latest/latex/pdf/pPb &
mkdir LHCb-latex-template/latest/latex/pdf/Pbp &
wait
cp -r /nishome/kangye/pPb/Workdir/5_Plots LHCb-latex-template/latest/latex/pdf/pPb/Workdir &
cp -r /nishome/kangye/pPb/FWorkdir/5_Plots LHCb-latex-template/latest/latex/pdf/pPb/FWorkdir &
cp -r /nishome/kangye/pPb/BWorkdir/5_Plots LHCb-latex-template/latest/latex/pdf/pPb/BWorkdir &
cp -r /nishome/kangye/Pbp/Workdir/5_Plots LHCb-latex-template/latest/latex/pdf/Pbp/Workdir &
cp -r /nishome/kangye/Pbp/FWorkdir/5_Plots LHCb-latex-template/latest/latex/pdf/Pbp/FWorkdir &
cp -r /nishome/kangye/Pbp/BWorkdir/5_Plots LHCb-latex-template/latest/latex/pdf/Pbp/BWorkdir &
cp /nishome/kangye/pPb/Latex/1_Tables/Ratio/* LHCb-latex-template/latest/latex/Table/Ratio/ &
