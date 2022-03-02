#!/bin/sh

i=0
while (( $i < 10 )) ; do
    ./bin/test.exe $RANDOM 0 0 > ./data/lattice.dat
    gnuplot ./gnuplot/ising.plt
    mv img/test.png img/test_${i}.png
    (( i++ ))
done;
