#set terminal x11 size 1500,1000
set terminal png size 1500,1000
set output "projectile.png"

set xrange [0:60000]
set yrange [0:20000]

set title "Shell Trajectory [vi = 700 m/s]"
set xlabel "x(m)"
set ylabel "y(m)"

y(x,alpha,vi) = x*tan(alpha) -g*(x/(vi*cos(alpha)))*(x/(vi*cos(alpha)))/2
g=9.8
vi=700

alpha30=3.1415*(30./180) 
alpha35=3.1415*(35./180) 
alpha40=3.1415*(40./180) 
alpha45=3.1415*(45./180) 
alpha50=3.1415*(50./180) 
alpha55=3.1415*(55./180) 

# no drag
plot "data/projectile_30.dat" using 4:6, "data/projectile_35.dat" using 4:6, "data/projectile_40.dat" using 4:6, "data/projectile_45.dat" using 4:6, "data/projectile_50.dat" using 4:6, "data/projectile_55.dat" using 4:6, y(x,alpha30,vi) title "analytic, 30deg", y(x,alpha35,vi) title "analytic, 35deg", y(x,alpha40,vi) title "analytic, 40deg", y(x,alpha45,vi) title "analytic, 45deg", y(x,alpha50,vi) title "analytic, 50deg", y(x,alpha55,vi) title "analytic, 55deg"

# data with simple drag
#plot "data/drag_30.dat" using 4:6, "data/drag_35.dat" using 4:6, "data/drag_40.dat" using 4:6, "data/drag_45.dat" using 4:6, "data/drag_50.dat" using 4:6, "data/drag_55.dat" using 4:6, y(x,alpha30,vi) title "analytic, 30deg", y(x,alpha35,vi) title "analytic, 35deg", y(x,alpha40,vi) title "analytic, 40deg", y(x,alpha45,vi) title "analytic, 45deg", y(x,alpha50,vi) title "analytic, 50deg", y(x,alpha55,vi) title "analytic, 55deg"
