#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <list>
#include "persona.h"

struct Apuesta{
    int tipo;
    std::string valor;
    int cantidad;
};

class Jugador:public Persona{
    private:
        int dinero_;
        std::string codigo_;
        std::list<Apuesta> apuestas_;
    
    public:
        Jugador(std::string dni, std::string codigo, std:: string nombre="", std::string apellidos="", int edad=0, std::string direccion="", std::string localidad="", std::string provincia="", std::string pais="")
            :Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais){
                codigo_=codigo;
                dinero_=1000;
            };
        
        inline std::string getCodigo(){
            return codigo_;
        }
        inline void setCodigo(std::string codigo){
            codigo_=codigo;
        }

        inline int getDinero(){
            return dinero_;
        }
        inline void setDinero(int dinero){
            dinero_=dinero;
        }

        inline std::list<Apuesta> getApuestas(){
            return apuestas_;
        }
        void setApuestas();
};

#endif