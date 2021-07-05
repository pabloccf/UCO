#include <stdio.h>
#include <stdlib.h>
#include "funciones2.h"

int main(){
	int dividendo,divisor;
	printf("Introduzca el dividendo y el divisor:\n");
	scanf("%d%d",&dividendo,&divisor);

	printf("%d/%d=%d\n",dividendo,divisor,dividir(dividendo,divisor));
	return 0;
}
