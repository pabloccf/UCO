#include <stdio.h>
#include <stdlib.h>
#include "funciones4.h"

int main(){
	int a;
	printf("Introduzca un numero:\n");
	scanf("%d",&a);

	printf("La suma de los digitos es: %d\n",sumadigitos(a));
	return 0;
}