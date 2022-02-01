set terminal x11 
#set terminal png
#set output "puresine.png"


set multiplot layout 3,1 

# draw the two different sines
set xrange [0:12.8]
set xlabel "time (s)"
set ylabel "amplitude"
plot "data/puresine_phase_0.dat" u ($4):($6) with lines linecolor rgb "red" title "0.2344 Hz signal, phase=0", "data/puresine_phase_1.dat" u ($4):($6) with lines linecolor rgb "blue" title "0.2344 Hz signal, phase=PI/2"


set xrange [0:1]
set xlabel "frequency (Hz)"
set ylabel "FFT amplitude (Re)"
set arrow from 0.2344, graph 0 to 0.2344, graph 1 nohead 
plot "data/puresine_phase_0.dat" u ($2/12.8):(sqrt($8*$8)) title "0.2344 Hz signal, phase=0" with linespoints linecolor rgb "red", "data/puresine_phase_1.dat" u ($2/12.8):(sqrt($8*$8)) title "0.2344 Hz signal, phase=PI/2" with linespoints linecolor rgb "blue"

set xrange [0:1]
set xlabel "frequency (Hz)"
set ylabel "FFT amplitude (Im)"
set arrow from 0.2344, graph 0 to 0.2344, graph 1 nohead
plot "data/puresine_phase_0.dat" u ($2/12.8):(sqrt($10*$10)) title "0.2344 Hz signal, phase=0" with linespoints linecolor rgb "red", "data/puresine_phase_1.dat" u ($2/12.8):(sqrt($10*$10)) title "0.2344 Hz signal, phase=PI/2" with linespoints linecolor rgb "blue"



unset multiplot
