set term pngcairo size 1000,500
set output "img/lorenz_attractor.png"

set multiplot layout 1,2

set xrange[-10:10]
set yrange[0:30]
set ylabel "z"
set ylabel "y"
plot "data/lorenz_25.0.dat" u 6:($4*$4<0.001?$8:1/0) w p title "z vs y, x=0"

set xrange[-20:20]                                        
set yrange[0:40]                                          
set ylabel "z"
set ylabel "x"
plot "data/lorenz_25.0.dat" u 4:($6*$6<0.001?$8:1/0) w p title "z vs x, y=0"


unset multiplot 
