#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int digitos(string cad){
	int count=0,s=cad.size();
	for(int i=0;i<s;i++){
		if(isdigit(cad[i])){
			count++;
		}
	}
	return count;
}
int main(){
	string cad;
	cout<<"Introduce una oracion y te dire el numero de digitos que tiene dicha oracion"<<endl;
	getline(cin,cad);
	cout<<"La oracion tiene "<<digitos(cad)<<" digitos"<<endl;
cin.ignore();
cin.get();
}

