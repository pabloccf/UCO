#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <string.h>

int vector[3]={0, 0, 0};

pthread_mutex_t semaforo=PTHREAD_MUTEX_INITIALIZER;

void* funcion(){
    int valor_aleatorio=rand()%10;
    int posicion_aleatoria=rand()%3;

    printf("Hilo %lu, valor aleatorio a sumar: %d\n", pthread_self(), valor_aleatorio);
    printf("Hilo %lu, posicion aleatoria del vector: %d\n", pthread_self(), posicion_aleatoria);

    pthread_mutex_lock(&semaforo);
    vector[posicion_aleatoria]=vector[posicion_aleatoria]+valor_aleatorio;
    pthread_mutex_unlock(&semaforo);

    pthread_exit(NULL);
}

int main(int argc, const char* argv[]){
    if(argc<2){
        fprintf(stderr, "Error, numero de argumentos no validos. Dime el numero de hilos que tengo que crear\n");
        exit(EXIT_FAILURE);
    }

    const int nhilos=atoi(argv[1]);
    pthread_t hilos[nhilos];
    srand(time(NULL));

    printf("Proceso principal, mostrando el vector inicial: \n");
    for (int i = 0; i < 3; i++){
        printf("v[%d]= %d ", i, vector[i]);
    }
    printf("\n");

    for(int i=0; i<nhilos; i++){
        if(pthread_create(&hilos[i], NULL, funcion, NULL)){
            fprintf(stderr, "Error creando la hebra. Errno value: %d\n", errno);
            exit(EXIT_FAILURE);
        }
    }

    for(int i=0; i<nhilos; i++){
        if(pthread_join(hilos[i], NULL)){
            fprintf(stderr, "Error recogiendo la hebra. Errno value: %d\n", errno);
            exit(EXIT_FAILURE);
        }
    }

    printf("Proceso principal, mostrando el vector final: \n");
    for (int i = 0; i < 3; i++){
        printf("v[%d]= %d ", i, vector[i]);
    }
    printf("\n");
}