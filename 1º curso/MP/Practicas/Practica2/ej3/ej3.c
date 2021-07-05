#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones3.h"
int main()
{
	int n;
	printf("Introduzca la cantidad de jugadores: ");
	scanf("%d",&n);
	struct Ficha_jugador* v=(struct Ficha_jugador*)calloc(n,sizeof(struct Ficha_jugador));

	for (int i = 0; i < n; ++i)
	{
		leerjugador(&v[i]);
	}

	printf("-------------------\n");
	for (int i = 0; i < n; ++i)
	{
		imprimirjugador(v[i]);
		printf("-------------------\n");
	}
	printf("\n");

	n=borrarjugadores(v,n,'a');

	printf("-------------------\n");
	for (int i = 0; i < n; ++i)
	{
		imprimirjugador(v[i]);
		printf("-------------------\n");
	}

	free(v);
	return 0;
}