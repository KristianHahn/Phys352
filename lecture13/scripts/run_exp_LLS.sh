#!/bin/sh

# run these by hand, just to get the best fit parameter
# values for exp_LLS.plt

./bin/main_fit_exp_LLS.exe ./idata/exp.dat 500 
./bin/main_fit_exp_LLS.exe ./idata/expGSL.dat 500  

