#!/bin/sh

q=1.0
OmegaD=2.0
F=0.2

./bin/main_ho_damped_driven.exe 0.15 $q $OmegaD $F  >& ./data/damped_${q}_driven_${OmegaD}_${F}.dat

