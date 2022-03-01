set term png

#set xrange[1:10000]
#set yrange[-1:1]

set ylabel "Energy per Spin"
set xlabel "Temperature"

set output 'img/EvsT.png'
plot 'data/EvsT.dat' u 2:4 title "10x10 lattice" w p  pt 6 lc rgb "red"


replot
