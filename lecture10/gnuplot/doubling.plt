set terminal png

set  yrange[-4:4]
set  xrange[0:100]


set title ""
set ylabel "theta (radians)"
set xlabel "time (s)"

set output "img/doubling_FD1.35.png"
plot "data/realistic_FD1.35.dat" using 2:4 title "FD=1.35" with lines

set output "img/doubling_FD1.44.png"
plot "data/realistic_FD1.44.dat" using 2:4 title "FD=1.44" with lines

set output "img/doubling_FD1.465.png"
plot "data/realistic_FD1.465.dat" using 2:4 title "FD=1.465" with lines
