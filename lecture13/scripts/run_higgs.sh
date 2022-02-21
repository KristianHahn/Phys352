#!/bin/sh 

./bin/main_fit_higgs_BGonly_NLLS_GSL.exe ./data/higgs.dat 60 >& log/higgs_BGonly.log

./bin/main_fit_higgs_SIG_BGfixed_NLLS_GSL.exe ./data/higgs.dat 60 >& log/higgs_sig_bgfixed.log

./bin/main_fit_higgs_SIG_BG2comp_NLLS_GSL.exe  ./data/higgs.dat 60 >& log/higgs_sig_bg2comp.log
./bin/main_fit_higgs_SIG_BG3comp_NLLS_GSL.exe  ./data/higgs.dat 60 >& log/higgs_sig_bg3comp.log

gnuplot ./gnuplot/higgsfit_BGonly.plt  
gnuplot ./gnuplot/higgsfit_fixedBG.plt
gnuplot ./gnuplot/higgsfit_2compBG.plt  
gnuplot ./gnuplot/higgsfit_3compBG.plt  
