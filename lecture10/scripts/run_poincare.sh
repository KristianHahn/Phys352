#!/bin/sh

#              <theta_i> <q> <Fd> <Wd>
./bin/main_poincare.exe 0.15 0.5 0.0 0.666666  > data/poincare_FD0.0.dat 
./bin/main_poincare.exe 0.15 0.5 0.5 0.666666  > data/poincare_FD0.5.dat 
./bin/main_poincare.exe 0.15 0.5 1.2 0.666666  > data/poincare_FD1.2_thetai0.15.dat 
./bin/main_poincare.exe 0.20 0.5 1.2 0.666666  > data/poincare_FD1.2_thetai0.2.dat 
./bin/main_poincare.exe 0.10 0.5 1.2 0.666666  > data/poincare_FD1.2_thetai0.1.dat 


