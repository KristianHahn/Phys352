#!/bin/sh

#generate the wave data
./bin/main_wave_pulse.exe 


# number of time samples (eg: of .dat files)
n=200

echo "gnuplotting ..."
i=0;
while (( $i < $n )); do
    (( l = $i + 1 ))
    sed -e "s,XXX,$i,g;" ./gnuplot/pulse_template.plt > pulse.plt
    gnuplot pulse.plt
    (( i++ ))
done;

echo "animating ..."
rm data/wavedata_pulse_t_*.dat
convert -delay 10 $(ls img/pulse_*.png | sort -t'_' -k3 -n) -loop 0 img/pulse.gif
rm img/pulse_t_*.png
rm pulse.plt
