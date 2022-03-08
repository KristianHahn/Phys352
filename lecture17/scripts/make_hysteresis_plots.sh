#!/bin/sh

temps=(0.125 0.25 0.5)


for T in ${temps[*]}; do
    ifileN2P=\"data/hysteresis_T${T}_H_neg2pos.dat\"
    ifileP2N=\"data/hysteresis_T${T}_H_pos2neg.dat\"
    ofile=\"./img/hysteresis_T${T}.png\"
    titleN2P=\"T=${T},H:negative-to-positive\"
    titleP2N=\"T=${T},H:positive-to-negative\"
    gnuplot -e "ifileN2P=$ifileN2P;ifileP2N=$ifileP2N;ofile=$ofile;titleN2P=$titleN2P;titleP2N=$titleP2N;" gnuplot/hysteresis.plt
done


