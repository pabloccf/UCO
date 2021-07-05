#include <iostream>
#include <vector>
#include <algorithm>

bool descendente(int i, int j){
    return i>j;
}

bool ascendente(int i, int j){
    return j>i;
}

int main(){
    int n;
    std::cout<<"Introduzca el tamaño del vector: ";
    std::cin>>n;
    std::vector<int> v(n);

    for (int i = 0; i < v.size(); i++){
        std::cout<<"Introduzca v["<<i<<"]: ";
        std::cin>>v[i];
    }

    int opcion;
    std::cout<<"¿Como desea ordenar el vector? Introduzca 0 para ordenarlo de manera ascendente y 1 para ordenarlo de manera descendente: ";
    std::cin>>opcion;

    if(opcion==0){
        std::sort(v.begin(), v.end());

        std::cout<<"El vector ordenado de manera ascendente es:"<<std::endl;
        for (int i = 0; i < v.size(); i++){
            std::cout<<"v["<<i<<"]= "<<v[i]<<std::endl;
        }
    }

    else if(opcion==1){
        std::sort(v.begin(), v.end(), descendente);

        std::cout<<"El vector ordenado de manera descendente es:"<<std::endl;
        for (int i = 0; i < v.size(); i++){
            std::cout<<"v["<<i<<"]= "<<v[i]<<std::endl;
        }
    }
    
    return 0;
}