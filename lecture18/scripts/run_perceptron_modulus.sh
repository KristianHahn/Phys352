
value=$1

frandomization=0.0
fdamage=0.0
testp="./characters/${value}.dat"

./bin/main_perceptron.exe $RANDOM $frandomization $fdamage $testp
