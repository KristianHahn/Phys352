all : main.exe fp.exe

main.exe : src/main.c obj/euler.o
	gcc -g -ansi -pedantic -Iinclude $? -o $@

obj/euler.o : src/euler.c
	gcc -g -ansi -pedantic -Iinclude -c $< -o $@

fp.exe : src/function_pointer.c
	gcc -ansi -pedantic  $< -o $@


clean : 
	rm -f *.exe *~
	rm -f obj/*.o



.PHONY : clean 
