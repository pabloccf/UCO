#ifndef FUNCIONES3_H
#define FUNCIONES3_H
struct Ficha_jugador{
	char nombre[50];//Si nombre es NULL se considera borrado
	int dorsal;
	float peso;
	int estatura;
};
void leerjugador(struct Ficha_jugador* a);//Lo pasamos por referencia
void imprimirjugador(struct Ficha_jugador a);
int borrarjugadores(struct Ficha_jugador* v,int n,char c);
#endif