#set terminal x11 size 1000,1000
set terminal png size 1000,1000
set output "fft_standing_k_8.0.png"

# change k accordingly ...
k = 8.0
f = 300*k
fname = sprintf("data/fft_standing_k_%.1f.dat", k)

set multiplot layout 2,1

set yrange[-2.5:2.5]
set xrange[0:0.0066]
tstring = sprintf("timeseries, f = %f Hz", f)
plot fname using 4:6 w l title tstring


unset yrange
set xrange[0:5000]
set arrow from f,graph 0 to f,graph 1 nohead
tstring = sprintf("FFT, f = %f Hz", f)
plot fname using ($2/(400*0.000033)):(sqrt($8*$8)) w l title tstring, fname using ($2/(400*0.000033)):(sqrt($10*$10)) w l title tstring

unset multiplot
