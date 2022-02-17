set terminal qt 0 size 1000,500

datafile = "idata/exp.dat"
fitfile = "odata/exp_LLS_GSL.root.dat"
wfitfile = "odata/exp_LLS_GSL_weight.root.dat"

#datafile = "idata/expGSL.dat"
#fitfile = "odata/exp_LLS_GSL_weight.dat"

set multiplot layout 1,2

unset xrange
unset yrange

p datafile  u 2:4 w p pt 7 ps 0.25 title "data", fitfile u 2:10 w l lc  "red" title "fit", fitfile u 2:12 w l linestyle 3 linecolor "black" title "uncert", fitfile u 2:14 w l ls 3 linecolor "black" notitle

set xrange[0:10]
if (datafile eq "idata/expGSL.dat") set yrange[4:6]; else set yrange[10000:16000];


p datafile u 2:4 w p pt 7 ps 0.25 title "data", fitfile u 2:10 w l lc  "red" title "fit", fitfile u 2:12 w l linestyle 3 linecolor "black" title "uncert", fitfile u 2:14 w l ls 3 linecolor "black" notitle

unset multiplot 


set terminal qt 1 size 1000,500

set multiplot layout 1,2

unset xrange
unset yrange

p datafile u 2:4 w p pt 7 ps 0.25 title "data", wfitfile u 2:10 w l lc  "red" title "fit", wfitfile u 2:12 w l linestyle 3 linecolor "black" title "uncert", wfitfile u 2:14 w l ls 3 linecolor "black" notitle

set xrange[0:10]
if (datafile eq "idata/expGSL.dat") set yrange[4:6]; else set yrange[10000:16000];



p datafile u 2:4 w p pt 7 ps 0.25 title "data", wfitfile u 2:10 w l lc  "red" title "fit", wfitfile u 2:12 w l linestyle 3 linecolor "black" title "uncert", wfitfile u 2:14 w l ls 3 linecolor "black" notitle

unset multiplot 
