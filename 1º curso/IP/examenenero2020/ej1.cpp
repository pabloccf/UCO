#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int cuentadigitos(string cad){
	int s=cad.size(),count=0;
	for(int i=0;i<s;i++){
		if(isdigit(cad[i])){
			count++;
		}
	}
	return count;
}
