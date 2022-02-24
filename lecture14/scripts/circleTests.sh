#!/bin/bash


if [ -e data/circleTests_5000.dat ]; then rm data/circleTests_5000.dat; fi
i=0  
while (( $i < 1000 )); do 
    ./bin/circleInt.exe 5001 $RANDOM;  
    (( i++ )); 
done  | grep '4A' | awk '{print $4}' >> ./data/circleTests_5000.dat

if [ -e data/circleTests_10000.dat ]; then rm data/circleTests_10000.dat; fi
 i=0  
 while (( $i < 1000 )); do 
     ./bin/circleInt.exe 10001 $RANDOM;  
     (( i++ )); 
 done  | grep '4A' | awk '{print $4}' > ./data/circleTests_10000.dat


 if [ -e data/circleTests_20000.dat ]; then rm data/circleTests_20000.dat; fi
 i=0  
 while (( $i < 1000 )); do 
     ./bin/circleInt.exe 20001 $RANDOM;  
     (( i++ )); 
 done  | grep '4A' | awk '{print $4}' > ./data/circleTests_20000.dat

if [ -e data/circleTests_40000.dat ]; then rm data/circleTests_40000.dat; fi
i=0  
while (( $i < 1000 )); do 
    ./bin/circleInt.exe 40001 $RANDOM;  
    (( i++ )); 
done  | grep '4A' | awk '{print $4}' > ./data/circleTests_40000.dat


