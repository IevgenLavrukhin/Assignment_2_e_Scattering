# This Makefile creates an executable "run" file from "closest_star.c" file.


all: compile link clean

compile: 
	gcc -Wall -std=c99 -lm scattering.c -o scattering.o -c
	gcc -Wall -std=c99 -lm func.c -o func.o -c
link:
	gcc -Wall -std=c99 -lm  func.o scattering.o -o run

clean:
	rm -f *.o
