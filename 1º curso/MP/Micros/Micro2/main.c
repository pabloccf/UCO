#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char* argv[]){
	if(argc!=4){
		printf("ERROR: Cantidad de argumentos no valida\n");
		printf("USAGE: %s [FICHERO NOTAS] [FICHERO ALUMNOS] [FICHERO RESULTADO]\n",argv[0]);
		return 1;
	}
	FILE* f=fopen(argv[1],"r");
	if(f==NULL){
		printf("ERROR: No existe el fichero de notas\n");
		return 1;
	}
	fclose(f);

	f=fopen(argv[2],"r");
	if(f==NULL){
		printf("ERROR: No existe el fichero de alumnos\n");
		return 1;
	}
	fclose(f);

	int n;
	struct Alumno* v=readstudents(argv[2],&n);

	calculateavg(argv[1],v,n);
	fichero(argv[3],v,n);

	return 0;
}