E(x,B_0,B_1) = B_0*exp(B_1*x)

# these parameters are from the naive linearized LS best fit
# they are expected to not fit well at large y : 
# see http://mathworld.wolfram.com/LeastSquaresFittingExponential.html

set term pngcairo
set output "img/exp_LLS.png"


# for the root generated exp data and LLS fit 
B_1 = -0.050711
B_0 =  15282.324387
#set xrange[0:10]
#set yrange[10000:16000]
plot "idata/exp.dat" using 2:4 title "data" w p pt 7 ps 0.25 , E(x,B_0,B_1) with lines linecolor rgb "blue" title "LS fit"

# for the GSL generated exp data and LLS fit 
#B_1 = -0.050121
#B_0 = 5.014911
#plot "idata/expGSL.dat" using 2:4 title "data" w p pt 7 ps 0.25 , E(x,B_0,B_1) with lines linecolor rgb "blue" title "LS fit"


