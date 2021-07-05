#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	int a;
	cout<<"Introduce un numero y te digo si corresponde con un dia laborable o de fin de semana"<<endl;
	cin>>a;
	if((a>=1)&&(a<=5)){
		cout<<"Ese dia es un dia laborable"<<endl;
	}
	if((a>=6)&&(a<=7)){
		cout<<"Ese es un dia de fin de semana"<<endl;
	}
	if((a<1)||(a>7)){
		cout<<"Error, ese numero no corresponde con un dia laborable ni de fin de semana"<<endl;
		cin.ignore();
		cin.get();
		exit(-1);
	}
cin.ignore();
cin.get();
}

