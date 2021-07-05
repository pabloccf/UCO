#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

double integral(double (*func)(double),double init,double end){
    int n=20;
    double x=end-init;
    double step=x/n;

    double sum=0;
    for (double i = 0; i < n; i++){
        sum+=2*func(init+i*step);
    }

    double res=step/2*(func(init)+sum+func(end));
    return res;
    
}