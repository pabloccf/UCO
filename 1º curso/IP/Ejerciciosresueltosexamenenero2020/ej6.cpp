#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
void mat_mul_sum(float ma[6][6],float mb[6][6],float mc[6][6],float md[6][6]){
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			md[j][i]=0;
			for(int k=0;k<6;k++){
				md[j][i]=md[j][i]+ma[j][k]*mb[k][i];
			}
			md[j][i]=md[j][i]+mc[j][i];
		}
	}
}