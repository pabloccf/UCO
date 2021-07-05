#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define n 3

int v[n];
int indiceProductor=0;
int indiceConsumidor=0;
int hebraProductor=0;
int hebraConsumidor=0;

sem_t mutex;
sem_t full;
sem_t empty;

void producirDato(int numero){
    v[indiceProductor]=numero;
    indiceProductor=(indiceProductor + 1)%n;
    for (int i = 0; i < n; i++){
        printf("|%d", v[i]);
    }
    printf("|");
}

int consumirDato(){
    int numeroConsumido=v[indiceConsumidor];
    v[indiceConsumidor]='\0';
    indiceConsumidor=(indiceConsumidor + 1)%n;
    for (int i = 0; i < n; i++){
        printf("|%d", v[i]);
    }
    printf("|");

    return numeroConsumido;
}

void* productor(){
    sem_wait(&empty);
    sem_wait(&mutex);
    hebraProductor++;
    int numero=rand()%101;
    producirDato(numero);
    printf("---> Productor %d, Dato: %d\n", hebraProductor, numero);
    sem_post(&mutex);
    sem_post(&full);

    pthread_exit(NULL);
}

void* consumidor(){
    sem_wait(&full);
    sem_wait(&mutex);
    hebraConsumidor++;
    int numero=consumirDato();
    printf("---> Consumidor %d, Dato: %d\n", hebraConsumidor, numero);
    sem_post(&mutex);
    sem_post(&empty);

    pthread_exit(NULL);
}

int main(){
    srand(time(NULL));

    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, n);

    pthread_t threadProductor[3];
    pthread_t threadConsumidor[3];

    for (int i = 0; i < 3; i++){
        if(pthread_create(&threadProductor[i], NULL, productor, NULL)){
            fprintf(stderr, "Error en la creacion de la hebra de los productores.\n");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 3; i++){
        if(pthread_create(&threadConsumidor[i], NULL, consumidor, NULL)){
            fprintf(stderr, "Error en la creacion de la hebra de los consumidores.\n");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 3; i++){
        if(pthread_join(threadProductor[i], NULL)){
            fprintf(stderr, "Error en la recogida de la hebra de los productores.\n");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 3; i++){
        if(pthread_join(threadConsumidor[i], NULL)){
            fprintf(stderr, "Error en la recogida de la hebra de los consumidores.\n");
            exit(EXIT_FAILURE);
        }
    }
    
    for (int i = 0; i < n; i++){
        printf("Valor %d del buffer: %d\n", i+1, v[i]);
    }

    exit(EXIT_SUCCESS);
}