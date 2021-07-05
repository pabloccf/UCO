#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
bool palindromo(string cad){
	int s=cad.size();
	for(int i=0;i<s/2;i++){
		if(cad[i]!=cad[s-1-i]){
			return false;
		}
		return true;
	}
}
int main(){
	string cad;
	cout<<"Dime una palabra y te dire si es un palindromo o no"<<endl;
	getline(cin,cad);
	if(palindromo(cad)==false){
		cout<<"No es un palindromo"<<endl;
	}
	else{
		cout<<"Es un palindromo"<<endl;
	}
cin.ignore();
cin.get();
}

