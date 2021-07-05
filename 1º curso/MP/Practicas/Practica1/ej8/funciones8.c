/**
 @file funciones8.c
 @author Pablo López
 @brief Este fichero contiene las definiciones de las funciones
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones8.h"
void estadisticasCadena(char* cadena,int* digitos,int* mayus,int* minus,int* espacios){
	*digitos=0;
	*mayus=0;
	*minus=0;
	*espacios=0;
	for(int i=0;cadena[i]!='\0';i++){
		if(isdigit(cadena[i])){
			(*digitos)++;
		}
		if(isupper(cadena[i])){
			(*mayus)++;
		}
		if(islower(cadena[i])){
			(*minus)++;
		}
		if(isspace(cadena[i])){
			(*espacios)++;
		}
	}
}