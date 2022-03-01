#!/bin/sh

./bin/main_M_vs_time.exe $RANDOM 1.5  0 > ./data/timeseries_T1.5.dat
./bin/main_M_vs_time.exe $RANDOM 2.0  0 > ./data/timeseries_T2.0.dat
./bin/main_M_vs_time.exe $RANDOM 2.25 0 > ./data/timeseries_T2.25.dat
./bin/main_M_vs_time.exe $RANDOM 4.0  0 > ./data/timeseries_T4.0.dat
