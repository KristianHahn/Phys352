set terminal png

set xrange[1:1000]
set yrange[-1:1]

set ylabel "Magnetization"
set xlabel "MC time step"


set output "img/timeseries_T1.5.png"
plot 'data/timeseries_T1.5.dat' u 2:4 title "10x10 lattice, T=1.5" with lines lc rgb "red"

set output "img/timeseries_T2.0.png"
plot 'data/timeseries_T2.0.dat' u 2:4  title "10x10 lattice, T=2.0" with lines lc rgb "red"

set output "img/timeseries_T2.25.png"
plot 'data/timeseries_T2.25.dat' u 2:4  title "10x10 lattice, T=2.25" with lines lc rgb "red"

set output "img/timeseries_T4.0.png"
plot 'data/timeseries_T4.0.dat' u 2:4  title "10x10 lattice, T=4.0" with lines lc rgb "red"
