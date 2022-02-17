# NLLS 

set term pngcairo
set output "img/exp_NLLS_GSL.png"

f(x,A,lambda,b) = A*exp(-lambda*x) + b

# without weights
nowgt_A      = 4.98204
nowgt_lambda = 1.60298
nowgt_b      = 1.07418


# with weights
wgt_A      = 4.79653
wgt_lambda = 1.43937
wgt_b      = 1.00368



plot "odata/exp_NLLS_GSL.dat" using 1:2:3 title "data" w yerrorbars, f(x,nowgt_A,nowgt_lambda,nowgt_b) with lines linecolor rgb "blue" title "GSL-LS (no weights)", f(x,wgt_A,wgt_lambda,wgt_b) with lines linecolor rgb "red" title "GSL-LS (weighted)"


