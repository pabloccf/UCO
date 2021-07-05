#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

int main(int argc,char** argv){
	int n,max,min;
	char filename[200];
	if(argc==5){
		n=atoi(argv[2]);
		max=atoi(argv[3]);
		min=atoi(argv[4]);
	}
	else{
		printf("ERROR:Cantidad de argumentos no valida\n");
		printf("USAGE: %s [FICHERO] [ELEMENTOS] [LIM SUPERIOR] [LIM INFERIOR]",argv[0]);
		return 0;
	}
	srand(time(NULL));

	int* v= crearvector(max,min,n);
	escribefichero(argv[1],v,n);

	free(v);
	
	return 0;
}