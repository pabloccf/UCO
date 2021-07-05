#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
void mat_mal_sum(float ma[6][6],float mb[6][6],float mc[6][6],float md[6][6]){
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			md[i][j]=0;
			for(int k=0;k<6;k++){
				md[i][j]+=ma[i][k]*mb[k][j];
			}
			md[i][j]+=mc[i][j];
		}
	}
}
