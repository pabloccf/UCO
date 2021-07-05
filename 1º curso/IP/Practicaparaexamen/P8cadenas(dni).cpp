#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
void dniisvalid(string cad){
	for(int i=0;i<9;i++){
		if(cad.size()>9){
			cout<<"ERROR. El dni tiene que tener 9 caracteres"<<endl;
		}
	}
	for(int i=0;i<8;i++){
		if(!isdigit(cad[i])){
			cout<<"ERROR. Los 8 primeros caracteres tienen que ser numeros"<<endl;
		}
	}
	cad[8]=toupper(cad[8]);
	int numero=stoi(cad);
	char letras[]="TRWAGMYFPDXBNJZSQVHLCKE";
	char letra=letras[numero%23];
	if(cad[8]!=letra){
		cout<<"ERROR, la letra no se corresponde con el dni"<<endl;
	}
	cout<<"Correcto"<<endl;
}
int main(){
	string cad;
	cout<<"Introduce tu dni"<<endl;
	getline(cin,cad);
	dniisvalid(cad);
cin.ignore();
cin.get();
}

