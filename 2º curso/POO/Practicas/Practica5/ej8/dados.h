//dados.h

#ifndef DADOS_H
#define DADOS_H

#include <vector>

//La clase dados representa el lanzamiento de 2 dados
class Dados{
    private:
        int d1_;
        int d2_;
        int cont1_;
        int cont2_;
        int sum1_;
        int sum2_;
        std::vector<int> hist1;
        std::vector<int> hist2;

    public:
        Dados(); //el constructor no devuelve nada

        void lanzamiento(); //Asigna un numero aleatorio a cada dado

        int getDado1(); //el método devuelve el valor del primer dado

        int getDado2(); //el método devuelve el valor del segundo dado

        bool setDado1(int nd1); //Asigna el parámetro al primer dado

        bool setDado2(int nd2); //Asigna el parámetro al segundo dado

        int getSuma(); //Devuelve la suma de los dos dados

        int getLanzamientos1(); //Devuelve la cantidad de veces que se ha lanzado el primer dado

        int getLanzamientos2(); //Devuelve la cantidad de veces que se ha lanzado el segundo dado

        float getMedia1(); //Devuelve la media de los valores obtenidos en los lanzamientos del primer dado

        float getMedia2(); //Devuelve la media de los valores obtenidos en los lanzamientos del segundo dado

        void getUltimos1(int v[]); //Rellena el vector con los últimos 5 valores del dado 1

        void getUltimos2(int v[]); //Rellena el vector con los últimos 5 valores del dado 2

        void insertador();
        
        void extractor();
};

#endif