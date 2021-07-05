#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones3.h"
void leerjugador(struct Ficha_jugador* a){
	printf("Introduce el nombre del jugador: ");
	scanf("%s",a->nombre);
	printf("Introduce el dorsal del jugador: ");
	scanf("%d",&(a->dorsal));
	printf("Introduce el peso del jugador: ");
	scanf("%f",&(a->peso));
	printf("Introduce la estatura del jugador: ");
	scanf("%d",&(a->estatura));
}
void imprimirjugador(struct Ficha_jugador a){
	printf("Nombre: <%s>\n",a.nombre );
	printf("Dorsal: %d\n",a.dorsal );
	printf("Peso: %f\n",a.peso );
	printf("Estatura: %d\n",a.estatura );
}
int borrarjugadores(struct Ficha_jugador* v,int n,char c){
	int i=0;
	while(i<n){
		if(strchr(v[i].nombre,c)!=NULL){
			//Reemplazamos el jugador i con el ultimo
			v[i]=v[n-1];
			n--;//Actualizamos el tamaño
		}
		else{
			//Si no borramos al jugador pasamos al siguiente
			i++;
		}
	}
	realloc(v,n*sizeof(struct Ficha_jugador));
	return n;
}