#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
bool esprimo(int v) {
    int suma=0;
    for(int i=1; i<=v; i++) {
        if(v%i==0) {
            suma++;
        }
	}
        if(suma<=2) {
            return true;
        }
        else {
            return false;
        }
}
int main() {
    int n;
    cout<<"Introduce un numero y te digo si es primo o no"<<endl;
    cin>>n;
    if(esprimo(n)==true) {
        cout<<"El numero introducido es primo"<<endl;
    }
    else{
        cout<<"El numero introducido no es primo"<<endl;
    }
    cin.ignore();
    cin.get();
}

