#ifndef FUNCIONES4_H
#define FUNCIONES4_H
int** reservarMemoria(int nfil,int ncol);
void rellenaMatriz(int** matriz,int nfil,int ncol);
void imprimeMatriz(int** matriz,int nfil,int ncol);
int* minCol(int** matriz,int nfil,int ncol);
void liberarMemoria(int*** matriz,int nfil);
#endif