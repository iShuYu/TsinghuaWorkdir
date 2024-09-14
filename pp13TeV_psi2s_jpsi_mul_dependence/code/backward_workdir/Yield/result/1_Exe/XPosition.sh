./XPosition ../3_Result/JpsiMultiplicityDist.root "Sp" ../3_Result/Psi2SMultiplicityDist.root "Sp" ../../rawdata/3_Bins/nbin 10000 "../4_Plot/JpsiPrompt" "../4_Plot/Psi2SPrompt" ../3_Result/promptBin.txt ../3_Result/promptBinErr.txt
./XPosition ../3_Result/JpsiMultiplicityDist.root "Sb" ../3_Result/Psi2SMultiplicityDist.root "Sb" ../../rawdata/3_Bins/nbin 10000 "../4_Plot/JpsiFromb" "../4_Plot/Psi2SFromb" ../3_Result/frombBin.txt ../3_Result/frombBinErr.txt
numpt=$(head -1 ../../rawdata/3_Bins/ptbin)
for i in $(seq 1 $numpt)
do
        ./XPosition ../3_Result/JpsiMultiplicityDistPT${i}.root "Sp" ../3_Result/Psi2SMultiplicityDistPT${i}.root "Sp" ../../rawdata/3_Bins/nbin 10000 "../4_Plot/JpsiPromptPT${i}" "../4_Plot/Psi2SPromptPT${i}" ../3_Result/promptBinPT${i}.txt ../3_Result/promptBinPTErr${i}.txt
        ./XPosition ../3_Result/JpsiMultiplicityDistPT${i}.root "Sb" ../3_Result/Psi2SMultiplicityDistPT${i}.root "Sb" ../../rawdata/3_Bins/nbin 10000 "../4_Plot/JpsiFrombPT${i}" "../4_Plot/Psi2SFrombPT${i}" ../3_Result/frombBinPT${i}.txt ../3_Result/frombBinPT${i}Err.txt
done
numy=$(head -1 ../../rawdata/3_Bins/ybin)
for i in $(seq 1 $numy)
do
	./XPosition ../3_Result/JpsiMultiplicityDistY${i}.root "Sp" ../3_Result/Psi2SMultiplicityDistY${i}.root "Sp" ../../rawdata/3_Bins/nbin 10000 "../4_Plot/JpsiPromptY${i}" "../4_Plot/Psi2SPromptY${i}" ../3_Result/promptBinY${i}.txt ../3_Result/promptBinYErr${i}.txt
	./XPosition ../3_Result/JpsiMultiplicityDistY${i}.root "Sb" ../3_Result/Psi2SMultiplicityDistY${i}.root "Sb" ../../rawdata/3_Bins/nbin 10000 "../4_Plot/JpsiFrombY${i}" "../4_Plot/Psi2SFrombY${i}" ../3_Result/frombBinY${i}.txt ../3_Result/frombBinYErr${i}.txt
done


	
