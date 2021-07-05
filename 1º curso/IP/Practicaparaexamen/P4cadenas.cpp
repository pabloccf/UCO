#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int vocales(string cad){
	int count=0,s=cad.size();
	for(int i=0;i<s;i++){
		if(cad[i]=='a'){count++;}
			else if(cad[i]=='e'){count++;}
				else if(cad[i]=='i'){count++;}
					else if(cad[i]=='o'){count++;}
						else if(cad[i]=='u'){count++;}
	}
	return count;
}
int main(){
	string cad;
	cout<<"Dime una frase y te digo el numero de vocales que tiene"<<endl;
	getline(cin,cad);
	cout<<"Tu frase tiene "<<vocales(cad)<<" vocales"<<endl;
cin.ignore();
cin.get();
}

