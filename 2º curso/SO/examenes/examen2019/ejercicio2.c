#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int v[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
sem_t semaforo;

void* aleatorio(){
    int posicion;
    int valor;
    int* total=malloc(sizeof(int*));

    for (int i = 0; i < 100; i++){
        posicion=rand()%10;
        valor=rand()%101;

        printf("Hilo %lu valor aleatorio a sumar: %d\n", pthread_self(), valor);
        printf("Hilo %lu posicion aleatoria del vector: %d\n", pthread_self(), posicion);

        if(sem_wait(&semaforo)){
            fprintf(stderr, "Error al bloquear el semaforo. Errno value: %d\n", errno);
            exit(EXIT_FAILURE);
        }

        v[posicion] += valor;

        if(sem_post(&semaforo)){
            fprintf(stderr, "Error al desbloquear el semaforo. Errno value: %d\n", errno);
            exit(EXIT_FAILURE);
        }

        sleep(1);
        *total += valor;
    }
    
    pthread_exit((void*) total);
}

int main(int argc, const char* argv[]){
    if(argc<2){
        fprintf(stderr, "Error, numero de argumentos no valido. Debe introducir el numero de hilos que desea crear.\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    int nhilos=atoi(argv[1]);
    int total=0;
    int *suma=malloc(sizeof(int*));
    pthread_t hilos[nhilos];

    sem_init(&semaforo, 0, 1);

    for (int i = 0; i < nhilos; i++){
        if(pthread_create(&hilos[i], NULL, aleatorio, NULL)){
            fprintf(stderr, "Error al crear la hebra. Errno value: %d\n", errno);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < nhilos; i++){
        if(pthread_join(hilos[i], (void**) &suma)){
            fprintf(stderr, "Error al recoger la hebra. Errno value: %d\n", errno);
            exit(EXIT_FAILURE);
        }

        printf("El hilo %d ha devuelto el valor: %d\n", i, *suma);
        total += *suma;
    }

    printf("El valor total es: %d\n", total);
    total=0;
    for (int i = 0; i < 10; i++){
        printf("v[%d] = %d ", i, v[i]);
        total += v[i];
    }

    printf("\n");

    printf("El total en el vector es: %d\n", total);
}