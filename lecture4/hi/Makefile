
SRC=$(shell echo *.c)
EXE=$(patsubst  %.c, %.exe, $(SRC)) 

all : main.exe

%.o : src/%.c	
	gcc -ansi -pedantic -I include -c $< -o $@

main.exe : main.o hello.o hi.o
	gcc -ansi -pedantic -I include $? -o $@

lib : hello.o hi.o
	ar -r lib/libgreetings.a $?

fromlib : lib
	gcc -ansi -pedantic -I include src/main.c  -o main.exe -Llib -lgreetings
clean : 
	rm -f *.exe *.o *~
	rm -f lib/*.a


