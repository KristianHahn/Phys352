set terminal pngcairo
set output ofile

set xrange[-5:5]
set yrange[-1:1]

set ylabel "M"
set xlabel "H"

plot ifileN2P u 4:6 title titleN2P with lp pt 7 ps 0.5 lc rgb "red", ifileP2N u 4:6 title titleP2N with lp pt 6 ps 0.6 lc rgb "blue"



