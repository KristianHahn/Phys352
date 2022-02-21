# 3 component BG 
#As      = 133.31455 +/- 17.42469
#mu      = 126.17796 +/- 0.23461
#sigma   = 1.63495 +/- 0.23840
#Ab      = 1742.18631 +/- 25430134573040428.00000
#tau     = -20.08283 +/- 0.16297
#x0      = 99.35632 +/- 293142638050701.50000

B(x) = Ab*exp((x-x0)/tau)
Ab      = 1742.18631
tau     = -20.08283 
x0      = 99.35632

S(x) = As*exp(-(x-mu)**2/(2*sigma**2))
As      = 133.31455
mu      = 126.17796
sigma   = 1.63495


SB(x) = B(x) + S(x)

set xrange[100:160]
set grid x y
set xlabel "m(gg)"
set ylabel "N"


plot  "data/higgs.dat" using ($1):2:3 with yerrorbars title "data", B(x) w l lc rgb "red" title "BG", SB(x) w l lc rgb "blue" title "SIG+BG"

set terminal pngcairo
set output 'img/mgg_sig_bg3comp.png'
replot 
