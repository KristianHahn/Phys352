#!/bin/sh

# run with >alphanum.csv for output to gephi ...

dir=./characters

pats=(`ls $dir/*.dat`)
i=0;
endi=`echo "${#pats[*]}-1" | bc`;
endj=`echo "${#pats[*]}" | bc`;




echo "Source,Target,Hamming"
while (( $i <= $endi )); do
     j=`echo $i+1 | bc`;
     while (( $j < $endj )); do
 	dist=`./bin/main_hamming.exe ${pats[$i]} ${pats[$j]} | tail -1 | awk '{print $2}'`
 	node1=`echo ${pats[$i]} | sed -e 's,.*/,,; s,.dat,,'`
 	node2=`echo ${pats[$j]} | sed -e 's,.*/,,; s,.dat,,'`
 	echo "$node1,$node2,$dist"
 	(( j++ ));
     done 
     #echo "---------------"
     (( i++ ));
done



#create the nodes file ...
# echo "Id,Label" > nodes.csv
# while (( $i <= $endi )); do
#     node=`echo ${pats[$i]} | sed -e 's,.*/,,; s,.dat,,'`
#     echo "$node,$node" >> nodes.csv
#     (( i++ ));
# done;
