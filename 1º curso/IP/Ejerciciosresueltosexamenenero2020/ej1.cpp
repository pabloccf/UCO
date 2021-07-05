#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int cuentadigitos(string cad){
	int count=0,s=cad.size();
	for(int i=0;i<s;i++){
		if(isdigit(cad[i])){
			count++;
		}
	}
	return count;
}


