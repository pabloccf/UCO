#ifndef FUNCIONES8_H
#define FUNCIONES8_H	
struct libro{
	char titulo[100];
	char autor[50];
	float precio;
	int unidades;
};
void limpiarlinea(char* cad);//Cambiar \n por \0
int existelibro(char* filename,char* titulo);//Devuelve la posicion en la que se encuentra el libro y devuelve -1 si no lo encuentra
void introducirlibro(char* filename,struct libro nuevo_libro);//Añade un nuevo libro al final del fichero 
int cantidadlibros(char* filename);//Nos dice cuantos libros hay en el fichero
void listarlibros(char* filename);//Imprime los libros que hay en el fichero (almacenandolos previamente en un vector dinamico)
void venderlibros(char* filename,char* titulo,int n_vendidos);//Actualiza elfichero quitandole unidades a un libro
void borraragotados(char* filename);//Elimina del fichero los libros agotados con 0 unidades
#endif