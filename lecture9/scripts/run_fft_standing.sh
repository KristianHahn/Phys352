#!/bin/sh

kvals=( 2.0 4.0 8.0 )

for k in ${kvals[*]}; do 

    ./bin/main_fft_standing.exe $k > ./data/fft_standing_k_${k}.dat
    sed -e "s,XXX,$k,g" gnuplot/fft_standing_template.plt >  fft_standing.plt  
    gnuplot fft_standing.plt  
    rm fft_standing.plt  
done
