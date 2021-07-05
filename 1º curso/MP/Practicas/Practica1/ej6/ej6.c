#include <stdio.h>
#include <stdlib.h>
#include "funciones6.h"
int main(){
	int num1,num2,resultado;
	printf("Introduce el primer numero\n");
	scanf("%d",&num1);

	printf("Introduce el segundo numero\n");
	scanf("%d",&num2);

	minimo_referencia(num1,num2,&resultado);
	int res_min=minimo(num1,num2);
	if(res_min==resultado){
		printf("Las funciones devolvieron el mismo resultado: %d\n",resultado);
	}
	else{
		printf("Las funciones devolvieron resultados distintos: %d %d\n",res_min,resultado);	
	}
	return 0;
}