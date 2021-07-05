#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <errno.h>

int par=0;
int impar=0;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

void* suma(void* n){
    int* indicelocal=(int*) n;
    int* suma=malloc(sizeof(int*));
    
    for (int i = 0; i < 5; i++){
        int x=rand()%11;
        *suma= *suma + x;
    }
    
    if(pthread_mutex_lock(&mutex)){
        fprintf(stderr, "Error en el bloqueo del mutex.\n");
        exit(EXIT_FAILURE);
    }

    printf("Hebra %lu con indice %d\n", pthread_self(), *indicelocal);
    printf("El valor de la suma en %d es: %d\n", *indicelocal, *suma);

    if(*indicelocal%2==0){
        par= par + *suma;
    }

    else{
        impar= impar + *suma;
    }

    if(pthread_mutex_unlock(&mutex)){
        fprintf(stderr, "Error en el desbloqueo de la hebra.\n");
        exit(EXIT_FAILURE);
    }

    pthread_exit((void*) suma);
}

int main(int argc, char* argv[]){
    if(argc<2){
        printf("Error, numero de argumentos no valido. Ejecucion: ./ej2 nºHebras\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    int n=atoi(argv[1]);
    int* resultado;
    pthread_t thread[n];
    int indiceglobal[n];

    for (int i = 0; i < n; i++){
        indiceglobal[i]=i+1;
        if(pthread_create(&thread[i], NULL, suma, (void*) &indiceglobal[i])){
            fprintf(stderr, "Error en la creacion de la hebra.\n");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < n; i++){
        if(pthread_join(thread[i], (void**) &resultado)){
            fprintf(stderr, "Error en la recogida de la hebra.\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("El valor total par es: %d\n", par);
    printf("El valor total impar es: %d\n", impar);

    exit(EXIT_SUCCESS);
}
