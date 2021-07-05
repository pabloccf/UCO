#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones8.h"
void limpiarlinea(char* cad){
	int n=strlen(cad);
	for (int i = 0; i < n; ++i)
	{
		if(cad[i]=='\n'){
			cad[i]='\0';
		}
	}
}
int existelibro(char* filename,char* titulo){
	FILE* f=fopen(filename,"r");
	if(f==NULL){
		printf("ERROR: No se pudo abrir el fichero <%s>\n",filename);
	}
	else{
		char linea[200];
		int count=0;
		while(fgets(linea,200,f)!=NULL){
			limpiarlinea(linea);
			if(strcmp(linea,titulo)==0){
				return count;
			}
			fgets(linea,200,f);
			fgets(linea,200,f);
			count++;
		}
		fclose(f);
	}
	return -1;
}
void introducirlibro(char* filename,struct libro nuevo_libro){
	FILE* f=fopen(filename,"a");
	if(f==NULL){
		printf("ERROR: No se pudo abrir el fichero <%s>\n",filename);
	}
	else{
		fprintf(f, "%s\n",nuevo_libro.titulo);
		fprintf(f, "%s\n",nuevo_libro.autor);
		fprintf(f, "%f %d\n",nuevo_libro.precio,nuevo_libro.unidades);
		fclose(f);
	}
}
int cantidadlibros(char* filename){
	int count=0;
	FILE* f=fopen(filename,"r");
	if(f==NULL){
		printf("ERROR: No se pudo abrir el fichero <%s>\n",filename);
	}
	else{
		char linea[200];
		while(fgets(linea,200,f)!=NULL){
			fgets(linea,200,f);
			fgets(linea,200,f);
			count++;
		}
		fclose(f);
	}
	return count;
}
void listarlibros(char* filename){
	int n=cantidadlibros(filename);
	FILE* f=fopen(filename,"r");
	if(f==NULL){
		printf("ERROR: No se pudo abrir el fichero <%s>\n",filename);
	}
	else{
		struct libro* v=(struct libro*)calloc(n,sizeof(struct libro));
		if(v==NULL){
			printf("ERROR: No se pudo reservar memoria\n");
		}
		else{
			printf("----------------------------\n");
			char linea[200];
			for (int i = 0; i < n; ++i)
			{
				fgets(linea,200,f);
				limpiarlinea(linea);
				strcpy(v[i].titulo,linea);

				fgets(linea,200,f);
				limpiarlinea(linea);
				strcpy(v[i].titulo,linea);

				fgets(linea,200,f);
				sscanf(linea,"%f%d",&(v[i].precio),&(v[i].unidades));

				sscanf(linea,"%f%d",&(v[i].precio),&(v[i].unidades));
				printf("TITULO: %s\n",v[i].titulo);
				printf("AUTOR: %s\n",v[i].autor);
				printf("PRECIO: %f\n",v[i].precio);
				printf("UNIDADES: %d\n",v[i].unidades);
				printf("----------------------------------\n");
			}

			free(v);
		}
		fclose(f);
	}
}
void venderlibros(char* filename,char* titulo,int n_vendidos){
	int n=cantidadlibros(filename);
	int pos=existelibro(filename,titulo);
	FILE* f=fopen(filename,"r");
	if(f==NULL){
		printf("ERROR: No se pudo abrir el fichero <%s>\n",filename);
	}
	else{
		struct libro* v=(struct libro*)calloc(n,sizeof(struct libro));
		if(v==NULL){
			printf("ERROR: No se pudo reservar memoria\n");
		}
		else{
			char linea[200];
			for (int i = 0; i < n; ++i)
			{
				fgets(linea,200,f);
				limpiarlinea(linea);
				strcpy(v[i].titulo,linea);

				fgets(linea,200,f);
				limpiarlinea(linea);
				strcpy(v[i].titulo,linea);

				fgets(linea,200,f);
				sscanf(linea,"%f%d",&(v[i].precio),&(v[i].unidades));

				sscanf(linea,"%f%d",&(v[i].precio),&(v[i].unidades));
			}
			fclose(f);
			v[pos].unidades-=n_vendidos;
			if(v[pos].unidades<0){
				v[pos].unidades=0;
			}
			f=fopen(filename,"w");
			for (int i = 0; i < n; ++i)
			{
				fprintf(f, "%s\n",v[i].titulo);
				fprintf(f, "%s\n",v[i].autor);
				fprintf(f, "%f %d\n",v[i].precio,v[i].unidades);
			}

			free(v);
		}
	}
	fclose(f);
}
void borraragotados(char* filename){
	int n=cantidadlibros(filename);
	FILE* f=fopen(filename,"r");
	if(f==NULL){
		printf("ERROR: No se pudo abrir el fichero <%s>\n",filename);
	}
	else{
		struct libro* v=(struct libro*)calloc(n,sizeof(struct libro));
		if(v==NULL){
			printf("ERROR: No se pudo reservar memoria\n");
		}
		else{
			char linea[200];
			for (int i = 0; i < n; ++i)
			{
				fgets(linea,200,f);
				limpiarlinea(linea);
				strcpy(v[i].titulo,linea);

				fgets(linea,200,f);
				limpiarlinea(linea);
				strcpy(v[i].titulo,linea);

				fgets(linea,200,f);
				sscanf(linea,"%f%d",&(v[i].precio),&(v[i].unidades));

				sscanf(linea,"%f%d",&(v[i].precio),&(v[i].unidades));
			}
			fclose(f);

			f=fopen(filename,"w");
			for (int i = 0; i < n; ++i)
			{
				if(v[i].unidades>0){
				fprintf(f, "%s\n",v[i].titulo);
				fprintf(f, "%s\n",v[i].autor);
				fprintf(f, "%f %d\n",v[i].precio,v[i].unidades);
				}
			}

			free(v);
		}
	}
	fclose(f);
}