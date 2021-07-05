#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
float string_calc(string val1,string val2,int op){
	float a=stof(val1);
	float b=stof(val2);
	switch(op){
		case 1:{
			return a+b;
		}break;
		case 2:{
			return a*b;
		}break;
	}
}
