# Makefile

# Compile the program
program: mycomp.o complex.o
	gcc -Wall -ansi -pedantic mycomp.o complex.o -o program

# Compile mycomp.c
mycomp.o: mycomp.c
	gcc -Wall -ansi -pedantic mycomp.c

# Compile complex.c
complex.o: complex.c complex.h
	gcc -Wall -ansi -pedantic -c complex.c
