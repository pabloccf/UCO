#include <stdio.h>
#include <stdlib.h>
#include "funciones6.h"

int main(){
	int nfil,ncol;
	printf("Introduzca la cantidad de filas y columnas:\n");
	scanf("%d%d",&nfil,&ncol);

	int** m=reservarMemoria(nfil,ncol);
	if(m!=NULL){
		rellenaMatriz(m,nfil,ncol);
		imprimeMatriz(m,nfil,ncol);

		int* minimos=minCol(m,nfil,ncol);
		if(minimos!=NULL){
			//Imprimo el vector
			printf("Minimos:\n");
			for (int i = 0; i < ncol; ++i)
			{
				printf("%d ",minimos[i] );
			}
			printf("\n");
			//Libero el vector
			free(minimos);
		}

		liberarMemoria(&m,nfil);
	}
	return 0;
}