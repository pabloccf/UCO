#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "jugador.h"

bool ascendente(Jugador j1, Jugador j2){
    int dni1=std::stoi(j1.getDNI().substr(0, 8));
    int dni2=std::stoi(j2.getDNI().substr(0, 8));

    return j1.getDNI()<j2.getDNI();
}

bool descendente(Jugador j1, Jugador j2){
    int dni1=std::stoi(j1.getDNI().substr(0, 8));
    int dni2=std::stoi(j2.getDNI().substr(0, 8));

    return j1.getDNI()>j2.getDNI();
}

void crearJugadores(std::vector<Jugador> &v, size_t n){
    for (size_t i = 0; i < n; i++){
        std::string dni=std::to_string(rand() % 100000000) + "X";
        std::string codigo=("c"+i);

        v.push_back(Jugador(dni, codigo));
    }
}

int main(){
    srand(time(NULL));
    std::vector<Jugador> jugadores;
    crearJugadores(jugadores, 5);

    std::cout<<"Los DNIs del vector de jugadores: "<<std::endl;
    for (auto i = jugadores.begin(); i != jugadores.end(); i++){
        std::cout<<i->getDNI()<<std::endl;
    }

    int op;
    std::cout<<"¿Como desea ordenar el vector? Introduzca 0 para ordenarlo de manera ascendente y 1 para ordenarlo de manera descendente: ";
    std::cin>>op;

    if(op==0){
        std::sort(jugadores.begin(), jugadores.end(), ascendente);
        std::cout<<"El vector de jugadores ordenado de manera ascendente es:"<<std::endl;
        for (int i = 0; i < (int) jugadores.size(); i++){
            std::cout<<jugadores[i].getDNI()<<std::endl;
        }
    }

    else if(op==1){
        std::sort(jugadores.begin(), jugadores.end(), descendente);
        std::cout<<"El vector de jugadores ordenado de manera descendente es:"<<std::endl;
        for (int i = 0; i < (int) jugadores.size(); i++){
            std::cout<<jugadores[i].getDNI()<<std::endl;
        }
    }

    return 0;
}


