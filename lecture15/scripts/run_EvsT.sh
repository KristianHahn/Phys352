#!/bin/sh


# fine-grained for a nice M vs T plot
rm data/EvsT.dat
i=0.4;
while (( `echo "$i < 5.0" | bc -l` )); do
    echo "i: $i"
    ./bin/main_E_vs_T.exe $RANDOM $i 0 | grep "T:" >> data/EvsT.dat
    i=`echo "$i + 0.01" | bc -l`
done;




