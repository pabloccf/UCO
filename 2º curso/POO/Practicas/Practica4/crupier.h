#ifndef CRUPIER_H
#define CRUPIER_H

#include <string>
#include "persona.h"

//Representa un crupier
class Crupier:public Persona{
    private:
        std::string codigo_;
    
    public:
        Crupier(const std::string &dni, const std::string &codigo, const std::string &nombre="", const std::string &apellidos="", int edad=0, const std::string &direccion="", const std::string &localidad="", const std::string &provincia="", const std::string &pais="")
            :Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais){ //Constructor
                codigo_=codigo;
            }

        inline std::string getCodigo(){ //Devuelve el código del crupier
            return codigo_;
        }
        inline void setCodigo( const std::string &codigo){ //Asigna el código del crupier
            codigo_=codigo;
        }
};

#endif