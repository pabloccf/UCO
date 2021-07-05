#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones5.h"
char** split(char* cadena,int* n){
	//Copio la cadena a una variable para poder editarla sin destrozar la original
	char cad[200];
	strcpy(cad,cadena);
	//Reservo mi vector de cadenas
	char** vcad=(char**)calloc(strlen(cadena),sizeof(char*));
	if(vcad==NULL){
		printf("ERROR: No se pudo reservar memoria\n");
	}
	else{
		*n=0;
		char* aux;
		aux=strtok(cad," ");//Le paso una cadena y un espacio para saber donde cortar la cadena. Esta función corta la cadena
		while(aux!=NULL){
			vcad[*n]=(char*)calloc(strlen(aux)+1,sizeof(char));//Le suma 1 para el '\0'
			if(vcad[*n]==NULL){
				printf("ERROR: No se pudo reservar memoria\n");
				*n=0;
				return NULL;
			}
			strcpy(vcad[*n],aux);
			(*n)++;

			aux=strtok(NULL," ");//Pasandole NULL strtok sigue leyendo por donde iba anteriormente y si le paso la cadena empieza desde el princìpio de nuevo y por lo tanto estaria en un bucle infinito
		}
	}
	vcad=(char**)realloc(vcad,(*n)*sizeof(char*));
	if(vcad==NULL){
		printf("ERROR: No se pudo realocar la memoria\n");
		*n=0;
	}
	return vcad;
}
void media(char** vcad,int n,float* media,int* mayor,int* menor){
	*mayor=strlen(vcad[0]);
	*menor=strlen(vcad[0]);
	float sum=0;
	for (int i = 0; i < n; ++i)
	{
		int length=strlen(vcad[i]);
		sum+=length;
		if(length>*mayor){
			*mayor=length;
		}
		if(length<*menor){
			*menor=length;
		}
	}
	*media=sum/n;
}
struct Freq* medirFrecuencias(char** vcad,int n, int* nfreq){
	struct Freq* vfreq=(struct Freq*)calloc(n,sizeof(struct Freq));
	if(vfreq==NULL){
		printf("ERROR: No se pudo reservar memoria\n");
	}
	else{
		//Mirar la longitud de la palabra

		//Si en el vector de frq ya tengo esa longitud le sumo 1 a la frq

		//si no, añado una struct al vector con esa longitud y freq=1

		//Cuando compruebe todas las palabras, divido las frecuencias del vector entre n

		*nfreq=0;
		for (int i = 0; i < n; ++i)//Por cada palabra yo repito el proceso
		{
			int length=strlen(vcad[i]);
			//Busco la longitud en el vector
			int encontrado=0;
			for (int j = 0; j < *nfreq; ++j)
			{
				if(vfreq[j].longitud==length){
					encontrado=1;
					vfreq[j].frecuencia++;
					break;
				}
			}
			if(!encontrado){
				//Creo una nueva struct y la añado al vetor
				struct Freq aux;
				aux.longitud=length;
				aux.frecuencia=1;
				vfreq[*nfreq]=aux;
				(*nfreq)++;
			}
		}
		for (int i = 0; i < *nfreq; ++i)
		{
			vfreq[i].frecuencia=vfreq[i].frecuencia/n;
		}
	}
	vfreq=(struct Freq*)realloc(vfreq,(*nfreq)*sizeof(struct Freq));
	if(vfreq==NULL){
		printf("ERROR: No se pudo realocar la memoria\n");
		*nfreq=0;
	}
	return vfreq;
}