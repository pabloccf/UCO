#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

int main(int argc, const char* argv[]){
    if(argc!=2){
        fprintf(stderr, "Error, numero de argumentos no valido.\n");
        exit(EXIT_FAILURE);
    }

    pid_t pid=atoi(argv[1]);

    if(pid<0){
        fprintf(stderr, "Error, has introducido un PID negativo. Vuelve a ejecutar el programa introduciendo un PID valido.\n");

        if(kill(pid, SIGUSR1)){
            fprintf(stderr, "Error al enviar la señal SIGUSR1: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        sleep(1);

        if(kill(pid, SIGKILL)){
            fprintf(stderr, "Error al enviar la señal SIGKILL: %s\n", strerror(errno));
        }
    }

    exit(EXIT_SUCCESS);
}
