#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
void ordena(int n,int v[]){
	for(int i=0;i<n;i++){
		if(v[i]%2!=0){
			for(int j=i;j<n;j++){
				if(v[j]%2==0){
					int c=v[j];
					v[j]=v[i];
					v[i]=c;
				}
			}
		}
	}
}

