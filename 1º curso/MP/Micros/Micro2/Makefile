main.exe:main.o funciones.o
	gcc main.o funciones.o -o main.exe

main.o:main.c funciones.h
	gcc -c main.c

funciones.o:funciones.c funciones.h
	gcc -c funciones.c

.PHONY:saludo
saludo:
	@echo Ejecutando el Makefile de Pablo Lopez Gosalvez

.PHONY: saludarycompilar
saludarycompilar: saludo main.exe