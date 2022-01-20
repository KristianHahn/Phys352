set xrange [0:30000]
set yrange [0:10000]

set terminal png
set output "drag.png"

set title "Trajectory [vi=700 m/s, B2/m=4e-5 m^-1, a=6.5e-3 K/m, alpha=2.5]"
set xlabel "x(km)"
set ylabel "y(km)"


plot "data/drag_adiabatic_35.dat" using 4:6 with lines linecolor rgb "blue" title "35 deg, w/ correction", "data/drag_adiabatic_45.dat" using 4:6 with lines linecolor rgb "red" title "45 deg, w/ correction", "data/drag_35.dat" using 4:6 with dots linecolor rgb "blue" title "35 deg, w/o correction", "data/drag_45.dat" using 4:6 with dots linecolor rgb "red" title "45 deg, w/o correction"
