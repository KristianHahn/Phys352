set term pngcairo

set ylabel "z"
set xlabel "x"


set output "img/lorenz_phasespace.png"
plot "data/lorenz_25.0.dat" using 4:8 with l 


