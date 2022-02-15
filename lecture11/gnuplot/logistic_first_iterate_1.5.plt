set terminal png

mu=1.5
unity(x) = x
f(x) = mu*x*(1-x)

set ylabel "x[n+1]"
set xlabel "x[n]"

set yrange [0:1]
set xrange [0:1]
set output "img/logistic_first_iterate_1.5.png"
plot unity(x) with l , f(x) with l, "data/logistic_1.5.dat"  u 6:8 lt rgb "red" w l

set yrange [0.25:0.45]
set xrange [0.2:0.5]
set output "img/logistic_first_iterate_1.5_zoom.png"
plot unity(x) with l , f(x) with l, "data/logistic_1.5.dat"  u 6:8 lt rgb "red" w l


