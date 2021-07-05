#ifndef FUNCIONES2_H
#define FUNCIONES2_H
//Nota: Ref.= argumento pasado por referencia
void dividir(int* v,				//vector de numeros
			int n,					//tamaño del vector
			int num,				//numero que usamos para comparar si es mayor o menor
			int** mayores,			//Ref. vector con los numeros mayores
			int* nMayor,			//Ref. size del vector de mayores
			int** menores,			//Ref. vector con los numeros menores
			int* nMenor);			//Ref. size del vector de menores

#endif