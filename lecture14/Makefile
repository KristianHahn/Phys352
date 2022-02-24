

all : bin/circleInt.exe bin/avg_and_std.exe bin/combineData.exe


# add -DVERBOSE to plot a circle trial ...
bin/%.exe : src/%.c 
	gc -g -ansi -std=gnu99 -pedantic -Iinclude  $< -o  $@ -lm





clean : 
	rm -f *~
	rm -f bin/*.exe 
	rm -f src/*.c~ src/*.cc~
	rm -f include/*.h~
	rm -f scripts/*.sh~
	rm -f gnuplot/*.plt~
	rm -f log/*.log~
	rm -f slurm/*~
	#rm -f data/*.dat
	rm -f img/*.png
	#make -C physics clean
	#make -C ode clean

.PHONY : clean 
#.PHONY : clean ode physics

