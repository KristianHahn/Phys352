#!/bin/sh

# be sure to compile with -DVERBOSE (and then to remove and recompile!!!)
./bin/circleInt.exe 5000 $RANDOM >& ./data/circle.dat
