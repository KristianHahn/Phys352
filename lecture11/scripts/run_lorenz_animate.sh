#!/bin/sh

i=0;
while (( $i < 500 )); do
    pstart=`echo "$i*1000" | bc -l`
    pstop=`echo "($i+1)*1000" | bc -l`
    sed -e "s,XXX,$pstart,g; s,YYY,$pstop,g; s,ZZZ,$i,g;" gnuplot/lorenz_phasespace_template.plt > tmp.plt
    gnuplot tmp.plt
    (( i++ ))
done 
rm tmp.plt 

convert -delay 5 $(ls img/lorenz_phasespace_*.png | sort -t'_' -k3 -n) -loop 0 img/lorenz.gif
rm img/lorenz_phasespace_*.png
