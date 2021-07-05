#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

double derivada(double (*func)(double,double x)){
    double h=0.0001;
    double res=(func(x+h)-func(x))/h;
    return res;
}