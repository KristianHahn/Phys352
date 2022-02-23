gauss(x,A,mean,sigma) = A*exp(-((x-mean)**2)/(2*(sigma**2)))

# extract sigma population with 10000x10000 trials
Nsamples_1 = 10000
s_1 = sqrt(0.0002703531)
Agauss_1 = sqrt(pi/(2*s_1**2))
A_1 = Nsamples_1/Agauss_1

sigma_pop = 1.632826

# test extimated sigma population with 20000x20000 trials
Nsamples_2 = 20000
s_2 = sigma_pop/sqrt(Nsamples_2)
s_2_calc = sqrt(0.0001362195)
Agauss_2 = sqrt(pi/(2*s_2**2))
A_2 = Nsamples_2/Agauss_2


# test extimated sigma population with 5000x5000 trials
Nsamples_3 = 5000
s_3 = sigma_pop/sqrt(Nsamples_3)
Agauss_3 = sqrt(pi/(2*s_3**2))
A_3 = Nsamples_3/Agauss_3

# test extimated sigma population with 40000x40000 trials
Nsamples_4 = 40000
s_4 = sigma_pop/sqrt(Nsamples_4)
s_4_sample = sqrt(0.0000679724)
Agauss_4 = sqrt(pi/(2*s_4_sample**2))
A_4 = Nsamples_4/Agauss_4



reset
n=501 #number of intervals
#max=3.205 #max value
#min=3.05 #min value

max=0.1 #max value
min=-0.1 #min value


width=(max-min)/n #interval width
#function used to map a value to the intervals
hist(x,width)=width*floor(x/width)+width/2.0

#set term png #output terminal and file
#set output "histogram.png"
set xrange [min:max]
set yrange [0:]

#to put an empty boundary around the
#data inside an autoscaled graph.
set offset graph 0.05,0.05,0.05,0.0
set xtics min,(max-min)/5,max
set boxwidth width*0.9
set style fill solid 0.5 #fillstyle
set tics out nomirror
set xlabel "x"
set ylabel "Frequency"

#count and plot

set term x11 0 
plot "data/circleTests_10000.dat" u (hist($1-pi,width)):(1.0) smooth freq w boxes lc rgb "green" notitle, gauss(x,A_1,0,s_1)
set term x11 1 
plot "data/circleTests_20000.dat" u (hist($1-pi,width)):(1.0) smooth freq w boxes lc rgb "green" notitle, gauss(x,A_2,0,s_2)
set term x11 2
plot "data/circleTests_5000.dat" u (hist($1-pi,width)):(1.0) smooth freq w boxes lc rgb "green" notitle, gauss(x,A_3,0,s_3)
set term x11 3
plot "data/circleTests_40000.dat" u (hist($1-pi,width)):(1.0) smooth freq w boxes lc rgb "green" notitle, gauss(x,A_4,0,s_4_sample)
