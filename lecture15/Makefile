
#bin/main_fit_beta_LLS_GSL.exe
all : bin/test.exe bin/main_M_vs_time.exe bin/main_M_vs_T.exe  bin/main_E_vs_T.exe bin/main_specific_heat.exe 

bin/%GSL.exe : src/%GSL.c 
	gcc -g -ansi -std=gnu99 -pedantic -Iinclude $< -o  $@ -lm -lgsl -lgslcblas

# add -DTIMESERIES for snaphosts of lattice magnetization
bin/%.exe : src/%.c 
	gcc -DTIMESERIES -g -ansi -std=gnu99 -pedantic -Iinclude -IIsing/include  -IIsingPhysics/include $< -o  $@ -lm -LIsing/lib -lIsing -LIsingPhysics/lib -lIsingPhysics


boltzmann : 
	g++ `root-config --cflags` src/main_boltzmann.cc `root-config --libs` -o bin/main_boltzmann.exe


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

