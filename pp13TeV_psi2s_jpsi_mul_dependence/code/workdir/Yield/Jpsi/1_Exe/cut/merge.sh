rm -rf ../../2_Rootfile/MCTIS_after_cut/MagUp.root
rm -rf ../../2_Rootfile/MCTIS_after_cut/MagDown.root
rm -rf ../../2_Rootfile/MCTIS_after_cut/TIS.root
hadd ../../2_Rootfile/MCTIS_after_cut/TIS.root ../../2_Rootfile/MCTIS_after_cut/*total*
hadd ../../2_Rootfile/MCTIS_after_cut/MagUp.root ../../2_Rootfile/MCTIS_after_cut/*_MagUp.root
hadd ../../2_Rootfile/MCTIS_after_cut/MagDown.root ../../2_Rootfile/MCTIS_after_cut/*_MagDown.root

