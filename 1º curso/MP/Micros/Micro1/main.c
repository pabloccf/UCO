/**
@file main.c
@author Pablo López
@date 13-04-2020
@brief Este archivo contiene el main
*/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**
@fn main()
@brief Esta función es el punto de entrada del programa
@return 0 si todo sale correctamente
*/

int main(){
	int nfil,ncol;
	printf("Introduzca la cantidad de filas y columnas:\n");
	scanf("%d%d",&nfil,&ncol);

	int** m=reservaMatriz(nfil,ncol);
	if(m!=NULL){
		rellenaMatriz(m,nfil,ncol);
		imprimeMatriz(m,nfil,ncol);

		int divisibles;
		int sumadiv;
		divideMatriz(m,nfil,ncol,&divisibles,&sumadiv);
		printf("Hay %d numeros divisibles entre 3\n",divisibles );
		printf("La suma de los numeros divisibles entre 3 es: %d\n",sumadiv );

		liberarmemoriaMatriz(&m,nfil);	
	}
	return 0;
}