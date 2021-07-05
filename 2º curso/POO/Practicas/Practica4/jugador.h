#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <list>
#include "persona.h"

//Representa una apuesta 
struct Apuesta{
    int tipo;
    std::string valor;
    int cantidad;
};

//Representa un jugador
class Jugador:public Persona{
    private:
        int dinero_;
        std::string codigo_;
        std::list<Apuesta> apuestas_;
    
    public:
        Jugador(std::string dni, std::string codigo, std:: string nombre="", std::string apellidos="", int edad=0, std::string direccion="", std::string localidad="", std::string provincia="", std::string pais="")
            :Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais){ //Constructor
                codigo_=codigo;
                dinero_=1000;
            };
        
        inline std::string getCodigo(){ //Devuelve el código del jugador
            return codigo_;
        }
        inline void setCodigo(std::string codigo){ //Asigna un código al jugador
            codigo_=codigo;
        }

        inline int getDinero(){ //Devuelve el dinero del jugador
            return dinero_;
        }
        inline void setDinero(int dinero){ //Asigna el dinero del jugador
            dinero_=dinero;
        }

        inline std::list<Apuesta> getApuestas(){ //Devuelve una lista de apuestas del jugador
            return apuestas_;
        }
        void setApuestas(); //Lee las apuestas del jugador desde su fichero
};

#endif