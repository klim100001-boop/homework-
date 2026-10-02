all: third_program.o min_func.o
	gcc third_program.o min_func.o && del *.o

third_program.o: third_program.c
	gcc -c third_program.c

min_func.o: min_func.c
	gcc -c min_func.c