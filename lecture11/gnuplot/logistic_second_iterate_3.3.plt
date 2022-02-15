set terminal pngcairo

mu=3.3
unity(x) = x
f(x) = mu*x*(1-x)

set ylabel "x[n+2]"
set xlabel "x[n]"


set yrange [0:1]
set xrange [0:1]
set output "img/logistic_second_iterate_3.3.png"
plot unity(x) with l , f(f(x)) with l




