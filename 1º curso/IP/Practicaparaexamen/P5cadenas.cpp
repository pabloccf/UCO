#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
void replace(string &cad,char a,char b){
	int s=cad.size();
	for(int i=0;i<s;i++){
		if(cad[i]==a){
			cad[i]=b;
		}
	}
	cout<<cad<<endl;
}
int main(){
	string cad;
	char a,b;
	cout<<"Escribe una frase y posteriormente las letras que quieres cambiar"<<endl;
	cout<<endl;
	cout<<"Escribe una frase"<<endl;
	getline(cin,cad);
	cout<<endl;
	cout<<"Dime una letra que quieres cambiar"<<endl;
	cin>>a;
	cout<<"Dime una segunda letra que quieras cambiar"<<endl;
	cin>>b;
	cout<<"La frase final es: "<<endl;
	replace(cad,a,b);
cin.ignore();
cin.get();
}

