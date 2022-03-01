set terminal x11 size 600,600

set yrange[-1:201]
set xrange[-1:201]
set autoscale
set isosam 202,202
set key under Left reverse
#set xtics 1
#set ytics 1
#set grid xtics
#set grid ytics

set terminal png
set output "img/test.png"


dy(y,z) = (z>0?-0.5:0.5)

 plot "data/lattice.dat" using ($4):($6+dy($6,$8)):(0):($8>0?$8/2:1/0) w vec lt 3, "data/lattice.dat" using ($4):($6+dy($6,$8)):(0):($8<0?$8/2:1/0) w vec lt 1


