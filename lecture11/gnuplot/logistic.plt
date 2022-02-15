set terminal png


set ylabel "x"
set xlabel "n"

set yrange [0:1]
set xrange [0:50]
set output "img/logistic_steady.png"
plot "data/logistic_2.0.dat" using 2:4 with l title "mu = 2.0", "data/logistic_3.1.dat" using 2:4 with l title "mu = 3.1"

set yrange [0:1]
set xrange [0:50]
set output "img/logistic_chaotic.png"
plot "data/logistic_3.8.dat" using 2:4 with l title "mu = 3.8"
