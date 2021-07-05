#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones5.h"

int main(){
	char filename[200];
	printf("Introduzca el nombre del fichero:\n");
	gets(filename);

	mayusculas(filename);
	return 0;
}