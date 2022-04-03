main: main.o operation.o file.o func.o
	gcc -o main main.o operation.o file.o func.o

main.o operation.o file.o func.o: main.c class/operation/operation.c utils/file/file.c utils/func/func.c
	gcc -c main.c class/operation/operation.c utils/file/file.c utils/func/func.c
