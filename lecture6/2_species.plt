Na(t,Nai,tau) = (Nai/2)*(exp(-2*t/tau)+1)
Nb(t,Nbi,tau) = (Nbi/2)*(1-exp(-2*t/tau))


set grid x y
set xlabel "t"

#set terminal x11 size 1000,1000
set terminal png size 1000,1000
set output "2_species.png"

set multiplot layout 2,1 

set ylabel "N"
set xrange[0:5]
set yrange[0:1000]
plot 'data/2_species.dat' using 3:1 title "A", 'data/2_species.dat' using 3:2 title "B", Na(x,1000,1) with lines title "Na(x,1000,1)", Nb(x,1000,1) with lines title "Nb(x,1000,1)"

set ylabel "relative error"
set xrange[0:5]
set yrange[0.20:-0.20]
plot 'data/2_species.dat' using ($3):((Na($3,1000,1)-$1)/Na($3,1000,1)) title "A", 'data/2_species.dat' using ($3):((Nb($3,1000,1)-$2)/Nb($3,1000,1)) title "B" 

unset multiplot


