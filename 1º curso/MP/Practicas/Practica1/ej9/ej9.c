/**
@file ej9.c
@author Pablo López
@date 10-04-2020
@brief Este fichero contiene el main
*/
#include <stdio.h>
#include <stdlib.h>
#include "funciones9.h"

/**
@fn main()
@return 0 si todo va bien
@brief punto de entrada del programa
*/
int main(){
	int n;
	struct Monomio polinomio[100];
	printf("Introduzca la cantidad de monomios: ");
	scanf("%d",&n);

	leerPolinomio(polinomio,n);
	imprimirPolinomio(polinomio,n);

	struct Monomio mayor;
	struct Monomio menor;

	mayorMenor(polinomio,n,&mayor,&menor);

	printf("El monomio de mayor grado es: ");
	imprimirMonomio(mayor);
	printf("\n");

	printf("El monomio de menor grado es: ");
	imprimirMonomio(menor);
	printf("\n");

	int x;
	printf("Introduzca un valor a x: ");
	scanf("%d",&x);
	printf("El polinomio en el punto x=%d vale %d\n",x,evaluar(polinomio,n,x));

	return 0;
}