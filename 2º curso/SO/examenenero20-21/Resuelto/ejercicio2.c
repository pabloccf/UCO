/*Realice un programa que reciba por linea de argumentos el numero de hilos que se van a crear.
Antes de crear los hilos imprima el vector inicial (puede usar una variable global).
Los hilos generaran un numero aleatorio entre 0 y 9 que añadiran a una posicion aleatoria entre 0 y 2
Una vez recogidas todas las hebras imprima el vector resultado.
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>

//Declaracion de variable global
int vector[3]={0,0,0};//

//Declaracion e inicializacion del semaforo
pthread_mutex_t semaforo = PTHREAD_MUTEX_INITIALIZER;

//Funcion a la que accederan las hebras
void*funcion(void*arg)
{
    //Generamos los dos valores aleatorios
    int valor_aleatorio = rand()%10;
    int posicion_aleatoria = rand()%3;

    //Usamos pthread_self() para obtener el identificador de la hebra,  es necesario usar %lu porque con %d se sale del rango y aparecerian numeros raros
    printf("Soy la hebra %lu y voy a insertar el valor %d\n", pthread_self(), valor_aleatorio);
    printf("Soy la hebra %lu y voy a insertar en la posicion %d\n", pthread_self(), posicion_aleatoria);

    //Esta es la region critica, pues el vector es accesible por todos los hilos y se pueden dar circunstancias que lo corrompan
    pthread_mutex_lock(&semaforo);

    vector[posicion_aleatoria] = vector[posicion_aleatoria] + valor_aleatorio;

    pthread_mutex_unlock(&semaforo);

    //Finalizamos
    pthread_exit(NULL);
}

int main(int argc, char**argv)
{
    if(argc!=2)
    {
        perror("Error en la linea de argumentos");
        exit(EXIT_FAILURE);
    }

    int n_hilos = atoi(argv[1]);

    pthread_t hilo[n_hilos];

    srand(time(NULL));

    for(int i=0; i<3; i++)
    {
        printf("V[%d]=%d\t",i,vector[i]);
    }

    printf("\n");

    for(int i=0; i<n_hilos; i++)//Creamos tantas hebras como se haya indicado por linea de argumentos
    {
        if(pthread_create(&hilo[i], NULL, (void*)funcion, NULL)!=0)
        {
            perror("Error creando la hebra");
        }
    }

    for(int i=0; i<n_hilos;i++)//Recogemos todas las hebras
    {
        if(pthread_join(hilo[i],NULL)!=0)
        {
            perror("Join error");
        }
    }

    for(int i=0; i<3; i++)
    {
        printf("V[%d]=%d\t",i,vector[i]);
    }

    return 0;
}

//CONSEJOS

//Usar https://pubs.opengroup.org/onlinepubs/9699919799/

/*
Buscando pthread_mutex encontraremos un ejemplo de semaforos totalmente hecho.
Buscando pthread_create() encontraremos que parametros requiere la funcion 
y que devuelve la funcion para hacer el control de errores; lo mismo con pthread_join()
Buscando pthread_join() tambien encontraremos un ejemplo de un pequeño programa con hebras.
*/