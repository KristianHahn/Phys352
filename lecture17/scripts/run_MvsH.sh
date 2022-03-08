#!/bin/sh

temps=(0.5 1.0 2.0 2.5 3.0 5.0)

# for each T, scan H from -5 to 5 in steps of 0.5

#for T in ${temps[*]}; do
#    H=-5;
#    rm data/MvsH_T${T}.dat
#    while (( `echo "$H < 5.0" | bc -l` )); do
#	./bin/main_M_vs_T.exe $RANDOM $T $H -1.0 | grep "T:" >> data/MvsH_T${T}.dat
#	H=`echo "$H + 0.25" | bc -l`
#    done;
#done

# run one timeseries at T=1.0 to illustrate that M indeed flips instantaneously ...
T=1.0; H=0.5
./bin/main_M_vs_T.exe $RANDOM $T $H -1.0 verbose | grep "M:" >> data/timeseries_MvsH_T${T}.dat

# run a few timeseries at T=3.0 to illustrate that M changes continuously above Tc ...
T=3.0; H=0.5
./bin/main_M_vs_T.exe $RANDOM $T $H -1.0 verbose | grep "M:" >> data/timeseries_MvsH_T${T}_H${H}.dat
T=3.0; H=0.6
./bin/main_M_vs_T.exe $RANDOM $T $H -1.0 verbose | grep "M:" >> data/timeseries_MvsH_T${T}_H${H}.dat
T=3.0; H=0.7
./bin/main_M_vs_T.exe $RANDOM $T $H -1.0 verbose | grep "M:" >> data/timeseries_MvsH_T${T}_H${H}.dat
