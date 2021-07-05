#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    int v[n];
    std::cout<<"Introduzca el tamaño del vector: ";
    std::cin>>n;

    for (int i = 0; i < n; i++){
        std::cout<<"Introduzca v["<<i<<"]: ";
        std::cin>>v[i];
    }

    std::cout<<"Sorting..."<<std::endl;
    std::sort(v, v+n);

    std::cout<<"El vector ordenado es:"<<std::endl;
    for (int i = 0; i < n; i++){
        std::cout<<"v["<<i<<"]= "<<v[i]<<std::endl;
    }

    return 0;   
}