/**
@file funciones7.h
@author Pablo López
@date 12-04-2020
@brief Este archivo contiene las declaraciones de las funciones
*/

#ifndef FUNCIONES7_H
#define FUNCIONES7_H

/**
@fn int** multiplicacionMatrices(int** m1,int nfil1,int ncol1,int** m2,int nfil2,int ncol2,int* nfilres,int* ncolres)
@brief Multiplica dos matrices
@param m1 Primera matriz
@param nfil1 Cantidad de filas de la primera matriz
@param ncol1 Cantidad de columnas de la primera matriz
@param m2 Segunda matriz
@param nfil2 Cantidad de filas de la segunda matriz
@param ncol2 Cantidad de columnas de la segunda matriz
@param nfilres Parámetro pasado por referencia que se refiere a la cantidad de filas de la matriz resultado
@param ncolres Parámetro pasado por referencia que se refiere a la cantidad de columnas de la matriz resultado
@return Matriz resultante.@n@b NULL si no se pudo realizar la operacion 

Realiza la operacion m1*m2 y devuelve la matriz resultante 
*/

int** multiplicacionMatrices(int** m1,int nfil1,int ncol1,
							 int** m2,int nfil2,int ncol2,
							 int* nfilres,int* ncolres
);
#endif
