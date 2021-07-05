#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones6.h"

void escribenumeros(char* filename,int n,int max,int min){
	FILE* f=fopen(filename,"w");
	if(f==NULL){
		printf("ERROR: No se pudo abrir el fichero <%s>\n",filename);
	}
	else{
		for (int i = 0; i < n; ++i)
		{
			int num=(rand()% (max-min+1))+min;
			fprintf(f, "%d\n",num);
		}
	}
	fclose(f);
}
