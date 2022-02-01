
#change k's accordingly
k1 = 4
k2 = 4.4
f1 = 300*k1
f2 = 300*k2

# and n is needed ...
N = 800

set multiplot layout 2,1 

title1 = sprintf("beat : f2-f1 = %.0f Hz", f2-f1)

set xrange[0:0.0066]
p "data/fft_beat_sum.dat" u 4:6 w l title title1


set xrange[1000:2000]
set arrow from f1, graph 0 to f1, graph 1 nohead 
set arrow from f2, graph 0 to f2, graph 1 nohead 
p "data/fft_beat_sum.dat" u ($2/(N*0.000033)):(sqrt($8*$8)) w l title "Re", "data/fft_beat_sum.dat" u ($2/(N*0.000033)):(sqrt($10*$10)) w l title "Im"



