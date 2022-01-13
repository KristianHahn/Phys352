set terminal 'png'
set output 'temps.png'
plot '../data/chicago_temps_2012_daynum.dat' using 1:3 title 'AvgF' with lines,  '../data/chicago_temps_2012_daynum.dat' using 1:2 title 'HighF' with lines,  '../data/chicago_temps_2012_daynum.dat' using 1:4 title 'LoF' with lines
