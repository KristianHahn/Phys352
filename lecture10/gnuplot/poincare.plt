
set terminal png

set xlabel "theta(radians)"
set ylabel "omega(radians/s)"

set output "img/poincare_0.0.png"
plot "data/poincare_FD0.0.dat" using 4:6 with points pointtype 7 pointsize 0.5

set output "img/poincare_0.5.png"
plot "data/poincare_FD0.5.dat" using 4:6 with points pointtype 7 pointsize 0.5 title "FD=0.5"

set output "img/poincare_1.2_theta0.15.png"
plot "data/poincare_FD1.2_thetai0.15.dat" using 4:6 with points pointtype 7 pointsize 0.5 title "FD=1.2"


set output "img/poincare_1.2_combo.png"
plot "data/poincare_FD1.2_thetai0.15.dat" using 4:6 with points pointtype 7 pointsize 0.5 title "theta_i=0.15", "data/poincare_FD1.2_thetai0.2.dat" using 4:6 with points pointtype 7 pointsize 0.5 title "theta_1=0.2", "data/poincare_FD1.2_thetai0.1.dat" using 4:6 with points pointtype 7 pointsize 0.5 title "theta_1=0.1"
