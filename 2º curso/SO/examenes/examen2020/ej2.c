#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

int par=0;
int impar=0;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

void* aleatorio(int* n){
    int* indicelocal=n;
    int* suma=malloc(sizeof(int*));
    *suma=0;

    for(int i=0; i<100; i++){
        int x=rand()%11;
        *suma += x;
    }

        if(pthread_mutex_lock(&mutex)){
            fprintf(stderr, "Error al bloquear el mutex. Errno value: %d\n", errno);
            exit(EXIT_FAILURE);
        }

        printf("Soy la hebra %lu con indice %d\n", pthread_self(), *indicelocal);
        printf("El valor de la suma en %d es: %d\n", *indicelocal, *suma);

        if(*indicelocal%2==0){
            par += *suma;
        }

        else{
            impar += *suma;
        }

        if(pthread_mutex_unlock(&mutex)){
            fprintf(stderr, "Error al desbloquear el mutex. Errno value: %d\n", errno);
            exit(EXIT_FAILURE);
        }

    pthread_exit((void*) suma);
}

int main(int argc, const char* argv[]){
    if(argc<2){
        fprintf(stderr, "Error, numero de argumentos no valido. Debe de introducir el numero de hilos a crear\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    int nhilos=atoi(argv[1]);
    pthread_t hilos[nhilos];
    int* resultado;
    int indiceglobal[nhilos];

    for(int i=0; i<nhilos; i++){
        indiceglobal[i]= i+1;
        if(pthread_create(&hilos[i], NULL, (void*) aleatorio, (void*) &indiceglobal[i])){
            fprintf(stderr, "Error al crear la hebra. Errno value: %d\n", errno);
            exit(EXIT_FAILURE);
        }
    }

    for(int i=0; i<nhilos; i++){
        if(pthread_join(hilos[i], (void**) &resultado)){
            fprintf(stderr, "Error al recoger a la hebra. Errno value: %d\n", errno);
            exit(EXIT_FAILURE);
        }
    }

    printf("El valor de la variable par es: %d\n", par);
    printf("El valor de la variable impar es: %d\n", impar);

    exit(EXIT_SUCCESS);
}