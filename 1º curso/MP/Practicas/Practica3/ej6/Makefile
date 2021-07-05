ej6.exe:ej6.o funciones6.o
	gcc ej6.o funciones6.o -o ej6.exe

ej6.o:ej6.c funciones6.h
	gcc -c ej6.c

funciones6.o:funciones6.c funciones6.h
	gcc -c funciones6.c

.PHONY:clean
clean:
	@rm *.o