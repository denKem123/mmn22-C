# Makefile

# Compile the program
prog: mycomp.o complex.o
	gcc -Wall -ansi -pedantic mycomp.o complex.o -o prog

# Compile mycomp.c
mycomp.o: mycomp.c complex.h mycomp.h
	gcc -Wall -ansi -pedantic -c mycomp.c

# Compile complex.c
complex.o: complex.c complex.h
	gcc -Wall -ansi -pedantic -c complex.c
