#!/bin/sh

#              <theta_i> <q> <Fd> <Wd>
./bin/main_HO_realistic.exe 0.15 0.5 0.0 0.666666  > ./data/realistic_FD0.0.dat 
./bin/main_HO_realistic.exe 0.15 0.5 0.5 0.666666  > ./data/realistic_FD0.5.dat 
./bin/main_HO_realistic.exe 0.15 0.5 1.2 0.666666  > ./data/realistic_FD1.2.dat 


# for delta theta
./bin/main_HO_realistic.exe 0.2 0.5 0.5  0.666666  > ./data/realistic_thetai0.2_FD0.5.dat 
./bin/main_HO_realistic.exe 0.201 0.5 0.5  0.666666  > ./data/realistic_thetai0.201_FD0.5.dat 
./bin/main_HO_realistic.exe 0.2 0.5 1.2  0.666666  > ./data/realistic_thetai0.2_FD1.2.dat 
./bin/main_HO_realistic.exe 0.201 0.5 1.2  0.666666  > ./data/realistic_thetai0.201_FD1.2.dat 

# for period doubling
./bin/main_HO_realistic.exe 0.15 0.5 1.35 0.666666  > ./data/realistic_FD1.35.dat 
./bin/main_HO_realistic.exe 0.15 0.5 1.44 0.666666  > ./data/realistic_FD1.44.dat 
./bin/main_HO_realistic.exe 0.15 0.5 1.465 0.666666  > ./data/realistic_FD1.465.dat 

# for 4-period doubling
./bin/main_HO_realistic.exe 0.15 0.5 1.47 0.666666  > ./data/realistic_FD1.47.dat 

