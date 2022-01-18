

Ni=100
N(x) = Ni*exp(-x/tau)
tau=1
set xrange [1:5]
plot 'euler.dat' using 2:1, N(x) with lines 
