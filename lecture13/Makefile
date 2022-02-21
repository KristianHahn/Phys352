

all : lecture12 higgs
generator: bin/generator_exp.exe bin/generator_exp_GSL.exe 
lecture12: bin/main_fit_linear_LS.exe bin/main_fit_exp_LLS.exe bin/main_fit_exp_LLS_GSL.exe bin/main_fit_exp_NLLS_GSL.exe  
higgs:  bin/main_fit_higgs_BGonly_NLLS_GSL.exe bin/main_fit_higgs_SIG_BGfixed_NLLS_GSL.exe bin/main_fit_higgs_SIG_BG2comp_NLLS_GSL.exe bin/main_fit_higgs_SIG_BG3comp_NLLS_GSL.exe


bin/generator_exp.exe : src/generator_exp.cc 
	g++ -g -ansi  `root-config --cflags` $^ -o $@  `root-config --libs`

bin/generator_exp_GSL.exe : src/generator_exp_GSL.c 
	gcc -g -ansi -std=gnu99 -pedantic  $^ -o $@  -lgsl -lgslcblas -lm

bin/main_fit_exp_LLS.exe : src/main_fit_exp_LLS.c 
	gcc -g -ansi -std=gnu99 -pedantic  $^ -o $@   -lm

bin/main_fit_exp_LLS_GSL.exe : src/main_fit_exp_LLS_GSL.c 
	gcc -g -ansi -std=gnu99 -pedantic  $^ -o $@  -lgsl -lgslcblas -lm

bin/main_fit_exp_NLLS_GSL.exe : obj/exp_for_GSL.o obj/utils.o src/main_fit_exp_NLLS_GSL.c 
	gcc -g -ansi -std=gnu99 -pedantic  -Iinclude $^ -o $@  -lgsl -lgslcblas -lm

# higgs stuff 

#obj/higgs_BG_gsl.o 
bin/main_fit_higgs_BGonly_NLLS_GSL.exe : obj/utils.o src/main_fit_higgs_BGonly_NLLS_GSL.c 
	gcc -g -ansi -std=gnu99 -pedantic  -Iinclude $^ -o $@  -L./lib -lphysics -lgsl -lgslcblas -lm

#obj/higgs_SIG_BGfixed_gsl.o
bin/main_fit_higgs_SIG_BGfixed_NLLS_GSL.exe :  obj/utils.o src/main_fit_higgs_SIG_BGfixed_NLLS_GSL.c 
	gcc -g -ansi -std=gnu99 -pedantic  -Iinclude $^ -o $@  -L./lib -lphysics -lgsl -lgslcblas -lm

#obj/higgs_SIG_BG2comp_gsl.o
bin/main_fit_higgs_SIG_BG2comp_NLLS_GSL.exe :  obj/utils.o src/main_fit_higgs_SIG_BG2comp_NLLS_GSL.c 
	gcc -g -ansi -std=gnu99 -pedantic  -Iinclude $^ -o $@  -L./lib -lphysics -lgsl -lgslcblas -lm

#obj/higgs_SIG_BG3comp_gsl.o
bin/main_fit_higgs_SIG_BG3comp_NLLS_GSL.exe :  obj/utils.o src/main_fit_higgs_SIG_BG3comp_NLLS_GSL.c 
	gcc -g -ansi -std=gnu99 -pedantic  -Iinclude $^ -o $@  -L./lib -lphysics -lgsl -lgslcblas -lm


bin/main_%.exe : src/main_%.c 
	gcc -g -ansi -std=gnu99 -pedantic  $< -o $@   -lm

obj/%.o : src/%.c 
	gcc -g -ansi -std=gnu99 -pedantic -Iinclude -c $< -o $@ 

# don't include lib targets for lib distribution ...
#lib : ode physics
#ode :  
#	cd ode && make lib && cd - 
#physics : 
#	cd physics && make lib && cd - 

#bin/main_%.exe : lib src/main_%.c 
#	gcc -g -std=gnu99 -I include $(patsubst lib%,,$^) -o $@  -lm -lphysics -lgsl



clean : 
	rm -f *~
	rm -f obj/*.o 
	rm -f bin/*.exe 
	rm -f src/*.c~ src/*.cc~
	rm -f include/*.h~
	rm -f scripts/*.sh~
	rm -f gnuplot/*.plt~
	rm -f log/*.log~
	#rm -f data/*.dat
	rm -f img/*.png
	#make -C physics clean
	#make -C ode clean

.PHONY : clean 
#.PHONY : clean ode physics

