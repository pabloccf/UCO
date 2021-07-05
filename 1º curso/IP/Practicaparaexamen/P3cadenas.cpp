#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
void convierte_a_mayusculas(string& cad){
	int s=cad.size();
	for(int i=0;i<s;i++){
		char c=cad[i];
		cad[i]=toupper(c);
	}
}
int main(){
	string cad;
	cout<<"Dime una frase en minuscula y te digo esa misma frase en mayuscula"<<endl;
	getline(cin,cad);
	convierte_a_mayusculas(cad);
	cout<<"Tu frase escrita en mayuscula es:"<<cad<<endl;
cin.ignore();
cin.get();
}

