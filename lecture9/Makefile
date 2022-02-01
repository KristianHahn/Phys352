
all : bin/main_puresine.exe bin/main_wave_standing.exe bin/main_fft_standing.exe bin/main_wave_beat.exe bin/main_fft_beat.exe bin/main_wave_pulse.exe bin/main_fft_pulse.exe

lib : lib/libwave.a


bin/main_wave_%.exe : src/main_wave_%.c 
	gcc -g -std=gnu11 -pedantic -Iinclude $< -o $@ -Llib -lwave -lm -lfftw3

bin/main_fft_%.exe : src/main_fft_%.c 
	gcc -g -std=gnu11 -pedantic -Iinclude $< -o $@ -Llib -lwave -lm -lfftw3

bin/main_%.exe : src/main_%.c 
	gcc -g -std=gnu11 -pedantic -Iinclude $< -o $@ -lm -lfftw3

lib/libwave.a : obj/wave.o
	ar r lib/libwave.a $< 

obj/%.o : src/%.c 
	gcc -g -std=gnu11 -pedantic -Iinclude -c $< -o $@


clean : 
	rm -f *~
	rm -f bin/*.exe 
	rm -f src/*.c~
	rm -f include/*.h~
	#rm lib/*.a

.PHONY :  clean

