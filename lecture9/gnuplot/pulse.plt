set terminal png size 1000,1000
set output "pulse_t_199.png"

set yrange[-1.5:1.5]
set xrange[0:1]
p "data/wavedata_pulse_t_199.dat" u 4:6 w l title "gaussian"


