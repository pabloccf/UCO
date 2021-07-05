#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

int n;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

void* compra(int coches[]){
    int modelo=rand()%n;
    int cantidad=rand()%5+1;

    printf("El comprador %lu va a adquirir %d coches del tipo %d\n", pthread_self(), cantidad, modelo);

    if(pthread_mutex_lock(&mutex)){
        fprintf(stderr, "Error al bloquear el mutex. Errno value: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    coches[modelo] -= cantidad;

    if(pthread_mutex_unlock(&mutex)){
        fprintf(stderr, "Error al desbloquear el mutex. Errno value: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    pthread_exit(NULL);
}

void* suministro(int coches[]){
    int modelo=rand()%n;
    int cantidad=rand()%5+1;

    printf("El proveedor %lu va a suministrar %d coches del tipo %d\n", pthread_self(), cantidad, modelo);

    if(pthread_mutex_lock(&mutex)){
        fprintf(stderr, "Error al bloquear el mutex. Errno value: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    coches[modelo] += cantidad;

    if(pthread_mutex_unlock(&mutex)){
        fprintf(stderr, "Error al desbloquear el mutex. Errno value: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    pthread_exit(NULL);
}

int main(int argc, const char* argv[]){
    if(argc<3){
        fprintf(stderr, "Error, numero de argumentos no valido. Debe decirme el numero de clientes y el numero de proveedores.\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    int nClientes=atoi(argv[1]);
    int nProveedores=atoi(argv[2]);
    int modeloCoches=atoi(argv[2]);
    n=modeloCoches;
    int coches[n];

    pthread_t threadCliente[nClientes];
    pthread_t threadProveedor[nProveedores];

    for (int i = 0; i < nClientes; i++){
        if(pthread_create(&threadCliente[i], NULL, (void*) compra, (void*) coches)){
            fprintf(stderr, "Error al crear la hebra de los clientes. Errno value: %d\n", errno);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < nProveedores; i++){
        if(pthread_create(&threadProveedor[i], NULL, (void*) suministro, (void*) coches)){
            fprintf(stderr, "Error al crear la hebra de los proveedores. Errno value: %d\n", errno);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < nClientes; i++){
        if(pthread_join(threadCliente[i], NULL)){
            fprintf(stderr, "Error al recoger la hebra de los clientes. Errno value: %d\n", errno);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < nProveedores; i++){
        if(pthread_join(threadProveedor[i], NULL)){
            fprintf(stderr, "Error al recoger la hebra de los proveedores. Errno value: %d\n", errno);
            exit(EXIT_FAILURE);
        }
    }
    
    printf("Stock disponible de cada coche al cerrar el concesionario: \n");
    for (int i = 0; i < modeloCoches; i++){
        printf("-Coches del tipo %d: %d\n", i+1, coches[i]);
    }   
}