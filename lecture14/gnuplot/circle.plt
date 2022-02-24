set term pngcairo
set output "img/circle.png"

set style line 1 lc rgb "blue" lt 1 lw 2 pt 7 ps 0.25   # --- blue
set style line 2 lc rgb "red" lt 1 lw 2 pt 7 ps 0.25   # --- red

set xrange [0:1]
set yrange [0:1]

plot "data/circle.dat" using 1:($3==0?$2:1/0) with points ls 2 notitle, "data/circle.dat" using 1:($3==1?$2:1/0) with points ls 1 notitle
