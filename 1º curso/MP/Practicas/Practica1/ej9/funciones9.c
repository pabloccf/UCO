/**
@file funciones9.c
@author Pablo López
@date 10-04-2020
@brief Este fichero contiene las definiciones de las funciones
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones9.h"
void leerMonomio(struct Monomio* m){
	printf("Introduce el coeficiente: ");
	scanf("%d",&(m->coeficiente));

	printf("Introduce el grado: ");
	scanf("%d",&(m->grado));
}
void imprimirMonomio(struct Monomio m){
	printf("%dx^%d",m.coeficiente,m.grado);
}

void leerPolinomio(struct Monomio m[],int n){
	for(int i=0;i<n;i++){
		leerMonomio(&m[i]);
	}
}
void imprimirPolinomio(struct Monomio m[],int n){
	for(int i=0;i<n;i++){
		imprimirMonomio(m[i]);
		if(i!=n-1){
			printf(" + ");
		}
	}
	printf("\n");
}
void mayorMenor(struct Monomio m[],int n,struct Monomio*mayor,struct Monomio* menor){
	int ind_mayor=0;
	int ind_menor=0;
	for(int i=0;i<n;i++){
		if(m[i].grado>m[ind_mayor].grado){
			ind_mayor=i;
		}
		if(m[i].grado<m[ind_menor].grado){
			ind_menor=i;
		}
	}
	*mayor=m[ind_mayor];
	*menor=m[ind_menor];
}
int evaluar(struct Monomio m[],int n, int x){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=m[i].coeficiente*pow(x,m[i].grado);
	}
	return sum;
}