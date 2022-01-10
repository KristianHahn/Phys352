
SRC=$(shell echo *.c)
EXE=$(patsubst  %.c, %.exe, $(SRC)) 

all : $(EXE)
clean : 
	rm *.exe *~

%.exe : %.c	
	gcc -ansi -pedantic $< -o $@
