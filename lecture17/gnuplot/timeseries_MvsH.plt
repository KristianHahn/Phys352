set terminal pngcairo
set output ofile


set yrange[-1:1]

set ylabel "M"
set xlabel "MC time step"


plot ifile u 2:4 title mytitle with l


