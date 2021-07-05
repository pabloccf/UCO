#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int factorial(int v){
	int fact=1;
		for(int i=1;i<=v;i++){
		fact=fact*i;
		}
		return fact;
}
int main(){
	int n;
	cout<<"Introduce un numero y te dire su factorial"<<endl;
	cin>>n;
	cout<<"El factorial de "<<n<<" es "<<factorial(n)<<endl;
cin.ignore();
cin.get();
}

