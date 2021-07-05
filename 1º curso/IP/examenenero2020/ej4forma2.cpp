#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
void ordena(int n,int v[]){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if((v[i]%2!=0)&&(v[j]%2==0)){
				int c=v[j];
				v[j]=v[i];
				v[i]=c;
			}
		}
	}
}
