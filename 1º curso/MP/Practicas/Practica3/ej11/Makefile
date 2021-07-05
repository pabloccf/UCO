ej11.exe:ej11.o funciones11.o
	gcc ej11.o funciones11.o -o ej11.exe

ej11.o:ej11.c funciones11.h
	gcc -c ej11.c

funciones11.o:funciones11.c funciones11.h
	gcc -c funciones11.c

.PHONY: clean
clean:
	@rm *.o