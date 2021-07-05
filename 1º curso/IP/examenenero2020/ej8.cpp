#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
struct Punto{
	int x,y;
};
Punto punto_medio(Punto a,Punto b){
	Punto res;
	res.x=(a.x+b.x)/2;
	res.y=(a.y+b.y)/2;
	return res;
}

