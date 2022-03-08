#!/bin/sh

temps=(0.5 1.0 2.0 2.5 3.0 5.0)

for T in ${temps[*]}; do
    ifile=\"./data/MvsH_T${T}.dat\"
    ofile=\"./img/MvsH_T${T}.png\"
    mytitle=\"T=${T}\"
    gnuplot -e "ifile=$ifile;ofile=$ofile;mytitle=$mytitle" gnuplot/MvsH.plt
done

# single timeseries for T=1.0, H=0.5
gnuplot -e "ifile='./data/timeseries_MvsH_T1.0.dat';ofile='./img/timeseries_MvsH_T1.0.png';mytitle='T=1.0, H=0.5'" gnuplot/timeseries_MvsH.plt

# single timeseries for T=3.0, H=0.5-0.7
gnuplot -e "ifile='./data/timeseries_MvsH_T3.0_H0.5.dat';ofile='./img/timeseries_MvsH_T3.0_H0.5.png';mytitle='T=3.0, H=0.5'" gnuplot/timeseries_MvsH.plt
gnuplot -e "ifile='./data/timeseries_MvsH_T3.0_H0.6.dat';ofile='./img/timeseries_MvsH_T3.0_H0.7.png';mytitle='T=3.0, H=0.6'" gnuplot/timeseries_MvsH.plt
gnuplot -e "ifile='./data/timeseries_MvsH_T3.0_H0.7.dat';ofile='./img/timeseries_MvsH_T3.0_H0.7.png';mytitle='T=3.0, H=0.7'" gnuplot/timeseries_MvsH.plt
