set xrange[100:160]
set grid x y
set xlabel "m(gg)"
set ylabel "N"


plot  "higgs.dat" using ($1):2:3 with yerrorbars

set terminal png
set output 'mggNoFit.png'
replot 
