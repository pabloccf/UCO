#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int espar(int v) {
    float res;
    if(v%2==0) {
        res=1;
    }
    else {
        res=0;
    }
    return res;
}
int main() {
    int a;
    cout<<"Introduce un numero y te dire si es par o no"<<endl;
    cin>>a;
    if(espar(a)==1) {
        cout<<"El valor introducido es par"<<endl;
    }
    else {
        cout<<"El valor introducido no es par"<<endl;
    }
    cin.ignore();
    cin.get();
}

