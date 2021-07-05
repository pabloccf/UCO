#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, const char* argv[]){
    if(argc<2){
        fprintf(stderr, "Error, numero de argumentos no valido. Debe de introducir el valor P\n");
        exit(EXIT_FAILURE);
    }

    int p=atoi(argv[1]);
    int status;
    pid_t pid, childpid;

    for(int i=0; i<p; i++){
        pid=fork();
        switch(pid){
        case -1:
            perror("Fork error\n");
            fprintf(stderr, "Errno value: %d", errno);
            exit(EXIT_FAILURE);

        case 0:
            break;
        
        default:
            sleep(3);
            childpid=wait(&status);
            if(childpid>0){
                if(WIFEXITED(status)){
                    printf("Padre %d, hijo con PID %d ha finalizado con estado %d\n", getpid(), pid, WEXITSTATUS(status));
                }
                else if(WIFSIGNALED(status)){
                    printf("Padre %d, hijo con PID %d ha finalizado recibiendo una señal %d\n", getpid(), pid, WTERMSIG(status));
                }
                else if(WIFSTOPPED(status)){
                    printf("Padre %d, hijo con PID %d ha sido parado recibiendo una señal %d\n", getpid(), pid, WSTOPSIG(status));
                }

                printf("El PID del padre es %d, el estado es %d y la suma del ultimo digito del pid del padre y del estado es: %d\n", getpid(), WEXITSTATUS(status), getpid()%10+WEXITSTATUS(status));
                exit(getpid()%10+WEXITSTATUS(status));
            }

            else{
                if(errno==ECHILD){
                    printf("Padre %d, no hay mas hijos que esperar. Valor de errno= %d, definido como: %s", getpid(), errno, strerror(errno));
                    exit(EXIT_SUCCESS);
                }

                else{
                    printf("Error en la invocacion del wait. Valor de errno: %d\n", errno);
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    exit(getpid()%10);
}