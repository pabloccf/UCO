#include <stdio.h>
#include <stdlib.h>
#include "funciones2.h"
int dividir(int div,int divisor){
	if(div<divisor){
		return 0;
	}
	else{
		return 1+dividir(div-divisor,divisor);
	}
}