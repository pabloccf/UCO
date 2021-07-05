/**
@file funciones10.c
@author Pablo López
@date 12-04-2020
@brief Este archivo contiene las definiciones de las funciones
*/

#include <stdio.h>
#include <stdlib.h>
#include "funciones10.h"
void leeVector(double* v,int n){
	for(int i=0;i<n;i++){
		printf("Introduzca v[%d]: ",i);
		scanf("%lf",v+i);
	}
}
void escribeVector(double* v,int n){
	for(int i=0; i<n; i++){
		printf("v[%d]=%lf\n",i,*(v+i));
	}
}
double sumaPositivos(double* v, int n){
	double sum=0;
	for(int i=0;i<n;i++){
		if(*(v+i)>0){
			sum+=*(v+i);
		}
	}
	return sum;
}