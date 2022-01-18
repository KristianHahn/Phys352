#!/bin/sh

gcc -g -ansi -pedantic -Iinclude -c src/euler.c -o obj/euler.o
gcc -g -ansi -pedantic -Iinclude src/main.c obj/euler.o -o main.exe
gcc -ansi -pedantic  src/function_pointer.c -o fp.exe
