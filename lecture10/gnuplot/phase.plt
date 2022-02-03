set terminal png

set title ""
set ylabel "omega (radians/s)"
set xlabel "theta (radians)"

set  yrange[-1:1]
set  xrange[-1:1]
set output "img/phase_FD0.5.png"
plot "data/realistic_FD0.5.dat" using 4:6 title "FD=0.5" with dots

set  yrange[-3.5:3.5]
set  xrange[-3.5:3.5]
set output "img/phase_FD1.2.png"
plot "data/realistic_FD1.2.dat" using 4:6 title "FD=1.2" with dots
