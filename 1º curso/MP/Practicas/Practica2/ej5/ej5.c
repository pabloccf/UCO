#include <stdio.h>
#include <stdlib.h>
#include "funciones5.h"
int main(){
	char cad[200];
	printf("Introduce una frase:\n");
	gets(cad);

	int n;
	char** palabras=split(cad,&n);
	for (int i = 0; i < n; ++i)
	{
		printf("<%s>\n",palabras[i]);
	}
	float avg;
	int mayor;
	int menor;
	media(palabras,n,&avg,&mayor,&menor);
	printf("La media es: %f\n",avg );
	printf("La mayor longitud es: %d\n",mayor);
	printf("La menor longitud es: %d\n",menor);

	int nfreq=0;
	struct Freq* frecuencias=medirFrecuencias(palabras,n,&nfreq);
	for (int i = 0; i < nfreq; ++i)
	{
		printf("La frecuencia de la longitud %d es: %f\n",frecuencias[i].longitud,frecuencias[i].frecuencia);
	}

	return 0;
}