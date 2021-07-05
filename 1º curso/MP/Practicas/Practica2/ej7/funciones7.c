/**
@file funciones7.c
@author Pablo López
@date 12-04-2020
@brief Este archivo contiene las definiciones de las funciones
*/

#include <stdio.h>
#include <stdlib.h>
#include "funciones7.h"
#include "libMatrices.h"
int** multiplicacionMatrices(int** m1,int nfil1,int ncol1,
							 int** m2,int nfil2,int ncol2,
							 int* nfilres,int* ncolres
){
	//Compruebo que se pueda multiplicar
	if(ncol1!=nfil2){
		return NULL;
	}
	
	int** matriz=reservarMemoria(nfil1,ncol2);
	for (int i = 0; i < nfil1; ++i)
	{
		for(int j=0;j<ncol2;++j){
			//Selecciono un elemento de la matriz y lo pongo en 0
			matriz[i][j]=0;
			for(int k=0;k<ncol1;++k){
				//Calculo el elemento
				matriz[i][j]+=m1[i][k]*m2[k][j];
			}
		}
	}

	*nfilres=nfil1;
	*ncolres=ncol2;
	return matriz;

}