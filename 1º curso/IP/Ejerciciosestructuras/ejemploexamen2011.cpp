#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
struct Punto{
	float x,y;
};
float distancia(Punto a,Punto b){
	return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
Punto puntomedio(Punto a,Punto b){
	Punto res;
	res.x=(a.x+b.x)/2;
	res.y=(a.y+b.y)/2;
	return res;
}

