#!/bin/bash


if [ -e data/circleTest_5000.dat ]; then rm data/circleTest_5000.dat; fi
ecco "v:f" > ./data/circleTests_5000.dat
i=0  
while (( $i < 5000 )); do 
    ./bin/circleInt.exe 5001 $RANDOM;  
    (( i++ )); 
done  | grep '4A' | awk '{print $4}' >> ./data/circleTests_5000.dat

#if [ -e data/circleTest_10000.dat ]; then rm data/circleTest_10000.dat; fi
# i=0  
# while (( $i < 10000 )); do 
#     ./bin/circleInt.exe 10001 $RANDOM;  
#     (( i++ )); 
# done  | grep '4A' | awk '{print $4}' > ./data/circleTests_10000.dat


# if [ -e data/circleTest_20000.dat ]; then rm data/circleTest_20000.dat; fi

# i=0  
# while (( $i < 20000 )); do 
#     ./bin/circleInt.exe 20001 $RANDOM;  
#     (( i++ )); 
# done  | grep '4A' | awk '{print $4}' > ./data/circleTests_20000.dat

#if [ -e data/circleTest_40000.dat ]; then rm data/circleTest_40000.dat; fi
#i=0  
#while (( $i < 40000 )); do 
#    ./bin/circleInt.exe 40001 $RANDOM;  
#    (( i++ )); 
#done  | grep '4A' | awk '{print $4}' > ./data/circleTests_40000.dat


