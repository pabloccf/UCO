#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int n;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

void rellenarVector(int v[]){
    for (int i = 0; i < n; i++){
        v[i]=1+rand()%100;
    }
}

void* compra(int camisetas[]){
    int i=1+rand()%n;
    int cantidad=1+rand()%10;
    printf("El comprador %lu va a adquirir %d camisetas del tipo %d.\n", pthread_self(), cantidad, i);

    if(pthread_mutex_lock(&mutex)){
        fprintf(stderr, "Error en el bloqueo de mutex. Codigo de error %d", errno);
        exit(EXIT_FAILURE);
    }

    camisetas[i-1]=camisetas[i-1]-cantidad;

    if (pthread_mutex_unlock(&mutex)){
        fprintf(stderr, "Error en el desbloqueo de mutex. Codigo de error %d", errno);
        exit(EXIT_FAILURE);
    }

    pthread_exit(NULL);
}

void* suministro(int camisetas[]){
    int i=1+rand()%n;
    int cantidad=1+rand()%10;
    printf("El proveedor %lu va a suministrar %d camisetas del tipo %d.\n", pthread_self(), cantidad, i);

    if(pthread_mutex_lock(&mutex)){
        fprintf(stderr, "Error en el bloqueo de mutex. Codigo de error %d", errno);
        exit(EXIT_FAILURE);
    }

    camisetas[i-1]=camisetas[i-1]+cantidad;

    if(pthread_mutex_unlock(&mutex)){
        fprintf(stderr, "Error en el desbloqueo de mutex. Codigo de error %d", errno);
        exit(EXIT_FAILURE);
    }
    
    pthread_exit(NULL);
}

int main(int argc, const char* argv[]){
    if(argc<3){
        fprintf(stderr, "Error. Numero de argumentos no validos.\n");
        printf("Llamar al programa de la siguiente manera: ./ej1 N M. Donde N es el numero de clientes y M son los proveedores\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    int numeroClientes=atoi(argv[1]);
    int numeroProveedores=atoi(argv[2]);
    int modelosCamiseta=atoi(argv[2]);
    n=numeroProveedores;
    int camisetas[n];

    rellenarVector(camisetas);

    printf("Stock disponible de cada camiseta antes de abrir la tienda: \n");
    for (int i = 0; i < numeroProveedores; i++){
        printf("- Camisetas del tipo %d : %d\n", i+1, camisetas[i]);
    }

    pthread_t threadCliente[numeroClientes];                                            
    pthread_t threadProveedor[numeroProveedores];                                       

    printf("-------------------------------------------------------------------\n");
    for(int i = 0; i<numeroClientes; i++){                                              
        if(pthread_create(&threadCliente[i], NULL, (void*) compra, (void*) camisetas)){
            printf("Error al crear la hebra. Codigo de error: %d\n", errno);
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i<numeroProveedores; i++){                                          
        if(pthread_create(&threadProveedor[i], NULL, (void*) suministro, (void*) camisetas)){
            printf("Error al crear la hebra. Codigo de error: %d\n", errno);
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i<numeroClientes; i++){                                             
        if(pthread_join(threadCliente[i], NULL)){
            printf("Error al recoger la hebra. Codigo de error: %d\n", errno);
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i<numeroProveedores; i++){                                           
        if(pthread_join(threadProveedor[i], NULL)){
            printf("Error al recoger la hebra. Codigo de error: %d\n", errno);
            exit(EXIT_FAILURE);
        }
    }

    printf("-------------------------------------------------------------------\n");
    printf("Stock disponible de cada camisetas al cerrar la tienda: \n");               
    for(int i = 0; i<numeroProveedores; i++){
        printf("- Camisetas del tipo %d : %d\n", i+1, camisetas[i]);
    }
    
    exit(EXIT_SUCCESS);   
}