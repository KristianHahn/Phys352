#!/bin/sh

rm -f *.png 
gnuplot 2_species.plt 
gnuplot projectile.plt 
gnuplot drag.plt 
gnuplot sho.plt 
