all :  bin/main_HO_realistic.exe bin/main_poincare.exe bin/main_bifurcation.exe

bin/main_%.exe : src/main_%.c 
	gcc -g -ansi -std=gnu99 -pedantic -Icommon/include -Iphysics/include -I ode/include $< -o $@ -Lode/lib -Lphysics/lib -lm -lphysics -lODE

# don't include lib targets for lib distribution ...
#lib : ode physics
#ode :  
#	cd ode && make lib && cd - 
#physics : 
#	cd physics && make lib && cd - 

#bin/main_%.exe : lib src/main_%.c 
#	gcc -g -ansi -std=gnu99 -pedantic -Icommon/include -Iphysics/include -I ode/include $(patsubst lib%,,$^) -o $@ -Lode/lib -Lphysics/lib -lm -lphysics -lODE



clean : 
	rm -f *~
	rm -f bin/*.exe 
	rm -f src/*.c~
	rm -f data/*.dat
	rm -f img/*.png
	#make -C physics clean
	#make -C ode clean

.PHONY : clean 
#.PHONY : clean ode physics

