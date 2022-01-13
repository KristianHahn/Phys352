
SRC=$(shell echo *.c)
EXE=$(patsubst  %.c, %.exe, $(SRC)) 

%.exe : %.c	
	gcc -ansi -pedantic $< -o $@

hello : 
	$(MAKE) -C hello

all : $(EXE) hello

clean : 
	rm -f *.exe *~
	rm -f hello/*.exe hello/*.o



.PHONY : hello clean
