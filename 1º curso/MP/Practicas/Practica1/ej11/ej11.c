#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones11.h"
int main(){
	char cadena[200];
	char sufijo[200];
	char prefijo[200];
	printf("Introduzca la cadena que quiere analizar: ");
	gets(cadena);
	printf("La cadena es: <%s>\n",cadena);

	printf("Introduzca el prefijo que quiera analizar: ");
	gets(prefijo);

	printf("Introduzca el sufijo que quiera analizar: ");
	gets(sufijo);

	if(es_prefijo(cadena,prefijo)==1){
			printf("El prefijo <%s> si es prefijo de la cadena\n",prefijo);
	}
	else{
		printf("El prefijo <%s> no es prefijo de la cadena\n",prefijo);
	}
	if(es_sufijo(cadena,sufijo)==1){
		printf("El sufijo <%s> si es sufijo de la cadena\n",sufijo);
	}
	else{
		printf("El sufijo <%s> no es sufijo de la cadena\n",sufijo);
	}
	return 0;
}