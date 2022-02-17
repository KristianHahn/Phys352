# plot the GSL generated exp data with errors from weights

p "idata/expGSL.dat" u 2:4:(1/sqrt($6)) w yerrorbars
