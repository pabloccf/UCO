#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
void mezclamayor(int v1[],int v2[],int n){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(v2[i]<v1[j]){
				int c=v2[i];
				v2[i]=v1[j];
				v1[j]=c;
			}
			if(v2[i]<v2[j]){
				int c=v2[i];
				v2[i]=v2[j];
				v2[j]=c;
			}
		}
	}
}

