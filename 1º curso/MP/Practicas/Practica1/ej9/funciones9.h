/**
@file funciones9.h
@author Pablo López
@date 10-04-2020
@brief Este fichero contiene las declaraciones de las funciones
*/

#ifndef FUNCIONES9_H
#define FUNCIONES9_H

/**
@struct Monomio
@param coeficiente Coeficiente del monomio
@param grado Grado del monomio
@brief Representa un monomio

Esta estructura almacena la informacion de un monomio guardando su grado y su coeficiente
*/

struct Monomio{
	int coeficiente;
	int grado;
};
void leerMonomio(struct Monomio* m);
void imprimirMonomio(struct Monomio m);

/**
@fn void leerPolinomio(struct Monomio m[],int n)
@param m vector de monomios
@param n tamaño del vector de monomios 
@return nada
@brief Lee un polinomio
*/

void leerPolinomio(struct Monomio m[],int n);
void imprimirPolinomio(struct Monomio m[],int n);

/**
 @fn void mayorMenor(struct Monomio p[], int n, struct Monomio* mayor, struct Monomio* menor)
 @brief devuelve el mayor y menor grados
 */

void mayorMenor(struct Monomio m[],int n,struct Monomio*mayor,struct Monomio* menor);
int evaluar(struct Monomio m[],int n, int x);
#endif