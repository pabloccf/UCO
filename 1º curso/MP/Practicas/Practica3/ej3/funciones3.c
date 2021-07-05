#include <stdio.h>
#include <stdlib.h>
#include "funciones3.h"
int contar(char* cad,char c){
	if(cad[0]=='\0'){
		return 0;
	}
	if(cad[0]==c){
		return 1+contar(cad+1,c);
	}
	else{
		return contar(cad+1,c);
	}
}