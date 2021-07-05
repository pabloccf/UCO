ej7.exe:ej7.o funciones7.o
	gcc ej7.o funciones7.o -o ej7.exe

ej7.o:ej7.c funciones7.h
	gcc -c ej7.c

funciones7.o:funciones7.c funciones7.h
	gcc -c funciones7.c

.PHONY:clean
clean:
	@rm *.o