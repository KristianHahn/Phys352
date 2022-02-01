set terminal png size 1000,1000
set output "img/standing_t_XXX.png"

set multiplot layout 2,1

set yrange[-2.5:2.5]
set xrange[0:1]
set arrow from 0.3, graph 0 to 0.3, graph 1 nohead
plot 'data/standing_t_XXX.dat' using 4:6 w l

# 200*(dt=0.000033) = 0.0066
set xrange[0:0.0066]
plot 'data/timeseries_at_x_0.3_k_YYY.dat' every ::1::ZZZ using 2:6 w l 

unset multiplot
