#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <errno.h>

int v[3]={0, 0, 0};
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

void* aleatorio(){
    int valor=rand()%10;
    printf("Hilo %lu, valor aleatorio a sumar: %d\n", pthread_self(), valor);

    int posicion=rand()%3;
    printf("Hilo %lu, posicion aleatoria del vector: %d\n", pthread_self(), posicion);

    if(pthread_mutex_lock(&mutex)){
        fprintf(stderr, "Error al bloquear el mutex. Errno value: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    v[posicion] += valor;

    if(pthread_mutex_unlock(&mutex)){
        fprintf(stderr, "Error al desbloquear el mutex. Errno value: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    pthread_exit(NULL);
}

int main(int argc, const char* argv[]){
    if(argc<2){
        fprintf(stderr, "Error, numero de argumentos no validos. Dime el numero de hilos que tengo que crear\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    const int nhilos=atoi(argv[1]);
    pthread_t hilos[nhilos];

    printf("Proceso principal, mostrando el vector inicial: \n");
    for(int i=0; i<3; i++){
        printf("v[%d] = %d ", i, v[i]);
    }

    printf("\n");

    for(int i=0; i<nhilos; i++){
        if(pthread_create(&hilos[i], NULL, aleatorio, NULL)){
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
        printf("v[%d] = %d ", i, v[i]);
    }

    printf("\n");
}