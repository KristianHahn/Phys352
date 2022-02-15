set terminal pngcairo

set  xrange[0:2]

set title ""
set xlabel "frequency (Hz)"
set ylabel "FFT amplitude"

set output "img/fft_FD0.5.png"
p "data/fft_FD0.5.dat" u 2:4 w l

set output "img/fft_FD0.95.png"
p "data/fft_FD0.95.dat" u 2:4 w l

set output "img/fft_FD1.2.png"
p "data/fft_FD1.2.dat" u 2:4 w l

set output "img/fft_FD1.44.png"
p "data/fft_FD1.44.dat" u 2:4 w l

set output "img/fft_FD1.47.png"
p "data/fft_FD1.47.dat" u 2:4 w l


