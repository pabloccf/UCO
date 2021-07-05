#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
bool palindromo(string cad){
	int s=cad.size();
	for(int i=0;i<s/2;i++){
		if(cad[i]!=cad[s-1-i]){
			return false;
		}
	}
	return true;
}

