//dados.cc
//Cuerpo de los métodos de la clase Dados

#include <cstdlib>
#include <ctime>
#include <vector>
#include "dados.h"

using namespace std;

Dados::Dados(){
    srand(time(NULL));
    d1_=1;
    d2_=1;
    cont1_=0;
    cont2_=0;
    sum1_=0;
    sum2_=0;
    hist1=vector<int>(5,0);
    hist2=vector<int>(5,0);
}

void Dados::lanzamiento(){
    d1_=(rand()%6+1);
    d2_=(rand()%6+1);
    cont1_++;
    cont2_++;
    sum1_+=d1_;
    sum2_+=d2_;
    hist1.push_back(d1_);
    hist1.erase(hist1.begin());
    hist2.push_back(d2_);
    hist2.erase(hist2.begin());
}

int Dados::getDado1(){
    return d1_;
}

int Dados::getDado2(){
    return d2_;
}

int Dados::getSuma(){
    return (d1_+d2_);
}

bool Dados::setDado1(int nd1){
    if(nd1<0 || nd1>6){
        return false;
    }
    d1_=nd1;
    cont1_++;
    sum1_+=nd1;
    hist1.push_back(d1_);
    hist1.erase(hist1.begin());
    return true;
    
}

bool Dados::setDado2(int nd2){
    if(nd2<0 || nd2>6){
        return false;
    }
    d2_=nd2;
    cont2_++;
    sum2_+=nd2;
    hist2.push_back(d2_);
    hist2.erase(hist2.begin());
    return true;
}

int Dados::getLanzamientos1(){
    return cont1_;
}

int Dados::getLanzamientos2(){
    return cont2_;
}

float Dados::getMedia1(){
    if(cont1_==0){
        return 0;
    }
    return (float)sum1_/cont1_;
}

float Dados::getMedia2(){
    if(cont2_==0){
        return 0;
    }
    return (float)sum2_/cont2_;
}

void Dados::getUltimos1(int v[]){
    for(int i=0;i<5;i++){
        v[i]=hist1[hist1.size()-1-i];  //Mete en v[] los elementos de hist en orden inverso
    }
}

void Dados::getUltimos2(int v[]){
    for(int i=0;i<5;i++){
        v[i]=hist2[hist2.size()-1-i];  //Mete en v[] los elementos de hist en orden inverso
    }
}

