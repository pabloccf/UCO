#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, const char* argv[]){
    if(argc<2){
        fprintf(stderr, "Error, numero de argumentos no valido. Debe de introducir un numero\n");
        exit(EXIT_FAILURE);
    }

    int status;
    pid_t pid, childpid;
    int numero=atoi(argv[1]);

    for(int i=0; i<2; i++){
        pid=fork();
        switch(pid){
            case -1:
                perror("Fork error\n");
                fprintf(stderr, "Errno value: %d\n", errno);
                exit(EXIT_FAILURE);
            
            case 0:
                if(i==0){
                    int fact=1;
                    for(int j=2; j<=numero; j++){
                        fact *= j;
                    }

                    printf("Soy el hijo %d, mi padre %d el factorial de %d es %d\n", getpid(), getppid(), numero, fact);
                    exit(EXIT_SUCCESS);
                }

                else{
                    printf("Soy el hijo %d, mi padre %d y voy a abrir la calculadora\n", getpid(), getppid());
                    execlp("gnome-calculator", "gnome-calculator", NULL);

                    exit(EXIT_SUCCESS);
                }

            default:
                childpid=wait(&status);

                if(childpid>0){
                    if(WIFEXITED(status)){
                        printf("Padre %d, ha finalizado el hijo %d con el estado %d\n", getpid(), pid, WEXITSTATUS(status));
                    }

                    else if(WIFSIGNALED(status)){
                        printf("Padre %d, ha finalizado el hijo %d recibiendo la señal %d\n", getpid(), pid, WTERMSIG(status));
                    }

                    else if(WIFSTOPPED(status)){
                        printf("Padre %d, ha parado el hijo %d recibiendo la señal %d\n", getpid(), pid, WSTOPSIG(status));
                    }
                }

                else{
                    if(errno==ECHILD){
                        printf("Padre %d, no hay mas hijos que esperar. Valor de errno: %d, definido como: %s\n", getpid(), errno, strerror(errno));
                    }

                    else{
                        printf("Error en la invocacion del wait o waitpid. Valor de errno: %d, definido como: %s\n", errno, strerror(errno));
                        exit(EXIT_FAILURE);
                    }
                }

        }
    }

    exit(EXIT_SUCCESS);
}