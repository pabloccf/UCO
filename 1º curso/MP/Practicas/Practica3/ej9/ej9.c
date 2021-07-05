#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones9.h"

int main(){
	int n,max,min;
	char filename[200];
	srand(time(NULL));

	printf("Introduzca la cantidad de elementos:\n");
	scanf("%d",&n);

	printf("Introduzca el valor maximo:\n");
	scanf("%d",&max);

	printf("Introduzca el valor minimo:\n");
	scanf("%d",&min);

	printf("Introduzca el nombre del fichero:\n");
	scanf("%s",filename);

	int* v= crearvector(max,min,n);
	escribefichero(filename,v,n);

	free(v);
	
	return 0;
}