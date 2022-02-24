#!/bin/sh

if (( `hostname | grep -c quser` > 0 )); then
    module load root
fi;


files=$( ls ./data/circleTests_*.dat );
if [ -e tmp.dat ]; then rm tmp.dat; fi 
for f in $files; do
    png=`echo $f | sed -e "s,data,img,;s,.dat,.png,"`
    echo "v/F" > tmp.dat
    cat $f >> tmp.dat
    root -l -q -b root/hist.C\(\"tmp.dat\",\"$png\",1.650614\)
    rm tmp.dat
done 
