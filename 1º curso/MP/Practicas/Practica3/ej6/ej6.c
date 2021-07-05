#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones6.h"

int main(int argc, char* argv[]){
	int n,max,min;
	if(argc!=5){
		printf("ERROR: Cantidad de argumentos no valida\n");
		printf("USAGE: %s [FICHERO] [NUMEROS] [LIM SUPERIOR] [LIM INFERIOR]\n",argv[0]);
		return 1;
	}
	else{
		n=atoi(argv[2]);
		max=atoi(argv[3]);
		min=atoi(argv[4]);
	}

	srand(time(NULL));

	escribenumeros(argv[1],n,max,min);

	return 0;
}