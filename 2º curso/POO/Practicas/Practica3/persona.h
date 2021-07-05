#ifndef PERSONA_H
#define PERSONA_H
#include <string>

using namespace std;

//Representa una persona
class Persona{
    private:
        string dni_, 
               nombre_,
               apellidos_,
               direccion_,
               localidad_,
               provincia_,
               pais_;
        int edad_;
    
    public:
        Persona(string dni,string nombre="",string apellidos="",int edad=0,string direccion="",string localidad="",string provincia="",string pais=""); //Constructor
        inline string getDNI() const { //Devuelve el dni de la persona
            return dni_;
        }
        inline void setDNI(string dni){ //Asigna el dni de la persona
            dni_=dni;
        }    

        inline string getNombre() const { //Devuelve el nombre de la persona
            return nombre_;
        }
        inline void setNombre(string nombre){ //Asigna el nombre de la persona
            nombre_=nombre;
        }

        inline string getApellidos() const { //Devuelve los apellidos de la persona
            return apellidos_;
        }
        inline void setApellidos(string apellidos){ //Asigna los apellidos de la persona
            apellidos_=apellidos;
        }

        inline string getDireccion() const { //Devuelve la dirección de la persona
            return direccion_;
        }
        inline void setDireccion(string direccion){ //Asigna la dirección de la persona
            direccion_=direccion;
        }

        inline string getLocalidad() const { //Devuelve la localidad de la persona
            return localidad_;
        }
        inline void setLocalidad(string localidad){ //Asigna la localidad de la persona
            localidad_=localidad;
        }

        inline string getProvincia() const {  //Devuelve la provincia de la persona
            return provincia_;
        }
        inline void setProvincia(string provincia){ //Asigna la provincia de la persona
            provincia_=provincia;
        }

        inline string getPais() const { //Devuelve el pais de la persona
            return pais_;
        }
        inline void setPais(string pais){ //Asigna el pais de la persona
            pais_=pais;
        }

        inline int getEdad() const { //Devuelve la edad de la persona
            return edad_;
        }
        bool setEdad(int edad); //Modifica la edad y comprueba que sea mayor que 0


        inline string getApellidosyNombre(){ //Devuelve una cadena con el nombre y los apellidos concatenados
            return(apellidos_+", "+nombre_);
        }

        inline bool mayor(){ //Devuelve si es mayor de edad o no
            return(edad_>=18);
        }
};

#endif