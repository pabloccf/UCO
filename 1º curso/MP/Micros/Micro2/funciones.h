#ifndef FUNCIONES_H
#define FUNCIONES_H
struct Alumno{
	char nombre[200];
	long dni;
	float notamedia;
};
void cleanlinea(char* cad);
struct Alumno* readstudents(char* filename,int* n);
void calculateavg(char* filename,struct Alumno* v,int n);
void fichero(char* filename,struct Alumno* v,int n);
#endif