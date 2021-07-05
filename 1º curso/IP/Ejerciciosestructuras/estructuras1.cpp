/* Enunciado: 
 * Cree una estructura "Rectangulo" que contenga dos valores reales "w" (width) y "h" (height)
 * Codifique una función "area" que reciba un Rectangulo como parámetro y devuelva el área del rectángulo
 */

#include <iostream>
#include <cmath>

//Escriba aqui su codigo

//NO MODIFIQUE NADA A PARTIR DE AQUI
int main () {
    Rectangulo rects[] = {
        {10, 20},
        {1.5, 1},
        {2.4, 5.3}
    };

    if (fabs(area(rects[0]) - 200) < 0.001)   { std::cout << "test 1 correcto"    << std::endl; }
    else                                      { std::cout << "ERROR en el test 1" << std::endl; }

    if (fabs(area(rects[1]) - 1.5) < 0.001)   { std::cout << "test 2 correcto"    << std::endl; }
    else                                      { std::cout << "ERROR en el test 2" << std::endl; }

    if (fabs(area(rects[2]) - 12.72) < 0.001) { std::cout << "test 3 correcto"    << std::endl; }
    else                                      { std::cout << "ERROR en el test 3" << std::endl; }
}

