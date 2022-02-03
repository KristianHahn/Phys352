#set datafile separator ","

set terminal png
set output "img/realistic.png"

set  yrange[-4:4]
set  xrange[0:60]


set title ""
set ylabel "theta (radians)"
set xlabel "time (s)"

plot "./data/realistic_FD0.0.dat" using 2:4 title "FD=0.0" with lines, "./data/realistic_FD0.5.dat" using 2:4 title "FD=0.5" with lines, "./data/realistic_FD1.2.dat" using 2:4 title "FD=1.2" with lines
