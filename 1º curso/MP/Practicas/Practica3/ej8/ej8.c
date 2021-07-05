#include <stdio.h>
#include <stdlib.h>
#include "funciones8.h"

int main(int argc, char* argv[]){
	if(argc!=2){
		printf("ERROR: Cantidad de argumentos no valida\n");
		printf("USAGE: %s [FICHERO]\n",argv[0]);
		return 1;
	}
	FILE* f=fopen(argv[1],"r");
	if(f==NULL){
		f=fopen(argv[1],"w");
	}
	fclose(f);

	int opcion;
	do{
		printf("1. Comprobar si existe libro\n");
		printf("2. Introducir nuevo libro\n");
		printf("3. Contar numero de libros\n");
		printf("4. Listar libros\n");
		printf("5. Vender libros\n");
		printf("6. Borrar agotados\n");
		printf("7. Salir\n");
		scanf("%d",&opcion);

		switch(opcion){
			case 1: {//Comprobar
				char titulo[100];
				printf("Introduzca el titulo del libro:\n");
				scanf("%s",titulo);

				if(existelibro(argv[1],titulo)>=0){
					printf("Existe el libro\n");
				}
				else{
					printf("No existe el libro\n");
				}
			}break;
			case 2: {//Introducir
				struct libro aux;

				printf("Introduzca el titulo del libro:\n");
				scanf("%s",aux.titulo);

				printf("Introduzca el autor del libro\n");
				scanf("%s",aux.autor);

				printf("Introduzca el precio del libro\n");
				scanf("%f",&(aux.precio));

				printf("Introduzca las unidades del libro\n");
				scanf("%d",&(aux.unidades));

				introducirlibro(argv[1],aux);
			}break;
			case 3: {//Contar
				printf("Hay %d libros\n",cantidadlibros(argv[1]));
			}break;
			case 4: {//Listar
				listarlibros(argv[1]);
			}break;
			case 5: {//Vender
				char titulo[100];
				int n;
				printf("Introduzca el titulo del libro:\n");
				scanf("%s",titulo);

				printf("Introduzca las unidades:\n");
				scanf("%d",&n);
				venderlibros(argv[1],titulo,n);
			}break;
			case 6: {//Borrar
				borraragotados(argv[1]);
			}break;
			case 7: {//Salir

			}break;
			default:{
				printf("ERROR: Opcion no valida\n");
			}break;
		}

	}while(opcion!=7);
	return 0;
}