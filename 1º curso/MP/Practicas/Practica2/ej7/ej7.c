/**
@file ej7.c
@author Pablo López
@date 12-04-2020
@brief Este archivo contiene el main
*/

#include <stdio.h>
#include <stdlib.h>
#include "funciones7.h"
#include "libMatrices.h"

/**
@fn main()
@brief Función main

Este es el punto de entrada del programa
*/

int main(){
	int nfil1,ncol1;
	printf("Introduzca el tamaño de la primera matriz:\n");
	scanf("%d%d",&nfil1,&ncol1);
	int** matriz1=reservarMemoria(nfil1,ncol1);

	int nfil2,ncol2;
	printf("Introduzca el tamaño de la segunda matriz:\n");
	scanf("%d%d",&nfil2,&ncol2);
	int** matriz2=reservarMemoria(nfil2,ncol2);
	printf("\n");

	rellenaMatriz(matriz1,nfil1,ncol1);
	rellenaMatriz(matriz2,nfil2,ncol2);

	imprimeMatriz(matriz1,nfil1,ncol1);
	printf("\n\n");
	imprimeMatriz(matriz2,nfil2,ncol2);
	printf("\n\n");

	int nfilres,ncolres;
	int** resultado=multiplicacionMatrices(matriz1,nfil1,ncol1,matriz2,nfil2,ncol2,&nfilres,&ncolres);
	if(resultado==NULL){
		printf("ERROR: No se pudo multiplicar\n");
	}
	else{
		imprimeMatriz(resultado,nfilres,ncolres);
	}

	liberarMemoria(&matriz1,nfil1);
	liberarMemoria(&matriz2,nfil2);
	liberarMemoria(&resultado,nfilres);

	return 0;
}