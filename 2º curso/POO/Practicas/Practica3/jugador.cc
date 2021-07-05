#include <iostream>
#include <fstream>
#include <list>
#include <string>

#include "jugador.h"

void Jugador::setApuestas(){
    std::string filename=getDNI()+".txt";
    std::ifstream f(filename);
    
    if (f) {
        apuestas_.clear();

        Apuesta aux;
        std::string tipo, valor, cantidad;
        while (getline(f, tipo, ',')) {
            getline(f, valor, ',');
            getline(f, cantidad, '\n');

            aux.tipo = std::stoi(tipo);
            aux.valor = valor;
            aux.cantidad = std::stoi(cantidad);

            apuestas_.push_back(aux);
        }
    }
    else {
        std::cerr << "ERROR: No se pudo abrir el archivo " << filename << std::endl;
    }

    f.close();
}