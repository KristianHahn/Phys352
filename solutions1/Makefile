SRC= $(shell ls *.c)
EXE= $(patsubst %.c,%.exe,$(SRC))

all : $(EXE)

%.exe : %.c	
	gcc -std=c99 $^ -o $@

clean : 
	rm -f *.exe
	rm -f *~
