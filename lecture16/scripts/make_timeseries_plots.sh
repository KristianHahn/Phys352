#!/bin/sh

idir=$1
odir=$2 
mfile="'$idir/MvsTime.dat'"

for f in $idir/sweep_*.dat; do 
    datpath="'$f'" 

    png=`echo $f  | sed -e 's,.*/,,; s,.dat,.png,'`
    pngpath="'$odir/$png'"

    endsweep=`echo $f | sed -e 's,.*/sweep_,,; s,.dar,,'`
    endsweep="'$endsweep'"


    gnuplot  -e "ifile=$datpath;ofile=$pngpath;mfile=$mfile;endsweep=$endsweep" gnuplot/lattice.plt

done 

convert -delay 5 $(ls -1 $odir/*.png | sort -t'_' -k2 -n) -loop 0 $odir/timeseries.gif
rm $odir/*.png
