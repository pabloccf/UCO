#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

void miSenial(int signal){
    printf("Soy el hijo %d, recibida señal %d\n", getpid(), signal);
}

int main(){
    int status;
    pid_t pid, childpid;

    pid=fork();
    switch(pid){
    case -1:
        perror("Fork error\n");
        fprintf(stderr, "Errno value: %d", errno);
        exit(EXIT_FAILURE);

    case 0:
        sleep(1);
        printf("Soy el hijo %d, mi padre es %d, y voy a recibir señales...\n", getpid(), getppid());
        signal(SIGUSR1, miSenial);
        for(int i=0; i<3; i++){
            pause();
        }
    
    default:
        sleep(1);
        printf("Proceso padre %d, voy a empezar a enviar señales...\n", getpid());
        for(int i=0; i<3; i++){
            sleep(1);
            kill(pid, SIGUSR1);
        }

        sleep(1);
        kill(pid, SIGKILL);

        while(1){
            childpid=wait(&status);
            if(childpid>0){
                if(WIFEXITED(status)){
                    printf("El hijo con PID %i ha salido con estado: %i\n",pid, WEXITSTATUS(status));
                }
                else if(WIFSIGNALED(status)){
                    printf("Proceso padre %d, hijo %d finalizado al recibir la señal %d\n", getpid(), pid, WTERMSIG(status));
                }
                else{
                    printf("El hijo con PID %i ha sido parado con una señal: %i\n",pid, WSTOPSIG(status));
                }
            }

            else{
                if(errno==ECHILD){
                    printf("Proceso padre %d, no hay mas hijos que esperar. Valor de errno= %d, definido como: %s\n", getpid(), errno, strerror(errno));
                    exit(EXIT_SUCCESS);
                }

                else{
                    fprintf(stderr, "El proceso padre no ha esperado a que acabe el hijo. Valor de errno= %d, definido como %s\n", errno, strerror(errno));
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    return 0;
}