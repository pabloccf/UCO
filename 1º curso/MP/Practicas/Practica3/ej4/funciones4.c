#include <stdio.h>
#include <stdlib.h>
#include "funciones4.h"
int sumadigitos(int a){
	if(a==0){
		return 0;
	}
	return(a%10+sumadigitos(a/10)); 
}