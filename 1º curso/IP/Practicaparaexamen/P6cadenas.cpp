#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
string concatena(string a,string b){
	string c=a+b;
	return c;
}
int main(){
	string a;
	string b;
	cout<<"Introduce dos frases y te la escribo unidas"<<endl;
	cout<<endl;
	cout<<"Dime una frase"<<endl;
	getline(cin,a);
	cout<<"Dime una segunda frase y te la escribo seguido de la primera"<<endl;
	getline(cin,b);
	cout<<"La frase resultante es: "<<concatena(a,b)<<endl;
cin.ignore();
cin.get();
}

