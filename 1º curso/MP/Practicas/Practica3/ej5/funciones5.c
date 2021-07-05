#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones5.h"
void mayusculas(char* filename){
	FILE* f_in=fopen(filename,"r");
	char nombre_salida[]="mayusculas-";
	strcat(nombre_salida,filename);
	FILE* f_out=fopen(nombre_salida,"w");

	if(f_in!=NULL && f_out!=NULL){
		int c;
		while((c=fgetc(f_in))!=EOF){
			c=toupper(c);
			fputc(c,f_out);
		}
	}
	else{
		fprintf(stderr,"ERROR:No se pudo abrir el fichero\n");
	}

	fclose(f_in);
	fclose(f_out);
}