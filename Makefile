apc: main.o input.o addition.o subtraction.o multiplication.o division.o
	gcc main.o input.o addition.o subtraction.o multiplication.o division.o -o apc

main.o: main.c apc.h
	gcc -c main.c

input.o: input.c apc.h
	gcc -c input.c

addition.o: addition.c apc.h
	gcc -c addition.c

subtraction.o: subtraction.c apc.h
	gcc -c subtraction.c

multiplication.o: multiplication.c apc.h
	gcc -c multiplication.c

division.o: division.c apc.h
	gcc -c division.c

clean:
	rm -f *.o apc