#include <stdio.h>
#include <stdlib.h>
#include "funciones3.h"

int main(){
	char cad[200];
	char c;
	printf("Introduzca una cadena:\n");
	gets(cad);

	printf("Introduzca el caracter que quieres buscar en la cadena:\n");
	scanf("%c",&c);

	printf("El caracter %c aparece %d veces\n",c,contar(cad,c));
	return 0;
}