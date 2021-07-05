#include <stdio.h>
#include <stdlib.h>
#include "funciones7.h"

int main(int argc, char* argv[]){
	if(argc!=2){
		printf("ERROR: Cantidad de argumentos no valida\n");
		printf("%s [FICHERO]\n",argv[0]);
		return 1;
	}

	printf("La media de lo numeros pares es: %f\n",mediapares(argv[1]));
	return 0;
}