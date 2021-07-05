#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void tratarSennal();

int main(){
    int status;
    pid_t pid;

    switch (fork()){
    case -1: //Error
        perror("Fork error");
        fprintf(stderr,"errno: %i\n",errno);
        exit(EXIT_FAILURE);

    case 0: //Hijo
        signal(SIGUSR1,tratarSennal);
        for (int i = 0; i < 5; i++){
            pause();
        }
        sleep(1);
        exit(EXIT_SUCCESS);
    
    default: //Padre
        printf("Esperando a que mi hijo acabe...\n");
        for (int i = 0; i < 5; i++){
            sleep(1);
            kill(pid, SIGUSR1);
        }
        
        sleep(1);
        kill(pid, SIGKILL);
        sleep(10);
        wait(&status);
        printf("El hijo ha finalizado con codigo de salida: %d\n", WEXITSTATUS(status));
    }

    return 0;
}

void tratarSennal(){
    printf("Señal recibida\n");
}