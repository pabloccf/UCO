#include <stdio.h>
#include <stdlib.h>
#include "libMatrices.h"

int main(){
	int nfil,ncol;

	printf("Introduce el tamaño de la matriz:\n");
	scanf("%d%d",&nfil,&ncol);

	int** matriz=reservarMemoria(nfil,ncol);
	rellenaMatriz(matriz,nfil,ncol);
	imprimeMatriz(matriz,nfil,ncol);

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

	printf("Minimos:\n");
	for (int i = 0; i < ncol; ++i)
	{
		printf("%d ",minimo[i]);
	}
	printf("\n");

	liberarMemoria(&matriz,nfil);
	free(minimo);
	return 0;
}