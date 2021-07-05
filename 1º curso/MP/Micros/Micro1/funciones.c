/**
@file funciones.c
@author Pablo López
@date 13-04-2020
@brief Este archivo contiene las definiciones de las funciones
*/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int** reservaMatriz(int nfil,int ncol){
	int** m=(int**)calloc(nfil,sizeof(int*));
	if(m!=NULL){
		for (int i = 0; i < nfil; ++i)
		{
			m[i]=(int*)calloc(ncol,sizeof(int));
			if(m[i]==NULL){
				printf("ERROR: No se pudo reservar memoria\n");
				free(m);
				return NULL;
			}
		}
	}
	else{
		printf("ERROR: No se pudo reservar memoria\n");
	}
	return m;
}
void rellenaMatriz(int** matriz,int nfil,int ncol){
	for (int i = 0; i < nfil; ++i)
	{
		for (int j = 0; j < ncol; ++j)
		{
			printf("Introduzca el elemento %d %d: ",i,j);
			scanf("%d",&(matriz[i][j]));
		}
	}
}
void imprimeMatriz(int** matriz,int nfil,int ncol){
	for (int i = 0; i < nfil; ++i)
	{
		for (int j = 0; j < ncol; ++j)
		{
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
}
void divideMatriz(int** matriz,int nfil,int ncol,int* divisible,int* suma){
	*divisible=0;
	*suma=0;
	for (int i = 0; i < nfil; ++i)
	{
		for (int j = 0; j < ncol; ++j)
		{
			if(matriz[i][j]%3==0){
				(*divisible)++;
				*suma+=matriz[i][j];
			}
		}
	}
}
void liberarmemoriaMatriz(int*** matriz,int nfil){
	for (int i = 0; i < nfil; ++i)
	{
		free((*matriz)[i]);
	}
	free(*matriz);
	*matriz=NULL;
}
