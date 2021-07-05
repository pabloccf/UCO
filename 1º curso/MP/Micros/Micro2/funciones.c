#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void cleanlinea(char* cad){
	int n=strlen(cad);
	for (int i = 0; i < n; ++i)
	{
		if(cad[i]=='\n'){
			cad[i]='\0';
		}
	}
}
struct Alumno* readstudents(char* filename,int* n){
	FILE* f=fopen(filename,"r");
	struct Alumno* v;
	int count=0;
	if(f==NULL){
		printf("ERROR: El fichero <%s> no se pudo abrir\n",filename);
	}
	else{
		char linea[300];
		while(fgets(linea,300,f)!=NULL){
			fgets(linea,300,f);
			count++;
		}
	}
	fclose(f);
	f=fopen(filename,"r");
	if(f==NULL){
		printf("ERROR: El fichero <%s> no se pudo abrir\n",filename);
	}
	else{
		v=(struct Alumno*)calloc(count,sizeof(struct Alumno));
		if(v==NULL){
			printf("ERROR: No se pudo reservar memoria\n");
		}
		else{
			char linea[300];
			for (int i = 0; i < count; ++i)
			{
				fgets(linea,300,f);
				cleanlinea(linea);
				strcpy(v[i].nombre,linea);

				fgets(linea,300,f);
				cleanlinea(linea);
				v[i].dni=atol(linea);
			}
		}		
		fclose(f);
	}
	*n=count;
	return v;
}
void calculateavg(char* filename,struct Alumno* v,int n){
	FILE* f=fopen(filename,"r");
	if(f==NULL){
		printf("ERROR: El fichero <%s> no se pudo abrir\n",filename);
	}
	else{
		char linea[300];
		for (int i = 0; i < n; ++i)
		{
			fgets(linea,300,f);
			long dni=-1;
			float note1,note2,note3;
			sscanf(linea,"%ld%f%f%f",&dni,&note1,&note2,&note3);

			v[i].notamedia=(note1+note2+note3)/3;
		}
	}
	fclose(f);
}
void fichero(char* filename,struct Alumno* v,int n){
	FILE* f=fopen(filename,"w");
	if(f==NULL){
		printf("El fichero <%s> no se pudo crear\n",filename);
	}
	else{
		for (int i = 0; i < n; ++i)
		{
			fprintf(f, "%ld <%s> %f\n",v[i].dni,v[i].nombre,v[i].notamedia);
		}
	}
	fclose(f);
}