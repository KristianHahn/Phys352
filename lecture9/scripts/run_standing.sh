#!/bin/sh

# run as ...
# ./scripts/run_standing.sh 200 0.5
# ./scripts/run_standing.sh 200 1.0
# ./scripts/run_standing.sh 200 2.0
# ./scripts/run_standing.sh 200 4.0
# ./scripts/run_standing.sh 200 8.0


# number of time samples (eg: of .dat files)
n=$1

# change k ...
k=$2

echo "running : main_wave_standing.exe $k"
./bin/main_wave_standing.exe $k

echo "gnuplotting ..."
i=0;
while (( $i < $n )); do
    (( l = $i + 1 ))
    sed -e "s,XXX,$i,g;s,YYY,$k,g;s,ZZZ,$l,g" gnuplot/standing_template.plt > standing.plt
    gnuplot standing.plt
    (( i++ ))
done;

echo "animating ..."
rm data/standing_t_*.dat
convert -delay 5 $(ls img/standing_*.png | sort -t'_' -k3 -n) -loop 0 img/standing_k_${k}.gif
rm img/standing_t_*.png
rm standing.plt
