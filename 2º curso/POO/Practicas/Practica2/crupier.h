#ifndef CRUPIER_H
#define CRUPIER_H

#include <string>
#include "persona.h"


class Crupier:public Persona{
    private:
        std::string codigo_;
    
    public:
        Crupier(std::string dni, std::string codigo, std::string nombre="", std::string apellidos="", int edad=0, std::string direccion="", std::string localidad="", std::string provincia="", std::string pais="")
            :Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais){
                codigo_=codigo;
            }

        inline std::string getCodigo(){
            return codigo_;
        }
        inline void setCodigo(std::string codigo){
            codigo_=codigo;
        }
};

#endif