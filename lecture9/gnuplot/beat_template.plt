set terminal png size 1000,1000
set output "img/beat_t_XXX.png"


#change k's accordingly
k1 = 8
k2 = 8.8
f1 = 300*k1
f2 = 300*k2

set multiplot layout 2,1 

title1 = sprintf("f: %.0f Hz", f1)
title2 = sprintf("f: %.0f Hz", f2)

set yrange[-1.5:1.5]
set xrange[0:4]
p "data/wavedata_beat_t_XXX.dat" u 4:6 w l title title1, "data/wavedata_beat_t_XXX.dat" u 4:8 w l title title2

set yrange[-3:3]
set xrange[0:4]
p "data/wavedata_beat_t_XXX.dat" u 4:10 w l title "sum"

unset multiplot
