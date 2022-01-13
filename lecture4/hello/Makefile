
SRC=$(shell echo *.c)
EXE=$(patsubst  %.c, %.exe, $(SRC)) 

all : main.exe

%.o : src/%.c	
	gcc -ansi -pedantic -I include -c $< -o $@

main.exe : main.o hello.o
	gcc -ansi -pedantic -I include $? -o $@

clean : 
	rm -f *.exe *.o *~
