#!/bin/sh

for f in  ./slurm/output/circle_*.dat; do 
    Ntot=`grep Npts $f | awk '{print $4}';` 
    Nin=`grep Ninside $f | awk '{print $4}';` 
    echo "Ntot: $Ntot Nin: $Nin"
done > ./data/comboData.dat
