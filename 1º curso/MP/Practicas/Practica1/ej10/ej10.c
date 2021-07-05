/**
@file ej10.c
@author Pablo López
@date 12-04-2020
@brief Este fichero contiene el main
*/

#include <stdio.h>
#include <stdlib.h>
#include "funciones10.h"

/**
@fn main()
@return 0 si todo va bien
@brief Este es el punto de entrada del programa
*/

int main(){
	int n;
	double v[100];
	printf("Introduzca la cantidad de elementos: ");
	scanf("%d",&n);

	leeVector(v,n);
	escribeVector(v,n);
	printf("La suma es: %lf\n",sumaPositivos(v,n));
	return 0;
}