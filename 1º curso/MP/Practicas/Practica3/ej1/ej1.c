#include <stdio.h>
#include <stdlib.h>
#include "funciones1.h"

int main(){
	int x,y;
	printf("Introduzca dos numeros:\n");
	scanf("%d%d",&x,&y);

	if(y>x){
		int aux=x;
		x=y;
		y=aux;
	}

	printf("El MCD de %d y %d es: %d\n",x,y,mcd(x,y));
	return 0;
}