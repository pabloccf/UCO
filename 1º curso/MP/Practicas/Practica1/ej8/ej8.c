/**
 @file ej8.c
 @author Pablo López
 @brief Este fichero contiene el main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones8.h"

/**
@fn main()
@return 0 si todo termina correctamente
@brief Esta funcion es el punto de entrada del programa
*/

int main(){
	char cadena[100];
	printf("Introduce una cadena de caracteres\n");
	gets(cadena);//El gets(cadena) te lee la cadena con los espacios incluidos cosa que un scanf no hace.
	printf("La cadena es: <%s>\n",cadena);//Los signos < > entre el %s es para ver donde empieza y acaba la cadena, por si se cuea algun espacio al principio o al final poder verlo.

	int digitos,mayus,minus,espacios;

	estadisticasCadena(cadena,&digitos,&mayus,&minus,&espacios);
	printf("Hay %d caracteres numericos\n",digitos);
	printf("Hay %d caracteres en mayusculas\n",mayus);
	printf("Hay %d caracteres en minusculas\n",minus);
	printf("Hay %d caracteres que son espacios\n",espacios);
	return 0;
}