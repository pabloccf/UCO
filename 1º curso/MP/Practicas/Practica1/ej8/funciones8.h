/**
 @file funciones8.h
 @author Pablo López
 @brief Este fichero contiene las declaraciones de las funciones
*/

#ifndef FUNCIONES8_H
#define FUNCIONES8_H

/**
@fn void estadisticasCadena(char* cadena,int* digitos,int* mayus,int* minus,int* espacios)
@param cadena Es la cadena que va a analizar
@param digitos Es el numero de digitos que tiene la cadena
@param mayus Es el numero de mayusculas que tiene la cadena
@param minus Es el numero de minusculas que tiene la cadena
@param espacios Es el numero de espacios que tiene la cadena
@return nada
@brief Cuenta los numeros de digitos, mayusculas, minusculas y espacios que tiene una cadena.
*/

void estadisticasCadena(char* cadena,int* digitos,int* mayus,int* minus,int* espacios);
#endif