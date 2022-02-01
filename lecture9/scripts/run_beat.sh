#!/bin/sh

#generate the wave data
./bin/main_wave_beat.exe 4 4.4


# number of time samples (eg: of .dat files)
n=200

echo "gnuplotting ..."
i=0;
while (( $i < $n )); do
    (( l = $i + 1 ))
    sed -e "s,XXX,$i,g;s,YYY,$k,g;s,ZZZ,$l,g" gnuplot/beat_template.plt > beat.plt
    gnuplot beat.plt
    (( i++ ))
done;

echo "animating ..."
rm data/wavedata_beat_t_*.dat
convert -delay 5 $(ls img/beat_*.png | sort -t'_' -k3 -n) -loop 0 img/beat.gif
rm img/beat_t_*.png
rm beat.plt
