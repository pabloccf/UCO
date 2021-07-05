#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones11.h"
int existelibro(char* filename,char* titulo){
	int n=cantidadlibros(filename);
	FILE* f=fopen(filename,"rb");
	if(f==NULL){
		printf("ERROR: No se pudo abrir el fichero <%s>\n",filename);
	}
	else{
		struct libro aux;
		for (int i = 0; i < n; ++i)
		{
			fread(&aux,sizeof(struct libro),1,f);
			if(strcmp(aux.titulo,titulo)==0){
				fclose(f);
				return i;
			}
		}
	}
	fclose(f);
	return -1;
}
void introducirlibro(char* filename,struct libro nuevo_libro){
	FILE* f=fopen(filename,"ab");
	if(f==NULL){
		printf("ERROR: No se pudo abrir el fichero <%s>\n",filename);
	}
	else{
		fwrite(&nuevo_libro,sizeof(struct libro),1,f); 
		fclose(f);
	}
}
int cantidadlibros(char* filename){
	FILE* f=fopen(filename,"rb");
	if(f==NULL){
		printf("ERROR: No se pudo abrir el fichero <%s>\n",filename);
	}
	else{
		fseek(f,0,SEEK_END);
		int bytes=ftell(f);
		fclose(f);
		return (bytes/sizeof(struct libro));
	}
	return 0;
}
void listarlibros(char* filename){
	int n= cantidadlibros(filename);
	FILE* f=fopen(filename,"rb");
	if(f==NULL){
		printf("ERROR: No se pudo abrir el fichero <%s>\n",filename);
	}
	else{
		struct libro* v=(struct libro*)calloc(n,sizeof(struct libro));
		if(v==NULL){
			printf("ERROR: No se pudo reservar memoria\n");
		}
		else{
			fread(v,sizeof(struct libro),n,f);
			printf("----------------------------\n");
			for (int i = 0; i < n; ++i)
			{
				printf("Titulo: %s\n",v[i].titulo);
				printf("Autor: %s\n",v[i].autor);
				printf("Precio: %f\n",v[i].precio);
				printf("Unidades: %d\n",v[i].unidades);
				printf("---------------------------\n");
			}
		}
		fclose(f);
	}
}
void venderlibros(char* filename,char* titulo,int n){
	int pos=existelibro(filename,titulo);
	FILE* f=fopen(filename,"r+b");
	if(f==NULL){
		printf("ERROR: No se pudo abrir el fichero <%s>\n",filename);
	}
	else{
		//Leo el libro que quiero actualizar
		fseek(f,pos*sizeof(struct libro),SEEK_SET);
		struct libro aux;
		fread(&aux,sizeof(struct libro),1,f);
		//Actualizo el libro
		aux.unidades-=n;
		if(aux.unidades<0){
			aux.unidades=0;
		}
		//Escribo en el fichero el registro actualizado
		fseek(f,-sizeof(struct libro),SEEK_CUR);
		fwrite(&aux,sizeof(struct libro),1,f);
		fclose(f);
	}
}
void borraragotados(char* filename){
	FILE* f_original=fopen(filename,"rb");
	if(f_original==NULL){
		printf("ERROR: No se pudo abrir el fichero <%s>\n",filename);
	}
	else{
		char nombre_temp[200];
		strcpy(nombre_temp,filename);
		strcat(nombre_temp,"-temp");
		FILE* f_temp=fopen(nombre_temp,"wb");
		if(f_temp==NULL){
			printf("ERROR: No se pudo crear el fichero <%s>\n",nombre_temp);
		}
		else{
			struct libro aux;
			while(fread(&aux,sizeof(struct libro),1,f_original)==1){
				if(aux.unidades>0){
					fwrite(&aux,sizeof(struct libro),1,f_temp);
				}
			}
			fclose(f_temp);
			fclose(f_original);
			remove(filename);
			rename(nombre_temp,filename);
		}
	}
}