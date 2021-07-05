#include <stdio.h>
#include <stdlib.h>
#include "funciones10.h"
int* leerfichero(char* filename,int* n){
	FILE* f=fopen(filename,"rb");
	int* v;
	if(f==NULL){
		printf("ERROR: No se pudo abrir el fichero <%s>\n",filename);
	}
	else{
		fseek(f,0,SEEK_END);
		int tam=ftell(f);
		*n=tam/sizeof(int);
		v=(int*)calloc(*n,sizeof(int));
		if(v==NULL){
			printf("ERROR: No se pudo reservar memoria\n");
		}
		else{
			fseek(f,0,SEEK_SET);
			if(fread(v,sizeof(int),*n,f)!=*n){
				printf("ERROR: No se pudo leer el fichero <%s>\n",filename);
				v=NULL;
				*n=0;
			}
		}
		fclose(f);
	}
	return v;
}
float calculamedia(int* v,int n){
	float sum=0;
	float count=0;
	for (int i = 0; i < n; ++i)
	{
		if(v[i]%2==0){
		sum+=v[i];
		count++;
		}
	}
	return sum/count;
}