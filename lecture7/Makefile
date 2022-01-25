all :  bin/polymorphic.exe bin/main_sho.exe bin/main_sho_NL.exe bin/main_ho_damped.exe bin/main_ho_damped_driven.exe
#bin/compiler_error.exe 

# don't include lib targets for lib distribution ...
#ode :  ode
#	cd ode && make lib && cd - 
#physics : 
#	cd physics && make lib && cd - 
#main_%.exe : src/main_%.c ode physics 

bin/main_%.exe : src/main_%.c 
	gcc -g -ansi -pedantic -Icommon/include -Iphysics/include -I ode/include $< -o $@ -Lode/lib -Lphysics/lib -lm -lphysics -lODE

bin/polymorphic.exe : src/polymorphic.c
	gcc -g -std=c99 -pedantic -Iinclude  $< -o $@
/bincompiler_error.exe : src/compiler_error.c
	gcc -g -std=c99 -pedantic -Iinclude  $< -o $@


clean : 
	rm -f *~
	rm -f bin/*.exe 
	rm -f src/*.c~
	make -C physics clean
	make -C ode clean

.PHONY :  clean

