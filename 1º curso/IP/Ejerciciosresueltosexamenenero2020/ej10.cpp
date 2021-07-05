#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int numeros_distintos(int n,int v[]){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(v[i]>v[j]){
				int c=v[i];
				v[i]=v[j];
				v[j]=c;
			}
		}
	}
	int count=1;
	for(int h=0;h<n-1;h++){
		if(v[h]!=v[h+1]){
			count++;
		}
	}
	return count;
}

