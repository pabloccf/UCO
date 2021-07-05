#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* aleatorio();

int main(){
    int n;
    printf("Introduce el numero de hebras que quieras crear: ");
    scanf("%d", &n);

    float total=0, *subtotal;
    pthread_t hilos[n];
    srand48(time(NULL));

    for (int i = 0; i < n; i++){
        if (pthread_create(&hilos[i], NULL, aleatorio, NULL)){
            perror("pthread_create error");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < n; i++){
        if (pthread_join(hilos[i], (void**) &subtotal)){
            perror("pthread_join error");
            exit(EXIT_FAILURE);
        }
        
        printf("Valor recibido: %f\n",*subtotal);
        total+= *subtotal;
    }
    printf("La suma total es: %f\n",total);
    
    exit(EXIT_SUCCESS);
}

void* aleatorio(){
    printf("Soy la hebra %lu \n", pthread_self());

    float f1 = (float)rand()/(float)(RAND_MAX);
    printf("Valor de f1= %f\n", f1);

    float f2 = (float)rand()/(float)(RAND_MAX);
    printf("Valor de f2= %f\n", f2);
    
    float *f3 = malloc(sizeof(float));
    *f3 = f2 + f1;

    printf("Suma de la hebra actual = %f\n", *f3);


    pthread_exit((void*) f3);
}