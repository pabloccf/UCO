#ifndef PERSONA_H
#define PERSONA_H
#include <string>

using namespace std;

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
        Persona(string dni,string nombre="",string apellidos="",int edad=0,string direccion="",string localidad="",string provincia="",string pais="");
        inline string getDNI() const {
            return dni_;
        }
        inline void setDNI(string dni){
            dni_=dni;
        }    

        inline string getNombre() const {
            return nombre_;
        }
        inline void setNombre(string nombre){
            nombre_=nombre;
        }

        inline string getApellidos() const {
            return apellidos_;
        }
        inline void setApellidos(string apellidos){
            apellidos_=apellidos;
        }

        inline string getDireccion() const {
            return direccion_;
        }
        inline void setDireccion(string direccion){
            direccion_=direccion;
        }

        inline string getLocalidad() const {
            return localidad_;
        }
        inline void setLocalidad(string localidad){
            localidad_=localidad;
        }

        inline string getProvincia() const {
            return provincia_;
        }
        inline void setProvincia(string provincia){
            provincia_=provincia;
        }

        inline string getPais() const {
            return pais_;
        }
        inline void setPais(string pais){
            pais_=pais;
        }

        inline int getEdad() const {
            return edad_;
        }
        bool setEdad(int edad);


        inline string getApellidosyNombre(){
            return(apellidos_+", "+nombre_);
        }

        inline bool mayor(){
            return(edad_>=18);
        }
};

#endif