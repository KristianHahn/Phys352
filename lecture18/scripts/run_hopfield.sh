frandomization=0.4
fdamage=0.3

testp="./characters/A.dat"
inputp=("./characters/A.dat" "./characters/B.dat" "./characters/C.dat")

#testp="./characters/B.dat"
#inputp=("./characters/A.dat" "./characters/B.dat" "./characters/C.dat")

#testp="./characters/C.dat"
#inputp=("./characters/A.dat" "./characters/B.dat" "./characters/C.dat")

./bin/main_hopfield.exe $RANDOM $frandomization $fdamage $testp ${inputp[*]} 
