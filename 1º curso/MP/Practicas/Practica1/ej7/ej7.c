#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones7.h"
int main(){
	int nv;
	int v[100];
	float media=0.0,varianza=0.0,desvtip=0.0;

	printf("Introduce la cantidad de numeros que vas a meter\n");
	scanf("%d",&nv);

	printf("Introduce los elementos del vector\n");
	leervector(nv,v);

	printf("Los elementos del vector son:\n");
	imprimirvector(nv,v);

	estadisticasVector(nv,v,&media,&varianza,&desvtip);
	printf("Media: %f\n Varianza: %f\n Desviacion Tipica: %f\n",media,varianza,desvtip);
	return 0;
}