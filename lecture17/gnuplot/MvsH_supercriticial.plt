set term pngcairo

f(H,T) = tanh(H/T)

set xlabel "H"
set ylabel "M"
set xrange[-5:5]



set output "img/MvsH_supercritical_T200.png"
set yrange[-.1:.1]
plot "data/MvsH_supercritical_T200.dat" u 4:6 w p pt 7, f(x,200) title "tanh(H/T)"

set output "img/MvsH_supercritical_T100.png"
set yrange[-.1:.1]
plot "data/MvsH_supercritical_T100.dat" u 4:6 w p pt 7, f(x,100) title "tanh(H/T)"

set output "img/MvsH_supercritical_T30.png"
set yrange[-.5:.5]
plot "data/MvsH_supercritical_T30.dat" u 4:6 w p pt 7, f(x,30) title "tanh(H/T)"

set output "img/MvsH_supercritical_T10.png"
set yrange[-1:1]
plot "data/MvsH_supercritical_T10.dat" u 4:6 w p pt 7, f(x,10) title "tanh(H/T)"





