#!/bin/sh


./bin/main_correlations.exe $RANDOM 1.00 0.0 50000 20 > ./data/correlation_T_1.00.dat
./bin/main_correlations.exe $RANDOM 1.50 0.0 50000 20 > ./data/correlation_T_1.50.dat
./bin/main_correlations.exe $RANDOM 2.00 0.0 50000 20 > ./data/correlation_T_2.00.dat
./bin/main_correlations.exe $RANDOM 2.25 0.0 50000 20 > ./data/correlation_T_2.25.dat
./bin/main_correlations.exe $RANDOM 2.50 0.0 50000 20 > ./data/correlation_T_2.50.dat
./bin/main_correlations.exe $RANDOM 2.75 0.0 50000 20 > ./data/correlation_T_2.75.dat
./bin/main_correlations.exe $RANDOM 3.00 0.0 50000 20 > ./data/correlation_T_3.00.dat
./bin/main_correlations.exe $RANDOM 5.00 0.0 50000 20 > ./data/correlation_T_5.00.dat

