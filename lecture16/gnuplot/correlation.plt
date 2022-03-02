set xrange[1:9]
set yrange[-0.25:0.7]

set key font ",8"
set xlabel 'i'
set ylabel 'f(i) - <s>^2'

f(x,C1,C2,si) = C1 + C2*exp(-x/si) 


p './data/correlation_T_1.00.dat' u 2:4 title "T = 1.00",  './data/correlation_T_1.50.dat' u 2:4  title "T = 1.50", './data/correlation_T_2.00.dat' u 2:4  title "T = 2.00", './data/correlation_T_2.25.dat' u 2:4  title "T = 2.25", './data/correlation_T_2.50.dat' u 2:4  title "T = 2.50",  './data/correlation_T_2.75.dat' u 2:4  title "T = 2.75", './data/correlation_T_3.00.dat' u 2:4  title "T = 3.00",  './data/correlation_T_4.00.dat' u 2:4  title "T = 4.00",  './data/correlation_T_5.00.dat' u 2:4  title "T = 5.00"

set term png
set output "img/correlation.png"
replot
