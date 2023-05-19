# Makefile

# Compile the program
prog: mycomp.o complex.o
	gcc -Wall -pedantic mycomp.o complex.o -o prog

# Compile mycomp.c
mycomp.o: mycomp.c complex.h mycomp.h
	gcc -Wall -pedantic mycomp.c

# Compile complex.c
complex.o: complex.c complex.h
	gcc -Wall -pedantic -c complex.c -lm
