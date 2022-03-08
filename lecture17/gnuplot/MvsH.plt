#takes ofile, ifile, mytitle as arguments

set term pngcairo
set output ofile

set xrange[-5:5]
set yrange[-1:1]

set xlabel "H"
set ylabel "M"

plot ifile u 4:6 w lp pt 7 title mytitle
