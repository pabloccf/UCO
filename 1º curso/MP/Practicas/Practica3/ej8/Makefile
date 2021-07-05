ej8.exe:ej8.o funciones8.o
	gcc ej8.o funciones8.o -o ej8.exe

ej8.o:ej8.c funciones8.h
	gcc -c ej8.c

funciones8.o:funciones8.c funciones8.h
	gcc -c funciones8.c

.PHONY: clean
clean:
	@rm *.o
