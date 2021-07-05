#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "ruleta.h"

bool Ruleta::addJugador(Jugador jugador){
    for(const Jugador &j: jugadores_){
        if(j.getDNI()==jugador.getDNI()){
            return false;
        }
    }

    jugadores_.push_back(jugador);

    std::ifstream file(jugador.getDNI()+".txt");
    if(!file){
        std::ofstream ofile(jugador.getDNI()+".txt");
        ofile.close();
    }

    file.close();
    return true;
}

int Ruleta::deleteJugador(std::string dni){
    if(jugadores_.empty()){
        return -1;
    }
    for(auto it=jugadores_.begin();it!=jugadores_.end();it++){
        if(it->getDNI()==dni){
            jugadores_.erase(it);
            return 1; //Jugador eliminado
        }
    }
    return -2; //Jugador no encontrado
}

int Ruleta::deleteJugador(Jugador jugador){
    if(jugadores_.empty()){
        return -1;
    }
    for(auto it=jugadores_.begin();it!=jugadores_.end();it++){
        if(it->getDNI()==jugador.getDNI()){
            jugadores_.erase(it);
            return 1;
        }
    }
    return -2;
}

void Ruleta::escribeJugadores(){
    std::ofstream file("jugadores.txt");

    if(file){
        for(Jugador j:jugadores_){
            file<<j.getDNI()<<','
                <<j.getCodigo()<<','
                <<j.getNombre()<<','
                <<j.getApellidos()<<','
                <<j.getDireccion()<<','
                <<j.getLocalidad()<<','
                <<j.getProvincia()<<','
                <<j.getPais()<<','
                <<j.getDinero()<<','
                <<std::endl;
        }

        file.close();
    }
}

void Ruleta::leeJugadores(){
    std::ifstream file("jugadores.txt");

    if(file){
        std::string dni;
        std::string codigo;
        std::string nombre;
        std::string apellidos;
        std::string direccion;
        std::string localidad;
        std::string provincia;
        std::string pais;
        std::string dinero;
        //Lee fichero
        while(getline(file,dni,',')){
            getline(file,codigo,',');
            getline(file,nombre,',');
            getline(file,apellidos,',');
            getline(file,direccion,',');
            getline(file,localidad,',');
            getline(file,provincia,',');
            getline(file,pais,',');
            getline(file,dinero,'\n');
            //Construye un jugador
            Jugador aux=Jugador(dni,codigo,nombre,apellidos,0,direccion,localidad,provincia,pais);
            aux.setDinero(stoi(dinero));

            jugadores_.push_back(aux);
        }

        file.close();
    }
}

std::string Ruleta::getColor(int bola){
    if (bola>=1 && bola<=10){
        if (bola%2==0){
            return "negro";
        }
        else{
            return "rojo";
        }
    }

    else if(bola>=11 && bola<=18){
        if (bola%2==0){
            return "rojo";
        }
        else{
            return "negro";
        }
    }
    
    else if(bola>=19 && bola<=28){
        if (bola%2==0){
            return "negro";
        }
        else{
            return "rojo";
        }
    }

    else if(bola>=29 && bola<=36){
        if (bola%2==0){
            return "rojo";
        }
        else{
            return "negro";
        }
    }
    
    else{
        return "error";
    }
}

void Ruleta::getPremios(){
    std::list<Apuesta> apuestas;
    for(Jugador& j:jugadores_){
        j.setApuestas();
        apuestas=j.getApuestas();

        for(Apuesta a:apuestas){
            switch (a.tipo){
            case 1: //Numero de apuesta
                if (stoi(a.valor)==bola_){
                    j.setDinero(j.getDinero()+35*a.cantidad);
                    banca_-=35*a.cantidad;
                }

                else{
                    j.setDinero(j.getDinero()-a.cantidad);
                    banca_+=a.cantidad;
                }
                
                break;
            
            case 2: //Color apuesta
                if (a.valor==getColor(bola_)){
                    j.setDinero(j.getDinero()+a.cantidad);
                    banca_-=a.cantidad;
                }

                else{
                    j.setDinero(j.getDinero()-a.cantidad);
                    banca_+=a.cantidad;
                }
            
                break;
                
            case 3: //Apuesta de paridad
                if (bola_==0){
                    j.setDinero(j.getDinero()-a.cantidad);
                    banca_+=a.cantidad;
                }

                else{
                    if (a.valor=="par" && bola_%2==0){
                        j.setDinero(j.getDinero()+a.cantidad);
                        banca_-=a.cantidad;
                    }
                    else if(a.valor=="impar" && bola_%2==1){
                        j.setDinero(j.getDinero()+a.cantidad);
                        banca_-=a.cantidad;
                    }
                    else{
                        j.setDinero(j.getDinero()-a.cantidad);
                        banca_+=a.cantidad;
                    }
                }
                
                break;

            case 4: //Apuesta alta/baja
                if (bola_==0){
                    j.setDinero(j.getDinero()-a.cantidad);
                    banca_+=a.cantidad;
                }

                else{
                    if (a.valor=="alto" && bola_>=19){
                        j.setDinero(j.getDinero()+a.cantidad);
                        banca_-=a.cantidad;
                    }
                    else if(a.valor=="bajo" && bola_<=18){
                        j.setDinero(j.getDinero()+a.cantidad);
                        banca_-=a.cantidad;
                    }
                    else{
                        j.setDinero(j.getDinero()-a.cantidad);
                        banca_+=a.cantidad;
                    }            
                }
                 
                break;
            }
        }
    }
}