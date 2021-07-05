#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define n 5

int v[n];
int indiceConsumicion=0;
int indiceProduccion=0;

sem_t mutex;
sem_t full;  //Semaforo que incrementara hasta valer 5
sem_t empty;  //Semaforo que decrementara hasta valer 0

void producirDato(int numero){  //Funcion para meter datos en el buffer
    v[indiceProduccion]=numero;
    indiceProduccion=(indiceProduccion + 1)%n;
    for (int i = 0; i < n; i++){
        printf("|%d", v[i]);
    }
    printf("|");
}

int consumirDato(){
    int numeroConsumido=v[indiceConsumicion];
    v[indiceConsumicion]='\0';
    indiceConsumicion=(indiceConsumicion + 1)%n;
    for (int i = 0; i < n; i++){
        printf("|%d", v[i]);
    }
    printf("|");
    
    return numeroConsumido;
}

void* productor(){
    for (int i = 0; i < 10; i++){
        sem_wait(&empty);
        sem_wait(&mutex);
        int numero=rand()%101;
        producirDato(numero);
        printf("---> Productor, Dato: %d: %d\n", i+1, numero);
        sem_post(&mutex);
        sem_post(&full);
    }

    pthread_exit(NULL);
}

void* consumidor(){
    for (int i = 0; i < 10; i++){
        sem_wait(&full);
        sem_wait(&mutex);
        int numero=consumirDato();
        printf("---> Consumidor, Dato: %d: %d\n", i+1, numero);
        sem_post(&mutex);
        sem_post(&empty);
    }
    
    pthread_exit(NULL);
}

int main(){
    srand(time(NULL));

    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, n);

    pthread_t threadProductor;
    pthread_t threadConsumidor;

    if(pthread_create(&threadProductor, NULL, productor, NULL)){
        fprintf(stderr, "Error en la creacion de la hebra de los productores.\n");
        exit(EXIT_FAILURE);
    }

    if(pthread_create(&threadConsumidor, NULL, consumidor, NULL)){
        fprintf(stderr, "Error en la creacion de la hebra de los consumidores.\n");
        exit(EXIT_FAILURE);
    }

    if(pthread_join(threadProductor, NULL)){
        fprintf(stderr, "Error en la recogida de la hebra de los productores.\n");
        exit(EXIT_FAILURE);
    }

    if(pthread_join(threadConsumidor, NULL)){
        fprintf(stderr, "Error en la recogida de la hebra de los consumidores.\n");
    }

    for (int i = 0; i < n; i++){
        printf("Valor %d del buffer: %d\n", i+1, v[i]);
    }
    exit(EXIT_SUCCESS);
}