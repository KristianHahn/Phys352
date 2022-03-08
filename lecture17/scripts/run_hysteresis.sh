#!/bin/sh

temps=(0.125 0.25 0.5)

# for each T, scan H from -5 to 5 in steps of 0.5

for T in ${temps[*]}; do

    H=-5;
    rm data/hysteresis_T${T}_H_neg2pos.dat
    while (( `echo "$H < 5.0" | bc -l` )); do
	./bin/main_M_vs_T.exe $RANDOM $T $H -1.0 | grep "T:" >> data/hysteresis_T${T}_H_neg2pos.dat
	H=`echo "$H + 0.25" | bc -l`
    done;

    H=5;
    rm data/hysteresis_T${T}_H_pos2neg.dat
    while (( `echo "$H > -5.0" | bc -l` )); do
	./bin/main_M_vs_T.exe $RANDOM $T $H 1.0 | grep "T:" >> data/hysteresis_T${T}_H_pos2neg.dat
	H=`echo "$H - 0.25" | bc -l`
    done;
done


