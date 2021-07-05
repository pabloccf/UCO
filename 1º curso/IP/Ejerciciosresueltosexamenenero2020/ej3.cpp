#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int find_in_matrix(float m[6][6],float val){
	int count=0;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(m[j][i]==val){
				count++;
			}
		}
	}
	return count;
}