#!/bin/sh

gcc -g -ansi -pedantic -Iinclude -c src/euler.c -o obj/euler.o
gcc -g -ansi -pedantic -Iinclude -Llib src/main_2species.c obj/euler.o  -o main_2species.exe -lm -lphysics
gcc -g -ansi -pedantic -Iinclude -Llib src/main_projectile.c obj/euler.o -o main_projectile.exe -lm -lphysics
gcc -g -ansi -pedantic -Iinclude -Llib src/main_drag.c obj/euler.o -o main_drag.exe -lm -lphysics
gcc -g -ansi -pedantic -Iinclude -Llib src/main_sho.c obj/euler.o -o main_sho.exe -lm -lphysics
