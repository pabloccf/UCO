#include <stdio.h>
#include <stdlib.h>
#include "funciones2.h"

int main(){
	int v[200];
	int n,num;
	int nMenor,nMayor;
	int* menores;
	int* mayores;
	printf("Introduce el tamaño del vector: ");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		printf("Introduce el elemento %d del vector: ",i);
		scanf("%d",&v[i]);
	}
	printf("Introduce el numero por el que partir el vector: ");
	scanf("%d",&num);

	dividir(v,n,num,&mayores,&nMayor,&menores,&nMenor);

	printf("El vector es: \n");
	for (int i = 0; i < n; i++){
		printf("%d\n",v[i] );
	}

	printf("\nEl vector de mayores que %d es:\n",num);
	for (int i = 0; i < nMayor; i++)
	{
		printf("%d\n",mayores[i] );
	}

	printf("\nEl vector de menores que %d es:\n",num );
	for (int i = 0; i < nMenor; i++)
	{
		printf("%d\n",menores[i] );
	}
	printf("\n");
	return 0;
}