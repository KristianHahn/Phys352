#!/bin/sh

#                       <mu> <x0> 
./bin/main_logistic.exe 2.0  0.35 > ./data/logistic_2.0.dat 
./bin/main_logistic.exe 3.1  0.35 > ./data/logistic_3.1.dat 
./bin/main_logistic.exe 3.8  0.35 > ./data/logistic_3.8.dat 

# for the iterate
./bin/main_logistic.exe 1.5  0.5 > ./data/logistic_1.5.dat 
./bin/main_logistic.exe 3.3  0.6 > ./data/logistic_3.3.dat 
