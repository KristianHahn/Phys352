

#set xrange[1:10000]
#set yrange[-1:1]

#set term png
#set output "img/MvsT_coarse.png"
#plot 'data/MvsT_coarse.dat' u 2:4

set ylabel "Magnetization"
set xlabel "Temperature"

set term png
set output "img/MvsT.png"
plot 'data/MvsT.dat' u 2:4 title "10x10 lattice" w p  pt 6 lc rgb "red"



replot
