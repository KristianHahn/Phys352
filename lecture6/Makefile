all : main_2species.exe  main_projectile.exe main_drag.exe main_sho.exe

obj/euler.o : src/euler.c
	gcc -g -ansi -pedantic -Iinclude -c $< -o $@

obj/decay.o : src/decay.c
	gcc -g -ansi -pedantic -Iinclude -c $< -o $@
obj/projectiles.o : src/projectiles.c
	gcc -g -ansi -pedantic -Iinclude -c $< -o $@
obj/sho.o : src/sho.c
	gcc -g -ansi -pedantic -Iinclude -c $< -o $@

lib : lib/libphysics.a

#lib/libphysics.a : obj/decay.o obj/projectiles.o obj/sho.o
#	ar -r lib/libphysics.a $^

main_2species.exe : src/main_2species.c obj/euler.o lib
	gcc -g -ansi -pedantic -Iinclude -Llib $(patsubst lib%,,$^)  -o $@ -lm -lphysics

main_projectile.exe : src/main_projectile.c obj/euler.o lib
	gcc -g -ansi -pedantic -Iinclude -Llib $(patsubst lib%,,$^) -o $@ -lm -lphysics

main_drag.exe : src/main_drag.c obj/euler.o lib
	gcc -g -ansi -pedantic -Iinclude -Llib $(patsubst lib%,,$^) -o $@ -lm -lphysics

main_sho.exe : src/main_sho.c obj/euler.o lib
	gcc -g -ansi -pedantic -Iinclude -Llib $(patsubst lib%,,$^) -o $@ -lm -lphysics


clean : 
	rm -f *.exe *~
	rm -f src/*.c~
	rm -f include/*.h~
	rm -f obj/*.o
	# rm lib/*.a 

.PHONY : clean 
# lib
