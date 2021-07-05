#include <stdio.h>
#include <stdlib.h>
#include "funciones7.h"

float mediapares(char* filename){
	FILE* f= fopen(filename,"r");
	if(f==NULL){
		printf("ERROR: No se pudo abrir el fichero <%s>\n",filename);
	}
	else{
		float sum=0;
		int count=0;
		int num;
		while(fscanf(f,"%d",&num)==1){
			if(num%2==0){
				sum+=num;
				count++;
			}
		}

		fclose(f);
		return(sum/count);
	}
	return -1;
}