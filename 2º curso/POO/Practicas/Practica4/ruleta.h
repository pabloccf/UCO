#ifndef RULETA_H
#define RULETA_H

#include <vector>
#include <string>
#include <list>
#include "jugador.h"
#include "crupier.h"

//Representa una ruleta
class Ruleta{
    private:
        int banca_;
        int bola_;
        std::list<Jugador> jugadores_;
        Crupier crupier_;

        std::string getColor(int bola);

        int lanzamientos_;
    
    public:
        Ruleta(Crupier crupier):crupier_(crupier){ //Constructor
            srand(time(NULL));
            bola_=-1;
            banca_=1000000;
            lanzamientos_=0;
        }

        inline int getBanca(){ //Devuelve el dinero que tiene la banca
            return banca_;
        }
        inline bool setBanca(int banca){ //Asigna un valor a la banca, solo se admiten valores positivos. Devuelve true si el valor es válido y false en caso contrario.
            if(banca>0){
                banca_=banca;
                return true;
            }
            return false;
        }

        inline int getBola(){ //Devuelve el valor actual de la bola
            return bola_;
        }
        inline bool setBola(int bola){ //Asigna un valor a la bola, solo se admiten valores entre 0 y 36 incluidos. Devuelve true si el valor es válido y false en caso contrario.
            if(bola>=0 && bola<=36){
                bola_=bola;
                lanzamientos_++;
                return true;
            }
            return false;
        }

        inline Crupier getCrupier(){ //Devuelve el Objeto del crupier
            return crupier_;
        }
        inline void setCrupier(Crupier crupier){ //Asigna el parámetro al crupier
            crupier_=crupier;
        }

        inline std::list<Jugador> getJugadores(){ //Devuelve la lista de jugadores
            return jugadores_;
        }
        bool addJugador(Jugador jugador); //Añade un jugador a la lista
        int deleteJugador(std::string dni); //Elimina un jugador de la lista por dni
        int deleteJugador(Jugador jugador); //Elimina un jugador de la lista por Objeto
        void escribeJugadores(); //Guarda la lista de jugadores
        void leeJugadores(); //Carga la lista de jugadores
        
        inline void giraRuleta(){ //Asigna un valor aleatorio a la bola
            bola_=rand()%37;
            lanzamientos_++;
        }

        void getPremios(); //Actualiza el dinero de los jugadores en función de las apuestas que se hayan realizado
        void getEstadoRuleta(int &jugadores, int &dinero, int &lanzamiento, int &beneficio) const;
};

#endif