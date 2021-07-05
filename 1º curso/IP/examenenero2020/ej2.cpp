#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
bool vectiguales(int v1[],int v2[],int n){
	for(int i=0;i<n;i++){
		if(v1[i]!=v2[i]){
			return false;
		}
	}
	return true;
}

