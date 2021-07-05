programa.exe:ej5.o funciones5.o
	gcc ej5.o funciones5.o -o programa.exe

ej5.o:ej5.c funciones5.h
	gcc -c ej5.c

funciones5.o:funciones5.c funciones5.h
	gcc -c funciones5.c

.PHONY: clean
clean:
	@rm *.o

