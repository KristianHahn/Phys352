#!/bin/sh 

./scripts/run_realistic.sh
./scripts/run_fft.sh

./scripts/run_logistic.sh

./scripts/run_lorenz.sh  
./scripts/run_lorenz_animate.sh  

./scripts/make_plots.sh
