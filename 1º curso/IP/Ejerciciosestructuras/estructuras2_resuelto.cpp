/* Enunciado: 
 * Cree una estructura "Punto" que contenga dos valores reales "x" e "y"
 * Codifique una función "distancia" que reciba dos puntos como parámetro y devuelva la distancia entre ambos
 */

#include <iostream>
#include <cmath>

//Escriba aqui su codigo
struct Punto {
    float x, y;
};

float distancia (Punto a, Punto b) {
    return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}

//NO MODIFIQUE NADA A PARTIR DE AQUI
int main () {
    Punto points[] = {
        {10, 20},   {10, 40},
        {1.5, 1},   {2.4, 4},
        {2.4, 5.3}, {10.8, 6.9}
    };

    if (fabs(distancia(points[0], points[1]) - 20) < 0.001) { std::cout << "test 1 correcto" << std::endl; }
    else { std::cout << "ERROR en el test 1" << std::endl; }

    if (fabs(distancia(points[2], points[3]) - 3.13209) < 0.001) { std::cout << "test 2 correcto" << std::endl; }
    else { std::cout << "ERROR en el test 2" << std::endl; }

    if (fabs(distancia(points[4], points[5]) - 8.55102) < 0.001) { std::cout << "test 3 correcto" << std::endl; }
    else { std::cout << "ERROR en el test 3" << std::endl; }
}