#!/bin/sh

# wave data generated with run_beat.sh

# run the ffts
./bin/main_fft_beat.exe 1 > ./data/fft_beat_k1.dat
./bin/main_fft_beat.exe 2 > ./data/fft_beat_k2.dat
# plot the output with beat_k1k2.plt ...

./bin/main_fft_beat.exe 3 > ./data/fft_beat_sum.dat
# plot the output with beat_sum.plt ...
