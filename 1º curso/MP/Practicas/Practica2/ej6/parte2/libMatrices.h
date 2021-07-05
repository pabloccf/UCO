#ifndef LIBMATRICES_H
#define LIBMATRICES_H
int** reservarMemoria(int nfil,int ncol);
void rellenaMatriz(int** matriz,int nfil,int ncol);
void imprimeMatriz(int** matriz,int nfil,int ncol);
void liberarMemoria(int*** matriz,int nfil);
#endif