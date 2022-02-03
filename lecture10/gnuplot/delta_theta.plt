
set logscale y
set format y "%.0tx10^{%T}"

set xlabel "time (s)"
set ylabel "dtheta (radians)"

set terminal png

set xrange [0:40]
set output "img/delta_theta_FD_0.5.png"
plot "<paste data/realistic_thetai0.2_FD0.5.dat data/realistic_thetai0.201_FD0.5.dat" using 2:(abs($4-$14)) with lines title "dTheta for FD=0.5"


set xrange [0:100]
set output "img/delta_theta_FD_1.2.png"
plot "<paste data/realistic_thetai0.2_FD1.2.dat data/realistic_thetai0.201_FD1.2.dat" using 2:(abs($4-$14)) with lines title "dTheta for FD=1.2"


