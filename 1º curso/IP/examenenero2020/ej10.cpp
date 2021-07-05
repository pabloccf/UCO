#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int numeros_distintos(int n,int v[]){
	int count=1;
	for(int i=0;i<n-1;i++){
		if(v[i]!=v[i+1]){
			count++;
		}
	}
	return count;
}

