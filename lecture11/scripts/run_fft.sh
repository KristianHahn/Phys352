#!/bin/sh

# for harmonics
./bin/main_fft.exe ./data/realistic_FD0.5.dat  > data/fft_FD0.5.dat
./bin/main_fft.exe ./data/realistic_FD0.95.dat  > data/fft_FD0.95.dat
./bin/main_fft.exe ./data/realistic_FD1.2.dat  > data/fft_FD1.2.dat
./bin/main_fft.exe ./data/realistic_FD1.44.dat  > data/fft_FD1.44.dat
./bin/main_fft.exe ./data/realistic_FD1.47.dat  > data/fft_FD1.47.dat


