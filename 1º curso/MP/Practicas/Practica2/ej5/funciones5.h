#ifndef FUNCIONES5_H
#define FUNCIONES5_H
struct Freq{
	int longitud;
	float frecuencia;
};
char** split(char* cadena,int* n);//Coge la frase y forma un vector de cadenas donde cada elemento es una palabra de la frase
void media(char** vcad,int n,float* media,int* mayor,int* menor);
struct Freq* medirFrecuencias(char** vcad,int n, int* nfreq);
#endif