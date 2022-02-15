set terminal pngcairo

set ylabel "z"
set xlabel "t"

set yrange [0:50]
set xrange [0:50]
set output "img/lorenz.png"
plot "data/lorenz_5.0.dat" using 2:8 with l title "r = 5.0", "data/lorenz_10.0.dat" using 2:8 with l title "r = 10.0", "data/lorenz_25.0.dat" using 2:8 with l title "r = 25.0"


