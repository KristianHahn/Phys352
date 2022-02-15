#!/bin/sh

# for harmonics
#                         <theta_i> <q> <Fd> <Wd>
./bin/main_HO_realistic.exe 0.15    0.5 0.5  0.666666  > ./data/realistic_FD0.5.dat 
./bin/main_HO_realistic.exe 0.15    0.5 0.95 0.666666  > ./data/realistic_FD0.95.dat 
./bin/main_HO_realistic.exe 0.15    0.5 1.2  0.666666  > ./data/realistic_FD1.2.dat 
./bin/main_HO_realistic.exe 0.15    0.5 1.44 0.666666  > ./data/realistic_FD1.44.dat 
./bin/main_HO_realistic.exe 0.15    0.5 1.47 0.666666  > ./data/realistic_FD1.47.dat 

