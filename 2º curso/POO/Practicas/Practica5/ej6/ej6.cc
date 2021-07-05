#include <iostream>

template<class type>

void imprimeVector(type v[], int t){
    for (int i = 0; i < t; i++){
        std::cout<<v[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    int v[10]={1, 2, 3, 4, 3, 6, 7, 8, 9, 77};
    float i[3]={4.5, 10.25, 1.4};
    char a[6]="Pablo";

    imprimeVector(v, 10);
    imprimeVector(i, 3);
    imprimeVector(a, 5);

    return 0;
}