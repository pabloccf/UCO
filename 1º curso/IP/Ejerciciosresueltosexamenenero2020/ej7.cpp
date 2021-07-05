#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
float string_calc(string val1,string val2,int op){
	float a=stof(val1);
	float b=stof(val2);
	if(op==1){
		return a+b;
	}
	else if(op==2){
		return a*b;
	}
}

