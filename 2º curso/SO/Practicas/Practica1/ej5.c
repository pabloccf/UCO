#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

int global=0;

int main(){
    int status;

    printf("Soy el padre con ID: %d\n", getppid());
    printf("La variable global antes de comenzar a incrementarla vale: %d\n", global);

    switch (fork()){
    case -1: //Error
        perror("Fork error\n");
        fprintf(stderr, "errno: %d\n", errno);
        exit(EXIT_FAILURE);

    case 0: //Hijo
        printf("Soy el hijo con ID %d. El ID de mi padre es %d\n", getpid(), getppid());
        printf("Voy a intentar incrementar en uno a la variable global\n");
        global++;
        exit(EXIT_SUCCESS);

    default: //Padre
        printf("Esperando a que mi hijo termine.\n");
        wait(&status);
        printf("Tras incrementar en uno a la variable global mi hijo, esta variable vale: %d\n", global);
        printf("Mi hijo ha salido sin poder incrementar en uno a la variable global, codigo de salida: %d\n", WEXITSTATUS(status));
    }
}