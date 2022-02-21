#!/bin/sh


./bin/main_fit_exp_LLS_GSL.exe ./idata/expGSL.dat 500 | grep "++fit++ " | sed -e 's,++fit++,,' > odata/exp_LLS_GSL.dat
./bin/main_fit_exp_LLS_GSL.exe  ./idata/expGSL.dat 500 weight | grep "++fit++ " | sed -e 's,++fit++,,' > odata/exp_LLS_GSL_weight.dat

./bin/main_fit_exp_LLS_GSL.exe ./idata/exp.dat 500 | grep "++fit++ " | sed -e 's,++fit++,,' > odata/exp_LLS_GSL.root.dat
./bin/main_fit_exp_LLS_GSL.exe  ./idata/exp.dat 500 weight | grep "++fit++ " | sed -e 's,++fit++,,' > odata/exp_LLS_GSL_weight.root.dat
