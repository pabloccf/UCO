/**
@file funciones10.h
@author Pablo López
@date 12-04-2020
@brief Este archivo contiene las declaraciones de las funciones
*/

#ifndef FUNCIONES10_H
#define FUNCIONES10_H

/**
@fn void leeVector(double* v,int n)
@brief Lee el vector introducido por el usuario
@param v vector de elementos
@param n tamaño del vector 
@return Nada
*/

void leeVector(double* v,int n);
void escribeVector(double* v,int n);

/**
@fn double sumaPositivos(double* v, int n)
@brief Suma los números positivos del vector
@param v vector de elementos 
@param n tamaño del vector
@return suma de los numeros positivos

Esta funcion recorre el vector de elemntos y va sumando cada uno de los números positivos que hay en dicho vector
*/

double sumaPositivos(double* v, int n);
#endif