#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <errno.h>

int v[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
sem_t semaforo;

void* rutina(){
    int posicion=0;
    int valor=0;
    int* total=malloc(sizeof(int*));
    *total=0;

    for(int i=0; i<100; i++){
        posicion=rand()%10;
        valor=rand()%101;

        printf("Hilo %lu, el valor aleatorio a sumar es %d\n", pthread_self(), valor);
        printf("Hilo %lu, la posicion aleatoria generada es: %d\n", pthread_self(), posicion);

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
        fprintf(stderr, "Error, numero de argumentos no valido. Debe introducir el numero de hilos que desea crear\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    int nhilos=atoi(argv[1]);
    pthread_t hilos[nhilos];
    int total=0;
    int* subtotal;

    sem_init(&semaforo, 0, 1);

    for(int i=0; i<nhilos; i++){
        if(pthread_create(&hilos[i], NULL, rutina, NULL)){
            fprintf(stderr, "Error al crear la hebra. Errno value: %d\n", errno);
            exit(EXIT_FAILURE);
        }
    }

    for(int i=0; i<nhilos; i++){
        if(pthread_join(hilos[i], (void**) &subtotal)){
            fprintf(stderr, "Error al recoger la hebra. Errno value: %d\n", errno);
            exit(EXIT_FAILURE);
        }

        printf("El hilo %d ha devuelto el valor %d\n", i, *subtotal);
        total += *subtotal;
    }

    printf("El valor total de la suma de los valores devueltos por todos los hilos es: %d\n", total);
    total=0;

    for(int i=0; i<10; i++){
        printf("v[%d] = %d ", i, v[i]);
        total += v[i];
    }
    printf("\n");

    printf("El valor total en el vector es: %d\n", total);

    exit(EXIT_SUCCESS);
}