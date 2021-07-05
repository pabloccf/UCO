#ifndef FUNCIONES11_H
#define FUNCIONES11_H	
struct libro{
	char titulo[100];
	char autor[50];
	float precio;
	int unidades;
};
int existelibro(char* filename,char* titulo);
void introducirlibro(char* filename,struct libro nuevo_libro);
int cantidadlibros(char* filename);
void listarlibros(char* filename);
void venderlibros(char* filename,char* titulo,int n);
void borraragotados(char* filename);
#endif