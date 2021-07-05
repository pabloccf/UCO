/**
@file funciones.h
@author Pablo López
@date 13-04-2020
@brief Este archivo contiene las declaraciones de las funciones
*/

#ifndef FUNCIONES_H
#define FUNCIONES_H

/**
@fn int** reservaMatriz(int nfil,int ncol)
@brief Reserva la memoria de la matriz
@param nfil Número de filas de la matriz
@param ncol Número de columnas de la matriz
@return Devuelve la matriz.@n@b NULL si no se pudo reservar memoria

Esta función reserva la memoria de la matriz tanto de las filas como de las columnas
*/

int** reservaMatriz(int nfil,int ncol);
void rellenaMatriz(int** matriz,int nfil,int ncol);
void imprimeMatriz(int** matriz,int nfil,int ncol);
void divideMatriz(int** matriz,int nfil,int ncol,int* ndiv,int* sum);
void liberarmemoriaMatriz(int*** matriz,int nfil);
#endif