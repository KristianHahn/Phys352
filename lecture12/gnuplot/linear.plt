L(x,a,b) = a*x + b  

A = 3.284170
B = 3.012162

plot "idata/linear.dat" using 1:2 title "data", L(x,A,B) with lines linecolor rgb "blue" title "LS fit"

