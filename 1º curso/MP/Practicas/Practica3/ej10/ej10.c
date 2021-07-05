#include <stdio.h>
#include <stdlib.h>
#include "funciones10.h"

int main(int argc, char* argv[]){
	if(argc!=2){
		printf("ERROR: Cantidad de elementos no valida\n");
		printf("USAGE: %s [FICHERO]\n",argv[0]);
		return 0;
	}

	int n;
	int*v = leerfichero(argv[1],&n);
	for (int i = 0; i < n; ++i)
	{
		if(v[i]%2==0){
		printf("Los numeros pares del vector es: v[%d]= %d\n",i,v[i]);	
		}
	}
	float media=calculamedia(v,n);

	printf("La media de los numeros es: %f\n",media);

	return 0;
}