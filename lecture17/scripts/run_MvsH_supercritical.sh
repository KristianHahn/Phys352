#!/bin/sh

temps=(200 100 30 10)

# for each T, scan H from -5 to 5 in steps of 0.5

for T in ${temps[*]}; do
    H=-5;
    rm data/MvsH_supercritical_T${T}.dat
    while (( `echo "$H < 5.0" | bc -l` )); do
	./bin/main_M_vs_T.exe $RANDOM $T $H -1.0 | grep "T:" >> data/MvsH_supercritical_T${T}.dat
	H=`echo "$H + 0.25" | bc -l`
    done;
done


