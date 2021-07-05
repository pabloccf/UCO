#include <iostream>

#include <vector>

int main () {
    //Declaracion    
    std::vector<int> v; //equivalente a "int v[];"
    std::vector<int> v1(10); //equivalente a "int v1[10];"
    std::vector<int> v2(10, 5); //equivalente a "int v2[10] = { 5, ..., 5 }; "
    std::vector<int> v3 = { 1, 2, 3, 4 };  //equivalente "int v3[] = { 1, 2, 3, 4 };"

    //Recorrer
    for (int i = 0; i < v.size(); i++) { //Normal
        std::cout << v[i] << std::endl;
    }

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) { //Iteradores
        std::cout << *it << std::endl;
    }
    //Nota: auto adivina el tipo que es
    for (auto it = v.begin(); it != v.end(); it++) { //Iteradores
        std::cout << *it << std::endl;
    }

    for (int x : v) { //foreach (para cada int x en v)
        std::cout << x << std::endl;
    }

    //Funciones
    v.push_back(2); //Inserta un 2 por detras (AMPLIA EL VECTOR)
    v.pop_back(); //Saca el ultimo elemento del vector (por detras) (REDUCE EL TAMAÑO DEL VECTOR)
    v.insert(v.begin(), 2); //Inserta un 2 al principio (AMPLIA EL VECTOR)
    v[0] = 4;
    v.erase(v.end()); //Borra el elemento al que apunte el iterador

    v.empty(); //Me devuelve un bool que me dice si el vector esta vacio (no tiene elementos)
    v.clear(); //Borra todos los elementos del vector


    return 0;
}