set terminal x11 


set multiplot layout 2,1 


#set xrange [0:0.066]
set xlabel "time (s)"
set ylabel "amplitude"
plot "data/fft_pulse.dat" u ($4):($6) with lines linecolor rgb "red" 

set xrange [0:3000]
set xlabel "frequency (Hz)"
set ylabel "FFT amplitude"
#plot "data/fft_pulse.dat" u ($2/(2000*.000033)):(sqrt($8*$8)) title "Re" with linespoints linecolor rgb "black",  "data/fft_pulse.dat" u ($2/(2000*.000033)):(sqrt($10*$10)) title "Im" with linespoints linecolor rgb "red" 
plot "data/fft_pulse.dat" u ($2/(2000*.000033)):(($8*$8)+($10*$10)) title "power" with linespoints linecolor rgb "black"

#clear 

unset multiplot
