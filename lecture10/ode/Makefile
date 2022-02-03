# no Makefile for lib distribution, commenting everything out ...

all : lib
lib : lib/libODE.a

obj/%.o : src/%.c
	gcc -g -ansi -pedantic -std=gnu99 -Iinclude -I../common/include -c $< -o $@

lib/libODE.a : obj/euler.o obj/rkO2.o obj/rkO4.o
	ar -r lib/libODE.a $^

clean : 
	rm -f src/*.c~
	rm -f include/*.h~
	rm -f obj/*.o
	rm lib/*.a 

.PHONY : clean 
