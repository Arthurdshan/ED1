all:
	gcc -Wall -c main.c
	gcc -Wall -c radix_sort.c
	gcc -Wall -c vector.c
	gcc -Wall -o main main.o vector.o radix_sort.o
	./main
	del *.o
	del main.exe