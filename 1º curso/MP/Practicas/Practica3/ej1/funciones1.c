#include <stdio.h>
#include <stdlib.h>
#include "funciones1.h"
int mcd(int x,int y){
	if(y==0){
		return x;
	}
	else{
		return mcd(y,x%y);
	}	
}