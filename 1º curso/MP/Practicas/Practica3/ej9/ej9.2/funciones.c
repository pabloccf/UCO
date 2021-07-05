#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"
int* crearvector(int max,int min,int n){
	int* v=(int*)calloc(n,sizeof(int));
	if(v==NULL){
		printf("ERROR: No se pudo reservar memoria\n");
	}
	else{
		for (int i = 0; i < n; ++i){
			v[i]=(rand()%(max-min+1))+min;
		}
	}
	return v;
}
void escribefichero(char* filename,int* v,int n){
	FILE* f=fopen(filename,"wb");
	if(f==NULL){
		printf("ERROR: No se pudo abrir el fichero <%s>\n",filename);
	}
	else{
		if(fwrite(v,sizeof(int),n,f)!=n){
			printf("ERROR: No se pudo escribir en el fichero\n");
		}
		fclose(f);
	}
}
