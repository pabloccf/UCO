#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones6.h"
int** reservarMemoria(int nfil,int ncol){
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
	srand(time(NULL));//Inicializo el generador de numeros aleatorios
	for (int i = 0; i < nfil; ++i)
	{
		for (int j = 0; j < ncol; ++j)
		{
			matriz[i][j]=(rand()%20)+1;
		}
	}
}
void imprimeMatriz(int** matriz,int nfil,int ncol){
	for (int i = 0; i < nfil; ++i)
	{
		for (int j = 0; j < ncol; ++j)
		{
			printf("%d ", *(*(matriz+i)+j));
		}
		printf("\n");
	}	
}
int* minCol(int** matriz,int nfil,int ncol){
	int* minimo=(int*)calloc(ncol,sizeof(int));
	if(minimo!=NULL){
		for (int j = 0; j < ncol; ++j)
		{
			minimo[j]=matriz[0][j];
			for (int i = 0; i < nfil; ++i)
			{
				if(matriz[i][j]<minimo[j]){
					minimo[j]=matriz[i][j];
				}
			}
		}
	}
	else{
		printf("ERROR: No se pudo reservar memoria\n");
	}
	return minimo;
}
void liberarMemoria(int*** matriz,int nfil){//Nota: Para poner la matriz a NULL tienes que pasarlo por referencia
	for (int i = 0; i < nfil; ++i)
	{
		free((*matriz)[i]);
	}
	free(*matriz);
	*matriz=NULL;
}