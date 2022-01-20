#set terminal x11 size 1500,1000
set terminal png size 1500,1000
set output "sho.png"

set title "SHO Euler [l = 1m, dt = 0.04s, m = 1kg]
set ylabel "theta (rad)"
set xlabel "time (s)"

set xrange[0:10]
set  yrange[-2:2]

plot "data/sho.dat" using 2:4 title "euler"




