
p 'data/specific_heat_10.dat' u 2:4 w linespoints, 'data/specific_heat_50.dat' u 2:4 w linespoints, 'data/specific_heat_100.dat' u 2:4 w linespoints, 'data/specific_heat_200.dat' u 2:4 w linespoints

set ylabel "Specific Heat per Spin"
set xlabel "Temperature"

set term png 
set output "img/specific_heat.png"
replot
