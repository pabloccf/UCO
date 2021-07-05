#include <stdio.h>
#include <stdlib.h>
#include "funciones2.h"
void dividir(int* v,int n,int num,int** mayores,int* nMayor,int** menores,int* nMenor){
	*menores=(int*)calloc(n,sizeof(int));
	*mayores=(int*)calloc(n,sizeof(int));
	if(*mayores==NULL || *menores==NULL){
		printf("ERROR: No se pudo reservar memoria\n");
		*nMenor=0;
		*nMayor=0;
	}
	else{
	int countmayor=0;
	int countmenor=0;
	for(int i=0;i<n;i++){
		if(v[i]>num){
			(*mayores)[countmayor]=v[i];
			countmayor++;
		}
		else{
			(*menores)[countmenor]=v[i];
			countmenor++;
		}
	}
	*nMenor=countmenor;
	*nMayor=countmayor;
	}

}