N(x,Ni,tau) = Ni*exp(-x/tau)

set xrange[0:2]
set grid x y
set xlabel "t"
set ylabel "N"


plot N(x,1000,1) with lines linecolor rgb "blue" title "Ni=1000, tau=1", \
	 N(x,3000,2) with lines linecolor rgb "red" title "Ni=3000, tau=2", \
	 N(x,5000,0.1) with lines linecolor rgb "violet" title "Ni=5000, tau=0.1"
