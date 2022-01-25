#!/bin/sh

./bin/main_ho_damped.exe 0.15 10 >& ./data/damped_10.dat
./bin/main_ho_damped.exe 0.15 5 >& ./data/damped_5.dat
./bin/main_ho_damped.exe 0.15 1 >& ./data/damped_1.dat
