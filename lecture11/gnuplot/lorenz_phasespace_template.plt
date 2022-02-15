set term pngcairo

set ylabel "z"
set xlabel "x"

set xrange[-20:20]
set yrange[0:50]

set output "img/lorenz_phasespace_ZZZ.png"
plot "data/lorenz_25.0.dat" every 1::0::YYY using 4:8 with l 
#plot "data/lorenz_25.0.dat" every 1::0::99 using 4:8 with l 

